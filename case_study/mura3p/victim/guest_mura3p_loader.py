#!/usr/bin/env python3
"""
guest_mura3p_loader.py — MURA victim inside the SNP guest, ground truth for all 3 planes.

Same preprocessing and handshake as cc_uvm/.../mura/guest_mura_loader.py (the
victim of the MURA case study); the only change is that ground truth covers the
whole (3,224,224) tensor (148 pages incl. the base offset), not just plane R:

  1. load valid/train image, Resize(224) -> ToTensor -> Normalize, allocate dst, zero_()
  2. GUEST_READY_FOR_TRACK, wait for a newline (host arms the tracker)
  3. dst.copy_(src)
  4. print CLASS, IMG_PATH, BASE_OFF, PAGES_TOTAL, GPA_PAGE x N, GUEST_LOAD_READY
  5. [--wait_for_host] hold dst until /tmp/host_read_done

  python3 guest_mura3p_loader.py --index 3 --split valid --wait_for_host
"""
import argparse
import os
import struct
import sys
import time

import torch
from PIL import Image
from torchvision import transforms

MURA = "/home/ubuntu/cc_uvm/pytorch_uvm310_test/mura"


def va_to_gpa(va):
    with open("/proc/self/pagemap", "rb") as f:
        f.seek((va // 4096) * 8)
        e = struct.unpack("Q", f.read(8))[0]
    if not (e >> 63) & 1:
        return None
    return ((e & ((1 << 55) - 1)) << 12) | (va % 4096)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--index", type=int, required=True)
    ap.add_argument("--split", default="valid", choices=["valid", "train"])
    ap.add_argument("--wait_for_host", action="store_true")
    a = ap.parse_args()

    with open(f"{MURA}/mura_downloads/{a.split}_image_paths.csv") as f:
        paths = [l.strip() for l in f if l.strip()]
    rel = paths[a.index % len(paths)]
    cls = rel.split("/")[2].replace("XR_", "")
    img_path = os.path.join(MURA, rel.replace("MURA-v1.1", "mura_downloads"))

    tf = transforms.Compose([
        transforms.Resize((224, 224)),
        transforms.ToTensor(),
        transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
    ])
    src = tf(Image.open(img_path).convert("RGB")).contiguous()
    dst = torch.empty_like(src).contiguous()
    dst.zero_()

    print("GUEST_READY_FOR_TRACK", flush=True)
    try:
        sys.stdin.readline()
    except Exception:
        pass
    dst.copy_(src)

    va = dst.data_ptr()
    nbytes = dst.numel() * dst.element_size()
    first, last = va // 4096, (va + nbytes - 1) // 4096
    print("GUEST_LOAD_START", flush=True)
    print(f"CLASS: {cls}", flush=True)
    print(f"IMG_PATH: {img_path}", flush=True)
    print(f"BASE_OFF: {va % 4096}", flush=True)
    print(f"PAGES_TOTAL: {last - first + 1}", flush=True)
    for pg in range(first, last + 1):
        g = va_to_gpa(pg * 4096)
        print(f"GPA_PAGE: 0x{g & ~0xfff:016x}" if g is not None else "GPA_PAGE: NONE", flush=True)
    print("GUEST_LOAD_READY", flush=True)

    if a.wait_for_host:
        flag = "/tmp/host_read_done"
        if os.path.exists(flag):
            os.remove(flag)
        while not os.path.exists(flag):
            time.sleep(0.2)
        try:
            os.remove(flag)
        except Exception:
            pass
        print("GUEST_LOAD_DONE", flush=True)


if __name__ == "__main__":
    main()
