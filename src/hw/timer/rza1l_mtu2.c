/*
 * Renesas RZ/A1 MTU2 (Multi-Function Timer Pulse Unit 2)
 *
 * The stock Deluge firmware runs MTU2 channels 0, 1 and 4 as free-running
 * time bases for busy-wait delays and timeouts, each at its own prescale of
 * P0phi (TIMER_SYSTEM_FAST = ch0 /64, SUPERFAST = ch1 /1, SLOW = ch4 /1024):
 *
 *   start = *TCNT[TIMER_SYSTEM_SLOW];
 *   while ((uint16_t)(*TCNT[TIMER_SYSTEM_SLOW] - start) < ticks);
 *
 * and channel 2 as a one-shot compare-match timer for MIDI and gate output.
 * The Rust-BSP firmware arms channel 3 as a periodic 1 ms compare-match
 * interrupt that polls the encoder pins, and channel 2 for MIDI/gate output.
 *
 * Modelled, per channel 0-4:
 *  - TSTR.CSTn starts and stops the counter; a stopped counter holds its count.
 *  - TCR.TPSC selects the internal clock, P0phi / 1, 4, 16, 64, 256 or 1024 as
 *    the channel offers it. The external clocks (TCLKA-D, TCNT2 overflow) have
 *    no input here: a channel set to one holds its count.
 *  - TCR.CCLR = 001 clears TCNT on the TGRA compare match, so the counter runs
 *    0..TGRA and matches every TGRA + 1 counts. Any other CCLR leaves the
 *    counter free-running through 0xFFFF, matching TGRA once per wrap.
 *  - TSR.TGFA is set on the compare match and cleared by writing 0 to it after
 *    reading it as 1 (hardware manual, MTU2 TSR).
 *  - TGInA is held high while TSR.TGFA and TIER.TGIEA are both set.
 * The other compare registers (TGRB-F), input capture, PWM and complementary
 * modes, the overflow flag and the synchronous counter (TCNTS) are not
 * modelled; their bytes read back what was written.
 *
 * Counts are a function of the virtual clock, so -icount runs stay
 * deterministic; one QEMU_CLOCK_VIRTUAL timer per running channel fires at its
 * next compare match.
 *
 * Register offsets (from the firmware's st_mtu2):
 *   ch  TCR    TIER   TSR    TCNT   TGRA   TSTR bit
 *   0   0x300  0x304  0x305  0x306  0x308  0 (0x01)
 *   1   0x380  0x384  0x385  0x386  0x388  1 (0x02)
 *   2   0x000  0x004  0x005  0x006  0x008  2 (0x04)
 *   3   0x200  0x208  0x22C  0x210  0x218  6 (0x40)
 *   4   0x201  0x209  0x22D  0x212  0x21C  7 (0x80)
 *   TSTR 0x280, TRWER 0x284 (the write gate is not modelled: always open).
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/log.h"
#include "qemu/host-utils.h"
#include "qemu/timer.h"
#include "migration/vmstate.h"
#include "hw/core/irq.h"
#include "hw/misc/deluge_vcpu_tick.h"
#include "hw/timer/rza1l_mtu2.h"

/*
 * MTU2 input clock: the peripheral clock P0phi (~33.33 MHz, the same rate the
 * OSTM model counts at).
 */
#define RZA1L_MTU2_CLK_HZ 33333333u

#define MTU2_TSTR 0x280

#define MTU2_TCR_TPSC_MASK 0x07
#define MTU2_TCR_CCLR_MASK 0xe0
#define MTU2_TCR_CCLR_TGRA 0x20

#define MTU2_TIER_TGIEA 0x01
#define MTU2_TSR_TGFA 0x01
/* TSR's upper bits read 1 (TCFD and a reserved bit). */
#define MTU2_TSR_FIXED 0xc0

