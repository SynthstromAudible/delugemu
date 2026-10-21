# SPDX-License-Identifier: GPL-2.0-or-later
"""Declarative scenario runner.

A scenario is a JSON (or YAML, if PyYAML is installed) document describing a
sequence of interactions and assertions. It is the shareable, re-runnable
artifact for a bug report or an integration test.

Schema::

    {
      "name": "enter-song-view",
      "firmware": null,          # optional; null lets run.sh resolve one
      "sd": "auto",              # optional SD image path
      "icount": 6,               # optional deterministic virtual clock
      "boot_wait": 3.0,          # optional seconds to wait after launch
      "steps": [
        {"wait": 0.5},
        {"press": "PLAY"},                      # or {"press": {"name":"PLAY","hold_ms":150}}
        {"key": "spc"},
        {"turn": ["SELECT_ENC", 4]},            # or {"turn": {"encoder":..,"delta":..}}
        {"pad": [0, 0]},                        # or {"pad": {"x":0,"y":0}}
        {"screenshot": "song.png"},
        {"assert_led": ["PLAY", true]},         # or {"assert_led": {"name":..,"state":..}}
        {"assert_segment": "120"},
        {"assert_oled_contains": "SONG"},
        {"assert_no_aborts": true}
      ]
    }
"""
import json
import os

from .session import DelugeSession


def load_scenario(path):
    with open(path, encoding="utf-8") as fh:
        text = fh.read()
    if path.lower().endswith((".yaml", ".yml")):
        try:
            import yaml  # optional dependency
        except ImportError:
            raise RuntimeError("PyYAML not installed; use a .json scenario or "
                               "`pip install pyyaml`")
        return yaml.safe_load(text)
    return json.loads(text)


def _apply(session, verb, arg):
    if verb == "wait":
        session.wait(float(arg))
    elif verb == "press":
        if isinstance(arg, dict):
            session.press(arg["name"], arg.get("hold_ms", 120))
        else:
            session.press(arg)
    elif verb == "key":
        if isinstance(arg, dict):
            session.key(arg["qcode"], arg.get("hold_ms", 120))
        else:
            session.key(arg)
    elif verb == "turn":
        if isinstance(arg, dict):
            session.turn(arg["encoder"], arg["delta"])
        else:
            session.turn(arg[0], arg[1])
    elif verb == "pad":
        if isinstance(arg, dict):
            session.pad(arg["x"], arg["y"], arg.get("hold_ms", 120))
        else:
            session.pad(arg[0], arg[1])
    elif verb == "hold":
        session.hold(arg)
    elif verb == "release":
        session.release()
    elif verb == "screenshot":
        return session.screenshot(arg)
    elif verb == "assert_led":
        if isinstance(arg, dict):
            session.assert_led(arg["name"], arg.get("state", True))
        else:
            session.assert_led(arg[0], arg[1] if len(arg) > 1 else True)
    elif verb == "assert_segment":
        session.assert_segment(arg)
    elif verb == "assert_oled_contains":
        session.assert_oled_contains(arg)
    elif verb == "assert_no_aborts":
        if arg:
            session.assert_no_aborts()
    else:
        raise ValueError("unknown scenario verb %r" % verb)
    return None


def run_scenario(scenario, session=None, artifacts_dir=None, int_log=None,
                 on_step=None, **launch_kwargs):
    """Run a scenario (path or dict). If no ``session`` is given, launch one
    from the scenario's firmware/sd/icount (overridable via launch_kwargs).

    Returns a results dict. Raises on the first failing step after capturing a
    failure screenshot into ``artifacts_dir``."""
    if isinstance(scenario, str):
        scenario = load_scenario(scenario)

    owns_session = session is None
    if owns_session:
        kwargs = dict(
            firmware=scenario.get("firmware"),
            sd=scenario.get("sd"),
            icount=scenario.get("icount"),
            int_log=int_log,
            artifacts_dir=artifacts_dir,
        )
        kwargs.update(launch_kwargs)
        session = DelugeSession.launch(**kwargs)
        if artifacts_dir is None:
            session.artifacts_dir = os.getcwd()

    results = {"name": scenario.get("name", "scenario"), "steps": [],
               "ok": True}
    try:
        boot_wait = scenario.get("boot_wait")
        if boot_wait:
            session.wait(float(boot_wait))
        for index, step in enumerate(scenario.get("steps", [])):
            if len(step) != 1:
                raise ValueError("step %d must have exactly one verb: %r"
                                 % (index, step))
            (verb, arg), = step.items()
            if on_step:
                on_step(index, verb, arg)
            try:
                out = _apply(session, verb, arg)
                results["steps"].append({"verb": verb, "ok": True, "out": out})
            except AssertionError as exc:
                results["ok"] = False
                results["steps"].append({"verb": verb, "ok": False,
                                        "error": str(exc)})
                shot = _safe_screenshot(session, "failure.png")
                raise AssertionError("step %d (%s) failed: %s%s"
                                     % (index, verb, exc,
                                        " [see %s]" % shot if shot else ""))
    finally:
        if owns_session:
            session.close()
    return results


def _safe_screenshot(session, name):
    try:
        return session.screenshot(name)
    except Exception:
        return None
