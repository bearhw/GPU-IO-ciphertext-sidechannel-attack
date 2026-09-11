# 결과 정리 (논문용)

모든 수치는 MURA valid 3,197장 기준. write-trace 측정은 5 run × 10 iteration,
채널 411개 (mura_host_regB_{1..5}.log + mura_guest_nomul_{1..5}_raw.log).

---

## Table 1. Write-trace 로 관측되는 입력 채널의 성질

공격 설계의 근거가 되는 실측값. 채널 = 224×224 float32 한 장 = 200,704 B = 49 페이지.

| 성질 | 값 | 함의 |
|---|---|---|
| 물리적으로 완전 연속인 채널 | **29%** | 주소 기반 수집으로는 71% 를 놓친다 |
| 스트림에서 49연속 write 로 관측 (외부 write 0) | **90%** | 시간축 수집이 훨씬 강건하다 |
| write 순서 = 논리 순서 (정순) | **75%** | 순서는 복원 가능한 정보다 |
| write 순서 = 역순 | **24%** | 정순/역순 2후보로 99% 커버 |
| 그 외 순서 | 1% | |
| 지배 2MB 블록에 49페이지 전부 포함 | **58%** | 나머지는 부분 결손 |
| 지배 블록 내 페이지 수 (중앙값 / 평균) | 49 / 45.1 | |
| 파이프라인 최종 확보 페이지 | **39.4 / 49 (80%)** | 블록 결손 + 시간 그룹핑 누락 반영 |

### 2MB 블록의 구성 (512 페이지 중, 중앙값)

| 구성 | 페이지 | 비율 |
|---|---|---|
| 타깃 채널 | 48 | 9% |
| 같은 이미지의 다른 채널 (R=G=B 동일) | 81 | 16% |
| 다른 이미지 | 294 | 57% |
| 비-GT (activation 등) | 121 | 24% |

→ 블록은 다른 이미지들로 지배된다. 어느 것이 현재 추론 대상인지는
   write 타임스탬프 없이는 정의되지 않는다.

---

## Table 2. 탐색 공간 축소

전체 2MB 블록 수 = 131,072 (256 GB guest).

