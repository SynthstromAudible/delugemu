# USB peripheral mode: audio (UAC1) + MIDI — emulator design

> Status: **design / not yet implemented.** This document scopes making
> `qemu-system-arm -M deluge` act as the USB *host* for a Deluge running its USB
> stack in **peripheral (function) mode**, serving both **USB Audio Class 1
> (UAC1)** and **USB-MIDI** to the developer's machine — i.e. modelling the
> Deluge the way it is almost always used: plugged into a computer. It is
> written against the DelugeFirmware `feat/usb_audio` branch
> (`src/deluge/drivers/usb/usb_audio.{h,cpp}`,
> `.../userdef/r_usb_paudio_config.h`, `.../userdef/r_usb_pmidi_config.h`, and
> `src/deluge/io/midi/r_usb_pmidi_descriptor.c`).

Read [register-coverage.md](register-coverage.md) (*USB200 / USB201*) and
[architecture.md](architecture.md) (*MIDI I/O*) first. This design **replaces**
the existing host-mode USB-MIDI model as the primary USB behaviour.

## 1. Decision: the emulated Deluge is a USB *peripheral*

The RZ/A1L USB module is dual-role. The Deluge can be a **host** (you plug a
controller into it) or a **peripheral** (you plug it into a computer). In
practice the peripheral case dominates — MIDI to/from a DAW, and now UAC1 audio
— so **the emulator will model peripheral mode as the primary role**, with the
emulator itself playing the part of the host computer.

The firmware selects its role at init with a single global, `g_usb_usbmode`
(`src/deluge/io/midi/midi_engine.cpp`: `potentiallyAHost = (g_usb_usbmode ==
USB_HOST)`). `hw_usb_hmodule_init` tries host first; **finding no attached
device, it falls back to peripheral mode.** That fall-back is exactly the
emulator's current *disconnected-default* behaviour (SYSSTS0.LNST = SE0, no
attach) — so peripheral mode is the natural path and needs no device fabricated
on the bus. What the emulator must add is the **host side of the conversation**:
drive VBUS/bus-reset, enumerate the peripheral, and move data on its pipes.

Consequence: the existing host-mode MIDI bridge (`midi=on`, which fabricates an
attached USB-MIDI *device* and keeps the firmware in host mode — see
`register-coverage.md`) is **superseded**. See §9 for migration/coexistence.

## 2. What the firmware exposes as a peripheral (the contract)

One composite device, from `r_usb_pmidi_descriptor.c`:

- `idVendor 0x16D0`, `idProduct 0x0CE2`, `bcdUSB 0x0200`, `bcdDevice 0x0301`
  (release bumped when audio was added, so hosts don't reuse cached MIDI-only
  info).
- One configuration, `TOTAL_CONFIG_LENGTH` bytes, containing **four
  interfaces**:

| Interface | Class | Alt settings | Streams |
| --------- | ----- | ------------ | ------- |
| 0 | Audio Control (UAC1) | 1 | — |
| 1 | Audio Streaming OUT (host→Deluge) | 0 = zero-bandwidth, 1 = streaming | ISO |
| 2 | Audio Streaming IN (Deluge→host) | 0 = zero-bandwidth, 1 = streaming | ISO |
| 3 | MIDI Streaming | 1 | bulk |

Endpoints: audio OUT ep 3, audio IN ep 4; MIDI in ep 1, MIDI out ep 2
(`r_usb_paudio_config.h`). Pipe assignments:

| Stream | USB dir | Pipe | FIFO | DMA ch | Notes |
| ------ | ------- | ---- | ---- | ------ | ----- |
| Audio from host (computer→Deluge) | ISO OUT, ep 3 | `USB_PIPE1` | **D1FIFO** | ch1 (`USB_AUDIO_RX_DMA_CHANNEL`) | 44.1k/24-bit stereo |
| Audio to host (Deluge→computer)   | ISO IN, ep 4  | `USB_PIPE2` | **D0FIFO** | ch0 (`USB_AUDIO_TX_DMA_CHANNEL`) | SOF-paced |
| MIDI to host (Deluge→computer)    | ep 1 (IN)  | `USB_PIPE3` (`USB_CFG_PMIDI_BULK_OUT`) | **CFIFO** | — | TX: CFIFO write + `BVAL` → BEMP |
| MIDI from host (computer→Deluge)  | ep 2 (OUT) | `USB_PIPE4` (`USB_CFG_PMIDI_BULK_IN`)  | **CFIFO** | — | RX: CFIFO read ← BRDY |

