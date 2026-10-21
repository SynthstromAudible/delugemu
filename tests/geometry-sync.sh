#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Guard that the committed Python control map (pylib/delugemu/_controls.py) is
# in sync with the C front-panel headers it is generated from. If a control's
# geometry changes in C without regenerating, the scripting interface would
# click the wrong pixels; this fails CI so the generator is re-run.
#
#   ./tests/geometry-sync.sh
#
# Skips cleanly (exit 0) when python3 is unavailable.

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

fail() { printf 'GEOMETRY FAIL: %s\n' "$*" >&2; exit 1; }
skip() { printf 'GEOMETRY SKIP: %s\n' "$*"; exit 0; }

command -v python3 >/dev/null 2>&1 || skip "python3 not available"

if python3 "${REPO_ROOT}/scripts/gen_control_map.py" --check; then
    printf 'GEOMETRY OK: control map matches the C headers\n'
else
    fail "pylib/delugemu/_controls.py is stale; run scripts/gen_control_map.py and commit"
fi
