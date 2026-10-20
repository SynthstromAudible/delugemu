/*
 * Renesas RZ/A1 USB 2.0 host/function controller
 *
 * Models the USB200/USB201 register window (st_usb20, base 0xE8010000 /
 * 0xE8207000). The controller is dual-role; the model supports both roles, and
 * audio streaming layers onto the peripheral one. Selected by properties:
 *
 *   - Peripheral (the "peripheral" property, ON BY DEFAULT): the Deluge is a USB
 *     device plugged into a computer, and the model plays the host. Once the
 *     firmware configures function mode and enables the peripheral interrupts,
 *     the model drives enumeration (VBUS attach -> bus reset -> SET_ADDRESS ->
 *     SET_CONFIGURATION -> streaming SET_INTERFACEs), advancing on the firmware's
 *     acknowledgements. On its own this is a USB-MIDI device (MIDI only) — the
 *     lowest common denominator every firmware supports, hence the default. With
 *     "audio" also set, the UAC1 audio streams run too: to-host (ISO IN, pipe 2 /
 *     D0FIFO / DMA ch0) captured to a WAV, from-host (ISO OUT, pipe 1 / D1FIFO /
 *     DMA ch1) fed from a tone or WAV. See docs/usb-audio.md.
 *
 *   - Host ("midi" property): the Deluge is the USB host with an attached device
 *     (a controller plugged into it). The model presents a permanently attached
 *     full-speed USB-MIDI device; once the firmware enables the attach interrupt
 *     the model raises ATTCH, and the firmware drives bus reset and enumerates
 *     the device over the DCP (pipe 0), which the model answers with synthetic
 *     descriptors and the SACK / BRDY / BEMP interrupts its host control-transfer
 *     state machine expects. Host mode overrides the peripheral default. Setting
 *     "peripheral" off with no other USB property gives a truly disconnected bus.
 *
 *   Bulk MIDI data is bridged to a host serial-MIDI chardev (the "chardev"
 *   property) in both roles, over the shared CFIFO (CURPIPE-routed) with
 *   32-bit USB-MIDI event packets. The framing/deframing is identical; only the
 *   pipe numbers differ (peripheral: TX pipe 3 / RX pipe 4; host: TX pipe 1 /
 *   RX pipes 2..5). The firmware's receive pipe gets raw chardev bytes framed
 *   into packets and the pipe's BRDY raised; its transmit pipe's packets are
 *   deframed back to a raw MIDI byte stream, acknowledged via the pipe's BEMP.
 *
 * Register offsets and bit definitions are taken from the firmware's
 * usb20_iodefine.h and r_usb_bitdefine.h.
 *
 * Copyright (c) 2026 delugemu contributors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/log.h"
#include "qemu/main-loop.h"
#include "qemu/timer.h"
#include "qemu/error-report.h"
#include <math.h>
#include "hw/core/sysbus.h"
#include "hw/core/irq.h"
#include "hw/core/qdev-properties.h"
#include "hw/core/qdev-properties-system.h"
#include "chardev/char-fe.h"
#include "migration/vmstate.h"
#include "hw/usb/rza1l_usb.h"

/* ---- Register offsets (st_usb20) ---------------------------------------- */
#define USB_SYSCFG0  0x00
#define USB_SYSSTS0  0x04
#define USB_DVSTCTR0 0x08
#define USB_CFIFO    0x14
#define USB_D0FIFO   0x18
#define USB_D1FIFO   0x1c
#define USB_CFIFOSEL 0x20
#define USB_CFIFOCTR 0x22
/* NB: a 4-byte reserved gap (iodefine dummy4[4]) sits between CFIFOCTR and
 * D0FIFOSEL, so the data-FIFO select/control registers start at 0x28. */
#define USB_D0FIFOSEL 0x28
#define USB_D0FIFOCTR 0x2a
#define USB_D1FIFOSEL 0x2c
#define USB_D1FIFOCTR 0x2e
#define USB_INTENB0  0x30
#define USB_INTENB1  0x32
#define USB_BRDYENB  0x36
#define USB_NRDYENB  0x38
#define USB_BEMPENB  0x3A
#define USB_INTSTS0  0x40
#define USB_INTSTS1  0x42
#define USB_BRDYSTS  0x46
#define USB_NRDYSTS  0x48
#define USB_BEMPSTS  0x4A
#define USB_FRMNUM   0x4C
#define USB_UFRMNUM  0x4E
#define USB_USBADDR  0x50
#define USB_USBREQ   0x54
#define USB_USBVAL   0x56
#define USB_USBINDX  0x58
#define USB_USBLENG  0x5A
#define USB_DCPCFG   0x5C
#define USB_DCPMAXP  0x5E
#define USB_DCPCTR   0x60
#define USB_PIPESEL  0x64
#define USB_PIPECFG  0x68
#define USB_PIPE1CTR 0x70   /* PIPEnCTR = PIPE1CTR + (n-1)*2, up to PIPE9CTR */

/* ---- Bit definitions ---------------------------------------------------- */
/* SYSCFG0 */
#define USB_USBE     0x0001
#define USB_DPRPU    0x0010   /* D+ pull-up (peripheral attach) */
#define USB_DRPD     0x0020   /* D+/D- pull-down (host) */
#define USB_DCFM     0x0040   /* function controller select (1 = host) */

/* SYSSTS0 */
#define USB_LNST     0x0003
#define USB_FS_JSTS  0x0001

/* DVSTCTR0 */
#define USB_USBRST   0x0040
#define USB_UACT     0x0010
#define USB_HSPROC   0x0004
#define USB_RHST     0x0007
#define USB_FSMODE   0x0002

/* CFIFOSEL */
#define USB_ISEL     0x0020
#define USB_CURPIPE  0x000f

/* CFIFOCTR */
#define USB_BVAL     0x8000
#define USB_BCLR     0x4000
#define USB_FRDY     0x2000
#define USB_DTLN     0x0fff

/* INTSTS0 / INTENB0 */
#define USB_BRDY     0x0100
#define USB_NRDY     0x0200
#define USB_BEMP     0x0400
#define USB_CTRT     0x0800   /* control transfer stage transition */
#define USB_DVST     0x1000   /* device state transition */
#define USB_SOFR     0x2000   /* SOF (frame) update */
#define USB_VBINT    0x8000   /* VBUS interrupt */
/* INTSTS0 status fields (peripheral mode). */
#define USB_CTSQ     0x0007   /* control transfer stage */
#define USB_VALID    0x0008   /* setup packet detect flag */
#define USB_DVSQ     0x0070   /* device state (DVSQ) */
#define USB_VBSTS    0x0080   /* VBUS input level */
/* CTSQ (control transfer stage) values. */
#define USB_CS_IDST  0x0000   /* idle / setup stage */
#define USB_CS_WRND  0x0005   /* control write no-data status stage */
/* DVSQ (device state) values. */
#define USB_DS_DFLT  0x0010   /* default (after bus reset) */
#define USB_DS_ADDS  0x0020   /* address */
#define USB_DS_CNFG  0x0030   /* configured */

/* INTENB0 SOF enable (same bit as INTSTS0.SOFR). */
#define USB_SOFE     0x2000

/* DnFIFOCTR / DnFIFOSEL (data-FIFO ports, used by the audio DMA). */
#define USB_DREQE    0x1000   /* DnFIFOSEL: DMA request enable */

/* INTSTS1 / INTENB1 */
#define USB_SACK     0x0010
#define USB_ATTCH    0x0800

/* DCPCTR */
#define USB_SUREQ    0x4000
#define USB_CCPL     0x0004   /* control transfer end (issue status stage) */

/* PIPEnCTR */
#define USB_PID      0x0003   /* PID field mask */
#define USB_PID_BUF  0x0001   /* BUF: pipe armed for transfer */

/* Bulk MIDI pipe assignment, host mode (firmware r_usb_hmidi_config.h). */
#define USB_BULK_SEND_PIPE 1  /* host OUT: Deluge transmits MIDI */
#define USB_BULK_RECV_MIN  2  /* host IN:  Deluge receives MIDI */
#define USB_BULK_RECV_MAX  5

/* Bulk MIDI pipe assignment, peripheral mode (r_usb_pmidi_config.h). The
 * device-perspective BULK_OUT/BULK_IN names are inverted from the USB host
 * convention: BULK_OUT (pipe 3) is the Deluge transmitting to the host, BULK_IN
 * (pipe 4) is the Deluge receiving from the host. */
#define USB_PMIDI_PIPE_TX  3  /* USB_CFG_PMIDI_BULK_OUT: Deluge -> host */
#define USB_PMIDI_PIPE_RX  4  /* USB_CFG_PMIDI_BULK_IN:  host -> Deluge */

/* Standard control requests (bRequest). */
#define USB_REQ_SET_ADDRESS       0x05
#define USB_REQ_GET_DESCRIPTOR    0x06
#define USB_REQ_SET_CONFIGURATION 0x09
#define USB_REQ_SET_INTERFACE     0x0b

/* UAC1 streaming interfaces (host's point of view); alt 1 starts each stream. */
#define USB_PAUDIO_STREAM_OUT_IFACE 1   /* host -> Deluge (from-host audio)   */
#define USB_PAUDIO_STREAM_IN_IFACE  2   /* Deluge -> host (to-host audio)     */

/* Isochronous pipes (r_usb_paudio_config.h: ISO_OUT = PIPE1, ISO_IN = PIPE2). */
#define USB_PAUDIO_PIPE_FROM_HOST 1     /* ISO OUT, drained via D1FIFO (ch1)  */
#define USB_PAUDIO_PIPE_TO_HOST   2     /* ISO IN,  filled via D0FIFO (ch0)   */

/* UAC1 stream format: 44.1 kHz, 2 channels, 24-in-32 MSB subframes. */
#define USB_PAUDIO_SAMPLE_RATE  44100
#define USB_PAUDIO_FRAME_BYTES  8       /* 2 channels x 4-byte subframe       */

/* From-host audio source kinds (resolved from the "audio-in" property). */
enum { AUDIO_IN_NONE = 0, AUDIO_IN_TONE, AUDIO_IN_FILE };

/* GET_DESCRIPTOR types (wValue high byte). */
#define USB_DT_DEVICE        0x01
#define USB_DT_CONFIGURATION 0x02
#define USB_DT_STRING        0x03

