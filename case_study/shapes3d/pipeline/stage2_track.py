#!/usr/bin/env python3
"""
stage2_track.py — Stage 2: run the victim, trace its writes, find the tensor burst.

Same handshake as MURA: the guest loader faults its destination tensor in, says
GUEST_READY_FOR_TRACK, the host arms write_pattern_tracker, then the loader copies
the (3,224,224) tensor in one sweep — 148 consecutive page writes (147 pages plus
one for the unaligned base). Candidates are windows of consecutive tracked writes
with all-distinct pages and a tight time envelope (MURA's burst finder, scaled to
3 planes). The loader also reports ground truth (GPAs, base offset, class) which
is used only for scoring and for --gt (known-address) runs.

  sudo python3 stage2_track.py --index 0 --split test [--gpu] [--output-dir DIR]
"""
import argparse
import re
import subprocess
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

LINE_RE = re.compile(r'WRITE\s+gpa=0x([0-9a-fA-F]+)\s+ts=(\d+)')
N_PAGES = c.IMG_PAGES + 1            # 148: the base is 64 B-aligned, never page-aligned
MAX_SPAN_US = 300.0 * 3              # MURA: 49 pages in <=300 us
MAX_GAP_US = 10.0
TOP_K = 10
CLUSTER_OVERLAP = 120                # MURA used 40 of 49


def page_runs(pages: List[int]) -> int:
    u = sorted(set(pages))
    return 1 + sum(1 for a, b in zip(u, u[1:]) if b - a != c.PAGE_SIZE)


def find_burst_candidates(writes: List[Tuple[int, int]], n: int = N_PAGES,
                          max_span_us: float = MAX_SPAN_US, max_gap_us: float = MAX_GAP_US,
                          top_k: int = TOP_K) -> List[Dict]:
    filt = [(g, t) for g, t in writes
            if not (c.BLIND_A_LO <= g < c.BLIND_A_HI or c.BLIND_B_LO <= g < c.BLIND_B_HI)]
    wins = []
    for k in range(len(filt) - n + 1):
        w = filt[k:k + n]
        pages = [g for g, _ in w]
        if len(set(pages)) != n:
            continue
        ts = [t for _, t in w]
        span = (ts[-1] - ts[0]) / 1000.0
        gap = max(b - a for a, b in zip(ts, ts[1:])) / 1000.0
        if span > max_span_us or gap > max_gap_us:
            continue
        wins.append({"pages": pages, "set": set(pages), "runs": page_runs(pages),
                     "span_us": span, "max_gap_us": gap, "start": k})
    wins.sort(key=lambda x: (x["runs"], x["span_us"]))
    reps = []
    for w in wins:
        if all(len(w["set"] & r["set"]) < CLUSTER_OVERLAP for r in reps):
            reps.append(w)
            if len(reps) >= top_k:
                break
    return [{"channel_pages_int": w["pages"], "runs": w["runs"],
             "span_us": round(w["span_us"], 1), "max_gap_us": round(w["max_gap_us"], 1),
             "blocks": sorted({hex(g & ~(c.BLIND_ALIGN_2MB - 1)) for g in w["pages"]})}
            for w in reps]


CHAIN_LINK = 400            # max foreign writes between two pages of one physical run
CHAIN_GAP = 400             # max foreign writes between consecutive runs of one copy
PIECE_MIN = 4
MAX_PIECES = 400


