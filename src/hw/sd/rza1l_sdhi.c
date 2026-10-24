/*
 * Renesas RZ/A1L SDHI (SD Host Interface) controller model
 *
 * Models the SDHI host port the Synthstrom Deluge uses (SD_PORT = 1, IP1 at
 * 0xE804E800) well enough for the firmware's command/response/data flow. The
 * controller owns an SDBus to which a QEMU sd-card can be attached.
 *
 * The firmware driver (Renesas SD library + Deluge glue in
 * deluge/drivers/sd/sd.c) is configured for hardware-interrupt mode
 * (SDCFG_HWINT) and DMA data transfer (SDCFG_TRNS_DMA). After issuing a command
 * it waits on the SDHI interrupt; its ISR reads SD_INFO1/SD_INFO2. Data is moved
 * by a DMAC channel reading/writing the SD data FIFO. Because the DMAC model
 * accesses its source/destination through the system address space, the same
 * FIFO serves both DMA and PIO accesses.
 *
 * In 64-byte DMA mode (SDCFG_TRANS_DMA_64) the firmware points the DMAC at the
 * register base (SD_CMD) with a fixed source address rather than at SD_BUF0, so
 * the controller also exposes the data FIFO at that single offset while a DMA
 * transfer is in progress; see the SD_CMD handling in the read/write paths.
 *
 * Timing. SD access is the Deluge's usual bottleneck (sample streaming), so the
 * controller models how long the bus is busy rather than completing everything
 * instantly. Every command, response and data block takes its bit count in SD
 * clocks, at the clock the firmware programs into SD_CLK_CTRL (IMCLK = P1 =
 * 66.67 MHz, divided) and the bus width in SD_OPTION; a flash read (CMD17/18)
 * first waits the card's access latency, and a flash write (CMD24/25) adds the
 * card's per-block programming time and a final busy period. The buffer holds
 * one block, as on the hardware: the next block only crosses the bus once the
 * previous one has been drained (or, writing, once the card is ready again), so
 * DMA is paced by a level-sensitive request line (`dreq`) that is high while a
 * block is waiting. All delays run on the virtual clock, so they are
 * deterministic under -icount. The latencies are properties (timing, and
 * read-latency-us / write-block-us / write-busy-us); timing=off restores the
 * old instant behaviour.
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/log.h"
#include "qemu/bswap.h"
#include "hw/core/sysbus.h"
#include "hw/core/irq.h"
#include "hw/core/qdev-properties.h"
#include "hw/sd/sd.h"
#include "migration/vmstate.h"
#include "hw/sd/rza1l_sdhi.h"
#include "hw/misc/deluge_vcpu_tick.h"

/* Register offsets (16-bit registers, natural byte offsets). */
#define SD_CMD          0x00
#define SD_ARG0         0x04
#define SD_ARG1         0x06
#define SD_STOP         0x08
#define SD_SECCNT       0x0A
#define SD_RESP0        0x0C
#define SD_RESP7        0x1A
#define SD_INFO1        0x1C
#define SD_INFO2        0x1E
#define SD_INFO1_MASK   0x20
#define SD_INFO2_MASK   0x22
#define SD_CLK_CTRL     0x24
#define SD_SIZE         0x26
#define SD_OPTION       0x28
#define SD_ERR_STS1     0x2C
#define SD_ERR_STS2     0x2E
#define SD_BUF0         0x30
#define SDIO_MODE       0x34
#define SDIO_INFO1      0x36
#define SDIO_INFO1_MASK 0x38
#define CC_EXT_MODE     0xD8
#define SOFT_RST        0xE0
#define SD_VERSION      0xE2
#define EXT_SWAP        0xF0

/* SD_INFO1 bits. */
#define INFO1_RESP       0x0001  /* response/command end */
#define INFO1_DATA_TRNS  0x0004  /* data-transfer/access end */
#define INFO1_REM_CD     0x0008  /* CD-pin removal event */
#define INFO1_INS_CD     0x0010  /* CD-pin insertion event */
#define INFO1_CD_LEVEL   0x0020  /* CD-pin current level (1 = card present) */
#define INFO1_WP_LEVEL   0x0080  /* WP-pin current level (1 = not protected) */
#define INFO1_REM_DAT3   0x0100  /* DAT3 removal event */
#define INFO1_INS_DAT3   0x0200  /* DAT3 insertion event */
#define INFO1_DAT3_LEVEL 0x0400  /* DAT3 current level (1 = card present) */
#define INFO1_DET_CD     (INFO1_REM_CD | INFO1_INS_CD)
#define INFO1_DET_DAT3   (INFO1_REM_DAT3 | INFO1_INS_DAT3)
#define INFO1_IRQ_BITS   (INFO1_RESP | INFO1_DATA_TRNS | INFO1_DET_CD | \
                          INFO1_DET_DAT3)

/* SD_INFO2 bits. */
#define INFO2_ERR0       0x0001  /* CMD error */
#define INFO2_ERR6       0x0040  /* response timeout */
#define INFO2_RE         0x0100  /* read buffer ready (BRE) */
#define INFO2_WE         0x0200  /* write buffer ready (BWE) */
#define INFO2_SCLKDIVEN  0x2000  /* SD bus idle/clock ready */
#define INFO2_CBSY       0x4000  /* command busy */
#define INFO2_ILA        0x8000  /* illegal access */
#define INFO2_ERR_MASK   0x807f  /* all error bits + ILA */
#define INFO2_IRQ_BITS   (INFO2_RE | INFO2_WE | INFO2_ERR_MASK)

