# USB-audio Phase 2 — DONE (from-host stream + peripheral MIDI)

> Status: **✅ COMPLETE and verified** against DelugeFirmware `feat/usb_audio`
> (commit `dd7304ebe`). Companion to [usb-audio.md](usb-audio.md) (the overall
> design; see its §6 for the implementation summary and the two
> firmware-interaction bugs fixed during bring-up, and §7 for the tests).
> This doc is retained as the task record; the task checkboxes below are the
> original plan. Outcome summary:
>   - Task 1 (from-host audio, pipe 1 / D1FIFO / ch1): done — `--usb-audio-in`
>     tone/WAV source, `--usb-audio-in-capture` sink, exercised by the `implicit`
>     and `adaptive` modes of `tests/usb-peripheral.sh`.
>   - Task 2 (peripheral MIDI, pipes 3/4 over CFIFO): done — the MIDI bridge is
>     parameterised by mode and shared with host mode; `tests/usb-peripheral.sh`.
>   - Task 3 (enumeration hardening): done — full composite SET_INTERFACEs,
>     control-write CCPL/IDST sequencing, `g_usb_peri_connected`.
>   - Task 4 (run.sh + tests): done — `--usb-audio-in[-capture]`, mode-aware
>     `--usb-midi`, two tests. Live CoreAudio routing left as optional future.

Phase 2 = make the emulator feed the two *inbound* streams the firmware expects
as a peripheral: **audio from the host** (ISO OUT, pipe 1 / D1FIFO) and
**USB-MIDI both directions** (bulk pipes 3/4 over CFIFO). After this the emulated
Deluge behaves, to the host side the model stands in for, like a real Deluge
plugged into a computer.

## Carry-over facts from Phase 1 (don't re-derive)

- **Register offsets** (the `dummy4[4]` gap gotcha, already fixed in the model):
  D0FIFO `0x18`, D1FIFO `0x1C`, D0FIFOSEL `0x28`, D0FIFOCTR `0x2A`,
  D1FIFOSEL **`0x2C`**, D1FIFOCTR **`0x2E`**. Bits: `FRDY 0x2000`, `BVAL 0x8000`,
  `BCLR 0x4000`, `DTLN 0x0FFF`, `DREQE 0x1000` (all already `#define`d).
- **DMAC needs no changes** (O2): a register-mode one-shot transfer runs on
  `SETEN`, honours `SAD`/`DAD`, and pulses the per-channel DMAINT. For from-host
  the firmware DMAs `&USB200.D1FIFO.UINT32 → fromHostStaging` with **SAD set**
  (source fixed), so the DMAC issues repeated 32-bit reads from phys
  `0xE801001C` — the model must answer those reads with packet bytes.
- **Enumeration driver** lives in `rza1l_usb.c` (`PERI_*` state machine,
  `rza1l_usb_peri_post`/`_on_clear`). It already drives SET_ADDRESS →
  SET_CONFIGURATION → SET_INTERFACE(2,1). Phase 2 adds more SET_INTERFACE steps.
- **Control sequencer**: no-data control write = latch `USBREQ/VAL/INDX/LENG`,
  post `CTRT` with `CTSQ=WRND|VALID`, advance on the firmware's `DCPCTR.CCPL`
  (which also must reset `CTSQ→IDST`, else the firmware churns).
- **The model peeks guest memory** via `dma_memory_read(&address_space_memory,…)`
  (used for Phase 1 debugging; the includes were removed — re-add
  `system/address-spaces.h` + `system/dma.h` if debugging again). Audio-ring
  symbols are in `build/Debug/deluge.nmdump` / `nm` (anon-namespace statics).
- **Firmware must be rebuilt** (`cd ~/code/DelugeFirmware && ./dbt build debug`)
  after edits — and the D0/D1 assignment has changed under us before, so always
  re-confirm against a fresh build.

## Task 1 — From-host audio (ISO OUT, pipe 1, D1FIFO, DMA ch1)

Firmware contract (`usb_audio.cpp`): `startFromHost()` (via
`usbAudioSetInterface(1, alt!=0)`) arms pipe 1 — `BRDYENB |= (1<<1)`,
`usb_cstd_set_buf(pipe1)`. On a packet it runs `usbAudioHandleBrdy` →
`startFromHostDma`: reads `D1FIFOCTR`, needs `FRDY`, byte count `= D1FIFOCTR &
DTLN`, zero/oversize → `D1FIFOCTR = BCLR` (drop); else DMA ch1 `D1FIFO →
fromHostStaging` (len rounded up to 4), `D1FIFOSEL |= DREQE`; on DMA-complete
re-arms (pipe is double-buffered). `serviceFromHost()` is also called at the top
of `usbAudioHandleSof`, so SOF can poll it too.

- [ ] Enumeration: add `PERI_SET_IFACE_OUT` driving `SET_INTERFACE(wIndex=1,
      wValue=1)` so `usbAudioSetInterface(1,1) → startFromHost()`. Decide order
      vs the existing stream-in SET_INTERFACE (either order should be fine;
      enable both).
- [ ] Model a **from-host packet source**: produce ~44/45 frames per 1 ms (the
      host clock), 24-in-32 stereo. Phase-2a source = a WAV/raw file or a
      generated test tone (`--usb-audio-in <src>`); later a QEMU `audiodev`
      capture input.
