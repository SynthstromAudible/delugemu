#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Pad-scroll model test.
#
# The firmware animates pad scrolls with the PIC's scroll commands rather than
# full column sends: opening the song browser (LOAD) scrolls the browser in one
# row at a time with SET_SCROLL_UP/DOWN. This launches a headless emulator
# through the `delugemu` Python package, presses LOAD, polls the pad readout
# (dz-pad-leds) while the browser opens, and checks that
#
#   1. the PIC received vertical scroll commands (from its debug trace), and
#   2. the reported pads stepped through the scroll: successive distinct frames
#      that are each the previous one shifted by exactly one row.
#
# Polling is wall-clock, so not every step need be caught; a couple of
# intermediate one-row steps are enough to show the model applies the scroll
# instead of jumping straight to the final image.
#
# Skips cleanly (exit 0) when no firmware or SD image is available.
#
# Usage:
#   ./tests/pad-scroll.sh
#   DELUGE_FIRMWARE=path DELUGE_SD=path ./tests/pad-scroll.sh

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
case "$(uname -s 2>/dev/null || echo unknown)" in
    MINGW*|MSYS*|CYGWIN*) EXE_SUFFIX=".exe" ;;
    *)                    EXE_SUFFIX="" ;;
esac
BIN="${REPO_ROOT}/qemu/build/qemu-system-arm${EXE_SUFFIX}"

BOOT_SECONDS="${BOOT_SECONDS:-12}"
RUN_LOG="${TMPDIR:-/tmp}/deluge_pad_scroll_run.log"

fail() { printf 'PAD-SCROLL FAIL: %s\n' "$*" >&2; exit 1; }
skip() { printf 'PAD-SCROLL SKIP: %s\n' "$*"; exit 0; }

[ -x "${BIN}" ] || fail "qemu-system-arm not built at ${BIN} (run scripts/build.sh)"
command -v python3 >/dev/null 2>&1 || skip "python3 not available"

# Resolve firmware the same way run.sh does, to decide up front whether to run.
FIRMWARE="${DELUGEMU_FIRMWARE:-${DELUGE_FIRMWARE:-}}"
FIRMWARE_DIR="${DELUGEMU_FIRMWARE_DIR:-${REPO_ROOT}/firmware}"
if [ -z "${FIRMWARE}" ] && [ -d "${FIRMWARE_DIR}" ]; then
    FIRMWARE="$(find "${FIRMWARE_DIR}" -type f -iname '*.bin' 2>/dev/null \
                | LC_ALL=C sort | head -n1 || true)"
fi
[ -n "${FIRMWARE}" ] && [ -f "${FIRMWARE}" ] \
    || skip "no firmware image found (set DELUGE_FIRMWARE=path to run)"

# The song browser needs a card to list.
SD="${DELUGE_SD:-${REPO_ROOT}/build/deluge_sd.img}"
[ -f "${SD}" ] || skip "no SD image at ${SD} (run scripts/mksd.sh, or set DELUGE_SD)"

printf '  firmware=%s, sd=%s, waiting %ss for boot...\n' "${FIRMWARE}" "${SD}" "${BOOT_SECONDS}"

PYTHONPATH="${REPO_ROOT}/pylib" python3 - "${FIRMWARE}" "${SD}" "${BOOT_SECONDS}" "${RUN_LOG}" << 'PYEOF'
import sys, time

from delugemu import DelugeSession

firmware, sd, boot_wait, run_log = sys.argv[1], sys.argv[2], float(sys.argv[3]), sys.argv[4]


def row_shift(a, b):
    """+1 if b is a shifted one row down (row y took row y+1), -1 if up, else 0."""
    cols, rows = len(a), len(a[0])
    for d in (1, -1):
        if all(b[c][y] == a[c][y + d] for c in range(cols) for y in range(rows)
               if 0 <= y + d < rows):
            return d
    return 0


# The scroll-command trace we assert on is opt-in (it's costly on hot guest paths).
with DelugeSession.launch(firmware=firmware, sd=sd, boot_wait=boot_wait, run_log=run_log,
                          env={"DELUGE_PIC_DEBUG": "1"}) as dz:
    before = dz.read_pads()
    dz.press("LOAD")
    frames = [before]
    deadline = time.monotonic() + 3.0
    while time.monotonic() < deadline:
        p = dz.read_pads()
        if p != frames[-1]:
            frames.append(p)

with open(run_log, errors="replace") as f:
    scrolls = sum(1 for l in f if "deluge_pic: SET_SCROLL_" in l and "vertical" in l)

steps = [row_shift(a, b) for a, b in zip(frames, frames[1:])]
shifted = sum(1 for s in steps if s)
print(f"  vertical scroll commands={scrolls} distinct pad frames={len(frames)} "
      f"one-row steps={shifted} ({steps})")

ok = True
if scrolls == 0:
    print("FAIL: the firmware sent no vertical scroll on opening the browser", file=sys.stderr)
    ok = False
if shifted < 2:
    print("FAIL: the pad readout did not step through the scroll one row at a time",
          file=sys.stderr)
    ok = False
if not ok:
    sys.exit(1)
print(f"PAD-SCROLL OK: the pads followed the browser's scroll in {shifted} one-row steps")
PYEOF