#define SD_CMD_INDEX_MASK 0x003f

/* SD_STOP bits. */
#define SD_STOP_STP        0x0001  /* compulsory transfer stop (issue CMD12) */
#define SD_STOP_SEC_ENABLE 0x0100  /* honour SD_SECCNT for a multi-block transfer */

/* CC_EXT_MODE bits. */
#define CC_EXT_MODE_DMASDRW 0x0002  /* SD buffer accesses are driven by DMA */

/* SD_CLK_CTRL bits. */
#define SD_CLK_CTRL_DIV_MASK 0x00ff
#define SD_CLK_CTRL_DIV_1    0x00ff  /* SDCLK = IMCLK */

/* SD_OPTION bits. */
#define SD_OPTION_WIDTH_1BIT 0x8000  /* data bus is 1 bit wide (else 4) */

/* SDHI module clock (IMCLK = P1 clock) the SD clock is divided from. */
#define SDHI_IMCLK_HZ 66666667u

/*
 * SD bus framing, in SD clocks. A command is 48 bits; the card answers after
 * NCR (2..64) clocks with a 48-bit (R1/R3/R6/R7) or 136-bit (R2) response, and
 * a command with no response still needs NCC (8) clocks before the next. A data
 * block is a start bit, the data on each line, a CRC16 per line and an end bit.
 */
#define SD_CMD_BITS      48
#define SD_NCR_CLOCKS    8
#define SD_NCR_MAX       64
#define SD_RESP_BITS     48
#define SD_RESP_R2_BITS  136
#define SD_BLOCK_FRAMING (1 + 16 + 1)

/*
 * Controller phases. Each non-idle phase ends when s->timer fires (or at once
 * with timing off); see rza1l_sdhi_advance.
 */
enum {
    SDHI_IDLE,        /* bus free */
    SDHI_CMD,         /* command + response on the CMD line */
    SDHI_READ_WAIT,   /* card fetching / sending the next block */
    SDHI_READ_BUF,    /* block in the buffer, waiting for the host to drain it */
    SDHI_WRITE_BUF,   /* buffer free, waiting for the host to fill it */
    SDHI_WRITE_WAIT,  /* block crossing the bus, then the card programming it */
    SDHI_END,         /* auto CMD12 after the last block */
};

/* Standard SD commands whose data comes from / goes to the flash array. */
#define SD_CMD_READ_SINGLE   17
#define SD_CMD_READ_MULTIPLE 18
#define SD_CMD_WRITE_SINGLE  24
#define SD_CMD_WRITE_MULTIPLE 25

/*
 * Standard SD/MMC commands that complete without any response. For these a
 * zero-length result from the card is normal and must not be reported as a
 * response timeout. CMD0 GO_IDLE_STATE, CMD4 SET_DSR, CMD15 GO_INACTIVE_STATE.
 */
static bool rza1l_sdhi_cmd_has_no_response(uint8_t cmd)
{
    return cmd == 0 || cmd == 4 || cmd == 15;
}

static void rza1l_sdhi_update_irq(RzA1lSdhiState *s)
{
    /*
     * The hardware mask registers use inverted logic: a register bit of 0 means
     * the corresponding interrupt is enabled. Raise the line whenever an enabled
     * event bit is set (SCLKDIVEN/CBSY are status, not interrupt sources).
     */
    uint16_t i1 = s->info1 & (uint16_t)~s->info1_mask & INFO1_IRQ_BITS;
    uint16_t i2 = s->info2 & (uint16_t)~s->info2_mask & INFO2_IRQ_BITS;
    bool level = i1 || i2;

    /* Note when the line rises, to time how long the firmware takes to look. */
    if (level && !s->irq_level) {
        s->irq_raised_ns = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);
        s->irq_unacked = true;
    }
    s->irq_level = level;
    qemu_set_irq(s->irq, level);
}

/* ---- DELUGEMU_SDHI_STATS probe ---- */

static bool rza1l_sdhi_stats_enabled(void)
{
    static int v = -1;
    if (v < 0) {
        v = getenv("DELUGEMU_SDHI_STATS") != NULL;
    }
    return v;
}

/* Charge the time since the current phase began, up to `now`, to the stats. */
static void rza1l_sdhi_stats_charge(RzA1lSdhiState *s, int64_t now)
{
    int64_t ns = now - s->phase_since_ns;

    if (ns > 0) {
        if (s->phase == SDHI_READ_BUF || s->phase == SDHI_WRITE_BUF) {
            s->stats_buf_ns += ns;
        } else if (s->phase != SDHI_IDLE) {
            s->stats_bus_ns += ns;
        }
        s->phase_since_ns = now;
    }
}

/*
 * The firmware read a status register: if the interrupt line was up, that's
 * the interrupt being serviced (or a poll noticing the event).
 */
static void rza1l_sdhi_irq_ack(RzA1lSdhiState *s)
{
    if (s->irq_unacked && rza1l_sdhi_stats_enabled()) {
        int64_t ns = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL) - s->irq_raised_ns;

        s->stats_irqs++;
        s->stats_irq_sum_ns += ns;
        s->stats_irq_max_ns = MAX(s->stats_irq_max_ns, ns);
    }
    s->irq_unacked = false;
}