#define RZA1L_USB_DCP_MAXP   64   /* control endpoint max packet size */

static bool rza1l_usb_debug(void)
{
    static int v = -1;
    if (v < 0) {
        v = getenv("RZA1L_USB_DEBUG") != NULL;
    }
    return v;
}

#define USB_DBG(fmt, ...) \
    do { \
        if (rza1l_usb_debug()) { \
            fprintf(stderr, "rza1l-usb: " fmt "\n", ##__VA_ARGS__); \
        } \
    } while (0)

/*
 * Whether the controller is acting as a USB peripheral — the Deluge plugged
 * into a computer, with the model playing the host and driving enumeration.
 * This is the default role (the `peripheral` property, on by default, and the
 * lowest-common-denominator that every firmware supports as USB-MIDI); it is
 * suppressed by host mode (`midi=on`, the Deluge hosting a MIDI device), and
 * running the audio streams (`audio=on`) implies it. Audio *streaming* is
 * gated separately on `audio` / `audio-out` / `audio-in`, so peripheral mode on
 * its own is a MIDI-only device.
 */
static inline bool rza1l_usb_is_peripheral(RzA1lUsbState *s)
{
    return !s->midi && (s->peripheral || s->audio);
}

/* ---- Synthetic USB-MIDI device descriptors ----------------------------- */

/* Standard 18-byte device descriptor: class defined at interface level. */
static const uint8_t usb_midi_device_desc[18] = {
    0x12,             /* bLength                                            */
    0x01,             /* bDescriptorType = DEVICE                           */
    0x00, 0x02,       /* bcdUSB = 2.00                                      */
    0x00,             /* bDeviceClass (per-interface)                       */
    0x00,             /* bDeviceSubClass                                    */
    0x00,             /* bDeviceProtocol                                    */
    RZA1L_USB_DCP_MAXP, /* bMaxPacketSize0 = 64                             */
    0x66, 0x66,       /* idVendor  (synthetic)                              */
    0x01, 0x01,       /* idProduct (synthetic)                             */
    0x00, 0x01,       /* bcdDevice = 1.00                                   */
    0x00,             /* iManufacturer (no strings)                         */
    0x00,             /* iProduct                                           */
    0x00,             /* iSerialNumber                                      */
    0x01,             /* bNumConfigurations                                 */
};

/*
 * Configuration descriptor for a minimal USB-MIDI device:
 *   config -> AudioControl interface -> MIDIStreaming interface
 *   -> bulk OUT endpoint -> bulk IN endpoint, each with a class-specific
 *   MS endpoint descriptor binding one embedded MIDI jack.
 */
static const uint8_t usb_midi_config_desc[] = {
    /* Configuration descriptor (9) */
    0x09, 0x02, 0x65, 0x00, 0x02, 0x01, 0x00, 0x80, 0x32,
    /* Interface 0: Audio Control (9) */
    0x09, 0x04, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
    /* AC interface header (9) */
    0x09, 0x24, 0x01, 0x00, 0x01, 0x09, 0x00, 0x01, 0x01,
    /* Interface 1: MIDIStreaming (9) */
    0x09, 0x04, 0x01, 0x00, 0x02, 0x01, 0x03, 0x00, 0x00,
    /* MS interface header (7) */
    0x07, 0x24, 0x01, 0x00, 0x01, 0x41, 0x00,
    /* MIDI IN jack (embedded) (6) */
    0x06, 0x24, 0x02, 0x01, 0x01, 0x00,
    /* MIDI OUT jack (embedded) (9) */
    0x09, 0x24, 0x03, 0x01, 0x02, 0x01, 0x01, 0x01, 0x00,
    /* Bulk OUT endpoint (9) */
    0x09, 0x05, 0x01, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00,
    /* MS bulk OUT class endpoint (5) */
    0x05, 0x25, 0x01, 0x01, 0x01,
    /* Bulk IN endpoint (9) */
    0x09, 0x05, 0x81, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00,
    /* MS bulk IN class endpoint (5) */
    0x05, 0x25, 0x01, 0x01, 0x03,
};

/* String descriptor 0: supported language IDs (English, US). */
static const uint8_t usb_midi_string_langid[4] = {
    0x04, 0x03, 0x09, 0x04,
};

/* Minimal empty string for any other index (device declares no string ids). */
static const uint8_t usb_midi_string_empty[2] = {
    0x02, 0x03,
};

/* ---- Interrupt handling ------------------------------------------------- */

/*
 * INTSTS0.BRDY/NRDY/BEMP are summary bits: each is the OR of the corresponding
 * per-pipe status register masked by its enable. Synthesise them live so that
 * clearing a pipe's BRDYSTS/BEMPSTS bit also clears the INTSTS0 summary, just
 * like the hardware. Other INTSTS0 bits are stored normally.
 */
static uint16_t rza1l_usb_intsts0(RzA1lUsbState *s)
{
    uint16_t v = s->regs[USB_INTSTS0 >> 1] &
                 ~(uint16_t)(USB_BRDY | USB_NRDY | USB_BEMP);

    if (s->regs[USB_BRDYSTS >> 1] & s->regs[USB_BRDYENB >> 1]) {
        v |= USB_BRDY;
    }
    if (s->regs[USB_NRDYSTS >> 1] & s->regs[USB_NRDYENB >> 1]) {
        v |= USB_NRDY;
    }
    if (s->regs[USB_BEMPSTS >> 1] & s->regs[USB_BEMPENB >> 1]) {
        v |= USB_BEMP;
    }
    return v;
}

static void rza1l_usb_update_irq(RzA1lUsbState *s)
{
    uint16_t ints0 = rza1l_usb_intsts0(s) & s->regs[USB_INTENB0 >> 1];
    uint16_t ints1 = s->regs[USB_INTSTS1 >> 1] & s->regs[USB_INTENB1 >> 1];
    int level = (ints0 || ints1) ? 1 : 0;

    qemu_set_irq(s->irq, level);
}

/*
 * Bottom half: apply any interrupt events queued by an MMIO write, decoupled
 * from the write itself so the firmware sees the interrupt on a later tick
 * (matching hardware latency and avoiding reentrancy into the register file).
 */
static void rza1l_usb_event(void *opaque)
{
    RzA1lUsbState *s = opaque;

    if (s->pending_attach) {
        s->pending_attach = false;
        s->regs[USB_INTSTS1 >> 1] |= USB_ATTCH;
        USB_DBG("raise ATTCH (device present)");
    }
    if (s->pending_brdy) {
        s->regs[USB_BRDYSTS >> 1] |= s->pending_brdy;
        s->pending_brdy = 0;
    }
    if (s->pending_bemp) {
        s->regs[USB_BEMPSTS >> 1] |= s->pending_bemp;
        s->pending_bemp = 0;
    }
    s->regs[USB_INTSTS0 >> 1] |= s->pending_ints0;
    s->regs[USB_INTSTS1 >> 1] |= s->pending_ints1;
    s->pending_ints0 = 0;
    s->pending_ints1 = 0;

    rza1l_usb_update_irq(s);
}

static void rza1l_usb_schedule_event(RzA1lUsbState *s)
{
    qemu_bh_schedule(s->event_bh);
}

/* ---- Peripheral-mode USB-audio: WAV sink -------------------------------- */

/* Patch a little-endian u32 at a fixed offset in the open WAV file. */
static void rza1l_usb_wav_patch_u32(FILE *fp, long off, uint32_t v)
{
    uint8_t b[4] = { v & 0xff, (v >> 8) & 0xff, (v >> 16) & 0xff,
                     (v >> 24) & 0xff };
    if (fseek(fp, off, SEEK_SET) == 0) {
        fwrite(b, 1, 4, fp);
    }
}

/*
 * Open a WAV sink and write a 44-byte canonical header for 44.1 kHz /
 * 2-channel / 32-bit PCM. The RIFF and data sizes are placeholders, kept
 * current after every append (so the file is valid even if the emulator is
 * killed). Both audio sinks carry the Deluge's q31 samples (24-bit MSB-aligned
 * in 32-bit subframes) verbatim. Returns the open file, or NULL.
 */
static FILE *rza1l_usb_wav_open_file(const char *path)
{
    static const uint32_t rate = USB_PAUDIO_SAMPLE_RATE;
    static const uint16_t channels = 2;
    static const uint16_t bits = 32;
    uint32_t byte_rate = rate * channels * (bits / 8);
    uint16_t block_align = channels * (bits / 8);
    uint8_t hdr[44] = {
        'R','I','F','F', 0,0,0,0, 'W','A','V','E',
        'f','m','t',' ', 16,0,0,0, 1,0, 0,0, 0,0,0,0, 0,0,0,0, 0,0, 0,0,
        'd','a','t','a', 0,0,0,0,
    };
    FILE *fp;

    if (!path || path[0] == '\0') {
        return NULL;
    }
    fp = fopen(path, "wb");
    if (!fp) {
        warn_report("rza1l-usb: cannot open USB-audio WAV '%s'", path);
        return NULL;
    }
    hdr[22] = channels & 0xff;    hdr[23] = channels >> 8;
    hdr[24] = rate & 0xff;        hdr[25] = (rate >> 8) & 0xff;
    hdr[26] = (rate >> 16) & 0xff; hdr[27] = (rate >> 24) & 0xff;
    hdr[28] = byte_rate & 0xff;   hdr[29] = (byte_rate >> 8) & 0xff;
    hdr[30] = (byte_rate >> 16) & 0xff; hdr[31] = (byte_rate >> 24) & 0xff;
    hdr[32] = block_align & 0xff; hdr[33] = block_align >> 8;
    hdr[34] = bits & 0xff;        hdr[35] = bits >> 8;
    fwrite(hdr, 1, sizeof(hdr), fp);
    return fp;
}

static void rza1l_usb_wav_append(FILE *fp, uint64_t *data_bytes,
                                 const uint8_t *data, uint32_t len)
{
    if (!fp || len == 0) {
        return;
    }
    fwrite(data, 1, len, fp);
    *data_bytes += len;
    /* Keep the RIFF/data sizes current so the file is a valid, playable WAV
     * even if the emulator is killed without a clean close. */
    rza1l_usb_wav_patch_u32(fp, 4, 36 + (uint32_t)*data_bytes);
    rza1l_usb_wav_patch_u32(fp, 40, (uint32_t)*data_bytes);
    fseek(fp, 0, SEEK_END);
}

static void rza1l_usb_wav_close_file(FILE **fp, uint64_t *data_bytes)
{
    if (!*fp) {
        return;
    }
    rza1l_usb_wav_patch_u32(*fp, 4, 36 + (uint32_t)*data_bytes);
    rza1l_usb_wav_patch_u32(*fp, 40, (uint32_t)*data_bytes);
    fclose(*fp);
    *fp = NULL;
}

/* Open the to-host WAV sink (Deluge -> host stream capture). */
static void rza1l_usb_wav_open(RzA1lUsbState *s)
{
    s->wav = rza1l_usb_wav_open_file(s->audio_out);
    s->wav_data_bytes = 0;
    if (s->wav) {
        USB_DBG("USB-audio: to-host WAV sink open '%s'", s->audio_out);
    }
}

static void rza1l_usb_wav_write(RzA1lUsbState *s, const uint8_t *data,
                                uint32_t len)
{
    rza1l_usb_wav_append(s->wav, &s->wav_data_bytes, data, len);
}

static void rza1l_usb_wav_close(RzA1lUsbState *s)
{
    if (s->wav) {
        rza1l_usb_wav_close_file(&s->wav, &s->wav_data_bytes);
        USB_DBG("USB-audio: to-host WAV sink closed, %" PRIu64 " data bytes",
                s->wav_data_bytes);
    }
}

/* ---- Peripheral-mode USB-audio: from-host source (pipe 1 / D1FIFO) ------ */

/* Read a little-endian u32 (or fewer bytes) from a buffer. */
static uint32_t rza1l_usb_rd_le(const uint8_t *p, int n)
{
    uint32_t v = 0;
    int i;
    for (i = 0; i < n; i++) {
        v |= (uint32_t)p[i] << (8 * i);
    }
    return v;
}

/*
 * Open and validate an input WAV naming the from-host source. Parses the RIFF
 * chunks to find the PCM format and the start of the sample data. Accepts
 * 16/24/32-bit, mono or stereo PCM; the sample rate is assumed to be 44.1 kHz
 * (the only rate the stream runs at) and is not resampled. Returns true on
 * success, leaving the file positioned at the data.
 */
static bool rza1l_usb_wav_in_open(RzA1lUsbState *s)
{
    uint8_t riff[12], chunk[8], fmt[16];
    FILE *fp = fopen(s->audio_in, "rb");
    uint16_t fmt_tag;
    uint32_t rate;

    if (!fp) {
        warn_report("rza1l-usb: cannot open USB-audio input WAV '%s'",
                    s->audio_in);
        return false;
    }
    if (fread(riff, 1, 12, fp) != 12 ||
        memcmp(riff, "RIFF", 4) != 0 || memcmp(riff + 8, "WAVE", 4) != 0) {
        warn_report("rza1l-usb: '%s' is not a RIFF/WAVE file", s->audio_in);
        fclose(fp);
        return false;
    }
    /* Walk the chunks looking for "fmt " then "data". */
    while (fread(chunk, 1, 8, fp) == 8) {
        uint32_t size = rza1l_usb_rd_le(chunk + 4, 4);
        if (memcmp(chunk, "fmt ", 4) == 0) {
            uint32_t n = size < sizeof(fmt) ? size : sizeof(fmt);
            if (fread(fmt, 1, n, fp) != n) {
                break;
            }
            if (n < size) {
                fseek(fp, size - n, SEEK_CUR);
            }
            fmt_tag = rza1l_usb_rd_le(fmt, 2);
            s->wav_in_ch = rza1l_usb_rd_le(fmt + 2, 2);
            rate = rza1l_usb_rd_le(fmt + 4, 4);
            s->wav_in_bits = rza1l_usb_rd_le(fmt + 14, 2);
            if (fmt_tag != 1) {
                warn_report("rza1l-usb: input WAV '%s' is not PCM (tag %u)",
                            s->audio_in, fmt_tag);
                fclose(fp);
                return false;
            }
            if ((s->wav_in_ch != 1 && s->wav_in_ch != 2) ||
                (s->wav_in_bits != 16 && s->wav_in_bits != 24 &&
                 s->wav_in_bits != 32)) {
                warn_report("rza1l-usb: input WAV '%s' unsupported "
                            "(%u ch, %u-bit)", s->audio_in, s->wav_in_ch,
                            s->wav_in_bits);
                fclose(fp);
                return false;
            }
            if (rate != USB_PAUDIO_SAMPLE_RATE) {
                warn_report("rza1l-usb: input WAV '%s' is %u Hz; feeding it as "
                            "44.1 kHz (no resampling)", s->audio_in, rate);
            }
        } else if (memcmp(chunk, "data", 4) == 0) {
            s->wav_in_data_off = ftell(fp);
            s->wav_in = fp;
            USB_DBG("USB-audio: from-host source WAV '%s' (%u ch, %u-bit)",
                    s->audio_in, s->wav_in_ch, s->wav_in_bits);
            return true;
        } else {
            fseek(fp, size + (size & 1), SEEK_CUR); /* chunks are word-aligned */
        }
    }
    warn_report("rza1l-usb: input WAV '%s' has no data chunk", s->audio_in);
    fclose(fp);
    return false;
}

/* Fetch one stereo frame (two q31 samples, MSB-aligned) from the input WAV,
 * looping at end-of-file. */
static void rza1l_usb_wav_in_frame(RzA1lUsbState *s, int32_t *l, int32_t *r)
{
    uint8_t raw[2 * 4];
    uint32_t stride = s->wav_in_ch * (s->wav_in_bits / 8);
    int32_t ch[2] = { 0, 0 };
    int c;

    if (fread(raw, 1, stride, s->wav_in) != stride) {
        /* Loop the file (skip past the header to the data). */
        fseek(s->wav_in, s->wav_in_data_off, SEEK_SET);
        if (fread(raw, 1, stride, s->wav_in) != stride) {
            *l = *r = 0;
            return;
        }
    }
    for (c = 0; c < s->wav_in_ch; c++) {
        const uint8_t *p = raw + c * (s->wav_in_bits / 8);
        switch (s->wav_in_bits) {
        case 16:
            ch[c] = (int32_t)(int16_t)rza1l_usb_rd_le(p, 2) << 16;
            break;
        case 24:
            ch[c] = (int32_t)(rza1l_usb_rd_le(p, 3) << 8); /* sign via <<8 */
            break;
        default: /* 32 */
            ch[c] = (int32_t)rza1l_usb_rd_le(p, 4);
            break;
        }
    }
    *l = ch[0];
    *r = (s->wav_in_ch == 2) ? ch[1] : ch[0]; /* mono -> both channels */
}

/* Produce `frames` stereo frames of from-host audio into buf: interleaved
 * left/right, each a 4-byte little-endian q31 sample (24-bit MSB-aligned). */
static void rza1l_usb_fromhost_fill(RzA1lUsbState *s, uint8_t *buf,
                                    uint32_t frames)
{
    uint32_t i;

    for (i = 0; i < frames; i++) {
        int32_t l = 0, r = 0;

        if (s->audio_in_kind == AUDIO_IN_TONE) {
            double t = (double)s->tone_phase / USB_PAUDIO_SAMPLE_RATE;
            double v = sin(2.0 * M_PI * (double)s->tone_freq * t);
            /* ~0.37 of full scale, zeroing the low byte to keep it a clean
             * 24-bit value in the top bits (MSB-aligned q31). */
            l = r = (int32_t)(v * (double)0x30000000) & ~0xff;
            s->tone_phase++;
        } else if (s->audio_in_kind == AUDIO_IN_FILE) {
            rza1l_usb_wav_in_frame(s, &l, &r);
        }

        buf[i * 8 + 0] = l & 0xff;
        buf[i * 8 + 1] = (l >> 8) & 0xff;
        buf[i * 8 + 2] = (l >> 16) & 0xff;
        buf[i * 8 + 3] = (l >> 24) & 0xff;
        buf[i * 8 + 4] = r & 0xff;
        buf[i * 8 + 5] = (r >> 8) & 0xff;
        buf[i * 8 + 6] = (r >> 16) & 0xff;
        buf[i * 8 + 7] = (r >> 24) & 0xff;
    }
}

/*
 * Present one from-host packet in pipe 1's buffer, if the firmware has armed
 * the pipe (BRDYENB bit set by startFromHost) and the previous packet has been
 * drained. Paces 44 or 45 frames per USB frame, averaging 44.1 kHz. Raises the
 * pipe's BRDY so the firmware's usbAudioHandleBrdy() starts the receive DMA.
 */
static void rza1l_usb_fromhost_present(RzA1lUsbState *s)
{
    uint16_t bit = (uint16_t)(1u << USB_PAUDIO_PIPE_FROM_HOST);
    uint32_t frames;

    if (s->audio_in_kind == AUDIO_IN_NONE || s->fromhost_pending) {
        return;
    }
    if (!(s->regs[USB_BRDYENB >> 1] & bit)) {
        return; /* firmware has not armed the from-host pipe */
    }

    s->fromhost_frac += USB_PAUDIO_SAMPLE_RATE / 100; /* 441 per frame */
    frames = s->fromhost_frac / 10;
    s->fromhost_frac %= 10;
    if (frames * USB_PAUDIO_FRAME_BYTES > RZA1L_USB_AUDIO_PKT_MAX) {
        frames = RZA1L_USB_AUDIO_PKT_MAX / USB_PAUDIO_FRAME_BYTES;
    }

    rza1l_usb_fromhost_fill(s, s->fromhost, frames);
    s->fromhost_len = frames * USB_PAUDIO_FRAME_BYTES;
    s->fromhost_pos = 0;
    s->fromhost_pending = true;
    s->regs[USB_BRDYSTS >> 1] |= bit;
}

/* D1FIFO read: hand the DMAC the next word of the staged from-host packet.
 * With the source address fixed (CHCFG.SAD), the DMAC reads this port once per
 * 32-bit word; drain in order and retire the packet when the last word goes. */
static uint32_t rza1l_usb_read_d1fifo(RzA1lUsbState *s)
{
    uint32_t v = 0;
    int i;

    for (i = 0; i < 4; i++) {
        if (s->fromhost_pos < s->fromhost_len) {
            v |= (uint32_t)s->fromhost[s->fromhost_pos++] << (8 * i);
        }
    }
    if (s->fromhost_pending && s->fromhost_pos >= s->fromhost_len) {
        /* The firmware's DMA has drained the whole packet. */
        s->fromhost_frames += s->fromhost_len / USB_PAUDIO_FRAME_BYTES;
        rza1l_usb_wav_append(s->wav_in_cap, &s->wav_in_cap_bytes,
                             s->fromhost, s->fromhost_len);
        s->fromhost_pending = false;
    }
    return v;
}

/* ---- Peripheral-mode USB-audio: 1 ms SOF clock -------------------------- */

static void rza1l_usb_sof_tick(void *opaque)
{
    RzA1lUsbState *s = opaque;

    if (!s->sof_running) {
        return;
    }
    /* Present a from-host packet for this USB frame (raises pipe-1 BRDY), then
     * raise SOFR. The firmware's handler pumps usbAudioHandleSof(), which
     * services both directions, and usbAudioHandleBrdy() starts the receive
     * DMA for the packet just presented. */
    rza1l_usb_fromhost_present(s);
    s->regs[USB_INTSTS0 >> 1] |= USB_SOFR;
    rza1l_usb_update_irq(s);

    timer_mod(s->sof_timer,
              qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL) + NANOSECONDS_PER_SECOND / 1000);
}

