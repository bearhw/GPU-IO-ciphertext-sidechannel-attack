#!/usr/bin/env python3
"""
verify_dict.py — Validate the 64-page reference dictionary before an attack run.

Three checks, weakest to strongest:

  (default)         distinctness — no two refs dump identically.
  --against-capture detection    — does the dictionary actually find known pixel
                                   values in a page set already captured from the
                                   guest? Offline, and the only check that proves
                                   a ref is usable.
  --live            reproducibility — re-inject a value and compare against the
                                   stored ref. Needs root and the same VM the
                                   dictionary was built on.

Distinctness alone is not enough: a ref whose injected pattern landed at the wrong
byte phase is rotated, matches nothing a victim ever holds, and is still distinct
from every other ref. That is how a dictionary with 2 of 64 usable refs passed.

Usage:
    python3 verify_dict.py
    python3 verify_dict.py --against-capture 6 --image /path/to/image1.png
    sudo python3 verify_dict.py --live --sample 8
"""

import argparse
import hashlib
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

MIN_DETECTION_RATE = 0.50      # a usable ref finds at least half of its occurrences
MIN_OCCURRENCES    = 20        # below this the rate is too noisy to judge


def page_sig(path: Path) -> bytes:
    return hashlib.sha256(c.parse_dump(path)).digest()


def check_distinct(dict_dir: Path):
    by_sig = defaultdict(list)
    missing = []
    headers = set()
    for u8 in c.REF_U8_64:
        f = dict_dir / f"ref_{u8:03d}.out"
        if not f.exists():
            missing.append(u8)
            continue
        with open(f, errors="ignore") as fh:
            headers.add(fh.readline().strip())
        by_sig[page_sig(f)].append(u8)

    dups = sorted((v for v in by_sig.values() if len(v) > 1), key=len, reverse=True)
    bad = sorted(u for g in dups for u in g)

    print(f"[verify] dict dir       : {dict_dir}")
    print(f"[verify] refs present   : {len(c.REF_U8_64) - len(missing)}/{len(c.REF_U8_64)}")
    print(f"[verify] distinct dumps : {len(by_sig)}")
    print(f"[verify] FIXED_GPA      : {headers if len(headers) <= 2 else str(len(headers)) + ' DIFFERENT (!)'}")
    if missing:
        print(f"[verify] [!] missing    : {missing}")
    if len(headers) > 1:
        print(f"[verify] [!] refs span more than one FIXED_GPA — dictionary is inconsistent")
    for g in dups:
        print(f"[verify] [!] identical  : u8 = {sorted(g)}")
    if not dups and not missing:
        print(f"[verify] distinctness OK (necessary, not sufficient — see --against-capture)")
    return bad, missing


def expected_positions(image_path: Path):
    """Chunk positions of the victim's R channel that hold a dictionary value.

    Reproduces the guest's own transform, so this is what a correct dictionary
    has to find.
    """
    import numpy as np
    from PIL import Image
    from torchvision import transforms

    t = transforms.Compose([
        transforms.Resize((c.IMG_SIZE, c.IMG_SIZE)),
        transforms.ToTensor(),
        transforms.Normalize(mean=[c.IMAGENET_MEAN[k] for k in "RGB"],
                             std=[c.IMAGENET_STD[k] for k in "RGB"]),
    ])
    r = t(Image.open(image_path).convert("RGB")).contiguous()[0].numpy()
    flat = r.flatten().view(np.uint8)
    by_chunk = {c.chunk16(u8, "R"): u8 for u8 in c.REF_U8_64}
    out = {}
    for t_idx in range(c.XOR_ROWS * c.XOR_COLS):
        u8 = by_chunk.get(flat[t_idx * c.CHUNK_SIZE:(t_idx + 1) * c.CHUNK_SIZE].tobytes())
        if u8 is not None:
            out[t_idx] = u8
    return out


