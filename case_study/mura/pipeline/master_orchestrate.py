#!/usr/bin/env python3
"""
master_orchestrate.py — Master Orchestrator for MURA End-to-End Attack Pipeline.

Coordinates the complete 5-stage modular pipeline:
  Stage 1: Reference Dictionary & Fixed GPA Management (stage1_ref_dict.py)
  Stage 2: Target 49-Page GPA Tracking & Multi-Block Stitching (stage2_track_gpa.py)
  Stage 3: PSP 49-Page Sequential Collision Swap & Dump (stage3_swap_dump.py)
  Stage 4: 64-Ref XOR Feature Extraction (stage4_extract_features.py)
  Stage 5: XorSliceSENetV3 Classification, 2D Reconstruction & Metrics (stage5_reconstruct.py)

Usage:
    # Run full pipeline for sample 0 (blind mode)
    sudo python3 master_orchestrate.py --index 0 --blind

    # Run specific stages (e.g. Stage 4 to 5)
    python3 master_orchestrate.py --from-stage 4 --to-stage 5 --index 0

    # Batch mode over multiple studies
    sudo python3 master_orchestrate.py --start 0 --end 5 --blind
"""

import argparse
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

import common as c
import stage1_ref_dict as s1
import stage2_track_gpa as s2
import stage3_swap_dump as s3
import stage4_extract_features as s4
import stage5_reconstruct as s5


def orchestrate_single(index: int, output_dir: Path, from_stage: int = 1,
                       to_stage: int = 5, blind: bool = False,
                       class_name: Optional[str] = None, rebuild_dict: bool = False,
                       mock: bool = False, host_log: Optional[str] = None) -> Dict:
    """Execute stages for a single MURA index."""
    print(f"\n{'='*74}")
    print(f"  [MURA E2E Orchestrator] Study Index {index} (Stages {from_stage} -> {to_stage})")
    print(f"{'='*74}\n")

    output_dir.mkdir(parents=True, exist_ok=True)
    summary: Dict = {"index": index, "status": "ok"}
    t_start = time.time()

    # Stage 1: Ref Dictionary
    if from_stage <= 1 <= to_stage:
        print("\n--- [Stage 1: Reference Dictionary & Fixed GPA] ---")
        meta1 = s1.run_stage1(output_dir, rebuild=rebuild_dict)
        summary["stage1"] = meta1

    # Stage 2: Track & Multi-Block Stitching
    if from_stage <= 2 <= to_stage:
        print("\n--- [Stage 2: Target 49-Page Tracking & Stitching] ---")
        meta2 = s2.run_stage2(index, output_dir, blind=blind,
                              study_type=class_name, host_log_override=host_log)
        summary["stage2"] = meta2

    # Stage 3: PSP Collision Swap & Dump
    if from_stage <= 3 <= to_stage:
        print("\n--- [Stage 3: PSP 49-Page Collision Swap & Dump] ---")
        meta3 = s3.run_stage3(index, output_dir, mock=mock)
        summary["stage3"] = meta3

    # Stage 4: Feature Extraction
    if from_stage <= 4 <= to_stage:
        print("\n--- [Stage 4: 64-Ref XOR Feature Extraction] ---")
        meta4 = s4.run_stage4(index, output_dir, mock=mock)
        summary["stage4"] = meta4

    # Stage 5: Classification & Reconstruction
    if from_stage <= 5 <= to_stage:
        print("\n--- [Stage 5: Classification & Captured Pages Summary] ---")
        meta5 = s5.run_stage5(index, output_dir, mock=mock)
        summary["stage5"] = meta5

    elapsed = time.time() - t_start
    summary["elapsed_sec"] = round(elapsed, 2)
    return summary