/* Start/stop the SOF clock to track INTENB0.SOFE (set by startToHost()). */
static void rza1l_usb_sof_update(RzA1lUsbState *s)
{
    bool want = s->audio && (s->regs[USB_INTENB0 >> 1] & USB_SOFE);

    if (want && !s->sof_running) {
        s->sof_running = true;
        timer_mod(s->sof_timer,
                  qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL) +
                      NANOSECONDS_PER_SECOND / 1000);
        USB_DBG("USB-audio: SOF clock started");
    } else if (!want && s->sof_running) {
        s->sof_running = false;
        timer_del(s->sof_timer);
        USB_DBG("USB-audio: SOF clock stopped");
    }
}

/* ---- Peripheral-mode USB-audio: enumeration driver ---------------------- */

/*
 * The model plays the USB host against the firmware's peripheral stack. It
 * drives, in order: VBUS attach, bus reset, then the three no-data control
 * writes (SET_ADDRESS / SET_CONFIGURATION / SET_INTERFACE(stream-in, alt 1))
 * that bring the device to the configured, streaming state. Each step posts one
 * INTSTS0 event and waits (peri_wait) for the firmware to acknowledge it by
 * clearing that bit, then advances. See docs/usb-audio.md §9a.
 */
enum {
    PERI_IDLE = 0,
    PERI_ATTACH,        /* raise VBINT (VBUS present) */
    PERI_RESET,         /* raise DVST, device state -> Default */
    PERI_SET_ADDR,      /* SET_ADDRESS control write */
    PERI_SET_CONFIG,    /* SET_CONFIGURATION control write */
    PERI_SET_IFACE_OUT, /* SET_INTERFACE(stream-out, alt 1): from-host audio */
    PERI_SET_IFACE_IN,  /* SET_INTERFACE(stream-in, alt 1): to-host audio */
    PERI_STREAMING,     /* configured; both streams driven by SOF */
};

