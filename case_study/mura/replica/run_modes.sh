#!/bin/bash
source ~/miniforge3/etc/profile.d/conda.sh 2>/dev/null || source ~/miniconda3/etc/profile.d/conda.sh
conda activate mura
cd ~/replica_pageset
export MURA_CACHE=/home/ubuntu/xor_cache_64
export MURA_DATA=/home/ubuntu/mura/mura_downloads
for M in none oracle softmax model; do
  echo "########## order=$M ##########"
  python -u eval_reassembly.py --ckpt reassembly_64ref.pth --order "$M" \
    --direction-ckpt direction_64ref.pth --out "cm_order_$M"
  echo
done
echo "ALL DONE"