static const struct {
    hwaddr tcr, tier, tsr, tcnt, tgra;
    uint8_t cst;
    /* P0phi divisor for each TPSC value; 0 = an external clock (held). */
    uint16_t div[8];
} rza1l_mtu2_ch[RZA1L_MTU2_NUM_CH] = {
    { 0x300, 0x304, 0x305, 0x306, 0x308, 0x01, { 1, 4, 16, 64, 0, 0, 0, 0 } },
    { 0x380, 0x384, 0x385, 0x386, 0x388, 0x02, { 1, 4, 16, 64, 0, 0, 256, 0 } },
    { 0x000, 0x004, 0x005, 0x006, 0x008, 0x04, { 1, 4, 16, 64, 0, 0, 0, 1024 } },
    { 0x200, 0x208, 0x22c, 0x210, 0x218, 0x40,
      { 1, 4, 16, 64, 256, 1024, 0, 0 } },
    { 0x201, 0x209, 0x22d, 0x212, 0x21c, 0x80,
      { 1, 4, 16, 64, 256, 1024, 0, 0 } },
};

/* True if the access [offset, offset + size) touches [reg, reg + len). */
static bool rza1l_mtu2_overlaps(hwaddr offset, unsigned size, hwaddr reg,
                                unsigned len)
{
    return offset < reg + len && reg < offset + size;
}

static unsigned rza1l_mtu2_div(RzA1lMtu2State *s, int n)
{
    return rza1l_mtu2_ch[n].div[s->ch[n].tcr & MTU2_TCR_TPSC_MASK];
}

/* Counts per compare match: TGRA + 1 when TGRA clears the counter, else 2^16. */
static uint64_t rza1l_mtu2_period(RzA1lMtu2Channel *c)
{
    if ((c->tcr & MTU2_TCR_CCLR_MASK) == MTU2_TCR_CCLR_TGRA) {
        return (uint64_t)c->tgra + 1;
    }
    return 1ull << 16;
}

/* Whole counts since base_ns, or 0 if the channel is not counting. */
static uint64_t rza1l_mtu2_ticks(RzA1lMtu2State *s, int n, int64_t now)
{
    RzA1lMtu2Channel *c = &s->ch[n];
    unsigned div = rza1l_mtu2_div(s, n);

    if (!c->running || !div || now <= c->base_ns) {
        return 0;
    }
    return muldiv64(now - c->base_ns, RZA1L_MTU2_CLK_HZ,
                    NANOSECONDS_PER_SECOND) / div;
}

/* Virtual-clock time at which count `ticks` after base_ns is reached. */
static int64_t rza1l_mtu2_ns_at(RzA1lMtu2State *s, int n, uint64_t ticks)
{
    return s->ch[n].base_ns +
           (int64_t)muldiv64_round_up(ticks * rza1l_mtu2_div(s, n),
                                      NANOSECONDS_PER_SECOND,
                                      RZA1L_MTU2_CLK_HZ);
}

/* Counts from base until TCNT next reaches TGRA. */
static uint64_t rza1l_mtu2_to_tgra(RzA1lMtu2Channel *c)
{
    return (uint16_t)(c->tgra - c->base);
}

/* TCNT `ticks` counts after base_ns. */
static uint16_t rza1l_mtu2_count_at(RzA1lMtu2Channel *c, uint64_t ticks)
{
    uint64_t d = rza1l_mtu2_to_tgra(c);

    if ((c->tcr & MTU2_TCR_CCLR_MASK) != MTU2_TCR_CCLR_TGRA || ticks <= d) {
        return (uint16_t)(c->base + ticks);
    }
    /* Cleared to 0 on the count after each match at TGRA. */
    return (ticks - d - 1) % rza1l_mtu2_period(c);
}

static uint16_t rza1l_mtu2_count(RzA1lMtu2State *s, int n, int64_t now)
{
    return rza1l_mtu2_count_at(&s->ch[n], rza1l_mtu2_ticks(s, n, now));
}

/*
 * Re-base the count to the last whole count at `now`, before anything that
 * sets how the channel counts changes.
 */
