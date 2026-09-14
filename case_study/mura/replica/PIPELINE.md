# Attack Pipeline (MURA Vision Workload)

A host-side attacker observing only the write fault traces of an SEV-SNP guest
identifies the body part in the X-ray being inferred by the victim.

Empirical basis: 5 runs x 10 iterations, 411 channels
(`mura_host_regB_{1..5}.log` + `mura_guest_nomul_{1..5}_raw.log`).
Classification benchmark: MURA valid (3,197 images).

---

## Overall Workflow

```
 [1] Write Tracker
      │  GPA + timestamp stream (3M - 5M writes per run)
      ▼
 [2] 2MB Block Ranking        S(b) = H(b) · R(b)
      │  131,072 → 906–1,156 candidates, GT block mean rank 1.8
      ▼
 [3] Stream Filtering to Top-K + Adjacent Blocks (±1)
      │  K=10 → 22–30 allowed blocks
      ▼
 [4] Temporal Contiguous Segments → 49-Page Candidates
      │  600–3,300 candidates (precision 0.03–0.16, recall 0.32–0.48)
      ▼
 [5] 1-Page Probe (swap-read + 64-ref matching)          ← Cost reduction
      │  Only passing candidates proceed (~10x reduction)
      ▼
 [6] 49-Page Swap-Read → Write-Order Concatenation
      │  Ignore physical addresses. Temporal order is logical order.
      ▼
 [7] 64-Ref XOR Slice Construction → (64, 224, 56)
      ▼
 [8] Direction Discriminator (Forward/Reverse) → Flip if needed
      │  Accuracy 97.5%
      ▼
 [9] Body-Part Classification Model
         accuracy 80.0%  /  balanced 78.5%
```

---

## Stage-by-Stage Rationale and Empirical Data

### [2] 2MB Block Ranking

H(b) = number of finalized contiguous runs in block b, R(b) = longest run length (in pages).

