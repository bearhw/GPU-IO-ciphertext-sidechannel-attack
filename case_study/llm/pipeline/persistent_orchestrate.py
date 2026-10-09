#!/usr/bin/env python3
"""
persistent_orchestrate.py — reference-faithful (final_logs_bs1) LLM input_ids
localization, warmup-establish-measure.

Mechanism: one persistent real-generate() process reuses the input_ids frame
across inferences, so its 2MB block is written on every inference → over an
accumulated window H (appearances) is large → ungated S=H*R ranks it top-few
(bs=1 reference: input_ids rank ~5-7). Localization is per-sample "is the block
in the top-K"; no swaps needed to measure it.

Two phases (this is the point — you do NOT re-track every sample):
  1. WARMUP: run the tracker WHILE generating the first --warmup samples, then
     score the accumulated log → this ESTABLISHES the (reused) input_ids block
     ranking. Tracking (write-protect) slows generate, so we do it only here.
  2. MEASURE: stop the tracker (guest runs at full speed). Every later sample's
     input_ids reuses the SAME blocks, so we just generate it (fast), read its
     ground-truth block, and check it against the established ranking. That IS
     how the next sample is handled: the location is already known.

Usage:
  sudo python3 persistent_orchestrate.py --start 0 --end 3462 --warmup 100 \
       --top-k 7 --max-new-tokens 4 --output-dir persistent_run
"""
import argparse
import atexit
import re
import signal
import subprocess
import sys
import threading
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

import common as c
from stage2_track_blocks import score_blocks_from_log, block_base_gpa

RE_BASE = re.compile(r'input_ids base(?: page)? GPA:\s*0x([0-9a-f]+)', re.I)
RE_N = re.compile(r'N_image_pad:\s+(\d+)', re.I)

_TRACKER: Optional[Tuple[subprocess.Popen, Any]] = None
_GUEST: Optional[subprocess.Popen] = None


def _stop_tracker():
    global _TRACKER
    if _TRACKER is None:
        return
    tp, lf = _TRACKER
    if tp and tp.poll() is None:
        tp.terminate()
        try:
            tp.wait(timeout=20)
        except Exception:
            tp.kill()
    if lf:
        try:
            lf.flush(); lf.close()
        except Exception:
            pass
    _TRACKER = None


def _cleanup():
    _stop_tracker()
    global _GUEST
    if _GUEST and _GUEST.poll() is None:
        try:
            _GUEST.stdin.write("QUIT\n"); _GUEST.stdin.flush()
            _GUEST.wait(timeout=8)
        except Exception:
            try:
                _GUEST.kill()
            except Exception:
                pass


def _sig(signum, frame):
    raise SystemExit(128 + signum)


class GuestGenerateLoop:
    def __init__(self, max_new_tokens: int):
        self.max_new_tokens = max_new_tokens
        self.proc: Optional[subprocess.Popen] = None

    def start(self):
        global _GUEST
        cmd = (
            f"cd {c.GUEST_CWD} && sudo env HF_HUB_OFFLINE=1 TRANSFORMERS_OFFLINE=1 "
            f"{c.GUEST_PY} -u {c.GSCRIPT} --model_id Qwen/Qwen2-VL-2B-Instruct "
            f"--calibrate --stdin-loop --max_new_tokens {self.max_new_tokens}"
        )
        print("[guest] launching persistent real-generate loop (model load ~45-60s)...", flush=True)
        self.proc = subprocess.Popen(c.SSH_CMD + [cmd], stdin=subprocess.PIPE,
                                     stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                     text=True, bufsize=1)
        _GUEST = self.proc
        for line in self.proc.stdout:
            if "LOOP_READY" in line:
                print("[guest] LOOP_READY", flush=True)
                return
        raise RuntimeError("guest generate loop failed to reach LOOP_READY")

    def infer(self, index: int) -> Dict[str, Any]:
        if self.proc is None or self.proc.poll() is not None:
            self.start()
        self.proc.stdin.write(f"{index}\n")
        self.proc.stdin.flush()
        res: Dict[str, Any] = {"base": None, "N": None}
        for l in self.proc.stdout:
            if l.startswith("LOOP_ERR"):
                res["error"] = l.strip()
                break
            m = RE_BASE.search(l)
            if m and res["base"] is None:
                res["base"] = int(m.group(1), 16)
            m = RE_N.search(l)
            if m:
                res["N"] = int(m.group(1))
            if "HOLDING" in l:
                break
        if self.proc and self.proc.poll() is None:
            self.proc.stdin.write("NEXT\n"); self.proc.stdin.flush()
            for l in self.proc.stdout:
                if "RELEASED" in l:
                    break
        return res

    def close(self):
        if self.proc and self.proc.poll() is None:
            try:
                self.proc.stdin.write("QUIT\n"); self.proc.stdin.flush()
                self.proc.wait(timeout=10)
            except Exception:
                self.proc.kill()
        self.proc = None


def write_csv(samples: List[Tuple[int, int]], rank_of: Dict[int, int], total_blocks: int,
              top_k: int, csv_path: Path) -> Tuple[int, int]:
    n_loc = 0
    lines = ["index,gt_base,gt_block,gt_rank,in_topk,total_blocks\n"]
    for idx, base in samples:
        blk = block_base_gpa(base)
        r = rank_of.get(blk)
        intop = (r is not None and r <= top_k)
        if intop:
            n_loc += 1
        lines.append(f"{idx},0x{base:x},0x{blk:x},{r if r else ''},{intop},{total_blocks}\n")
    csv_path.write_text("".join(lines))
    return n_loc, len(samples)