/*
 * Once per virtual second, report how hard the SD bus worked: commands issued,
 * data moved, and the fraction of the second the controller was busy. Busy is
 * split into bus time (command, card latency, transfer or programming), which
 * near 100% means the card is the bottleneck, and buffer wait (a block sat in
 * the one-block buffer waiting for the firmware or DMA to drain or fill it),
 * which is the firmware holding up the card. irq is how long the firmware took
 * to read the status registers after the controller raised its interrupt:
 * under -icount this tracks how long the firmware runs with interrupts masked
 * (guest instruction count, not real A9 timing: no cache or memory stalls).
 */
static void rza1l_sdhi_stats_tick(void *opaque)
{
    RzA1lSdhiState *s = opaque;
    int64_t now = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);

    rza1l_sdhi_stats_charge(s, now);
    if (s->stats_cmds) {
        double bus = s->stats_bus_ns * 100.0 / NANOSECONDS_PER_SECOND;
        double buf = s->stats_buf_ns * 100.0 / NANOSECONDS_PER_SECOND;

        fprintf(stderr, "sdhi: t=%.1fs cmds=%u read=%uKiB write=%uKiB "
                "busy=%.1f%% (bus=%.1f%% bufwait=%.1f%%) "
                "irq=%u avg=%.0fus max=%.0fus\n", now / 1e9, s->stats_cmds,
                s->stats_rd_blocks / 2, s->stats_wr_blocks / 2,
                bus + buf, bus, buf, s->stats_irqs,
                s->stats_irqs ? s->stats_irq_sum_ns / 1e3 / s->stats_irqs : 0,
                s->stats_irq_max_ns / 1e3);
    }
    s->stats_bus_ns = 0;
    s->stats_buf_ns = 0;
    s->stats_irqs = 0;
    s->stats_irq_sum_ns = 0;
    s->stats_irq_max_ns = 0;
    s->stats_cmds = 0;
    s->stats_rd_blocks = 0;
    s->stats_wr_blocks = 0;
    timer_mod(s->stats_timer, now + NANOSECONDS_PER_SECOND);
}

/* ---- Bus timing ---- */

/* Duration of `clocks` SD clock cycles at the programmed divider. */
static int64_t rza1l_sdhi_clocks_ns(RzA1lSdhiState *s, uint64_t clocks)
{
    unsigned div = s->clk_ctrl & SD_CLK_CTRL_DIV_MASK;

    /* DIV field: 0x00 = /2, single bit 2^n = /(4 << n), 0xFF = /1. */
    if (div == SD_CLK_CTRL_DIV_1) {
        div = 1;
    } else if (div == 0) {
        div = 2;
    } else {
        div = 4 * div;
    }
    return muldiv64(clocks * div, NANOSECONDS_PER_SECOND, SDHI_IMCLK_HZ);
}

/* Time one data block of s->blocklen bytes spends on the DAT lines. */
static int64_t rza1l_sdhi_block_ns(RzA1lSdhiState *s)
{
    unsigned width = (s->option & SD_OPTION_WIDTH_1BIT) ? 1 : 4;

    return rza1l_sdhi_clocks_ns(s, (uint64_t)s->blocklen * 8 / width +
                                   SD_BLOCK_FRAMING);
}

/* A full no-data command with an R1 response, as for the auto CMD12. */
static int64_t rza1l_sdhi_cmd12_ns(RzA1lSdhiState *s)
{
    return rza1l_sdhi_clocks_ns(s, SD_CMD_BITS + SD_NCR_CLOCKS + SD_RESP_BITS);
}

/*
 * The time the controller is acting at: the deadline of the phase end being
 * handled, or now for something the firmware did.
 */
static int64_t rza1l_sdhi_now(RzA1lSdhiState *s)
{
    return s->on_deadline ? s->deadline_ns
                          : qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);
}

static void rza1l_sdhi_set_phase(RzA1lSdhiState *s, uint8_t phase)
{
    if (rza1l_sdhi_stats_enabled()) {
        rza1l_sdhi_stats_charge(s, rza1l_sdhi_now(s));
    }
    s->phase = phase;
}

static void rza1l_sdhi_advance(RzA1lSdhiState *s);

/* The current phase's deadline has passed: handle its end, at the deadline. */
static void rza1l_sdhi_phase_due(RzA1lSdhiState *s)
{
    bool was = s->on_deadline;

    s->on_deadline = true;
    rza1l_sdhi_advance(s);
    s->on_deadline = was;
}

/*
 * End the current phase after `ns` of bus activity, timed from when the
 * controller acted rather than from when it got round to it. If that deadline
 * has already passed (the previous phase's timer fired late), end the phase
 * straight away so the transfer catches up. With timing disabled every phase
 * ends immediately, which reproduces the original instant model.
 */
static void rza1l_sdhi_schedule(RzA1lSdhiState *s, int64_t ns)
{
    s->deadline_ns = rza1l_sdhi_now(s) + MAX(ns, 0);
    if (!s->timing ||
        s->deadline_ns <= qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL)) {
        rza1l_sdhi_phase_due(s);
        return;
    }
    timer_mod(s->timer, s->deadline_ns);
}

static void rza1l_sdhi_timer_cb(void *opaque)
{
    rza1l_sdhi_phase_due(opaque);
}

