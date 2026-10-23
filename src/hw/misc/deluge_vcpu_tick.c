/*
 * vCPU-side tick for virtual-clock device timers (see deluge_vcpu_tick.h)
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "hw/misc/deluge_vcpu_tick.h"

#define DELUGE_VCPU_TICK_MAX 8

static struct {
    DelugeVcpuTickFn *fn;
    void *opaque;
} deluge_vcpu_ticks[DELUGE_VCPU_TICK_MAX];
static int deluge_vcpu_tick_count;

void deluge_vcpu_tick_register(DelugeVcpuTickFn *fn, void *opaque)
{
    assert(deluge_vcpu_tick_count < DELUGE_VCPU_TICK_MAX);
    deluge_vcpu_ticks[deluge_vcpu_tick_count].fn = fn;
    deluge_vcpu_ticks[deluge_vcpu_tick_count].opaque = opaque;
    deluge_vcpu_tick_count++;
}

void deluge_vcpu_tick(void)
{
    for (int i = 0; i < deluge_vcpu_tick_count; i++) {
        deluge_vcpu_ticks[i].fn(deluge_vcpu_ticks[i].opaque);
    }
}
