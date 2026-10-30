#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Scripted-run determinism test.
#
# A scripted run (pylib's run_until, the dz-stop-at-ns property) pauses the VM
# at exact virtual times under -icount sleep=off and injects input there, so
# two runs of the same script must see the same guest. This test runs two
# emulators at once on a host kept busy, steps both in 10 ms of virtual time,
# presses a button at the same virtual time in each, and asserts:
#
#   * both runs pause at the same virtual times (the first instruction
#     boundary at or past each time asked for), and
#   * both runs show the same panel (OLED, pads, LEDs, gold knobs) at every
#     step.
#
# Firmware is not shipped with the repo; the test SKIPS cleanly (exit 0) when
# none is present.
#
# Usage:
#   DELUGE_FIRMWARE=path [DELUGE_SD_IMG=img] ./tests/determinism.sh
#   DET_SECONDS=8 ./tests/determinism.sh   # virtual seconds per run

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
case "$(uname -s 2>/dev/null || echo unknown)" in
    MINGW*|MSYS*|CYGWIN*) EXE_SUFFIX=".exe" ;;
    *)                    EXE_SUFFIX="" ;;
esac
BIN="${REPO_ROOT}/qemu/build/qemu-system-arm${EXE_SUFFIX}"
DET_SECONDS="${DET_SECONDS:-8}"

fail() { printf 'DETERMINISM FAIL: %s\n' "$*" >&2; exit 1; }
skip() { printf 'DETERMINISM SKIP: %s\n' "$*"; exit 0; }

[ -x "${BIN}" ] || fail "qemu-system-arm not built at ${BIN} (run scripts/build.sh)"
command -v python3 >/dev/null 2>&1 || skip "python3 not available"

FIRMWARE="${DELUGE_FIRMWARE:-}"
if [ -z "${FIRMWARE}" ]; then
    for cand in "${REPO_ROOT}/firmware2/deluge.elf" "${REPO_ROOT}/firmware/deluge.elf"; do
        if [ -f "${cand}" ]; then FIRMWARE="${cand}"; break; fi
    done
fi
[ -n "${FIRMWARE}" ] && [ -f "${FIRMWARE}" ] \
    || skip "no firmware image found (set DELUGE_FIRMWARE=path to run)"
SD="${DELUGE_SD_IMG:-}"

# The load: one busy process per host CPU, for as long as the test runs.
LOAD_PIDS=()
cleanup() { [ ${#LOAD_PIDS[@]} -eq 0 ] || kill "${LOAD_PIDS[@]}" 2>/dev/null || true; }
trap cleanup EXIT
for _ in $(seq "$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)"); do
    sh -c 'while :; do :; done' &
    LOAD_PIDS+=($!)
done

status=0
PYTHONPATH="${REPO_ROOT}/pylib" python3 - "${FIRMWARE}" "${SD}" "${DET_SECONDS}" << 'PYEOF' || status=$?
import hashlib, json, os, sys, tempfile, threading
from delugemu import DelugeSession

firmware, sd, seconds = sys.argv[1], sys.argv[2] or None, int(sys.argv[3])
STEP = 10_000_000
PRESS_AT = seconds * 1_000_000_000 // 2


def run(label, results):
    with tempfile.TemporaryDirectory() as tmp:
        extra = ("-icount", "shift=2,sleep=off", "-S") + (("-snapshot",) if sd else ())
        with DelugeSession.launch(firmware=firmware, sd=sd, sock=os.path.join(tmp, "qmp.sock"),
                                  extra_qemu=extra, artifacts_dir=tmp) as dz:
            stops, trace = [], []
            for t in range(STEP, seconds * 1_000_000_000 + 1, STEP):
                dz.run_until(t)
                stops.append(dz.vclock_ns())
                if t in (PRESS_AT, PRESS_AT + 20_000_000):
                    dz.button(8, 3, t == PRESS_AT)  # Play: starts the song
                panel = [dz.read_oled(), dz.read_pads(flashes=False), dz.read_leds(), dz.read_gold_knob()]
                trace.append(hashlib.sha1(json.dumps(panel, sort_keys=True).encode()).hexdigest())
            results[label] = (stops, trace)


results = {}
threads = [threading.Thread(target=run, args=(n, results)) for n in ("a", "b")]
for th in threads:
    th.start()
for th in threads:
    th.join()
if set(results) != {"a", "b"}:
    sys.exit("a run did not finish")

bad = False
for what, i in (("pauses", 0), ("panels", 1)):
    a, b = results["a"][i], results["b"][i]
    parted = next((n for n, (x, y) in enumerate(zip(a, b)) if x != y), None)
    if parted is not None:
        bad = True
        print(f"the runs' {what} part at the stop asked for {(parted + 1) * STEP} ns")
sys.exit(1 if bad else 0)
PYEOF
[ "${status}" -eq 0 ] || fail "two scripted runs of one firmware differ"
printf 'DETERMINISM PASS: %s virtual seconds, two runs, identical pauses and panels\n' "${DET_SECONDS}"
