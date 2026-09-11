# MNIST End-to-End Modular Attack Pipeline

SEV-SNP 환경에서 MNIST 워크로드의 암호화 메모리를 사이드채널로 분석/복원하는 5단계 모듈형 공격 파이프라인입니다. 각 단계는 독립적인 CLI 스크립트로 동작하며, JSON 캐시와 표준 입출력을 통해 결합됩니다. `master_orchestrate.py`를 통해 전체 또는 일부 단계를 자동화할 수 있습니다.

---

## 1. 아키텍처 및 파이프라인 단계

```
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 1: Zero GPA Acquisition (stage1_zero_gpa.py)                     │
│  - 게스트 ICMP 커널 모듈(/proc/large_icmp_last)로부터 클린 Zero GPA 획득 │
│  - read_gpa.py를 통해 z.out 덤프 및 zero_gpa.json 저장                   │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 2: Target Image GPA Tracking (stage2_track_gpa.py)               │
│  - 게스트 프로세스로부터 Ground Truth GPA 획득                          │
│  - write_pattern_tracker 기반 Region-B Precursor 블라인드 분석         │
│  - 블라인드 미검출 시 Ground Truth로 안전 자동 전환                       │
│  - Page 2 GPA 연산 및 tracked_target_{index}.json 저장                 │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 3: PSP Page Swap & Dump (stage3_swap_dump.py)                    │
│  - swap_and_dump.py로 Page 1 & Page 2 ↔ Zero Page 스왑 덤프            │
│  - --swap-back으로 게스트 메모리 안전 복원                              │
│  - {label}-{index}.out, {label}-{index}_p2.out, swap_meta_{index}.json │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 4: Sparsity Feature Extraction (stage4_extract_features.py)      │
│  - z.out 및 덤프 파일 비교                                             │
│  - PyTorch 64B 정렬 + 공간 구조/Center-of-Mass 기반 in-page 오프셋 탐지 │
│  - 196-dim Sparsity Vector 추출: {label}-{index}.out_v5.list           │
└───────────────────────────────────┬────────────────────────────────────┘
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│ Stage 5: Multi-Model Reconstruction & Comparison (stage5_reconstruct.py)│
│  - v6r (Embedding Retrieval), v9r (UNet-GAN), v10 (V10Decoder) 동시 복원│
│  - MNIST Ground Truth 대조 SSIM, PSNR, L1 Error 계산                    │
│  - comparison_{index}.png 및 SSIM 비교 테이블 출력                      │
└────────────────────────────────────────────────────────────────────────┘
```

---

## 2. 파일 구성

| 파일명 | 역할 |
|---|---|
| `common.py` | 공통 설정, SSH 연결, 경로 상수, SSIM/PSNR 메트릭 연산 |
| `stage1_zero_gpa.py` | [Stage 1] Zero Page GPA 획득 및 `z.out` 덤프 |
| `stage2_track_gpa.py` | [Stage 2] `write_pattern_tracker` 블라인드 추적 및 GT 획득 |
| `stage3_swap_dump.py` | [Stage 3] PSP 기반 Page 1 & 2 스왑 덤프 |
| `stage4_extract_features.py` | [Stage 4] 오프셋 추론 및 196-dim Sparsity Vector 추출 |
| `stage5_reconstruct.py` | [Stage 5] v6r, v9r, v10 다중 모델 복원 및 SSIM 비교표 |
| `master_orchestrate.py` | Stage 1~5 통합 제어, 단계별 선택 실행, 배치 처리 |

---

## 3. 사용법 (Usage Examples)

### (1) Master Orchestrator로 End-to-End 전체 실행
```bash
# 단일 샘플 전체 실행 (Stage 1~5)
sudo python3 master_orchestrate.py --index 30

# 블라인드 write-tracker 모드로 실행
sudo python3 master_orchestrate.py --index 30 --blind

# 배치 모드 실행 (Sample 0 ~ 10)
sudo python3 master_orchestrate.py --start 0 --end 10 --skip-existing
```

### (2) 특정 단계(Stage)만 선택 실행
```bash
# Stage 4(Feature 추출)부터 Stage 5(복원)까지만 실행
python3 master_orchestrate.py --from-stage 4 --to-stage 5 --index 1000

# Stage 5(이미지 복원 & SSIM 테이블)만 단독 배치 실행
python3 master_orchestrate.py --stage 5 --start 1000 --end 1010
```

### (3) 개별 모듈 단독 실행
```bash
# Stage 1 단독: Zero Page 획득
sudo python3 stage1_zero_gpa.py --output-dir .

# Stage 2 단독: Target GPA 추적
sudo python3 stage2_track_gpa.py --index 30 --blind

# Stage 3 단독: PSP 스왑 덤프
sudo python3 stage3_swap_dump.py --index 30

# Stage 4 단독: Sparsity 추출 (오프셋 자동 추론)
python3 stage4_extract_features.py --index 30

# Stage 5 단독: v6r / v9r / v10 복원 및 SSIM 비교
python3 stage5_reconstruct.py --index 30
```

---

## 4. 산출물 명세

- `zero_gpa.json` & `z.out`: Zero Page GPA 및 덤프
- `tracked_target_{index}.json`: 추적된 Page 1 / Page 2 GPA 및 블라인드 후보
- `{label}-{index}.out` & `{label}-{index}_p2.out`: 4KB 메모리 덤프
- `swap_meta_{index}.json`: 스왑 실행 메타데이터
- `{label}-{index}.out_v5.list` & `features_{index}.json`: 196-dim Sparsity 벡터 및 인-페이지 오프셋 정보
- `recon_{index}_v6r.png`, `recon_{index}_v9r.png`, `recon_{index}_v10.png`: 모델별 28×28 복원 이미지
- `comparison_{index}.png`: Ground Truth 및 3개 모델 복원 비교 시각화
- `metrics_{index}.json`: 모델별 SSIM, PSNR, L1 Error 수치