> **Direction-naming trap (verified in firmware):** the `USB_CFG_PMIDI_BULK_*`
> macro names are from the **device's own** perspective, *inverted* from the
> USB-spec host convention. The firmware **sends** MIDI to the computer on
> `USB_CFG_PMIDI_BULK_OUT` = **PIPE3** (`midi_engine.cpp:333,341`) and
> **receives** from the computer on `USB_CFG_PMIDI_BULK_IN` = **PIPE4**
> (`midi_engine.cpp:955-962`, `r_usb_plibusbip.c:880`). So PIPE3 = Deluge→host,
> PIPE4 = host→Deluge. Audio's "OUT/IN" follow the USB host convention (OUT =
> into the Deluge).

Pipes 1/2 are reserved for audio because only they can do isochronous transfers
(`r_usb_pmidi_config.h`). Samples are 24-bit MSB-aligned in 32-bit subframes
(== the Deluge's q31 layout), so every packet is a whole number of 32-bit words.
Max audio packet `48 frames × 8 bytes = 384 bytes`.

### 2.1 Enumeration (emulator acts as host)

After bus reset the emulator-as-host issues the standard sequence over the DCP
(pipe 0): GET_DESCRIPTOR(device) → SET_ADDRESS → GET_DESCRIPTOR(config, full) →
SET_CONFIGURATION → **SET_INTERFACE** per streaming interface. The firmware's
peripheral driver answers GET_DESCRIPTOR from its real descriptor tables; the
emulator drives the SETUP packets and consumes the IN data stages.

`SET_INTERFACE` is the stream on/off switch — it calls
`usbAudioSetInterface(iface, alt)`:

```
iface 1 (audio OUT), alt 1 -> startFromHost()   alt 0 -> stopFromHost()
iface 2 (audio IN),  alt 1 -> startToHost()      alt 0 -> stopToHost()
```

### 2.2 Audio to host (ISO IN, pipe 2, D0FIFO, DMA ch0)

SOF-paced. `startToHost()` sets `INTENB0 |= USB_SOFE` (b13, `0x2000`). Each USB
frame the controller raises `INTSTS0.SOFR` (b13) → `usbAudioHandleSof()`:

1. Bail if `!toHostStreaming || toHostDmaBusy`.
2. Require `D0FIFOCTR & USB_FRDY` (b13) — a buffer free, else back-pressure.
3. Stage `numFrames` samples (~44.1 avg, servo ±1; zero-length when unprimed).
4. DMA ch0 `toHostStaging → &D0FIFO.UINT32` (`numFrames*8` bytes), then
   `D0FIFOSEL |= USB_DREQE` (b12, `0x1000`).
5. DMA-complete IRQ → `toHostDmaComplete()` clears `DREQE`, sets
   `D0FIFOCTR = USB_BVAL` (b15) to **commit the short packet**.

**Emulator obligations:** raise SOF at 1 ms while `SOFE` set; expose
`D0FIFOCTR.FRDY` when a buffer is free; service the ch0 DMA that *writes* D0FIFO;
on the `BVAL` commit, forward the frame block to the audio sink (§4); apply
back-pressure by withholding `FRDY` until the previous IN packet is "collected".

### 2.3 Audio from host (ISO OUT, pipe 1, D1FIFO, DMA ch1)

BRDY-paced. `startFromHost()` sets `BRDYENB |= (1<<1)` and
`usb_cstd_set_buf(pipe1)`. A packet arriving raises pipe-1 BRDY →
`usbAudioHandleBrdy()` → `startFromHostDma()`:

1. Require `D1FIFOCTR & USB_FRDY`; length = `D1FIFOCTR & USB_DTLN` (b11-0,
   `0x0FFF`); zero/oversize → `D1FIFOCTR = USB_BCLR` (b14) drops it.
2. DMA ch1 `&D1FIFO.UINT32 → fromHostStaging` (len rounded up to 4), then
   `D1FIFOSEL |= USB_DREQE`.
3. DMA-complete → clear `DREQE`, copy to resampler ring, re-arm (double-buffered).

**Emulator obligations:** when an OUT packet is available from the source (§4),
load pipe-1's buffer, report `D1FIFOCTR.DTLN`, raise `D1FIFOCTR.FRDY` + pipe-1
**BRDY**; service the ch1 DMA that *reads* D1FIFO; support double-buffering.

### 2.4 MIDI (bulk pipes 3/4, CFIFO, "rohan")

MIDI uses the shared custom ("rohan") driver — `usb_send_start_rohan(...,
USB_CFG_PMIDI_BULK_OUT, ...)` — which streams 32-bit USB-MIDI event packets
through the **CFIFO** with the active pipe on `CFIFOSEL.CURPIPE`, exactly like
the existing host-mode bridge, but on peripheral pipes 3 (Deluge→host) and 4
(host→Deluge). The framing/deframing the model already has is reusable; only
the pipe assignment and BRDY/BEMP roles change:

- **Pipe 3, Deluge→host (MIDI to the computer):** firmware writes packets to
  CFIFO and commits with `CFIFOCTR.BVAL` (`usb_send_start_rohan`,
  `r_usb_hdriver.c:1346,1367`); the model deframes (CIN→length table) to raw
  MIDI on the chardev and raises pipe-3 **BEMP** (send-complete). Mirrors
  today's pipe-1 TX.
- **Pipe 4, host→Deluge (MIDI from the computer):** chardev MIDI is framed into
  4-byte packets; when the firmware arms pipe 4 (`usb_receive_start_rohan_midi`,
  PID=BUF, `BRDYENB`), the model latches a transfer, reports `CFIFOCTR.DTLN`,
  hands packets out on CFIFO reads (`r_usb_plibusbip.c:624`), raises pipe-4
  **BRDY**. Mirrors today's pipe-2..5 RX.

> **O1 — RESOLVED and verified in firmware.** MIDI moves to peripheral mode
> alongside audio; the host-mode bridge is retired as the default (§9). Both
> MIDI directions transit **CFIFO** (TX `r_usb_hdriver.c:1346`; RX
> `r_usb_plibusbip.c:624`), confirming the existing CFIFO framing code is
> reusable; the D0/D1FIFO-DMA paths in the peripheral lib are used only by audio.

## 3. Emulator design

### 3.1 A peripheral-mode controller that plays host

Add a peripheral-role path to `rza1l-usb`, entered when the firmware runs the
controller in function mode (`SYSCFG0.DCFM==0`, no host attach) — which is the
current disconnected default. A new property enables the computer side:

- `peripheral` (bool) — run the host-role state machine against a
  Deluge-as-peripheral: VBUS on, bus reset, enumerate, then stream.
- Audio sink/source binding (QEMU `audiodev`, as `rza1l-ssif` uses) for the two
  iso streams, and the existing MIDI `CharBackend` (`chr`) for MIDI.

A **host-role driver** inside the model posts SETUP packets through the DCP and
reacts to the firmware's descriptor/handshake responses (the inverse of today's
host-mode control state machine, which fabricated a device). It reads the
firmware's real descriptors rather than carrying a synthetic copy.

