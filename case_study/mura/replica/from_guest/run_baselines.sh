#!/bin/bash
source ~/miniforge3/etc/profile.d/conda.sh 2>/dev/null || source ~/miniconda3/etc/profile.d/conda.sh
conda activate mura
cd ~/replica_pageset
export MURA_CACHE=/home/ubuntu/xor_cache_64
export MURA_DATA=/home/ubuntu/mura/mura_downloads
CK=/home/ubuntu/cc_uvm/pytorch_uvm310_test/mura/mura_xor_slice_64ref.pth
echo "########## A) Upper bound: No degradation ##########"
python -u eval_reassembly.py --ckpt "$CK" --no-degrade --no-order-search --out cm_A_ideal
echo; echo "########## B) Degradation applied, forward only ##########"
python -u eval_reassembly.py --ckpt "$CK" --no-order-search --out cm_B_degraded_fwd
echo; echo "########## C) Degradation applied + forward/reverse search ##########"
python -u eval_reassembly.py --ckpt "$CK" --out cm_C_degraded_search
