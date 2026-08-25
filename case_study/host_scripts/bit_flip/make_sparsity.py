#!/usr/bin/env python3
"""
make_sparsity.py — Generate a 196-element sparsity map from two separate dump files.

Accepts two QEMU xp /512gx dump files (before and after swap) and finds the
best 16-byte alignment against a JSON ground truth, then saves the result.

Usage:
  python3 make_sparsity.py <before.out> <after.out> --sample-idx N --output <out.list> \
      [--json UNet_training_v5.json]
"""

import argparse
import json
import re
import sys
from pathlib import Path

CHUNK_SIZE = 16
NUM_CHUNKS = 196
IMAGE_SIZE = NUM_CHUNKS * CHUNK_SIZE   # 3136 bytes
DUMP_BYTES = 4096

HEX_LINE = re.compile(
    r'^[0-9a-f]+:\s+0x([0-9a-f]{16})\s+0x([0-9a-f]{16})',
    re.IGNORECASE,
)


def parse_dump(path):
    """Parse a single QEMU xp dump file into a little-endian bytearray."""
    buf = bytearray()
    with open(path, errors='replace') as f:
        for line in f:
            m = HEX_LINE.match(line.strip())
            if m:
                for grp in (m.group(1), m.group(2)):
                    buf += int(grp, 16).to_bytes(8, 'little')
    return buf


def get_sparsity_at_offset(dump1, dump2, offset):
    vec = []
    for k in range(NUM_CHUNKS):
        s = offset + k * CHUNK_SIZE
        e = s + CHUNK_SIZE
        changed = any(dump1[i] ^ dump2[i] for i in range(s, e))
        vec.append(1 if changed else 0)
    return vec


def get_sparsity_two_pages(dump1_p1, dump2_p1, offset, dump1_p2, dump2_p2):
    """Read chunks from each page and combine when image spans two pages."""
    n1 = (DUMP_BYTES - offset) // CHUNK_SIZE
    n2 = NUM_CHUNKS - n1
    vec = []
    for k in range(n1):
        s = offset + k * CHUNK_SIZE
        e = s + CHUNK_SIZE
        vec.append(1 if any(dump1_p1[i] ^ dump2_p1[i] for i in range(s, e)) else 0)
    for k in range(n2):
        s = k * CHUNK_SIZE
        e = s + CHUNK_SIZE
        vec.append(1 if any(dump1_p2[i] ^ dump2_p2[i] for i in range(s, e)) else 0)
    return vec


PYTORCH_ALIGN = 64   # PyTorch CPU allocator guaranteed alignment (empirical: all offsets are multiples of 64)

# ── Host-side offset inference: spatial structure + centering ─────────────
# 196 chunks form a (28 rows x 7 cols) grid (each chunk = 4 horizontal pixels).
# Real image sparsity has (1) connected blobs of 1s and (2) MNIST digits centered
# in the frame, so the center of mass is near a fixed position. Wrong offsets
# (heap/garbage) produce scattered 1s or all-0/all-1.
#
# The old zero-density method (a single scalar: count of zero chunks) was
# fundamentally weak: dozens of offsets within the 8192-byte window had similar
# zero counts, so it couldn't pinpoint the real location. "Max zeros" was fooled
# by empty heap, "average zeros" by coincidentally aligned garbage (empirical:
# wrong on 5/5 samples). The structure+centering method correctly ranked the
# real offset #1 on the same 5/5 samples.
GRID_W, GRID_H = 7, 28
# Center-of-mass distribution from 60,000 input_sparsity_seq in UNet_training_v5.json
VCOM_MU, VCOM_SD = 14.0, 0.64    # vertical (row) center of mass: mean 14.0, stdev 0.64
HCOM_MU, HCOM_SD = 3.14, 0.13    # horizontal (col) center of mass: mean 3.14, stdev 0.13
CENTERING_WEIGHT = 0.10          # centering is a weak tie-breaker to resolve shift
                                 # ambiguity (structure is the primary signal). Too large
                                 # and slightly off-center real digits lose to
                                 # coincidentally aligned garbage.
MIN_ONES, MAX_ONES = 12, 100     # reject if too sparse/dense to be a digit.
                                 # empirical: 60k input_sparsity_seq nonzero range 19~103.
                                 # upper bound 100 catches "nearly full heap" regions
                                 # (mis-selected failures cluster at nonzero 100~108).
                                 # from 1161 match_rate.csv rows: all correct digits have
                                 # nonzero<95, so upper bound 100 loses zero correct
                                 # samples while redirecting ~87 dense-region mis-selections.