/*
 * vCPU-side catch-up (see deluge_vcpu_tick.h): end the current phase as soon
 * as its deadline has passed, rather than when the main loop next wakes, which
 * without -icount can be up to a millisecond late on every phase.
 */
static void rza1l_sdhi_vcpu_tick(void *opaque)
{
    RzA1lSdhiState *s = opaque;

    if (timer_pending(s->timer) &&
        timer_expired(s->timer, qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL))) {
        timer_del(s->timer);
        rza1l_sdhi_phase_due(s);
    }
}

static void rza1l_sdhi_update_dreq(RzA1lSdhiState *s)
{
    /*
     * The DMAC request is level-detected: hold it while a block is waiting to
     * be read from, or room is waiting to be written to, the buffer — but only
     * once the firmware has handed buffer accesses to DMA.
     */
    qemu_set_irq(s->dreq, s->buf_ready &&
                          (s->cc_ext_mode & CC_EXT_MODE_DMASDRW));
}

/* Drop any in-flight transfer (soft reset or a new command). */
static void rza1l_sdhi_abort(RzA1lSdhiState *s)
{
    timer_del(s->timer);
    rza1l_sdhi_set_phase(s, SDHI_IDLE);
    s->data_dir = 0;
    s->datacnt = 0;
    s->blockcnt = 0;
    s->buf_ready = false;
    s->info2 &= ~(INFO2_RE | INFO2_WE);
    rza1l_sdhi_update_dreq(s);
}

static void rza1l_sdhi_command(RzA1lSdhiState *s, uint16_t cmdreg)
{
    SDRequest req;
    uint8_t rsp[16];
    size_t rlen;
    uint64_t clocks;

    req.cmd = cmdreg & SD_CMD_INDEX_MASK;
    req.arg = ((uint32_t)s->arg1 << 16) | s->arg0;
    req.crc = 0;

    /* Clear status from any previous command. */
    rza1l_sdhi_abort(s);
    s->info1 &= ~(INFO1_RESP | INFO1_DATA_TRNS);
    s->info2 &= ~(INFO2_ERR_MASK | INFO2_RE | INFO2_WE);
    memset(s->resp, 0, sizeof(s->resp));
    s->pending_info2 = 0;
    s->stats_cmds++;
    s->total_cmds++;

    rlen = sdbus_do_command(&s->sdbus, &req, rsp, sizeof(rsp));

    clocks = SD_CMD_BITS + SD_NCR_CLOCKS;
    if (rlen == 0) {
        /*
         * No response. For commands that genuinely return none this is the
         * expected outcome; otherwise it means the card did not answer, which
         * the controller reports as a response timeout.
         */
        if (!rza1l_sdhi_cmd_has_no_response(req.cmd)) {
            s->pending_info2 |= INFO2_ERR6;
            clocks = SD_CMD_BITS + SD_NCR_MAX;
        }
    } else if (rlen == 4) {
        /* Short response (R1/R1b/R3/R6/R7): RESP1:RESP0 = 32-bit content. */
        uint32_t v = ldl_be_p(&rsp[0]);
        s->resp[0] = v & 0xffff;
        s->resp[1] = (v >> 16) & 0xffff;
        clocks += SD_RESP_BITS;
    } else if (rlen == 16) {
        /*
         * Long response (R2, CID/CSD). The SDHI exposes the 136-bit response
         * frame bits [135:8] across SD_RESP7..SD_RESP0; the firmware reads
         * cid/csd[k] = SD_RESP(7-k) and expects, e.g., CSD_STRUCTURE at
         * csd[0][7:6] (= frame[127:126] = CSD[127:126]). QEMU returns the raw
         * 16-byte CID/CSD (rsp[0] = bits [127:120], rsp[15] = CRC). Prepend the
         * 8-bit frame header, drop the trailing CRC byte, then slice into the
         * eight response halfwords MSB first.
         */
        uint8_t frame[16];
        int k;

        frame[0] = 0x3f;                 /* R2 frame header (all-ones field) */
        memcpy(&frame[1], rsp, 15);      /* CSD/CID[127:8]; drop CRC (rsp[15]) */
        for (k = 0; k < 8; k++) {
            s->resp[7 - k] = ((uint16_t)frame[2 * k] << 8) | frame[2 * k + 1];
        }
        clocks += SD_RESP_R2_BITS;
    }

    /*
     * Determine whether a data phase follows from the card's resulting state,
     * which avoids decoding the SDHI command flags (and the ACMD13/CMD13 index
     * ambiguity). The transfer length comes from SD_SIZE/SD_SECCNT.
     *
     * SD_SECCNT is only meaningful for a multi-block transfer, which the driver
     * selects by setting the SD_STOP block-count-enable bit. For a single-block
     * transfer it clears SD_STOP and leaves SD_SECCNT holding whatever count a
     * previous multi-block transfer programmed; honouring that stale value would
     * make the controller wait for blocks that never arrive, so the access-end
     * interrupt would never fire and the driver would time out. Clamp to one
     * block unless the block-count-enable bit is set.
     */
    if (sdbus_data_ready(&s->sdbus)) {
        s->data_dir = 1;
    } else if (sdbus_receive_ready(&s->sdbus)) {
        s->data_dir = 2;
    }
    if (s->data_dir) {
        s->blocklen = s->size ? s->size : 512;
        s->blockcnt = (s->stop & SD_STOP_SEC_ENABLE) && s->seccnt ?
                      s->seccnt : 1;
        s->datacnt = s->blocklen;
    }

    /* The response arrives once the command has crossed the bus. */
    rza1l_sdhi_set_phase(s, SDHI_CMD);
    rza1l_sdhi_schedule(s, rza1l_sdhi_clocks_ns(s, clocks));
}

