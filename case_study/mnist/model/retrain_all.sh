#!/usr/bin/env bash
# retrain_all.sh — Retrain v6r encoder, its retrieval DB, v9r, and v10 on REAL
# end-to-end attack captures, in dependency order.
#
#   v6r encoder ──> rebuild retrieval DB
#               └─> v10 decoder (reuses the frozen encoder)
#   v9r (independent)
#
# IMPORTANT: stage5 loads the *_new.pth weights with priority, but the training
# scripts save to the non-"_new" names. So after each train we copy the result onto
# the *_new.pth name that stage5 actually reads. Originals are backed up once into
# pretrain_backup/ so everything can be reverted.
#
# No guest needed. Train captures must already exist:
#   sudo python3 ../pipeline/capture_campaign.py --split train --start 0 --end 40
#
# Usage:
#   ./retrain_all.sh                                   # all four
#   ONLY=v10 ./retrain_all.sh                          # skip to v10 (encoder/DB unchanged)
#   CAPTURE_DIR=/abs/results ./retrain_all.sh
set -euo pipefail
cd "$(dirname "$(readlink -f "$0")")"                  # model/

CAPTURE_DIR="${CAPTURE_DIR:-$(readlink -f ../pipeline/output_train/results)}"
export CAPTURE_DIR MNIST_SPLIT=train
ONLY="${ONLY:-all}"
BK=pretrain_backup

if ! ls "$CAPTURE_DIR"/sparsities_*_bs512_idx*.npy >/dev/null 2>&1; then
    echo "[retrain] no train captures in $CAPTURE_DIR"
    echo "[retrain] run:  sudo python3 ../pipeline/capture_campaign.py --split train --start 0 --end 40"
    exit 1
fi

mkdir -p "$BK"
backup() { for f in "$@"; do [[ -f "$f" && ! -f "$BK/$f" ]] && cp -v "$f" "$BK/$f" || true; done; }
promote() {  # promote <trained.pth> <stage5_new.pth>
    cp -v "$1" "$2"
}

echo "[retrain] CAPTURE_DIR=$CAPTURE_DIR | captures: $(ls "$CAPTURE_DIR"/sparsities_*_bs512_idx*.npy | wc -l)"
backup sparsity_encoder_v6r.pth sparsity_encoder_v6r_new.pth \
       v6r_embeddings_new.npy v6r_images_new.npy \
       unet_gan_generator_v9r.pth unet_gan_generator_v9r_new.pth \
       v10_decoder.pth v10_decoder_new.pth

run_v6r() {
    echo "=== [1/4] v6r encoder ==="
    python3 train_v6r.py
    promote sparsity_encoder_v6r.pth sparsity_encoder_v6r_new.pth
    echo "=== [2/4] rebuild v6r retrieval DB ==="
    python3 build_v6r_db.py --encoder sparsity_encoder_v6r.pth
}
run_v9r() {
    echo "=== [3/4] v9r UNet-GAN ==="
    python3 train_v9r.py
    promote unet_gan_generator_v9r.pth unet_gan_generator_v9r_new.pth
}
run_v10() {
    echo "=== [4/4] v10 decoder (frozen new encoder) ==="
    python3 train_v10.py
    promote v10_decoder.pth v10_decoder_new.pth
}

case "$ONLY" in
    all) run_v6r; run_v9r; run_v10 ;;
    v6r) run_v6r ;;
    v9r) run_v9r ;;
    v10) run_v10 ;;
    *) echo "[retrain] unknown ONLY=$ONLY (use all|v6r|v9r|v10)"; exit 1 ;;
esac

echo "[retrain] done. stage5 will now load the retrained *_new.pth weights."
echo "[retrain] originals preserved in $BK/ (revert: cp $BK/<f> <f>)."
