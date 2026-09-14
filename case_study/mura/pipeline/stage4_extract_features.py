#!/usr/bin/env python3
"""
stage4_extract_features.py — Stage 4: 64-Ref XOR Slice Feature Extraction.

Compares the 49 dumped image pages against the 64 reference dictionary pages
to construct a (64, 224, 56) float32 XOR feature tensor. Supports top-aligned
partial capture fraction padding.

Outputs:
  - xor_slice_{index}.npy
  - xor_slice_{index}.npy.frac
  - features_{index}.json

Usage:
    python3 stage4_extract_features.py --index 0 [--output-dir .]
"""

import argparse
import json
import os
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

import numpy as np

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c


def load_ref_dictionary_patterns() -> Dict[int, List[bytes]]:
    """Load 16-byte chunks for each of the 64 reference values from dict_pages_mura."""
    ref_patterns = {}
    dict_dir = c.DICT_DIR

    for u8 in c.REF_U8_64:
        ref_file = dict_dir / f"ref_{u8:03d}.out"
        chunks = []
        if ref_file.exists():
            raw = c.parse_dump(ref_file)
            for j in range(c.CHUNKS_PER_PAGE):
                chunks.append(raw[j * c.CHUNK_SIZE : (j + 1) * c.CHUNK_SIZE])
        else:
            # Fallback to computed normalized float32 pattern
            expected_chunk = c.chunk16(u8, "R")
            chunks = [expected_chunk] * c.CHUNKS_PER_PAGE
        ref_patterns[u8] = chunks
    return ref_patterns


def extract_xor_slice(dump_files: List[str], ref_patterns: Dict[int, List[bytes]]) -> Tuple[np.ndarray, float]:
    """
    Extract (64, 224, 56) boolean/float32 XOR slice by comparing dumped pages
    against the reference patterns at identical chunk offsets.
    """
    num_pages = len(dump_files)
    xor_slice = np.zeros((c.NUM_REFS, c.XOR_ROWS, c.XOR_COLS), dtype=np.float32)

    # Parse all available dumped pages
    page_chunks = []
    for f in dump_files:
        p = Path(f)
        raw = c.parse_dump(p)
        for j in range(c.CHUNKS_PER_PAGE):
            page_chunks.append(raw[j * c.CHUNK_SIZE : (j + 1) * c.CHUNK_SIZE])

    total_chunks = len(page_chunks)
    total_chunks = min(total_chunks, c.XOR_ROWS * c.XOR_COLS)

    for r_idx, u8 in enumerate(c.REF_U8_64):
        ref_chunk_list = ref_patterns.get(u8, [])
        for t_idx in range(total_chunks):
            page_offset = t_idx % c.CHUNKS_PER_PAGE
            img_c = page_chunks[t_idx]
            ref_c = ref_chunk_list[page_offset] if page_offset < len(ref_chunk_list) else b""

            if img_c == ref_c and img_c != (b"\x00" * c.CHUNK_SIZE):
                row = t_idx // c.XOR_COLS
                col = t_idx % c.XOR_COLS
                if row < c.XOR_ROWS and col < c.XOR_COLS:
                    xor_slice[r_idx, row, col] = 1.0

    capture_fraction = min(1.0, float(num_pages / c.IMG_PAGES))
    return xor_slice, capture_fraction


def run_stage4(index: int, output_dir: Path, mock: bool = False) -> Dict:
    """Execute Stage 4."""
    output_dir.mkdir(parents=True, exist_ok=True)
    swap_meta_path = output_dir / f"swap_meta_{index}.json"
    features_json = output_dir / f"features_{index}.json"
    npy_path = output_dir / f"xor_slice_{index}.npy"
    frac_path = output_dir / f"xor_slice_{index}.npy.frac"

    if mock:
        # Generate synthetic xor_slice for testing
        xor_slice = np.random.binomial(1, 0.05, size=(c.NUM_REFS, c.XOR_ROWS, c.XOR_COLS)).astype(np.float32)
        capture_fraction = 1.0
        target_class = "ELBOW"
        num_pages = 49
    else:
        if not swap_meta_path.exists():
            raise FileNotFoundError(f"Missing {swap_meta_path} — run Stage 3 first.")
        swap_meta = c.load_json(swap_meta_path)
        dump_files = swap_meta.get("dump_files", [])
        target_class = swap_meta.get("target_class", "ELBOW")
        num_pages = len(dump_files)

        ref_patterns = load_ref_dictionary_patterns()
        xor_slice, capture_fraction = extract_xor_slice(dump_files, ref_patterns)

    # Save NPY & .frac sidecar
    np.save(npy_path, xor_slice)
    frac_path.write_text(f"{capture_fraction:.4f}\n")
    print(f"[stage4] Saved XOR slice shape={xor_slice.shape} (Fraction: {capture_fraction:.3f}) → {npy_path}")

    # Compute sparsity & match statistics
    total_elements = xor_slice.size
    active_matches = int(np.sum(xor_slice))
    match_density = float(active_matches / total_elements)

    meta = {
        "stage": 4,
        "index": index,
        "target_class": target_class,
        "shape": list(xor_slice.shape),
        "total_pages_used": num_pages,
        "capture_fraction": capture_fraction,
        "active_matches": active_matches,
        "match_density": match_density,
        "npy_path": str(npy_path),
        "timestamp": time.time(),
    }
    c.save_json(features_json, meta)
    print(f"[stage4] Saved feature extraction metadata → {features_json}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=0, help="MURA study / sample index")
    p.add_argument("--mock", action="store_true", help="Generate synthetic XOR slice (testing)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save features")
    args = p.parse_args()

    run_stage4(args.index, Path(args.output_dir), mock=args.mock)


if __name__ == "__main__":
    main()