/* Set the INTSTS0 device-state (DVSQ) field without disturbing other bits. */
static void rza1l_usb_set_dvsq(RzA1lUsbState *s, uint16_t dvsq)
{
    s->regs[USB_INTSTS0 >> 1] =
        (s->regs[USB_INTSTS0 >> 1] & ~USB_DVSQ) | (dvsq & USB_DVSQ);
}

/* Latch an 8-byte control SETUP into the request registers (as the peripheral
 * controller would from a bus SETUP packet) and present a no-data write at the
 * status stage (CTSQ = WRND, VALID), raising CTRT. */
static void rza1l_usb_peri_control_write(RzA1lUsbState *s, uint8_t bmreq,
                                         uint8_t brequest, uint16_t wvalue,
                                         uint16_t windex)
{
    s->regs[USB_USBREQ >> 1] = ((uint16_t)brequest << 8) | bmreq;
    s->regs[USB_USBVAL >> 1] = wvalue;
    s->regs[USB_USBINDX >> 1] = windex;
    s->regs[USB_USBLENG >> 1] = 0;

    s->regs[USB_INTSTS0 >> 1] =
        (s->regs[USB_INTSTS0 >> 1] & ~USB_CTSQ) | USB_CS_WRND | USB_VALID;
    /*
     * Advance on the firmware's CCPL, not on it clearing CTRT. The firmware's
     * decoder clears CTRT at the very start of its interrupt handling, before
     * usb_pstd_save_request() has latched USBREQ/USBVAL/USBINDX. Advancing then
     * would let us post the next control write and overwrite those registers
     * before the firmware reads them, so the first request would be processed
     * with the next one's values. CCPL (issued by usb_pstd_ctrl_end, after
     * set_interface3 has run) is the real completion point.
     */
    s->peri_wait = 0;
    s->peri_ctrl_wait = true;
    s->pending_ints0 |= USB_CTRT;
    rza1l_usb_schedule_event(s);
}

/* Post the event for the current peri_step. */
static void rza1l_usb_peri_post(RzA1lUsbState *s)
{
    switch (s->peri_step) {
    case PERI_ATTACH:
        s->regs[USB_INTSTS0 >> 1] |= USB_VBSTS;   /* VBUS now present */
        s->peri_wait = USB_VBINT;
        s->pending_ints0 |= USB_VBINT;
        rza1l_usb_schedule_event(s);
        USB_DBG("USB-audio enum: attach (VBINT)");
        break;
    case PERI_RESET:
        rza1l_usb_set_dvsq(s, USB_DS_DFLT);
        s->peri_wait = USB_DVST;
        s->pending_ints0 |= USB_DVST;
        rza1l_usb_schedule_event(s);
        USB_DBG("USB-audio enum: bus reset (DVST, Default)");
        break;
    case PERI_SET_ADDR:
        USB_DBG("USB-audio enum: SET_ADDRESS");
        rza1l_usb_peri_control_write(s, 0x00, USB_REQ_SET_ADDRESS, 2, 0);
        break;
    case PERI_SET_CONFIG:
        USB_DBG("USB-audio enum: SET_CONFIGURATION");
        rza1l_usb_peri_control_write(s, 0x00, USB_REQ_SET_CONFIGURATION, 1, 0);
        break;
    case PERI_SET_IFACE_OUT: {
        /* Alt 1 = implicit feedback (follows our clock), alt 2 = adaptive
         * (host clocks it). Both use pipe 1 and the same format; only the
         * firmware's timing path differs. */
        uint16_t alt = s->audio_adaptive ? 2 : 1;
        USB_DBG("USB-audio enum: SET_INTERFACE(%d, alt %u) [from-host, %s]",
                USB_PAUDIO_STREAM_OUT_IFACE, alt,
                s->audio_adaptive ? "adaptive" : "implicit");
        rza1l_usb_peri_control_write(s, 0x01, USB_REQ_SET_INTERFACE, alt,
                                     USB_PAUDIO_STREAM_OUT_IFACE);
        break;
    }
    case PERI_SET_IFACE_IN:
        USB_DBG("USB-audio enum: SET_INTERFACE(%d, alt 1) [to-host]",
                USB_PAUDIO_STREAM_IN_IFACE);
        rza1l_usb_peri_control_write(s, 0x01, USB_REQ_SET_INTERFACE, 1,
                                     USB_PAUDIO_STREAM_IN_IFACE);
        break;
    default:
        break;
    }
}

/* Begin enumeration (one-shot), once the firmware has configured peripheral
 * mode and enabled the peripheral interrupt set. */
static void rza1l_usb_peri_kick(RzA1lUsbState *s)
{
    if (!rza1l_usb_is_peripheral(s) || s->peri_kicked) {
        return;
    }
    if (s->regs[USB_SYSCFG0 >> 1] & USB_DCFM) {
        return; /* still in host mode */
    }
    if (!(s->regs[USB_SYSCFG0 >> 1] & USB_USBE)) {
        return;
    }
    s->peri_kicked = true;
    s->peri_step = PERI_ATTACH;
    rza1l_usb_wav_open(s);

    /* Prime the from-host source for a fresh streaming session. */
    s->tone_phase = 0;
    s->fromhost_frac = 0;
    s->fromhost_frames = 0;
    s->fromhost_pending = false;
    s->fromhost_pos = s->fromhost_len = 0;
    if (s->wav_in) {
        fseek(s->wav_in, s->wav_in_data_off, SEEK_SET);
    }
    if (s->audio_in_kind != AUDIO_IN_NONE) {
        s->wav_in_cap = rza1l_usb_wav_open_file(s->audio_in_capture);
        s->wav_in_cap_bytes = 0;
    }

    rza1l_usb_peri_post(s);
}

/* Move to the next enumeration step and post its event. Shared by the two
 * completion signals: an INTSTS0 edge the firmware clears (VBINT / DVST) and a
 * control write's CCPL. */
static void rza1l_usb_peri_advance(RzA1lUsbState *s)
{
    switch (s->peri_step) {
    case PERI_ATTACH:
        s->peri_step = PERI_RESET;
        break;
    case PERI_RESET:
        s->peri_step = PERI_SET_ADDR;
        break;
    case PERI_SET_ADDR:
        rza1l_usb_set_dvsq(s, USB_DS_ADDS);
        s->peri_step = PERI_SET_CONFIG;
        break;
    case PERI_SET_CONFIG:
        rza1l_usb_set_dvsq(s, USB_DS_CNFG);
        /* Start each audio stream only when it is wanted: from-host when a
         * source is configured (audio-in), to-host when a capture sink is
         * (audio-out). With neither, the composite still enumerates and MIDI
         * runs - a MIDI-only peripheral. */
        if (s->audio_in_kind != AUDIO_IN_NONE) {
            s->peri_step = PERI_SET_IFACE_OUT;
        } else if (s->audio_out && s->audio_out[0]) {
            s->peri_step = PERI_SET_IFACE_IN;
        } else {
            s->peri_step = PERI_STREAMING;
            USB_DBG("USB-audio enum: configured, MIDI only (no audio streams)");
            return;
        }
        break;
    case PERI_SET_IFACE_OUT:
        if (s->audio_out && s->audio_out[0]) {
            s->peri_step = PERI_SET_IFACE_IN;
        } else {
            s->peri_step = PERI_STREAMING;
            USB_DBG("USB-audio enum: configured, streaming (from-host only)");
            return;
        }
        break;
    case PERI_SET_IFACE_IN:
        s->peri_step = PERI_STREAMING;
        USB_DBG("USB-audio enum: configured, streaming");
        return;
    default:
        return;
    }
    rza1l_usb_peri_post(s);
}

