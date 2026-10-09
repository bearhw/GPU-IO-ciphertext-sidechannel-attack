#!/usr/bin/env python3
"""
build_attack_dataset.py — Turn captured page dumps into model-input sparsity maps.

Reads the dumps a capture run produced and rebuilds the XOR slice for each sample:

    map[r, row, col] = 1  iff  dump chunk t equals reference r's chunk at t % 256
    where t = row * XOR_COLS + col

Which references are compared is the only thing that sets the channel count, and the
dumps do not depend on it, so 16-, 32- and 64-channel datasets all come from one
capture. REF_U8_64 is density-ranked, so channel i of an N-channel map is
REF_U8_64[i] — the same convention the training scripts use.

A dump is only interpretable with the dictionary from the VM boot that produced it,
because the VEK changes with the instance. Each sample records its boot id and each
boot's references are snapshotted, so this pairs them up and refuses samples whose
snapshot is missing rather than emitting a map of noise.

Usage:
    python3 build_attack_dataset.py --split train --n-ref 64
    python3 build_attack_dataset.py --split train --n-ref 16 --out-dir datasets/
"""

import argparse
import json
import sys
from collections import Counter
from pathlib import Path

import numpy as np

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

SNAP_ROOT = HERE / "dict_snapshots"
CAPTURE_ROOT = HERE / "captures"


def load_snapshot(boot_id: str, n_ref: int):
    """The reference chunks for one boot, as {channel_index: [256 chunks]}.

    Channels whose reference was never built are left out; a missing channel stays
    all-zero in the map, which is what the attack actually saw.
    """
    d = SNAP_ROOT / boot_id
    if not d.is_dir():
        return None
    refs = {}
    for ch, u8 in enumerate(c.REF_U8_64[:n_ref]):
        f = d / f"ref_{u8:03d}.out"
        if not f.exists():
            continue
        raw = c.parse_dump(f)
        refs[ch] = [raw[j * c.CHUNK_SIZE:(j + 1) * c.CHUNK_SIZE]
                    for j in range(c.CHUNKS_PER_PAGE)]
    return refs


def build_map(dump_files, refs, n_ref: int) -> np.ndarray:
    """One sample's sparsity map. Pages that were never dumped stay zero."""
    chunks = []
    for f in dump_files:
        raw = c.parse_dump(Path(f))
        chunks += [raw[j * c.CHUNK_SIZE:(j + 1) * c.CHUNK_SIZE]
                   for j in range(c.CHUNKS_PER_PAGE)]

    out = np.zeros((n_ref, c.XOR_ROWS, c.XOR_COLS), dtype=bool)
    limit = min(len(chunks), c.XOR_ROWS * c.XOR_COLS)
    for ch, ref_chunks in refs.items():
        for t in range(limit):
            if chunks[t] == ref_chunks[t % c.CHUNKS_PER_PAGE]:
                out[ch, t // c.XOR_COLS, t % c.XOR_COLS] = True
    return out


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--split", default="train", choices=["train", "valid"])
    p.add_argument("--n-ref", type=int, default=64, choices=[16, 32, 64])
    p.add_argument("--capture-dir", default=None,
                   help="Defaults to captures/<split>")
    p.add_argument("--out-dir", default=str(HERE / "datasets"))
    p.add_argument("--limit", type=int, default=None, help="Stop after N samples")
    args = p.parse_args()

    cap = Path(args.capture_dir) if args.capture_dir else CAPTURE_ROOT / args.split
    if not cap.is_dir():
        sys.exit(f"{cap} not found — has a capture run written there yet?")

    metas = sorted(cap.glob("swap_meta_*.json"),
                   key=lambda f: int(f.stem.split("_")[-1]))
    if not metas:
        sys.exit(f"no swap_meta_*.json under {cap}")
    print(f"[build] {len(metas)} captured sample(s) in {cap}")

    snapshots = {}
    maps, labels, index, skipped = [], [], [], Counter()

    for m in metas:
        meta = json.loads(m.read_text())
        idx = meta.get("index")
        dumps = meta.get("dump_files") or []
        cls = meta.get("target_class")
        bid = meta.get("boot_id") or ""

        if not dumps:
            skipped["no dumps"] += 1
            continue
        if cls not in c.CLASS2IDX:
            skipped[f"unknown class {cls}"] += 1
            continue
        if not bid:
            # Captured before boot ids were recorded: the matching references cannot
            # be identified, and guessing one would silently produce a noise map.
            skipped["no boot id"] += 1
            continue
        if bid not in snapshots:
            snapshots[bid] = load_snapshot(bid, args.n_ref)
        refs = snapshots[bid]
        if not refs:
            skipped[f"no snapshot for boot {bid[:8]}"] += 1
            continue

        maps.append(build_map(dumps, refs, args.n_ref))
        labels.append(c.CLASS2IDX[cls])
        index.append({"index": idx, "class": cls, "boot_id": bid,
                      "pages": len(dumps),
                      "gt_overlap": meta.get("gt_overlap"),
                      "gt_exact_order": meta.get("gt_exact_order")})
        if len(maps) % 200 == 0:
            print(f"[build] {len(maps)} maps built", flush=True)
        if args.limit and len(maps) >= args.limit:
            break

    if not maps:
        sys.exit("no usable samples — check boot ids and dict_snapshots/")

    out_dir = Path(args.out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)
    tag = f"{args.split}_{args.n_ref}ref"
    x = np.stack(maps)
    np.save(out_dir / f"{tag}_slices.npy", x)
    np.save(out_dir / f"{tag}_labels.npy", np.array(labels, dtype=np.int64))
    (out_dir / f"{tag}_index.json").write_text(json.dumps(index, indent=1))

    print()
    print(f"[build] {tag}: {x.shape} bool  ({x.nbytes / 1e9:.2f} GB)")
    print(f"[build] density: {x.mean():.5f}")
    print(f"[build] class counts: "
          f"{dict(Counter(c.CLASSES[l] for l in labels))}")
    if skipped:
        print(f"[build] skipped: {dict(skipped)}")
    print(f"[build] wrote {out_dir}/{tag}_*.npy")


if __name__ == "__main__":
    main()