def main():
    global _TRACKER
    atexit.register(_cleanup)
    signal.signal(signal.SIGTERM, _sig)
    signal.signal(signal.SIGINT, _sig)

    p = argparse.ArgumentParser()
    p.add_argument("--start", type=int, default=0)
    p.add_argument("--end", type=int, default=3462)
    p.add_argument("--warmup", type=int, default=100)
    p.add_argument("--top-k", type=int, default=7)
    p.add_argument("--max-new-tokens", type=int, default=4)
    p.add_argument("--score-every", type=int, default=50)
    p.add_argument("--rearm-ms", type=int, default=2000,
                   help="Tracker DST_TRACK re-arm period. MUST be large over the full "
                        "range: re-arm cost = pages/rearm_ms, so the default 20ms freezes "
                        "the guest. 2000ms gives ~0.8x slowdown, all input_ids writes "
                        "captured (ref tracker_range.sh). Do NOT narrow the range instead "
                        "-- input_ids has a thin tail out to ~70GB.")
    p.add_argument("--output-dir", type=Path, default=c.PIPELINE_DIR / "persistent_run")
    args = p.parse_args()

    out = args.output_dir
    out.mkdir(parents=True, exist_ok=True)
    csv_path = out / "localize_summary.csv"
    log_path = c.LLM_DIR / "e2e_persistent_wpt.log"

    print("=" * 70)
    print("  PERSISTENT LOCALIZATION — warmup-establish-measure")
    print(f"  range=[{args.start},{args.end}] warmup={args.warmup} top_k={args.top_k} "
          f"max_new_tokens={args.max_new_tokens} -> {out}")
    print("=" * 70, flush=True)

    guest = GuestGenerateLoop(args.max_new_tokens)
    guest.start()

    # ── Phase 1: WARMUP (tracker ON, generate) → establish block ranking ──
    lf = open(log_path, "w", encoding="utf-8")
    tracker = subprocess.Popen(
        [c.TRACKER_BIN, "--start-gpa", hex(c.TRACK_START), "--track-size", hex(c.TRACK_SIZE),
         "--duration", "360000", "--settle", str(c.TRACKER_SETTLE_S),
         "--rearm-ms", str(args.rearm_ms)],
        stdout=lf, stderr=subprocess.PIPE, text=True)
    _TRACKER = (tracker, lf)
    deadline = time.time() + c.TRACKER_SETTLE_S + 10
    while time.time() < deadline:
        line = tracker.stderr.readline()
        if not line or "Settle done" in line:
            break
    threading.Thread(target=lambda: [None for _ in tracker.stderr], daemon=True).start()
    print(f"[phase1] tracker armed. warming up {args.warmup} samples (tracked, slow)...", flush=True)

    warmup_end = min(args.start + args.warmup, args.end + 1)
    samples: List[Tuple[int, int]] = []
    t0 = time.time()
    for idx in range(args.start, warmup_end):
        res = guest.infer(idx)
        if res.get("error"):
            print(f"  [warmup] idx {idx}: {res['error']}", flush=True)
            continue
        if res["base"]:
            samples.append((idx, res["base"]))
        if (idx - args.start + 1) % 20 == 0:
            print(f"  [warmup] {idx - args.start + 1}/{args.warmup} ({time.time()-t0:.0f}s)", flush=True)

    lf.flush()
    _stop_tracker()   # DST_TRACK off → guest full speed for the rest
    print(f"[phase1] warmup done ({time.time()-t0:.0f}s). scoring accumulated log...", flush=True)

    scores, _, _ = score_blocks_from_log(str(log_path))
    ranked = sorted(scores.keys(), key=lambda b: -scores[b][0])
    rank_of = {b: i + 1 for i, b in enumerate(ranked)}
    total_blocks = len(scores)
    print(f"[phase1] established {total_blocks} blocks. top-{args.top_k}:", flush=True)
    for i, b in enumerate(ranked[:args.top_k]):
        S, H, R, ets = scores[b]
        print(f"    #{i+1} 0x{b:x} S={S} H={H} R={R}", flush=True)
    # warmup localization
    nloc, ntot = write_csv(samples, rank_of, total_blocks, args.top_k, csv_path)
    print(f"[phase1] warmup localized(top-{args.top_k}): {nloc}/{ntot} "
          f"({nloc/max(ntot,1)*100:.1f}%)", flush=True)

    # ── Phase 2: MEASURE (tracker OFF, fast generate) against the ranking ──
    print(f"[phase2] measuring the rest (no tracking, fast); reuse -> same blocks...", flush=True)
    t1 = time.time()
    try:
        for idx in range(warmup_end, args.end + 1):
            res = guest.infer(idx)
            if res.get("error"):
                continue
            if res["base"]:
                samples.append((idx, res["base"]))
            if len(samples) % args.score_every == 0:
                nloc, ntot = write_csv(samples, rank_of, total_blocks, args.top_k, csv_path)
                print(f"  [phase2] {ntot} samples, localized(top-{args.top_k})="
                      f"{nloc}/{ntot} ({nloc/ntot*100:.1f}%)  [{time.time()-t1:.0f}s]", flush=True)
    finally:
        nloc, ntot = write_csv(samples, rank_of, total_blocks, args.top_k, csv_path)
        print(f"\n[FINAL] localized(top-{args.top_k}): {nloc}/{ntot} "
              f"({nloc/max(ntot,1)*100:.1f}%) -> {csv_path}", flush=True)
        _cleanup()


if __name__ == "__main__":
    main()