- [ ] Present a packet on pipe 1: when the firmware has armed it (`PIPE1CTR`
      PID=BUF and `BRDYENB` bit 1 set), load the model's pipe-1 buffer, set
      `D1FIFOCTR.DTLN` = byte count, `D1FIFOCTR.FRDY`, and raise **pipe-1 BRDY**
      (reuse `pending_brdy` + `event_bh`). Service the ch1 DMA by answering
      reads of D1FIFO (`0x1C`) with buffer bytes in order (SAD-fixed → repeated
      reads of the same offset).
- [ ] Pace the source off the SOF clock (already running when streaming) so
      packets arrive ~1/frame; honour the firmware's re-arm (next BRDY only
      after it drains + re-arms). Double-buffering: allow up to 2 outstanding.
- [ ] Handle teardown: `SET_INTERFACE(1,0)` / bus reset / `usbAudioStopAll`
      stops the source cleanly.
- [ ] **Acceptance**: feed a known sine; read it back via `directMonitoring`
      (host audio mixed into outputs) captured on the to-host WAV, and assert it
      matches the input within resampler tolerance (allow for the Kaiser-sinc
      resampler + async servo). The servo won't drift under `--icount` (host and
      device clocks identical) — that's fine for a functional match; to exercise
      the servo, inject a deliberate rate offset in the source (optional).

Gotchas to watch: the from-host DTLN must be a whole number of 4-byte words;
`startFromHostDma` drops zero-length. The resampler needs the ring kept ~224
frames ahead (`kFromHostTargetFill`) — underruns print "USB audio: input
underrun" (route firmware `D_PRINTLN` to see it, or peek `fromHostRead/Written`).

## Task 2 — USB-MIDI in peripheral mode (bulk pipes 3/4, CFIFO)

Verified in Phase-1 recon (see usb-audio.md §2.4): peripheral MIDI transits
**CFIFO**, CURPIPE-routed, on **pipe 3 = Deluge→host (TX/BEMP)** and **pipe 4 =
host→Deluge (RX/BRDY)** — the device-perspective `USB_CFG_PMIDI_BULK_OUT`=PIPE3
/ `BULK_IN`=PIPE4 naming is inverted from the USB host convention. Pipes 3/4 are
configured by the firmware at `SET_CONFIGURATION` (no SET_INTERFACE alt needed;
MIDI interface is #3).

- [ ] Re-target the existing CFIFO MIDI framing/deframing (today keyed to
      host-mode pipes: `USB_BULK_SEND_PIPE 1` TX, `USB_BULK_RECV_MIN..MAX 2..5`
      RX) to peripheral pipes: **pipe 3 = TX (deframe CFIFO→chardev on BVAL,
      raise pipe-3 BEMP)**, **pipe 4 = RX (frame chardev→CFIFO, raise pipe-4
      BRDY when armed)**. Gate the new mapping on peripheral mode (`audio`/a new
      `peripheral` property) so host-mode (`midi=on`) keeps its current mapping.
- [ ] Confirm the firmware arms pipe 4 for receive (`usb_receive_start_rohan_midi`,
      PID=BUF + `BRDYENB` bit 4) and completes TX on pipe 3 via BEMP — trace
      against a fresh build; the BRDY/BEMP re-arm quirks from host mode
      (enable-after-commit re-evaluation) likely still apply.
- [ ] Reuse the CoreMIDI bridge machinery (`scripts/midi_bridge.c`,
      `--usb-midi coremidi` → "DelugEmu USB"); the user-facing flag stays the
      same but now represents the Deluge as a *peripheral* to the computer.
- [ ] **Acceptance**: extend/mirror `tests/usb-midi-bridge.sh` for peripheral
      mode — SysEx Identity Request in on pipe 4, Identity Reply out on pipe 3.

## Task 3 — Enumeration hardening

- [ ] Drive the full composite correctly when both audio interfaces + MIDI are
      active: SET_CONFIGURATION(1) then SET_INTERFACE for iface 1 (alt 1) and
      iface 2 (alt 1); MIDI (iface 3) needs none. Verify the firmware's
      `set_interface3` validation (`req_value <= get_alternate_num`) passes for
      both streaming interfaces.
- [ ] Alt-setting 0 teardown: `SET_INTERFACE(n,0)` must cleanly stop that
      stream (model stops its source/sink, firmware reconfigures the pipe).
- [ ] Bus-reset / detach path: on a modelled detach, firmware calls
      `usbAudioStopAll` (stops both) — make sure the model's sources/sinks and
      SOF clock stop and can re-enumerate.
- [ ] Consider a real `peripheral` bool property distinct from `audio`, so MIDI
      can run peripheral-mode without audio and vice-versa.

## Task 4 — run.sh surface + CoreAudio + docs

- [ ] `--usb-audio-in <src>` (file / `tone[:freq]` / `coreaudio` capture) for
      the from-host source; keep `--usb-audio <wav>` for to-host.
- [ ] Optional: bridge to-host to a live QEMU `audiodev`/CoreAudio so the Deluge
      shows up as a capture source on macOS (route to a DAW via BlackHole);
      from-host reads a QEMU audio input.
- [ ] Update `docs/usb-audio.md` §6 (mark Phase 2 done), §2.4/§9 (peripheral
      MIDI wired, host-mode bridge retired or behind a legacy flag), and
      `docs/register-coverage.md` / `docs/architecture.md` to describe
      peripheral mode as the primary USB behaviour.
- [ ] Add from-host + round-trip assertions (landed in `tests/usb-peripheral.sh`
      `implicit`/`adaptive` modes).

## Out of scope (unchanged)

- USB mass-storage; exposing a *real* enumerable USB device to macOS (needs a
  signed DriverKit driver — infeasible, and adds no test value).
