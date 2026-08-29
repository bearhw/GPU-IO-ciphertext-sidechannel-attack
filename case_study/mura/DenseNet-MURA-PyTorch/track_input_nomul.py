#!/usr/bin/env python3
"""
Input image GPA tracking — NO mul_(1.0).

Used with the persistent write-protect kernel patch.
Since dst_track keeps write-protect active after a fault,
the DataLoader's natural writes trigger faults on every iteration.

Sequence:
  1. Signal host -> host starts tracker (applies write-protect)
  2. Wait (for host tracker to finish enabling dst_track)
  3. Load tensor via DataLoader -> natural write faults occur
  4. GPU inference
  5. Signal host -> done

Usage (guest):
    sudo python3 track_input_nomul.py --max_iters 10
"""
import argparse
import os
import struct
import subprocess
import time

import torch

from densenet import densenet169
from pipeline import get_study_level_data, get_dataloaders

_HOST_ADDR = "user@10.0.2.2"


def _signal_host(remote_path):
    try:
        subprocess.run(
            ["sudo", "-u", "ubuntu", "ssh",
             "-o", "StrictHostKeyChecking=no",
             "-o", "ConnectTimeout=3",
             "-o", "BatchMode=yes",
             _HOST_ADDR, f"touch {remote_path}"],
            timeout=5, check=False, capture_output=True,
        )
    except Exception:
        pass


def va_to_gpa(va):
    page_size = 4096
    page_num = va // page_size
    offset = va % page_size
    with open('/proc/self/pagemap', 'rb') as f:
        f.seek(page_num * 8)
        entry = struct.unpack('Q', f.read(8))[0]
    present = (entry >> 63) & 1
    if not present:
        return None
    pfn = entry & ((1 << 55) - 1)
    return (pfn << 12) | offset


def print_tensor_gpa(label, tensor):
    tensor = tensor.contiguous()
    va = tensor.data_ptr()
    n_bytes = tensor.numel() * tensor.element_size()
    n_pages = (n_bytes + 4095) // 4096

    pages_per_ch = 49
    pages_per_img = 147
    ch_names = ['R', 'G', 'B']

    gpas = []
    for pg in range(n_pages):
        g = va_to_gpa(va + pg * 4096)
        gpas.append(g)

    present = sum(1 for g in gpas if g is not None)
    if not present:
        print(f"[GPA] {label}: all pages not present", flush=True)
        return

    n_images = tensor.shape[0] if tensor.dim() == 4 else 1
    print(f"[GPA_SUMMARY] {label}: images={n_images} pages={n_pages} "
          f"present={present} shape={tuple(tensor.shape)} bytes={n_bytes}",
          flush=True)

    for pg, g in enumerate(gpas):
        if g is None:
            continue
        img_idx = pg // pages_per_img
        ch_idx = (pg % pages_per_img) // pages_per_ch
        ch_pg = (pg % pages_per_img) % pages_per_ch
        ch = ch_names[ch_idx] if ch_idx < 3 else '?'
        print(f"[GPA_PAGE] {label} img={img_idx} ch={ch} ch_pg={ch_pg} "
              f"GPA=0x{g & ~0xfff:016x}", flush=True)


def _tty_print(msg):
    try:
        with open("/dev/tty", "w") as tty:
            tty.write(msg + "\n")
            tty.flush()
    except OSError:
        print(msg, flush=True)


def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument("--study_type", default="XR_WRIST")
    p.add_argument("--max_iters", type=int, default=10)
    p.add_argument("--phase", default="valid", choices=["train", "valid"])
    p.add_argument("--host-addr", default=None)
    p.add_argument("--batch_size", type=int, default=1)
    return p.parse_args()


@torch.inference_mode()
def main():
    global _HOST_ADDR
    args = parse_args()
    if args.host_addr:
        _HOST_ADDR = args.host_addr

    study_data = get_study_level_data(study_type=args.study_type)
    dataloaders = get_dataloaders(study_data, batch_size=args.batch_size,
                                 num_workers=0)

    model = densenet169(pretrained=True)
    model = model.cuda()
    model.eval()

    phase = args.phase
    n_total = len(dataloaders[phase])
    n_iters = min(args.max_iters, n_total)

    print(f"[INFO] phase={phase}  max_iters={n_iters}  "
          f"dataset_size={n_total}  batch_size={args.batch_size}",
          flush=True)
    print(f"[INFO] NO mul_(1.0) — relies on persistent write-protect",
          flush=True)

    data_iter = iter(dataloaders[phase])

    for i in range(n_iters):
        # 1) Signal host -> start tracking
        _signal_host("/tmp/d2h_start")
        time.sleep(3)

        # 2) DataLoader writes to tensor -> faults via persistent write-protect
        data = next(data_iter)
        inputs = data['images'][0]

        load_done_ns = time.clock_gettime_ns(time.CLOCK_REALTIME)
        print(f"[TS] iter{i}/input: load_done_realtime_ns={load_done_ns}",
              flush=True)
        print_tensor_gpa(f"iter{i}/input", inputs)

        _tty_print(f"[iter{i}] input loaded, sending to GPU")

        inputs = inputs.cuda()
        outputs = model(inputs)
        pred = torch.mean(outputs).item()

        _signal_host("/tmp/d2h_done")
        _tty_print(f"[iter{i}] done  pred={pred:.4f}")

    print(f"[INFO] {n_iters} iterations complete.", flush=True)


if __name__ == "__main__":
    main()
