/*
 * Renesas RZ/A1 MTU2 (Multi-Function Timer Pulse Unit 2)
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef HW_TIMER_RZA1L_MTU2_H
#define HW_TIMER_RZA1L_MTU2_H

#include "hw/core/sysbus.h"
#include "qom/object.h"
#include "qemu/timer.h"

#define TYPE_RZA1L_MTU2 "rza1l-mtu2"
OBJECT_DECLARE_SIMPLE_TYPE(RzA1lMtu2State, RZA1L_MTU2)

#define RZA1L_MTU2_MMIO_SIZE 0x400

/* Timer channels 0-4. Each raises its compare-match-A interrupt, TGInA. */
#define RZA1L_MTU2_NUM_CH 5

typedef struct RzA1lMtu2Channel {
    RzA1lMtu2State *mtu2; /* owning device, for the timer callback       */
    int index;          /* channel number, 0-4                             */
    QEMUTimer *timer;   /* fires at the channel's next TGRA compare match  */
    qemu_irq irq;       /* TGInA: high while TSR.TGFA and TIER.TGIEA        */
    int64_t base_ns;    /* virtual-clock time of the count `base`          */
    uint16_t base;      /* TCNT at base_ns; the count itself while stopped */
    uint16_t tgra;      /* TGRA compare value                              */
    uint8_t tcr;        /* TCR: prescaler (TPSC) and counter clear (CCLR)  */
    bool running;       /* TSTR.CSTn                                       */
    bool tgfa;          /* TSR.TGFA: compare match A occurred              */
    bool tgfa_read;     /* TGFA read as 1 since it was set: writing 0 clears */
} RzA1lMtu2Channel;

struct RzA1lMtu2State {
    /*< private >*/
    SysBusDevice parent_obj;

    /*< public >*/
    MemoryRegion iomem;

    RzA1lMtu2Channel ch[RZA1L_MTU2_NUM_CH];
    /* Backing store for the register bytes the model does not synthesise. */
    uint8_t regs[RZA1L_MTU2_MMIO_SIZE];
};

#endif /* HW_TIMER_RZA1L_MTU2_H */