/*
 * Data phase finished (all blocks moved, auto CMD12 issued): raise access end
 * and free the bus.
 */
static void rza1l_sdhi_finish(RzA1lSdhiState *s)
{
    /*
     * A block-count-enabled (SD_STOP.SEC) transfer is an open-ended
     * CMD18/CMD25 sequence: the card keeps streaming until it is told to
     * stop. The hardware automatically issues CMD12 once SD_SECCNT blocks
     * have moved, returning the card to the transfer state. Mirror that so
     * the subsequent CMD13 status poll sees STATE_TRAN rather than a card
     * still stuck in the data state (which the driver reports as an error).
     */
    if (s->stop & SD_STOP_SEC_ENABLE) {
        SDRequest stop = { .cmd = 12, .arg = 0, .crc = 0 };
        uint8_t rsp[16];

        sdbus_do_command(&s->sdbus, &stop, rsp, sizeof(rsp));
    }
    s->info2 &= ~(INFO2_RE | INFO2_WE);
    s->info1 |= INFO1_DATA_TRNS;
    s->data_dir = 0;
    rza1l_sdhi_set_phase(s, SDHI_IDLE);
}

/* The current phase's bus activity is over: move to the next phase. */
static void rza1l_sdhi_advance(RzA1lSdhiState *s)
{
    uint8_t cmd = s->cmd & SD_CMD_INDEX_MASK;
    bool flash = cmd == SD_CMD_READ_SINGLE || cmd == SD_CMD_READ_MULTIPLE;

    switch (s->phase) {
    case SDHI_CMD:
        s->info1 |= INFO1_RESP;
        s->info2 |= s->pending_info2;
        if (s->data_dir == 1) {
            /* The card fetches the first block from flash, then sends it. */
            int64_t ns = rza1l_sdhi_block_ns(s);

            if (flash) {
                ns += (int64_t)s->read_latency_us * SCALE_US;
            }
            rza1l_sdhi_set_phase(s, SDHI_READ_WAIT);
            rza1l_sdhi_schedule(s, ns);
        } else if (s->data_dir == 2) {
            /* The (empty) buffer is ready to take the first block. */
            rza1l_sdhi_set_phase(s, SDHI_WRITE_BUF);
            s->buf_ready = true;
            s->info2 |= INFO2_WE;
        } else {
            rza1l_sdhi_set_phase(s, SDHI_IDLE);
        }
        break;
    case SDHI_READ_WAIT:
        rza1l_sdhi_set_phase(s, SDHI_READ_BUF);
        s->buf_ready = true;
        s->info2 |= INFO2_RE;
        break;
    case SDHI_WRITE_WAIT:
        if (s->blockcnt > 0) {
            rza1l_sdhi_set_phase(s, SDHI_WRITE_BUF);
            s->buf_ready = true;
            s->info2 |= INFO2_WE;
        } else {
            rza1l_sdhi_finish(s);
        }
        break;
    case SDHI_END:
        rza1l_sdhi_finish(s);
        break;
    default:
        break;
    }
    rza1l_sdhi_update_dreq(s);
    rza1l_sdhi_update_irq(s);
}

/* The host has drained (read) or filled (write) the buffered block. */
static void rza1l_sdhi_data_block_done(RzA1lSdhiState *s)
{
    uint8_t cmd = s->cmd & SD_CMD_INDEX_MASK;
    bool flash = cmd == SD_CMD_WRITE_SINGLE || cmd == SD_CMD_WRITE_MULTIPLE;

    s->buf_ready = false;
    if (s->blockcnt) {
        s->blockcnt--;
    }
    s->datacnt = s->blocklen;

    if (s->data_dir == 1) {
        s->stats_rd_blocks++;
        if (s->blockcnt > 0) {
            /* The card streams the next block straight after. */
            rza1l_sdhi_set_phase(s, SDHI_READ_WAIT);
            rza1l_sdhi_update_dreq(s);
            rza1l_sdhi_schedule(s, rza1l_sdhi_block_ns(s));
        } else {
            rza1l_sdhi_set_phase(s, SDHI_END);
            rza1l_sdhi_update_dreq(s);
            rza1l_sdhi_schedule(s, (s->stop & SD_STOP_SEC_ENABLE) ?
                                   rza1l_sdhi_cmd12_ns(s) : 0);
        }
    } else {
        /*
         * The block crosses the bus, then the card programs it (busy on DAT0)
         * before accepting the next. After the last block the card also
         * finishes programming before access end.
         */
        int64_t ns = rza1l_sdhi_block_ns(s);

        s->stats_wr_blocks++;
        if (flash) {
            ns += (int64_t)s->write_block_us * SCALE_US;
            if (s->blockcnt == 0) {
                ns += (int64_t)s->write_busy_us * SCALE_US;
            }
        }
        if (s->blockcnt == 0 && (s->stop & SD_STOP_SEC_ENABLE)) {
            ns += rza1l_sdhi_cmd12_ns(s);
        }
        rza1l_sdhi_set_phase(s, SDHI_WRITE_WAIT);
        rza1l_sdhi_update_dreq(s);
        rza1l_sdhi_schedule(s, ns);
    }
    rza1l_sdhi_update_irq(s);
}

