/*
 * Renesas RZ/A1 SPIBSC (SPI multi-I/O bus controller) — minimal model
 *
 * The SPIBSC drives the serial NOR/QSPI flash on the Deluge. The firmware uses
 * it in two ways:
 *   - "SPI mode" manual commands: write the command/address/data registers
 *     (SMCMR/SMADR/SMENR/SMWDR), kick a transfer via SMCR.SPIE, busy-wait on
 *     CMNSR.TEND, then read SMRDR for the response. Used for flash status reads
 *     (read_status -> WIP bit), erase/program, and ID reads.
 *   - "external address space read mode": the flash is memory-mapped (handled
 *     elsewhere by the 0x18000000 SPI-ROM window); the firmware proper is loaded
 *     directly via -kernel, so that path is not exercised during boot here.
 *
 * This model makes every manual transfer complete instantly: CMNSR.TEND always
 * reads set. CMNSR.SSLF tracks the SSL keep/negate state so spibsc_stop() /
 * spibsc_transfer() chip-select handshakes behave.
 *
 * A 4 MB serial NOR flash sits behind it, as one array both access paths see:
 *   - Manual (SPI) mode transfers form command transactions, one per SSL
 *     assertion: the command (SMCMR), its address (SMADR, 3 or 4 bytes per
 *     SMENR.ADE), then data units of 1, 2 or 4 bytes (SMENR.SPIDE) written from
 *     SMWDR0 or read into SMRDR0. A unit of n bytes occupies the top n bytes of
 *     the 32-bit register, first wire byte lowest. Implemented: READ and the
 *     fast/dual/quad/4-byte read variants, page program (0x02/0x12, NOR AND,
 *     wrapping within a 256-byte page), 4 KB and 64 KB erase, chip erase,
 *     WREN/WRDI, RDSR (never busy) and RDID.
 *   - The memory-mapped window (RZA1L_SPI_ROM_BASE, and its uncached mirror),
 *     read-only, reads the same array.
 * The array starts erased (all 0xFF), which the firmware's settings-validity
 * check reads as "never saved"; an all-zero sector would instead parse as
 * saved settings with every value 0 (all four clip-status pad colours red).
 * With the flash-file property it is loaded from, and written back to, a file.
 *
 * Register offsets verified via offsetof on the firmware st_spibsc:
 *   CMNCR 0x00 SSLDR 0x04 SPBCR 0x08 DRCR 0x0c DRCMR 0x10 DREAR 0x14
 *   DROPR 0x18 DRENR 0x1c SMCR 0x20 SMCMR 0x24 SMADR 0x28 SMOPR 0x2c
 *   SMENR 0x30 SMRDR0 0x38 SMRDR1 0x3c SMWDR0 0x40 SMWDR1 0x44 CMNSR 0x48
 *   CKDLY 0x50 DRDMCR 0x58 DRDRENR 0x5c SMDMCR 0x60 SMDRENR 0x64 SPODLY 0x68.
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/log.h"
#include "migration/vmstate.h"
#include "hw/ssi/rza1l_spibsc.h"
#include "hw/core/qdev-properties.h"
#include "qapi/error.h"

/* Register byte offsets. */
#define SPIBSC_DRCR   0x0c
#define SPIBSC_SMCR   0x20
#define SPIBSC_SMCMR  0x24
#define SPIBSC_SMADR  0x28
#define SPIBSC_SMENR  0x30
#define SPIBSC_SMWDR0 0x40
#define SPIBSC_SMRDR0 0x38
#define SPIBSC_SMRDR1 0x3c
#define SPIBSC_CMNSR  0x48

/* SMCMR fields. */
#define SMCMR_CMD_SHIFT 16
#define SMCMR_CMD_MASK  0xff

/* SMENR fields. */
#define SMENR_CDE        0x00004000  /* command enable */
#define SMENR_ADE_SHIFT  8           /* address enable: 0x7 = 24-bit, 0xf = 32-bit */
#define SMENR_ADE_MASK   0xf
#define SMENR_SPIDE_MASK 0xf         /* data: 0x8 = 8, 0xc = 16, 0xf = 32 bits */

/* SMCR bits. */
#define SMCR_SPIE  0x00000001  /* start transfer */
#define SMCR_SPIWE 0x00000002  /* data write enable */
#define SMCR_SPIRE 0x00000004  /* data read enable */
#define SMCR_SSLKP 0x00000100  /* keep SSL asserted after transfer */

/* DRCR bits. */
#define DRCR_SSLN  0x01000000  /* negate SSL */

/* CMNSR bits. */
#define CMNSR_TEND 0x00000001  /* transfer end (always set in this model) */
#define CMNSR_SSLF 0x00000002  /* SSL line state */

