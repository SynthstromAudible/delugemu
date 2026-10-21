# SPDX-License-Identifier: GPL-2.0-or-later
"""Command-line front end for the delugemu scripting interface.

    delugemu run <scenario.json> [--firmware P] [--sd P] [--icount N]
    delugemu press PLAY            # one-shot verbs against a running instance
    delugemu turn SELECT_ENC 4
    delugemu pad 0 0
    delugemu key spc
    delugemu shot out.png
    delugemu oled | leds | seg | pads
    delugemu controls              # list known control names

One-shot verbs attach to an already-running emulator's QMP socket
(--sock, default /tmp/dz_qmp.sock); `run` launches one unless --sock is given.
"""
import argparse
import os
import sys

from . import geometry
from .qmp import QmpError
from .scenario import run_scenario
from .session import DelugeSession


def _attach(args):
    return DelugeSession.attach(args.sock)


def _cmd_run(args):
    int_log = args.int_log
    if args.sock:
        session = DelugeSession.attach(args.sock, artifacts_dir=args.artifacts)
        try:
            res = run_scenario(args.scenario, session=session,
                               artifacts_dir=args.artifacts, int_log=int_log)
        finally:
            session.close(quit_qemu=False)
    else:
        overrides = {}
        if args.firmware:
            overrides["firmware"] = args.firmware
        if args.sd:
            overrides["sd"] = args.sd
        if args.icount is not None:
            overrides["icount"] = args.icount
        if int_log is None:
            int_log = os.path.join(args.artifacts or ".", "int.log")
        res = run_scenario(args.scenario, artifacts_dir=args.artifacts,
                           int_log=int_log, **overrides)
    print("scenario %r: %s (%d steps)"
          % (res["name"], "OK" if res["ok"] else "FAIL", len(res["steps"])))
    return 0 if res["ok"] else 1


def _cmd_press(args):
    with _attach(args) as d:
        d.press(args.name)
    return 0


def _cmd_turn(args):
    with _attach(args) as d:
        d.turn(args.encoder, args.delta)
    return 0


def _cmd_pad(args):
    with _attach(args) as d:
        d.pad(args.x, args.y)
    return 0


def _cmd_key(args):
    with _attach(args) as d:
        d.key(args.qcode)
    return 0


def _cmd_shot(args):
    with _attach(args) as d:
        path = d.screenshot(args.path)
    print(path)
    return 0


def _cmd_oled(args):
    with _attach(args) as d:
        print(d.oled_text())
    return 0


def _cmd_leds(args):
    with _attach(args) as d:
        for name, on in sorted(d.read_leds().items()):
            if on or args.all:
                print("%-14s %s" % (name, "on" if on else "off"))
    return 0


def _cmd_seg(args):
    with _attach(args) as d:
        print(d.read_segment())
    return 0


def _cmd_pads(args):
    with _attach(args) as d:
        grid = d.read_pads()
    for row in range(8):
        cells = []
        for col in range(18):
            r, g, b = grid[col][row]
            cells.append("   " if (r or g or b) == 0 else "%02x%02x%02x" % (r, g, b))
        print(" ".join(cells))
    return 0


def _cmd_controls(args):
    for name in geometry.names():
        c = geometry.CONTROLS[name]
        kind = "encoder" if not c["has_led"] else "button"
        print("%-14s %-8s (%d,%d)" % (name, kind, c["cx"], c["cy"]))
    return 0


def build_parser():
    p = argparse.ArgumentParser(prog="delugemu", description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--sock", default="/tmp/dz_qmp.sock",
                   help="QMP socket of a running emulator (default: %(default)s)")
    sub = p.add_subparsers(dest="command", required=True)

    r = sub.add_parser("run", help="run a scenario file")
    r.add_argument("scenario")
    r.add_argument("--firmware")
    r.add_argument("--sd")
    r.add_argument("--icount")
    r.add_argument("--int-log", dest="int_log")
    r.add_argument("--artifacts", default=".",
                   help="directory for screenshots/logs (default: cwd)")
    r.set_defaults(func=_cmd_run, sock=None)

    pr = sub.add_parser("press", help="tap a named control")
    pr.add_argument("name")
    pr.set_defaults(func=_cmd_press)

    tu = sub.add_parser("turn", help="turn an encoder")
    tu.add_argument("encoder")
    tu.add_argument("delta", type=int)
    tu.set_defaults(func=_cmd_turn)

    pd = sub.add_parser("pad", help="tap a pad grid cell")
    pd.add_argument("x", type=int)
    pd.add_argument("y", type=int)
    pd.set_defaults(func=_cmd_pad)

    ke = sub.add_parser("key", help="press a host key by qcode")
    ke.add_argument("qcode")
    ke.set_defaults(func=_cmd_key)

    sh = sub.add_parser("shot", help="screendump to a file")
    sh.add_argument("path")
    sh.set_defaults(func=_cmd_shot)

    sub.add_parser("oled", help="dump the OLED as text").set_defaults(func=_cmd_oled)
    le = sub.add_parser("leds", help="dump indicator LEDs")
    le.add_argument("--all", action="store_true", help="include unlit LEDs")
    le.set_defaults(func=_cmd_leds)
    sub.add_parser("seg", help="dump the 7-segment display").set_defaults(func=_cmd_seg)
    sub.add_parser("pads", help="dump the RGB pad grid").set_defaults(func=_cmd_pads)
    sub.add_parser("controls", help="list known control names").set_defaults(
        func=_cmd_controls)
    return p


def main(argv=None):
    args = build_parser().parse_args(argv)
    try:
        return args.func(args)
    except (QmpError, AssertionError, ValueError, KeyError) as exc:
        sys.stderr.write("delugemu: %s\n" % exc)
        return 1


if __name__ == "__main__":
    sys.exit(main())
