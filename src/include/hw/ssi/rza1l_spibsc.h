/*
 * Renesas RZ/A1 SPIBSC (SPI multi-I/O bus controller) — minimal model
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef HW_SSI_RZA1L_SPIBSC_H
#define HW_SSI_RZA1L_SPIBSC_H

#include "hw/core/sysbus.h"
#include "qom/object.h"

#define TYPE_RZA1L_SPIBSC "rza1l-spibsc"
OBJECT_DECLARE_SIMPLE_TYPE(RzA1lSpibscState, RZA1L_SPIBSC)

#define RZA1L_SPIBSC_MMIO_SIZE 0x100

/* The Deluge's serial NOR part: 4 MB (JEDEC density 0x16). */
#define RZA1L_SPIBSC_FLASH_SIZE (4 * 1024 * 1024)

struct RzA1lSpibscState {
    /*< private >*/
    SysBusDevice parent_obj;

    /*< public >*/
    MemoryRegion iomem;
    /* The memory-mapped flash (external address space read mode). */
    MemoryRegion flash_window;

    /* Shadow of the register file (only the documented offsets are used). */
    uint32_t regs[RZA1L_SPIBSC_MMIO_SIZE / 4];

    /* Whether the SSL (chip-select) line is currently held asserted. */
    bool ssl_asserted;

    /* The flash array, erased (0xFF) unless loaded from flash_file. */
    uint8_t *flash;
    /* Optional backing file: loaded at realize, written back on every program/erase. */
    char *flash_file;

    /* The command transaction in progress (one SSL assertion). */
    uint8_t txn_cmd;
    uint32_t txn_addr;
    uint32_t txn_cursor;
    uint32_t txn_out_pos;
    bool txn_wel;
};

#endif /* HW_SSI_RZA1L_SPIBSC_H */