static uint32_t rza1l_sdhi_read_buf(RzA1lSdhiState *s, unsigned size)
{
    uint32_t val = 0;
    unsigned i;

    /* Only a block that has fully arrived in the buffer can be read. */
    if (s->phase != SDHI_READ_BUF) {
        return 0;
    }
    for (i = 0; i < size && s->datacnt; i++) {
        uint8_t b = sdbus_read_byte(&s->sdbus);
        val |= (uint32_t)b << (8 * i);
        s->datacnt--;
    }
    if (s->datacnt == 0) {
        rza1l_sdhi_data_block_done(s);
    }
    return val;
}

uint32_t rza1l_sdhi_dma_pull(void *opaque, uint8_t *buf, uint32_t len)
{
    RzA1lSdhiState *s = opaque;
    uint32_t n;

    /* As for rza1l_sdhi_read_buf: only a block that has fully arrived. */
    if (s->phase != SDHI_READ_BUF || s->data_dir != 1) {
        return 0;
    }
    n = MIN(len, s->datacnt);
    sdbus_read_data(&s->sdbus, buf, n);
    s->datacnt -= n;
    if (s->datacnt == 0) {
        rza1l_sdhi_data_block_done(s);
    }
    return n;
}

static void rza1l_sdhi_write_buf(RzA1lSdhiState *s, uint32_t val, unsigned size)
{
    unsigned i;

    if (s->phase != SDHI_WRITE_BUF) {
        return;
    }
    for (i = 0; i < size && s->datacnt; i++) {
        sdbus_write_byte(&s->sdbus, (val >> (8 * i)) & 0xff);
        s->datacnt--;
    }
    if (s->datacnt == 0) {
        rza1l_sdhi_data_block_done(s);
    }
}

static uint64_t rza1l_sdhi_read(void *opaque, hwaddr offset, unsigned size)
{
    RzA1lSdhiState *s = opaque;

    /* A status poll should see a phase that has already ended as ended. */
    rza1l_sdhi_vcpu_tick(s);

    /*
     * During a 64-byte DMA-driven read the DMAC pulls bytes from the register
     * base (SD_CMD) with a fixed source address rather than from SD_BUF0; route
     * those accesses to the data FIFO so the block is drained. Only the exact
     * DMA source offset is redirected: the real status/response registers
     * (SD_INFO1, SD_INFO2, SD_RESP*, ...) must keep returning their true values
     * because the firmware polls them while a DMA transfer is in progress.
     */
    if (s->data_dir != 0 && (s->cc_ext_mode & CC_EXT_MODE_DMASDRW) &&
        offset == SD_CMD) {
        return rza1l_sdhi_read_buf(s, size);
    }

    if (offset >= SD_RESP0 && offset <= SD_RESP7) {
        return s->resp[(offset - SD_RESP0) / 2];
    }
    if (offset == SD_INFO1 || offset == SD_INFO2) {
        rza1l_sdhi_irq_ack(s);
    }

    switch (offset) {
    case SD_CMD:
        return s->cmd;
    case SD_ARG0:
        return s->arg0;
    case SD_ARG1:
        return s->arg1;
    case SD_STOP:
        return s->stop;
    case SD_SECCNT:
        return s->seccnt;
    case SD_INFO1:
        /*
         * The CD/DAT3 level bits reflect the live card-detect state and are not
         * latching, so report them from the bus rather than from stored status
         * (which a clear-write could otherwise drop). WP is reported high
         * (not write-protected): the emulated card has no write-protect slider.
         */
        if (sdbus_get_inserted(&s->sdbus)) {
            return s->info1 | INFO1_CD_LEVEL | INFO1_DAT3_LEVEL |
                   INFO1_WP_LEVEL;
        }
        return (s->info1 & ~(INFO1_CD_LEVEL | INFO1_DAT3_LEVEL)) |
               INFO1_WP_LEVEL;
    case SD_INFO2:
        /*
         * CBSY is set from command issue until the bus is free again (access
         * end, for a data command). SCLKDIVEN reads clear while a command is on
         * the CMD line, when the SD clock may not be changed.
         */
        return s->info2 | (s->phase != SDHI_IDLE ? INFO2_CBSY : 0) |
               (s->phase != SDHI_CMD ? INFO2_SCLKDIVEN : 0);
    case SD_INFO1_MASK:
        return s->info1_mask;
    case SD_INFO2_MASK:
        return s->info2_mask;
    case SD_CLK_CTRL:
        return s->clk_ctrl;
    case SD_SIZE:
        return s->size;
    case SD_OPTION:
        return s->option;
    case SD_ERR_STS1:
        return s->err_sts1;
    case SD_ERR_STS2:
        return s->err_sts2;
    case SD_BUF0:
        return rza1l_sdhi_read_buf(s, size);
    case SDIO_MODE:
        return s->sdio_mode;
    case SDIO_INFO1:
        return s->sdio_info1;
    case SDIO_INFO1_MASK:
        return s->sdio_info1_mask;
    case CC_EXT_MODE:
        return s->cc_ext_mode;
    case SOFT_RST:
        return s->soft_rst;
    case SD_VERSION:
        return 0;
    case EXT_SWAP:
        return s->ext_swap;
    default:
        qemu_log_mask(LOG_UNIMP, "%s: unimplemented read @0x%02x\n",
                      __func__, (unsigned)offset);
        return 0;
    }
}