/*
 * Flash-array read commands (Spansion S25FL512 set, matching the firmware's
 * sflash.h): READ/FAST_READ plus the dual/quad and 4-byte-address variants.
 * These are the commands whose SMRDR data must look like erased flash.
 */
static bool rza1l_spibsc_cmd_reads_flash_array(uint8_t cmd)
{
    switch (cmd) {
    case 0x03:  /* READ */
    case 0x13:  /* READ_4B */
    case 0x0b:  /* FAST_READ */
    case 0x0c:  /* FAST_READ_4B */
    case 0x3b:  /* DUAL_READ */
    case 0x3c:  /* DUAL_READ_4B */
    case 0x6b:  /* QUAD_READ */
    case 0x6c:  /* QUAD_READ_4B */
    case 0xbb:  /* DUAL_IO_READ */
    case 0xbc:  /* DUAL_IO_READ_4B */
    case 0xeb:  /* QUAD_IO_READ */
    case 0xec:  /* QUAD_IO_READ_4B */
        return true;
    default:
        return false;
    }
}

#define FLASH_PAGE_SIZE 256u
static const uint8_t rza1l_spibsc_jedec_id[3] = { 0xef, 0x40, 0x16 };

/* Write the array's [addr, addr + len) back to the backing file, if any. */
static void rza1l_spibsc_persist(RzA1lSpibscState *s, uint32_t addr, uint32_t len)
{
    FILE *f;

    if (!s->flash_file) {
        return;
    }
    f = fopen(s->flash_file, "r+b");
    if (!f) {
        f = fopen(s->flash_file, "w+b");
    }
    if (!f) {
        qemu_log_mask(LOG_GUEST_ERROR, "%s: cannot write %s\n", TYPE_RZA1L_SPIBSC,
                      s->flash_file);
        return;
    }
    if (fseek(f, addr, SEEK_SET) == 0) {
        fwrite(s->flash + addr, 1, len, f);
    }
    fclose(f);
}

static void rza1l_spibsc_erase(RzA1lSpibscState *s, uint32_t addr, uint32_t len)
{
    uint32_t base = (addr % RZA1L_SPIBSC_FLASH_SIZE) & ~(len - 1);

    memset(s->flash + base, 0xff, len);
    rza1l_spibsc_persist(s, base, len);
}

/* The flash's response to one data byte of the current transaction. */
static uint8_t rza1l_spibsc_flash_out(RzA1lSpibscState *s)
{
    uint8_t cmd = s->txn_cmd;
    uint8_t b = 0;

    if (rza1l_spibsc_cmd_reads_flash_array(cmd)) {
        b = s->flash[s->txn_cursor % RZA1L_SPIBSC_FLASH_SIZE];
        s->txn_cursor++;
    } else if (cmd == 0x05) {          /* RDSR: never busy; WEL in bit 1 */
        b = s->txn_wel ? 0x02 : 0x00;
    } else if (cmd == 0x9f) {          /* RDID */
        b = s->txn_out_pos < 3 ? rza1l_spibsc_jedec_id[s->txn_out_pos] : 0;
    }
    s->txn_out_pos++;
    return b;
}

/* One data byte the host sends in the current transaction. */
static void rza1l_spibsc_flash_in(RzA1lSpibscState *s, uint8_t b)
{
    if ((s->txn_cmd == 0x02 || s->txn_cmd == 0x12) && s->txn_wel) {
        uint32_t a = s->txn_cursor % RZA1L_SPIBSC_FLASH_SIZE;

        s->flash[a] &= b;
        rza1l_spibsc_persist(s, a, 1);
        s->txn_cursor = (s->txn_cursor & ~(FLASH_PAGE_SIZE - 1)) |
                        ((s->txn_cursor + 1) & (FLASH_PAGE_SIZE - 1));
    }
}

/* The transaction ends with SSL: an erase command takes effect here. */
static void rza1l_spibsc_end_transaction(RzA1lSpibscState *s)
{
    switch (s->txn_cmd) {
    case 0x06:                         /* WREN */
        s->txn_wel = true;
        break;
    case 0x04:                         /* WRDI */
        s->txn_wel = false;
        break;
    case 0x20: case 0x21:              /* 4 KB sector erase */
        if (s->txn_wel) {
            rza1l_spibsc_erase(s, s->txn_addr, 4 * 1024);
        }
        s->txn_wel = false;
        break;
    case 0xd8: case 0xdc:              /* 64 KB block erase */
        if (s->txn_wel) {
            rza1l_spibsc_erase(s, s->txn_addr, 64 * 1024);
        }
        s->txn_wel = false;
        break;
    case 0x60: case 0xc7:              /* chip erase */
        if (s->txn_wel) {
            rza1l_spibsc_erase(s, 0, RZA1L_SPIBSC_FLASH_SIZE);
        }
        s->txn_wel = false;
        break;
    case 0x02: case 0x12:              /* page program */
        s->txn_wel = false;
        break;
    default:
        break;
    }
    s->txn_cmd = 0;
}

