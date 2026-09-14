#!/bin/bash
# Wait for v2 training to finish then generate confusion matrix
while pgrep -f "train_pageset.py --epochs 60" > /dev/null; do sleep 120; done
source ~/miniforge3/etc/profile.d/conda.sh 2>/dev/null || source ~/miniconda3/etc/profile.d/conda.sh
conda activate mura
cd ~/replica_pageset
export MURA_CACHE=/home/ubuntu/xor_cache_64
export MURA_DATA=/home/ubuntu/mura/mura_downloads
python -u eval_confusion.py --ckpt pageset_64ref.pth --batch 32 --workers 2