def pieces(writes: List[Tuple[int, int]]) -> List[Dict]:
    """Physically ascending page runs, followed through interleaved foreign writes.

    The destination tensor is a fresh ~600 KB anonymous allocation, mostly
    physically contiguous (7-9 runs for 148 pages), and the copy writes it in
    order. The tracker reports writes in batches, so timing is not a usable burst
    boundary (an interrupt split #1's copy 49 + 99 with 367 foreign writes in
    between); physical continuity is."""
    filt = [g for g, t in writes
            if not (c.BLIND_A_LO <= g < c.BLIND_A_HI or c.BLIND_B_LO <= g < c.BLIND_B_HI)]
    tails, runs = {}, []
    for k, g in enumerate(filt):
        r = tails.pop(g - c.PAGE_SIZE, None)
        if r is not None and k - r["k1"] <= CHAIN_LINK and g not in r["set"]:
            r["pages"].append(g)
            r["set"].add(g)
            r["k1"] = k
        else:
            r = {"pages": [g], "set": {g}, "k0": k, "k1": k}
            runs.append(r)
        tails[g] = r
    return sorted([r for r in runs if len(r["pages"]) >= PIECE_MIN], key=lambda r: r["k0"])


SEG_GAP_US = 10.0


def time_segments(writes: List[Tuple[int, int]], gap_us: float = SEG_GAP_US, min_len: int = 4) -> List[Dict]:
    """Runs of writes with < gap_us between neighbours, in write order.

    A long-running victim (resident server) gets its tensor from fragmented memory:
    148 pages in 144-146 physical runs, so physical continuity says nothing. The
    copy is still one sweep in tensor order, seen as a dense burst in the trace
    (11-12 pilot2: 146 writes with 0 foreign, or 148 with 78 foreign interleaved).
    Foreign pages inside a segment are dropped after the dump (no dictionary hits)."""
    filt = [(g, t) for g, t in writes
            if not (c.BLIND_A_LO <= g < c.BLIND_A_HI or c.BLIND_B_LO <= g < c.BLIND_B_HI)]
    segs, cur, k0 = [], [], 0
    for k, (g, t) in enumerate(filt):
        if cur and t - cur[-1][1] > gap_us * 1000:
            if len(cur) >= min_len:
                segs.append({"k0": k0, "k1": k - 1, "t0": cur[0][1], "pages": [x for x, _ in cur]})
            cur, k0 = [], k
        cur.append((g, t))
    if len(cur) >= min_len:
        segs.append({"k0": k0, "k1": len(filt) - 1, "t0": cur[0][1], "pages": [x for x, _ in cur]})
    for sg in segs:                      # keep first occurrence of each page
        seen, u = set(), []
        for g in sg["pages"]:
            if g not in seen:
                seen.add(g)
                u.append(g)
        sg["pages"] = u
    return segs


def chained_candidates(writes, n: int = N_PAGES, top_k: int = TOP_K) -> List[Dict]:
    """Chains of runs in write order totalling n pages; fewest runs and fewest
    interleaved foreign writes first."""
    P = pieces(writes)
    out = []
    for i, p in enumerate(P):
        ch, tot, used = [p], len(p["pages"]), set(p["pages"])
        for q in P[i + 1:]:
            if tot >= n - 1:
                break
            if q["k0"] > ch[-1]["k1"] + CHAIN_GAP:
                break
            if q["k0"] > ch[-1]["k1"] and not (used & q["set"]):
                ch.append(q)
                tot += len(q["pages"])
                used |= q["set"]
        if tot >= n - 1:
            out.append({"pages": [g for r in ch for g in r["pages"]][:n], "parts": len(ch),
                        "foreign": ch[-1]["k1"] - ch[0]["k0"] + 1 - tot})
    out.sort(key=lambda x: (x["parts"], x["foreign"]))
    reps = []
    for w in out:
        ws = set(w["pages"])
        if all(len(ws & set(r["pages"])) < CLUSTER_OVERLAP for r in reps):
            reps.append(w)
            if len(reps) >= top_k:
                break
    return [{"channel_pages_int": w["pages"], "parts": w["parts"], "foreign": w["foreign"],
             "runs": page_runs(w["pages"]),
             "blocks": sorted({hex(g & ~(c.BLIND_ALIGN_2MB - 1)) for g in w["pages"]})}
            for w in reps]


RUNHIT_LO, RUNHIT_HI = 0.0, 0.04    # slice of the trace (first-write position); pilots: tensor at 1-5%
RUNHIT_TOP_K = 8


