#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Build the delugemu TCG plugins in plugins/ against the integrated QEMU tree's plugin API.
# Output: build/plugins/lib<name>.{dylib,so}. Use with run.sh ... -- -plugin build/plugins/libdzcache.dylib,<args>
set -euo pipefail
. "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/common.sh"

OUT="${REPO_ROOT}/build/plugins"
mkdir -p "${OUT}"
case "$(uname -s)" in
    Darwin) EXT=dylib; LINK=(-undefined dynamic_lookup) ;;
    *)      EXT=so;    LINK=() ;;
esac
GLIB_CFLAGS="$(pkg-config --cflags glib-2.0)"
for src in "${REPO_ROOT}"/plugins/*.c; do
    name="$(basename "${src}" .c)"
    # shellcheck disable=SC2086
    cc -O2 -shared -fPIC -Wall -Wno-unused-function -I "${QEMU_DIR}/include/plugins" ${GLIB_CFLAGS} \
        "${LINK[@]}" -o "${OUT}/lib${name}.${EXT}" "${src}"
    log "Built ${OUT}/lib${name}.${EXT}"
done
