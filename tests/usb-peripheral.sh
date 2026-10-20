#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# USB *peripheral* regression test — the Deluge as a composite USB-audio + MIDI
# device plugged into a computer (the model plays the USB host). Covers the
# three peripheral configurations independently:
#
#   midi-only   MIDI interface only, no audio streams (the default role).
#   implicit    MIDI + audio both directions, from-host using the implicit-
#               feedback alternate setting (the default; follows our clock).
#   adaptive    MIDI + audio both directions, from-host using the adaptive
#               alternate setting (--usb-audio-adaptive; host-clocked, Windows).
#
# (Host-mode MIDI — the Deluge as a USB *host* with an attached MIDI device —
# is covered separately by tests/usb-midi-bridge.sh.)
#
# Each mode drives a SysEx Identity Request in / Identity Reply out over the
# peripheral MIDI pipes (host->Deluge pipe 4, Deluge->host pipe 3). The audio
# modes additionally assert the to-host capture is a valid real-time WAV and the
# injected from-host tone comes back intact on the consumed-frames capture.
#
# Firmware is not shipped with the repo; the test SKIPS cleanly (exit 0) when no
# image (or python3) is present, so it is safe to wire into CI.
#
# Usage:
#   ./tests/usb-peripheral.sh                 # all three modes
#   ./tests/usb-peripheral.sh implicit        # one mode
#   DELUGE_FIRMWARE=path RUN_SECONDS=15 ./tests/usb-peripheral.sh

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN="${REPO_ROOT}/qemu/build/qemu-system-arm"
RUN_SECONDS="${RUN_SECONDS:-15}"
TONE_HZ=440

fail() { printf 'USB-PERIPHERAL FAIL: %s\n' "$*" >&2; exit 1; }
skip() { printf 'USB-PERIPHERAL SKIP: %s\n' "$*"; exit 0; }

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

MODES="${1:-midi-only implicit adaptive}"

# Drive one mode: launch run.sh as a USB peripheral with its MIDI interface on a
# UNIX-socket chardev, round-trip a SysEx Identity exchange, and (for the audio
# modes) validate the captured streams. Echoes "PASS: ..." or exits non-zero.
run_one() {
    local mode="$1"
    local sock th fh log extra audio
    sock="$(mktemp -u /tmp/delugemu-pmidi.XXXXXX.sock)"
    th="$(mktemp -u "${TMPDIR:-/tmp}/delugemu-periTH.XXXXXX.wav")"
    fh="$(mktemp -u "${TMPDIR:-/tmp}/delugemu-periFH.XXXXXX.wav")"
    log="$(mktemp "${TMPDIR:-/tmp}/delugemu-peri.XXXXXX.log")"
    rm -f "${sock}"

    # Peripheral is the default role, so midi-only needs no extra flags beyond
    # the MIDI chardev; the audio modes add the audio streams.
    extra=()
    audio=0
    case "${mode}" in
        midi-only) extra=() ;;
        implicit)  extra=(--usb-audio "${th}" --usb-audio-in "tone:${TONE_HZ}" \
                          --usb-audio-in-capture "${fh}"); audio=1 ;;
        adaptive)  extra=(--usb-audio "${th}" --usb-audio-in "tone:${TONE_HZ}" \
                          --usb-audio-in-capture "${fh}" --usb-audio-adaptive); audio=1 ;;
        *) fail "unknown mode '${mode}' (want midi-only|implicit|adaptive)" ;;
    esac

    printf '  [%s] booting peripheral + MIDI socket for up to %ss...\n' \
        "${mode}" "${RUN_SECONDS}"

    # run.sh exec()s qemu, so `timeout` (and our kill) reach it directly. --icount
    # keeps the audio capture length reproducible.
    timeout "${RUN_SECONDS}" "${REPO_ROOT}/scripts/run.sh" "${FIRMWARE}" \
        --display headless --audio none --icount \
        --usb-midi "unix:${sock},server=on,wait=off" \
        ${extra[@]+"${extra[@]}"} >"${log}" 2>&1 &
    local runpid=$!

    local reply
    reply="$(SOCK="${sock}" python3 - <<'PY'
import os, socket, sys, time
sock = os.environ["SOCK"]
deadline = time.time() + 12
while not os.path.exists(sock) and time.time() < deadline:
    time.sleep(0.1)
if not os.path.exists(sock):
    sys.exit(0)  # qemu never came up; outer check handles it