def runhit_blocks(writes: List[Tuple[int, int]], lo: float = RUNHIT_LO, hi: float = RUNHIT_HI,
                  k: int = RUNHIT_TOP_K) -> List[Dict]:
    """Blind 2MB-block ranking, as in the LLM/MURA pipelines: score = max physical
    run x pages written, over the pages FIRST-WRITTEN in the [lo, hi] slice of the
    trace. Over the whole trace the victim's start-up writes bury the input block
    (11-14, 400 test traces: GT block median rank 15.5); in the early slice where
    the copy happens it is top-3 in 78.5% and top-8 in ~97%. Each block's pages are
    returned in first-write order with their trace position."""
    from collections import defaultdict
    filt = [g for g, _ in writes
            if not (c.BLIND_A_LO <= g < c.BLIND_A_HI or c.BLIND_B_LO <= g < c.BLIND_B_HI)]
    first: Dict[int, int] = {}
    for i, g in enumerate(filt):
        first.setdefault(g, i)
    n = len(filt)
    per = defaultdict(list)
    for g, i in first.items():
        if lo * n <= i <= hi * n:
            per[g & ~(c.BLIND_ALIGN_2MB - 1)].append(g)
    scored = []
    for blk, p in per.items():
        q = sorted(p)
        best = cur = 1
        for a, b in zip(q, q[1:]):
            cur = cur + 1 if b - a == c.PAGE_SIZE else 1
            best = max(best, cur)
        scored.append((best * len(q), blk, best, len(q)))
    scored.sort(key=lambda x: -x[0])
    out = []
    for s, blk, run, hits in scored[:k]:
        pages = sorted(per[blk], key=first.get)
        out.append({"block": hex(blk), "score": s, "max_run": run, "hits": hits,
                    "pages": pages, "k": [first[g] for g in pages]})
    return out


def read_writes(path: Path, filtered: bool = False) -> List[Tuple[int, int]]:
    w = []
    for line in open(path, errors="ignore"):
        m = LINE_RE.search(line)
        if m:
            g = int(m.group(1), 16)
            if filtered and (c.BLIND_A_LO <= g < c.BLIND_A_HI or c.BLIND_B_LO <= g < c.BLIND_B_HI):
                continue
            w.append((g, int(m.group(2))))
    return w


def run_victim(index: int, split: str, gpu: bool, on_ready) -> Tuple[Dict, subprocess.Popen]:
    if c.USE_SERVER:
        cmd = (f"python3 -u {c.GUEST_DIR}/guest_shapes_server.py client "
               f"--index {index} --split {split} --wait_for_host" + (" --gpu" if gpu else ""))
    else:
        cmd = (f"cd {c.GUEST_DIR} && sudo {c.GUEST_PY} -u guest_shapes_loader.py "
               f"--index {index} --split {split} --wait_for_host" + (" --gpu" if gpu else ""))
    p = subprocess.Popen(c.SSH_BASE + [cmd], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                         stderr=subprocess.PIPE, text=True)
    gt: Dict = {"pages": []}
    for line in p.stdout:
        s = line.strip()
        if s == "GUEST_READY_FOR_TRACK":
            on_ready()
            # Request time, as the hypervisor would see the inference request
            # arrive on virtio-net; same clock as the tracker's timestamps.
            gt["t_go_ns"] = time.monotonic_ns()
            p.stdin.write("\n")
            p.stdin.flush()
        elif s.startswith("CLASS:"):
            gt["class"] = s.split(":", 1)[1].strip()
        elif s.startswith("IMG_PATH:"):
            gt["img"] = s.split(":", 1)[1].strip()
        elif s.startswith("BASE_OFF:"):
            gt["base_off"] = int(s.split(":", 1)[1])
        elif s.startswith("GPU_PRED:"):
            gt["gpu_pred"] = s.split(":", 1)[1].strip()
        elif s.startswith("GPA_PAGE:"):
            v = s.split(":", 1)[1].strip()
            gt["pages"].append(int(v, 16) if v != "NONE" else None)
        elif s == "GUEST_LOAD_READY":
            break
    return gt, p


