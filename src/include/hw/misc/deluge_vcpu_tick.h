/*
 * vCPU-side tick for virtual-clock device timers
 *
 * Without -icount, QEMU fires QEMU_CLOCK_VIRTUAL timers from the main loop,
 * whose poll timeout is rounded up to whole milliseconds on hosts without
 * ppoll() (macOS). A device modelling microsecond-scale latencies would see
 * every deadline stretched to >= 1 ms. Devices that need finer resolution
 * register a catch-up callback here; the timer models call deluge_vcpu_tick()
 * whenever the firmware reads a free-running counter, which it does constantly
 * (including while it waits on a peripheral), so an expired deadline is
 * serviced on the vCPU thread within a few guest instructions of falling due.
 * Callbacks run under the BQL, like a timer callback; under -icount they are
 * harmless no-ops (the timers have already fired on time).
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef HW_MISC_DELUGE_VCPU_TICK_H
#define HW_MISC_DELUGE_VCPU_TICK_H

typedef void DelugeVcpuTickFn(void *opaque);

/* Register a catch-up callback, invoked from every deluge_vcpu_tick(). */
void deluge_vcpu_tick_register(DelugeVcpuTickFn *fn, void *opaque);

/* Run every registered catch-up callback. Cheap when nothing is due. */
void deluge_vcpu_tick(void);

#endif /* HW_MISC_DELUGE_VCPU_TICK_H */