### 3.2 SOF timer

A `QEMUTimer` at 1 ms (`NANOSECONDS_PER_SECOND/1000`), armed while
`INTENB0.SOFE` is set and configured. Each tick sets `INTSTS0.SOFR` and
re-evaluates the USBIn IRQ through the existing deferred `event_bh` plumbing.
Under `--icount` SOF is in guest time → deterministic frame pacing for capture.

### 3.3 D0FIFO / D1FIFO + DMAC channels 0/1

The model currently routes only **CFIFO** (`0x14` / sel `0x20` / ctr `0x22`).
Add the data FIFOs:

| Offset | Reg | Role |
| ------ | --- | ---- |
| `0x18` | D0FIFO | to-host audio words written by DMA ch0 |
| `0x1C` | D1FIFO | from-host audio words read by DMA ch1 |
| `0x24` | D0FIFOSEL | `CURPIPE`, `MBW` (32-bit `0x0800`), `DREQE` (b12) |
| `0x26` | D0FIFOCTR | `FRDY` (b13), `BVAL` (b15) |
| `0x28` | D1FIFOSEL | `CURPIPE`, `MBW`, `DREQE` |
| `0x2A` | D1FIFOCTR | `FRDY` (b13), `BCLR` (b14), `DTLN` (b11-0) |

