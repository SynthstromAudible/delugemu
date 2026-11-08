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
#     boundary at or past each time asked for),
#   * both runs show the same panel (OLED, pads, LEDs, gold knobs) at every
#     step, and
#   * both runs return from every interrupt to the same PC (the -d int log),
#     so the virtual clock kept the same pace against the instruction stream.
#
# It checks each firmware it is given. A firmware that idles in WFE (the
# Rust/Embassy-BSP firmware) halts the vCPU thousands of times per virtual
# second, which is what exposes a clock warp taken from a stale instruction
# count (qemu-patches/0008); the published C-BSP firmware busy-polls and never
# halts, so give the test a WFE image too.
#
# Firmware is not shipped with the repo; the test SKIPS cleanly (exit 0) when
# none is present.
#
# Usage:
#   DELUGE_FIRMWARE=path [DELUGE_SD_IMG=img] ./tests/determinism.sh
#   DELUGE_WFE_FIRMWARE=path ./tests/determinism.sh   # a WFE-idling image
#   DET_SECONDS=8 ./tests/determinism.sh   # virtual seconds per run
#   DET_RUNS=4 ./tests/determinism.sh      # emulators per firmware, at once

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
case "$(uname -s 2>/dev/null || echo unknown)" in
    MINGW*|MSYS*|CYGWIN*) EXE_SUFFIX=".exe" ;;
    *)                    EXE_SUFFIX="" ;;
esac
# run.sh launches DELUGEMU_QEMU_BIN when it is set.
BIN="${DELUGEMU_QEMU_BIN:-${REPO_ROOT}/qemu/build/qemu-system-arm${EXE_SUFFIX}}"
DET_SECONDS="${DET_SECONDS:-8}"
# Each run is one more chance for host scheduling to show. Against a build
# without qemu-patches/0008, four runs caught the WFE warp race in 6 trials of
# 6 on a 32-CPU host; two caught it in 2 of 3.
DET_RUNS="${DET_RUNS:-4}"

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
FIRMWARES=()
[ -n "${FIRMWARE}" ] && [ -f "${FIRMWARE}" ] && FIRMWARES+=("${FIRMWARE}")
WFE_FIRMWARE="${DELUGE_WFE_FIRMWARE:-}"
if [ -n "${WFE_FIRMWARE}" ]; then
    [ -f "${WFE_FIRMWARE}" ] || fail "DELUGE_WFE_FIRMWARE=${WFE_FIRMWARE} does not exist"
    FIRMWARES+=("${WFE_FIRMWARE}")
fi
[ ${#FIRMWARES[@]} -gt 0 ] || skip "no firmware image found (set DELUGE_FIRMWARE=path to run)"
[ -n "${WFE_FIRMWARE}" ] \
    || printf 'determinism: no WFE-idling firmware (DELUGE_WFE_FIRMWARE); halted-vCPU clock warps go unchecked\n'
SD="${DELUGE_SD_IMG:-}"

# The load: one busy process per host CPU, for as long as the test runs.
LOAD_PIDS=()
cleanup() { [ ${#LOAD_PIDS[@]} -eq 0 ] || kill "${LOAD_PIDS[@]}" 2>/dev/null || true; }
trap cleanup EXIT
for _ in $(seq "$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)"); do
    sh -c 'while :; do :; done' &
    LOAD_PIDS+=($!)
done

for fw in "${FIRMWARES[@]}"; do
    printf 'determinism: %s\n' "${fw}"
    status=0
    PYTHONPATH="${REPO_ROOT}/pylib" python3 - "${fw}" "${SD}" "${DET_SECONDS}" "${DET_RUNS}" << 'PYEOF' || status=$?
import hashlib, json, os, sys, tempfile, threading
from delugemu import DelugeSession

firmware, sd, seconds, runs = sys.argv[1], sys.argv[2] or None, int(sys.argv[3]), int(sys.argv[4])
STEP = 10_000_000
PRESS_AT = seconds * 1_000_000_000 // 2


def interrupt_returns(path):
    # The PC each interrupt returned to. Other -d int lines can differ between
    # identical runs where a TCG block happens to end (a stale ESR, a mode
    # switch reported one instruction apart) without the guest seeing it.
    with open(path, errors="replace") as fh:
        return [line.rstrip() for line in fh if line.startswith("Exception return")]


def run(label, results):
    with tempfile.TemporaryDirectory() as tmp:
        extra = ("-icount", "shift=2,sleep=off", "-S") + (("-snapshot",) if sd else ())
        int_log = os.path.join(tmp, "int.log")
        with DelugeSession.launch(firmware=firmware, sd=sd, sock=os.path.join(tmp, "qmp.sock"),
                                  int_log=int_log, extra_qemu=extra, artifacts_dir=tmp) as dz:
            stops, trace = [], []
            for t in range(STEP, seconds * 1_000_000_000 + 1, STEP):
                dz.run_until(t)
                stops.append(dz.vclock_ns())
                if t in (PRESS_AT, PRESS_AT + 20_000_000):
                    dz.button(8, 3, t == PRESS_AT)  # Play: starts the song
                panel = [dz.read_oled(), dz.read_pads(flashes=False), dz.read_leds(), dz.read_gold_knob()]
                trace.append(hashlib.sha1(json.dumps(panel, sort_keys=True).encode()).hexdigest())
        results[label] = (stops, trace, interrupt_returns(int_log))


results = {}
threads = [threading.Thread(target=run, args=(n, results)) for n in range(runs)]
for th in threads:
    th.start()
for th in threads:
    th.join()
if set(results) != set(range(runs)):
    sys.exit("a run did not finish")


def first_difference(a, b):
    parted = next((n for n, (x, y) in enumerate(zip(a, b)) if x != y), None)
    if parted is None and len(a) != len(b):
        parted = min(len(a), len(b))
    return parted


bad = False
for r in range(1, runs):
    for what, i in (("pauses", 0), ("panels", 1)):
        parted = first_difference(results[0][i], results[r][i])
        if parted is not None:
            bad = True
            print(f"runs 1 and {r + 1}: {what} part at the stop asked for {(parted + 1) * STEP} ns")
    a, b = results[0][2], results[r][2]
    parted = first_difference(a, b)
    if parted is not None:
        bad = True
        end = "(end)"
        print(f"runs 1 and {r + 1}: interrupts part at return {parted + 1} of {len(a)}/{len(b)}: "
              f"{a[parted] if parted < len(a) else end} vs {b[parted] if parted < len(b) else end}")
if not bad:
    print(f"{len(results[0][2])} interrupt returns, identical in {runs} runs")
sys.exit(1 if bad else 0)
PYEOF
    [ "${status}" -eq 0 ] || fail "two scripted runs of ${fw} differ"
done
printf 'DETERMINISM PASS: %s virtual seconds, %s runs each of %d firmware, identical pauses, panels and interrupts\n' \
    "${DET_SECONDS}" "${DET_RUNS}" "${#FIRMWARES[@]}"
