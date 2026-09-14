# Results Summary (Paper Ready)

All metrics are based on the MURA validation set (3,197 images).
Write-trace measurements are derived from 5 runs x 10 iterations, 411 channels
(`mura_host_regB_{1..5}.log` + `mura_guest_nomul_{1..5}_raw.log`).

---

## Table 1. Properties of Input Channels Observed via Write Traces

Empirical properties providing the foundation for the attack design.
1 channel = 224x224 float32 plane = 200,704 B = 49 pages.

| Property | Value | Implication |
|---|---|---|
| Physically fully contiguous channels | **29%** | Address-based collection misses 71% |
| Observed as 49 consecutive writes in stream (0 external writes) | **90%** | Temporal aggregation is substantially more robust |
| Write order = logical order (forward) | **75%** | Sequence order is recoverable information |
| Write order = reverse order | **24%** | Forward / Reverse hypotheses cover 99% |
| Other orderings | 1% | |
| Dominant 2MB block contains all 49 pages | **58%** | Remainder suffer partial page loss |
| Pages contained in dominant block (Median / Mean) | 49 / 45.1 | |
| End-to-end recovered pages in pipeline | **39.4 / 49 (80%)** | Reflects block loss + temporal grouping omissions |

### 2MB Block Composition (out of 512 pages, median)

| Component | Pages | Percentage |
|---|---|---|
| Target channel | 48 | 9% |
| Other channels of same image (R=G=B identical) | 81 | 16% |
| Other images | 294 | 57% |
| Non-GT (activations, etc.) | 121 | 24% |

→ Blocks are dominated by pages from other images. Which pages belong to the current inference
is undefined without write timestamps.

---

## Table 2. Search Space Reduction

Total 2MB block count = 131,072 (256 GB guest).

| Workload | Runs x Iterations | Candidate Blocks | % of Total | GT Block Mean Rank |
|---|---|---|---|---|
| MURA (vision) | 5 x 10 | **906–1,156** | 0.7–0.9% | **1.8** (4/5 runs at #1) |
| Qwen2-VL (b=1) | 3 x 3,463 | 1,159–2,348 | 0.9–1.8% | 4.7 (all top-7) |

Proportion of GT pages captured in write stream: MURA **100%**, VLM 33–97%.

---

## Table 3. Classification Accuracy (Main Results)

MURA 7-class body-part classification. Random baseline = 14.3%, majority class prior = 20.6%.
`Reassembly` degradation = 80% page recovery + 24% reverse order simulation.

| # | Method | Input | Acc | Balanced | Notes |
|---|---|---|---|---|---|
| 0 | Original model (Reference) | Aligned complete 49 pages | 80.2% | — | **Infeasible for attacker** |
| 1 | Page-set (Permutation-invariant) | Raw 512-page 2MB block | **48.6%** | 47.6% | Discards sequence order |
| 2 | Reassembly, no orientation handling | Reassembled (224, 56) | 67.2% | 66.0% | 24% reverse samples classified inverted |
| 3 | Reassembly + max-softmax orientation | " | 74.4% | 73.5% | 33% over-selection |
| 4 | **Reassembly + orientation classifier** | " | **80.0%** | **78.5%** | **Final. 26% selected (actual 24%)** |
| 5 | Reassembly + oracle orientation (Upper bound) | " | 80.1% | 78.6% | Assumes orientation known |

Orientation classifier accuracy: **97.5%** (2-class, distinguishes forward from reverse on reassembled inputs).

**Final attack accuracy of 80.0% is -0.1%p vs upper bound (80.1%) and -0.2%p vs original model (80.2%).**

---

## Table 4. Ablation — Contribution of Each Component

| Component Removed | Acc | Delta |
|---|---|---|
| Final (All components applied) | **80.0%** | — |
| − Orientation classifier (Replaced with max-softmax) | 74.4% | −5.6%p |
| − All orientation handling | 67.2% | −12.8%p |
| − Degradation fine-tuning (Using clean model) | 66.9%\* | −13.1%p |
| − Write-order reassembly (Direct 2MB block input) | 48.6% | −31.4%p |

\* Clean model + degraded input, forward only.

The largest gain comes from **write-order reassembly (+31.4%p)**, followed by **orientation handling (+12.8%p)**,
and **degradation fine-tuning (+13.1%p)**.

---

## Limitations (For Paper Disclosure)

1. **Unmodeled swap-read error.** XOR slices were computed from plaintext. Real swap-read failures/corruptions
   during PSP page moves were not modeled (unverified due to absence of Phase 0 dictionary and historical VM divergence).
2. **Missing-page mask leakage.** Page omission patterns alone predict direction with 55.6% accuracy (random: 50%).
   A portion of the 97.5% orientation discriminator accuracy may stem from this artifact.
3. **Replica assumption.** Assumes the attacker replicates the software stack to generate training data.
   Divergence in memory layout distributions between victim and replica would impact accuracy.
4. **Unknown aspect ratio.** Using the training set mean (1.339) as prior is the primary cause of the ~3%p degradation compared to ground-truth dimensions.

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
