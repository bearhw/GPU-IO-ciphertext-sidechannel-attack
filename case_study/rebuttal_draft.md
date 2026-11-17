We thank the reviewers. All new results below will be added to the revision.

# Common

**End-to-end attack and cost (A1–2, A5–6, B2, C2–3, C5–6).** We now run end-to-end attacks on MURA and VLM without ground-truth addresses, covering every step in Figure 2. We enable CC by following NVIDIA's deployment guide step by step **(H100 in CC mode, transfers via bounce buffers)**. Victims run the original code (PyTorch MNIST example, DenseNet-MURA-PyTorch, Qwen2-VL-2B-Instruct fine-tuned on ReXGradient-160K) on a guest with default PyTorch.

- MURA (1,905 test samples): 67.1% top-1 and 88.1% top-3 accuracy. Building the 64-entry dictionary takes 21 min. Each input takes 167 s: tracking 8 s, localization 92 s, 49-page dump 66 s, classification 1 s.
- VLM (3 runs, n=1,641): localization succeeds for 78.9±0.6% of inputs and end-to-end for 42.7±1.5%. Building the 30-entry dictionary takes 4 min. Each input takes 51 s: tracking 21 s, localization 13 s, matching 17 s.
- MNIST (bs=512): Dictionary building takes 6.18 s and the online phase 320.98 s per batch (Step ① 127.02 s, ② 190.42 s, ③ 3.54 s).

**The victim slows down by [XX]% under attack.**

**Novelty (A1, A4, A8, B3–4, D1, D4).** Prior ciphertext attacks on ML in CPU CC target intermediates, which move to the GPU under GPU CC. We instead exploit the input tensor left in CPU memory and locate it from runtime access patterns during GPU I/O. Any CC deployment that tensorizes inputs in CPU memory, including CPU-only AMX inference, is exposed. **Standard stacks (Hugging Face processors, torchvision transforms) preprocess on the CPU by default.**

|              | Prior CPU-only attacks | Ours (GPU CC) |
|--------------|------------------------|---------------|
| Signal       | Intermediates with binary sparsity (post-ReLU) | GPU-ready input tensor: coarse, data-dependent encodings |
| Localization | Fixed offsets from offline analysis of the ML framework | Runtime OS-allocator behavior |

**PAGE_SWAP_DISABLE / ciphertext hiding (C1, C4, C8, D8–9).** Neither is part of a standard deployment. NVIDIA's latest CC deployment guide launches SNP guests with policy=0x30000, which leaves PAGE_SWAP_DISABLE (bit 25, firmware 1.58+) cleared. Ciphertext hiding requires Turin and stays off in KVM unless the host sets kvm_amd.ciphertext_hiding_asids, i.e., it relies on the untrusted host. **Azure's confidential H100 VMs run on Genoa, which lacks it.** Our setup follows the guide: firmware 1.51, the default policy, and an EPYC 7643. Without page move, kernel zero-fill still exposes zero-block ciphertext at the victim address, which suffices for sparse inputs. We will move ciphertext hiding to Background.

# Reviewer A

**VLM dictionary (A3, A7).** **The dictionary is built from [the training split]. n=1,641 counts inputs whose label it covers; over all 3,462 test inputs, end-to-end success is [XX]%.**

# Reviewer B

**Mitigation (B1, B5).** A compact data type packs more values per block, but uniform regions such as a white background still repeat. A tensor-specific defense is per-input masking, which XORs each 16 B block with a fresh random pad that the GPU removes. This removes collisions at one extra pass per side. We will discuss it.

# Reviewer C

**Contiguity / KASLR (C7).** All results were collected with KASLR enabled. The attack tracks writes via NPFs and reads ciphertext by host physical address. We locate the tensor from observed writes rather than predicting its placement**, and stitch runs that cross 2 MB boundaries by write order**.

# Reviewer D

**Token ID width (D2).** Hugging Face Transformers returns token IDs as int64, PyTorch's default integer type, and our victim uses this default unchanged. **With int32, a block holds 4 tokens instead of 2; localization is unaffected, since repeated <|image_pad|> tokens still form identical blocks. We will re-run with int32.**

**Color images (D15).** The only difference from grayscale is the cipher-map size. Each 16 B block of the three float32 planes holds 4 pixels of one channel, so a per-channel dictionary works. On Fruits-360, Dict-64 covers 32–34% of blocks; on 3DShapes, 49–75%. Leakage depends on dictionary coverage, not color.

**TDXRay (D5).** TDXRay infers access patterns at cache-line or page granularity through cache and page-table side channels. We exploit ciphertext, so the two are orthogonal. We will cite it.

**Disclosure (D3).** We reported to AMD and NVIDIA in July 2026. AMD acknowledged it as a new case of the known ciphertext side channel; NVIDIA acknowledged receipt only.

**Editorial (D6–14).** We will fix all issues, including SEV-IO/TDISP in Background.
