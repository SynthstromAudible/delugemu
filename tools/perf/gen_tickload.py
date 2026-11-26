#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Generate Deluge "TICKLOAD" profiling songs: many voices start together on every sequencer step.

Purpose: stress the song tick (PlaybackHandler::actionTimerTick -> clips -> NoteRows -> Sound::noteOn) on top of
the audio render, with a steady voice count, so the cost of *starting* notes can be separated from the cost of
*rendering* them; optionally with many effect units running (and allocating) in the render at the same time.

Song shape (all parameters configurable):
  * 1 bar loop at 120 BPM, 16 sixteenth-note steps, no swing, no arp, no automation.
  * On every step N voices start at the same tick (default N=20). Each note lasts one step (gate 1.0 = 24 ticks,
    the Deluge's default note length for a 16th step) and the amp envelope has the minimum release, so the
    previous step's voices are gone within ~1 render window: steady state is ~N voices, the spike is the starts.
  * Synth-only (subtractive saw + square, 24 dB ladder LPF, default-synth patching), so nothing streams from SD.
  * "synth" layout: C instrument clips (one SoundInstrument each) x K-note chords (N = C*K, or N split over C).
  * "kit" layout: one kit with R synth-type drum rows (no samples), one note per row per step (N = R).
  * FX off by default. --fx: reverb + delay sends on every sound (unchanged since the first version).
    --fx-set/--fx-all/--fx-vary: per-sound effect chains; --kit-fx: kit-level FX; --song-fx: master FX.
    Every tag, attribute and value encoding is taken from the firmware's song read/write code (see the Effects
    comment block below for the sources and for what makes each unit run in the render).

Effects (SPEC = comma list of UNIT[=VALUE], 'all' = every unit except route):
  modfx[=flanger|chorus|phaser|stereochorus|warble|dimension|grain]   delay[=16th|8th|8thT|4thD|...|off]
  analog  reverb[=0..50 | song: freeverb|mutable|digital]  bitcrush[=0..50]  srr[=0..50]  clip[=0..15]
  fold[=0..50] (sounds)  eq[=-50..50]  lpf[=12dB|24dB|24dBDrive|SVF_Band|SVF_Notch]  hpf[=SVF_Band|SVF_Notch|
  HPLadder]  route[=H2L|L2H|PARA]  comp[=0..50]  sidechain[=0..50] (first sound sends, the others duck)

Usage:
  gen_tickload.py                      # standard set (existing identical files are left untouched)
  gen_tickload.py --set --outdir DIR   # standard set into DIR
  gen_tickload.py --only FXALL,GRAIN   # just these standard variants
  gen_tickload.py --stage KIT20 DIR    # card content DIR/SONGS holding only that variant
  gen_tickload.py -o FOO.XML --clips 4 --chord 5 --bpm 140 --fx
  gen_tickload.py -o K.XML --kit 24
  gen_tickload.py -o A.XML --fx-set modfx=phaser,delay=8thT,analog,reverb=30 --song-fx comp,reverb=digital
  gen_tickload.py -o B.XML --fx-all --fx-vary --clips 7 --voices 20 --song-fx all
  gen_tickload.py -o C.XML --kit 20 --fx-set modfx=grain --kit-fx delay,comp,sidechain
  gen_tickload.py --check FILE.XML ...  # static validation, per-step voice starts and active FX of existing files

