#!/usr/bin/env python3
"""
stage4_extract_features.py — Stage 4: Sparsity Feature Vector Extraction.

Compares Page 1 & Page 2 memory dumps against z.out, infers in-page byte offset
via spatial structure and center-of-mass analysis (or uses explicit offset),
and extracts the 196-element sparsity vector (.out_v5.list).

Usage:
    python3 stage4_extract_features.py --index 0 [--output-dir .] [--pixel-offset N]
"""

import argparse
import ast
import json
import math
import re
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

# Grid dimensions and structure scoring constants
GRID_W, GRID_H = 7, 28
VCOM_MU, VCOM_SD = 14.0, 0.64
HCOM_MU, HCOM_SD = 3.14, 0.13
CENTERING_WEIGHT = 0.10
MIN_ONES, MAX_ONES = 12, 100


def get_sparsity_at_offset(dump1: bytearray, dump2: bytearray, offset: int) -> List[int]:
    vec = []
    for k in range(c.NUM_CHUNKS):
        s = offset + k * c.CHUNK_BYTES
        e = s + c.CHUNK_BYTES
        changed = any(dump1[i] ^ dump2[i] for i in range(s, e))
        vec.append(1 if changed else 0)
    return vec


def get_sparsity_two_pages(dump1_p1: bytearray, dump2_p1: bytearray, offset: int,
                           dump1_p2: bytearray, dump2_p2: bytearray) -> List[int]:
    """Combine chunks when image tensor spans across Page 1 and Page 2."""
    n1 = min(c.NUM_CHUNKS, max(0, (c.PAGE_SIZE - offset) // c.CHUNK_BYTES))
    n2 = c.NUM_CHUNKS - n1
    vec = []
    for k in range(n1):
        s = offset + k * c.CHUNK_BYTES
        e = s + c.CHUNK_BYTES
        vec.append(1 if any(dump1_p1[i] ^ dump2_p1[i] for i in range(s, e)) else 0)
    for k in range(n2):
        s = k * c.CHUNK_BYTES
        e = s + c.CHUNK_BYTES
        vec.append(1 if any(dump1_p2[i] ^ dump2_p2[i] for i in range(s, e)) else 0)
    return vec[:c.NUM_CHUNKS]


def structure_score(vec: List[int]) -> Optional[float]:
    """Score how image-like a 196-element binary chunk vector is."""
    ones = [(k // GRID_W, k % GRID_W) for k in range(c.NUM_CHUNKS) if vec[k]]
    n = len(ones)
    if n < MIN_ONES or n > MAX_ONES:
        return None

    g = [vec[r * GRID_W:(r + 1) * GRID_W] for r in range(GRID_H)]

    # 4-neighbor adjacency edges + connected components
    adj = 0
    seen = [[False] * GRID_W for _ in range(GRID_H)]
    comps, largest = 0, 0
    for r in range(GRID_H):
        for c_col in range(GRID_W):
            if g[r][c_col]:
                if c_col + 1 < GRID_W and g[r][c_col + 1]:
                    adj += 1
                if r + 1 < GRID_H and g[r + 1][c_col]:
                    adj += 1
            if g[r][c_col] and not seen[r][c_col]:
                comps += 1
                sz = 0
                stack = [(r, c_col)]
                seen[r][c_col] = True
                while stack:
                    y, x = stack.pop()
                    sz += 1
                    for dy, dx in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                        ny, nx = y + dy, x + dx
                        if 0 <= ny < GRID_H and 0 <= nx < GRID_W and g[ny][nx] and not seen[ny][nx]:
                            seen[ny][nx] = True
                            stack.append((ny, nx))
                largest = max(largest, sz)

    edge_density = adj / (2 * n)
    comp_penalty = 1.0 / comps
    large_frac = largest / n
    structure = edge_density * comp_penalty * large_frac

    # Center of mass Gaussian likelihood
    v_com = sum(r for r, _ in ones) / n
    h_com = sum(c_col for _, c_col in ones) / n
    v_ll = math.exp(-0.5 * ((v_com - VCOM_MU) / VCOM_SD) ** 2)
    h_ll = math.exp(-0.5 * ((h_com - HCOM_MU) / HCOM_SD) ** 2)
    centering = v_ll * h_ll

    return structure * (1.0 - CENTERING_WEIGHT + CENTERING_WEIGHT * centering)


def infer_page_offset(z1: bytearray, p1: bytearray, z2: bytearray, p2: bytearray) -> Tuple[int, List[int], float]:
    """Scan all 64-byte aligned offsets in 0..4095 and select the most structured one."""
    best_score = -1.0
    best_off = 0
    best_vec = []

    for off in range(0, c.PAGE_SIZE, c.PYTORCH_ALIGN):
        vec = get_sparsity_two_pages(z1, p1, off, z2, p2)
        score = structure_score(vec)
        if score is not None and score > best_score:
            best_score = score
            best_off = off
            best_vec = vec

    if best_score < 0:
        # Fallback to offset 0 if no score passed threshold
        best_off = 0
        best_vec = get_sparsity_two_pages(z1, p1, 0, z2, p2)
        best_score = 0.0

    return best_off, best_vec, best_score


def run_stage4(index: int, output_dir: Path, pixel_offset: Optional[int] = None,
               label: Optional[int] = None, json_path: Optional[Path] = None) -> Dict:
    """Execute Stage 4."""
    output_dir.mkdir(parents=True, exist_ok=True)
    features_json = output_dir / f"features_{index}.json"

    # 1. Resolve label and pixel_offset from Stage 2 if available
    if label is None or pixel_offset is None:
        target_meta_file = output_dir / f"tracked_target_{index}.json"
        if not target_meta_file.exists():
            target_meta_file = HERE / f"tracked_target_{index}.json"
        if target_meta_file.exists():
            tdata = c.load_json(target_meta_file)
            if label is None:
                label = int(tdata.get("label", 0))
            if pixel_offset is None:
                pixel_offset = tdata.get("pixel_offset")

    label_str = str(label) if label is not None else "0"

    # 2. Resolve dump paths
    z_file = output_dir / "z.out"
    if not z_file.exists():
        z_file = HERE / "z.out"
    if not z_file.exists():
        z_file = c.FLOW_DIR / "z.out"

    p1_file = output_dir / f"{label_str}-{index}.out"
    if not p1_file.exists():
        candidates = list(output_dir.glob(f"*-{index}.out"))
        if candidates:
            p1_file = candidates[0]
            m = re.search(r'(\d+)-\d+\.out$', p1_file.name)
            if m and label is None:
                label = int(m.group(1))
                label_str = str(label)
    if not p1_file.exists():
        flow_candidates = list(c.FLOW_DIR.glob(f"*-{index}.out"))
        # Filter out _p2
        flow_candidates = [f for f in flow_candidates if not f.name.endswith("_p2.out")]
        if flow_candidates:
            p1_file = flow_candidates[0]
            m = re.search(r'(\d+)-\d+\.out$', p1_file.name)
            if m and label is None:
                label = int(m.group(1))
                label_str = str(label)

    p2_file = output_dir / f"{label_str}-{index}_p2.out"
    if not p2_file.exists():
        p2_file = c.FLOW_DIR / f"{label_str}-{index}_p2.out"
    if not p2_file.exists():
        candidates_p2 = list(output_dir.glob(f"*-{index}_p2.out"))
        if candidates_p2:
            p2_file = candidates_p2[0]
        else:
            candidates_p2 = list(c.FLOW_DIR.glob(f"*-{index}_p2.out"))
            if candidates_p2:
                p2_file = candidates_p2[0]

    if not z_file.exists() or not p1_file.exists():
        raise FileNotFoundError(f"[stage4] Dumps missing: {z_file} or {p1_file}. Run stage1/stage3 first.")

    z1 = c.parse_dump(z_file)
    p1 = c.parse_dump(p1_file)
    z2 = c.parse_dump(z_file)
    p2 = c.parse_dump(p2_file) if p2_file.exists() else z2

    if pixel_offset is not None and pixel_offset >= 0:
        print(f"[stage4] Using explicit pixel_offset: {pixel_offset}")
        sparsity = get_sparsity_two_pages(z1, p1, pixel_offset, z2, p2)
        inferred = False
        score = structure_score(sparsity) or 1.0
    else:
        print("[stage4] In-page offset not specified -> running host-side spatial structure inference...")
        pixel_offset, sparsity, score = infer_page_offset(z1, p1, z2, p2)
        inferred = True
        print(f"[stage4] Inferred optimal page_offset = {pixel_offset} (structure score = {score:.4f})")

    # Match rate check if JSON ground truth exists
    match_rate = None
    if json_path is None and c.DEFAULT_JSON.exists():
        json_path = c.DEFAULT_JSON
    if json_path and json_path.exists():
        try:
            with open(json_path) as jf:
                jdata = json.load(jf)
            sample_entry = next((item for item in jdata if item.get("sample_idx") == index), None)
            if sample_entry and "input_sparsity_seq" in sample_entry:
                gt_sp = sample_entry["input_sparsity_seq"]
                matches = sum(1 for a, b in zip(sparsity, gt_sp) if a == b)
                match_rate = (matches / len(sparsity)) * 100.0
                print(f"[stage4] Ground Truth Sparsity Match Rate: {match_rate:.2f}% ({matches}/{len(sparsity)})")
        except Exception:
            pass

    # Save .out_v5.list
    list_path = output_dir / f"{label_str}-{index}.out_v5.list"
    with open(list_path, "w") as lf:
        lf.write(str(sparsity) + "\n")
    print(f"[stage4] Saved sparsity vector → {list_path.name} ({sum(sparsity)} active chunks / 196)")

    meta = {
        "stage": 4,
        "index": index,
        "label": label,
        "pixel_offset": pixel_offset,
        "offset_inferred": inferred,
        "structure_score": score,
        "active_chunks": sum(sparsity),
        "match_rate": match_rate,
        "list_file": str(list_path),
        "sparsity": sparsity,
        "timestamp": time.time(),
    }
    c.save_json(features_json, meta)
    print(f"[stage4] Saved feature metadata → {features_json.name}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, required=True, help="MNIST sample index (0-59999)")
    p.add_argument("--label", type=int, default=None, help="MNIST digit label (0-9)")
    p.add_argument("--pixel-offset", type=int, default=None, help="In-page byte offset (if known)")
    p.add_argument("--json", default=None, help="Path to UNet_training_v5.json for match rate grading")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to read dumps and save features")
    args = p.parse_args()

    j_path = Path(args.json) if args.json else None
    run_stage4(args.index, Path(args.output_dir), pixel_offset=args.pixel_offset,
               label=args.label, json_path=j_path)


if __name__ == "__main__":
    main()