| Workload | runs × iterations | 후보 블록 | 전체 대비 | GT 블록 평균 rank |
|---|---|---|---|---|
| MURA (vision) | 5 × 10 | **906–1,156** | 0.7–0.9% | **1.8** (4/5 runs 가 #1) |
| Qwen2-VL (b=1) | 3 × 3,463 | 1,159–2,348 | 0.9–1.8% | 4.7 (전부 top-7) |

GT 페이지가 write 스트림에 포착된 비율: MURA **100%**, VLM 33–97%.

---

## Table 3. 분류 정확도 (본 결과)

MURA 7-class 신체 부위. 랜덤 = 14.3%, 다수 클래스 prior = 20.6%.
`재조립` 열화 = 페이지 80% 확보 + 역순 24% 시뮬레이션.

| # | 방법 | 입력 | acc | balanced | 비고 |
|---|---|---|---|---|---|
| 0 | 원본 모델 (참조) | 정렬된 완전한 49페이지 | 80.2% | — | **공격자가 만들 수 없음** |
| 1 | Page-set (순열 불변) | 2MB 블록 512페이지 통째 | **48.6%** | 47.6% | 순서 정보를 버림 |
| 2 | 재조립, 방향 처리 없음 | 재조립 (224,56) | 67.2% | 66.0% | 역순 24% 가 뒤집힌 채 분류 |
| 3 | 재조립 + max-softmax 방향 | " | 74.4% | 73.5% | 33% 과다 채택 |
| 4 | **재조립 + 방향 판별기** | " | **80.0%** | **78.5%** | **최종. 26% 채택 (실제 24%)** |
| 5 | 재조립 + oracle 방향 (상한) | " | 80.1% | 78.6% | 방향을 안다고 가정 |

방향 판별기 정확도: **97.5%** (2-class, 재조립 입력에서 정순/역순 판별).

**최종 공격 성능 80.0% 는 상한(80.1%) 대비 −0.1%p, 원본 모델(80.2%) 대비 −0.2%p.**

---

## Table 4. Ablation — 각 요소의 기여

| 제거한 요소 | acc | 손실 |
|---|---|---|
| 최종 (전부 적용) | **80.0%** | — |
| − 방향 판별기 (max-softmax 로 대체) | 74.4% | −5.6%p |
| − 방향 처리 전체 | 67.2% | −12.8%p |
| − 열화 fine-tune (clean 모델 사용) | 66.9%\* | −13.1%p |
| − write 순서 재조립 (2MB 블록 직접 입력) | 48.6% | −31.4%p |

\* clean 모델 + 열화 입력, 정순 기준.

가장 큰 기여는 **write 순서 재조립(+31.4%p)**, 다음이 **방향 처리(+12.8%p)**,
그 다음이 **열화 fine-tune(+13.1%p)** 이다.

---

## 한계 (명시 필요)

1. **swap-read 오차 미반영.** xor slice 를 평문에서 정확히 계산했다. 실제
   PSP page-move 기반 swap-read 의 실패·오염은 모델링하지 않았다.
   (Phase 0 사전 부재 + 로그 시점과 VM 메모리 상태 불일치로 미검증)
2. **결손 마스크 누수.** 페이지 결손 패턴만으로 방향이 55.6% 예측 가능하다
   (랜덤 50%). 방향 판별기 97.5% 중 일부가 이 인공물 덕일 수 있다.
3. **replica 가정.** 학습 데이터는 공격자가 동일 스택을 복제해 생성한다고
   가정한다. 피해자와 replica 의 메모리 배치 분포가 다르면 성능이 달라진다.
   (양쪽 write 트레이스 통계 대조로 검증 가능하나 미수행)
4. **종횡비 미상.** 공격자는 원본 종횡비를 모르므로 학습셋 평균(1.339)을
   prior 로 사용했다. 이것이 원본 대비 약 3%p 손실의 주된 원인이다.

---

## LaTeX

```latex
% Table 3
\begin{table}[t]
\centering
\caption{MURA body-part classification from write traces (valid $n{=}3{,}197$;
random $14.3\%$). Reassembly inputs have $80\%$ of pages recovered and
$24\%$ reverse-ordered, both measured from real traces.}
\label{tab:mura-acc}
\begin{tabular}{llcc}
\toprule
& Method & Acc. & Bal. acc. \\
\midrule
\multicolumn{4}{l}{\emph{Reference (not attacker-achievable)}} \\
0 & Original model, ordered complete pages & 80.2\% & --- \\
\midrule
\multicolumn{4}{l}{\emph{Attacker-achievable}} \\
1 & Page-set model on the raw 2\,MB block   & 48.6\% & 47.6\% \\
2 & Reassembly, no orientation handling     & 67.2\% & 66.0\% \\
3 & Reassembly + max-softmax orientation    & 74.4\% & 73.5\% \\
4 & \textbf{Reassembly + orientation classifier} & \textbf{80.0\%} & \textbf{78.5\%} \\
\midrule
5 & Reassembly + oracle orientation (upper bd.) & 80.1\% & 78.6\% \\
\bottomrule
\end{tabular}
\end{table}

% Table 1
\begin{table}[t]
\centering
\caption{Properties of the victim's input-channel writes, measured over
411 channels (5 runs $\times$ 10 iterations). A channel is
$224{\times}224$ float32 $=$ 49 pages.}
\label{tab:trace-props}
\begin{tabular}{lc}
\toprule
Property & Value \\
\midrule
Physically contiguous (single run of pages)      & 29\% \\
Emitted as 49 consecutive writes (0 interleaved) & 90\% \\
Write order $=$ logical order (forward)          & 75\% \\
Write order $=$ reversed                          & 24\% \\
All 49 pages inside the dominant 2\,MB block     & 58\% \\
Pages recovered end-to-end                        & 39.4 / 49 \\
\bottomrule
\end{tabular}
\end{table}
```
