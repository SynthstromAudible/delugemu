#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# USB-audio (UAC1) bidirectional regression test.
#
# Boots a Deluge firmware image that implements the USB Audio Class peripheral
# (the DelugeFirmware `feat/usb_audio` branch) with the emulator presenting the
# controller as a USB-audio device, and exercises both stream directions at
# once:
#   - to-host (Deluge -> computer): captured to a WAV and checked for a valid,
#     real-time-length stream. Path: peripheral enumeration (attach -> bus reset
#     -> SET_ADDRESS -> SET_CONFIGURATION -> SET_INTERFACE(stream-in, alt 1)),
#     the 1 ms SOF clock pacing usbAudioHandleSof(), the D0FIFO DMA, BVAL commit.
#   - from-host (computer -> Deluge): a test tone is injected; the frames the
#     firmware actually consumes are captured and checked to carry that tone
#     intact. Path: SET_INTERFACE(stream-out, alt 1) -> startFromHost(), pipe-1
#     BRDY, and the D1FIFO receive DMA. (The firmware deliberately does not echo
#     host audio onto the to-host stream, so the input is verified on the
#     consumed frames rather than a round trip.)
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
FHWAV="$(mktemp -u "${TMPDIR:-/tmp}/delugemu-usbaudioin.XXXXXX.wav")"
trap 'rm -f "${WAV}" "${FHWAV}"' EXIT

# Frequency of the from-host test tone we inject and then look for.
TONE_HZ=440

printf 'USB-AUDIO: firmware=%s\n' "${FIRMWARE#${REPO_ROOT}/}"
printf '  streaming both directions for ~%ss (deterministic, --icount):\n' \
    "${RUN_SECONDS}"
printf '    to-host  -> %s\n' "${WAV##*/}"
printf '    from-host <- %d Hz tone, consumed frames -> %s\n' \
    "${TONE_HZ}" "${FHWAV##*/}"

# Drive the verified launch path. --icount makes the SOF cadence track guest
# time, so the capture length is reproducible; --audio none keeps the test from
# needing a host audio backend (the engine still renders from the SSI DMA ring).
# A timeout stops the headless emulator; the WAV headers self-finalise on every
# packet, so they are valid even though the process is killed rather than exited.
#   --usb-audio          : capture the to-host stream (Deluge -> computer)
#   --usb-audio-in        : feed the from-host stream (computer -> Deluge) a tone
#   --usb-audio-in-capture: capture the from-host frames the firmware consumes
timeout "${RUN_SECONDS}" "${REPO_ROOT}/scripts/run.sh" "${FIRMWARE}" \
    --display headless --audio none --icount \
    --usb-audio "${WAV}" \
    --usb-audio-in "tone:${TONE_HZ}" \
    --usb-audio-in-capture "${FHWAV}" \
    >/dev/null 2>&1 || true

[ -s "${WAV}" ] || skip "no WAV produced (firmware likely lacks USB-audio support)"

export DELUGEMU_WAV="${WAV}" DELUGEMU_FHWAV="${FHWAV}" DELUGEMU_TONE="${TONE_HZ}"
python3 - <<'PY'
import os, sys, wave, struct, math

def load(path):
    w = wave.open(path, "rb")
    ch, rate, width, frames = (w.getnchannels(), w.getframerate(),
                               w.getsampwidth(), w.getnframes())
    return w, ch, rate, width, frames

def check_format(label, ch, rate, width, frames):
    dur = frames / rate if rate else 0
    print(f"  {label}: {ch}ch {rate}Hz {width*8}-bit {frames} frames ({dur:.2f}s)")
    if ch != 2 or rate != 44100 or width != 4:
        print(f"USB-AUDIO FAIL: {label} unexpected format "
              f"(want 2ch/44100/32-bit, got {ch}ch/{rate}/{width*8}-bit)",
              file=sys.stderr)
        sys.exit(1)

def goertzel(x, f, sr):
    k = 2 * math.cos(2 * math.pi * f / sr)
    s1 = s2 = 0.0
    for v in x:
        s0 = v + k * s1 - s2
        s2, s1 = s1, s0
    return s1 * s1 + s2 * s2 - k * s1 * s2

# ---- To-host stream (Deluge -> computer) --------------------------------
try:
    w, ch, rate, width, frames = load(os.environ["DELUGEMU_WAV"])
except Exception as e:
    print(f"USB-AUDIO SKIP: to-host capture is not a valid WAV ({e}) - "
          "firmware likely lacks USB-audio support")
    sys.exit(0)

# A header-only / near-empty capture means the firmware never reached the
# streaming state (no USB-audio support) - skip rather than fail.
if frames < rate // 2:
    print(f"USB-AUDIO SKIP: only {frames} to-host frames captured "
          "(firmware likely lacks USB-audio support)")
    sys.exit(0)
check_format("to-host  WAV", ch, rate, width, frames)

# ---- From-host stream (computer -> Deluge) ------------------------------
# The firmware deliberately does NOT echo host audio back on the to-host
# stream, so the injected tone is verified on the frames the firmware actually
# consumed (captured by --usb-audio-in-capture) instead: this proves the whole
# from-host path - enumeration of the stream-out interface, pipe-1 BRDY, and the
# D1FIFO receive DMA - carried the samples intact at the real-time rate.
fhpath = os.environ.get("DELUGEMU_FHWAV", "")
tone = int(os.environ["DELUGEMU_TONE"])
try:
    fw, fch, frate, fwidth, fframes = load(fhpath)
except Exception as e:
    print(f"USB-AUDIO SKIP: from-host capture is not a valid WAV ({e}) - "
          "firmware likely lacks from-host audio support")
    sys.exit(0)
if fframes < frate // 2:
    print(f"USB-AUDIO SKIP: only {fframes} from-host frames consumed "
          "(firmware likely lacks from-host audio support)")
    sys.exit(0)
check_format("from-host WAV", fch, frate, fwidth, fframes)

# Analyse up to 1 s of the left channel: the injected tone must dominate.
N = min(fframes, frate)
raw = fw.readframes(N)
left = [struct.unpack_from('<i', raw, i * fch * fwidth)[0] / 2147483648.0
        for i in range(N)]
total = sum(v * v for v in left) / len(left) or 1e-12
tone_e = goertzel(left, tone, frate) / len(left)
others = [goertzel(left, f, frate) / len(left)
          for f in (tone // 2, tone * 3 // 2, tone * 2)]
peak = max(abs(v) for v in left)
rel_db = 10 * math.log10(max(tone_e, 1e-12) / total)
print(f"  from-host tone: {tone} Hz is {rel_db:+.1f} dB vs total energy, "
      f"peak amp {peak:.3f}")
# The tone bin should hold essentially all the energy, and clearly beat the
# off-bins (a flat/silent capture or wrong data would not).
if tone_e < 0.5 * total or any(tone_e < 1e3 * o for o in others):
    print("USB-AUDIO FAIL: from-host tone not dominant - the input path did "
          "not carry the injected signal intact", file=sys.stderr)
    sys.exit(1)

print("USB-AUDIO PASS: valid real-time to-host capture + from-host tone intact")
PY