static void rza1l_mtu2_sync(RzA1lMtu2State *s, int n, int64_t now)
{
    RzA1lMtu2Channel *c = &s->ch[n];
    uint64_t ticks = rza1l_mtu2_ticks(s, n, now);

    if (!ticks) {
        return;
    }
    c->base = rza1l_mtu2_count_at(c, ticks);
    c->base_ns = rza1l_mtu2_ns_at(s, n, ticks);
}

static void rza1l_mtu2_update_irq(RzA1lMtu2State *s, int n)
{
    RzA1lMtu2Channel *c = &s->ch[n];
    bool tgiea = s->regs[rza1l_mtu2_ch[n].tier] & MTU2_TIER_TGIEA;

    qemu_set_irq(c->irq, c->tgfa && tgiea);
}

/* Arm the channel's timer for its next compare match after `now`. */
static void rza1l_mtu2_schedule(RzA1lMtu2State *s, int n, int64_t now)
{
    RzA1lMtu2Channel *c = &s->ch[n];
    uint64_t first, period, ticks, next;

    if (!c->running || !rza1l_mtu2_div(s, n)) {
        timer_del(c->timer);
        return;
    }
    period = rza1l_mtu2_period(c);
    /* A count that starts on TGRA matches only when it comes round again. */
    first = rza1l_mtu2_to_tgra(c);
    if (!first) {
        first = period;
    }
    ticks = rza1l_mtu2_ticks(s, n, now);
    if (ticks < first) {
        next = first;
    } else {
        next = first + ((ticks - first) / period + 1) * period;
    }
    timer_mod(c->timer, MAX(rza1l_mtu2_ns_at(s, n, next), now + 1));
}

static void rza1l_mtu2_match(RzA1lMtu2State *s, int n, int64_t now)
{
    RzA1lMtu2Channel *c = &s->ch[n];

    if (!c->tgfa) {
        c->tgfa = true;
        c->tgfa_read = false;
    }
    rza1l_mtu2_update_irq(s, n);
    rza1l_mtu2_schedule(s, n, now);
}

/* Take a compare match that has fallen due but whose timer has not yet run. */
static void rza1l_mtu2_catch_up(RzA1lMtu2State *s, int n, int64_t now)
{
    QEMUTimer *t = s->ch[n].timer;

    if (timer_pending(t) && timer_expire_time_ns(t) <= now) {
        timer_del(t);
        rza1l_mtu2_match(s, n, now);
    }
}

static void rza1l_mtu2_vcpu_tick(void *opaque)
{
    RzA1lMtu2State *s = opaque;
    int64_t now = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);

    for (int n = 0; n < RZA1L_MTU2_NUM_CH; n++) {
        rza1l_mtu2_catch_up(s, n, now);
    }
}

static void rza1l_mtu2_fire(void *opaque)
{
    RzA1lMtu2Channel *c = opaque;

    rza1l_mtu2_match(c->mtu2, c->index, qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL));
}

static uint8_t rza1l_mtu2_read_byte(RzA1lMtu2State *s, hwaddr boff,
                                    int64_t now)
{
    for (int n = 0; n < RZA1L_MTU2_NUM_CH; n++) {
        RzA1lMtu2Channel *c = &s->ch[n];

        if (boff == rza1l_mtu2_ch[n].tsr) {
            if (c->tgfa) {
                c->tgfa_read = true;
            }
            return MTU2_TSR_FIXED | (c->tgfa ? MTU2_TSR_TGFA : 0);
        }
        if (boff == rza1l_mtu2_ch[n].tcnt || boff == rza1l_mtu2_ch[n].tcnt + 1) {
            uint16_t cnt = rza1l_mtu2_count(s, n, now);
            return cnt >> ((boff - rza1l_mtu2_ch[n].tcnt) * 8);
        }
    }
    return s->regs[boff];
}

static uint64_t rza1l_mtu2_read(void *opaque, hwaddr offset, unsigned size)
{
    RzA1lMtu2State *s = opaque;
    int64_t now;
    uint64_t val = 0;

    /* The firmware's tick source: let fine-grained device timers catch up. */
    deluge_vcpu_tick();

    now = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);
    for (unsigned i = 0; i < size; i++) {
        val |= (uint64_t)rza1l_mtu2_read_byte(s, offset + i, now) << (8 * i);
    }
    return val;
}

