#!/usr/bin/env bash
# boot_guest.sh — boot the SNP guest for the 3DShapes capture, fast.
#
# A 256 GB SNP guest validates all of its memory at boot. With 2 MB backing that
# takes ~2 min; when host memory is fragmented THP falls back to 4 KB and it took
# 28 min (2026-11-12: 305 GB page cache, 15 GB free, 48 of 234 GB huge). Dropping
# the page cache and compacting first gives THP its 2 MB pages back. Neither
# touches anyone's data; other VMs only see a brief slowdown.
#
# Refuses to start if another QEMU is running (never touch another user's VM).
set -u
LAUNCH=/home/eun/esp_bak/sev-step/launch-qemu-noncc.sh
BOOT_LOG=/tmp/mura_vm_boot.log

if pgrep -x qemu-system-x86 >/dev/null || pgrep -f 'qemu-system-x86_64' >/dev/null; then
    echo "[boot] a QEMU is already running — not starting another" >&2
    exit 1
fi
rm -f /tmp/qemu-monitor.sock /tmp/qmp-sock
sync
echo 3 > /proc/sys/vm/drop_caches
echo 1 > /proc/sys/vm/compact_memory
echo "===== mura3p boot $(date) =====" >> "$BOOT_LOG"
setsid bash "$LAUNCH" -cc >> "$BOOT_LOG" 2>&1 < /dev/null &
for i in $(seq 120); do
    if ssh -p 7777 -i /home/eun/.ssh/id_ed25519 -o ConnectTimeout=5 -o BatchMode=yes \
           -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null -o LogLevel=ERROR \
           ubuntu@localhost true 2>/dev/null; then
        echo "[boot] guest up after $((i * 15))s"
        exit 0
    fi
    sleep 15
done
echo "[boot] guest did not come up in 30 min" >&2
exit 2
