#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Automated pad-click input test.
#
# Launches a headless emulator through the `delugemu` Python package, taps a
# handful of pads with DelugeSession.pad() (QMP absolute-pointer + left-button
# events at the geometry the emulator itself hit-tests against), and verifies
# from the input/PIC trace that each click hit the intended pad and was
# delivered to the firmware as a press + release.
#
# Skips cleanly (exit 0) when no firmware is available, like tests/scenario.sh.
#
# Usage:
#   ./tests/pad-click.sh
#   DELUGE_FIRMWARE=path ./tests/pad-click.sh

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
case "$(uname -s 2>/dev/null || echo unknown)" in
    MINGW*|MSYS*|CYGWIN*) EXE_SUFFIX=".exe" ;;
    *)                    EXE_SUFFIX="" ;;
esac
BIN="${REPO_ROOT}/qemu/build/qemu-system-arm${EXE_SUFFIX}"

BOOT_SECONDS="${BOOT_SECONDS:-12}"
RUN_LOG="${TMPDIR:-/tmp}/deluge_pad_click_run.log"

fail() { printf 'PAD-CLICK FAIL: %s\n' "$*" >&2; exit 1; }
skip() { printf 'PAD-CLICK SKIP: %s\n' "$*"; exit 0; }

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

printf '  firmware=%s, waiting %ss for boot...\n' "${FIRMWARE}" "${BOOT_SECONDS}"

PYTHONPATH="${REPO_ROOT}/pylib" python3 - "${FIRMWARE}" "${BOOT_SECONDS}" "${RUN_LOG}" << 'PYEOF'
import re, sys

from delugemu import DelugeSession

firmware, boot_wait, run_log = sys.argv[1], float(sys.argv[2]), sys.argv[3]

# (col, row) in delugemu coordinates: row 0 is the bottom row, columns 16/17
# are the sidebar.
pads = [(0, 7), (2, 7), (0, 5), (4, 5), (3, 2), (7, 1), (15, 0), (16, 3)]

# The input/PIC tracing we assert on is opt-in (it's costly on hot guest paths).
with DelugeSession.launch(firmware=firmware, boot_wait=boot_wait, run_log=run_log,
                          env={"DELUGE_INPUT_DEBUG": "1",
                               "DELUGE_PIC_DEBUG": "1"}) as dz:
    for x, y in pads:
        print(f"  tapping pad({x},{y})")
        dz.pad(x, y)
        dz.wait(0.2)
    dz.wait(0.5)

with open(run_log, errors="replace") as f:
    lines = f.readlines()

presses  = sum(1 for l in lines if "deluge_input: pointer press at" in l)
hit_pads = [tuple(map(int, m.groups())) for l in lines
            for m in [re.search(r"deluge_input: press hit pad \((\d+),(\d+)\)", l)] if m]
miss     = sum(1 for l in lines if "deluge_input: press miss" in l)
pic_down = sum(1 for l in lines if re.search(r"deluge_pic: send_event .*pressed=1", l))
pic_up   = sum(1 for l in lines if re.search(r"deluge_pic: send_event .*pressed=0", l))

n = len(pads)
print(f"  presses={presses} hits={len(hit_pads)} misses={miss} "
      f"pic_press={pic_down} pic_release={pic_up}")
for l in lines:
    if "deluge_input: p" in l or "deluge_pic: send_event" in l:
        print(" ", l.rstrip())

ok = True
if presses != n:
    print(f"FAIL: {presses}/{n} presses reached the input handler", file=sys.stderr); ok = False
if hit_pads != pads:
    print(f"FAIL: hit pads {hit_pads}, expected {pads} (misses={miss})", file=sys.stderr); ok = False
if pic_down != n or pic_up != n:
    print(f"FAIL: PIC saw {pic_down} press / {pic_up} release events, expected {n} each",
          file=sys.stderr); ok = False
if not ok:
    sys.exit(1)
print(f"PAD-CLICK OK: all {n} clicks hit the intended pad and reached the firmware")
PYEOF