/* The firmware cleared one or more INTSTS0 bits. If it acknowledged the edge
 * event we were waiting on (VBINT attach / DVST bus reset), advance. */
static void rza1l_usb_peri_on_clear(RzA1lUsbState *s, uint16_t cleared)
{
    if (!rza1l_usb_is_peripheral(s) || !s->peri_kicked || s->peri_wait == 0) {
        return;
    }
    if (!(cleared & s->peri_wait)) {
        return;
    }
    s->peri_wait = 0;
    rza1l_usb_peri_advance(s);
}

/*
 * The firmware issued CCPL, completing the status stage of the control write we
 * posted. Real hardware then returns the control sequencer to idle and raises
 * one more CTRT with CTSQ = IDST; the firmware's stand_req0() handles that
 * "setup/idle" stage - running the setup-time callbacks it defers past the
 * status stage, in particular set_configuration0() -> usb_peri_configured()
 * (which sets g_usb_peri_connected, gating peripheral MIDI) and set_interface0().
 * Present that idle-stage CTRT now (it uses the request the firmware already
 * latched, so it is safe), and advance only once the firmware acknowledges it -
 * see rza1l_usb_peri_control_write() for why advancing on the earlier,
 * status-stage CTRT would race save_request().
 */
static void rza1l_usb_peri_on_ccpl(RzA1lUsbState *s)
{
    if (!rza1l_usb_is_peripheral(s) || !s->peri_kicked || !s->peri_ctrl_wait) {
        return;
    }
    s->peri_ctrl_wait = false;
    /* CTSQ is already IDST and VALID clear (the CCPL handler cleared them). */
    s->peri_wait = USB_CTRT;
    s->pending_ints0 |= USB_CTRT;
    rza1l_usb_schedule_event(s);
}

/* Accumulate a to-host audio packet word written by the DMAC to D0FIFO. */
static void rza1l_usb_d0fifo_write(RzA1lUsbState *s, uint32_t value)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (s->tohost_len < RZA1L_USB_AUDIO_PKT_MAX) {
            s->tohost[s->tohost_len++] = (value >> (8 * i)) & 0xff;
        }
    }
}

/* Commit the accumulated to-host packet (D0FIFOCTR.BVAL) to the WAV sink. */
static void rza1l_usb_d0fifo_commit(RzA1lUsbState *s)
{
    if (s->tohost_len) {
        rza1l_usb_wav_write(s, s->tohost, s->tohost_len);
        s->tohost_len = 0;
    }
}

/* ---- Bulk MIDI data bridge ---------------------------------------------- */

/* Per-pipe interrupt status bit (BRDYSTS/BEMPSTS/BRDYENB/...): pipe n -> 1<<n. */
static inline uint16_t rza1l_usb_pipe_bit(uint16_t pipe)
{
    return (uint16_t)(1u << pipe);
}

/* Number of MIDI bytes carried by a USB-MIDI event packet, indexed by CIN. */
static const uint8_t usb_midi_cin_len[16] = {
    0, 0, 2, 3, 3, 1, 2, 3, 3, 3, 3, 3, 2, 2, 3, 1,
};

/*
 * Enqueue one complete 4-byte USB-MIDI event packet onto the bulk IN ring.
 * Packets are dropped if the firmware has fallen too far behind (the ring is
 * full) - the same lossy behaviour a real MIDI input would exhibit.
 */
static void rza1l_usb_rxq_push(RzA1lUsbState *s, uint8_t cin, uint8_t b0,
                               uint8_t b1, uint8_t b2)
{
    if (s->rx_q_count + 4 > RZA1L_USB_RXQ_BYTES) {
        USB_DBG("bulk IN ring full, dropping MIDI packet");
        return;
    }
    s->rx_q[s->rx_q_tail] = cin;
    s->rx_q[(s->rx_q_tail + 1) % RZA1L_USB_RXQ_BYTES] = b0;
    s->rx_q[(s->rx_q_tail + 2) % RZA1L_USB_RXQ_BYTES] = b1;
    s->rx_q[(s->rx_q_tail + 3) % RZA1L_USB_RXQ_BYTES] = b2;
    s->rx_q_tail = (s->rx_q_tail + 4) % RZA1L_USB_RXQ_BYTES;
    s->rx_q_count += 4;
}

/*
 * Frame one raw host-MIDI byte into USB-MIDI event packets (cable 0). Handles
 * channel-voice messages (with running status), system common / real-time
 * messages, and SysEx. Completed packets are pushed onto the bulk IN ring.
 */
static void rza1l_usb_midi_frame_byte(RzA1lUsbState *s, uint8_t b)
{
    if (b >= 0xf8) {
        /* System real-time: a single status byte, may interleave anywhere. */
        rza1l_usb_rxq_push(s, 0x0f, b, 0, 0);
        return;
    }

    if (b & 0x80) {
        /* Status byte. */
        if (b == 0xf0) {
            s->in_sysex = true;
            s->sysex_buf[0] = 0xf0;
            s->sysex_len = 1;
            return;
        }
        if (b == 0xf7) {
            if (s->in_sysex) {
                s->sysex_buf[s->sysex_len++] = 0xf7;
                switch (s->sysex_len) {
                case 1:
                    rza1l_usb_rxq_push(s, 0x05, 0xf7, 0, 0);
                    break;
                case 2:
                    rza1l_usb_rxq_push(s, 0x06, s->sysex_buf[0],
                                       s->sysex_buf[1], 0);
                    break;
                default:
                    rza1l_usb_rxq_push(s, 0x07, s->sysex_buf[0],
                                       s->sysex_buf[1], s->sysex_buf[2]);
                    break;
                }
                s->in_sysex = false;
                s->sysex_len = 0;
            }
            return;
        }
        /* Any other status terminates an in-progress SysEx. */
        s->in_sysex = false;
        s->sysex_len = 0;

        if (b < 0xf0) {
            /* Channel-voice status: set running status. */
            s->midi_status = b;
            s->midi_ndata = 0;
            s->midi_need = (b < 0xc0 || b >= 0xe0) ? 2 : 1;
        } else {
            /* System common (0xf1..0xf6). */
            s->midi_status = b;
            s->midi_ndata = 0;
            switch (b) {
            case 0xf2: s->midi_need = 2; break;       /* song position */
            case 0xf1: case 0xf3: s->midi_need = 1; break; /* MTC / song sel */
            default:                                   /* f4,f5,f6: no data */
                rza1l_usb_rxq_push(s, 0x05, b, 0, 0);
                s->midi_status = 0;
                s->midi_need = 0;
                break;
            }
        }
        return;
    }

    /* Data byte. */
    if (s->in_sysex) {
        s->sysex_buf[s->sysex_len++] = b;
        if (s->sysex_len == 3) {
            rza1l_usb_rxq_push(s, 0x04, s->sysex_buf[0], s->sysex_buf[1],
                               s->sysex_buf[2]);
            s->sysex_len = 0;
        }
        return;
    }

    if (s->midi_status == 0) {
        return; /* orphan data byte */
    }

    s->midi_data[s->midi_ndata++] = b;
    if (s->midi_ndata < s->midi_need) {
        return;
    }

    /* A complete message has been collected; emit its USB-MIDI packet. */
    if (s->midi_status < 0xf0) {
        uint8_t cin = s->midi_status >> 4;
        rza1l_usb_rxq_push(s, cin, s->midi_status, s->midi_data[0],
                           s->midi_need == 2 ? s->midi_data[1] : 0);
        /* Channel-voice messages support running status. */
        s->midi_ndata = 0;
    } else {
        uint8_t cin = (s->midi_status == 0xf2) ? 0x03 : 0x02;
        rza1l_usb_rxq_push(s, cin, s->midi_status, s->midi_data[0],
                           s->midi_need == 2 ? s->midi_data[1] : 0);
        s->midi_status = 0; /* system common does not run */
        s->midi_ndata = 0;
    }
}

/*
 * If a bulk IN pipe is armed (PID=BUF), its BRDY interrupt is enabled, no
 * transfer is already in flight, and packets are queued, latch up to one
 * bulk-max-packet transfer and raise the pipe's BRDY interrupt so the firmware
 * drains it via CFIFO.
 */
static void rza1l_usb_try_deliver_rx(RzA1lUsbState *s)
{
    uint16_t pipe;

    if (!s->mbridge || s->rx_xfer_len != 0 || s->rx_q_count == 0) {
        return;
    }

    for (pipe = s->midi_rx_lo; pipe <= s->midi_rx_hi; pipe++) {
        uint16_t bit = rza1l_usb_pipe_bit(pipe);

        if (!(s->recv_armed & bit)) {
            continue;
        }
        if (!(s->regs[USB_BRDYENB >> 1] & bit)) {
            continue;
        }

        /* Latch up to one max-size transfer from the ring. */
        uint32_t n = MIN(s->rx_q_count, RZA1L_USB_BULK_MAXP);
        uint32_t i;
        for (i = 0; i < n; i++) {
            s->rx_xfer[i] = s->rx_q[s->rx_q_head];
            s->rx_q_head = (s->rx_q_head + 1) % RZA1L_USB_RXQ_BYTES;
        }
        s->rx_q_count -= n;
        s->rx_xfer_len = n;
        s->rx_xfer_pos = 0;
        s->rx_xfer_pipe = pipe;

        /* This transfer consumes the pipe's armed state; the firmware re-arms
         * (PID=BUF) after draining the data in checkIncomingUsbMidi(). */
        s->recv_armed &= ~bit;

        s->pending_brdy |= bit;
        rza1l_usb_schedule_event(s);
        USB_DBG("bulk IN pipe %u: deliver %u bytes (BRDY)", pipe, n);
        return;
    }
}

