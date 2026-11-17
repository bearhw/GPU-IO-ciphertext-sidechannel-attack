#!/bin/bash
#SBATCH --job-name=mura_ft_ff
#SBATCH --output=mura_ft_ff_%j.out
#SBATCH --error=mura_ft_ff_%j.out
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8
#SBATCH --gres=gpu:1
#SBATCH --time=08:00:00
# partition/account 는 run_blind_ft.slurm 에서 쓴 값을 sbatch -p / -A 로 넘김.
set -euo pipefail

cd /home/esp/mura_ft

module load Anaconda3 2>/dev/null || module load anaconda3 2>/dev/null || true
PY=${PY:-python3}
echo "host: $(hostname)  gpu:"; nvidia-smi -L || true
$PY -c "import torch; print('torch', torch.__version__, 'cuda', torch.cuda.is_available())"

# blind shift 분포 + foreign fill: shift로 밀려 들어온 페이지를 0이 아니라
# 다른 train 샘플의 인접 페이지로 채움 (blind 캡처에서 실제로 관측된 형태).
# 기존 _blind_ft 모델을 덮어쓰지 않도록 출력 이름은 _blind_ff.
declare -A CKPT=( [16]=mura_xor_slice_16ref.pth [32]=mura_xor_slice_32ref.pth [64]=mura_xor_slice_64ref_v2.pth )

for N in 16 32 64; do
    echo "=================== Dict-$N  ($(date +%H:%M:%S)) ==================="
    $PY finetune_attack_model.py \
        --n-ref "$N" \
        --ckpt "${CKPT[$N]}" \
        --train-split train --holdout-split --every 10 \
        --balance --epochs 30 \
        --shift-dist datasets/blind_shift_dist.json \
        --foreign-fill 0.9 \
        --out "mura_attack_${N}ref_blind_ff.pth" \
        --log "finetune_ff_${N}ref_${SLURM_JOB_ID:-local}.log"
    echo "Dict-$N done -> mura_attack_${N}ref_blind_ff.pth + _history.json + _curve.png"
done

echo "ALL DONE ($(date +%H:%M:%S))"