/* SMCR.SPIE: one manual-mode transfer of the current transaction. */
static void rza1l_spibsc_transfer(RzA1lSpibscState *s, uint32_t smcr)
{
    uint32_t smenr = s->regs[SPIBSC_SMENR / 4];
    unsigned ade = (smenr >> SMENR_ADE_SHIFT) & SMENR_ADE_MASK;
    unsigned spide = smenr & SMENR_SPIDE_MASK;
    unsigned n = spide == 0xf ? 4 : spide == 0xc ? 2 : spide == 0x8 ? 1 : 0;

    if (smenr & SMENR_CDE) {
        if (s->ssl_asserted && s->txn_cmd) {
            rza1l_spibsc_end_transaction(s);
        }
        s->txn_cmd = (s->regs[SPIBSC_SMCMR / 4] >> SMCMR_CMD_SHIFT) & SMCMR_CMD_MASK;
        s->txn_out_pos = 0;
        s->txn_addr = 0;
        if (ade) {
            s->txn_addr = s->regs[SPIBSC_SMADR / 4] & (ade == 0xf ? 0xffffffffu : 0xffffffu);
        }
        s->txn_cursor = s->txn_addr;
    }
    if (n) {
        uint32_t wd = s->regs[SPIBSC_SMWDR0 / 4];
        uint32_t rd = 0;
        unsigned shift = 32 - 8 * n;

        for (unsigned k = 0; k < n; k++) {
            unsigned bit = (n == 4) ? 8 * k : shift + 8 * k;

            if (smcr & SMCR_SPIWE) {
                rza1l_spibsc_flash_in(s, (wd >> bit) & 0xff);
            }
            if (smcr & SMCR_SPIRE) {
                rd |= (uint32_t)rza1l_spibsc_flash_out(s) << bit;
            }
        }
        if (smcr & SMCR_SPIRE) {
            s->regs[SPIBSC_SMRDR0 / 4] = rd;
        }
    }
    s->ssl_asserted = smcr & SMCR_SSLKP;
    if (!s->ssl_asserted) {
        rza1l_spibsc_end_transaction(s);
    }
}

static uint64_t rza1l_spibsc_flash_read(void *opaque, hwaddr offset, unsigned size)
{
    RzA1lSpibscState *s = opaque;
    uint64_t v = 0;

    for (unsigned k = 0; k < size; k++) {
        v |= (uint64_t)s->flash[(offset + k) % RZA1L_SPIBSC_FLASH_SIZE] << (8 * k);
    }
    return v;
}

static void rza1l_spibsc_flash_write(void *opaque, hwaddr offset, uint64_t value,
                                     unsigned size)
{
    qemu_log_mask(LOG_GUEST_ERROR, "%s: write to the read-only flash window at 0x%"
                  HWADDR_PRIx "\n", TYPE_RZA1L_SPIBSC, offset);
}

static const MemoryRegionOps rza1l_spibsc_flash_ops = {
    .read = rza1l_spibsc_flash_read,
    .write = rza1l_spibsc_flash_write,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid.min_access_size = 1,
    .valid.max_access_size = 8,
    .impl.min_access_size = 1,
    .impl.max_access_size = 8,
};

static uint64_t rza1l_spibsc_read(void *opaque, hwaddr offset, unsigned size)
{
    RzA1lSpibscState *s = opaque;
    uint32_t reg;

    switch (offset) {
    case SPIBSC_CMNSR:
        reg = CMNSR_TEND | (s->ssl_asserted ? CMNSR_SSLF : 0);
        break;
    case SPIBSC_SMRDR0:
    case SPIBSC_SMRDR1:
        /* Latched by the last read transfer (rza1l_spibsc_transfer). */
        reg = s->regs[offset / 4];
        break;
    default:
        reg = (offset < RZA1L_SPIBSC_MMIO_SIZE) ? s->regs[offset / 4] : 0;
        break;
    }

    if (size == 4) {
        return reg;
    }
    return (reg >> ((offset & 3) * 8)) & ((1u << (size * 8)) - 1);
}