/*
 * Deframe the bulk OUT transfer the firmware just committed (CFIFO + BVAL) back
 * into a raw MIDI byte stream and write it to the host chardev.
 */
static void rza1l_usb_flush_tx(RzA1lUsbState *s)
{
    uint32_t i;

    for (i = 0; i + 4 <= s->tx_len; i += 4) {
        uint8_t cin = s->tx_buf[i] & 0x0f;
        uint8_t len = usb_midi_cin_len[cin];
        if (len) {
            /* qemu_chr_fe_write_all is a no-op if no chardev is connected. */
            qemu_chr_fe_write_all(&s->chr, &s->tx_buf[i + 1], len);
        }
    }
    s->tx_len = 0;
}

/* ---- Control-transfer engine (DCP / pipe 0) ----------------------------- */

/*
 * The firmware has written USBREQ/USBVAL/USBINDX/USBLENG and triggered the
 * SETUP packet (DCPCTR.SUREQ). Decode the request, stage any IN response, and
 * queue the SETUP-ACK interrupt. Data-stage BRDY / status-stage BEMP follow as
 * the firmware advances the transfer.
 */
static void rza1l_usb_setup(RzA1lUsbState *s)
{
    uint16_t req = s->regs[USB_USBREQ >> 1];
    uint16_t val = s->regs[USB_USBVAL >> 1];
    uint16_t leng = s->regs[USB_USBLENG >> 1];
    uint8_t bmreqtype = req & 0xff;
    uint8_t brequest = (req >> 8) & 0xff;

    s->resp_len = 0;
    s->resp_pos = 0;
    s->data_ready = false;
    s->ctrl_in = (bmreqtype & 0x80) != 0;
    s->ctrl_active = true;

    USB_DBG("SETUP bmReqType=0x%02x bRequest=0x%02x wValue=0x%04x wLength=%u",
            bmreqtype, brequest, val, leng);

    switch (brequest) {
    case USB_REQ_GET_DESCRIPTOR: {
        uint8_t type = (val >> 8) & 0xff;
        const uint8_t *src = NULL;
        uint32_t srclen = 0;

        if (type == USB_DT_DEVICE) {
            src = usb_midi_device_desc;
            srclen = sizeof(usb_midi_device_desc);
        } else if (type == USB_DT_CONFIGURATION) {
            src = usb_midi_config_desc;
            srclen = sizeof(usb_midi_config_desc);
        } else if (type == USB_DT_STRING) {
            if ((val & 0xff) == 0) {
                src = usb_midi_string_langid;
                srclen = sizeof(usb_midi_string_langid);
            } else {
                src = usb_midi_string_empty;
                srclen = sizeof(usb_midi_string_empty);
            }
        }
        if (src) {
            uint32_t n = MIN(leng, srclen);
            n = MIN(n, RZA1L_USB_RESP_MAX);
            memcpy(s->resp, src, n);
            s->resp_len = n;
            s->data_ready = (n > 0);
        }
        break;
    }
    case USB_REQ_SET_ADDRESS:
        s->dev_address = val;
        break;
    case USB_REQ_SET_CONFIGURATION:
        s->configured = (val != 0);
        USB_DBG("SET_CONFIGURATION %u -> configured=%d", val, s->configured);
        break;
    default:
        USB_DBG("unhandled control request 0x%02x", brequest);
        break;
    }

    /* SETUP transaction acknowledged by the (synthetic) device. */
    s->pending_ints1 |= USB_SACK;

    rza1l_usb_schedule_event(s);
}

/* ---- MMIO read ---------------------------------------------------------- */

static uint16_t rza1l_usb_read16(RzA1lUsbState *s, hwaddr offset)
{
    switch (offset) {
    case USB_SYSSTS0:
        /* Report the modelled line state; host-sequencer bits read 0. */
        return s->line_state & USB_LNST;

    case USB_DVSTCTR0: {
        uint16_t v = s->regs[offset >> 1] & ~(uint16_t)(USB_RHST | USB_HSPROC);
        /* Once the bus is active with a device, report full-speed, no HSPROC. */
        if (s->attached && (s->regs[offset >> 1] & USB_UACT)) {
            v |= USB_FSMODE;
        }
        return v;
    }

    case USB_CFIFOCTR: {
        uint16_t pipe = s->regs[USB_CFIFOSEL >> 1] & USB_CURPIPE;

        /* Bulk IN (receive) pipe: report FRDY and the remaining byte count only
         * while a transfer is latched. With nothing waiting it must report NO
         * FRDY, so the firmware's drain loop (which keeps reading until FRDY
         * clears) stops instead of spinning on a zero-length packet. */
        if (pipe >= s->midi_rx_lo && pipe <= s->midi_rx_hi) {
            if (pipe == s->rx_xfer_pipe && s->rx_xfer_len > s->rx_xfer_pos) {
                uint32_t rem = s->rx_xfer_len - s->rx_xfer_pos;
                return USB_FRDY | (rem & USB_DTLN);
            }
            return 0; /* no packet waiting on this receive pipe */
        }

        /* Control IN data: FIFO ready, DTLN = bytes left in this packet. */
        if (s->data_ready) {
            uint32_t rem = s->resp_len - s->resp_pos;
            uint32_t pkt = MIN(rem, RZA1L_USB_DCP_MAXP);
            return USB_FRDY | (pkt & USB_DTLN);
        }
        /* Otherwise the FIFO is ready to accept a write (bulk/control OUT). */
        return USB_FRDY;
    }

    case USB_D0FIFOCTR:
        /* To-host audio buffer: always report FRDY (a buffer is free). The WAV
         * sink consumes each committed packet immediately, so there is no
         * back-pressure to model. */
        return USB_FRDY;

    case USB_D1FIFOCTR:
        /* From-host audio buffer: report FRDY and the staged packet's byte
         * count while one is waiting; otherwise no data (no FRDY), which stops
         * startFromHostDma() re-arming once the pipe has been drained. */
        if (s->audio && s->fromhost_pending &&
            s->fromhost_pos < s->fromhost_len) {
            return USB_FRDY | ((s->fromhost_len - s->fromhost_pos) & USB_DTLN);
        }
        return 0;

    case USB_INTSTS0:
        return rza1l_usb_intsts0(s);

    case USB_INTSTS1:
    case USB_BRDYSTS:
    case USB_NRDYSTS:
    case USB_BEMPSTS:
        return s->regs[offset >> 1];

    case USB_FRMNUM:
    case USB_UFRMNUM:
        return 0;

    default:
        return s->regs[offset >> 1];
    }
}

static uint32_t rza1l_usb_read_cfifo(RzA1lUsbState *s)
{
    uint16_t pipe = s->regs[USB_CFIFOSEL >> 1] & USB_CURPIPE;
    uint32_t v = 0;
    int i;

    /* Bulk IN pipe: drain the latched transfer four bytes at a time, LE. */
    if (pipe >= s->midi_rx_lo && pipe <= s->midi_rx_hi &&
        pipe == s->rx_xfer_pipe && s->rx_xfer_len > 0) {
        for (i = 0; i < 4; i++) {
            if (s->rx_xfer_pos < s->rx_xfer_len) {
                v |= (uint32_t)s->rx_xfer[s->rx_xfer_pos++] << (8 * i);
            }
        }
        if (s->rx_xfer_pos >= s->rx_xfer_len) {
            /* Transfer drained; release the latch and deliver any backlog once
             * the firmware re-arms the pipe. */
            s->rx_xfer_len = 0;
            s->rx_xfer_pos = 0;
            s->rx_xfer_pipe = 0;
        }
        return v;
    }

    /* Return up to four bytes of the staged control-IN response, LE order. */
    for (i = 0; i < 4; i++) {
        if (s->resp_pos < s->resp_len) {
            v |= (uint32_t)s->resp[s->resp_pos++] << (8 * i);
        }
    }
    if (s->resp_pos >= s->resp_len) {
        /* Whole response consumed; the final (short) packet ends the stage. */
        s->data_ready = false;
    } else if ((s->resp_pos % RZA1L_USB_DCP_MAXP) == 0) {
        /*
         * A full max-size packet has just been drained and more data remains:
         * the controller makes the next packet available, raising BRDY again.
         */
        s->pending_brdy |= 0x0001;
        rza1l_usb_schedule_event(s);
    }
    return v;
}

/*
 * CFIFO write. For the bulk OUT (send) pipe the firmware streams 32-bit
 * USB-MIDI event packets here before committing the transfer with CFIFOCTR.BVAL;
 * accumulate them. Writes on any other pipe (control OUT status stages) are
 * accepted and discarded.
 */
static void rza1l_usb_write_cfifo(RzA1lUsbState *s, uint32_t value)
{
    uint16_t pipe = s->regs[USB_CFIFOSEL >> 1] & USB_CURPIPE;
    int i;

    if (s->mbridge && pipe == s->midi_tx_pipe) {
        for (i = 0; i < 4; i++) {
            if (s->tx_len < RZA1L_USB_TXBUF_BYTES) {
                s->tx_buf[s->tx_len++] = (value >> (8 * i)) & 0xff;
            }
        }
    }
}

static uint64_t rza1l_usb_read(void *opaque, hwaddr offset, unsigned size)
{
    RzA1lUsbState *s = opaque;
    uint64_t value;

    if (offset == USB_CFIFO) {
        return rza1l_usb_read_cfifo(s);
    }
    if (offset == USB_D1FIFO) {
        /* From-host audio payload, drained word-by-word by the DMAC (ch1). */
        return rza1l_usb_read_d1fifo(s);
    }

    switch (size) {
    case 1: {
        uint16_t word = rza1l_usb_read16(s, offset & ~1u);
        value = (offset & 1) ? (word >> 8) : (word & 0xff);
        break;
    }
    case 2:
        value = rza1l_usb_read16(s, offset);
        break;
    case 4:
        value = rza1l_usb_read16(s, offset) |
                ((uint32_t)rza1l_usb_read16(s, offset + 2) << 16);
        break;
    default:
        value = 0;
        break;
    }
    return value;
}

