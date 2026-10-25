#!/usr/bin/env python3
"""Run the dz probe firmware on a real Deluge through a Black Magic Probe, for calibrating the emulator.

This halts and reloads the Deluge: only use it when you mean to. Nothing is written to the SD card or flash; `restore`
(or a power cycle) puts the installed firmware back.

  tools/perf/hw_probe.py load --elf probe.elf      # reset_halt, load the probe into RAM, run
  ... wait for the song (the probe loads and plays it by itself, PLAY ~13 s after boot) ...
  tools/perf/hw_probe.py dump --elf probe.elf --out hw.bin
  tools/perf/hw_probe.py restore

Needs a BMP firmware whose RZ/A1 driver has `monitor reset_halt` (watchdog reset of the whole SoC, then the boot ROM
and loader run up to the application entry). That leaves every peripheral in its reset state, so the probe starts as
cleanly as on a normal boot. Halting a running firmware and loading over it instead leaves USB and the GIC live, and an
interrupt left active then blocks the SD controller's.
"""
import argparse
import subprocess
import sys

GDB = "arm-none-eabi-gdb"


def gdb(port, elf, cmds, timeout=600):
    script = ["set confirm off", "set pagination off", "target extended-remote %s" % port, "monitor swd_scan",
              "attach 1", "set mem inaccessible-by-default off"] + cmds + ["detach"]
    argv = [GDB, "-nx", "-batch"] + ([elf] if elf else []) + sum([["-ex", c] for c in script], [])
    p = subprocess.run(argv, capture_output=True, text=True, timeout=timeout)
    return p.stdout + p.stderr


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("action", choices=["load", "dump", "restore", "status"])
    ap.add_argument("--elf", help="probe firmware ELF (load, dump, status)")
    ap.add_argument("--out", default="hw.bin", help="dump: output file")
    ap.add_argument("--port", default="/dev/cu.usbmodem98B72AB21", help="BMP GDB server serial port")
    args = ap.parse_args()

    status = ['printf "AUTO stage=%u result=%d load_window=%u play_window=%u window=%u\\n", '
              'dzAutoStage, dzResult, dzLoadIndex, dzPlayIndex, dzProbe.index']
    if args.action == "load":
        out = gdb(args.port, args.elf, ["monitor reset_halt", "maintenance flush register-cache", "load",
                                        "compare-sections"])
    elif args.action == "dump":
        out = gdb(args.port, args.elf, status + [
            "dump binary memory %s &dzProbe ((char*)&dzProbe)+sizeof(dzProbe)" % args.out])
    elif args.action == "status":
        out = gdb(args.port, args.elf, status)
    else:
        out = gdb(args.port, None, ["monitor reset_halt", "maintenance flush register-cache"])
    keep = ("Core ", "AUTO ", "Start address", "MIS-MATCHED", "Error", "error")
    print("\n".join(l for l in out.splitlines() if l.startswith(keep)) or out[-1000:])
    return 1 if "MIS-MATCHED" in out else 0


if __name__ == "__main__":
    sys.exit(main())