Python 3 standard library only.
"""


import argparse
import os
import sys
import xml.etree.ElementTree as ET

# Standard-set output directory: $TICKLOAD_OUTDIR, else ./SONGS.
DEFAULT_OUTDIR = os.environ.get("TICKLOAD_OUTDIR") or "SONGS"

# --- timing (model/song/song.cpp) -------------------------------------------------------------------------------
# inputTickMagnitude = insideWorldTickMagnitude; FlashStorage::defaultMagnitude = 2 (storage/flash_storage.cpp).
# Song::getBarLength() = increaseMagnitude(96, mag) = 384 ticks, getSixteenthNoteLength() = 6 << 2 = 24 ticks.
INPUT_TICK_MAGNITUDE = 2
TICKS_PER_BAR = 96 << INPUT_TICK_MAGNITUDE  # 384
TICKS_PER_16TH = 6 << INPUT_TICK_MAGNITUDE  # 24

# --- note encoding (model/note/note_row.cpp NoteRow::writeToFile / readFromFile) ----------------------------------
# "noteDataWithSplitProb" = "0x" + per note 28 hex chars:
#   pos(8) length(8) velocity(2) lift(2) probability(2) iterance(4) fill(2)
# probability 20 = kNumProbabilityValues (100%), lift 64 = kDefaultLiftValue, iterance 0 = kDefaultIteranceValue
# (off), fill 0 = FillMode::OFF (definitions_cxx.hpp). Accepted regardless of the song's firmwareVersion.
NOTE_HEX_LEN = 28
LIFT_DEFAULT = 64
PROB_100 = 20


def hex32(v):
    return "0x%08X" % (v & 0xFFFFFFFF)


def user_to_param(v):
    """UI 0..50 -> param value; util/functions.cpp getParamFromUserValue default branch."""
    return (v * 85899345 - 2147483648) & 0xFFFFFFFF


def cable_amount(v):
    """Patch cable UI -50..50 -> amount; getParamFromUserValue(PATCH_CABLE)."""
    return v * 21474836


def eq_to_param(v):
    """EQ bass/treble UI -50..50 -> param; getParamFromUserValue(UNPATCHED_START + UNPATCHED_BASS/TREBLE)."""
    if v == -50:
        return 0x80000000
    return (v * 42949672) & 0xFFFFFFFF


# ------------------------------------------------------------------------------------------------------------------
# Effects. Every name and encoding below comes from the firmware's serialization code:
#   modFXType strings     util/functions.cpp fxTypeToString/stringToFXType (enum ModFXType, definitions_cxx.hpp)
#   lpfMode/hpfMode/route model/mod_controllable/filters/filter_config.cpp filterMap/routeMap
#   sound attrs/tags      ModControllableAudio::writeAttributesToFile (modFXType, lpfMode, hpfMode, filterRoute,
#                         clippingAmount) / writeTagsToFile (delay, sidechain, audioCompressor, stutter),
#                         Sound::writeToFile (sideChainSend), Sound::writeParamsToFile (patched + unpatched params)
#   song/kit params       GlobalEffectable::writeParamAttributesToFile / writeParamTagsToFile
#   song reverb           Song::writeToFile <reverb model=...> (dsp/reverb/reverb.hpp Model: 0 freeverb,
#                         1 mutable, 2 digital)
#   delay sync            Song::convertSyncLevelFromInternalValueToFileValue: file = internal - 1 + magnitude;
#                         internal level L lasts 3 << (9 - L) ticks (Delay / LFO sync code); syncType raw enum
#                         (model/sync.h: 0 even, 10 triplet, 19 dotted)
# What makes each unit actually run in the render (so it costs CPU / allocates):
#   Sound modFX: Sound::setModFXType allocates the modfx buffer (flanger/chorus/stereo chorus/warble/dimension)
#     or a GranularProcessor + 512 KiB stealable grain buffer (grainFX) at load; processed every render.
#   Song/kit modFX: GlobalEffectable::processFXForGlobalEffectable allocates at render time, and only if the
#     param named by modFXCurrentParam is above minimum (getActiveModFXType) -> we write modFXCurrentParam="depth".
#   Delay: buffer allocated at render when the feedback/amount param is above minimum; analog=1 adds the IR model.
#   Reverb: one global reverb, fed by every send above minimum (sound reverbAmount, song/kit reverbAmount).
#   Bitcrush / SRR: processSRRAndBitcrushing when the param is above minimum. Clipping: clippingAmount > 0
#     (UI 0..15). Wavefolder: waveFold above minimum (per voice).
#   EQ: bass/treble != 0 (hasBassAdjusted / hasTrebleAdjusted). HPF: hpfFrequency above minimum.
#   Compressor: Sound / GlobalEffectableForClip run it when compressorThreshold > 0; the song master compressor
#     always runs, its threshold comes from <audioCompressor thresh> (knob position, 0 = no compression).
#   Sidechain: a sound with sideChainSend registers a hit on every note-on (AudioEngine::registerSideChainHit);
#     sounds with a patch cable from "compressor" (PatchSource::SIDECHAIN) render the sidechain envelope; a kit
#     ducks through sidechainCompressorVolume.
#   Stutter is configured (<stutter quantized reverse pingPong>) but only runs while the stutter knob is held,
#     so a song file cannot switch it on.
# ------------------------------------------------------------------------------------------------------------------

MODFX_TYPES = ["flanger", "chorus", "phaser", "StereoChorus", "TapeWarble", "dimension", "grainFX"]  # enum order
MODFX_ALIASES = {
    "flanger": "flanger", "chorus": "chorus", "phaser": "phaser", "stereochorus": "StereoChorus",
    "stereo": "StereoChorus", "warble": "TapeWarble", "tapewarble": "TapeWarble", "dimension": "dimension",
    "grain": "grainFX", "grainfx": "grainFX",
}
LPF_MODES = ["12dB", "24dB", "24dBDrive", "SVF_Band", "SVF_Notch"]  # FilterMode up to lastLpfMode
HPF_MODES = ["SVF_Band", "SVF_Notch", "HPLadder"]                 # FilterMode from firstHPFMode
FILTER_ROUTES = ["H2L", "L2H", "PARA"]
REVERB_MODELS = {"freeverb": 0, "mutable": 1, "digital": 2}
SYNC_TYPES = {"": 0, "t": 10, "d": 19}
NOTE_TICKS = {"1bar": 384, "2nd": 192, "4th": 96, "8th": 48, "16th": 24, "32nd": 12, "64th": 6}

FX_UNITS_SOUND = ["modfx", "delay", "analog", "reverb", "bitcrush", "srr", "clip", "fold", "eq", "lpf", "hpf",
                  "route", "comp", "sidechain"]
FX_UNITS_KIT = ["modfx", "delay", "analog", "reverb", "bitcrush", "srr", "clip", "eq", "lpf", "hpf", "route",
                "comp", "sidechain"]
FX_UNITS_SONG = ["modfx", "delay", "analog", "reverb", "bitcrush", "srr", "eq", "lpf", "hpf", "route", "comp"]
FX_ALL_EXCLUDES = ("route",)  # "all" = every unit that costs something
DISTORTION_UNITS = ["bitcrush", "srr", "clip", "fold"]

# Default values per unit (amounts are UI 0..50 like the Deluge menus unless noted).
FX_DEFAULTS = {
    "modfx": "chorus", "delay": "16th", "analog": None, "reverb": 20, "bitcrush": 30, "srr": 20,
    "clip": 5,          # clippingAmount, UI 0..15 (gui/menu_item/fx/clipping.h)
    "fold": 20, "eq": 15,  # eq: bass and treble boost, UI -50..50
    "lpf": "24dBDrive", "hpf": "HPLadder", "route": "PARA",
    "comp": 35,         # compressorThreshold UI value; > 25 makes the param > 0, which switches the compressor on
    "sidechain": 30,    # ducking depth (patch cable / kit sidechainCompressorVolume)
}
SONG_REVERB_DEFAULT = "mutable"


def sync_file_value(name):
    """'16th', '8thT' (triplet), '4thD' (dotted), 'off' -> (syncLevel file value, syncType)."""
    name = str(name)
    if name.lower() in ("off", "0", "free"):
        return 0, 0
    base, suffix = name, ""
    if name[-1] in "tTdD" and name[:-1].lower() in NOTE_TICKS:
        base, suffix = name[:-1], name[-1].lower()
    base = base.lower()
    if base not in NOTE_TICKS:
        raise SystemExit("bad delay sync %r; use off, %s (+T triplet / D dotted)" % (name, ", ".join(NOTE_TICKS)))
    ticks = NOTE_TICKS[base] << (INPUT_TICK_MAGNITUDE - 2)
    level = 9 - (ticks // 3).bit_length() + 1  # 3 << (9 - L) == ticks
    assert 3 << (9 - level) == ticks
    return level - 1 + INPUT_TICK_MAGNITUDE, SYNC_TYPES[suffix]


def parse_fx_spec(spec, allowed, what):
    """'modfx=phaser,delay=8th,reverb,bitcrush=40' -> ordered dict unit -> value (None = default)."""
    out = {}
    if not spec:
        return out
    for item in spec.split(","):
        item = item.strip()
        if not item:
            continue
        unit, _, val = item.partition("=")
        unit = unit.strip().lower()
        val = val.strip() or None
        if unit == "all":
            for u in allowed:
                if u not in FX_ALL_EXCLUDES and u not in out:
                    out[u] = None
            continue
        if unit not in allowed:
            raise SystemExit("unknown %s FX unit %r; known: %s, all" % (what, unit, ", ".join(allowed)))
        out[unit] = val
    return out


def _amount(units, unit):
    v = units[unit] if units[unit] is not None else FX_DEFAULTS[unit]
    try:
        return int(v)
    except ValueError:
        raise SystemExit("FX unit %s wants a number, got %r" % (unit, v))


def _choice(units, unit, table, what):
    v = units[unit] if units[unit] is not None else FX_DEFAULTS[unit]
    if isinstance(table, dict):
        key = str(v).lower()
        if key not in table:
            raise SystemExit("bad %s %r; one of: %s" % (what, v, ", ".join(sorted(set(table)))))
        return table[key]
    for t in table:
        if t.lower() == str(v).lower():
            return t
    raise SystemExit("bad %s %r; one of: %s" % (what, v, ", ".join(table)))


class SoundFx:
    """Effect settings of one Sound (synth instrument or kit row). Defaults reproduce the plain TICKLOAD songs."""

    def __init__(self):
        self.modfx_type = "none"
        self.modfx_rate = 0x00000000
        self.modfx_depth = 0x00000000
        self.modfx_offset = 0x00000000
        self.modfx_feedback = 0x00000000
        self.delay_feedback = 0x80000000
        self.delay_rate = 0x00000000
        self.delay_sync = 7
        self.delay_sync_type = 0
        self.ping_pong = 1
        self.analog = 0
        self.reverb = 0x80000000
        self.srr = 0x80000000
        self.bitcrush = 0x80000000
        self.clipping = 0
        self.fold = 0x80000000
        self.bass = self.treble = self.bass_freq = self.treble_freq = 0
        self.lpf_mode = "24dB"
        self.hpf_mode = "HPLadder"
        self.hpf_freq = 0x80000000
        self.route = "H2L"
        self.comp_threshold = 0x00000000
        self.comp_ratio = 1073741824
        self.sidechain_send = 0
        self.duck = None


class GlobalFx:
    """Effect settings of a GlobalEffectable: the song (master) or a kit (affect-entire / clip level)."""

    def __init__(self):
        self.modfx_param = "feedback"
        self.modfx_type = "none"
        self.modfx_depth = 0x00000000
        self.modfx_rate = 0xE0000000
        self.modfx_offset = 0x00000000
        self.modfx_feedback = 0x80000000
        self.delay_amount = 0x80000000
        self.delay_rate = 0x00000000
        self.delay_sync = 7
        self.delay_sync_type = 0
        self.ping_pong = 1
        self.analog = 0
        self.reverb = 0x80000000
        self.srr = 0x80000000
        self.bitcrush = 0x80000000
        self.clipping = 0
        self.bass = self.treble = self.bass_freq = self.treble_freq = 0
        self.lpf_freq = 0x7FFFFFFF
        self.hpf_freq = 0x80000000
        self.lpf_mode = "24dB"
        self.hpf_mode = "HPLadder"
        self.route = "H2L"
        self.comp_threshold_param = 0x00000000  # kit: compressorThreshold param (> 0 = on)
        self.comp_thresh_attr = 0               # song: <audioCompressor thresh> knob position
        self.comp_ratio = 1073741824
        self.sidechain_volume = None            # kit: sidechainCompressorVolume
        self.reverb_model = 1


def apply_common(fx, units, index, vary, is_global):
    """Shared unit handling for SoundFx and GlobalFx. index/vary pick per-sound variations (--fx-vary)."""
    if "modfx" in units:
        if vary:
            fx.modfx_type = MODFX_TYPES[index % len(MODFX_TYPES)]
        else:
            fx.modfx_type = _choice(units, "modfx", MODFX_ALIASES, "modFX type")
        fx.modfx_rate = user_to_param(20)
        fx.modfx_depth = user_to_param(30)
        fx.modfx_feedback = user_to_param(20)
        fx.modfx_offset = user_to_param(25)
        if is_global:
            fx.modfx_param = "depth"  # GlobalEffectable::getActiveModFXType gates on this param being > min
    if "delay" in units:
        fx.ping_pong = 1
        fx.delay_sync, fx.delay_sync_type = sync_file_value(units["delay"] or FX_DEFAULTS["delay"])
        amount = user_to_param(20)
        if is_global:
            fx.delay_amount = amount
        else:
            fx.delay_feedback = amount
    if "analog" in units:
        fx.analog = 1
    if "eq" in units:
        a = _amount(units, "eq")
        fx.bass = eq_to_param(a)
        fx.treble = eq_to_param(a)
        fx.bass_freq = user_to_param(20)
        fx.treble_freq = user_to_param(30)
    if "route" in units:
        fx.route = _choice(units, "route", FILTER_ROUTES, "filter route")

    dist = [u for u in DISTORTION_UNITS if u in units]
    if vary and dist:
        dist = [dist[index % len(dist)]]
    for u in dist:
        if u == "bitcrush":
            fx.bitcrush = user_to_param(_amount(units, u))
        elif u == "srr":
            fx.srr = user_to_param(_amount(units, u))
        elif u == "clip":
            fx.clipping = max(0, min(15, _amount(units, u)))
        elif u == "fold":
            fx.fold = user_to_param(_amount(units, u))

    if "lpf" in units:
        fx.lpf_mode = LPF_MODES[index % len(LPF_MODES)] if vary else _choice(units, "lpf", LPF_MODES, "LPF mode")
    if "hpf" in units:
        fx.hpf_mode = HPF_MODES[index % len(HPF_MODES)] if vary else _choice(units, "hpf", HPF_MODES, "HPF mode")
        fx.hpf_freq = user_to_param(10)


def sound_fx_for(cfg, index):
    """SoundFx for sound #index (synth clip index or kit row)."""
    fx = SoundFx()
    if cfg.fx:  # original --fx: reverb + delay sends, nothing else
        fx.reverb = user_to_param(cfg.fx_reverb)
        fx.delay_feedback = user_to_param(cfg.fx_delay)
    units = cfg.fx_units
    apply_common(fx, units, index, cfg.fx_vary, is_global=False)
    if "reverb" in units:
        fx.reverb = user_to_param(_amount(units, "reverb"))
    if "comp" in units:
        fx.comp_threshold = user_to_param(_amount(units, "comp"))
        fx.comp_ratio = 0x60000000
    if "sidechain" in units:
        if index == 0:
            fx.sidechain_send = 2147483647  # full send, as SampleBrowser gives a kick drum
        else:
            fx.duck = cable_amount(_amount(units, "sidechain"))
    return fx


