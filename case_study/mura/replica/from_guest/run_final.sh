#!/bin/bash
source ~/miniforge3/etc/profile.d/conda.sh 2>/dev/null || source ~/miniconda3/etc/profile.d/conda.sh
conda activate mura
cd ~/replica_pageset
export MURA_CACHE=/home/ubuntu/xor_cache_64
export MURA_DATA=/home/ubuntu/mura/mura_downloads
echo "########## D) Fine-tuned model, degradation applied, forward only ##########"
python -u eval_reassembly.py --ckpt reassembly_64ref.pth --no-order-search --out cm_D_ft_fwd
echo; echo "########## E) Fine-tuned model + forward/reverse search ##########"
python -u eval_reassembly.py --ckpt reassembly_64ref.pth --out cm_E_ft_search
