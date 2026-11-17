#!/usr/bin/env bash
# stop_capture.sh — Stop the blind capture cleanly, leaving NO orphans.
#
# Never `kill` the daemon directly: that leaves its children (master_orchestrate,
# stage1_ref_dict's ICMP injection, swap_pages_tool's PSP commands) running against
# the hardware, which is what overloaded the host into a reboot. This stops the
# watchdog first (so it cannot relaunch), signals the daemon so it reaps its own
# child group, then verifies the whole subtree is gone.
set -u
cd /home/eun/open-science/case_study/mura/pipeline

ts() { date '+%H:%M:%S'; }
alive() { pgrep -f "$1" >/dev/null 2>&1; }

echo "[$(ts)] stopping watchdog (so it stops relaunching the daemon)"
pkill -f blind_capture_watchdog.sh 2>/dev/null || true
sleep 2

echo "[$(ts)] signalling daemon to reap its child group (SIGTERM)"
# SIGTERM triggers the daemon's handler, which killpg's the running child subtree.
sudo pkill -TERM -f 'capture_daemon.py' 2>/dev/null || true

# Give the handler time to kill its child group and exit.
for i in $(seq 1 20); do
    sleep 1
    alive 'capture_daemon.py' || break
done

# Escalate only if the daemon ignored SIGTERM.
if alive 'capture_daemon.py'; then
    echo "[$(ts)] daemon still up after 20s — SIGKILL"
    sudo pkill -9 -f 'capture_daemon.py' 2>/dev/null || true
    sleep 2
fi

# Final sweep: anything the daemon spawned that somehow outlived it. These are the
# processes that must never be left touching the guest.
for pat in 'master_orchestrate.py' 'stage1_ref_dict.py' 'swap_pages_tool' 'guest_mura_loader'; do
    if alive "$pat"; then
        echo "[$(ts)] sweeping stray: $pat"
        sudo pkill -TERM -f "$pat" 2>/dev/null || true
        sleep 2
        alive "$pat" && sudo pkill -9 -f "$pat" 2>/dev/null || true
    fi
done

rm -f .capture_daemon.lock
sleep 1

echo "[$(ts)] remaining:"
for pat in blind_capture_watchdog capture_daemon.py master_orchestrate stage1_ref_dict swap_pages_tool guest_mura_loader; do
    printf '  %-26s %s\n' "$pat" "$(pgrep -fc "$pat" 2>/dev/null || echo 0)"
done
echo "[$(ts)] guest qemu: $(ps -C qemu-system-x86 -o pid= --no-headers 2>/dev/null | tr -d ' ' || echo none)"
echo "[$(ts)] done. (guest VM left running; it is safe to leave up)"
