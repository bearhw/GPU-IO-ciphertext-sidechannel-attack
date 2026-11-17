#!/usr/bin/env python3
"""build_v6r_db.py — Rebuild the v6r retrieval database with the current encoder.

v6r retrieval = encode the query sparsity, then return the nearest image in a
precomputed embedding DB (stage5: argmax(v6r_emb_db @ q.T) -> v6r_img_db[idx]).
When the encoder is retrained the DB embeddings go stale, so regenerate them here.

The DB is the attacker's reference set: MNIST *train* images and the embedding of
each one's clean sparsity (the encoder maps a real capture into this clean space).
Retrieval can only ever return an image that is IN this DB, so on the test split it
returns the nearest train digit — an inherent cap, not a bug.

Outputs (what stage5 loads):
  v6r_embeddings_new.npy   (N, 128) float32, L2-normalized
  v6r_images_new.npy       (N, 28, 28) float32 in [0,1]

Usage:
  python3 build_v6r_db.py                      # encoder sparsity_encoder_v6r.pth, 60000 train imgs
  python3 build_v6r_db.py --n 60000 --encoder sparsity_encoder_v6r.pth
"""

import argparse
import os

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F

HERE = os.path.dirname(os.path.abspath(__file__))
CHUNK_BYTES, PAGE, IMG_BYTES, NUM_CHUNKS = 16, 4096, 3136, 196


class SparsityEncoder(nn.Module):
    """Must match train_v6r / stage5 (196 -> 128)."""
    def __init__(self, input_dim=196, embed_dim=128):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(input_dim, 512), nn.BatchNorm1d(512), nn.ReLU(inplace=True),
            nn.Linear(512, 256),       nn.BatchNorm1d(256), nn.ReLU(inplace=True),
            nn.Linear(256, embed_dim),
        )

    def forward(self, x):
        return F.normalize(self.net(x), dim=1)


def clean_sparsity(img01: np.ndarray) -> list:
    """Deterministic (offset-0) sparsity of a clean image: chunk=1 if any pixel != 0."""
    b = img01.astype(np.float32).flatten().tobytes()
    page = bytearray(PAGE)
    page[:IMG_BYTES] = b
    return [1 if any(page[k * CHUNK_BYTES:(k + 1) * CHUNK_BYTES]) else 0
            for k in range(NUM_CHUNKS)]


def load_train_images(n: int) -> np.ndarray:
    raw = os.path.join(HERE, "data", "MNIST", "raw", "train-images-idx3-ubyte")
    with open(raw, "rb") as f:
        f.seek(16)
        buf = f.read(n * 784)
    return np.frombuffer(buf, dtype=np.uint8).reshape(-1, 28, 28).astype(np.float32) / 255.0


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--encoder", default=os.path.join(HERE, "sparsity_encoder_v6r.pth"))
    p.add_argument("--n", type=int, default=60000, help="Reference images (MNIST train)")
    p.add_argument("--emb-out", default=os.path.join(HERE, "v6r_embeddings_new.npy"))
    p.add_argument("--img-out", default=os.path.join(HERE, "v6r_images_new.npy"))
    args = p.parse_args()

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    enc = SparsityEncoder().to(device)
    enc.load_state_dict(torch.load(args.encoder, map_location=device))
    enc.eval()

    imgs = load_train_images(args.n)
    print(f"[db] encoding {len(imgs)} reference images with {os.path.basename(args.encoder)}")
    sp = np.array([clean_sparsity(im) for im in imgs], dtype=np.float32)

    embs = []
    with torch.no_grad():
        for i in range(0, len(sp), 1024):
            z = enc(torch.tensor(sp[i:i + 1024], dtype=torch.float32, device=device))
            embs.append(z.cpu().numpy())
    embs = np.concatenate(embs).astype(np.float32)

    np.save(args.emb_out, embs)
    np.save(args.img_out, imgs.astype(np.float32))
    print(f"[db] wrote {args.emb_out} {embs.shape} and {args.img_out} {imgs.shape}")


if __name__ == "__main__":
    main()
