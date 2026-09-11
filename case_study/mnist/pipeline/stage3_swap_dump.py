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
from typing import Dict, Optional

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


def run_stage3(index: int, output_dir: Path, image_gpa: Optional[int] = None,
               page2_gpa: Optional[int] = None, zero_gpa: Optional[int] = None,
               label: Optional[int] = None) -> Dict:
    """Execute Stage 3."""
    output_dir.mkdir(parents=True, exist_ok=True)
    meta_path = output_dir / f"swap_meta_{index}.json"

    # 1. Resolve Zero GPA
    if zero_gpa is None:
        zero_json = output_dir / "zero_gpa.json"
        if not zero_json.exists():
            zero_json = HERE / "zero_gpa.json"
        if not zero_json.exists():
            raise FileNotFoundError(f"[stage3] zero_gpa.json not found. Run stage1_zero_gpa.py first.")
        zero_data = c.load_json(zero_json)
        zero_gpa = int(zero_data["zero_gpa"], 16)

    # 2. Resolve Target GPA and Label
    if image_gpa is None or label is None:
        target_json = output_dir / f"tracked_target_{index}.json"
        if not target_json.exists():
            target_json = HERE / f"tracked_target_{index}.json"
        if not target_json.exists():
            raise FileNotFoundError(f"[stage3] tracked_target_{index}.json not found. Run stage2_track_gpa.py first.")
        target_data = c.load_json(target_json)
        if image_gpa is None:
            image_gpa = int(target_data["image_gpa"], 16)
        if label is None:
            label = int(target_data.get("label", 0))
        if page2_gpa is None and target_data.get("page2_gpa"):
            page2_gpa = int(target_data["page2_gpa"], 16)

    if page2_gpa is None:
        page2_table = c.load_page2_table()
        page2_gpa = page2_table.get(image_gpa, image_gpa + c.PAGE_SIZE)

    dump_p1 = output_dir / f"{label}-{index}.out"
    dump_p2 = output_dir / f"{label}-{index}_p2.out"

    print(f"[stage3] Starting swap dump for index {index} (label={label})")
    print(f"         Zero GPA : 0x{zero_gpa:x}")
    print(f"         Page 1   : 0x{image_gpa:x} → {dump_p1.name}")
    print(f"         Page 2   : 0x{page2_gpa:x} → {dump_p2.name}")

    t0 = time.time()
    # [1/2] Page 1
    swap_and_dump_page(image_gpa, zero_gpa, label, index, dump_p1, output_dir)
    # [2/2] Page 2
    swap_and_dump_page(page2_gpa, zero_gpa, label, index, dump_p2, output_dir)

    meta = {
        "stage": 3,
        "index": index,
        "label": label,
        "zero_gpa": f"0x{zero_gpa:x}",
        "image_gpa": f"0x{image_gpa:x}",
        "page2_gpa": f"0x{page2_gpa:x}",
        "dump_p1": str(dump_p1),
        "dump_p2": str(dump_p2),
        "total_swap_time_sec": time.time() - t0,
        "timestamp": time.time(),
    }
    c.save_json(meta_path, meta)
    print(f"[stage3] Saved swap metadata → {meta_path.name}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, required=True, help="MNIST sample index (0-59999)")
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
               page2_gpa=p2_gpa, zero_gpa=z_gpa, label=args.label)


if __name__ == "__main__":
    main()
