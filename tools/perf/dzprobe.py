"""Shared helpers for the performance tools: firmware symbols, and the dz probe firmware's ring of 100 ms windows.

The probe firmware is the DelugeFirmware branch debug/pmu-render-probe. It records, per 100 ms window: render timing
and gaps, culls, late clusters, A9 PMU counters summed over renders (cycles, instructions, L1 refills, cache stall
cycles) and for the most expensive render, per-function inclusive costs (DzScope) and delay-path counts. It also
loads and plays a song by itself at boot (dzCommand = AUTO, dzSongPath = a file-name substring).
"""
import struct
import subprocess

NUM_WINDOWS = 2048
_BASE = ["start", "renders", "maxGap", "maxGapCaller", "maxGapTask", "maxGapTaskTime", "maxRender",
         "maxRenderSamples", "maxRenderVoicesStarted", "maxRenderHops", "maxTask", "maxTaskTime", "maxIrq", "irqs",
         "culls", "late", "clustersFinished", "frames"]
_PMU = ["cyc", "ins", "l1i", "l1d", "l1dacc", "istall", "dstall", "l2rd", "l2rdhit"]
# Later probe builds append fields; a dump's size says how many it has
FIELDS = (_BASE + ["sum_" + p for p in _PMU] + ["max_" + p for p in _PMU] + ["maxFrames", "voices", "audioVoices"]
          + ["scopeCalls%d" % i for i in range(6)] + ["scopeIns%d" % i for i in range(6)]
          + ["scopeCyc%d" % i for i in range(6)]
          + ["delayRateChange", "delaySecondary", "delayResampling", "delayAnalog", "tickInvMin", "tickInvMax"])
SCOPE_NAMES = ["Delay::process", "Reverb::process", "processFX", "Sound::render",
               "GlobalEffectableForClip::renderOutput", "TimeStretcher::hopEnd"]
TICK_HZ = 33.33e6  # getSystemTicks()


def load_windows(path):
    """Completed windows from a dump of the dzProbe struct, oldest first, each a dict with an "i" index."""
    raw = open(path, "rb").read()
    magic, index = struct.unpack_from("<II", raw)
    if magic != 0xD2D2D2D2:
        raise ValueError("%s: not a dz probe dump (magic %#x)" % (path, magic))
    nfields = (len(raw) - 8 - 12) // NUM_WINDOWS // 4
    names = FIELDS[:nfields]
    size = 4 * nfields
    out = []
    for i in range(max(0, index - NUM_WINDOWS + 1), index):
        w = dict(zip(names, struct.unpack_from("<%dI" % nfields, raw, 8 + (i % NUM_WINDOWS) * size)))
        w["i"] = i
        out.append(w)
    return out


def symbols(elf):
    """{demangled name: (address, size)} for every symbol in the ELF (size 0 for linker-script symbols)."""
    out = {}
    nm = subprocess.run(["arm-none-eabi-nm", "-C", "-S", elf], capture_output=True, text=True, check=True).stdout
    for line in nm.splitlines():
        # "addr size type name", or "addr type name" for symbols without a size
        parts = line.split(" ", 3)
        if len(parts) == 4 and len(parts[2]) == 1:
            out.setdefault(parts[3], (int(parts[0], 16), int(parts[1], 16)))
        elif len(parts) >= 3 and len(parts[1]) == 1:
            out.setdefault(line.split(" ", 2)[2], (int(parts[0], 16), 0))
    return out


def find(syms, prefix):
    """Address of the largest symbol whose name starts with prefix (picks the real body over thunks/clones)."""
    # ")::" would be a function-local static, e.g. Sound::render(...)::sound_memory
    hits = [(size, addr) for name, (addr, size) in syms.items() if name.startswith(prefix) and ")::" not in name]
    if not hits:
        raise KeyError("no symbol starting with %r" % prefix)
    return max(hits)[1]


def probe_addresses(elf):
    """The addresses the plugin and the dump need, resolved from the probe ELF."""
    s = symbols(elf)
    return {
        "ttb": find(s, "ttb_mmu1_base"),
        "mark": find(s, "PlaybackHandler::playButtonPressed("),
        "render": find(s, "AudioEngine::routine()"),
        "timer": find(s, "AudioEngine::audioSampleTimer"),
        "probe": find(s, "dzProbe"),
        "probe_size": s["dzProbe"][1],
        "scopes": [find(s, p) for p in ("Delay::process(", "deluge::dsp::Reverb::process(",
                                         "ModControllableAudio::processFX(", "Sound::render(Model",
                                         "GlobalEffectableForClip::renderOutput(", "TimeStretcher::hopEnd(")],
    }