def global_fx_for(units, is_song):
    fx = GlobalFx()
    apply_common(fx, units, 0, False, is_global=True)
    if "reverb" in units:
        v = units["reverb"]
        if is_song:
            fx.reverb_model = REVERB_MODELS[_choice({"reverb": v or SONG_REVERB_DEFAULT}, "reverb",
                                                    {k: k for k in REVERB_MODELS}, "reverb model")]
            fx.reverb = user_to_param(15)
        else:
            fx.reverb = user_to_param(int(v) if v else FX_DEFAULTS["reverb"])
    if "lpf" in units:
        fx.lpf_freq = user_to_param(35)
    if "comp" in units:
        if is_song:
            fx.comp_thresh_attr = user_to_param(_amount(units, "comp"))
        else:
            fx.comp_threshold_param = user_to_param(_amount(units, "comp"))
        fx.comp_ratio = 0x60000000
    if "clip" in units and is_song:
        raise SystemExit("song-level clipping is not rendered by the firmware (renderSongFX); drop 'clip'")
    if "sidechain" in units:
        fx.sidechain_volume = user_to_param(_amount(units, "sidechain"))
    return fx


def note_hex(pos, length, vel):
    s = "%08X%08X%02X%02X%02X%04X%02X" % (pos, length, vel, LIFT_DEFAULT, PROB_100, 0, 0)
    assert len(s) == NOTE_HEX_LEN
    return s


def time_per_timer_tick(bpm):
    """Song::setBPMInner: samples per internal tick = 110250 / (bpm * 2^mag), stored as 32.32 fixed point split
    into timePerTimerTick (int part) and timerTickFraction (low 32 bits, written as a signed int32)."""
    t = 110250.0 / (bpm * (1 << INPUT_TICK_MAGNITUDE))
    big = int(round(t * 4294967296.0))
    ipart = big >> 32
    frac = big & 0xFFFFFFFF
    if frac >= 0x80000000:
        frac -= 0x100000000
    return ipart, frac


# ------------------------------------------------------------------------------------------------------------------
# XML fragments. Structure, tag names and attribute sets follow what the firmware writes (Song::writeToFile,
# SoundInstrument/Sound::writeToFile, Kit::writeDataToFile, InstrumentClip::writeDataToFile, NoteRow::writeToFile),
# cross-checked against contrib/audio_export/multi_sample/Multisample_Template_Full_Bar.XML (a real c1.3.0 song
# with a kit of 128 synth-type drums).
# ------------------------------------------------------------------------------------------------------------------

ARP_ATTRS = """mode="off"
{i}	syncLevel="7"
{i}	numOctaves="2"
{i}	syncType="0"
{i}	arpMode="off"
{i}	noteMode="up"
{i}	octaveMode="up\""""

def fx_tags(i, fx=None):
    """ModControllableAudio::writeTagsToFile: <delay>, <sidechain>, <audioCompressor>, <stutter>."""
    fx = fx or SoundFx()
    thresh = getattr(fx, "comp_thresh_attr", None)
    if thresh is None:
        thresh = fx.comp_threshold if fx.comp_threshold & 0x80000000 == 0 else 0
    thresh = thresh - (1 << 32) if thresh & 0x80000000 else thresh
    return (
        '{i}<delay\n'
        '{i}\tpingPong="{pp}"\n'
        '{i}\tanalog="{an}"\n'
        '{i}\tsyncLevel="{sl}"\n'
        '{i}\tsyncType="{st}" />\n'
        '{i}<sidechain\n'
        '{i}\tattack="327244"\n'
        '{i}\trelease="936"\n'
        '{i}\tsyncLevel="6"\n'
        '{i}\tsyncType="0" />\n'
        '{i}<audioCompressor\n'
        '{i}\tattack="83886080"\n'
        '{i}\trelease="83886080"\n'
        '{i}\tthresh="{th}"\n'
        '{i}\tratio="{ra}"\n'
        '{i}\tcompHPF="0"\n'
        '{i}\tcompBlend="2147483647" />\n'
        '{i}<stutter\n'
        '{i}\tquantized="1"\n'
        '{i}\treverse="0"\n'
        '{i}\tpingPong="0" />\n'
    ).format(i=i, pp=fx.ping_pong, an=fx.analog, sl=fx.delay_sync, st=fx.delay_sync_type, th=thresh,
             ra=fx.comp_ratio)


MOD_KNOBS = [
    ('pan', None, None), ('volumePostFX', None, None), ('lpfResonance', None, None), ('lpfFrequency', None, None),
    ('env1Release', None, None), ('env1Attack', None, None), ('delayFeedback', None, None), ('delayRate', None, None),
    ('reverbAmount', None, None), ('volumePostReverbSend', 'compressor', None), ('pitch', 'lfo1', None),
    ('lfo1Rate', None, None), ('portamento', None, None), ('stutterRate', None, None), ('bitcrushAmount', None, None),
    ('volume', 'velocity', 'envelope1'),
]

def eq_tag(i, fx=None):
    """ModControllableAudio::writeParamTagsToFile: <equalizer bass treble bassFrequency trebleFrequency>."""
    fx = fx or SoundFx()
    return ('{i}<equalizer\n{i}\tbass="%s"\n{i}\ttreble="%s"\n{i}\tbassFrequency="%s"\n'
            '{i}\ttrebleFrequency="%s" />\n' % (hex32(fx.bass), hex32(fx.treble), hex32(fx.bass_freq),
                                                 hex32(fx.treble_freq))).format(i=i)


def ind(n):
    return "\t" * n


def mod_knobs_xml(i):
    out = [i + "<modKnobs>\n"]
    for param, src, src2 in MOD_KNOBS:
        a = 'controlsParam="%s"' % param
        if src:
            a += ' patchAmountFromSource="%s"' % src
        if src2:
            a += ' patchAmountFromSecondSource="%s"' % src2
        out.append(i + "\t<modKnob %s />\n" % a)
    out.append(i + "</modKnobs>\n")
    return "".join(out)


