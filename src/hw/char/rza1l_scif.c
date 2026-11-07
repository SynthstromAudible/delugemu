/*
 * Renesas RZ/A1 SCIF (serial communication interface with FIFO)
 *
 * Models one SCIF channel as a UART. Transmit is synchronous: a byte written
 * to the transmit FIFO data register (SCFTDR) is pushed straight to the
 * character backend and the FIFO is reported permanently ready (TDFE|TEND).
 * With DELUGEMU_SCIF_STRICT set, the DIN MIDI channel instead models the
 * hardware's 16-byte transmit FIFO, its TXI DMA request and lost writes to a
 * full FIFO (see rza1l_scif_tx_update).
 * Receive is interrupt-driven: an incoming byte is latched, the receive-data
 * flags (RDF|DR) are set, and the RXI interrupt is asserted when receive
 * interrupts are enabled (SCSCR.RIE). Reading SCFRDR returns the byte and
 * clears the receive state.
 *
 * Register offsets within a channel (verified via offsetof on st_scif):
 *   SCSMR 0x00  SCBRR 0x04  SCSCR 0x08  SCFTDR 0x0C  SCFSR 0x10
 *   SCFRDR 0x14 SCFCR 0x18  SCFDR 0x1C  SCSPTR 0x20  SCLSR 0x24  SCEMR 0x28
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/log.h"
#include "qapi/error.h"
#include "hw/core/qdev-properties.h"
#include "hw/core/qdev-properties-system.h"
#include "hw/core/irq.h"
#include "migration/vmstate.h"
#include "hw/char/rza1l_scif.h"
#include "hw/dma/rza1l_dmac.h"
#include "qemu/timer.h"

/* Channel register offsets. */
#define SCIF_SCSMR  0x00 /* serial mode            (16) */
#define SCIF_SCBRR  0x04 /* bit rate               (8)  */
#define SCIF_SCSCR  0x08 /* serial control         (16) */
#define SCIF_SCFTDR 0x0C /* transmit FIFO data     (8)  */
#define SCIF_SCFSR  0x10 /* serial status          (16) */
#define SCIF_SCFRDR 0x14 /* receive FIFO data      (8)  */
#define SCIF_SCFCR  0x18 /* FIFO control           (16) */
#define SCIF_SCFDR  0x1C /* FIFO data count        (16) */
#define SCIF_SCSPTR 0x20 /* serial port            (16) */
#define SCIF_SCLSR  0x24 /* line status            (16) */
#define SCIF_SCEMR  0x28 /* serial extended mode   (16) */

/* SCSCR control bits. */
#define SCSCR_RE  0x0010 /* receive enable             */
#define SCSCR_TE  0x0020 /* transmit enable            */
#define SCSCR_RIE 0x0040 /* receive interrupt enable   */
#define SCSCR_TIE 0x0080 /* transmit interrupt enable  */

/* SCFSR status bits. */
#define SCFSR_DR   0x0001 /* receive data ready         */
#define SCFSR_RDF  0x0002 /* receive FIFO data full     */
#define SCFSR_TDFE 0x0020 /* transmit FIFO data empty   */
#define SCFSR_TEND 0x0040 /* transmit end               */

static void rza1l_scif_update_irq(RzA1lScifState *s)
{
    bool rx = (s->scscr & SCSCR_RIE) && s->rx_full;

    qemu_set_irq(s->irq, rx);
}

/* Transmit FIFO capacity, and TDFE trigger levels by SCFCR.TTRG (manual 14.3). */
#define SCIF_TX_FIFO_SIZE 16
#define SCFCR_TFRST 0x0004
static const uint8_t scif_ttrg_levels[4] = { 8, 4, 2, 0 };

static unsigned rza1l_scif_tx_trigger(RzA1lScifState *s)
{
    return scif_ttrg_levels[(s->scfcr >> 4) & 3];
}

/* Let the transmitter shift out whatever it has finished by `now`. */
static void rza1l_scif_tx_drain(RzA1lScifState *s, int64_t now)
{
    while (s->tx_count && s->tx_done_ns <= now) {
        s->tx_count--;
        if (s->tx_count) {
            s->tx_done_ns += s->tx_char_ns;
        }
    }
}

/*
 * Recompute TDFE and drive the TXI DMA request: asserted while the FIFO holds
 * no more than the trigger level, with transmit and its interrupt enabled.
 * While it's above the trigger, wake when it drains down to it.
 */
static void rza1l_scif_tx_update(RzA1lScifState *s)
{
    int64_t now = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);
    unsigned trigger;

    if (!s->tx_strict) {
        return;
    }
    rza1l_scif_tx_drain(s, now);
    trigger = rza1l_scif_tx_trigger(s);
    if (s->tx_count > trigger) {
        timer_mod(s->tx_timer,
                  s->tx_done_ns + (int64_t)(s->tx_count - trigger - 1) * s->tx_char_ns);
    }
    rza1l_dmac_scif_txi_set(s->dmac, s->tx_count <= trigger &&
                                     (s->scscr & SCSCR_TE) && (s->scscr & SCSCR_TIE));
}

