#!/bin/bash
# v2 학습 종료를 기다렸다가 confusion matrix 생성
while pgrep -f "train_pageset.py --epochs 60" > /dev/null; do sleep 120; done
source ~/miniforge3/etc/profile.d/conda.sh 2>/dev/null || source ~/miniconda3/etc/profile.d/conda.sh
conda activate mura
cd ~/replica_pageset
export MURA_CACHE=/home/ubuntu/xor_cache_64
export MURA_DATA=/home/ubuntu/mura/mura_downloads
python -u eval_confusion.py --ckpt pageset_64ref.pth --batch 32 --workers 2