def sound_body_xml(i, cfg, transpose=0, fx=None):
    """Attributes after the identity ones + child tags of a <sound> (Sound::writeToFile), for a SoundInstrument at
    song level or a SoundDrum inside a kit. No <defaultParams>: in a song the params live in the clip's
    <soundParams> (synth) or the NoteRow's <soundParams> (kit drum)."""
    fx = fx or SoundFx()
    s = ""
    s += i + '\tpolyphonic="poly"\n'
    s += i + '\tvoicePriority="1"\n'
    if fx.sidechain_send:
        s += i + '\tsideChainSend="%d"\n' % fx.sidechain_send
    s += i + '\tmode="subtractive"\n'
    if transpose:
        s += i + '\ttranspose="%d"\n' % transpose
    s += i + '\tmodFXType="%s"\n' % fx.modfx_type
    s += i + '\tlpfMode="%s"\n' % fx.lpf_mode
    s += i + '\thpfMode="%s"\n' % fx.hpf_mode
    s += i + '\tfilterRoute="%s"\n' % fx.route
    if fx.clipping:
        s += i + '\tclippingAmount="%d"\n' % fx.clipping
    s += i + '\tmaxVoices="%d">\n' % cfg.max_voices
    s += i + '\t<osc1\n'
    s += i + '\t\ttype="%s"\n' % cfg.osc1
    s += i + '\t\ttranspose="0"\n'
    s += i + '\t\tcents="0"\n'
    s += i + '\t\tretrigPhase="-1" />\n'
    s += i + '\t<osc2\n'
    s += i + '\t\ttype="%s"\n' % cfg.osc2
    s += i + '\t\ttranspose="-12"\n'
    s += i + '\t\tcents="0"\n'
    s += i + '\t\tretrigPhase="-1" />\n'
    for n in range(1, 5):
        s += i + '\t<lfo%d type="triangle" syncLevel="0" syncType="0" />\n' % n
    s += i + '\t<unison num="%d" detune="%d" spread="0" />\n' % (cfg.unison, 10 if cfg.unison > 1 else 8)
    s += mod_knobs_xml(i + "\t")
    s += fx_tags(i + "\t", fx)
    return s


def sound_params_xml(i, tag, cfg, fx=None):
    """<soundParams> (Sound::writeParamsToFile). Values: Sound::setupAsDefaultSynth() (osc B level, LPF, envelopes,
    patch cables) except env1 release (cfg.release, default 0 = shortest) and volume; the rest are the neutral
    values the firmware writes (as in the template song's drum soundParams)."""
    fx = fx or SoundFx()
    h = hex32
    osc_b = "0x80000000" if getattr(cfg, "osc2_muted", False) else "0x47AE1457"
    attrs = [
        ("portamento", "0x80000000"), ("compressorShape", "0xDC28F5B2"),
        ("oscAVolume", "0x7FFFFFFF"), ("oscAPulseWidth", "0x00000000"), ("oscAWavetablePosition", "0x00000000"),
        ("oscBVolume", osc_b), ("oscBPulseWidth", "0x00000000"), ("oscBWavetablePosition", "0x00000000"),
        ("noiseVolume", "0x80000000"), ("volume", hex32(cfg.volume)), ("pan", "0x00000000"),
        ("lpfFrequency", "0x10000000"), ("lpfResonance", "0xA2000000"),
        ("hpfFrequency", h(fx.hpf_freq)), ("hpfResonance", "0x80000000"),
        ("lfo1Rate", "0x1999997E"), ("lfo2Rate", "0x00000000"), ("lfo3Rate", "0x1999997E"), ("lfo4Rate", "0x00000000"),
        ("modulator1Amount", "0x80000000"), ("modulator1Feedback", "0x80000000"),
        ("modulator2Amount", "0x80000000"), ("modulator2Feedback", "0x80000000"),
        ("carrier1Feedback", "0x80000000"), ("carrier2Feedback", "0x80000000"),
        ("modFXRate", h(fx.modfx_rate)), ("modFXDepth", h(fx.modfx_depth)),
        ("delayRate", h(fx.delay_rate)), ("delayFeedback", h(fx.delay_feedback)), ("reverbAmount", h(fx.reverb)),
        ("arpeggiatorRate", "0x00000000"), ("stutterRate", "0x00000000"),
        ("sampleRateReduction", h(fx.srr)), ("bitCrush", h(fx.bitcrush)),
        ("modFXOffset", h(fx.modfx_offset)), ("modFXFeedback", h(fx.modfx_feedback)),
        ("compressorThreshold", h(fx.comp_threshold)),
        ("arpeggiatorGate", "0x00000000"), ("noteProbability", "0x7FFFFFFF"),
        ("lpfMorph", "0x80000000"), ("hpfMorph", "0x80000000"), ("waveFold", h(fx.fold)),
    ]
    s = i + "<%s\n" % tag
    s += "".join(i + '\t%s="%s"\n' % kv for kv in attrs[:-1])
    s += i + '\t%s="%s">\n' % attrs[-1]
    j = i + "\t"
    envs = [
        ("0x80000000", "0xE6666654", "0x7FFFFFFF", hex32(user_to_param(cfg.release))),
        ("0xA3D70A37", "0xA3D70A37", "0xFFFFFFE9", "0xE6666654"),
        ("0x00000000", "0x00000000", "0x00000000", "0x00000000"),
        ("0x00000000", "0x00000000", "0x00000000", "0x00000000"),
    ]
    for n, (a, d, su, r) in enumerate(envs, 1):
        s += j + "<envelope%d\n" % n
        s += j + '\tattack="%s"\n' % a
        s += j + '\tdecay="%s"\n' % d
        s += j + '\tsustain="%s"\n' % su
        s += j + '\trelease="%s" />\n' % r
    cables = [  # Sound::setupAsDefaultSynth + setupDefaultExpressionPatching
        ("note", "lpfFrequency", "bipolar", 0x08F5C28C),
        ("envelope1", "lpfFrequency", "bipolar", 0x1C28F5B8),
        ("velocity", "lpfFrequency", "bipolar", 0x0F5C28F0),
        ("velocity", "volume", "bipolar", 0x3FFFFFE8),
        ("aftertouch", "volume", "unipolar", cable_amount(33)),
        ("y", "lpfFrequency", "bipolar", cable_amount(20)),
    ]
    if fx.duck is not None:  # "volume ducking" (gui/ui/menus.cpp): SIDECHAIN -> GLOBAL_VOLUME_POST_REVERB_SEND
        cables.append(("compressor", "volumePostReverbSend", "bipolar", fx.duck))
    s += j + "<patchCables>\n"
    for src, dst, pol, amt in cables:
        s += j + "\t<patchCable\n"
        s += j + '\t\tsource="%s"\n' % src
        s += j + '\t\tdestination="%s"\n' % dst
        s += j + '\t\tpolarity="%s"\n' % pol
        s += j + '\t\tamount="%s" />\n' % hex32(amt)
    s += j + "</patchCables>\n"
    s += eq_tag(j, fx)
    s += i + "</%s>\n" % tag
    return s


def global_params_attrs(i, volume_hex, reverb_hex=None, tempo_hex="0x00000000", fx=None):
    """GlobalEffectable::writeParamAttributesToFile + writeParamTagsToFile (songParams / kitParams)."""
    fx = fx or GlobalFx()
    h = hex32
    attrs = [
        ("reverbAmount", reverb_hex or h(fx.reverb)), ("volume", volume_hex), ("pan", "0x00000000"),
    ]
    if fx.sidechain_volume is not None:
        attrs.append(("sidechainCompressorVolume", h(fx.sidechain_volume)))
    attrs += [
        ("sidechainCompressorShape", "0xDC28F5B2"), ("modFXDepth", h(fx.modfx_depth)), ("modFXRate", h(fx.modfx_rate)),
        ("stutterRate", "0x00000000"), ("sampleRateReduction", h(fx.srr)), ("bitCrush", h(fx.bitcrush)),
        ("modFXOffset", h(fx.modfx_offset)), ("modFXFeedback", h(fx.modfx_feedback)),
        ("compressorThreshold", h(fx.comp_threshold_param)),
        ("arpeggiatorGate", "0x7FFFFFFF"), ("noteProbability", "0x7FFFFFFF"),
        ("lpfMorph", "0x80000000"), ("hpfMorph", "0x80000000"),
        ("tempo", tempo_hex), ("arpeggiatorRate", "0x00000000"),
    ]
    s = "".join(i + '\t%s="%s"\n' % kv for kv in attrs[:-1])
    s += i + '\t%s="%s">\n' % attrs[-1]
    j = i + "\t"
    s += j + '<delay\n' + j + '\trate="%s"\n' % h(fx.delay_rate) + j + '\tfeedback="%s" />\n' % h(fx.delay_amount)
    s += j + '<lpf\n' + j + '\tfrequency="%s"\n' % h(fx.lpf_freq) + j + '\tresonance="0x80000000" />\n'
    s += j + '<hpf\n' + j + '\tfrequency="%s"\n' % h(fx.hpf_freq) + j + '\tresonance="0x80000000" />\n'
    s += eq_tag(j, fx)
    return s