def check_against_capture(index: int, image_path: Path, output_dir: Path, dict_dir: Path):
    import stage4_extract_features as s4

    swap_path = output_dir / f"swap_meta_{index}.json"
    if not swap_path.exists():
        print(f"[verify] [!] {swap_path} not found — run the pipeline on index {index} first")
        return None
    dump_files = json.loads(swap_path.read_text()).get("dump_files", [])
    if not dump_files:
        print(f"[verify] [!] index {index} captured no pages")
        return None

    refs = s4.load_ref_dictionary_patterns()
    dump = []
    for f in dump_files:
        raw = c.parse_dump(Path(f))
        dump += [raw[j * c.CHUNK_SIZE:(j + 1) * c.CHUNK_SIZE] for j in range(c.CHUNKS_PER_PAGE)]

    exp = expected_positions(image_path)

    # A capture whose window slipped by a few pages scores near zero even with a
    # perfect dictionary, so find the page shift that lines the two up and judge
    # the dictionary at that shift. Reporting the raw number as a dictionary
    # verdict is what made a ~70% dictionary look like 6.6%.
    def score(shift: int):
        hits = Counter()
        for t_idx, u8 in exp.items():
            d = t_idx + shift * c.CHUNKS_PER_PAGE
            off = t_idx % c.CHUNKS_PER_PAGE
            if 0 <= d < len(dump) and off < len(refs.get(u8, [])) and dump[d] == refs[u8][off]:
                hits[u8] += 1
        return hits

    shifts = {s: score(s) for s in range(-8, 9)}
    best_shift = max(shifts, key=lambda s: sum(shifts[s].values()))
    want, got = Counter(exp.values()), shifts[best_shift]
    raw = sum(shifts[0].values())

    print(f"\n[verify] detection against capture {index} ({image_path.name})")
    print(f"[verify] chunk positions holding a dictionary value: {len(exp)}")
    if best_shift:
        print(f"[verify] [!] capture window is off by {best_shift} page(s) — "
              f"raw detection {raw}/{len(exp)} = {raw/max(len(exp),1):.1%}")
        print(f"[verify]     judging the dictionary at that shift instead")
    print(f"\n{'u8':>5} {'occurs':>8} {'found':>7} {'rate':>7}")
    judged = usable = 0
    for u8 in c.REF_U8_64:
        w = want.get(u8, 0)
        if w < MIN_OCCURRENCES:
            continue
        judged += 1
        rate = got.get(u8, 0) / w
        usable += rate >= MIN_DETECTION_RATE
        flag = "" if rate >= MIN_DETECTION_RATE else "  <== unusable"
        print(f"{u8:>5} {w:>8} {got.get(u8,0):>7} {rate:>6.0%}{flag}")

    total_rate = sum(got.values()) / max(len(exp), 1)
    print(f"\n[verify] overall detection : {sum(got.values())}/{len(exp)} = {total_rate:.1%}")
    print(f"[verify] refs judged       : {judged} (>= {MIN_OCCURRENCES} occurrences)")
    print(f"[verify] refs usable       : {usable}/{judged}")
    if usable < judged:
        print(f"[verify] [!] the dictionary cannot detect values it should — rebuild the failing refs")
    return usable, judged


def check_live(sample: int, dict_dir: Path):
    """Re-inject a value and compare against the stored ref.

    Only meaningful once acquire_gpa verifies its own alignment: a fresh, verified
    injection that disagrees with the stored ref means the stored one is rotated.
    """
    import stage1_ref_dict as s1

    cache = c.load_json(c.DICT_CACHE_FILE)
    fixed_gpa = int(cache["fixed_gpa"], 16)
    tmp = HERE / "verify_live"
    tmp.mkdir(exist_ok=True)

    picks = c.REF_U8_64[:sample]
    print(f"\n[verify] live re-injection at FIXED_GPA 0x{fixed_gpa:x} ({len(picks)} ref(s))")
    ok = 0
    for u8 in picks:
        stored = dict_dir / f"ref_{u8:03d}.out"
        fresh = tmp / f"fresh_{u8:03d}.out"
        try:
            gpa = s1.acquire_gpa(u8, chunk_bytes=c.chunk16(u8, "R"))
            s1.do_swap_read(fixed_gpa, gpa, fresh)
        except Exception as e:
            print(f"  u8={u8:>3}: injection failed ({e})")
            continue
        same = c.parse_dump(fresh) == c.parse_dump(stored)
        ok += same
        print(f"  u8={u8:>3}: {'matches stored ref' if same else 'DIFFERS from stored ref'}")
    print(f"\n[verify] reproducible: {ok}/{len(picks)}")
    return ok, len(picks)


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--against-capture", type=int, default=None, metavar="INDEX",
                   help="Measure detection using an already-captured page set")
    p.add_argument("--image", default=None, help="Local copy of the image that capture held")
    p.add_argument("--live", action="store_true", help="Re-inject values and compare (needs root)")
    p.add_argument("--sample", type=int, default=8, help="How many refs to re-inject for --live")
    p.add_argument("--output-dir", default=str(HERE))
    args = p.parse_args()

    dict_dir = c.DICT_DIR
    bad, missing = check_distinct(dict_dir)
    failed = bool(bad or missing)

    if args.against_capture is not None:
        if not args.image:
            print("[verify] [!] --against-capture needs --image")
            sys.exit(2)
        res = check_against_capture(args.against_capture, Path(args.image),
                                    Path(args.output_dir), dict_dir)
        if res is None or res[0] < res[1]:
            failed = True

    if args.live:
        ok, n = check_live(args.sample, dict_dir)
        if ok < n:
            failed = True

    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