static void rza1l_scif_tx_timer(void *opaque)
{
    rza1l_scif_tx_update(opaque);
}

/* A byte written to SCFTDR in strict mode: queued, or lost if the FIFO's full. */
static void rza1l_scif_tx_write(RzA1lScifState *s, uint8_t b)
{
    int64_t now = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);

    rza1l_scif_tx_drain(s, now);
    if (s->tx_count >= SCIF_TX_FIFO_SIZE) {
        s->tx_dropped++;
        qemu_log("rza1l-scif strict: transmit FIFO full, byte 0x%02x ignored "
                 "(%u dropped so far)\n", b, s->tx_dropped);
    } else {
        if (s->tx_count == 0) {
            s->tx_done_ns = now + s->tx_char_ns;
        }
        s->tx_count++;
        qemu_chr_fe_write_all(&s->chr, &b, 1);
    }
    rza1l_scif_tx_update(s);
}

static uint64_t rza1l_scif_read(void *opaque, hwaddr offset, unsigned size)
{
    RzA1lScifState *s = opaque;

    switch (offset) {
    case SCIF_SCSMR:
        return s->scsmr;
    case SCIF_SCBRR:
        return s->scbrr;
    case SCIF_SCSCR:
        return s->scscr;
    case SCIF_SCFSR: {
        /*
         * Lenient: transmit is always ready. Strict: TDFE while the FIFO is at
         * or below its trigger level, TEND once it's empty.
         */
        uint16_t tx = SCFSR_TDFE | SCFSR_TEND;

        if (s->tx_strict) {
            rza1l_scif_tx_drain(s, qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL));
            tx = (s->tx_count <= rza1l_scif_tx_trigger(s) ? SCFSR_TDFE : 0) |
                 (s->tx_count == 0 ? SCFSR_TEND : 0);
        }
        return s->scfsr | tx | (s->rx_full ? (SCFSR_RDF | SCFSR_DR) : 0);
    }
    case SCIF_SCFRDR: {
        uint8_t b = s->rx_fifo;
        s->rx_full = false;
        s->scfsr &= ~(SCFSR_RDF | SCFSR_DR);
        rza1l_scif_update_irq(s);
        qemu_chr_fe_accept_input(&s->chr);
        return b;
    }
    case SCIF_SCFCR:
        return s->scfcr;
    case SCIF_SCFDR:
        /* Receive-data count in [4:0]; transmit count in [12:8] (strict only). */
        if (s->tx_strict) {
            rza1l_scif_tx_drain(s, qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL));
        }
        return (s->tx_strict ? s->tx_count << 8 : 0) | (s->rx_full ? 1 : 0);
    case SCIF_SCSPTR:
    case SCIF_SCLSR:
    case SCIF_SCEMR:
        return 0;
    default:
        qemu_log_mask(LOG_UNIMP, "%s: unimplemented read @ 0x%" HWADDR_PRIx "\n",
                      __func__, offset);
        return 0;
    }
}

static void rza1l_scif_write(void *opaque, hwaddr offset, uint64_t value,
                             unsigned size)
{
    RzA1lScifState *s = opaque;

    switch (offset) {
    case SCIF_SCSMR:
        s->scsmr = value;
        break;
    case SCIF_SCBRR:
        s->scbrr = value;
        break;
    case SCIF_SCSCR:
        s->scscr = value;
        rza1l_scif_update_irq(s);
        rza1l_scif_tx_update(s);
        break;
    case SCIF_SCFTDR: {
        uint8_t b = value;

        if (s->tx_strict) {
            rza1l_scif_tx_write(s, b);
        } else {
            /* Transmit immediately to the backend. */
            qemu_chr_fe_write_all(&s->chr, &b, 1);
        }
        break;
    }
    case SCIF_SCFSR:
        /*
         * Status bits are write-0-to-clear. Keep only the bits the firmware
         * leaves set; TDFE/TEND/RDF/DR are recomputed on read.
         */
        s->scfsr = value & ~(SCFSR_TDFE | SCFSR_TEND | SCFSR_RDF | SCFSR_DR);
        break;
    case SCIF_SCFCR:
        s->scfcr = value;
        if (value & SCFCR_TFRST) {
            s->tx_count = 0;
        }
        rza1l_scif_tx_update(s);
        break;
    case SCIF_SCFDR:
    case SCIF_SCSPTR:
    case SCIF_SCLSR:
    case SCIF_SCEMR:
        break;
    default:
        qemu_log_mask(LOG_UNIMP,
                      "%s: unimplemented write @ 0x%" HWADDR_PRIx
                      " value 0x%" PRIx64 "\n",
                      __func__, offset, value);
        break;
    }
}