static void rza1l_mtu2_write(void *opaque, hwaddr offset, uint64_t value,
                             unsigned size)
{
    RzA1lMtu2State *s = opaque;
    int64_t now = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);
    bool counting[RZA1L_MTU2_NUM_CH], tcnt[RZA1L_MTU2_NUM_CH];
    bool tsr[RZA1L_MTU2_NUM_CH];
    /* TSTR bits this write changes. */
    uint8_t cst_changed = 0;

    if (rza1l_mtu2_overlaps(offset, size, MTU2_TSTR, 1)) {
        uint8_t tstr = value >> (8 * (MTU2_TSTR - offset));
        cst_changed = tstr ^ s->regs[MTU2_TSTR];
    }

    /*
     * Settle each channel the write reconfigures at its old settings: take a
     * match already due, and re-base its count to now.
     */
    for (int n = 0; n < RZA1L_MTU2_NUM_CH; n++) {
        tcnt[n] = rza1l_mtu2_overlaps(offset, size, rza1l_mtu2_ch[n].tcnt, 2);
        tsr[n] = rza1l_mtu2_overlaps(offset, size, rza1l_mtu2_ch[n].tsr, 1);
        counting[n] =
            (cst_changed & rza1l_mtu2_ch[n].cst) || tcnt[n] ||
            rza1l_mtu2_overlaps(offset, size, rza1l_mtu2_ch[n].tcr, 1) ||
            rza1l_mtu2_overlaps(offset, size, rza1l_mtu2_ch[n].tgra, 2);
        if (counting[n]) {
            rza1l_mtu2_catch_up(s, n, now);
            rza1l_mtu2_sync(s, n, now);
        }
        if (tcnt[n]) {
            /* A byte write to TCNT keeps the live count's other byte. */
            stw_le_p(&s->regs[rza1l_mtu2_ch[n].tcnt],
                     rza1l_mtu2_count(s, n, now));
        }
    }

    for (unsigned i = 0; i < size; i++) {
        hwaddr boff = offset + i;
        uint8_t b = (value >> (8 * i)) & 0xff;
        bool is_tsr = false;

        for (int n = 0; n < RZA1L_MTU2_NUM_CH; n++) {
            RzA1lMtu2Channel *c = &s->ch[n];

            if (boff != rza1l_mtu2_ch[n].tsr) {
                continue;
            }
            is_tsr = true;
            /* TGFA clears on a 0 written after reading it as 1. */
            if (!(b & MTU2_TSR_TGFA) && c->tgfa_read) {
                c->tgfa = false;
                c->tgfa_read = false;
            }
        }
        if (!is_tsr) {
            s->regs[boff] = b;
        }
    }

    for (int n = 0; n < RZA1L_MTU2_NUM_CH; n++) {
        RzA1lMtu2Channel *c = &s->ch[n];

        if (counting[n]) {
            bool run = s->regs[MTU2_TSTR] & rza1l_mtu2_ch[n].cst;

            c->tcr = s->regs[rza1l_mtu2_ch[n].tcr];
            c->tgra = lduw_le_p(&s->regs[rza1l_mtu2_ch[n].tgra]);
            if (tcnt[n]) {
                c->base = lduw_le_p(&s->regs[rza1l_mtu2_ch[n].tcnt]);
                c->base_ns = now;
            }
            if (run && !c->running) {
                /* Counting starts from the held count. */
                c->base_ns = now;
            }
            c->running = run;
            rza1l_mtu2_schedule(s, n, now);
        }
        if (tsr[n] ||
            rza1l_mtu2_overlaps(offset, size, rza1l_mtu2_ch[n].tier, 1)) {
            rza1l_mtu2_update_irq(s, n);
        }
    }
}

static const MemoryRegionOps rza1l_mtu2_ops = {
    .read = rza1l_mtu2_read,
    .write = rza1l_mtu2_write,
    .endianness = DEVICE_NATIVE_ENDIAN,
    .valid.min_access_size = 1,
    .valid.max_access_size = 4,
};

