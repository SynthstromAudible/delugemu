#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Start and stop playback, verifying the PLAY indicator LED each way.

Demonstrates pressing a control by its ``Control`` enum member, polling display
state with ``wait_until``, asserting on an indicator LED, and reading the
7-segment tempo display.

    python3 pylib/examples/transport_led.py --firmware firmware/deluge.bin
"""
import argparse
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from delugemu import Control, DelugeSession   # noqa: E402
from delugemu.qmp import QmpError             # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--firmware", default=None,
                    help="firmware image (default: let run.sh resolve one)")
    ap.add_argument("--boot-wait", type=float, default=4.0)
    args = ap.parse_args()

    try:
        session = DelugeSession.launch(firmware=args.firmware,
                                       boot_wait=args.boot_wait)
    except QmpError as exc:
        print("skipped: could not launch the emulator (%s)" % exc)
        return 0

    with session as dz:
        print("tempo before:", dz.read_segment().strip())

        # Tap PLAY and wait for the firmware to light its LED.
        dz.press(Control.PLAY)
        dz.wait_until(lambda d: d.read_leds()["PLAY"], timeout=3.0)
        dz.assert_led(Control.PLAY, on=True)
        print("playing: PLAY LED is lit, tempo shows", dz.read_segment().strip())

        # Tap it again to stop; the LED should go back out.
        dz.press(Control.PLAY)
        dz.wait_until(lambda d: not d.read_leds()["PLAY"], timeout=3.0)
        dz.assert_led(Control.PLAY, on=False)
        print("stopped: PLAY LED is off")
    return 0


if __name__ == "__main__":
    sys.exit(main())