static void rza1l_sdhi_write(void *opaque, hwaddr offset, uint64_t value,
                             unsigned size)
{
    RzA1lSdhiState *s = opaque;
    uint16_t val = (uint16_t)value;

    /*
     * As for reads, only the exact 64-byte DMA source offset (SD_CMD) is routed
     * to the FIFO; status/control registers written by the firmware during a
     * transfer must reach their real registers.
     */
    if (s->data_dir != 0 && (s->cc_ext_mode & CC_EXT_MODE_DMASDRW) &&
        offset == SD_CMD) {
        rza1l_sdhi_write_buf(s, (uint32_t)value, size);
        return;
    }

    if (offset >= SD_RESP0 && offset <= SD_RESP7) {
        /* Response registers are read-only. */
        return;
    }

    switch (offset) {
    case SD_CMD:
        s->cmd = val;
        rza1l_sdhi_command(s, val);
        break;
    case SD_ARG0:
        s->arg0 = val;
        break;
    case SD_ARG1:
        s->arg1 = val;
        break;
    case SD_STOP:
        s->stop = val;
        break;
    case SD_SECCNT:
        s->seccnt = val;
        break;
    case SD_INFO1:
        /* Status register: written with 0s to clear the matching bits. */
        s->info1 &= val;
        rza1l_sdhi_update_irq(s);
        break;
    case SD_INFO2:
        s->info2 &= val;
        rza1l_sdhi_update_irq(s);
        break;
    case SD_INFO1_MASK:
        s->info1_mask = val;
        rza1l_sdhi_update_irq(s);
        break;
    case SD_INFO2_MASK:
        s->info2_mask = val;
        rza1l_sdhi_update_irq(s);
        break;
    case SD_CLK_CTRL:
        s->clk_ctrl = val;
        break;
    case SD_SIZE:
        s->size = val;
        break;
    case SD_OPTION:
        s->option = val;
        break;
    case SD_ERR_STS1:
        s->err_sts1 = val;
        break;
    case SD_ERR_STS2:
        s->err_sts2 = val;
        break;
    case SD_BUF0:
        rza1l_sdhi_write_buf(s, (uint32_t)value, size);
        break;
    case SDIO_MODE:
        s->sdio_mode = val;
        break;
    case SDIO_INFO1:
        s->sdio_info1 &= val;
        break;
    case SDIO_INFO1_MASK:
        s->sdio_info1_mask = val;
        break;
    case CC_EXT_MODE:
        s->cc_ext_mode = val;
        rza1l_sdhi_update_dreq(s);
        break;
    case SOFT_RST:
        s->soft_rst = val;
        /* Asserting reset (bit 0 clear) aborts any in-flight transfer. */
        if (!(val & 0x0001)) {
            rza1l_sdhi_abort(s);
            rza1l_sdhi_update_irq(s);
        }
        break;
    case EXT_SWAP:
        s->ext_swap = val;
        break;
    default:
        qemu_log_mask(LOG_UNIMP, "%s: unimplemented write @0x%02x = 0x%04x\n",
                      __func__, (unsigned)offset, val);
        break;
    }
}

static const MemoryRegionOps rza1l_sdhi_ops = {
    .read = rza1l_sdhi_read,
    .write = rza1l_sdhi_write,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 1,
        .max_access_size = 4,
    },
    .impl = {
        .min_access_size = 1,
        .max_access_size = 4,
    },
};

static void rza1l_sdhi_init(Object *obj)
{
    RzA1lSdhiState *s = RZA1L_SDHI(obj);

    qbus_init(&s->sdbus, sizeof(s->sdbus), TYPE_SD_BUS, DEVICE(s), "sd-bus");

    memory_region_init_io(&s->iomem, obj, &rza1l_sdhi_ops, s,
                          TYPE_RZA1L_SDHI, RZA1L_SDHI_MMIO_SIZE);
    sysbus_init_mmio(SYS_BUS_DEVICE(s), &s->iomem);
    sysbus_init_irq(SYS_BUS_DEVICE(s), &s->irq);
    qdev_init_gpio_out_named(DEVICE(s), &s->dreq, RZA1L_SDHI_DREQ, 1);

    s->timer = timer_new_ns(QEMU_CLOCK_VIRTUAL, rza1l_sdhi_timer_cb, s);

    object_property_add_uint64_ptr(obj, "dz-cmd-count", &s->total_cmds,
                                   OBJ_PROP_FLAG_READ);
}

static void rza1l_sdhi_realize(DeviceState *dev, Error **errp)
{
    RzA1lSdhiState *s = RZA1L_SDHI(dev);

    deluge_vcpu_tick_register(rza1l_sdhi_vcpu_tick, s);

    if (rza1l_sdhi_stats_enabled() && !s->stats_timer) {
        s->stats_timer = timer_new_ns(QEMU_CLOCK_VIRTUAL,
                                      rza1l_sdhi_stats_tick, s);
        timer_mod(s->stats_timer, qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL) +
                                  NANOSECONDS_PER_SECOND);
    }
}