static void rza1l_mtu2_reset(DeviceState *dev)
{
    RzA1lMtu2State *s = RZA1L_MTU2(dev);

    memset(s->regs, 0, sizeof(s->regs));
    for (int n = 0; n < RZA1L_MTU2_NUM_CH; n++) {
        RzA1lMtu2Channel *c = &s->ch[n];

        timer_del(c->timer);
        c->base_ns = 0;
        c->base = 0;
        c->tgra = 0xffff;
        stw_le_p(&s->regs[rza1l_mtu2_ch[n].tgra], 0xffff);
        c->tcr = 0;
        c->running = false;
        c->tgfa = false;
        c->tgfa_read = false;
        qemu_set_irq(c->irq, 0);
    }
}

static void rza1l_mtu2_realize(DeviceState *dev, Error **errp)
{
    RzA1lMtu2State *s = RZA1L_MTU2(dev);
    SysBusDevice *sbd = SYS_BUS_DEVICE(dev);

    memory_region_init_io(&s->iomem, OBJECT(dev), &rza1l_mtu2_ops, s,
                          TYPE_RZA1L_MTU2, RZA1L_MTU2_MMIO_SIZE);
    sysbus_init_mmio(sbd, &s->iomem);
    for (int n = 0; n < RZA1L_MTU2_NUM_CH; n++) {
        s->ch[n].mtu2 = s;
        s->ch[n].index = n;
        s->ch[n].timer = timer_new_ns(QEMU_CLOCK_VIRTUAL, rza1l_mtu2_fire,
                                      &s->ch[n]);
        sysbus_init_irq(sbd, &s->ch[n].irq);
    }
    deluge_vcpu_tick_register(rza1l_mtu2_vcpu_tick, s);
}

static const VMStateDescription vmstate_rza1l_mtu2_channel = {
    .name = "rza1l-mtu2-channel",
    .version_id = 1,
    .minimum_version_id = 1,
    .fields = (const VMStateField[]) {
        VMSTATE_TIMER_PTR(timer, RzA1lMtu2Channel),
        VMSTATE_INT64(base_ns, RzA1lMtu2Channel),
        VMSTATE_UINT16(base, RzA1lMtu2Channel),
        VMSTATE_UINT16(tgra, RzA1lMtu2Channel),
        VMSTATE_UINT8(tcr, RzA1lMtu2Channel),
        VMSTATE_BOOL(running, RzA1lMtu2Channel),
        VMSTATE_BOOL(tgfa, RzA1lMtu2Channel),
        VMSTATE_BOOL(tgfa_read, RzA1lMtu2Channel),
        VMSTATE_END_OF_LIST()
    },
};

static const VMStateDescription vmstate_rza1l_mtu2 = {
    .name = TYPE_RZA1L_MTU2,
    .version_id = 2,
    .minimum_version_id = 2,
    .fields = (const VMStateField[]) {
        VMSTATE_STRUCT_ARRAY(ch, RzA1lMtu2State, RZA1L_MTU2_NUM_CH, 1,
                             vmstate_rza1l_mtu2_channel, RzA1lMtu2Channel),
        VMSTATE_UINT8_ARRAY(regs, RzA1lMtu2State, RZA1L_MTU2_MMIO_SIZE),
        VMSTATE_END_OF_LIST()
    },
};

static void rza1l_mtu2_class_init(ObjectClass *klass, const void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->realize = rza1l_mtu2_realize;
    dc->vmsd = &vmstate_rza1l_mtu2;
    device_class_set_legacy_reset(dc, rza1l_mtu2_reset);
}

static const TypeInfo rza1l_mtu2_info = {
    .name          = TYPE_RZA1L_MTU2,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(RzA1lMtu2State),
    .class_init    = rza1l_mtu2_class_init,
};

static void rza1l_mtu2_register_types(void)
{
    type_register_static(&rza1l_mtu2_info);
}

type_init(rza1l_mtu2_register_types)