| Metric | Value |
|---|---|
| Total 2MB blocks | 131,072 (256 GB guest) |
| Candidate blocks | 906–1,156 (0.7–0.9%) |
| GT block mean rank | **1.8** (4 out of 5 runs at #1, remainder at #5) |
| GT pages captured in write stream | **100%** |

### [3]–[4] 49-Page Candidates from Temporal Contiguous Segments

**Key insight: Aggregate by timestamps, not physical addresses.**

| Metric | Value |
|---|---|
| Channel 49 pages fully physically contiguous | 28% |
| Channel 49 pages appear as 49 consecutive writes in stream (0 external writes) | **90%** |
| Dominant 2MB block contains all 49 pages | 58% |
| Number of blocks spanned per channel | 1 block 58% / 2 blocks 31% / 3 blocks 9% |

Because 42% of channels span across block boundaries, **adjacent blocks (±1) must be included**.
Omitting adjacent blocks causes recall to collapse to 0.05.

| K | Recall | Precision | Candidate Count | Required Swap-Reads (Without Probe) |
|---|---|---|---|---|
| 10 | 0.09–0.51 (mean 0.32) | 0.03–0.16 | 622–1,256 | 30k–60k |
| 30 | 0.25–0.73 (mean 0.48) | 0.03–0.10 | 1,275–3,340 | 60k–160k |

Recall is 0.3–0.5 due to slight offsets between segment boundaries and burst starting points.
**Each inference has a 30–50% capture probability**. Since MURA processes 25–30 images per run,
observing multiple inferences yields a cumulative success rate converging to 1.

### [5] 1-Page Probe

90% of candidates are not images. Reading all 49 pages for every candidate multiplies cost by 10x.
Swap-reading a single representative page and checking if any 16-byte offset matches the 64-ref dictionary
(`mura_block_triage.py:probe_page`, early-exit on first match) filters out non-image candidates.

Each reference is a 16-byte chunk repeating 4 bytes of `float32(u8/255)` four times. Real image pages
always contain uniform pixel areas (background) triggering matches, whereas the probability of activations
or weights matching that exact pattern at that location is practically zero.

### [6] Write-Order Reassembly

**Ignoring** physical addresses, concatenate 4096-byte blocks sequentially as they appear in the stream.
200,704 bytes = raw float32 array of the channel.

| Write Order vs Logical Order | Proportion |
|---|---|
| Forward | **75%** |
| Reverse | **24%** |
| Other | 1% |

→ Considering only two hypotheses covers 99% of cases.

### [8] Direction Discriminator

Selecting direction via max-softmax fails (over-selects reverse at 33% → -5.6%p penalty).
A dedicated 2-class classifier is trained specifically to distinguish forward from reverse.

| Metric | Value |
|---|---|
| Direction discrimination accuracy | **97.5%** |
| Un-reverse selection rate | 26% (actual: 24%) |

### [9] Classification Model

Input shape: (64, 224, 56). Using the original `XorSliceResNet` architecture,
fine-tune on degraded reassembly inputs (with ~80% page retention).
Since the attacker does not know the true aspect ratio, the training set mean (1.339) is used as a prior.

---

## Final Performance

| Method | Acc | Balanced |
|---|---|---|
| Original model (Clean aligned input, **infeasible for attacker**) | 80.2% | — |
| Full 2MB block input, permutation-invariant model | 48.6% | 47.6% |
| Reassembly, no direction handling | 67.2% | 66.0% |
| Reassembly + max-softmax direction | 74.4% | 73.5% |
| **Reassembly + direction discriminator (Final)** | **80.0%** | **78.5%** |
| Reassembly + oracle direction (Upper bound) | 80.1% | 78.6% |

Random baseline: 14.3%, majority class prior: 20.6%.

---

## Why Content Probe [5] is Essential

We attempted 8 different strategies to isolate image channels using write metadata (GPA + timestamp) alone,
and all of them failed. In the write trace, image sweeps and background memcpy operations are structurally indistinguishable.

| Strategy | Precision |
|---|---|
| Physically contiguous run length | 0.03–0.11 |
| Per-page write count | ≤0.03 |
| Region-B precursor | Ineffective (1,579x channel noise) |
| Multiples of 49 segment length | Recall ~0 |
| Cadence CV ranking | GT median rank #872–#9,871 |
| Block + temporal episode (stride 1) | 0.008–0.108 |
| Intra-block 49 contiguous segment | 0.00–0.62, recall 0.05 |
| Full stream 49-way partition | 0.001, recall 0.50 |
| **Block + Adjacent + Temporal Segment (Adopted)** | **0.03–0.16, recall 0.32–0.48** |

Note that probing is not an "extra phase". Creating the model input (xor slice) requires swap-reading
page contents anyway, so probing is simply a cost-cutting **optimization**.

---

## Implementation Status

| Stage | Status | File |
|---|---|---|
| [1] Write Tracker | Complete | `write_pattern_tracker_B.c` |
| [2] Block Ranking | Complete | `mura/plot_mura_detect.py`, `compare_top7.py` |
| [3]–[4] Segment → Candidate | Measurement only | — |
| [5] 1-Page Probe | Code ready, unlinked | `block_input_id/mura/mura_block_triage.py` |
| [6]–[7] Swap-read → XOR Slice | Unverified | `block_input_id/mura/mura_dict_build.py` |
| [8] Direction Discriminator | Complete (97.5%) | `replica/train_direction.py`, `direction_64ref.pth` |
| [9] Classification Model | Complete (80.0%) | `replica/train_reassembly.py`, `reassembly_64ref.pth` |

---

## Limitations (For Paper Disclosure)

1. **Unverified swap-read.** Stages [6]–[7] have not been executed online for MURA. There is no Phase 0 dictionary
   (`dict_cache_mura.json` with 64 ref dumps), and past logs diverge from current VM memory state.
   80.0% reflects classification accuracy **"under the assumption that page contents are accurately retrieved"**.
2. **Replica assumption.** Assumes the attacker replicates the software stack to generate training data from plaintext.
   Calculating XOR slices from plaintext is theoretically sound, but the exact memory layout distribution between victim and replica remains unverified (can be validated by comparing write trace statistics).
3. **Missing-page mask leakage.** Page omission patterns alone predict direction with 55.6% accuracy (random: 50%).
   A fraction of the 97.5% direction discriminator accuracy may stem from this artifact.
4. **Unknown aspect ratio.** Using training set mean as prior accounts for ~3%p degradation compared to the clean baseline.
5. **Mass swap-back risk.** Excessive PSP page moves have previously caused host resets. Stage [5] 1-page probing
   must be used to prune candidates before executing full swap-reads in Stage [6].