def _structure_score(vec):
    """Score how 'image-like' a 196-element binary chunk vector is. Higher = more likely a real digit."""
    ones = [(k // GRID_W, k % GRID_W) for k in range(NUM_CHUNKS) if vec[k]]
    n = len(ones)
    if n < MIN_ONES or n > MAX_ONES:
        return None                       # too sparse / too dense → not a digit
    g = [vec[r*GRID_W:(r+1)*GRID_W] for r in range(GRID_H)]

    # 4-neighbor adjacency edges (high for blobs, low for scattered) + connected components / largest component
    adj = 0
    seen = [[False]*GRID_W for _ in range(GRID_H)]
    comps, largest = 0, 0
    for r in range(GRID_H):
        for c in range(GRID_W):
            if g[r][c]:
                if c+1 < GRID_W and g[r][c+1]: adj += 1
                if r+1 < GRID_H and g[r+1][c]: adj += 1
            if g[r][c] and not seen[r][c]:
                comps += 1; sz = 0; stack = [(r, c)]; seen[r][c] = True
                while stack:
                    y, x = stack.pop(); sz += 1
                    for dy, dx in ((0,1),(0,-1),(1,0),(-1,0)):
                        ny, nx = y+dy, x+dx
                        if 0 <= ny < GRID_H and 0 <= nx < GRID_W and g[ny][nx] and not seen[ny][nx]:
                            seen[ny][nx] = True; stack.append((ny, nx))
                largest = max(largest, sz)

    adj_ratio = adj / n
    lcf       = largest / n               # largest connected component fraction (blob→1.0)
    structure = adj_ratio + 3*lcf - 0.3*comps

    vcom = sum(r for r, _ in ones) / n
    hcom = sum(c for _, c in ones) / n
    centering = ((vcom - VCOM_MU)/VCOM_SD)**2 + ((hcom - HCOM_MU)/HCOM_SD)**2
    return structure - CENTERING_WEIGHT * centering


def find_offset_by_structure(z_combined, dump_combined):
    """Infer offset host-side from an 8192-byte combined dump.

    Build a sparsity vector at each candidate offset and score it with
    _structure_score, selecting the most 'digit-like' location. Does not use
    the guest-reported offset.

    step=64: PyTorch CPU tensors are 64-byte aligned → scan in steps of 64
    instead of 16.

    Search upper bound = DUMP_BYTES - PYTORCH_ALIGN = 4032: the real offset is
    image_gpa & 0xFFF, and page1 (=image_gpa) is where the tensor starts, so
    the tensor always begins within page1 (offset 0~4032). offset>4032 would
    mean the tensor starts on page2, which is physically impossible — scanning
    there only produces garbage false positives that look structural (empirical:
    71% of 58 candidates picked from that region were failures). Page2 is only
    used as the continuation tail, not as a scan start point.
    """
    max_start = DUMP_BYTES - PYTORCH_ALIGN   # 4032 (was 8192-3136=5056)
    best_offset, best_score = 0, None
    for offset in range(0, max_start + 1, PYTORCH_ALIGN):
        vec = get_sparsity_at_offset(z_combined, dump_combined, offset)
        s = _structure_score(vec)
        if s is None:
            continue
        if best_score is None or s > best_score:
            best_score, best_offset = s, offset
    return best_offset, best_score


def find_truth_vector(json_path, sample_idx):
    with open(json_path) as f:
        data = json.load(f)
    for item in data:
        if item['sample_idx'] == sample_idx:
            return item['input_sparsity_seq']
    return None


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('before', help='Dump before swap (zero page)')
    p.add_argument('after',  help='Dump after swap (image page)')
    p.add_argument('--sample-idx', required=True, type=int, help='MNIST sample index')
    p.add_argument('--output',     required=True, help='Output .list file path')
    p.add_argument('--json',
                   default=str(Path(__file__).parent.parent /
                               'cc_uvm/pytorch_uvm310_test/mnist/UNet_training_v5.json'),
                   help='Path to UNet_training_v5.json')
    p.add_argument('--pixel-offset', type=int, default=None,
                   help='Exact in-page byte offset of image tensor; skips alignment search.')
    p.add_argument('--before2', default=None, help='Zero page dump for page 2 (two-page spanning case)')
    p.add_argument('--after2',  default=None, help='Image page dump for page 2 (two-page spanning case)')
    p.add_argument('--csv', default=None,
                   help='Append one result row (sample_idx, label, offset, match_rate, ...) '
                        'to this CSV file. Header written automatically if the file is new.')
    p.add_argument('--label', type=int, default=None,
                   help='MNIST label (for the CSV row; optional, defaults to JSON value)')
    args = p.parse_args()

    dump1 = parse_dump(args.before)
    dump2 = parse_dump(args.after)

    if len(dump1) != len(dump2):
        print(f'[!] Dump size mismatch: {len(dump1)} vs {len(dump2)}', file=sys.stderr)
        sys.exit(1)

    truth_vec = find_truth_vector(args.json, args.sample_idx)
    if truth_vec is None:
        print(f'[!] sample_idx={args.sample_idx} not found in {args.json}', file=sys.stderr)
        sys.exit(1)

    if args.before2 and args.after2:
        # Combine two-page dumps → infer offset via structure+centering scan
        dump1_p2   = parse_dump(args.before2)
        dump2_p2   = parse_dump(args.after2)
        z_combined   = dump1 + dump1_p2
        dump_combined = dump2 + dump2_p2

        if args.pixel_offset is not None:
            best_offset = args.pixel_offset
            print(f'Using provided offset: {best_offset}')
        else:
            print(f'Structure+centering scan over 8192-byte combined dump...')
            best_offset, best_score = find_offset_by_structure(z_combined, dump_combined)
            print(f'Best offset: {best_offset}  structure score: {best_score:.3f}'
                  if best_score is not None else
                  f'Best offset: {best_offset}  (no image-like region found)')

        if best_offset >= DUMP_BYTES:
            # image entirely on page 2
            p2_off = best_offset - DUMP_BYTES
            print(f'  → image entirely on page 2 (offset in p2={p2_off})')
            best_vec = get_sparsity_at_offset(dump1_p2, dump2_p2, p2_off)
        elif best_offset + IMAGE_SIZE > DUMP_BYTES:
            # image spans page boundary
            n1 = (DUMP_BYTES - best_offset) // CHUNK_SIZE
            print(f'  → spans two pages: page1={n1} chunks  page2={NUM_CHUNKS-n1} chunks')
            best_vec = get_sparsity_two_pages(dump1, dump2, best_offset, dump1_p2, dump2_p2)
        else:
            best_vec = get_sparsity_at_offset(dump1, dump2, best_offset)

    elif args.pixel_offset is not None:
        best_offset = args.pixel_offset
        best_vec    = get_sparsity_at_offset(dump1, dump2, best_offset)
        print(f'Using provided offset: {best_offset}')

    else:
        search_limit = DUMP_BYTES - IMAGE_SIZE   # 960
        best_offset, max_matches_tmp, best_vec = 0, -1, []
        print(f'Searching alignment for sample_idx={args.sample_idx}...')
        for offset in range(search_limit):
            vec = get_sparsity_at_offset(dump1, dump2, offset)
            matches = sum(a == b for a, b in zip(vec, truth_vec))
            if matches > max_matches_tmp:
                max_matches_tmp, best_offset, best_vec = matches, offset, vec

    max_matches = sum(a == b for a, b in zip(best_vec, truth_vec))
    match_rate  = max_matches / NUM_CHUNKS * 100
    print(f'Offset: {best_offset}  match rate: {match_rate:.1f}%')
    if match_rate < 80:
        print('[!] WARNING: low match rate — alignment may be poor.')

    Path(args.output).write_text(str(best_vec))
    print(f'Saved: {args.output}')

    if args.csv:
        import csv, datetime
        label = args.label
        if label is None:
            with open(args.json) as f:
                for item in json.load(f):
                    if item['sample_idx'] == args.sample_idx:
                        label = item.get('label'); break
        row = {
            'timestamp':   datetime.datetime.now().strftime('%Y-%m-%dT%H:%M:%S'),
            'sample_idx':  args.sample_idx,
            'label':       label if label is not None else '',
            'offset':      best_offset,
            'match_rate':  f'{match_rate:.1f}',
            'nonzero':     sum(best_vec),
        }
        csv_path = Path(args.csv)
        write_header = not csv_path.exists() or csv_path.stat().st_size == 0
        with open(csv_path, 'a', newline='') as f:
            w = csv.DictWriter(f, fieldnames=list(row.keys()))
            if write_header:
                w.writeheader()
            w.writerow(row)
        print(f'CSV row appended → {csv_path}')


if __name__ == '__main__':
    main()