Byte movement is via the **DMAC** (`src/hw/dma/rza1l_dmac.c`), not CPU FIFO
reads. The DMAC already models peripheral⇄memory rings for audio
(`tx_audio_ring`/`rx_audio_ring`) and SD (`rza1l_dmac_peripheral_rx_push`);
reuse that pattern. DMARS: D0FIFO `0x83`, D1FIFO `0x87`.

- **ch0 (to host):** D0FIFO as DMA destination; on `D0FIFOSEL.DREQE` the DMAC
  drains `toHostStaging` into the model's to-host buffer, then the model raises
  `INTC_ID_DMAINT0 + 0`; the following `BVAL` publishes the packet to the sink.
- **ch1 (from host):** D1FIFO as DMA source fed from the model's from-host
  buffer; on `DREQE` the DMAC fills `fromHostStaging`, model raises
  `INTC_ID_DMAINT0 + 1`.

> **O2 — validate first.** Confirm the DMAC keys request sources off `DMARS`
> (`0x83`/`0x87`) and that the USB model can register FIFO endpoints the way
> SSIF does, or add a thin hook (`rza1l_dmac_usb_fifo_*`). Highest-risk
> integration point; prove it in Phase 1.

### 3.4 Interrupts

Beyond today's BRDY/NRDY/BEMP summaries, add `INTSTS0.SOFR`/`INTENB0.SOFE`
(b13). Per-pipe BRDY/BEMP now cover pipes 1–4 (audio 1/2, MIDI 3/4); the
existing summary logic in `rza1l_usb_intsts0()` already ORs them — extend the
pipe range and keep audio-iso vs MIDI-bulk completion semantics distinct.

## 4. Host bridge (the testing payoff)

- **Audio to host → WAV (Phase 1):** decode to-host packets (24-in-32 → PCM),
  write a WAV, reusing `rza1l-ssif`'s conversion. Deterministic under `--icount`.
- **Audio from host (Phase 2):** feed a file/tone into pipe 1 to exercise the
  firmware resampler + servo.
- **MIDI (Phase 2):** bridge pipes 3/4 to the existing CoreMIDI port machinery
  (`scripts/midi_bridge.c`), named as it is today.
- **CoreAudio (Phase 4):** live capture source/sink on macOS (route to a DAW via
  a loopback device such as BlackHole).

## 5. `run.sh` surface

- `--usb-audio <sink>` — enable peripheral audio; `wav:<path>`, `coreaudio`, or
  `none` (CI timing).
- `--usb-audio-in <source>` — optional from-host source (file / tone / capture).
- `--usb-midi <chardev>` / `coremidi` — **re-pointed** at peripheral pipes 3/4
  (same user-facing flag; the "DelugEmu USB" port now represents the Deluge as a
  peripheral to the computer, which is what users expect).

## 6. Phasing

1. **Audio to host → WAV. ✅ DONE.** Implemented in `src/hw/usb/rza1l_usb.c`
   (property `audio`, WAV path `audio-out`; `scripts/run.sh --usb-audio <wav>`).
   The model drives peripheral enumeration (attach → bus reset → SET_ADDRESS →
   SET_CONFIGURATION → SET_INTERFACE(2,1)), runs a 1 ms SOF clock, accumulates
   the D0FIFO DMA writes, and commits each packet to a self-finalising WAV on
   `D0FIFOCTR.BVAL`. Verified against `feat/usb_audio` firmware: a 12 s headless
   run yields a valid 44.1 kHz / stereo / 32-bit WAV carrying the Deluge's
   real-time rendered output (works with `--audio none`; pair with `--icount`
   for determinism). Two bugs found and fixed during bring-up:
   - **Control sequencer churn:** the model must return `INTSTS0.CTSQ` to `IDST`
     (and clear `VALID`) when the firmware writes `DCPCTR.CCPL`, or the firmware
     re-runs `set_interface3` endlessly and the stream never primes.
   - **Register-offset gotcha (critical):** a 4-byte reserved gap (`dummy4[4]`)
     sits between `CFIFOCTR` and `D0FIFOSEL` in `usb20_iodefine.h`, so the
     data-FIFO select/control registers are at **D0FIFOSEL 0x28 / D0FIFOCTR 0x2A
     / D1FIFOSEL 0x2C / D1FIFOCTR 0x2E** — *not* 0x24/0x26/0x28/0x2A. The data
     ports themselves (D0FIFO 0x18, D1FIFO 0x1C) are contiguous and correct.
   Remaining for this phase: a skip-clean `tests/usb-audio.sh`.