/* ---- MMIO write --------------------------------------------------------- */

static void rza1l_usb_write16(RzA1lUsbState *s, hwaddr offset, uint16_t value)
{
    switch (offset) {
    case USB_INTSTS0: {
        /* Write-0-to-clear status: the firmware ANDs to acknowledge. Detect the
         * edge bits it just cleared so the peripheral enumeration driver can
         * advance when its posted event is acknowledged. */
        uint16_t before = s->regs[offset >> 1];
        s->regs[offset >> 1] &= value;
        rza1l_usb_peri_on_clear(s, before & ~s->regs[offset >> 1]);
        rza1l_usb_update_irq(s);
        return;
    }
    case USB_INTSTS1:
    case USB_BRDYSTS:
    case USB_NRDYSTS:
    case USB_BEMPSTS:
        /* Write-0-to-clear status: the firmware ANDs to acknowledge. */
        s->regs[offset >> 1] &= value;
        rza1l_usb_update_irq(s);
        return;

    case USB_INTENB0:
    case USB_INTENB1:
        s->regs[offset >> 1] = value;
        /*
         * hw_usb_hmodule_init() detects the already-attached device via
         * SYSSTS0 and performs the bus reset inline, then enables the attach
         * interrupt. The MGR task, however, only starts enumeration in
         * response to an ATTCH interrupt. Mirror real hardware (which raises
         * ATTCH once DRPD sees the device) by delivering a one-shot ATTCH the
         * first time the firmware arms it with a device present.
         */
        if (offset == USB_INTENB1 && s->midi && s->attached &&
            !s->attach_signalled && (value & USB_ATTCH)) {
            s->attach_signalled = true;
            s->pending_attach = true;
            rza1l_usb_schedule_event(s);
        }
        if (offset == USB_INTENB0 && rza1l_usb_is_peripheral(s)) {
            /* Start enumeration once the firmware enables the peripheral
             * interrupt set (VBINT et al) having configured function mode, and
             * track the SOF clock (startToHost() enables INTENB0.SOFE; a
             * MIDI-only peripheral never sets it, so the clock stays off). */
            if (value & USB_VBINT) {
                rza1l_usb_peri_kick(s);
            }
            rza1l_usb_sof_update(s);
        }
        rza1l_usb_update_irq(s);
        return;

    case USB_DCPCTR:
        /*
         * SUREQ (issue SETUP) and CCPL (complete control transfer / status
         * stage) are self-clearing command bits. Process the command and store
         * the register with them cleared so the firmware's read-back polls see
         * the operation has finished.
         */
        if (s->midi && (value & USB_SUREQ)) {
            s->regs[offset >> 1] = value & ~USB_SUREQ;
            rza1l_usb_setup(s);
        } else if (s->midi && (value & USB_CCPL)) {
            s->regs[offset >> 1] = value & ~USB_CCPL;
            /* Status stage completed via CCPL -> pipe-0 BEMP. */
            if (s->ctrl_active) {
                s->ctrl_active = false;
                s->pending_bemp |= 0x0001;
                rza1l_usb_schedule_event(s);
            }
        } else if (rza1l_usb_is_peripheral(s) && (value & USB_CCPL)) {
            /*
             * Peripheral control transfer completed. Return the control
             * sequencer to idle (CTSQ = IDST, VALID clear) so the firmware's
             * CTSQ read-back sees completion rather than a stuck status stage.
             */
            s->regs[offset >> 1] = value & ~USB_CCPL;
            s->regs[USB_INTSTS0 >> 1] &= ~(USB_CTSQ | USB_VALID);
            /* Control write complete: advance enumeration (and post the next
             * control write, now that the firmware has read this one). */
            rza1l_usb_peri_on_ccpl(s);
        } else {
            s->regs[offset >> 1] = value;
        }
        return;

    case USB_BRDYENB: {
        uint16_t before = s->regs[offset >> 1];
        s->regs[offset >> 1] = value;
        if (s->audio) {
            /* startFromHost() sets this pipe's BRDY enable; stopFromHost()
             * clears it. On either edge, reset the from-host pacing and staging
             * so a (re)started stream begins cleanly and a stopped one stops
             * presenting packets. */
            uint16_t fb = (uint16_t)(1u << USB_PAUDIO_PIPE_FROM_HOST);
            if ((value & fb) != (before & fb)) {
                s->fromhost_frac = 0;
                s->fromhost_pending = false;
                s->fromhost_pos = s->fromhost_len = 0;
            }
        }
        if (s->midi && (value & 0x0001)) {
            if (s->data_ready && s->resp_pos < s->resp_len) {
                /*
                 * Control-read data stage: the firmware is asking for the IN
                 * descriptor data staged at SETUP time.
                 */
                s->pending_brdy |= 0x0001;
                rza1l_usb_schedule_event(s);
            } else if (s->ctrl_active && !s->ctrl_in) {
                /*
                 * Status stage of a no-data control write (SET_ADDRESS /
                 * SET_CONFIGURATION) is an IN zero-length packet, completed via
                 * pipe-0 BRDY.
                 */
                s->ctrl_active = false;
                s->pending_brdy |= 0x0001;
                rza1l_usb_schedule_event(s);
            }
        }
        /* Enabling a bulk IN pipe's BRDY may unblock a queued transfer. */
        rza1l_usb_try_deliver_rx(s);
        /*
         * Re-evaluate the interrupt: a per-pipe BRDYSTS bit may already be
         * latched (the status is set independently of its enable), so enabling
         * it here must raise the level-triggered interrupt immediately.
         */
        rza1l_usb_update_irq(s);
        return;
    }

    case USB_BEMPENB:
        s->regs[offset >> 1] = value;
        /*
         * The firmware arms pipe-0 BEMP to await the control transfer's status
         * stage (a zero-length packet driven via CFIFO/BVAL). Once the data
         * stage (if any) has been consumed, signal that the status stage has
         * completed.
         */
        if (s->midi && (value & 0x0001) && s->ctrl_active && !s->data_ready) {
            s->ctrl_active = false;
            s->pending_bemp |= 0x0001;
            rza1l_usb_schedule_event(s);
        }
        /*
         * Re-evaluate the interrupt: the bulk OUT transfer completes (BEMPSTS
         * latched) as soon as the firmware commits the FIFO with BVAL, which
         * happens before it enables this pipe's BEMP. Enabling it here must
         * therefore raise the level-triggered interrupt for the already-latched
         * completion so multi-transfer sends continue.
         */
        rza1l_usb_update_irq(s);
        return;

    case USB_D0FIFOCTR:
        /* BVAL commits the to-host audio packet the DMAC just staged into
         * D0FIFO; flush it to the WAV sink. BCLR discards it. */
        if (s->audio && (value & USB_BVAL)) {
            rza1l_usb_d0fifo_commit(s);
        } else if (value & USB_BCLR) {
            s->tohost_len = 0;
        }
        return;

    case USB_CFIFOCTR: {
        uint16_t pipe = s->regs[USB_CFIFOSEL >> 1] & USB_CURPIPE;
        /*
         * BVAL on the bulk OUT pipe commits a transmit buffer: deframe the
         * accumulated USB-MIDI packets to raw MIDI on the chardev and signal
         * transmit completion via the pipe's BEMP interrupt. BCLR discards a
         * (zero-length) buffer. Pipe-0 control writes are no-ops here.
         */
        if (s->mbridge && pipe == s->midi_tx_pipe && (value & USB_BVAL)) {
            rza1l_usb_flush_tx(s);
            s->pending_bemp |= rza1l_usb_pipe_bit(s->midi_tx_pipe);
            rza1l_usb_schedule_event(s);
        } else if (value & USB_BCLR) {
            s->tx_len = 0;
        }
        return;
    }

    case USB_PIPE1CTR + 0:  /* PIPE1CTR */
    case USB_PIPE1CTR + 2:  /* PIPE2CTR */
    case USB_PIPE1CTR + 4:  /* PIPE3CTR */
    case USB_PIPE1CTR + 6:  /* PIPE4CTR */
    case USB_PIPE1CTR + 8:  /* PIPE5CTR */
    case USB_PIPE1CTR + 10: /* PIPE6CTR */
    case USB_PIPE1CTR + 12: /* PIPE7CTR */
    case USB_PIPE1CTR + 14: /* PIPE8CTR */
    case USB_PIPE1CTR + 16: /* PIPE9CTR */ {
        uint16_t pipe = ((offset - USB_PIPE1CTR) >> 1) + 1;
        s->regs[offset >> 1] = value;
        /*
         * Writing PID=BUF to a bulk IN pipe arms it to receive: the firmware
         * is ready for the next USB-MIDI transfer. Deliver any queued data.
         */
        if (s->mbridge && pipe >= s->midi_rx_lo && pipe <= s->midi_rx_hi &&
            (value & USB_PID) == USB_PID_BUF) {
            s->recv_armed |= rza1l_usb_pipe_bit(pipe);
            USB_DBG("arm bulk IN pipe %u (PID=BUF), recv_armed=0x%x",
                    pipe, s->recv_armed);
            rza1l_usb_try_deliver_rx(s);
        }
        return;
    }

    case USB_SYSSTS0:
        return; /* read-only */

    default:
        s->regs[offset >> 1] = value;
        return;
    }
}

static void rza1l_usb_write(void *opaque, hwaddr offset, uint64_t value,
                            unsigned size)
{
    RzA1lUsbState *s = opaque;

    if (rza1l_usb_debug() && offset != USB_CFIFO && offset != USB_D0FIFO &&
        offset != USB_D1FIFO) {
        USB_DBG("W [0x%02x]=0x%04x (sz%u)", (unsigned)offset,
                (unsigned)(value & 0xffff), size);
    }

    if (offset == USB_CFIFO) {
        rza1l_usb_write_cfifo(s, value);
        return;
    }
    if (offset == USB_D0FIFO) {
        /* To-host audio payload, written word-by-word by the DMAC (ch0). */
        rza1l_usb_d0fifo_write(s, value);
        return;
    }

    switch (size) {
    case 1: {
        hwaddr word_off = offset & ~1u;
        uint16_t word = s->regs[word_off >> 1];
        if (offset & 1) {
            word = (word & 0x00ff) | ((value & 0xff) << 8);
        } else {
            word = (word & 0xff00) | (value & 0xff);
        }
        rza1l_usb_write16(s, word_off, word);
        break;
    }
    case 2:
        rza1l_usb_write16(s, offset, value);
        break;
    case 4:
        rza1l_usb_write16(s, offset, value & 0xffff);
        rza1l_usb_write16(s, offset + 2, (value >> 16) & 0xffff);
        break;
    default:
        break;
    }
}