def release_guest():
    for _ in range(3):
        c.ssh_run("touch /tmp/host_read_done")
        time.sleep(0.4)
        if c.ssh_run("test -e /tmp/host_read_done; echo $?").strip()[:1] != "0":
            break


def run_stage2(index: int, out: Path, split: str = "test", gpu: bool = False,
               settle: int = 1, duration: int = 60) -> Dict:
    out.mkdir(parents=True, exist_ok=True)
    c.ensure_guest_suppressions()
    log_p, dbg_p = out / f"wpt_{index}.log", out / f"wpt_{index}_dbg.log"
    lf, df = open(log_p, "w"), open(dbg_p, "w")
    holder = {}

    def arm():
        holder["tr"] = subprocess.Popen(
            [str(c.TRACKER_PATH), "--duration", str(duration), "--settle", str(settle),
             "--start-gpa", "0x0", "--track-size", "0x4000000000",
             "--start-gpa2", hex(c.BLIND_B_LO), "--track-size2", hex(c.BLIND_B_HI - c.BLIND_B_LO)],
            stdout=lf, stderr=df)
        end = time.time() + settle + 5
        while time.time() < end:
            time.sleep(0.1)
            if "Settle done" in dbg_p.read_text(errors="ignore"):
                break

    t0 = time.time()
    gt, proc = run_victim(index, split, gpu, arm)
    time.sleep(1.0)
    tr = holder.get("tr")
    if tr:
        tr.terminate()
        try:
            tr.wait(timeout=3)
        except subprocess.TimeoutExpired:
            tr.kill()
    lf.close()
    df.close()

    writes = []
    for line in open(log_p, errors="ignore"):
        m = LINE_RE.search(line)
        if m:
            writes.append((int(m.group(1), 16), int(m.group(2))))
    cands = chained_candidates(writes)
    # Time-ordered physical runs for Stage 3's piece probe (the primary localizer).
    piece_list = [{"k0": r["k0"], "k1": r["k1"], "pages": r["pages"]} for r in pieces(writes)[:MAX_PIECES]]
    seg_list = time_segments(writes)[:MAX_PIECES]
    blocks = runhit_blocks(writes)
    gpages = [g for g in gt.get("pages", []) if g is not None]
    gset = set(gpages)
    meta = {"stage": 2, "index": index, "split": split, "gpu": gpu,
            "target_class": gt.get("class"), "img": gt.get("img"), "gpu_pred": gt.get("gpu_pred"),
            "gt_base_off": gt.get("base_off"), "t_go_ns": gt.get("t_go_ns"), "gt_pages_int": gt.get("pages", []),
            "n_writes": len(writes), "candidates": cands, "pieces": piece_list, "segments": seg_list,
            "gt_cand_overlap": [len(gset & set(x["channel_pages_int"])) for x in cands],
            "blocks": blocks, "gt_block_overlap": [len(gset & set(b["pages"])) for b in blocks],
            "t_stage2": round(time.time() - t0, 2), "timestamp": time.time()}
    c.save_json(out / f"tracked_{index}.json", meta)
    print(f"[stage2] #{index} {gt.get('class')} writes={len(writes)} blocks={len(blocks)} "
          f"gt-in-blocks={meta['gt_block_overlap']} (of {len(gpages)}) {meta['t_stage2']}s")
    meta["_proc"] = proc
    return meta


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--index", type=int, default=0)
    p.add_argument("--split", default="test", choices=["test", "capture_train"])
    p.add_argument("--gpu", action="store_true")
    p.add_argument("--output-dir", default=str(HERE / "runs" / "debug"))
    a = p.parse_args()
    run_stage2(a.index, Path(a.output_dir), a.split, a.gpu)
    release_guest()


if __name__ == "__main__":
    main()
