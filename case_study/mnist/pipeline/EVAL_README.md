# MNIST 블라인드 end-to-end 재학습/평가 실행 순서

목표: 실제 공격 캡처 분포로 v10 디코더를 재학습하고, 모델이 한 번도 안 본
**test 셋**으로 블라인드 SSIM을 측정한다. (SSIM이 ~0.4에 묶인 건 학습=합성 /
평가=실제 캡처의 분포 불일치 때문. 둘 다 실제 캡처로 맞추면 풀린다.)

핵심 스위치: `MNIST_SPLIT` (train | test). 게스트(main.py)와 호스트(stage5)가
같이 보고, stage2가 SSH로 게스트에 전달한다. 모든 러너가 알아서 세팅한다.

---

## 1. train 캡처  (게스트 필요)
```bash
cd /home/eun/open-science/case_study/mnist/pipeline
sudo python3 capture_campaign.py --split train --start 0 --end 40
```
- bs=512 × 41 블록 = 20,992장 (train 이미지), `output_train/results/`에 저장
- 끊기면 같은 명령 재실행 (`--skip-existing` 기본), 다시 뜨려면 `--redo`
- 많을수록 좋음. 디코더 재학습엔 최소 20~40 블록(1만~2만장) 권장

## 2. 재학습  (게스트 불필요) — v6r → DB → v9r → v10 순서
```bash
cd /home/eun/open-science/case_study/mnist/model
./retrain_all.sh
```
- `output_train/results`의 모든 `sparsities_*_bs512_idx*.npy`를 실제 입력으로 학습
- 순서가 중요: **v6r 인코더 → retrieval DB 재생성 → v9r → v10**(v10은 frozen v6r 인코더에 의존)
- stage5는 `*_new.pth`를 우선 로드하므로, 학습 후 자동으로 `_new.pth`로 복사(promote)됨
- 원본은 `pretrain_backup/`에 1회 백업 (되돌리기: `cp pretrain_backup/<f> <f>`)
- v10만: `ONLY=v10 ./retrain_all.sh` / 다른 캡처 디렉토리: `CAPTURE_DIR=/abs/results ./retrain_all.sh`

모델별 역할:
- **v10**(decoder) = 헤드라인. v6r 인코더 재학습 후 돌려야 효과 최대
- **v6r**(encoder+retrieval) = v10이 쓰는 인코더. retrieval DB는 train 6만장이라 test eval에선 최근접 train 이미지만 반환(구조적 상한)
- **v9r**(UNet-GAN) = 독립, 현재 최악. 같은 버그 수정됨

## 3. eval 캡처  (게스트 필요)
```bash
cd /home/eun/open-science/case_study/mnist/pipeline
sudo python3 capture_campaign.py --split eval --start 0 --end 18
```
- bs=512 × 19 블록 = 9,728장 (test 이미지, 모델이 안 본 셋). test는 1만장이라 batch 18이 최대
- `output_eval/results/`에 저장

## 4. 테스트 (재구성 + SSIM 집계)  (게스트 불필요)
```bash
cd /home/eun/open-science/case_study/mnist/pipeline
python3 run_test.py
```
- 재학습된 `v10_decoder.pth`로 eval 캡처를 재구성해서 test 셋 GT와 SSIM
- 출력: 모델별 **배치간 mean±std** + **이미지 풀링 mean(n)**
- 재구성 없이 기존 metrics만 집계: `python3 run_test.py --no-recon`

---

## 바뀐 것 (이번 준비)
- `model/main.py`, `main_holder.py`, `main_holder_norm.py`, `main_gpa_3.py`:
  게스트 추론 split을 `MNIST_SPLIT`로 (기본 test)
- `pipeline/stage5_reconstruct.py`: GT 로더 3개 전부 `MNIST_SPLIT` 반영 (t10k 기본)
- `pipeline/stage2_track_gpa.py`: `sudo env MNIST_SPLIT=...`로 게스트에 split 전달
- `model/capture_data.py` (신규): v6r/v9r/v10 공통 로더. bs=512 캡처 `.npy` → (real_sp, GT) 페어, 없으면 legacy 폴백
- `model/train_v6r.py`, `train_v9r.py`, `train_v10.py`: 학습 입력을 `augment_sparsity(clean)` → **실제 `real_sp`** (v6r는 대조학습 유지, real↔clean 뷰)
- 새 러너: `pipeline/capture_campaign.py`, `model/retrain_all.sh`, `model/build_v6r_db.py`, `pipeline/run_test.py`

## 선결 과제 (주의)
기존 캡처 3개가 같은 이미지인데 density 0.32/0.77/0.99로 요동 → **캡처 신뢰성
문제**(z.out 주소 유효성 / 관측률)가 있음. 이걸 안 고치면 train 캡처에 노이즈가
섞여 재학습 효과가 제한된다. 캡처 품질을 density로 먼저 확인할 것
(정상 MNIST sparsity density ≈ 0.2~0.35). 0.7+ 블록이 많으면 캡처부터 손봐야 함.
