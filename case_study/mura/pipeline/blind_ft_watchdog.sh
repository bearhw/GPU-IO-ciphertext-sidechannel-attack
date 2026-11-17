#!/usr/bin/env bash
# blind_ft_watchdog.sh — Run the blind re-fine-tune AFTER the blind capture
# finishes, and keep it running until all three models are done.
#
# Why a watchdog: the Oct 19 run died in a host reboot after 3 epochs of one model
# and nobody noticed for two days. This one is single-instance (flock), waits for
# the capture to stop hogging the host, restarts run_blind_finetune.sh if it dies,
# and — because run_blind_finetune.sh is resumable via .done markers — a restart
# resumes at the first unfinished model instead of redoing everything.
#
# The fine-tune is pure CPU torch: no ICMP/PSP/guest, so its only children are
# python workers, which the trap reaps directly.
#
#   tmux new -s blind_ft
#   bash blind_ft_watchdog.sh            # waits for blind_cap, then trains
#   bash blind_ft_watchdog.sh --now      # skip the wait, train immediately
set -u

cd /home/eun/open-science/case_study/mura/pipeline
LOG=blind_ft_watchdog.log
MAX_RESTARTS=50
WAIT_FOR_CAPTURE=1
[ "${1:-}" = "--now" ] && WAIT_FOR_CAPTURE=0

ts() { date '+%Y-%m-%d %H:%M:%S'; }

# Single instance. Two concurrent fine-tunes would thrash the CPU and double-write
# the same checkpoints. flock holds for the life of this script.
exec 9>.blind_ft_watchdog.lock
if ! flock -n 9; then
    echo "[ft-watchdog] another ft watchdog already holds the lock — exiting" >&2
    exit 1
fi

# If terminated, kill the training subtree so nothing is left pinning the CPU.
cleanup() {
    echo "[ft-watchdog $(ts)] terminating — stopping training subtree" | tee -a "$LOG"
    pkill -TERM -f 'run_blind_finetune.sh' 2>/dev/null || true
    pkill -TERM -f 'finetune_attack_model.py' 2>/dev/null || true
    sleep 3
    pkill -9 -f 'finetune_attack_model.py' 2>/dev/null || true
    exit 0
}
trap cleanup TERM INT HUP

echo "[ft-watchdog $(ts)] start (wait_for_capture=$WAIT_FOR_CAPTURE)" | tee -a "$LOG"

# Wait for the blind capture to finish before starting, so the two do not contend
# for the host. Poll for the capture watchdog AND the daemon to both be gone.
if [ "$WAIT_FOR_CAPTURE" -eq 1 ]; then
    echo "[ft-watchdog $(ts)] waiting for blind_cap to finish..." | tee -a "$LOG"
    while pgrep -f 'blind_capture_watchdog.sh' >/dev/null 2>&1 \
          || pgrep -f 'capture_daemon.py' >/dev/null 2>&1; do
        sleep 60
    done
    echo "[ft-watchdog $(ts)] blind_cap gone — starting fine-tune" | tee -a "$LOG"
fi

# Build the BLIND valid eval set from captures/valid. captures/valid still holds
# the earlier block-given metas for indices the blind run never reached, so
# --blind-only keeps only probe-chosen (blind) samples. Written as valid_blind_*
# so the old block-given valid_* dataset is left intact for comparison. Rebuilt
# every start so late blind captures are always included; cheap next to training.
PY_ENV=/home/eun/miniforge3/envs/mura/bin/python
echo "[ft-watchdog $(ts)] building blind valid eval set (valid_blind)" | tee -a "$LOG"
for N in 16 32 64; do
    "$PY_ENV" build_attack_dataset.py --split valid --n-ref "$N" \
        --blind-only --tag valid_blind 2>&1 | tee -a "$LOG"
    if [ ! -f "datasets/valid_blind_${N}ref_slices.npy" ]; then
        echo "[ft-watchdog $(ts)] FAILED to build valid_blind_${N}ref — aborting" | tee -a "$LOG"
        exit 1
    fi
done
echo "[ft-watchdog $(ts)] blind valid eval set ready" | tee -a "$LOG"

n=0
while [ "$n" -lt "$MAX_RESTARTS" ]; do
    # Already finished?
    if [ -f mura_attack_16ref_blind_ft.done ] \
       && [ -f mura_attack_32ref_blind_ft.done ] \
       && [ -f mura_attack_64ref_blind_ft.done ]; then
        echo "[ft-watchdog $(ts)] all three models done — stopping" | tee -a "$LOG"
        break
    fi

    n=$((n + 1))
    echo "[ft-watchdog $(ts)] launching run_blind_finetune.sh (attempt $n)" | tee -a "$LOG"
    bash run_blind_finetune.sh 2>&1 | tee -a "$LOG"
    rc=${PIPESTATUS[0]}
    echo "[ft-watchdog $(ts)] run_blind_finetune.sh exited rc=$rc" | tee -a "$LOG"

    if [ "$rc" -eq 0 ]; then
        echo "[ft-watchdog $(ts)] complete" | tee -a "$LOG"
        break
    fi
    if [ "$rc" -eq 2 ]; then
        echo "[ft-watchdog $(ts)] config error (rc=2) — not retrying, fix and rerun" | tee -a "$LOG"
        break
    fi
    echo "[ft-watchdog $(ts)] restarting in 30s (resumes at first unfinished model)" | tee -a "$LOG"
    sleep 30
done

[ "$n" -ge "$MAX_RESTARTS" ] && echo "[ft-watchdog $(ts)] hit $MAX_RESTARTS restarts — giving up, check $LOG" | tee -a "$LOG"