def print_summary_table(results: List[Dict]):
    """Print formatted summary table with Top-3 predictions and confidences, captured pages, and stitching status."""
    print("\n" + "=" * 106)
    print("  MURA END-TO-END ATTACK & CLASSIFICATION SUMMARY")
    print("=" * 106)
    print(f"{'Index':<7}{'Target GT':<12}{'Top-3 Predictions (Conf %)':<58}{'Captured Pages':<18}{'Stitched':<10}")
    print("-" * 106)
    for r in results:
        idx = r.get("index", "-")
        s5_res = r.get("stage5", {})
        s3_res = r.get("stage3", {})
        s2_res = r.get("stage2", {})

        # Persistent metadata fallbacks
        if not s2_res and idx != "-":
            tr_file = HERE / f"tracked_mura_{idx}.json"
            if tr_file.exists():
                s2_res = c.load_json(tr_file)
        if not s3_res and idx != "-":
            sw_file = HERE / f"swap_meta_{idx}.json"
            if sw_file.exists():
                s3_res = c.load_json(sw_file)

        target = s5_res.get("target_class", s2_res.get("target_class", "-"))

        top3_list = s5_res.get("top3", [])
        if top3_list:
            top3_str = ", ".join(f"{i+1}. {item['class']} ({item['prob']*100:.1f}%)" for i, item in enumerate(top3_list))
        else:
            pred = s5_res.get("predicted_class", "-")
            conf = f"{s5_res.get('confidence', 0.0)*100:.1f}%" if "confidence" in s5_res else "-"
            top3_str = f"1. {pred} ({conf})"

        # Captured pages (1 channel = 49 pages)
        cap_str = s5_res.get("captured_pages", "-")
        if cap_str == "-":
            succ = s3_res.get("successful_pages", s2_res.get("total_pages", 0))
            cap_str = f"{succ}/{c.IMG_PAGES} ({succ/c.IMG_PAGES*100:.1f}%)" if c.IMG_PAGES > 0 else f"{succ}"
        else:
            cnt = s5_res.get("captured_pages_count", 0)
            cap_str = f"{cap_str} ({cnt/c.IMG_PAGES*100:.1f}%)"

        stitched = "YES" if s2_res.get("is_stitched") else "NO"

        print(f"{idx:<7}{target:<12}{top3_str:<58}{cap_str:<18}{stitched:<10}")
    print("=" * 106 + "\n")


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=0, help="Single MURA study index")
    p.add_argument("--start", type=int, default=None, help="Batch start index (inclusive)")
    p.add_argument("--end", type=int, default=None, help="Batch end index (exclusive)")
    p.add_argument("--stage", type=int, choices=[1, 2, 3, 4, 5], default=None, help="Run only specific stage")
    p.add_argument("--from-stage", type=int, default=1, help="Starting stage (1-5)")
    p.add_argument("--to-stage", type=int, default=5, help="Ending stage (1-5)")
    p.add_argument("--blind", action="store_true", help="Perform blind write tracking in Stage 2")
    p.add_argument("--class-name", default=None, help="Optional target class name filter (e.g. ELBOW, HAND)")
    p.add_argument("--host-log", default=None, help="Optional offline host log for Stage 2")
    p.add_argument("--rebuild-dict", action="store_true", help="Rebuild ref dictionary in Stage 1")
    p.add_argument("--mock", action="store_true", help="Run with mock data (testing)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save artifacts")
    args = p.parse_args()

    from_st = args.stage if args.stage is not None else args.from_stage
    to_st   = args.stage if args.stage is not None else args.to_stage

    out_dir = Path(args.output_dir)

    results = []
    if args.start is not None and args.end is not None:
        for idx in range(args.start, args.end):
            if idx > args.start:
                print(f"\n[batch] Inter-sample PSP cooldown (3.0s)...")
                time.sleep(3.0)
            res = orchestrate_single(
                idx, out_dir, from_stage=from_st, to_stage=to_st,
                blind=args.blind, class_name=args.class_name,
                rebuild_dict=args.rebuild_dict, mock=args.mock, host_log=args.host_log)
            results.append(res)
    else:
        res = orchestrate_single(
            args.index, out_dir, from_stage=from_st, to_stage=to_st,
            blind=args.blind, class_name=args.class_name,
            rebuild_dict=args.rebuild_dict, mock=args.mock, host_log=args.host_log)
        results.append(res)

    print_summary_table(results)


if __name__ == "__main__":
    main()
