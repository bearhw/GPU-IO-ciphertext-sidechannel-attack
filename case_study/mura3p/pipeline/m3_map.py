#!/usr/bin/env python3
"""
shapes_map.py — cipher map for 3DShapes, from real dumps or simulated from images.

A cipher map is (3, 224, 56) int16: for each channel plane and 16 B block, the index
of the matching dictionary keyword (0..K-1 within that channel) or -1.

  real:      decode_dumps()  — compare each dumped block with every ref dump at the
             same in-page offset (all reads happen under FIXED_GPA).
  simulated: simulate()      — victim-identical preprocessing + exact tuple lookup.

to_input() turns a map into the classifier input (4, 224, 224) float32: the
recovered pixel values of each channel (u8/255, 0 where missed) plus a hit mask.
"""
import sys
from pathlib import Path
from typing import Dict, List, Optional, Sequence

import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

PLANE_BLOCKS = c.MAP_ROWS * c.MAP_COLS          # 12,544 blocks = 49 pages
CH_IDX = {ch: i for i, ch in enumerate(c.CHANNELS_ALL)}


# --------------------------------------------------------------------------- keywords
def keyword_tables(refs: Optional[List[Dict]] = None):
    """Per channel: (codes uint32[K], pixels uint8[K,4]) in rank order."""
    refs = refs or c.load_keywords()
    out = {}
    for ch in c.CHANNELS_ALL:
        rs = sorted([r for r in refs if r["ch"] == ch], key=lambda r: r["rank"])
        px = np.array([r["pixels"] for r in rs], dtype=np.uint8)
        codes = (px[:, 0].astype(np.uint32) | px[:, 1].astype(np.uint32) << 8 |
                 px[:, 2].astype(np.uint32) << 16 | px[:, 3].astype(np.uint32) << 24)
        out[ch] = (codes, px)
    return out


# --------------------------------------------------------------------------- simulation
def preprocess_u8(img64: np.ndarray) -> np.ndarray:
    """(64,64,3) uint8 -> (224,224,3) uint8, the victim's Resize((224,224)) on PIL."""
    return np.asarray(Image.fromarray(img64).resize((224, 224), Image.BILINEAR))


def block_codes(img224: np.ndarray) -> np.ndarray:
    b = img224.transpose(2, 0, 1).reshape(3, 224, 56, 4).astype(np.uint32)
    return b[..., 0] | b[..., 1] << 8 | b[..., 2] << 16 | b[..., 3] << 24


def simulate(img64: np.ndarray, tables=None) -> np.ndarray:
    tables = tables or keyword_tables()
    codes = block_codes(preprocess_u8(img64))
    m = np.full((3, c.MAP_ROWS, c.MAP_COLS), -1, np.int16)
    for ch, (kc, _) in tables.items():
        i = CH_IDX[ch]
        lut = {int(v): k for k, v in enumerate(kc)}
        flat = codes[i].ravel()
        hit = np.isin(flat, kc)
        idx = np.full(flat.shape, -1, np.int16)
        idx[hit] = [lut[int(v)] for v in flat[hit]]
        m[i] = idx.reshape(c.MAP_ROWS, c.MAP_COLS)
    return m


# --------------------------------------------------------------------------- real dumps
def load_ref_pages(refs: Optional[List[Dict]] = None) -> Dict[str, List[np.ndarray]]:
    """Per channel, ref dump blocks as (256,16) uint8 arrays in rank order."""
    refs = refs or c.load_keywords()
    out = {ch: [] for ch in c.CHANNELS_ALL}
    for r in sorted(refs, key=lambda r: (r["ch"], r["rank"])):
        raw = c.parse_dump(c.DICT_DIR / f"ref_{r['name']}.out")
        out[r["ch"]].append(np.frombuffer(raw, np.uint8).reshape(256, 16))
    return out


def page_hits(raw: bytes, ref_pages) -> np.ndarray:
    """(256, 2) int16 per block: (channel index, keyword index) or (-1, -1)."""
    blk = np.frombuffer(raw, np.uint8).reshape(256, 16)
    res = np.full((256, 2), -1, np.int16)
    for ch, pages in ref_pages.items():
        for k, rp in enumerate(pages):
            eq = np.all(blk == rp, axis=1) & (res[:, 0] < 0)
            res[eq] = (CH_IDX[ch], k)
    return res


def count_page_matches(path: Path, ref_pages) -> int:
    return int((page_hits(c.parse_dump(path), ref_pages)[:, 0] >= 0).sum())


