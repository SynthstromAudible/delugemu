# SPDX-License-Identifier: GPL-2.0-or-later
"""Minimal QMP (QEMU Machine Protocol) client over a UNIX socket.

QMP is newline-delimited JSON. A single client connects, reads the greeting,
sends ``qmp_capabilities`` once, then exchanges command/response objects. This
consolidates the socket boilerplate previously duplicated across the ad-hoc
``scripts/*.py`` drivers.
"""
import json
import socket
import time


class QmpError(Exception):
    """A QMP command returned an error, or the connection failed."""


class QmpClient:
    def __init__(self, sock_path, connect_timeout=30.0):
        self.sock_path = sock_path
        self._sock = None
        self._f = None
        self._connect(connect_timeout)

    def _connect(self, timeout):
        deadline = time.monotonic() + timeout
        last = None
        while time.monotonic() < deadline:
            try:
                s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                s.connect(self.sock_path)
                self._sock = s
                self._f = s.makefile("rw")
                break
            except OSError as exc:
                last = exc
                time.sleep(0.1)
        else:
            raise QmpError("could not connect to QMP socket %s: %s"
                           % (self.sock_path, last))
        self._f.readline()  # greeting
        self.execute("qmp_capabilities")

    def execute(self, command, **arguments):
        """Run a QMP command; return its ``return`` value or raise QmpError."""
        obj = {"execute": command}
        if arguments:
            obj["arguments"] = arguments
        self._f.write(json.dumps(obj) + "\n")
        self._f.flush()
        while True:
            line = self._f.readline()
            if not line:
                raise QmpError("QMP connection closed")
            msg = json.loads(line)
            if "event" in msg:
                continue  # asynchronous event; keep reading for the reply
            if "error" in msg:
                raise QmpError(msg["error"].get("desc", str(msg["error"])))
            return msg.get("return")

    def hmp(self, command_line):
        """Run a human-monitor command line and return its text output."""
        return self.execute("human-monitor-command",
                            **{"command-line": command_line})

    def qom_get(self, path, prop):
        return self.execute("qom-get", path=path, property=prop)

    def qom_list(self, path):
        return self.execute("qom-list", path=path)

    def find_device(self, typename, root="/machine", max_nodes=4096):
        """Breadth-first search the composition tree for a child device whose
        QOM type contains ``typename``; return its canonical path or None."""
        seen = set()
        queue = [root]
        while queue and len(seen) < max_nodes:
            path = queue.pop(0)
            if path in seen:
                continue
            seen.add(path)
            try:
                entries = self.qom_list(path)
            except QmpError:
                continue
            for entry in entries:
                etype = entry.get("type", "")
                if not etype.startswith("child<"):
                    continue
                child_path = path + "/" + entry["name"]
                if typename in etype:
                    return child_path
                queue.append(child_path)
        return None

    def close(self):
        try:
            if self._f:
                self._f.close()
        except OSError:
            pass
        try:
            if self._sock:
                self._sock.close()
        except OSError:
            pass
        self._f = self._sock = None
