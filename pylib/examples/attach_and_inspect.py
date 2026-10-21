#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Attach to an already-running emulator and dump its display state.

Unlike the other examples this one does not launch anything -- it connects to a
QMP socket an emulator is already serving, reads the deterministic display
state, and prints it. Useful for poking at a live session.

Start an emulator with a QMP socket first:

    ./scripts/run.sh firmware/deluge.bin --display none \\
        -- -qmp unix:/tmp/dz_qmp.sock,server,nowait

then:

    python3 pylib/examples/attach_and_inspect.py --sock /tmp/dz_qmp.sock
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
    ap.add_argument("--sock", default="/tmp/dz_qmp.sock",
                    help="QMP socket of a running emulator (default: %(default)s)")
    args = ap.parse_args()

    try:
        dz = DelugeSession.attach(args.sock, connect_timeout=5.0)
    except QmpError as exc:
        sys.stderr.write("could not attach to %s: %s\n" % (args.sock, exc))
        sys.stderr.write("start an emulator with a -qmp socket first "
                         "(see this script's header).\n")
        return 1

    # attach() does not own the process, so close() just disconnects.
    with dz:
        print("known controls (%d):" % len(list(Control)))
        print("  " + ", ".join(c.name for c in Control))

        print("\n7-segment:", repr(dz.read_segment()))

        lit = sorted(name for name, on in dz.read_leds().items() if on)
        print("lit indicator LEDs:", ", ".join(lit) or "(none)")

        print("OLED is", "on" if dz.oled_on() else "off")
        print("\n".join(dz.oled_text().splitlines()[:8]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
