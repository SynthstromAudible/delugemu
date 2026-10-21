#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Boot the emulator headless, check nothing faulted, and snapshot the screen.

The simplest end-to-end use of the library: launch via scripts/run.sh, wait for
the firmware to come up, assert the boot was clean (no CPU aborts in the -d int
log), dump the OLED as text, and save a PNG.

    python3 pylib/examples/boot_and_screenshot.py --firmware firmware/deluge.bin
"""
import argparse
import os
import sys
import tempfile

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from delugemu import DelugeSession          # noqa: E402
from delugemu.qmp import QmpError           # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--firmware", default=None,
                    help="firmware image (default: let run.sh resolve one)")
    ap.add_argument("--boot-wait", type=float, default=4.0,
                    help="seconds to wait for boot (default: %(default)s)")
    ap.add_argument("--out", default="boot.png", help="screenshot path")
    args = ap.parse_args()

    int_log = os.path.join(tempfile.gettempdir(), "dz_example_int.log")
    try:
        session = DelugeSession.launch(firmware=args.firmware, int_log=int_log,
                                       boot_wait=args.boot_wait)
    except QmpError as exc:
        # Most likely: no firmware available. Skip cleanly like the test harness.
        print("skipped: could not launch the emulator (%s)" % exc)
        return 0

    with session as dz:
        dz.assert_no_aborts()
        print("boot clean (no data/prefetch aborts)")
        print("OLED is %s" % ("on" if dz.oled_on() else "off"))
        # Print just the top of the OLED so the example stays terminal-friendly.
        print("\n".join(dz.oled_text().splitlines()[:8]))
        path = dz.screenshot(args.out)
        print("wrote screenshot:", path)
    return 0


if __name__ == "__main__":
    sys.exit(main())