static const MemoryRegionOps rza1l_scif_ops = {
    .read = rza1l_scif_read,
    .write = rza1l_scif_write,
    .endianness = DEVICE_NATIVE_ENDIAN,
    .valid.min_access_size = 1,
    .valid.max_access_size = 4,
};

static int rza1l_scif_can_receive(void *opaque)
{
    RzA1lScifState *s = opaque;

    /* Accept a byte only when receive is enabled and the holding reg is free. */
    return (s->scscr & SCSCR_RE) && !s->rx_full ? 1 : 0;
}

static void rza1l_scif_receive(void *opaque, const uint8_t *buf, int size)
{
    RzA1lScifState *s = opaque;

    if (size < 1) {
        return;
    }

    if (s->dmac) {
        /*
         * MIDI input is consumed by the firmware via the receive DMA ring
         * (it polls the channel's CRDA), so hand the byte straight to the
         * DMAC rather than latching it into SCFRDR and raising RXI.
         */
        rza1l_dmac_peripheral_rx_push(s->dmac, s->rx_dma_channel, buf[0]);
        return;
    }

    s->rx_fifo = buf[0];
    s->rx_full = true;
    s->scfsr |= SCFSR_RDF | SCFSR_DR;
    rza1l_scif_update_irq(s);
}

void rza1l_scif_set_rx_dma(RzA1lScifState *s, struct RzA1lDmacState *dmac,
                           int rx_dma_channel)
{
    s->dmac = dmac;
    s->rx_dma_channel = rx_dma_channel;
    rza1l_dmac_register_rx_ring(dmac, rx_dma_channel);
}

static void rza1l_scif_reset(DeviceState *dev)
{
    RzA1lScifState *s = RZA1L_SCIF(dev);

    s->scsmr = 0;
    s->scbrr = 0xff;
    s->scscr = 0;
    s->scfsr = 0;
    s->scfcr = 0;
    s->rx_fifo = 0;
    s->rx_full = false;
    s->tx_count = 0;
    rza1l_scif_update_irq(s);
}

static void rza1l_scif_realize(DeviceState *dev, Error **errp)
{
    RzA1lScifState *s = RZA1L_SCIF(dev);
    SysBusDevice *sbd = SYS_BUS_DEVICE(dev);

    memory_region_init_io(&s->iomem, OBJECT(dev), &rza1l_scif_ops, s,
                          TYPE_RZA1L_SCIF, RZA1L_SCIF_MMIO_SIZE);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq);

    qemu_chr_fe_set_handlers(&s->chr, rza1l_scif_can_receive,
                             rza1l_scif_receive, NULL, NULL, s, NULL, true);

    /*
     * Strict transmit is for the DIN MIDI channel, the one bound to a DMAC:
     * 31250 baud with 10 bits per character is 320 us a byte.
     */
    s->tx_strict = s->dmac && rza1l_scif_strict_enabled();
    s->tx_char_ns = 320000;
    s->tx_timer = timer_new_ns(QEMU_CLOCK_VIRTUAL, rza1l_scif_tx_timer, s);
}

static const Property rza1l_scif_properties[] = {
    DEFINE_PROP_CHR("chardev", RzA1lScifState, chr),
};

static const VMStateDescription vmstate_rza1l_scif = {
    .name = TYPE_RZA1L_SCIF,
    .version_id = 1,
    .minimum_version_id = 1,
    .fields = (const VMStateField[]) {
        VMSTATE_UINT16(scsmr, RzA1lScifState),
        VMSTATE_UINT8(scbrr, RzA1lScifState),
        VMSTATE_UINT16(scscr, RzA1lScifState),
        VMSTATE_UINT16(scfsr, RzA1lScifState),
        VMSTATE_UINT16(scfcr, RzA1lScifState),
        VMSTATE_UINT8(rx_fifo, RzA1lScifState),
        VMSTATE_BOOL(rx_full, RzA1lScifState),
        VMSTATE_END_OF_LIST()
    },
};

static void rza1l_scif_class_init(ObjectClass *klass, const void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->realize = rza1l_scif_realize;
    dc->vmsd = &vmstate_rza1l_scif;
    device_class_set_legacy_reset(dc, rza1l_scif_reset);
    device_class_set_props(dc, rza1l_scif_properties);
}

static const TypeInfo rza1l_scif_info = {
    .name          = TYPE_RZA1L_SCIF,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(RzA1lScifState),
    .class_init    = rza1l_scif_class_init,
};

static void rza1l_scif_register_types(void)
{
    type_register_static(&rza1l_scif_info);
}

type_init(rza1l_scif_register_types)