def decode_dumps(dumps: Sequence[Optional[Path]], ref_pages, base_off: int = 0) -> np.ndarray:
    """Dumps in tensor page order (None = missing) -> (3,224,56) map.

    base_off is the tensor's byte offset inside its first page (allocator alignment);
    block b of page k holds tensor bytes [k*4096 + 16b - base_off, +16).
    """
    m = np.full((3, c.MAP_ROWS, c.MAP_COLS), -1, np.int16)
    for k, p in enumerate(dumps):
        if p is None or not Path(p).exists():
            continue
        hits = page_hits(c.parse_dump(Path(p)), ref_pages)
        for b in np.flatnonzero(hits[:, 0] >= 0):
            t = k * c.PAGE_SIZE + 16 * int(b) - base_off
            if t < 0 or t % 16:
                continue
            g = t // 16                       # global block index in the tensor
            plane, rem = divmod(g, PLANE_BLOCKS)
            if plane >= 3:
                continue
            # The block's own keyword channel is authoritative; a block landing in
            # another plane means base_off is wrong, so it is dropped.
            if hits[b, 0] != plane:
                continue
            m[plane, rem // c.MAP_COLS, rem % c.MAP_COLS] = hits[b, 1]
    return m


def dump_hits(dumps: Sequence[Optional[Path]], ref_pages) -> List[Optional[np.ndarray]]:
    return [page_hits(c.parse_dump(Path(p)), ref_pages) if p and Path(p).exists() else None
            for p in dumps]


def _hit_arrays(hits):
    K, B, CH, KW = [], [], [], []
    for k, h in enumerate(hits):
        if h is None:
            continue
        b = np.flatnonzero(h[:, 0] >= 0)
        K.append(np.full(len(b), k))
        B.append(b)
        CH.append(h[b, 0])
        KW.append(h[b, 1])
    if not K:
        z = np.zeros(0, np.int64)
        return z, z, z, z
    return (np.concatenate(K).astype(np.int64), np.concatenate(B).astype(np.int64),
            np.concatenate(CH).astype(np.int64), np.concatenate(KW).astype(np.int64))


def map_from_hits(hits, base_off: int):
    """(map, consistent, inconsistent) for one shift. base_off is the tensor's start
    measured from the first dumped page; it is negative when the first tensor
    page(s) were not dumped."""
    K, B, CH, KW = _hit_arrays(hits)
    m = np.full((3, c.MAP_ROWS, c.MAP_COLS), -1, np.int16)
    t = K * c.PAGE_SIZE + 16 * B - base_off
    g = t // 16
    plane = g // PLANE_BLOCKS
    inside = (t >= 0) & (plane < 3)
    ok = inside & (plane == CH)
    rem = g[ok] % PLANE_BLOCKS
    m[plane[ok], rem // c.MAP_COLS, rem % c.MAP_COLS] = KW[ok]
    return m, int(ok.sum()), int((~ok).sum())


def estimate_base_off(hits, step: int = 64, span_pages: int = 24):
    """Blind tensor start: 64 B-aligned; every keyword belongs to one channel, so the
    right shift puts R/G/B hits inside the R/G/B planes. Searched over +-span_pages
    because the run assembly can miss the first page or include one extra."""
    K, B, CH, KW = _hit_arrays(hits)
    if len(K) == 0:
        return 0
    pos = K * c.PAGE_SIZE + 16 * B
    best = None
    for off in range(-span_pages * c.PAGE_SIZE, 2 * c.PAGE_SIZE, step):
        t = pos - off
        plane = (t // 16) // PLANE_BLOCKS
        ok = (t >= 0) & (plane < 3) & (plane == CH)
        score = 2 * int(ok.sum()) - len(K)
        if best is None or score > best[1]:
            best = (off, score)
    return best[0]


# --------------------------------------------------------------------------- model input
def to_input(m: np.ndarray, tables=None) -> np.ndarray:
    tables = tables or keyword_tables()
    x = np.zeros((4, 224, 224), np.float32)
    for ch, (_, px) in tables.items():
        i = CH_IDX[ch]
        hit = m[i] >= 0
        vals = np.zeros((c.MAP_ROWS, c.MAP_COLS, 4), np.float32)
        vals[hit] = px[m[i][hit]] / 255.0
        x[i] = vals.reshape(224, 224)
        x[3] = np.maximum(x[3], np.repeat(hit, 4, axis=1).astype(np.float32))
    return x