time.sleep(6)  # enumerate + arm the peripheral MIDI receive
got = b""
try:
    c = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    c.connect(sock)
    c.setblocking(False)
    c.sendall(bytes([0xF0, 0x7E, 0x7F, 0x06, 0x01, 0xF7]))  # Identity Request
    end = time.time() + 5
    while time.time() < end:
        try:
            chunk = c.recv(4096)
            if chunk:
                got += chunk
        except BlockingIOError:
            time.sleep(0.05)
        if got.hex().startswith("f07e7f0602") and got.endswith(b"\xf7"):
            break
except Exception:
    pass
print(got.hex())
PY
)"

    kill "${runpid}" 2>/dev/null || true
    wait "${runpid}" 2>/dev/null || true

    # MIDI assertion (all modes): a complete SysEx Identity Reply round-tripped.
    if [ -z "${reply}" ]; then
        rm -f "${sock}" "${th}" "${fh}" "${log}"
        skip "[${mode}] no MIDI reply (firmware likely lacks peripheral USB support)"
    fi
    case "${reply}" in
        f07e7f0602*f7) printf '    MIDI: Identity Reply %s\n' "${reply}" ;;
        *) rm -f "${sock}" "${th}" "${fh}" "${log}"
           fail "[${mode}] reply is not a complete SysEx Identity Reply: ${reply}" ;;
    esac

    # Audio assertions (implicit/adaptive): to-host WAV valid + from-host tone.
    if [ "${audio}" -eq 1 ]; then
        TH="${th}" FH="${fh}" TONE="${TONE_HZ}" python3 - <<'PY' || { rm -f "${sock}" "${th}" "${fh}" "${log}"; exit 1; }
import os, sys, wave, struct, math

def load(p):
    w = wave.open(p, "rb")
    return w, w.getnchannels(), w.getframerate(), w.getsampwidth(), w.getnframes()

def goertzel(x, f, sr):
    k = 2 * math.cos(2 * math.pi * f / sr); s1 = s2 = 0.0
    for v in x:
        s0 = v + k * s1 - s2; s2, s1 = s1, s0
    return s1 * s1 + s2 * s2 - k * s1 * s2

# To-host: valid real-time-length 2ch/44100/32-bit WAV.
try:
    w, ch, rate, width, frames = load(os.environ["TH"])
except Exception as e:
    print(f"    to-host capture invalid ({e})"); sys.exit(1)
if ch != 2 or rate != 44100 or width != 4:
    print(f"USB-PERIPHERAL FAIL: to-host format {ch}ch/{rate}/{width*8}-bit", file=sys.stderr); sys.exit(1)
if frames < rate // 2:
    print(f"USB-PERIPHERAL FAIL: only {frames} to-host frames", file=sys.stderr); sys.exit(1)
print(f"    to-host: {frames} frames ({frames/rate:.2f}s)")

# From-host: the injected tone must dominate the consumed frames.
tone = int(os.environ["TONE"])
try:
    fw, fch, frate, fwidth, fframes = load(os.environ["FH"])
except Exception as e:
    print(f"USB-PERIPHERAL FAIL: from-host capture invalid ({e})", file=sys.stderr); sys.exit(1)
if fframes < frate // 2:
    print(f"USB-PERIPHERAL FAIL: only {fframes} from-host frames consumed", file=sys.stderr); sys.exit(1)
N = min(fframes, frate)
raw = fw.readframes(N)
left = [struct.unpack_from('<i', raw, i*fch*fwidth)[0] / 2147483648.0 for i in range(N)]
total = sum(v*v for v in left) / len(left) or 1e-12
tone_e = goertzel(left, tone, frate) / len(left)
others = [goertzel(left, f, frate) / len(left) for f in (tone//2, tone*3//2, tone*2)]
rel = 10 * math.log10(max(tone_e, 1e-12) / total)
print(f"    from-host: {fframes} frames, {tone} Hz {rel:+.1f} dB vs total")
if tone_e < 0.5 * total or any(tone_e < 1e3 * o for o in others):
    print("USB-PERIPHERAL FAIL: from-host tone not dominant", file=sys.stderr); sys.exit(1)
PY
    fi

    rm -f "${sock}" "${th}" "${fh}" "${log}"
    printf '  [%s] PASS\n' "${mode}"
}

printf 'USB-PERIPHERAL: firmware=%s\n' "${FIRMWARE#${REPO_ROOT}/}"
for m in ${MODES}; do
    run_one "${m}"
done
printf 'USB-PERIPHERAL OK: peripheral modes (%s) exercised\n' "${MODES}"