static const MemoryRegionOps rza1l_usb_ops = {
    .read = rza1l_usb_read,
    .write = rza1l_usb_write,
    .endianness = DEVICE_NATIVE_ENDIAN,
    .valid.min_access_size = 1,
    .valid.max_access_size = 4,
};

/* ---- Host MIDI chardev (bulk IN source) -------------------------------- */

/*
 * Flow control for the host->device direction: only accept as many raw MIDI
 * bytes as could still fit in the bulk IN ring once framed. Each raw byte
 * frames into at most one 4-byte packet, so report a quarter of the free ring.
 */
static int rza1l_usb_chr_can_receive(void *opaque)
{
    RzA1lUsbState *s = opaque;
    uint32_t free_bytes = RZA1L_USB_RXQ_BYTES - s->rx_q_count;

    return free_bytes / 4;
}

static void rza1l_usb_chr_receive(void *opaque, const uint8_t *buf, int size)
{
    RzA1lUsbState *s = opaque;
    int i;

    USB_DBG("chardev RX %d bytes (first=0x%02x)", size, size ? buf[0] : 0);
    for (i = 0; i < size; i++) {
        rza1l_usb_midi_frame_byte(s, buf[i]);
    }
    USB_DBG("after framing: rx_q_count=%u recv_armed=0x%x brdyenb=0x%x",
            s->rx_q_count, s->recv_armed, s->regs[USB_BRDYENB >> 1]);
    rza1l_usb_try_deliver_rx(s);
}

static void rza1l_usb_reset(DeviceState *dev)
{
    RzA1lUsbState *s = RZA1L_USB(dev);

    memset(s->regs, 0, sizeof(s->regs));
    /*
     * When acting as a USB-MIDI device, present a full-speed device on the
     * host port from boot. The firmware's synchronous host init
     * (hw_usb_hmodule_init) samples SYSSTS0.LNST via usb_chattaring(); seeing
     * FS_JSTS there sets anythingInitiallyAttachedAsUSBHost, keeps the
     * controller in host mode, and drives the bus reset + enumeration inline.
     */
    s->attached = s->midi;
    s->line_state = s->midi ? USB_FS_JSTS : 0;
    s->dev_address = 0;
    s->configured = false;
    s->resp_len = 0;
    s->resp_pos = 0;
    s->ctrl_in = false;
    s->data_ready = false;
    s->ctrl_active = false;
    s->pending_ints0 = 0;
    s->pending_ints1 = 0;
    s->pending_brdy = 0;
    s->pending_bemp = 0;
    s->pending_attach = false;
    s->attach_signalled = false;

    /* Bulk MIDI bridge state. */
    s->rx_q_head = 0;
    s->rx_q_tail = 0;
    s->rx_q_count = 0;
    s->rx_xfer_len = 0;
    s->rx_xfer_pos = 0;
    s->rx_xfer_pipe = 0;
    s->recv_armed = 0;
    s->midi_status = 0;
    s->midi_ndata = 0;
    s->midi_need = 0;
    s->in_sysex = false;
    s->sysex_len = 0;
    s->tx_len = 0;

    /* Peripheral-mode USB-audio state. */
    s->peri_step = PERI_IDLE;
    s->peri_kicked = false;
    s->peri_wait = 0;
    s->peri_ctrl_wait = false;
    s->tohost_len = 0;
    if (s->sof_running && s->sof_timer) {
        timer_del(s->sof_timer);
    }
    s->sof_running = false;
    rza1l_usb_wav_close(s);

    /* From-host stream state. */
    if (s->wav_in_cap) {
        USB_DBG("USB-audio: from-host delivered %" PRIu64 " frames",
                s->fromhost_frames);
    }
    rza1l_usb_wav_close_file(&s->wav_in_cap, &s->wav_in_cap_bytes);
    s->fromhost_pending = false;
    s->fromhost_pos = s->fromhost_len = 0;
    s->fromhost_frac = 0;
    s->fromhost_frames = 0;
    s->tone_phase = 0;

    qemu_set_irq(s->irq, 0);
}

static void rza1l_usb_realize(DeviceState *dev, Error **errp)
{
    RzA1lUsbState *s = RZA1L_USB(dev);
    SysBusDevice *sbd = SYS_BUS_DEVICE(dev);

    memory_region_init_io(&s->iomem, OBJECT(dev), &rza1l_usb_ops, s,
                          TYPE_RZA1L_USB, RZA1L_USB_MMIO_SIZE);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq);

    s->event_bh = qemu_bh_new(rza1l_usb_event, s);
    s->sof_timer = timer_new_ns(QEMU_CLOCK_VIRTUAL, rza1l_usb_sof_tick, s);

    /*
     * Resolve the from-host audio source once. "tone" / "tone:<freq>" drives a
     * built-in sine generator (a deterministic, self-contained test source);
     * anything else is taken as a path to an input WAV, looped as it plays.
     * With no source configured the from-host (stream-out) interface is left
     * unstarted and only the to-host stream runs.
     */
    s->audio_in_kind = AUDIO_IN_NONE;
    if (s->audio && s->audio_in && s->audio_in[0]) {
        if (strncmp(s->audio_in, "tone", 4) == 0) {
            const char *colon = strchr(s->audio_in, ':');
            s->tone_freq = 440;
            if (colon) {
                int f = atoi(colon + 1);
                if (f > 0 && f < USB_PAUDIO_SAMPLE_RATE / 2) {
                    s->tone_freq = f;
                }
            }
            s->audio_in_kind = AUDIO_IN_TONE;
            USB_DBG("USB-audio: from-host source = %u Hz test tone",
                    s->tone_freq);
        } else if (rza1l_usb_wav_in_open(s)) {
            s->audio_in_kind = AUDIO_IN_FILE;
        }
    }

    /*
     * MIDI bulk data bridge. The firmware's MIDI engine is the same in both
     * modes; only which pipes it uses and which end is the host differ, so the
     * bridge is parameterised rather than duplicated:
     *   - host mode (midi=on): the model presents a USB-MIDI device and the
     *     firmware (as host) transmits on pipe 1, receives on pipes 2..5.
     *   - peripheral mode (audio=on): the composite device's MIDI interface is
     *     live; the firmware (as device) transmits on pipe 3, receives on
     *     pipe 4. Enabled alongside USB audio so a Deluge-as-peripheral also
     *     carries MIDI, over the same host chardev.
     */
    if (s->midi) {
        s->mbridge = true;
        s->midi_tx_pipe = USB_BULK_SEND_PIPE;
        s->midi_rx_lo = USB_BULK_RECV_MIN;
        s->midi_rx_hi = USB_BULK_RECV_MAX;
    } else if (rza1l_usb_is_peripheral(s)) {
        s->mbridge = true;
        s->midi_tx_pipe = USB_PMIDI_PIPE_TX;
        s->midi_rx_lo = USB_PMIDI_PIPE_RX;
        s->midi_rx_hi = USB_PMIDI_PIPE_RX;
    }

    /*
     * Bridge the bulk MIDI pipes to the host chardev (if one is configured).
     * Incoming raw MIDI bytes are framed and delivered over the bulk IN pipe;
     * the receive handler runs in the main loop, the same context as MMIO.
     */
    USB_DBG("realize: chardev connected=%d",
            qemu_chr_fe_backend_connected(&s->chr));
    qemu_chr_fe_set_handlers(&s->chr, rza1l_usb_chr_can_receive,
                             rza1l_usb_chr_receive, NULL, NULL, s, NULL, true);
}

static const VMStateDescription vmstate_rza1l_usb = {
    .name = TYPE_RZA1L_USB,
    .version_id = 2,
    .minimum_version_id = 2,
    .fields = (const VMStateField[]) {
        VMSTATE_UINT16_ARRAY(regs, RzA1lUsbState, RZA1L_USB_NUM_REGS),
        VMSTATE_BOOL(attached, RzA1lUsbState),
        VMSTATE_UINT16(line_state, RzA1lUsbState),
        VMSTATE_UINT16(dev_address, RzA1lUsbState),
        VMSTATE_BOOL(configured, RzA1lUsbState),
        VMSTATE_END_OF_LIST()
    },
};

static const Property rza1l_usb_properties[] = {
    DEFINE_PROP_BOOL("midi", RzA1lUsbState, midi, false),
    DEFINE_PROP_CHR("chardev", RzA1lUsbState, chr),
    /* Peripheral (USB-MIDI device) is the default role, so any firmware comes up
     * as a USB-MIDI peripheral out of the box; host mode (midi=on) overrides it. */
    DEFINE_PROP_BOOL("peripheral", RzA1lUsbState, peripheral, true),
    DEFINE_PROP_BOOL("audio", RzA1lUsbState, audio, false),
    DEFINE_PROP_STRING("audio-out", RzA1lUsbState, audio_out),
    DEFINE_PROP_STRING("audio-in", RzA1lUsbState, audio_in),
    DEFINE_PROP_STRING("audio-in-capture", RzA1lUsbState, audio_in_capture),
    DEFINE_PROP_BOOL("audio-in-adaptive", RzA1lUsbState, audio_adaptive, false),
};

static void rza1l_usb_class_init(ObjectClass *klass, const void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->realize = rza1l_usb_realize;
    dc->vmsd = &vmstate_rza1l_usb;
    device_class_set_props(dc, rza1l_usb_properties);
    device_class_set_legacy_reset(dc, rza1l_usb_reset);
}

static const TypeInfo rza1l_usb_info = {
    .name = TYPE_RZA1L_USB,
    .parent = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(RzA1lUsbState),
    .class_init = rza1l_usb_class_init,
};

static void rza1l_usb_register_types(void)
{
    type_register_static(&rza1l_usb_info);
}

type_init(rza1l_usb_register_types)