2. **Audio from host + MIDI in peripheral mode. ✅ DONE.** (Plan archived in
   [usb-audio-phase2-todo.md](usb-audio-phase2-todo.md).)
   - **From-host audio** (ISO OUT, pipe 1 / D1FIFO / DMA ch1): enumeration now
     also drives `SET_INTERFACE(1,1)` → `startFromHost()`; the model presents one
     packet per SOF while the firmware has pipe 1 armed (`BRDYENB` bit 1), paced
     at 44.1 kHz, raises pipe-1 BRDY, and answers the SAD-fixed D1FIFO read DMA
     word-by-word. Source is a built-in test tone (`--usb-audio-in tone[:freq]`)
     or an input WAV (looped). The frames the firmware actually consumes can be
     captured (`--usb-audio-in-capture <wav>`) for checking. Note the firmware
     deliberately does **not** echo host audio onto the to-host stream
     (`audio_engine.cpp`: `toUSB` is taken *before* `doUSBDirectMonitoring`), so
     the input is verified on the consumed frames, not a round trip.
   - **Peripheral MIDI** (bulk pipes 3 TX / 4 RX over CFIFO): the MIDI data
     bridge is parameterised by mode — host mode (`midi=on`) uses pipes 1/2–5,
     peripheral mode (`audio=on`) uses pipes 3/4 — and the framing/deframing,
     rx-queue and chardev are shared. Enabled automatically alongside USB audio;
     `scripts/run.sh --usb-midi <chardev>` bridges the composite MIDI interface
     when combined with `--usb-audio`/`--usb-audio-in` (host-mode `midi=on` is
     not set in that case). Verified by a SysEx Identity round-trip
     (`tests/usb-midi-peripheral.sh`).
   Two firmware-interaction bugs found and fixed during bring-up:
   - **Lost first SET_INTERFACE / control-write register race:** the firmware's
     decoder clears `CTRT` at the *start* of its interrupt, before
     `usb_pstd_save_request()` latches `USBREQ/USBVAL/USBINDX`. Advancing the
     enumeration on CTRT-clear let the model post the next control write and
     overwrite those registers before the firmware read them, so the first of two
     back-to-back `SET_INTERFACE`s was processed with the second's values (only
     the last pipe got configured). Fixed by advancing on the firmware's `CCPL`
     (issued by `usb_pstd_ctrl_end`, after `set_interface3`) instead.
   - **Peripheral-connected flag / missing idle-stage CTRT:** `g_usb_peri_connected`
     (which gates the firmware arming peripheral MIDI receive) is set by
     `set_configuration0()`, run from the *idle-stage* `CTRT` (`CTSQ=IDST`) that
     real hardware raises *after* the status stage. The model now presents that
     idle-stage CTRT after each control write's CCPL, then advances when the
     firmware acknowledges it. Without it, enumeration "completed" but the MIDI
     engine never armed pipe 4. A stale `CFIFOCTR` returning bare `FRDY` for an
     empty receive pipe also had to be fixed to report *no* FRDY, or the
     firmware's drain loop spun on zero-length packets.
3. **Full enumeration hardening. ✅ (covered.)** Enumeration drives the full
   composite — SET_CONFIGURATION then `SET_INTERFACE(1,1)` (from-host) and
   `SET_INTERFACE(2,1)` (to-host); MIDI needs no alt setting. `usbAudioStopAll`
   on bus reset / reconfigure is honoured by the firmware; the model tears the
   from-host stream down when `BRDYENB` bit 1 clears. (A distinct `peripheral`
   property, separable from `audio`, remains a possible future refinement.)
