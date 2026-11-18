#!/usr/bin/env python3
"""
dict_k_redecode.py — re-run the run*hit capture offline with a smaller dictionary.

Dict-K (K < 16) is the top-K prefix of Dict-16 per channel, so every step after the
capture can be replayed exactly from the saved files with the boot's ref dumps cut
to the first K ranks:
  1. block probe: recount hits of the saved probe reads (probe_<i>/blockXX_q.out);
     a block is kept if a read has >= PIECE_MIN_HITS hits.  Live, the second read of a
     block was skipped when the first already hit with Dict-16, so a Dict-K run that
     would have read it is approximated conservatively (block dropped).
  2. kept blocks' pages (subset of pre_pages, already dumped) -> LNDS assembly
  3. base offset estimate -> cipher map (keyword index < K)
--check runs the same replay with K=16 and compares with what the capture saved.

  python3 dict_k_redecode.py ../captures/test_runhit --k 8 [--check]
"""
import argparse
import json
import sys
from pathlib import Path

import numpy as np

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "pipeline"))
sys.path.insert(0, str(HERE))
import common as c
import shapes_map as sm
import stage3_dump as s3
from redecode import snapshots, ref_pages_at


def replay(d: Path, i: int, meta, tr, ref):
    kept = []
    for bi, b in enumerate(tr["blocks"]):
        best = 0
        for q in (0, 1):
            f = d / f"probe_{i}" / f"block{bi:02d}_{q}.out"
            if f.exists():
                best = max(best, int((sm.page_hits(c.parse_dump(f), ref)[:, 0] >= 0).sum()))
        if best >= s3.PIECE_MIN_HITS:
            kept.append(bi)
    keep_pages = {g for bi in kept for g in tr["blocks"][bi]["pages"]}
    sel = [(g, f) for g, f in zip(meta["pre_pages"], meta["pre_dumps"]) if g in keep_pages]
    pages, dumps = [g for g, _ in sel], [f for _, f in sel]
    if pages:
        pages, dumps = s3.assemble_by_channel(pages, dumps, ref, windowed=False)
    hits = sm.dump_hits(dumps, ref)
    off = sm.estimate_base_off(hits) if pages else 0
    m = sm.map_from_hits(hits, off)[0] if pages else np.full((3, c.MAP_ROWS, c.MAP_COLS), -1, np.int16)
    return kept, pages, (m + 1).astype(np.uint8)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dir")
    ap.add_argument("--k", type=int, default=8)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--year", type=int, default=2026)
    a = ap.parse_args()
    d = Path(a.dir)
    snaps = snapshots(d, a.year)
    K = 16 if a.check else a.k
    od = HERE / "dictk_out" / d.name                 # capture dirs are root-owned
    od.mkdir(parents=True, exist_ok=True)
    rows = []
    for jf in sorted(d.glob("dump_*.json"), key=lambda p: int(p.stem.split("_")[1])):
        i = int(jf.stem.split("_")[1])
        meta, tr = c.load_json(jf), c.load_json(d / f"tracked_{i}.json")
        if meta.get("probe_choice") != "runhit":
            continue
        ref = {ch: v[:K] for ch, v in ref_pages_at(snaps, meta["timestamp"]).items()}
        kept, pages, m = replay(d, i, meta, tr, ref)
        gset = set(tr["gt_pages_int"])
        r = {"index": i, "gt_class": tr["target_class"], "kept_blocks": kept,
             "live_kept": [s["rank"] for s in meta["probe_scores"] if s["hits"] >= s3.PIECE_MIN_HITS],
             "pages_int": pages, "gt_overlap": len(gset & set(pages)), "gt_overlap_live": meta["gt_overlap"]}
        if a.check:
            r["same_pages"] = pages == meta["pages_int"]
            live = d / f"cmap_{i}.npy"
            r["same_cmap"] = bool(live.exists() and np.array_equal(np.load(live), m))
        else:
            np.save(od / f"cmap_{i}_d{K}.npy", m)
        rows.append(r)
        print(f"#{i} kept {kept} (live {r['live_kept']}) gt {r['gt_overlap']}/{r['gt_overlap_live']}"
              + (f" same_pages {r['same_pages']} same_cmap {r['same_cmap']}" if a.check else ""), flush=True)
    out = od / (f"dict{K}_check.json" if a.check else f"dict{K}_redecode.json")
    if a.check:
        print(f"check: blocks {sum(r['kept_blocks'] == r['live_kept'] for r in rows)}/{len(rows)}  "
              f"pages {sum(r['same_pages'] for r in rows)}/{len(rows)}  cmap {sum(r['same_cmap'] for r in rows)}/{len(rows)}")
    out.write_text(json.dumps(rows))


if __name__ == "__main__":
    main()
