#!/bin/bash
source ~/miniforge3/etc/profile.d/conda.sh 2>/dev/null || source ~/miniconda3/etc/profile.d/conda.sh
conda activate mura
cd ~/replica_pageset
export MURA_CACHE=/home/ubuntu/xor_cache_64
export MURA_DATA=/home/ubuntu/mura/mura_downloads
python -u train_reassembly.py \
  --init /home/ubuntu/cc_uvm/pytorch_uvm310_test/mura/mura_xor_slice_64ref.pth \
  --epochs 12 --batch 32 --workers 1 --lr 1e-4