4. **CoreAudio bridge + docs.** Live host-audio routing to a QEMU `audiodev`
   remains optional/future; docs updated here. Host-mode MIDI is kept behind the
   `midi=on` property as a legacy path (§9), not removed.

## 7. Testing

All skip cleanly when no firmware is present, and are deterministic under
`--icount`:

- **`tests/usb-audio.sh`** — boots `feat/usb_audio` and streams *both*
  directions at once. Asserts the to-host capture is a valid, real-time-length
  44.1 kHz/stereo/32-bit WAV, and that the from-host test tone (injected via
  `--usb-audio-in tone:440`) is carried intact — verified on the frames the
  firmware consumes (`--usb-audio-in-capture`) with a Goertzel check, since the
  firmware does not echo host audio onto the to-host stream.
- **`tests/usb-midi-peripheral.sh`** — boots as a USB peripheral (`audio=on`)
  with the composite MIDI interface bridged to a UNIX socket, and round-trips a
  SysEx Identity Request (in on pipe 4) / Identity Reply (out on pipe 3).
- **`tests/usb-midi-bridge.sh`** — the legacy host-mode (`midi=on`) MIDI bridge,
  still green (the bridge code is shared, parameterised by pipe numbers).

## 8. Open questions / decisions

- **O1 — RESOLVED (verified):** peripheral mode for both audio and MIDI;
  host-mode bridge retired (§1, §9). MIDI confirmed to transit CFIFO on pipes
  3 (Deluge→host) / 4 (host→Deluge); audio uses D0/D1FIFO DMA (§2.4).
- **O2 — RESOLVED (verified):** DMAC D0/D1FIFO endpoint hookup needs no DMAC
  changes. A register-mode one-shot transfer on `SETEN` honours `SAD`/`DAD`
  (fixed FIFO address) and pulses the per-channel DMAINT; `SWRST` preserves
  `CHCFG`. To-host writes D0FIFO (ch0), from-host reads D1FIFO (ch1); both work.
- **Mode entry:** confirm `SYSCFG0.DCFM==0` + no host attach is an unambiguous
  trigger for the peripheral path, vs. gating solely on the `peripheral`
  property.
- **Clock realism:** the firmware's async/adaptive servo assumes host≠device
  clock; under `--icount` they won't drift. Decide whether to inject a
  deliberate ratio for servo testing (otherwise the servo simply sits at nominal
  — fine for a functional test).

## 9. Migration from the host-mode MIDI bridge

Today `midi=on` fabricates an attached USB-MIDI device and keeps the firmware in
*host* mode. Under this design the Deluge is the *peripheral*, so that bridge no
longer represents the common case. Plan:

- Keep the CFIFO framing/deframing code; re-target it from host-mode pipes
  (1 TX, 2–5 RX) to peripheral pipes (**3 TX** Deluge→host, **4 RX** host→Deluge).
- Retire `midi=on`'s host-mode enumeration as the default. If hosting a USB-MIDI
  *controller* into the Deluge is still wanted for testing, keep it behind an
  explicit legacy flag; otherwise remove it once peripheral MIDI is proven.
- Update `register-coverage.md` and `architecture.md` to describe peripheral
  mode as the primary USB behaviour.

## 9a. Phase 1 implementation contract (verified against firmware)

Recon done by tracing the real `feat/usb_audio` build (`build/Debug/deluge.elf`)
and reading the Renesas peripheral driver. Concrete facts the model relies on:

**O2 — RESOLVED, no DMAC change needed.** `rza1l-dmac` already executes a
register-mode one-shot transfer on `SETEN` (`rza1l_dmac_copy`), honours `DAD`
(fixed destination → repeated writes to the same address) and pulses the
per-channel IRQ `s->irq[ch]` on completion (audio does not set `DEM`). So the
firmware's `startDma(ch0, toHostStaging, &D0FIFO, n)` lands as repeated 32-bit
`dma_memory_write`s to phys `0xE8010018`, dispatched straight into the USB
model's MMIO handler, and `DMAINT0` fires `toHostDmaComplete`. The USB model
only has to implement the D0FIFO MMIO behaviour + the SOF clock.

