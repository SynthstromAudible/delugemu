#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Build a raw FAT32 disk image for the Deluge SDHI SD slot from a content
# directory (defaults to ./sdcard, the factory content).
#
# Usage:
#   ./scripts/mksd.sh [content-dir] [output-image]
#
# Defaults:
#   content-dir   sdcard
#   output-image  build/deluge_sd.img
#
# Run the result with:
#   ./scripts/run.sh firmware2/deluge.elf --sd build/deluge_sd.img

set -euo pipefail

. "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/common.sh"

CONTENT_DIR="${1:-${REPO_ROOT}/sdcard}"
OUT_IMG="${2:-${REPO_ROOT}/build/deluge_sd.img}"

[ -d "${CONTENT_DIR}" ] || die "Content directory not found: ${CONTENT_DIR}"
mkdir -p "$(dirname "${OUT_IMG}")"

# Format with 32 KiB clusters, the allocation unit Synthstrom recommends for
# Deluge cards. The firmware streams samples a cluster at a time, so the
# cluster size shapes its SD access pattern; tool defaults for small volumes
# (a few KiB) would make the emulated card behave unlike a real one.
CLUSTER_SECTORS=64   # x 512-byte sectors = 32 KiB

# Size the image at the content size plus 30% slack (min 64 MiB), then round up
# to the next power of two: QEMU's sd-card device requires a power-of-2 capacity.
# Floor at 4 GiB: FAT32 needs at least 65525 clusters, which at 32 KiB is just
# over 2 GiB of data area, so 2 GiB falls short once the FATs are reserved.
# The image is sparse, so the unused space costs neither disk nor time.
MIN_IMG_MIB=4096
content_kib=$(du -sk "${CONTENT_DIR}" | awk '{print $1}')
need_mib=$(( (content_kib * 13 / 10) / 1024 + 64 ))
[ "${need_mib}" -lt "${MIN_IMG_MIB}" ] && need_mib="${MIN_IMG_MIB}"
img_mib="${MIN_IMG_MIB}"
while [ "${img_mib}" -lt "${need_mib}" ]; do
    img_mib=$(( img_mib * 2 ))
done
log "Content ${content_kib} KiB -> image ${img_mib} MiB (power of 2, 32 KiB clusters) at ${OUT_IMG}"

rm -f "${OUT_IMG}"

uname_s="$(uname -s)"
if [ "${uname_s}" = "Darwin" ]; then
    # macOS: create a sparse blank image, attach as raw device, format FAT32,
    # copy, eject.
    dd if=/dev/zero of="${OUT_IMG}" bs=1m count=0 seek="${img_mib}" status=none

    dev="$(hdiutil attach -nomount -imagekey diskimage-class=CRawDiskImage \
            "${OUT_IMG}" | head -1 | awk '{print $1}')"
    [ -n "${dev}" ] || die "hdiutil attach failed"
    # Ensure we always detach, even on error.
    trap 'hdiutil detach "${dev}" >/dev/null 2>&1 || true' EXIT

    newfs_msdos -F 32 -S 512 -c "${CLUSTER_SECTORS}" -v DELUGE "${dev}" >/dev/null
    diskutil mount "${dev}" >/dev/null
    mp="$(diskutil info "${dev}" | awk -F': *' '/Mount Point/ {print $2}')"
    [ -n "${mp}" ] || die "could not determine mount point for ${dev}"

    log "Copying ${CONTENT_DIR} -> ${mp}"
    # rsync without -X/-A so macOS writes no AppleDouble (._*) files onto the
    # FAT volume, and exclude metadata junk that Finder copies or vendor zips
    # may have left in the content folder — the firmware chokes on none of it,
    # but it clutters the card and ping-pongs back via the _rw write-back.
    rsync -rlt --exclude '._*' --exclude '.DS_Store' --exclude '__MACOSX' \
        "${CONTENT_DIR}/" "${mp}/"
    # The kernel itself still writes a ._ sidecar for any xattr it attaches on
    # create (com.apple.provenance tags every file a modern macOS process
    # writes), whatever rsync is told; strip them, and Spotlight's journal.
    find "${mp}" -name '._*' -type f -delete
    rm -rf "${mp}/.fseventsd" "${mp}/.Spotlight-V100"
    sync
    diskutil unmount "${dev}" >/dev/null
    hdiutil detach "${dev}" >/dev/null
    trap - EXIT
else
    # Linux: requires mtools (mkfs.fat + mcopy).
    command -v mkfs.fat >/dev/null || die "mkfs.fat not found (install dosfstools)"
    command -v mcopy    >/dev/null || die "mcopy not found (install mtools)"

    # Sparse blank image (seek past the end, write nothing).
    dd if=/dev/zero of="${OUT_IMG}" bs=1M count=0 seek="${img_mib}" status=none
    mkfs.fat -F 32 -S 512 -s "${CLUSTER_SECTORS}" -n DELUGE "${OUT_IMG}" >/dev/null
    log "Copying ${CONTENT_DIR} -> image"
    mcopy -i "${OUT_IMG}" -s "${CONTENT_DIR}"/* ::/
fi

log "SD image ready: ${OUT_IMG}"
