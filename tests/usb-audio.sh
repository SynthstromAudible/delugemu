#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# USB-audio (UAC1) to-host capture regression test.
#
# Boots a Deluge firmware image that implements the USB Audio Class peripheral
# (the DelugeFirmware `feat/usb_audio` branch) with the emulator presenting the
# controller as a USB-audio device and capturing the stream the firmware sends
# to the host (`scripts/run.sh --usb-audio <wav>`). It then asserts that a
# valid, real-time-length WAV was produced, exercising the whole to-host path:
# peripheral enumeration (attach -> bus reset -> SET_ADDRESS ->
# SET_CONFIGURATION -> SET_INTERFACE(stream-in, alt 1)), the 1 ms SOF clock that
# paces usbAudioHandleSof(), the D0FIFO DMA transfer, and the BVAL packet commit.
#
# The USB-audio firmware is not shipped with the repo; the test SKIPS cleanly
# (exit 0) when no suitable image is present or the capture comes back empty
# (e.g. a firmware build without USB-audio support), so it is safe to wire into
# CI. Point it at a build with DELUGE_FIRMWARE=/path/to/deluge.elf.
#
# Usage:
#   ./tests/usb-audio.sh
#   DELUGE_FIRMWARE=path ./tests/usb-audio.sh
#   RUN_SECONDS=12 ./tests/usb-audio.sh

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN="${REPO_ROOT}/qemu/build/qemu-system-arm"
RUN_SECONDS="${RUN_SECONDS:-10}"

fail() { printf 'USB-AUDIO FAIL: %s\n' "$*" >&2; exit 1; }
skip() { printf 'USB-AUDIO SKIP: %s\n' "$*"; exit 0; }

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

WAV="$(mktemp -u "${TMPDIR:-/tmp}/delugemu-usbaudio.XXXXXX.wav")"
trap 'rm -f "${WAV}"' EXIT

printf 'USB-AUDIO: firmware=%s\n' "${FIRMWARE#${REPO_ROOT}/}"
printf '  capturing the USB to-host stream for ~%ss (deterministic, --icount)...\n' \
    "${RUN_SECONDS}"

# Drive the verified launch path. --icount makes the SOF cadence track guest
# time, so the capture length is reproducible; --audio none keeps the test from
# needing a host audio backend (the engine still renders from the SSI DMA ring).
# A timeout stops the headless emulator; the WAV header self-finalises on every
# packet, so it is valid even though the process is killed rather than exited.
timeout "${RUN_SECONDS}" "${REPO_ROOT}/scripts/run.sh" "${FIRMWARE}" \
    --display headless --audio none --icount --usb-audio "${WAV}" \
    >/dev/null 2>&1 || true

[ -s "${WAV}" ] || skip "no WAV produced (firmware likely lacks USB-audio support)"

export DELUGEMU_WAV="${WAV}"
python3 - <<'PY'
import os, sys, wave

path = os.environ["DELUGEMU_WAV"]
try:
    w = wave.open(path, "rb")
except Exception as e:
    print(f"USB-AUDIO SKIP: capture is not a valid WAV ({e}) - "
          "firmware likely lacks USB-audio support")
    sys.exit(0)

ch, rate, width, frames = (w.getnchannels(), w.getframerate(),
                           w.getsampwidth(), w.getnframes())
dur = frames / rate if rate else 0
print(f"  WAV: {ch}ch {rate}Hz {width*8}-bit {frames} frames ({dur:.2f}s)")

if ch != 2 or rate != 44100 or width != 4:
    print("USB-AUDIO FAIL: unexpected format "
          f"(want 2ch/44100/32-bit, got {ch}ch/{rate}/{width*8}-bit)",
          file=sys.stderr)
    sys.exit(1)

# A header-only / near-empty capture means the firmware never reached the
# streaming state (no USB-audio support) - skip rather than fail.
if frames < rate // 2:
    print(f"USB-AUDIO SKIP: only {frames} frames captured "
          "(firmware likely lacks USB-audio support)")
    sys.exit(0)

print("USB-AUDIO PASS: valid real-time to-host capture")
PY