def global_effectable_attrs(i, fx=None):
    """GlobalEffectable::writeAttributesToFile (+ ModControllableAudio attrs); no trailing newline."""
    fx = fx or GlobalFx()
    s = ('{i}\tmodFXCurrentParam="%s"\n{i}\tcurrentFilterType="lpf"\n{i}\tmodFXType="%s"\n'
         '{i}\tlpfMode="%s"\n{i}\thpfMode="%s"\n{i}\tfilterRoute="%s"'
         % (fx.modfx_param, fx.modfx_type, fx.lpf_mode, fx.hpf_mode, fx.route)).format(i=i)
    if fx.clipping:
        s += '\n{i}\tclippingAmount="%d"'.format(i=i) % fx.clipping
    return s


def chord_notes(base, k):
    """k ascending MIDI notes from base, stacked major/minor thirds (fall back to semitones near the top)."""
    notes, n, steps = [], base, (4, 3)
    for j in range(k):
        notes.append(n)
        n += steps[j % 2]
    if notes[-1] > 120:
        notes = list(range(base, base + k))
    assert notes[-1] <= 127, "too many notes per chord"
    return notes


def step_positions(cfg):
    """Tick positions of the steps that start notes."""
    total = cfg.bars * TICKS_PER_BAR
    return [p for p in range(0, total, cfg.step_ticks)]


def note_row_data(cfg):
    length = max(1, int(round(cfg.step_ticks * cfg.gate)))
    return "0x" + "".join(note_hex(p, length, cfg.velocity) for p in step_positions(cfg))


# ------------------------------------------------------------------------------------------------------------------

