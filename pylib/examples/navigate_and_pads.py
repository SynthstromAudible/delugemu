#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Turn an encoder, tap pads, and read back the pad-grid colours.

Demonstrates ``turn`` on a rotary encoder (by ``Control`` member), tapping the
``pad`` grid, and decoding ``read_pads`` into (r, g, b) cells.

    python3 pylib/examples/navigate_and_pads.py --firmware firmware/deluge.bin
"""
import argparse
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from delugemu import Control, DelugeSession   # noqa: E402
from delugemu.qmp import QmpError             # noqa: E402


def lit_pads(grid):
    """(col, row, rgb) for every non-black pad. grid is 18 cols x 8 rows."""
    return [(c, r, grid[c][r])
            for c in range(len(grid))
            for r in range(len(grid[c]))
            if any(grid[c][r])]


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
        before = len(lit_pads(dz.read_pads()))
        print("lit pads at boot:", before)

        # Nudge the select encoder, then clockwise again (negative delta = CCW).
        dz.turn(Control.SELECT_ENC, 2)
        dz.turn(Control.SELECT_ENC, -1)

        # Tap a short diagonal across the bottom-left of the main 16x8 grid.
        # Column 0..15 is the main grid, 16/17 the sidebar; row 0 is the bottom.
        for i in range(4):
            dz.pad(i, i)
        dz.wait(0.3)

        after = lit_pads(dz.read_pads())
        print("lit pads after tapping:", len(after))
        for col, row, (r, g, b) in after[:8]:
            print("  pad (col=%2d row=%d) = #%02x%02x%02x" % (col, row, r, g, b))
    return 0


if __name__ == "__main__":
    sys.exit(main())
