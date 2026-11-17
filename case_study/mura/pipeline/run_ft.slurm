#!/bin/bash
#SBATCH --job-name=mura_blind_ft
#SBATCH --output=mura_ft_%j.out
#SBATCH --error=mura_ft_%j.out
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8
#SBATCH --gres=gpu:1
#SBATCH --time=08:00:00
# --- 아래 3개는 네 클러스터 값으로 확인해서 채워 (나머지는 그대로 둬도 됨) ---
#SBATCH --partition=a100_normal_q      # sinfo -s 로 GPU 파티션 이름 확인
#SBATCH --account=YOUR_ALLOC           # sacctmgr -n show assoc user=esp format=account 로 확인
# ---------------------------------------------------------------------------
set -euo pipefail

cd /home/esp/mura_ft

# 파이썬/torch 환경 활성화 — 클러스터에 맞게 둘 중 하나만 남겨:
#  (a) ARC가 제공하는 모듈
module load Anaconda3 2>/dev/null || module load anaconda3 2>/dev/null || true
#  (b) 개인 conda 환경이 있으면
# source ~/miniconda3/etc/profile.d/conda.sh && conda activate mura

PY=${PY:-python3}
echo "host: $(hostname)  gpu:"; nvidia-smi -L || true
$PY -c "import torch; print('torch', torch.__version__, 'cuda', torch.cuda.is_available())"

# train 셋으로 재파인튜닝 (blind shift 분포로 augment).
# 체크포인트 선택(best val macro)은 train 의 1/10 홀드아웃으로 — valid_blind 불필요.
# (홀드아웃은 환자 겹침이 있어 과대평가되지만, 어느 에폭을 저장할지 고르는 용도로만 씀.
#  진짜 blind 정확도는 캡처 끝난 뒤 완성된 valid_blind 로 따로 측정.)
# --ckpt 를 명시해서 디렉토리 구조 의존성 제거.
declare -A CKPT=( [16]=mura_xor_slice_16ref.pth [32]=mura_xor_slice_32ref.pth [64]=mura_xor_slice_64ref_v2.pth )

for N in 16 32 64; do
    echo "=================== Dict-$N  ($(date +%H:%M:%S)) ==================="
    $PY finetune_attack_model.py \
        --n-ref "$N" \
        --ckpt "${CKPT[$N]}" \
        --train-split train --holdout-split --every 10 \
        --balance --epochs 30 \
        --shift-dist datasets/blind_shift_dist.json \
        --out "mura_attack_${N}ref_blind_ft.pth" \
        --log "finetune_blind_${N}ref_${SLURM_JOB_ID:-local}.log"
    echo "Dict-$N done -> mura_attack_${N}ref_blind_ft.pth + _history.json + _curve.png"
done

echo "ALL DONE ($(date +%H:%M:%S))"
