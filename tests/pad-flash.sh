#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Pad-flash model test.
#
# The firmware blinks pads with the PIC's own flash commands rather than pad
# colour sends: in the sound menu it blinks the selected item's shortcut pad
# with SET_PAD_FLASHING (and SET_FLASH_COLOR for a coloured blink) every few
# hundred ms, and the PIC shows each for the flash length (6 ms). This launches
# a headless emulator through the `delugemu` Python package, opens the sound
# menu on a parameter from the boot clip view (SHIFT + that parameter's
# shortcut pad), polls the flash readout (dz-pad-flashes, read-and-clear) and
# checks that
#
#   1. flashes were reported, on the shortcut pad that opened the menu,
#   2. the PIC timing the firmware sets at boot is readable: flash length 6 ms,
#      a refresh time and a dimmer interval (from the pad-brightness default),
#   3. no flashes arrive once the menu is closed again (BACK).
#
# SHORTCUT_PAD defaults to (11, 1), a synth parameter's shortcut in the stock
# firmware's shortcut table.
#
# Skips cleanly (exit 0) when no firmware image is available. An SD card is
# optional (DELUGE_SD, or build/deluge_sd.img if present).
#
# Usage:
#   ./tests/pad-flash.sh
#   DELUGE_FIRMWARE=path [DELUGE_SD=path] ./tests/pad-flash.sh

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
case "$(uname -s 2>/dev/null || echo unknown)" in
    MINGW*|MSYS*|CYGWIN*) EXE_SUFFIX=".exe" ;;
    *)                    EXE_SUFFIX="" ;;
esac
BIN="${REPO_ROOT}/qemu/build/qemu-system-arm${EXE_SUFFIX}"

BOOT_SECONDS="${BOOT_SECONDS:-12}"
SHORTCUT_PAD="${SHORTCUT_PAD:-11,1}"
RUN_LOG="${TMPDIR:-/tmp}/deluge_pad_flash_run.log"

fail() { printf 'PAD-FLASH FAIL: %s\n' "$*" >&2; exit 1; }
skip() { printf 'PAD-FLASH SKIP: %s\n' "$*"; exit 0; }

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

SD="${DELUGE_SD:-}"

printf '  firmware=%s, sd=%s, waiting %ss for boot...\n' "${FIRMWARE}" "${SD:-default}" "${BOOT_SECONDS}"

PYTHONPATH="${REPO_ROOT}/pylib" python3 - "${FIRMWARE}" "${SD}" "${BOOT_SECONDS}" "${RUN_LOG}" "${SHORTCUT_PAD}" << 'PYEOF'
import sys, time

from delugemu import DelugeSession

firmware, sd, boot_wait, run_log = sys.argv[1], sys.argv[2] or None, float(sys.argv[3]), sys.argv[4]
px, py = (int(v) for v in sys.argv[5].split(","))
SHIFT = (8, 0)  # button matrix column, row

with DelugeSession.launch(firmware=firmware, sd=sd, boot_wait=boot_wait, run_log=run_log) as dz:
    settings = dz.read_pic_settings()
    dz.read_pad_flashes()  # drop any flashes from boot
    dz.button(*SHIFT, True)
    dz.wait(0.1)
    dz.pad_event(px, py, True)
    dz.wait(0.1)
    dz.pad_event(px, py, False)
    dz.wait(0.1)
    dz.button(*SHIFT, False)
    flashes = []
    deadline = time.monotonic() + 3.0
    while time.monotonic() < deadline:
        flashes += dz.read_pad_flashes()
        time.sleep(0.05)
    dz.press("BACK")
    time.sleep(0.5)
    dz.read_pad_flashes()
    quiet = []
    deadline = time.monotonic() + 1.0
    while time.monotonic() < deadline:
        quiet += dz.read_pad_flashes()
        time.sleep(0.05)

pads = sorted(set(flashes))
print(f"  pic settings={settings}")
print(f"  flashes in the sound menu={len(flashes)} distinct={pads}; after leaving it={len(quiet)}")

ok = True
if not flashes:
    print("FAIL: no pad flashes reported in the sound menu", file=sys.stderr)
    ok = False
if any((x, y) != (px, py) or not 0 <= c < 8 for x, y, c in flashes):
    print(f"FAIL: a flash on a pad other than the shortcut ({px}, {py}), or out of the colour range",
          file=sys.stderr)
    ok = False
if quiet:
    print("FAIL: flashes kept coming after leaving the menu", file=sys.stderr)
    ok = False
if settings["flash_length"] != 6 or settings["refresh_time"] < 1 or settings["dimmer_interval"] < 0:
    print("FAIL: the boot flash length (6 ms), refresh time or dimmer interval was not recorded",
          file=sys.stderr)
    ok = False
if not ok:
    sys.exit(1)
print(f"PAD-FLASH OK: {len(flashes)} flashes on {len(pads)} distinct (x, y, colour)")
PYEOF
