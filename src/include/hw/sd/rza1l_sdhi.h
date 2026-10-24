/*
 * Renesas RZ/A1L SDHI (SD Host Interface) controller model
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef HW_SD_RZA1L_SDHI_H
#define HW_SD_RZA1L_SDHI_H

#include "hw/core/sysbus.h"
#include "hw/sd/sd.h"
#include "qemu/timer.h"
#include "qom/object.h"

#define TYPE_RZA1L_SDHI "rza1l-sdhi"
OBJECT_DECLARE_SIMPLE_TYPE(RzA1lSdhiState, RZA1L_SDHI)

/* Named GPIO output: the DMA request line, high while the buffer is ready. */
#define RZA1L_SDHI_DREQ "dreq"

/* MMIO window: registers span SD_CMD (0x00) .. EXT_SWAP (0xF0). */
#define RZA1L_SDHI_MMIO_SIZE 0x100

struct RzA1lSdhiState {
    /*< private >*/
    SysBusDevice parent_obj;

    /*< public >*/
    MemoryRegion iomem;
    SDBus sdbus;
    qemu_irq irq;

    /* Command/argument registers. */
    uint16_t cmd;
    uint16_t arg0;
    uint16_t arg1;
    uint16_t stop;
    /* The data command's SD_CMD mode bits allow the controller's auto CMD12. */
    bool auto_cmd12;
    uint16_t seccnt;
    uint16_t size;

    /* Response registers (SD_RESP0..SD_RESP7). */
    uint16_t resp[8];

    /* Status and interrupt-mask registers. */
    uint16_t info1;
    uint16_t info2;
    uint16_t info1_mask;
    uint16_t info2_mask;

    /* Misc shadowed registers. */
    uint16_t clk_ctrl;
    uint16_t option;
    uint16_t err_sts1;
    uint16_t err_sts2;
    uint16_t sdio_mode;
    uint16_t sdio_info1;
    uint16_t sdio_info1_mask;
    uint16_t cc_ext_mode;
    uint16_t soft_rst;
    uint16_t ext_swap;

    /* In-flight data transfer state. */
    uint8_t  data_dir;   /* 0 = none, 1 = read (card->host), 2 = write */
    uint32_t blocklen;   /* bytes per block (from SD_SIZE) */
    uint32_t blockcnt;   /* blocks still to transfer (from SD_SECCNT) */
    uint32_t datacnt;    /* bytes left in the current block */

    /*
     * Bus timing model. Each command and data block occupies the SD bus for
     * as long as it would on hardware at the programmed SD clock and bus
     * width, plus the card's access latency (reads) and programming busy time
     * (writes). `phase` is the step the controller is in; `timer` fires when
     * that step's bus activity ends. `buf_ready` means the data buffer holds a
     * block to read (or has room for one to write); it drives `dreq`, the DMA
     * request line to the DMAC's SDHI channel.
     */
    QEMUTimer *timer;
    qemu_irq dreq;
    uint8_t  phase;
    bool     buf_ready;
    uint16_t pending_info2;  /* error bits to report with the response */

    /*
     * When the current phase is due to end. Phases are timed from the
     * previous phase's deadline rather than from when it was serviced, so a
     * late timer doesn't stretch the rest of a transfer. `on_deadline` is set
     * while the controller handles a phase end, so anything that follows
     * within the same step (a DMA drain of the block just made ready, the
     * next block, the stats) happens at the deadline.
     */
    int64_t  deadline_ns;
    bool     on_deadline;

    /* Properties. */
    bool     timing;         /* false: every step completes instantly */
    uint32_t read_latency_us;
    uint32_t write_block_us;
    uint32_t write_busy_us;

    /*
     * Commands issued since power-on, exported read-only as the QOM property
     * dz-cmd-count so scripts can wait for the card to go quiet (e.g. for a
     * song load to finish).
     */
    uint64_t total_cmds;

    /* DELUGEMU_SDHI_STATS probe (per virtual-second activity summary). */
    QEMUTimer *stats_timer;
    int64_t  phase_since_ns;   /* when the current phase began */
    int64_t  stats_bus_ns;     /* time the bus or card was working */
    int64_t  stats_buf_ns;     /* time a block waited on the host */
    bool     irq_level;
    bool     irq_unacked;      /* raised, status not read yet */
    int64_t  irq_raised_ns;
    uint32_t stats_irqs;
    int64_t  stats_irq_sum_ns;
    int64_t  stats_irq_max_ns;
    uint32_t stats_cmds;
    uint32_t stats_rd_blocks;
    uint32_t stats_wr_blocks;
};

/*
 * DMA bulk read (an RzA1lDmacPullFn): copy up to `len` bytes of the block
 * waiting in the data buffer, as that many reads of the data register would.
 */
uint32_t rza1l_sdhi_dma_pull(void *opaque, uint8_t *buf, uint32_t len);

#endif /* HW_SD_RZA1L_SDHI_H */
