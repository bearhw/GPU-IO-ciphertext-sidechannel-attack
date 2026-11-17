#!/usr/bin/env python3
"""
guest_shapes_loader.py — 3DShapes victim inside the SNP guest (MURA loader protocol).

  index -> 64x64 image -> Resize(224) -> ToTensor -> Normalize -> (3,224,224) f32

Protocol with the host (identical to guest_mura_loader.py, so MURA's stage-2 code
applies unchanged):
  1. preprocess, allocate the destination tensor and fault its pages in (zero_)
  2. print GUEST_READY_FOR_TRACK, wait for a newline (host arms the tracker)
  3. copy the tensor into the destination: one sweep of 147 page writes
  4. [--gpu] run the ResNet-18 victim on the GPU (CC on): .cuda() reads the CPU
     tensor through the encrypted bounce buffer, as in real confidential inference
  5. print GT: shape, tensor base offset, GPA of every tensor page, GUEST_LOAD_READY
  6. [--wait_for_host] hold the tensor until /tmp/host_read_done appears

  python3 guest_shapes_loader.py --index 3 --split test [--gpu] [--wait_for_host]
"""
import argparse
import os
import struct
import sys
import time

import numpy as np
import torch
from PIL import Image
from torchvision import transforms

HOME = os.path.expanduser("~ubuntu")
DATA = os.path.join(HOME, "shapes3d", "datasets")
CKPT = os.path.join(HOME, "shapes3d", "victim_resnet18.pth")
SHAPES = ["cube", "cylinder", "sphere", "capsule"]


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
    ap.add_argument("--split", default="test", choices=["test", "capture_train"])
    ap.add_argument("--gpu", action="store_true")
    ap.add_argument("--wait_for_host", action="store_true")
    a = ap.parse_args()

    z = np.load(os.path.join(DATA, f"shapes3d_{a.split}.npz"))
    i = a.index % len(z["shape"])
    img, shape, gidx = z["images"][i], int(z["shape"][i]), int(z["index"][i])

    model = None
    if a.gpu:
        from torchvision import models
        model = models.resnet18(weights=None)
        model.fc = torch.nn.Linear(model.fc.in_features, 4)
        model.load_state_dict(torch.load(CKPT, map_location="cpu"))
        model = model.cuda().eval()

    tf = transforms.Compose([
        transforms.Resize((224, 224)),
        transforms.ToTensor(),
        transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225]),
    ])
    src = tf(Image.fromarray(img)).contiguous()
    dst = torch.empty_like(src).contiguous()
    dst.zero_()

    print("GUEST_READY_FOR_TRACK", flush=True)
    try:
        sys.stdin.readline()
    except Exception:
        pass
    dst.copy_(src)

    pred = None
    if model is not None:
        with torch.no_grad():
            pred = int(model(dst.unsqueeze(0).cuda()).argmax(1).item())

    va = dst.data_ptr()
    nbytes = dst.numel() * dst.element_size()
    first, last = va // 4096, (va + nbytes - 1) // 4096
    print("GUEST_LOAD_START", flush=True)
    print(f"CLASS: {SHAPES[shape]}", flush=True)
    print(f"IMG_PATH: 3dshapes[{gidx}] {a.split}[{i}]", flush=True)
    print(f"BASE_OFF: {va % 4096}", flush=True)
    print(f"PAGES_TOTAL: {last - first + 1}", flush=True)
    if pred is not None:
        print(f"GPU_PRED: {SHAPES[pred]}", flush=True)
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
