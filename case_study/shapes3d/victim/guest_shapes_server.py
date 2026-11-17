#!/usr/bin/env python3
"""
guest_shapes_server.py — resident 3DShapes victim (model loaded once), plus client.

A serving victim keeps its model on the GPU and handles requests; reloading the
model and re-initialising CUDA under CC for every sample cost ~50 s per capture.
The server listens on a unix socket; the client speaks guest_shapes_loader.py's
stdout/stdin protocol, so the host's Stage 2 is unchanged:

  client -> server : "<split> <index> <gpu 0|1>"
  server -> client : GUEST_READY_FOR_TRACK          (dst faulted in)
  client -> server : "GO"                           (host armed the tracker)
  server -> client : GT lines ... GUEST_LOAD_READY  (copy + optional GPU forward)
  client           : waits for /tmp/host_read_done, then "RELEASE"
  server -> client : GUEST_LOAD_DONE                (dst freed)

  sudo nohup python3 guest_shapes_server.py serve &
  python3 guest_shapes_server.py client --index 3 --split test --gpu --wait_for_host
"""
import argparse
import os
import socket
import struct
import sys
import time

SOCK = "/tmp/shapes_victim.sock"
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


def serve():
    import numpy as np
    import torch
    from PIL import Image
    from torchvision import models, transforms

    model = models.resnet18(weights=None)
    model.fc = torch.nn.Linear(model.fc.in_features, 4)
    model.load_state_dict(torch.load(CKPT, map_location="cpu"))
    model = model.cuda().eval()
    with torch.no_grad():
        model(torch.zeros(1, 3, 224, 224).cuda())          # warm up CUDA/cuDNN
    data = {s: np.load(os.path.join(DATA, f"shapes3d_{s}.npz")) for s in ("test", "capture_train")}
    tf = transforms.Compose([transforms.Resize((224, 224)), transforms.ToTensor(),
                             transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])])
    if os.path.exists(SOCK):
        os.remove(SOCK)
    srv = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    srv.bind(SOCK)
    os.chmod(SOCK, 0o777)
    srv.listen(1)
    print("SERVER_READY", flush=True)
    while True:
        conn, _ = srv.accept()
        f = conn.makefile("rw", buffering=1)
        try:
            split, idx, gpu = f.readline().split()
            z = data[split]
            i = int(idx) % len(z["shape"])
            img, shape, gidx = z["images"][i], int(z["shape"][i]), int(z["index"][i])
            src = tf(Image.fromarray(img)).contiguous()
            dst = torch.empty_like(src).contiguous()
            dst.zero_()
            f.write("GUEST_READY_FOR_TRACK\n")
            f.readline()                                     # GO
            dst.copy_(src)
            pred = None
            if gpu == "1":
                with torch.no_grad():
                    pred = int(model(dst.unsqueeze(0).cuda()).argmax(1).item())
            va = dst.data_ptr()
            nbytes = dst.numel() * dst.element_size()
            first, last = va // 4096, (va + nbytes - 1) // 4096
            out = ["GUEST_LOAD_START", f"CLASS: {SHAPES[shape]}", f"IMG_PATH: 3dshapes[{gidx}] {split}[{i}]",
                   f"BASE_OFF: {va % 4096}", f"PAGES_TOTAL: {last - first + 1}"]
            if pred is not None:
                out.append(f"GPU_PRED: {SHAPES[pred]}")
            for pg in range(first, last + 1):
                g = va_to_gpa(pg * 4096)
                out.append(f"GPA_PAGE: 0x{g & ~0xfff:016x}" if g is not None else "GPA_PAGE: NONE")
            out.append("GUEST_LOAD_READY")
            f.write("\n".join(out) + "\n")
            f.readline()                                     # RELEASE
            del dst, src
            f.write("GUEST_LOAD_DONE\n")
        except Exception as e:
            try:
                f.write(f"LOOP_ERR {e!r}\n")
            except Exception:
                pass
        finally:
            conn.close()


def client(a):
    s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    for _ in range(100):
        try:
            s.connect(SOCK)
            break
        except OSError:
            time.sleep(0.1)
    f = s.makefile("rw", buffering=1)
    f.write(f"{a.split} {a.index} {1 if a.gpu else 0}\n")
    for line in f:
        sys.stdout.write(line)
        sys.stdout.flush()
        if line.strip() == "GUEST_READY_FOR_TRACK":
            sys.stdin.readline()
            f.write("GO\n")
        elif line.strip() == "GUEST_LOAD_READY":
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
            f.write("RELEASE\n")
        elif line.strip() in ("GUEST_LOAD_DONE",) or line.startswith("LOOP_ERR"):
            break


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("mode", choices=["serve", "client"])
    ap.add_argument("--index", type=int, default=0)
    ap.add_argument("--split", default="test")
    ap.add_argument("--gpu", action="store_true")
    ap.add_argument("--wait_for_host", action="store_true")
    a = ap.parse_args()
    serve() if a.mode == "serve" else client(a)