**Boot bring-up (observed).** The firmware tries host mode (`SYSCFG0`→`0x0063`,
DCFM+DRPD+USBE), finds nothing, then configures peripheral mode
(`SYSCFG0`→`0x0003`, DCFM=0) and enables the peripheral interrupt set
(`INTENB0`=`0x9f00` = VBINT|DVST|CTRT|BEMP|NRDY|BRDY). It then idles waiting for
VBUS — which the model must now supply. (`0x02`=BUSWAIT=5; `SOFCFG`=0x3C.)

**Enumeration the model drives (as host), minimal path to streaming:**
1. **Attach:** set `INTSTS0.VBSTS` (b7, `0x0080`) and raise `VBINT` (`0x8000`).
   Firmware `usb_pstd_chk_vbsts()==ATTACH` → `usb_pstd_attach_process()`.
2. **Bus reset:** set `INTSTS0.DVSQ` (b4-6) = `USB_DS_DFLT` (`0x0010`) and raise
   `DVST` (`0x1000`). Firmware `usb_pstd_bus_reset()`.
3. **Three no-data control writes**, each: latch `USBREQ`(=`bRequest<<8 |
   bmRequestType`)/`USBVAL`/`USBINDX`/`USBLENG`=0, then raise `CTRT` (`0x0800`)
   with `INTSTS0.CTSQ` first = `IDST` (0, `VALID` b3 set), then = `WRND` (5).
   The firmware's `usb_pstd_interrupt` reads the CTSQ field from a re-read of
   `INTSTS0`; at WRND it calls `save_request` + `stand_req3`, actioning the
   request and writing `DCPCTR.CCPL` (`0x0004`) to complete it. The model
   advances on that `CCPL` write.
   - `SET_ADDRESS(2)` → device to Address state (`DVSQ`=`USB_DS_ADDS` `0x0020`,
     raise DVST).
   - `SET_CONFIGURATION(1)` → Configured (`DVSQ`=`USB_DS_CNFG` `0x0030`, DVST);
     firmware configures all pipes.
   - `SET_INTERFACE(wIndex=2, wValue=1)` → `set_interface3` →
     `usbAudioSetInterface(2,1)` → `startToHost()`.
   (GET_DESCRIPTOR is intentionally skipped — the model is the host and needs no
   descriptors; the firmware services SET_* without a prior descriptor read.)

**INTSTS0 decoder priority** (`r_usb_preg_abs.c`, each gated by `INTENB0`):
BEMP→BRDY→NRDY→RESM→VBINT→SOFR→DVST→CTRT. Only one event is reported per
interrupt, so the model raises them one at a time and lets the firmware clear
each (`INTSTS0 &= ~bit`) before presenting the next. `CTRT` makes the firmware
re-read `INTSTS0` for the live CTSQ field.

**To-host streaming loop** (after `startToHost` sets `INTENB0.SOFE`):
- Model 1 ms SOF timer sets `INTSTS0.SOFR` (`0x2000`) and asserts the IRQ. The
  decoder calls `usbAudioHandleSof()` (`r_usb_preg_abs.c:326`) which stages
  frames and `startDma(ch0,…,&D0FIFO,n)`.
- DMAC writes n bytes to D0FIFO (model accumulates), pulses DMAINT0 →
  `toHostDmaComplete` clears `DREQE`, writes `D0FIFOCTR.BVAL` (`0x8000`).
- Model commits the accumulated packet on `BVAL`: 24-in-32 samples → WAV sink.
  `D0FIFOCTR` reads back `FRDY` (`0x2000`) when a buffer is free (back-pressure
  by withholding it until the prior packet is consumed).

## 10. Out of scope

- USB mass-storage device emulation (unchanged).
- Exposing the controller to the host OS as a *real* enumerable USB device
  (VID/PID in System Information) — infeasible on macOS without a signed
  DriverKit driver. This design makes the audio/MIDI *data* available on the
  host (WAV / CoreAudio / CoreMIDI), which is what testing needs.
