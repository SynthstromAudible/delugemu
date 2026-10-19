#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Peripheral-mode USB-MIDI data-bridge regression test (both directions).
#
# Boots a Deluge firmware image as a USB *peripheral* (-global rza1l-usb.audio=on
# brings up the composite USB-audio+MIDI device and drives enumeration), with the
# composite device's MIDI interface bridged to a host UNIX-socket chardev. Unlike
# usb-midi-bridge.sh - which tests the Deluge as a USB *host* with an attached
# MIDI device (rza1l-usb.midi=on) - here the computer is the host and the Deluge
# is the device, so MIDI transits the peripheral bulk pipes (pipe 4 host->Deluge,
# pipe 3 Deluge->host) over CFIFO.
#
# It exercises the full peripheral bulk pipe data path:
#   * RX (host -> Deluge): a Universal SysEx "Identity Request"
#     (F0 7E 7F 06 01 F7) is written to the socket. The model frames it into
#     32-bit USB-MIDI packets and delivers it on pipe 4 (BRDY).
#   * TX (Deluge -> host): the firmware's MIDI engine answers with an "Identity
#     Reply" (F0 7E 7F 06 02 ...), which the model deframes from pipe 3
#     (CFIFO/BVAL -> BEMP) and writes back to the socket.
#
# Receiving the reply byte-for-byte proves peripheral enumeration reached the
# connected/configured state (so the firmware armed its MIDI receive), the RX
# framer + pipe-4 delivery, and the TX deframer + pipe-3 BEMP continuation.
#
# Firmware is not shipped with the repo; the test SKIPS cleanly (exit 0) when no
# image (or python3) is present, so it is safe to wire into CI.
#
# Usage:
#   ./tests/usb-midi-peripheral.sh
#   DELUGE_FIRMWARE=path ./tests/usb-midi-peripheral.sh
#   RUN_SECONDS=15 ./tests/usb-midi-peripheral.sh

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN="${REPO_ROOT}/qemu/build/qemu-system-arm"
RUN_SECONDS="${RUN_SECONDS:-15}"

fail() { printf 'USB-MIDI-PERIPHERAL FAIL: %s\n' "$*" >&2; exit 1; }
skip() { printf 'USB-MIDI-PERIPHERAL SKIP: %s\n' "$*"; exit 0; }

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

printf 'USB-MIDI-PERIPHERAL: firmware=%s\n' "${FIRMWARE#${REPO_ROOT}/}"
printf '  booting as a USB peripheral with MIDI bridged to a UNIX socket for up to %ss...\n' \
    "${RUN_SECONDS}"

# AF_UNIX paths are short-limited, so keep the socket in /tmp. slot 0
# (-serial null) keeps SCIF0's DIN MIDI off the socket; slot 1
# (-serial chardev:um) is the USB MIDI bridge the SoC binds to usb0.
SOCK="$(mktemp -u /tmp/delugemu-pmidi.XXXXXX.sock)"
export DELUGEMU_BIN="${BIN}"
export DELUGEMU_FW="${FIRMWARE}"
export DELUGEMU_SOCK="${SOCK}"
export DELUGEMU_RUN_SECONDS="${RUN_SECONDS}"

python3 - <<'PY'
import os, socket, subprocess, sys, time

binp = os.environ["DELUGEMU_BIN"]
fw   = os.environ["DELUGEMU_FW"]
sock = os.environ["DELUGEMU_SOCK"]
run_seconds = int(os.environ["DELUGEMU_RUN_SECONDS"])

try:
    os.unlink(sock)
except FileNotFoundError:
    pass

# audio=on makes the Deluge a USB peripheral and drives enumeration; the model
# bridges the composite MIDI interface over the slot-1 chardev automatically.
cmd = [binp, "-M", "deluge", "-kernel", fw, "-display", "none",
       "-global", "rza1l-usb.audio=on",
       "-serial", "null",
       "-chardev", f"socket,id=um,path={sock},server=on,wait=off",
       "-serial", "chardev:um"]

p = subprocess.Popen(cmd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
got = b""
try:
    # Wait for the socket, then for enumeration + the firmware arming its first
    # peripheral MIDI receive.
    deadline = time.time() + run_seconds
    while not os.path.exists(sock) and time.time() < deadline:
        time.sleep(0.1)
    if not os.path.exists(sock):
        print("PERIPHERAL FAIL: qemu never created the MIDI socket", file=sys.stderr)
        sys.exit(2)
    time.sleep(6)

    c = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    c.connect(sock)
    c.setblocking(False)

    # Universal SysEx Identity Request.
    c.sendall(bytes([0xF0, 0x7E, 0x7F, 0x06, 0x01, 0xF7]))

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
finally:
    p.terminate()
    try:
        p.wait(timeout=5)
    except Exception:
        p.kill()
    try:
        os.unlink(sock)
    except FileNotFoundError:
        pass

hexs = got.hex()
print(f"  Deluge->host reply: {hexs or '(none)'}")

if not got:
    print("PERIPHERAL FAIL: firmware sent no MIDI in reply to the Identity "
          "Request (peripheral MIDI receive likely never armed)", file=sys.stderr)
    sys.exit(2)
if not hexs.startswith("f07e7f0602"):
    print("PERIPHERAL FAIL: reply is not a SysEx Identity Reply (F0 7E 7F 06 02 ..)",
          file=sys.stderr)
    sys.exit(2)
if not got.endswith(b"\xf7"):
    print("PERIPHERAL FAIL: Identity Reply truncated (no F7 terminator) -- a "
          "pipe-3 BEMP-gated transfer likely stalled", file=sys.stderr)
    sys.exit(2)

print("  reply is a complete SysEx Identity Reply (peripheral TX intact)")
PY
rc=$?

[ "${rc}" -eq 0 ] || fail "peripheral MIDI bridge did not round-trip the SysEx exchange"

printf 'USB-MIDI-PERIPHERAL OK: peripheral bulk MIDI bridge round-tripped a SysEx exchange\n'