static void rza1l_spibsc_write(void *opaque, hwaddr offset, uint64_t value,
                               unsigned size)
{
    RzA1lSpibscState *s = opaque;
    hwaddr base = offset & ~3;
    unsigned shift = (offset & 3) * 8;
    uint32_t mask = (size == 4) ? 0xffffffffu
                                : ((1u << (size * 8)) - 1) << shift;
    uint32_t val32 = (uint32_t)value << shift;

    if (base >= RZA1L_SPIBSC_MMIO_SIZE) {
        return;
    }

    /* CMNSR is read-only status. */
    if (base == SPIBSC_CMNSR) {
        return;
    }

    s->regs[base / 4] = (s->regs[base / 4] & ~mask) | (val32 & mask);

    switch (base) {
    case SPIBSC_SMCR:
        if (s->regs[base / 4] & SMCR_SPIE) {
            /*
             * Transfer kicked. It completes immediately (TEND stays set). The
             * SSL line is held asserted only if SSLKP was requested.
             */
            rza1l_spibsc_transfer(s, s->regs[base / 4]);
            /*
             * SPIE starts a transfer and reads back 0, so a driver that sets
             * SMCR's other fields with read-modify-write afterwards (the stock
             * firmware's spibsc_transfer) does not start another.
             */
            s->regs[base / 4] &= ~SMCR_SPIE;
        }
        break;
    case SPIBSC_DRCR:
        if (s->regs[base / 4] & DRCR_SSLN) {
            s->ssl_asserted = false;
            rza1l_spibsc_end_transaction(s);
        }
        break;
    default:
        break;
    }
}

static const MemoryRegionOps rza1l_spibsc_ops = {
    .read = rza1l_spibsc_read,
    .write = rza1l_spibsc_write,
    .endianness = DEVICE_NATIVE_ENDIAN,
    .valid.min_access_size = 1,
    .valid.max_access_size = 4,
};

static void rza1l_spibsc_reset(DeviceState *dev)
{
    RzA1lSpibscState *s = RZA1L_SPIBSC(dev);

    memset(s->regs, 0, sizeof(s->regs));
    s->ssl_asserted = false;
    s->txn_cmd = 0;
    s->txn_wel = false;
}

static void rza1l_spibsc_realize(DeviceState *dev, Error **errp)
{
    RzA1lSpibscState *s = RZA1L_SPIBSC(dev);
    SysBusDevice *sbd = SYS_BUS_DEVICE(dev);

    memory_region_init_io(&s->iomem, OBJECT(dev), &rza1l_spibsc_ops, s,
                          TYPE_RZA1L_SPIBSC, RZA1L_SPIBSC_MMIO_SIZE);
    sysbus_init_mmio(sbd, &s->iomem);

    s->flash = g_malloc(RZA1L_SPIBSC_FLASH_SIZE);
    memset(s->flash, 0xff, RZA1L_SPIBSC_FLASH_SIZE);
    if (s->flash_file) {
        FILE *f = fopen(s->flash_file, "rb");

        if (f) {
            size_t got = fread(s->flash, 1, RZA1L_SPIBSC_FLASH_SIZE, f);

            fclose(f);
            if (got < RZA1L_SPIBSC_FLASH_SIZE) {
                memset(s->flash + got, 0xff, RZA1L_SPIBSC_FLASH_SIZE - got);
            }
        }
    }
    memory_region_init_io(&s->flash_window, OBJECT(dev), &rza1l_spibsc_flash_ops, s,
                          TYPE_RZA1L_SPIBSC "-flash", RZA1L_SPIBSC_FLASH_SIZE);
    sysbus_init_mmio(sbd, &s->flash_window);
}

static const Property rza1l_spibsc_properties[] = {
    DEFINE_PROP_STRING("flash-file", RzA1lSpibscState, flash_file),
};

static const VMStateDescription vmstate_rza1l_spibsc = {
    .name = TYPE_RZA1L_SPIBSC,
    .version_id = 1,
    .minimum_version_id = 1,
    .fields = (const VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, RzA1lSpibscState,
                             RZA1L_SPIBSC_MMIO_SIZE / 4),
        VMSTATE_BOOL(ssl_asserted, RzA1lSpibscState),
        VMSTATE_END_OF_LIST()
    },
};

static void rza1l_spibsc_class_init(ObjectClass *klass, const void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->realize = rza1l_spibsc_realize;
    dc->vmsd = &vmstate_rza1l_spibsc;
    device_class_set_props(dc, rza1l_spibsc_properties);
    device_class_set_legacy_reset(dc, rza1l_spibsc_reset);
}

static const TypeInfo rza1l_spibsc_info = {
    .name          = TYPE_RZA1L_SPIBSC,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(RzA1lSpibscState),
    .class_init    = rza1l_spibsc_class_init,
};

static void rza1l_spibsc_register_types(void)
{
    type_register_static(&rza1l_spibsc_info);
}

type_init(rza1l_spibsc_register_types)
