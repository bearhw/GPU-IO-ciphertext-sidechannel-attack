#!/usr/bin/env bash
# run_blind_finetune.sh — Re-fine-tune all three models for the BLIND attack.
#
# Same train captures as before (block-given, 94.4% recovery) but augmented with
# the *blind* page-shift distribution (P(|k|>=4)=0.46 vs the block-given <=3),
# so the models learn the larger shifts the blind attack actually produces.
#
# Evaluation uses the BLIND-recaptured valid set (datasets/valid_blind_*), which
# blind_ft_watchdog.sh builds from captures/valid with --blind-only before calling
# this. If that dataset is missing, build it first:
#     python build_attack_dataset.py --split valid --n-ref N --blind-only --tag valid_blind
#
# RESUMABLE: each model writes mura_attack_${N}ref_blind_ft.done when all its
# epochs finish. A re-run (after a crash/reboot) skips models already marked done,
# so the watchdog can restart this without redoing completed models. This is meant
# to be driven by blind_ft_watchdog.sh, not run bare.
set -u

cd /home/eun/open-science/case_study/mura/pipeline
PY=/home/eun/miniforge3/envs/mura/bin/python
DIST=datasets/blind_shift_dist.json
STAMP=$(date +%Y%m%d-%H%M%S)

if [ ! -f "$DIST" ]; then
    echo "[!] $DIST missing — regenerate the blind shift distribution first" >&2
    exit 2
fi

for N in 16 32 64; do
    DONE="mura_attack_${N}ref_blind_ft.done"
    if [ -f "$DONE" ]; then
        echo "=== Dict-$N already done ($DONE present) — skipping ==="
        continue
    fi
    echo "=================================================================="
    echo "  Dict-$N  blind re-fine-tune   ($(date '+%H:%M:%S'))"
    echo "=================================================================="
    # Train data is datasets/train_${N}ref_slices.npy (block-given train-split
    # captures); eval is the BLIND-recaptured valid set, unseen by the checkpoint.
    EVAL=valid_blind
    if [ ! -f "datasets/${EVAL}_${N}ref_slices.npy" ]; then
        echo "[!] datasets/${EVAL}_${N}ref_slices.npy missing — build it first" >&2
        echo "    python build_attack_dataset.py --split valid --n-ref $N --blind-only --tag valid_blind" >&2
        exit 2
    fi
    "$PY" -u finetune_attack_model.py \
        --n-ref "$N" \
        --train-split train --eval-split "$EVAL" \
        --balance --epochs 30 \
        --shift-dist "$DIST" \
        --out "mura_attack_${N}ref_blind_ft.pth" \
        --log "finetune_blind_${N}ref_${STAMP}.log"
    rc=$?
    if [ "$rc" -ne 0 ]; then
        echo "[!] Dict-$N exited rc=$rc — NOT marking done; watchdog will retry" >&2
        exit "$rc"
    fi
    touch "$DONE"
    echo "  Dict-$N done -> mura_attack_${N}ref_blind_ft.pth (.done written)"
    echo
done

echo "ALL BLIND FINE-TUNES COMPLETE ($(date '+%H:%M:%S'))"
echo "models:  mura_attack_{16,32,64}ref_blind_ft.pth"
echo "curves:  mura_attack_{16,32,64}ref_blind_ft_curve.png"
echo "history: mura_attack_{16,32,64}ref_blind_ft_history.json"
