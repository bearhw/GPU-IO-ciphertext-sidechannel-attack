#!/usr/bin/env bash
# stall_guard.sh — Unstick the blind capture when the guest hangs mid-sample.
#
# master_orchestrate.py waits on the guest over ssh with no timeout, so a hung
# guest leaves the daemon blocked forever (16:48 -> 23:05 on Nov 3) and its own
# "guest unreachable" recovery never runs. Every live phase (guest boot, stage1
# swaps, stage2/3 probing) writes to daemon_blind.log continuously, so a log that
# has not moved for STALL_MIN minutes means a stuck child. Killing the child
# returns control to the daemon, which then reboots the guest itself.
#
# A guest kernel oops is worse than a hang: the guest keeps answering, so the
# daemon keeps capturing on a corrupted kernel while a lock the oopsing task held
# slowly stalls every new ssh session (Nov 4: GPF at 19:03, second GPF in mount
# at 21:20, samples 3 min -> 11 min, then a full stall). The guest console goes to
# BOOT_LOG, so an oops there stops the VM at once (ours only, via its own monitor
# socket); the daemon then finds the guest unreachable and boots a fresh one.
#
#   tmux new -d -s stall_guard 'bash stall_guard.sh'
set -u

cd /home/eun/open-science/case_study/mura/pipeline
LOG=daemon_blind.log
STALL_MIN=${1:-15}
GLOG=stall_guard.log
BOOT_LOG=/tmp/mura_vm_boot.log
MON=/tmp/qemu-monitor.sock
OOPS_RE='general protection fault|BUG: |Oops: |Kernel panic|soft lockup|hard LOCKUP|blocked for more than|list_(add|del) corruption|kernel BUG at'
CRASH_DIR=guest_crashes
CHILDREN=(master_orchestrate.py stage1_ref_dict.py swap_pages_tool 'ssh -p 7777')

ts() { date '+%Y-%m-%d %H:%M:%S'; }
say() { echo "[guard $(ts)] $*" | tee -a "$GLOG"; }

kill_children() {
    for pat in "${CHILDREN[@]}"; do
        pids=$(pgrep -f "$pat" | tr '\n' ' ')
        [ -n "$pids" ] && say "  $pat: $pids"
        sudo -n pkill -TERM -f "$pat" 2>/dev/null || true
    done
    sleep 20
    for pat in "${CHILDREN[@]}"; do
        sudo -n pkill -9 -f "$pat" 2>/dev/null || true
    done
}

# Our VM is the one listening on $MON; never signal any other QEMU on the host.
our_qemu() { pgrep -f "qemu-system-x86.*${MON}" | head -1; }

stop_our_vm() {
    local pid=$1
    say "  stopping our QEMU $pid via its monitor"
    sudo -n python3 - "$MON" <<'EOF' || true
import socket, sys, time
s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM); s.settimeout(5)
s.connect(sys.argv[1]); time.sleep(0.2); s.recv(4096); s.sendall(b"quit\n"); time.sleep(1)
EOF
    for _ in $(seq 30); do
        sudo -n kill -0 "$pid" 2>/dev/null || { say "  QEMU $pid gone"; return; }
        sleep 1
    done
    say "  QEMU $pid ignored quit — SIGKILL"
    sudo -n kill -9 "$pid" 2>/dev/null || true
}

say "watching $LOG (stall = ${STALL_MIN}min) and $BOOT_LOG (guest oops)"
handled_pid=""
while true; do
    sleep 60
    pgrep -f 'capture_daemon.py' >/dev/null || continue

    # 1. Guest oops: act once per QEMU instance. The daemon opens BOOT_LOG in
    # append mode, so the log is emptied after each handled oops; otherwise the
    # next boot would be killed for the old one.
    qpid=$(our_qemu)
    if [ -n "$qpid" ] && [ "$qpid" != "$handled_pid" ] && [ -r "$BOOT_LOG" ]; then
        hit=$(grep -aEm1 "$OOPS_RE" "$BOOT_LOG" || true)
        if [ -n "$hit" ]; then
            handled_pid=$qpid
            mkdir -p "$CRASH_DIR"
            keep="$CRASH_DIR/console_$(date +%Y%m%d_%H%M%S).log"
            cp "$BOOT_LOG" "$keep" 2>/dev/null || sudo -n cp "$BOOT_LOG" "$keep"
            say "guest oops in QEMU $qpid: ${hit:0:160}"
            say "  console saved to $keep"
            kill_children
            stop_our_vm "$qpid"
            sudo -n truncate -s 0 "$BOOT_LOG"
            touch "$LOG"
            continue
        fi
    fi

    # 2. Stall: a child stuck on a hung guest.
    age=$(( $(date +%s) - $(stat -c %Y "$LOG") ))
    [ "$age" -lt $((STALL_MIN * 60)) ] && continue
    say "$LOG idle ${age}s — killing stuck children"
    kill_children
    # Give the daemon time to reboot the guest before judging the log again.
    touch "$LOG"
done
