#!/usr/bin/env bash
# blind_capture_watchdog.sh — Keep the BLIND valid-split capture running.
#
# capture_daemon.py already recovers from guest reboots, dead dictionaries, stuck
# loaders and vfio loss. This wraps it so that if the daemon process itself dies
# (an unhandled exception, an OOM kill, a terminal hang-up), it is restarted rather
# than leaving the capture silently stopped for hours.
#
# Blind mode: --blind-block drops the guest-given 2MB block, so blocks come from
# burst candidates and --probe selects among them. --to-stage 5 runs classification
# with the fine-tuned model too, but the number that matters here is page recovery;
# re-score with the blind model afterwards.
#
#   tmux new -s blind_cap
#   bash blind_capture_watchdog.sh [PER_CLASS] [CHUNK]
set -u

cd /home/eun/open-science/case_study/mura/pipeline
PY=/home/eun/miniforge3/bin/python3
# Target is PER CLASS, not a single index bound: the valid CSV is ordered by body
# part, so an index bound (the old --end 500) lands entirely in WRIST. --per-class
# with interleave fills all seven classes evenly to this count of BLIND captures.
PER_CLASS=${1:-324}
CHUNK=${2:-100}
LOG=daemon_blind.log
MAX_RESTARTS=100

# Single instance only. A second watchdog would launch a second daemon, and two
# daemons driving the same ICMP/PSP hardware is exactly what corrupted the
# dictionary and overloaded the host. flock holds for the life of this script.
exec 9>.watchdog.lock
if ! flock -n 9; then
    echo "[watchdog] another watchdog already holds .watchdog.lock — exiting" >&2
    exit 1
fi

ts() { date '+%Y-%m-%d %H:%M:%S'; }

# Reap the whole daemon subtree if THIS watchdog is terminated, so stopping the
# watchdog never strands the daemon or its stage1/swap children.
cleanup() {
    echo "[watchdog $(ts)] terminating — stopping daemon subtree" | tee -a "$LOG"
    sudo pkill -TERM -f 'capture_daemon.py' 2>/dev/null || true
    sleep 5
    sudo pkill -9 -f 'capture_daemon.py' 2>/dev/null || true
    for pat in master_orchestrate.py stage1_ref_dict.py swap_pages_tool; do
        sudo pkill -9 -f "$pat" 2>/dev/null || true
    done
    exit 0
}
trap cleanup TERM INT HUP

# A reboot invalidates ~/.ssh/known_hosts for [localhost]:7777; the pipeline's own
# ssh now ignores it (UserKnownHostsFile=/dev/null), but clear the user's file too
# so any manual ssh in this session does not trip over it.
ssh-keygen -R "[localhost]:7777" >/dev/null 2>&1 || true

echo "[watchdog $(ts)] blind valid capture: per-class=$PER_CLASS chunk=$CHUNK" | tee -a "$LOG"

n=0
while [ "$n" -lt "$MAX_RESTARTS" ]; do
    n=$((n + 1))
    echo "[watchdog $(ts)] starting daemon (attempt $n)" | tee -a "$LOG"

    sudo "$PY" -u capture_daemon.py \
        --split valid --per-class "$PER_CLASS" --chunk "$CHUNK" \
        --blind-block --probe --to-stage 5 \
        2>&1 | tee -a "$LOG"

    rc=${PIPESTATUS[0]}
    echo "[watchdog $(ts)] daemon exited (rc=$rc)" | tee -a "$LOG"

    # rc 0 = daemon decided it was done (all indices captured). Stop.
    if [ "$rc" -eq 0 ]; then
        echo "[watchdog $(ts)] capture complete — stopping watchdog" | tee -a "$LOG"
        break
    fi

    echo "[watchdog $(ts)] restarting in 30s" | tee -a "$LOG"
    sleep 30
done

if [ "$n" -ge "$MAX_RESTARTS" ]; then
    echo "[watchdog $(ts)] hit $MAX_RESTARTS restarts — giving up, check $LOG" | tee -a "$LOG"
fi
