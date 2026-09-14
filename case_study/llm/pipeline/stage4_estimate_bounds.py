#!/usr/bin/env python3
"""
case_study/llm/pipeline/stage4_estimate_bounds.py — Stage 4: Pad Boundary & Indication Bounds Search.

Tasks:
1. Load host_base GPA from Stage 3.
2. Execute binary search on <|image_pad|> token chunks (~11 PSP swaps) to locate pad end.
3. Estimate exact padding count (N_est) and determine target indication token window [tok_min, tok_max].
4. Export stage4_bounds_{index}.json for Stage 5 dictionary matching.

Usage:
    python3 stage4_estimate_bounds.py --index 2 --output-dir .
    python3 stage4_estimate_bounds.py --base-gpa 0x1234000 --output-dir .
"""

import argparse
import sys
import time
from pathlib import Path
from typing import Any, Dict, Optional, Tuple

import common as c


def run_stage4(index: int, base_gpa: Optional[int] = None,
               stage3_json: Optional[Path] = None,
               output_dir: Optional[Path] = None) -> Dict[str, Any]:
    out_dir = output_dir or c.PIPELINE_DIR
    out_dir.mkdir(parents=True, exist_ok=True)
    out_json = out_dir / f"stage4_bounds_{index}.json"

    print("=" * 70)
    print(f"  [Stage 4] Pad Boundary & Indication Bounds Search for Sample {index}")
    print("=" * 70)

    gt_base = None
    gt_ind = None
    gt_N = None

    if base_gpa is None:
        st3_path = stage3_json or (out_dir / f"stage3_located_{index}.json")
        if not st3_path.exists():
            print(f"[!] Stage 3 output not found at {st3_path}", file=sys.stderr)
            return {"status": "MISSING_STAGE3"}
        st3 = c.load_json(st3_path)
        if not st3.get("host_base"):
            print(f"[!] Stage 3 did not locate a valid host_base: {st3}", file=sys.stderr)
            return {"status": "NO_BASE_GPA"}
        base_gpa = int(st3["host_base"], 16)
        gt_base = int(st3["gt_base"], 16) if st3.get("gt_base") else None
        gt_ind = st3.get("gt_indication")

    # Load dict cache for estimation
    if not c.DICT_CACHE.exists():
        print(f"[!] Dict cache {c.DICT_CACHE} missing", file=sys.stderr)
        return {"status": "MISSING_DICT_CACHE"}
    dict_cache = c.load_json(c.DICT_CACHE)

    import orchestrate_v4 as o

    print(f"[Stage 4] Estimating pad bounds for base_gpa=0x{base_gpa:x} via binary search...")
    t0 = time.time()
    pad_start, n_est = o._estimate_pad_bounds(base_gpa, dict_cache, c.SWAP_TOOL)

    if pad_start is None or n_est is None:
        print("[!] Pad-bounds estimation inconclusive", file=sys.stderr)
        return {
            "index": index,
            "host_base": hex(base_gpa),
            "status": "BOUNDS_INCONCLUSIVE",
            "pad_start": None,
            "N_est": None,
        }

    # Derive indication scan window
    # In orchestrate_v4: FIRST_PAD_POS = 1, POST_SCAN_MIN = 20, POST_SCAN_MAX = 60
    _BSEARCH_MARGIN = 1
    POST_SCAN_MIN = 20
    POST_SCAN_MAX = 60
    tok_min = pad_start + n_est + POST_SCAN_MIN - _BSEARCH_MARGIN
    tok_max = pad_start + n_est + POST_SCAN_MAX + _BSEARCH_MARGIN

    elapsed = time.time() - t0
    print(f"[Stage 4] Estimated pad bounds in {elapsed:.1f}s:")
    print(f"  pad_start={pad_start}  N_est={n_est}  Indication Token Window: [{tok_min}, {tok_max}] ({tok_max - tok_min + 1} tokens)")

    result = {
        "index": index,
        "host_base": hex(base_gpa),
        "pad_start": pad_start,
        "N_est": n_est,
        "tok_min": tok_min,
        "tok_max": tok_max,
        "gt_base": hex(gt_base) if gt_base else None,
        "gt_indication": gt_ind,
        "status": "SUCCESS",
        "timestamp": time.time(),
    }

    c.save_json(out_json, result)
    print(f"[Stage 4] Saved bounds metadata -> {out_json}")
    return result


def main():
    p = argparse.ArgumentParser(description="Stage 4: Pad Boundary & Indication Bounds Search")
    p.add_argument("--index", type=int, default=2, help="Sample index")
    p.add_argument("--base-gpa", type=str, default=None, help="Base GPA (hex)")
    p.add_argument("--stage3-json", type=Path, default=None, help="Path to stage3_located_{index}.json")
    p.add_argument("--output-dir", type=Path, default=c.PIPELINE_DIR, help="Output directory")
    args = p.parse_args()

    bgpa = int(args.base_gpa, 16) if args.base_gpa else None
    run_stage4(args.index, base_gpa=bgpa, stage3_json=args.stage3_json, output_dir=args.output_dir)


if __name__ == "__main__":
    main()