static void rza1l_sdhi_reset(DeviceState *dev)
{
    RzA1lSdhiState *s = RZA1L_SDHI(dev);

    s->cmd = 0;
    s->arg0 = 0;
    s->arg1 = 0;
    s->stop = 0;
    s->seccnt = 0;
    s->size = 0;
    memset(s->resp, 0, sizeof(s->resp));
    s->info1 = 0;
    s->info2 = 0;
    /* Interrupts start fully masked (register bits set = disabled). */
    s->info1_mask = 0xffff;
    s->info2_mask = 0xffff;
    s->clk_ctrl = 0;
    s->option = 0;
    s->err_sts1 = 0;
    s->err_sts2 = 0;
    s->sdio_mode = 0;
    s->sdio_info1 = 0;
    s->sdio_info1_mask = 0xffff;
    s->cc_ext_mode = 0;
    s->soft_rst = 0;
    s->ext_swap = 0;
    s->blocklen = 0;
    rza1l_sdhi_abort(s);
    s->pending_info2 = 0;
    s->on_deadline = false;

    s->irq_level = false;
    s->irq_unacked = false;
    qemu_set_irq(s->irq, 0);
}

static const VMStateDescription vmstate_rza1l_sdhi = {
    .name = TYPE_RZA1L_SDHI,
    .version_id = 3,
    .minimum_version_id = 3,
    .fields = (const VMStateField[]) {
        VMSTATE_UINT16(cmd, RzA1lSdhiState),
        VMSTATE_UINT16(arg0, RzA1lSdhiState),
        VMSTATE_UINT16(arg1, RzA1lSdhiState),
        VMSTATE_UINT16(stop, RzA1lSdhiState),
        VMSTATE_UINT16(seccnt, RzA1lSdhiState),
        VMSTATE_UINT16(size, RzA1lSdhiState),
        VMSTATE_UINT16_ARRAY(resp, RzA1lSdhiState, 8),
        VMSTATE_UINT16(info1, RzA1lSdhiState),
        VMSTATE_UINT16(info2, RzA1lSdhiState),
        VMSTATE_UINT16(info1_mask, RzA1lSdhiState),
        VMSTATE_UINT16(info2_mask, RzA1lSdhiState),
        VMSTATE_UINT16(clk_ctrl, RzA1lSdhiState),
        VMSTATE_UINT16(option, RzA1lSdhiState),
        VMSTATE_UINT16(err_sts1, RzA1lSdhiState),
        VMSTATE_UINT16(err_sts2, RzA1lSdhiState),
        VMSTATE_UINT16(sdio_mode, RzA1lSdhiState),
        VMSTATE_UINT16(sdio_info1, RzA1lSdhiState),
        VMSTATE_UINT16(sdio_info1_mask, RzA1lSdhiState),
        VMSTATE_UINT16(cc_ext_mode, RzA1lSdhiState),
        VMSTATE_UINT16(soft_rst, RzA1lSdhiState),
        VMSTATE_UINT16(ext_swap, RzA1lSdhiState),
        VMSTATE_UINT8(data_dir, RzA1lSdhiState),
        VMSTATE_UINT32(blocklen, RzA1lSdhiState),
        VMSTATE_UINT32(blockcnt, RzA1lSdhiState),
        VMSTATE_UINT32(datacnt, RzA1lSdhiState),
        VMSTATE_TIMER_PTR(timer, RzA1lSdhiState),
        VMSTATE_UINT8(phase, RzA1lSdhiState),
        VMSTATE_BOOL(buf_ready, RzA1lSdhiState),
        VMSTATE_UINT16(pending_info2, RzA1lSdhiState),
        VMSTATE_INT64(deadline_ns, RzA1lSdhiState),
        VMSTATE_END_OF_LIST()
    }
};

/*
 * Card timing defaults, typical of a class-10 SDHC card: ~300 us to fetch the
 * first block of a read from flash; for writes ~20 us of programming per block
 * of a multi-block write and ~1 ms of busy to commit the write at the end
 * (small random writes, e.g. FAT updates, are dominated by the latter).
 */
static const Property rza1l_sdhi_props[] = {
    DEFINE_PROP_BOOL("timing", RzA1lSdhiState, timing, true),
    DEFINE_PROP_UINT32("read-latency-us", RzA1lSdhiState, read_latency_us,
                       300),
    DEFINE_PROP_UINT32("write-block-us", RzA1lSdhiState, write_block_us, 20),
    DEFINE_PROP_UINT32("write-busy-us", RzA1lSdhiState, write_busy_us, 1000),
};

static void rza1l_sdhi_class_init(ObjectClass *klass, const void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    device_class_set_legacy_reset(dc, rza1l_sdhi_reset);
    dc->realize = rza1l_sdhi_realize;
    dc->vmsd = &vmstate_rza1l_sdhi;
    device_class_set_props(dc, rza1l_sdhi_props);
    dc->user_creatable = false;
}

static const TypeInfo rza1l_sdhi_info = {
    .name          = TYPE_RZA1L_SDHI,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(RzA1lSdhiState),
    .instance_init = rza1l_sdhi_init,
    .class_init    = rza1l_sdhi_class_init,
};

static void rza1l_sdhi_register_types(void)
{
    type_register_static(&rza1l_sdhi_info);
}

type_init(rza1l_sdhi_register_types)