def build_song(cfg):
    song_fx = global_fx_for(cfg.song_fx_units, is_song=True)
    kit_fx = global_fx_for(cfg.kit_fx_units, is_song=False)
    ipart, frac = time_per_timer_tick(cfg.bpm)
    clip_len = cfg.bars * TICKS_PER_BAR
    o = []
    w = o.append
    w('<?xml version="1.0" encoding="UTF-8"?>\n')
    w("<song\n")
    w('\tfirmwareVersion="c1.3.0"\n')
    w('\tearliestCompatibleFirmware="4.1.0-alpha"\n')
    w('\tarrangementAutoScrollOn="0"\n')
    w('\txScroll="0"\n')
    w('\txZoom="%d"\n' % (clip_len // 16))
    nclips = len(cfg.chords) if cfg.layout == "synth" else 1
    w('\tyScrollSongView="%d"\n' % max(-7, nclips - 8))  # clips fill the top rows of song view
    w('\tyScrollArrangementView="-6"\n')
    w('\txScrollArrangementView="0"\n')
    w('\txZoomArrangementView="192"\n')
    w('\ttimePerTimerTick="%d"\n' % ipart)
    w('\ttimerTickFraction="%d"\n' % frac)
    w('\trootNote="0"\n')
    w('\tinputTickMagnitude="%d"\n' % INPUT_TICK_MAGNITUDE)
    w('\tswingAmount="0"\n')
    w('\tswingInterval="7"\n')  # file value for 16ths at magnitude 2 (Song::convertSyncLevelFromFileValue...)
    w('\taffectEntire="0"\n')
    w('\tactiveModFunction="0"\n')
    w(global_effectable_attrs("", song_fx) + "\n")
    w('\tsongGridScrollX="0"\n')
    w('\tsongGridScrollY="0"\n')
    w('\tsessionLayout="0">\n')
    w("\t<modeNotes>\n")
    for n in (0, 2, 4, 5, 7, 9, 11):
        w("\t\t<modeNote>%d</modeNote>\n" % n)
    w("\t</modeNotes>\n")
    w('\t<reverb\n\t\troomSize="1288489856"\n\t\tdampening="1546188288"\n\t\twidth="2147483647"\n'
      '\t\thpf="0"\n\t\tlpf="2147483647"\n\t\tpan="0"\n\t\tmodel="%d">\n' % song_fx.reverb_model)
    w('\t\t<compressor\n\t\t\tattack="0"\n\t\t\trelease="0"\n\t\t\tvolume="-21474836"\n'
      '\t\t\tshape="-601295438"\n\t\t\tsyncLevel="2" />\n')
    w("\t</reverb>\n")
    w(fx_tags("\t", song_fx))
    w("\t<songParams\n")
    w(global_params_attrs("\t", "0x00000000", tempo_hex=hex32(int(round(cfg.bpm * 100))), fx=song_fx))
    w("\t</songParams>\n")

    # ---- instruments ----
    w("\t<instruments>\n")
    if cfg.layout == "synth":
        for c, k in enumerate(cfg.chords):
            w("\t\t<sound\n")
            w('\t\t\tpresetName="%s"\n' % synth_name(c))
            w('\t\t\tpresetFolder="SYNTHS"\n')
            w('\t\t\tdefaultVelocity="100"\n')
            w('\t\t\tisArmedForRecording="0"\n')
            w('\t\t\tactiveModFunction="0"\n')
            w(sound_body_xml("\t\t", cfg, fx=sound_fx_for(cfg, c)))
            w("\t\t</sound>\n")
    else:
        w("\t\t<kit\n")
        w('\t\t\tpresetName="%s"\n' % KIT_NAME)
        w('\t\t\tpresetFolder="KITS"\n')
        w('\t\t\tdefaultVelocity="100"\n')
        w('\t\t\tisArmedForRecording="0"\n')
        w('\t\t\tactiveModFunction="0"\n')
        w(global_effectable_attrs("\t\t", kit_fx) + ">\n")
        w(fx_tags("\t\t\t", kit_fx))
        w("\t\t\t<soundSources>\n")
        for r in range(cfg.kit_rows):
            w("\t\t\t\t<sound\n")
            w('\t\t\t\t\tname="%s"\n' % drum_name(r))
            # spread drum pitches (drums play at note 60 + transpose) for an audible, non-unison texture
            w(sound_body_xml("\t\t\t\t", cfg, transpose=kit_transpose(r), fx=sound_fx_for(cfg, r)))
            w("\t\t\t\t</sound>\n")
        w("\t\t\t</soundSources>\n")
        w("\t\t\t<selectedDrumIndex>0</selectedDrumIndex>\n")
        w("\t\t</kit>\n")
    w("\t</instruments>\n")

    w("\t<sections>\n")
    for s in range(24):
        w('\t\t<section id="%d" numRepeats="0" />\n' % s)
    w("\t</sections>\n")

    # ---- clips ----
    data = note_row_data(cfg)
    w("\t<sessionClips>\n")
    clips = list(enumerate(cfg.chords)) if cfg.layout == "synth" else [(0, cfg.kit_rows)]
    for c, k in clips:
        is_kit = cfg.layout == "kit"
        w("\t\t<instrumentClip\n")
        w('\t\t\tclipName=""\n')
        w('\t\t\tinKeyMode="0"\n')
        w('\t\t\tyScroll="%d"\n' % (0 if is_kit else 36))
        w('\t\t\tyScrollKeyboard="50"\n')
        if is_kit:
            w('\t\t\taffectEntire="1"\n')
        w('\t\t\tinstrumentPresetName="%s"\n' % (KIT_NAME if is_kit else synth_name(c)))
        w('\t\t\tinstrumentPresetFolder="%s"\n' % ("KITS" if is_kit else "SYNTHS"))
        w('\t\t\tisPlaying="1"\n')
        w('\t\t\tisSoloing="0"\n')
        w('\t\t\tisArmedForRecording="0"\n')
        w('\t\t\tlength="%d"\n' % clip_len)
        w('\t\t\tcolourOffset="%d"\n' % ((c * 23) % 64 - 32))
        w('\t\t\tsection="0"\n')
        if c == 0:
            # Clip::writeDataToFile: "beingEdited" when saved from clip view (song opens in that clip),
            # "selected" when saved from song view (song opens in session view). Session view is the neutral
            # choice for profiling (same UI for synth and kit variants).
            w('\t\t\t%s="1"\n' % ("beingEdited" if cfg.open_clip else "selected"))
        w('\t\t\tkeyboardLayout="0"\n')
        w('\t\t\tkeyboardRowInterval="5"\n')
        w('\t\t\tdrumsScrollOffset="0"\n')
        w('\t\t\tdrumsZoomLevel="8"\n')
        w('\t\t\tinKeyScrollOffset="0"\n')
        w('\t\t\tinKeyRowInterval="3">\n')
        w("\t\t\t<arpeggiator\n\t\t\t\t" + ARP_ATTRS.format(i="\t\t\t") + " />\n")
        if is_kit:
            w("\t\t\t<kitParams\n")
            w(global_params_attrs("\t\t\t", "0x00000000", fx=kit_fx))
            w("\t\t\t</kitParams>\n")
        else:
            w(sound_params_xml("\t\t\t", "soundParams", cfg, fx=sound_fx_for(cfg, c)))
        w("\t\t\t<columnControls>\n\t\t\t\t<leftCol\n\t\t\t\t\ttype=\"velocity\" />\n"
          "\t\t\t\t<rightCol\n\t\t\t\t\ttype=\"mod\" />\n\t\t\t</columnControls>\n")
        w("\t\t\t<noteRows>\n")
        if is_kit:
            for r in range(k):
                w("\t\t\t\t<noteRow\n")
                w('\t\t\t\t\tcolourOffset="%d"\n' % ((r * 7) % 64))
                w('\t\t\t\t\tnoteDataWithSplitProb="%s"\n' % data)
                w('\t\t\t\t\tdrumIndex="%d">\n' % r)
                w(sound_params_xml("\t\t\t\t\t", "soundParams", cfg, fx=sound_fx_for(cfg, r)))
                w("\t\t\t\t</noteRow>\n")
        else:
            for y in chord_notes(clip_base_note(c), k):
                w("\t\t\t\t<noteRow\n")
                w('\t\t\t\t\ty="%d"\n' % y)
                w('\t\t\t\t\tnoteDataWithSplitProb="%s" />\n' % data)
        w("\t\t\t</noteRows>\n")
        w("\t\t</instrumentClip>\n")
    w("\t</sessionClips>\n")
    w("</song>\n")
    return "".join(o)


KIT_NAME = "TICKLOAD KIT"


def synth_name(c):
    return "TICKLOAD SYN%d" % (c + 1)


def drum_name(r):
    return "TL%02d" % (r + 1)


def kit_transpose(r):
    return (r * 5) % 24 - 12


def clip_base_note(c):
    return 36 + (c * 7) % 24


# ------------------------------------------------------------------------------------------------------------------
# Static validation: re-parse the file the way the firmware would read the parts that matter.
# ------------------------------------------------------------------------------------------------------------------

def parse_note_data(s):
    assert s.startswith("0x"), "note data must start with 0x"
    s = s[2:]
    assert len(s) % NOTE_HEX_LEN == 0, "note data length %d not a multiple of %d" % (len(s), NOTE_HEX_LEN)
    notes = []
    for i in range(0, len(s), NOTE_HEX_LEN):
        h = s[i:i + NOTE_HEX_LEN]
        notes.append(dict(pos=int(h[0:8], 16), length=int(h[8:16], 16), vel=int(h[16:18], 16),
                          lift=int(h[18:20], 16), prob=int(h[20:22], 16), iterance=int(h[22:26], 16),
                          fill=int(h[26:28], 16)))
    return notes


def check_fx(root, errs):
    """Check effect attribute values against the firmware's string tables / ranges and count active FX units
    (by the activation rules described in the Effects comment block)."""
    seen = {}

    def add(k):
        seen[k] = seen.get(k, 0) + 1

    def p(el, name, default="0x80000000"):
        return int(el.get(name, default), 16) & 0xFFFFFFFF if el is not None else 0x80000000

    for el in root.iter():
        if el.get("modFXType") is not None:
            t = el.get("modFXType")
            if t != "none" and t not in MODFX_TYPES:
                errs.append("unknown modFXType %r" % t)
            if el.get("lpfMode") not in LPF_MODES + ["Off"]:
                errs.append("bad lpfMode %r" % el.get("lpfMode"))
            if el.get("hpfMode") not in HPF_MODES + ["Off"]:
                errs.append("bad hpfMode %r" % el.get("hpfMode"))
            if el.get("filterRoute") not in FILTER_ROUTES:
                errs.append("bad filterRoute %r" % el.get("filterRoute"))
            if not 0 <= int(el.get("clippingAmount", "0")) <= 15:
                errs.append("clippingAmount out of 0..15")
            if el.get("clippingAmount"):
                add("clip")
            if el.get("sideChainSend"):
                add("sidechain-send")
            if el.get("modFXCurrentParam") not in (None, "depth", "feedback", "offset"):
                errs.append("bad modFXCurrentParam %r" % el.get("modFXCurrentParam"))
        if el.tag == "delay" and el.get("syncType") is not None:
            if el.get("syncType") not in ("0", "10", "19") or not 0 <= int(el.get("syncLevel")) <= 10:
                errs.append("bad delay sync %r/%r" % (el.get("syncLevel"), el.get("syncType")))
    rev = root.find("reverb")
    if rev is not None and rev.get("model") not in ("0", "1", "2"):
        errs.append("bad reverb model %r" % rev.get("model"))

    # Sounds: attributes on the <sound>, params in the clip's / noteRow's <soundParams> (same order as sounds).
    sounds = [el for el in root.find("instruments").iter("sound")]
    params = [sp for sp in root.find("sessionClips").iter("soundParams")]
    for snd, sp in zip(sounds, params):
        if snd.get("modFXType", "none") != "none":
            add("modfx:" + snd.get("modFXType"))
        for name, unit in (("delayFeedback", "delay"), ("reverbAmount", "reverb"), ("bitCrush", "bitcrush"),
                           ("sampleRateReduction", "srr"), ("waveFold", "fold"), ("hpfFrequency", "hpf")):
            if p(sp, name) != 0x80000000:
                add(unit + (":analog" if unit == "delay" and snd.find("delay").get("analog") == "1" else ""))
        if p(sp, "compressorThreshold", "0") not in (0,) and p(sp, "compressorThreshold", "0") < 0x80000000:
            add("comp")
        eq = sp.find("equalizer")
        if p(eq, "bass", "0") or p(eq, "treble", "0"):
            add("eq")
        for c in sp.iter("patchCable"):
            if c.get("source") == "compressor":
                add("sidechain-duck")
    # Song / kit GlobalEffectables
    for label, el, pr in (("song", root, root.find("songParams")),) + tuple(
            ("kit", k, c.find("kitParams")) for k in root.find("instruments").iter("kit")
            for c in root.find("sessionClips") if c.find("kitParams") is not None):
        cur = {"depth": "modFXDepth", "feedback": "modFXFeedback", "offset": "modFXOffset"}.get(
            el.get("modFXCurrentParam"), "modFXFeedback")
        if el.get("modFXType", "none") != "none" and p(pr, cur) != 0x80000000:
            add(label + "-modfx:" + el.get("modFXType"))
        elif el.get("modFXType", "none") != "none":
            errs.append("%s modFX %s is gated off (%s at minimum)" % (label, el.get("modFXType"), cur))
        for name, unit in (("reverbAmount", "reverb"), ("bitCrush", "bitcrush"), ("sampleRateReduction", "srr")):
            if p(pr, name) != 0x80000000:
                add(label + "-" + unit)
        if p(pr.find("delay"), "feedback") != 0x80000000:
            add(label + "-delay")
        if p(pr.find("lpf"), "frequency") != 0x7FFFFFFF:
            add(label + "-lpf")
        if p(pr.find("hpf"), "frequency") != 0x80000000:
            add(label + "-hpf")
        eq = pr.find("equalizer")
        if p(eq, "bass", "0") or p(eq, "treble", "0"):
            add(label + "-eq")
        if label == "kit" and 0 < p(pr, "compressorThreshold", "0") < 0x80000000:
            add("kit-comp")
        if label == "song" and int(el.find("audioCompressor").get("thresh")) > 0:
            add("song-comp")
        if pr.get("sidechainCompressorVolume"):
            add(label + "-sidechain")
    return seen


def check_song(path, quiet=False, table=False):
    errs = []
    tree = ET.parse(path)  # well-formed XML
    root = tree.getroot()
    if root.tag != "song":
        errs.append("root tag is %r, not 'song'" % root.tag)
    mag = int(root.get("inputTickMagnitude", "-99"))
    bar = 96 << mag
    tpt = int(root.get("timePerTimerTick")) + (int(root.get("timerTickFraction")) & 0xFFFFFFFF) / 4294967296.0
    bpm = 110250.0 / tpt / (1 << mag)
    if int(root.get("swingAmount", "0")) != 0:
        errs.append("swing is on")

    insts = {}
    for el in root.find("instruments"):
        if el.tag == "sound":
            insts[("synth", el.get("presetName"), el.get("presetFolder", "SYNTHS"))] = el
        elif el.tag == "kit":
            insts[("kit", el.get("presetName"), el.get("presetFolder", "KITS"))] = el
        else:
            errs.append("unexpected instrument tag %s" % el.tag)
        for osc in el.iter():
            if osc.tag in ("osc1", "osc2") and osc.get("type") in ("sample", "wavetable", "inLeft", "inRight"):
                errs.append("%s uses %s (needs SD/audio input)" % (el.get("presetName"), osc.get("type")))
            if osc.get("fileName"):
                errs.append("file reference %s" % osc.get("fileName"))
    if len(insts) != len(root.find("instruments")):
        errs.append("duplicate instrument names")

    fx_seen = check_fx(root, errs)

    starts = {}       # tick -> voices started
    ends = {}         # tick -> voices ended
    per_clip = []
    total_voice_ticks = 0
    used = set()
    for clip in root.find("sessionClips"):
        if clip.tag != "instrumentClip":
            errs.append("unexpected clip tag %s" % clip.tag)
            continue
        length = int(clip.get("length"))
        is_kit = clip.find("kitParams") is not None
        is_syn = clip.find("soundParams") is not None
        if is_kit == is_syn:
            errs.append("clip must have exactly one of kitParams/soundParams (sets outputTypeWhileLoading)")
        key = ("kit" if is_kit else "synth", clip.get("instrumentPresetName"), clip.get("instrumentPresetFolder"))
        if key not in insts:
            errs.append("clip refers to missing instrument %r" % (key,))
            continue
        if key in used:
            errs.append("two clips on one instrument %r (only one would play)" % (key,))
        used.add(key)
        if clip.get("isPlaying") != "1":
            errs.append("clip %r not playing" % (key,))
        rows = clip.find("noteRows")
        nrows = 0
        last_y = -10**9
        ndrums = len(insts[key].find("soundSources")) if is_kit else 0
        for row in rows:
            nrows += 1
            if is_kit:
                di = int(row.get("drumIndex"))
                if not (0 <= di < ndrums):
                    errs.append("drumIndex %d out of range" % di)
                if row.find("soundParams") is None:
                    errs.append("kit row without soundParams")
            else:
                y = int(row.get("y"))
                if y <= last_y:
                    errs.append("noteRow y not strictly ascending (%d after %d)" % (y, last_y))
                last_y = y
            data = row.get("noteDataWithSplitProb")
            if data is None:
                errs.append("row without noteDataWithSplitProb")
                continue
            min_pos = 0
            for n in parse_note_data(data):
                if n["pos"] < min_pos:
                    errs.append("overlapping/unsorted notes at %d (firmware would drop it)" % n["pos"])
                if n["pos"] + n["length"] > length:
                    errs.append("note at %d len %d runs past clip length %d" % (n["pos"], n["length"], length))
                if not (1 <= n["vel"] <= 127) or n["prob"] != PROB_100 or n["iterance"] or n["fill"]:
                    errs.append("odd note fields %r" % n)
                min_pos = n["pos"] + n["length"]
                starts[n["pos"]] = starts.get(n["pos"], 0) + 1
                e = (n["pos"] + n["length"]) % length
                ends[e] = ends.get(e, 0) + 1
                total_voice_ticks += n["length"]
        per_clip.append((key[1], "kit" if is_kit else "synth", nrows))
        clip_len = length

    ticks = sorted(set(starts) | set(ends))
    if not quiet:
        print("%s: %.2f BPM, %d ticks/bar, %d clip(s): %s" % (
            os.path.basename(path), bpm, bar, len(per_clip),
            ", ".join("%s[%s x%d]" % c for c in per_clip)))
        if table:
            print("  tick : starts ends")
        for t in (ticks if table else []):
            print("  %4d : %5d %4d   (step %g)" % (t, starts.get(t, 0), ends.get(t, 0), t / (bar / 16.0)))
        avg = total_voice_ticks / float(clip_len)
        print("  steps with starts: %d, voices started per such step: min %d max %d, avg held voices %.1f "
              "(excluding release tails)" % (len(starts), min(starts.values()), max(starts.values()), avg))
        if fx_seen:
            print("  active FX: " + ", ".join("%s x%d" % kv for kv in sorted(fx_seen.items())))
    if errs:
        for e in errs:
            print("  ERROR:", e)
    elif not quiet:
        print("  OK")
    return not errs


# ------------------------------------------------------------------------------------------------------------------

class Cfg:
    pass


def make_cfg(a, **over):
    c = Cfg()
    for k, v in vars(a).items():
        setattr(c, k, v)
    for k, v in over.items():
        setattr(c, k, v)
    c.step_ticks = TICKS_PER_16TH * c.step_16ths
    if c.kit:
        c.layout = "kit"
        c.kit_rows = c.kit
        c.chords = None
        per_sound = 1
    else:
        c.layout = "synth"
        if c.voices is not None:
            n, cl = c.voices, c.clips
            c.chords = [n // cl + (1 if i < n % cl else 0) for i in range(cl)]
            c.chords = [k for k in c.chords if k > 0]
        else:
            c.chords = [c.chord] * c.clips
        per_sound = max(c.chords)
    c.fx_units = parse_fx_spec(c.fx_set, FX_UNITS_SOUND, "sound")
    if c.fx_all:
        c.fx_units = dict(parse_fx_spec("all", FX_UNITS_SOUND, "sound"), **c.fx_units)
    c.song_fx_units = parse_fx_spec(c.song_fx, FX_UNITS_SONG, "song")
    c.kit_fx_units = parse_fx_spec(c.kit_fx, FX_UNITS_KIT, "kit")
    if c.kit_fx_units and c.layout != "kit":
        raise SystemExit("--kit-fx needs the kit layout (--kit ROWS)")
    if c.max_voices is None:
        # Room for this step's notes plus the previous step's (in fast release) so the per-Sound voice limit
        # (Sound::acquireVoice -> terminateOneActiveVoice) never steals. The UI allows up to 16.
        c.max_voices = max(8, min(16, 2 * per_sound)) if per_sound <= 8 else min(255, 2 * per_sound)
    return c


# Card layout: all songs directly in /SONGS. The tick probe (tools/perf/firmware/tick-probe.patch, dz_probe.cpp) autoplays the strcasecmp-smallest
# *.XML directly in /SONGS whose name contains dzSongPath (default "TICKLOAD"; patch to e.g. "KIT20" with
# tools/perf/set_song.py). '.' < '_' so TICKLOAD.XML wins for "TICKLOAD", and every variant suffix is unique.
# FAT directory order is NOT usable for this (mksd.sh copies files in host readdir order).
VARIANT_SUBDIR = ""

STANDARD_SET = [
    # (filename, subdir, overrides, description)
    ("TICKLOAD.XML", "", dict(), "default: 5 synth clips x 4-note chords = 20 voices/step"),
    ("TICKLOAD_KIT20.XML", VARIANT_SUBDIR, dict(kit=20), "1 kit, 20 synth drum rows = 20 voices/step"),
    ("TICKLOAD_N10.XML", VARIANT_SUBDIR, dict(chord=2), "5 synth clips x 2 notes = 10 voices/step"),
    ("TICKLOAD_N30.XML", VARIANT_SUBDIR, dict(chord=6), "5 synth clips x 6 notes = 30 voices/step"),
    ("TICKLOAD_FX.XML", VARIANT_SUBDIR, dict(fx=True), "default + reverb/delay sends on every sound"),
    ("TICKLOAD_U4.XML", VARIANT_SUBDIR, dict(unison=4),
     "default with unison 4 (firmware's default-synth unison): heavier render"),
    ("TICKLOAD_FXALL.XML", VARIANT_SUBDIR, dict(fx_all=True, song_fx="all"),
     "default + full FX chain on every sound (chorus, analog delay, reverb, bitcrush, SRR, clip, fold, EQ, "
     "24dBDrive LPF, HPF, compressor, sidechain) + all master FX"),
    ("TICKLOAD_FXVARY.XML", VARIANT_SUBDIR, dict(clips=7, voices=20, fx_all=True, fx_vary=True, song_fx="all"),
     "7 synth clips (3/3/3/3/3/3/2 = 20 voices), full chain, every modFX type + different distortion and filter "
     "modes per clip + all master FX"),
    ("TICKLOAD_GRAIN.XML", VARIANT_SUBDIR, dict(fx_set="modfx=grain,reverb", song_fx="modfx=grain"),
     "default + grain modFX on every sound and on the master"),
    ("TICKLOAD_KITCHAIN.XML", VARIANT_SUBDIR, dict(kit=20, fx_all=True, fx_vary=True, kit_fx="all", song_fx="all"),
     "kit of 20 synth rows, full varied chain per row + all kit-level and master FX"),
]


def check_variant_names():
    """Every variant suffix must select only itself in the probe's rule (see above): the strcasecmp-smallest name
    containing it must be that file."""
    names = [e[0] for e in STANDARD_SET]
    for n in names:
        key = n[:-4].replace("TICKLOAD_", "", 1) if n != "TICKLOAD.XML" else "TICKLOAD"
        pick = min((m for m in names if key.lower() in m.lower()), key=str.lower)
        assert pick == n, "variant key %r would select %s" % (key, pick)


def warn_dir_name_clashes(outdir):
    """Warn when files someone else put in outdir change which song a variant key selects."""
    try:
        names = [f for f in os.listdir(outdir) if f.upper().endswith(".XML")]
    except OSError:
        return
    for n in (e[0] for e in STANDARD_SET):
        key = n[:-4].replace("TICKLOAD_", "", 1) if n != "TICKLOAD.XML" else "TICKLOAD"
        cands = [m for m in names if key.lower() in m.lower()]
        if cands and min(cands, key=str.lower).upper() != n:
            print("warning: in %s, dzSongPath %r selects %s, not %s" % (outdir, key, min(cands, key=str.lower), n))


def find_standard(name):
    key = name.upper()
    for entry in STANDARD_SET:
        stem = entry[0][:-4]
        if key in (entry[0], stem, stem.replace("TICKLOAD_", "", 1), "DEFAULT" if stem == "TICKLOAD" else None):
            return entry
    raise SystemExit("unknown variant %r; one of: %s" % (name, ", ".join(e[0] for e in STANDARD_SET)))


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("-o", "--output", help="write one song to this path (otherwise the standard set)")
    p.add_argument("--set", action="store_true", help="write the standard set (default when no -o)")
    p.add_argument("--outdir", default=DEFAULT_OUTDIR, help="directory for the standard set [%(default)s]")
    p.add_argument("--check", nargs="+", metavar="XML", help="only validate existing song files")
    p.add_argument("--stage", nargs=2, metavar=("VARIANT", "DIR"),
                   help="write card content DIR/SONGS/<variant>.XML holding only that standard variant (e.g. KIT20, "
                        "N30, DEFAULT), for probe autoplay; build it with scripts/mksd.sh DIR IMG")
    p.add_argument("--only", metavar="NAMES", help="with the standard set: only these variants (e.g. FXALL,GRAIN)")
    p.add_argument("--force", action="store_true", help="overwrite existing songs whose content differs")
    p.add_argument("-v", "--verbose", action="store_true", help="print the per-tick start/end table")
    g = p.add_argument_group("layout")
    g.add_argument("--clips", type=int, default=5, help="synth clips (one synth each) [%(default)s]")
    g.add_argument("--chord", type=int, default=4, help="notes per chord per clip [%(default)s]")
    g.add_argument("--voices", type=int, default=None,
                   help="total voices per step, split over --clips (overrides --chord)")
    g.add_argument("--kit", type=int, default=0, metavar="ROWS",
                   help="kit layout: one kit with ROWS synth drum rows instead of synth clips")
    g = p.add_argument_group("timing")
    g.add_argument("--bpm", type=float, default=120.0, help="[%(default)s]")
    g.add_argument("--bars", type=int, default=1, help="clip length in bars [%(default)s]")
    g.add_argument("--step-16ths", type=int, default=1,
                   help="start notes every this many 16ths [%(default)s]")
    g.add_argument("--gate", type=float, default=1.0,
                   help="note length as a fraction of the step (1.0 = back-to-back) [%(default)s]")
    g = p.add_argument_group("sound")
    g.add_argument("--velocity", type=int, default=100)
    g.add_argument("--osc1", default="saw", help="osc1 type: saw, square, analogSaw, sine, triangle... [saw]")
    g.add_argument("--osc2", default="square", help="osc2 type, or 'off' to mute osc B [square]")
    g.add_argument("--unison", type=int, default=1, help="unison voices per note (1..8) [%(default)s]")
    g.add_argument("--release", type=int, default=0, help="amp env release, UI 0..50 [%(default)s]")
    g.add_argument("--volume", type=lambda s: int(s, 0), default=0x30000000,
                   help="per-sound volume param (default-synth is 0x50000000) [0x30000000]")
    g.add_argument("--max-voices", type=int, default=None, help="per-sound voice limit (default: 2x chord, >=8)")
    g.add_argument("--open-clip", action="store_true",
                   help="song opens in the first clip's clip view instead of song (session) view")
    g.add_argument("--fx", action="store_true", help="turn on reverb + delay sends on every sound")
    g.add_argument("--fx-reverb", type=int, default=15, help="reverb send UI value with --fx [%(default)s]")
    g.add_argument("--fx-delay", type=int, default=15, help="delay feedback UI value with --fx [%(default)s]")
    g = p.add_argument_group(
        "effects", "SPEC is a comma list of UNIT[=VALUE]; 'all' = every unit except route. Units: "
        "modfx[=flanger|chorus|phaser|stereochorus|warble|dimension|grain] (default chorus), "
        "delay[=16th|8th|8thT|4thD|...|off] (sync, default 16th), analog (analog delay), reverb[=0..50] "
        "(song: reverb[=freeverb|mutable|digital]), bitcrush[=0..50], srr[=0..50] (decimation), clip[=0..15] "
        "(saturation), fold[=0..50] (wavefolder, sounds only), eq[=-50..50] (bass+treble boost), "
        "lpf[=12dB|24dB|24dBDrive|SVF_Band|SVF_Notch], hpf[=SVF_Band|SVF_Notch|HPLadder] (switches the HPF on), "
        "route[=H2L|L2H|PARA], comp[=0..50] (compressor threshold), sidechain[=0..50] (first sound sends, the "
        "others duck).")
    g.add_argument("--fx-set", metavar="SPEC", default="", help="effects on every sound (synths and kit rows)")
    g.add_argument("--fx-all", action="store_true", help="same as --fx-set all (merged with --fx-set values)")
    g.add_argument("--fx-vary", action="store_true",
                   help="vary per sound: modFX type cycles through all types, LPF/HPF modes cycle, and each sound "
                        "gets one of the selected distortion units (bitcrush/srr/clip/fold) in turn")
    g.add_argument("--song-fx", metavar="SPEC", default="", help="master effects (song level)")
    g.add_argument("--kit-fx", metavar="SPEC", default="", help="kit-level (affect-entire) effects, kit layout only")
    a = p.parse_args(argv)

    if a.check:
        ok = all([check_song(f, table=True) for f in a.check])
        return 0 if ok else 1

    jobs = []
    if a.stage:
        name, sub, over, desc = find_standard(a.stage[0])
        songs = os.path.join(a.stage[1], "SONGS")
        os.makedirs(songs, exist_ok=True)
        stale = [f for f in os.listdir(songs) if "TICKLOAD" in f.upper() and f.upper() != name]
        if stale:
            raise SystemExit("%s already holds other TICKLOAD songs %s; use an empty dir" % (songs, stale))
        jobs.append((os.path.join(songs, name), make_cfg(a, **over), desc))
    elif a.output and not a.set:
        jobs.append((a.output, make_cfg(a), "custom"))
    else:
        check_variant_names()
        warn_dir_name_clashes(a.outdir)
        only = [find_standard(n)[0] for n in a.only.split(",")] if a.only else None
        for name, sub, over, desc in STANDARD_SET:
            if only is not None and name not in only:
                continue
            d = os.path.join(a.outdir, sub)
            os.makedirs(d, exist_ok=True)
            jobs.append((os.path.join(d, name), make_cfg(a, **over), desc))
    ok = True
    for path, cfg, desc in jobs:
        if cfg.osc2 == "off":
            cfg.osc2 = "square"  # type kept, level muted in soundParams (oscBVolume = 0x80000000)
            cfg.osc2_muted = True
        xml = build_song(cfg)
        if os.path.exists(path):
            with open(path, newline="") as f:
                same = f.read() == xml
            if same:
                # never touch an identical file: other runs may be measuring with it
                print("unchanged %s - %s" % (path, desc))
                ok = check_song(path, quiet=not a.verbose, table=a.verbose) and ok
                continue
            if not a.force:
                print("ERROR: %s exists with different content; not overwriting (use --force)" % path)
                ok = False
                continue
        with open(path, "w", newline="\n") as f:
            f.write(xml)
        print("wrote %s (%d bytes) - %s" % (path, len(xml), desc))
        ok = check_song(path, table=a.verbose) and ok
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
