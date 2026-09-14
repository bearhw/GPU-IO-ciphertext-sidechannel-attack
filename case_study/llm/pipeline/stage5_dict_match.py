#!/usr/bin/env python3
"""
case_study/llm/pipeline/stage5_dict_match.py — Stage 5: Dictionary Matching & Label Recovery.

Tasks:
1. Load host_base GPA and estimated indication token window from Stage 4.
2. Execute sweep_blind dictionary matching on the target indication window.
3. Recover clinical labels (e.g. Pleural Effusion, Pneumonia, Atelectasis, etc.).
4. Perform rigorous evaluation against Ground Truth:
   - Top-1 Exact Match
   - Any-Label Match
   - Multi-match Analysis
   - False Positive (Spurious Match) Detection & Reporting
5. Export stage5_result_{index}.json.

Usage:
    python3 stage5_dict_match.py --index 2 --output-dir .
    python3 stage5_dict_match.py --stage4-json stage4_bounds_2.json --output-dir .
"""

import argparse
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Optional

import common as c


def run_stage5(index: int, stage4_json: Optional[Path] = None,
               base_gpa: Optional[int] = None,
               output_dir: Optional[Path] = None) -> Dict[str, Any]:
    out_dir = output_dir or c.PIPELINE_DIR
    out_dir.mkdir(parents=True, exist_ok=True)
    out_json = out_dir / f"stage5_result_{index}.json"

    print("=" * 70)
    print(f"  [Stage 5] Dictionary Matching & Label Recovery for Sample {index}")
    print("=" * 70)

    gt_base = None
    gt_ind = None

    if base_gpa is None:
        st4_path = stage4_json or (out_dir / f"stage4_bounds_{index}.json")
        if not st4_path.exists():
            print(f"[!] Stage 4 bounds file not found at {st4_path}", file=sys.stderr)
            # Try stage 3 directly
            st3_path = out_dir / f"stage3_located_{index}.json"
            if st3_path.exists():
                st3 = c.load_json(st3_path)
                if st3.get("host_base"):
                    base_gpa = int(st3["host_base"], 16)
                    gt_base = int(st3["gt_base"], 16) if st3.get("gt_base") else None
                    gt_ind = st3.get("gt_indication")
        else:
            st4 = c.load_json(st4_path)
            if st4.get("host_base"):
                base_gpa = int(st4["host_base"], 16)
                gt_base = int(st4["gt_base"], 16) if st4.get("gt_base") else None
                gt_ind = st4.get("gt_indication")

    if base_gpa is None:
        print(f"[!] No valid base_gpa available for index {index}", file=sys.stderr)
        return {"status": "NO_BASE_GPA"}

    if not c.DICT_CACHE.exists():
        print(f"[!] Dictionary cache {c.DICT_CACHE} missing", file=sys.stderr)
        return {"status": "MISSING_DICT_CACHE"}
    dict_cache = c.load_json(c.DICT_CACHE)

    import orchestrate_v4 as o

    print(f"[Stage 5] Sweeping dictionary against host_base=0x{base_gpa:x}...")
    t0 = time.time()
    matches, n_est = o.sweep_blind(base_gpa, dict_cache, c.SWAP_TOOL)
    elapsed = time.time() - t0

    recovered_labels = [m["label"] for m in matches] if matches else []

    eval_result = c.evaluate_recovery(recovered_labels, gt_ind)

    print("\n" + "=" * 70)
    print(f"  [Stage 5 RESULTS] Sample {index} (Elapsed: {elapsed:.1f}s)")
    print("=" * 70)
    print(f"  Ground Truth Indication : {gt_ind or 'N/A'}")
    print(f"  Recovered Label(s)      : {recovered_labels or 'NONE'}")
    print(f"  Verdict                 : {eval_result['verdict']}")
    print(f"  Top-1 Match             : {'PASS' if eval_result['top1_exact_match'] else 'FAIL'}")
    print(f"  Any Label Match         : {'PASS' if eval_result['any_label_match'] else 'FAIL'}")
    print(f"  Multi-Match Count       : {eval_result['multi_match_count']}")
    print(f"  False Positive Count    : {eval_result['false_positive_count']}")
    if eval_result["false_positive_labels"]:
        print(f"  False Positive Labels   : {eval_result['false_positive_labels']}")
    print("=" * 70 + "\n")

    result = {
        "index": index,
        "host_base": hex(base_gpa),
        "gt_base": hex(gt_base) if gt_base else None,
        "gt_indication": gt_ind,
        "recovered_labels": recovered_labels,
        "raw_matches": matches,
        "evaluation": eval_result,
        "elapsed_sec": elapsed,
        "timestamp": time.time(),
        "status": "SUCCESS",
    }

    c.save_json(out_json, result)
    print(f"[Stage 5] Saved recovery result -> {out_json}")
    return result


def main():
    p = argparse.ArgumentParser(description="Stage 5: Dictionary Matching & Clinical Label Recovery")
    p.add_argument("--index", type=int, default=2, help="Sample index")
    p.add_argument("--base-gpa", type=str, default=None, help="Base GPA (hex)")
    p.add_argument("--stage4-json", type=Path, default=None, help="Path to stage4_bounds_{index}.json")
    p.add_argument("--output-dir", type=Path, default=c.PIPELINE_DIR, help="Output directory")
    args = p.parse_args()

    bgpa = int(args.base_gpa, 16) if args.base_gpa else None
    run_stage5(args.index, stage4_json=args.stage4_json, base_gpa=bgpa, output_dir=args.output_dir)


if __name__ == "__main__":
    main()
