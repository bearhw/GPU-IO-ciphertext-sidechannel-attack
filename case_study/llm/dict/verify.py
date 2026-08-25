#!/usr/bin/env python3
"""
verify.py — AES-block-aware comparison of cp.out vs gpa.out

subcommands:
  calibrate  Find current token offset (O_cp) in cp.out → compute required --prefix
  verify     Compare cp.out vs gpa.out at clean AES block boundaries

calibrate usage:
  python3 verify.py calibrate cp.out \\
      --token-ids "12472,2090,315,11486" --target-offset 0x3f8

verify usage:
  python3 verify.py verify --cp cp.out --post gpa.out \\
      --token-offset 0x3f8 --token-ids "12472,2090,315,11486"
"""

import argparse
import re
import struct
import sys

HEX_LINE = re.compile(r'([0-9a-f]{12,16}):\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+)')


def parse_dump(path: str) -> bytes:
    """Parse xp /512gx dump file into raw bytes (little-endian 64-bit pairs in order)."""
    chunks = []
    with open(path, 'r', errors='replace') as f:
        for line in f:
            m = HEX_LINE.search(line)
            if m:
                v1 = int(m.group(2), 16)
                v2 = int(m.group(3), 16)
                chunks.append(struct.pack('<QQ', v1, v2))
    if not chunks:
        raise ValueError(f"No data lines found: {path}")
    return b''.join(chunks)


def clean_aes_blocks(token_offset: int, token_len: int) -> list[int]:
    """
    Return page offsets of 16-byte AES blocks fully contained within
    the token byte range [token_offset, token_offset+token_len).

    Partial blocks at the boundaries are excluded because surrounding
    data differs and cannot be compared.
    """
    end = token_offset + token_len
    first_full = (token_offset + 15) & ~15   # first 16-byte boundary >= token_offset
    return [b for b in range(first_full, end - 15, 16) if b + 16 <= 4096]


def cmd_calibrate(args) -> None:
    token_ids  = [int(x) for x in args.token_ids.split(',')]
    token_bytes = struct.pack(f'<{len(token_ids)}q', *token_ids)
    token_len   = len(token_bytes)
    target      = args.target_offset

    cp = parse_dump(args.cp_out)

    idx = cp.find(token_bytes)
    if idx < 0:
        print(f"[!] Token pattern not found in cp.out.")
        print(f"    Pattern: {token_bytes.hex()}")
        sys.exit(1)

    print(f"O_cp (current token start offset in page): 0x{idx:03x}  ({idx})")
    print(f"target_offset:                              0x{target:03x}  ({target})")

    needed = (target - idx) % token_len
    print(f"Required --prefix: {needed}")
    if needed == 0:
        print("-> Already aligned. No prefix needed.")
    else:
        print(f"-> Re-send with --prefix {needed} in send_tokens.py.")

    blocks = clean_aes_blocks(target, token_len)
    if blocks:
        print(f"\nComparable clean AES blocks: {[f'0x{b:03x}' for b in blocks]}")
        print(f"  (total {len(blocks)} blocks, {len(blocks) * 16} bytes = "
              f"{len(blocks) * 2} token(s) fully covered)")
    else:
        print("\n[!] No clean AES blocks — token straddles all block boundaries")


def cmd_verify(args) -> None:
    token_ids  = [int(x) for x in args.token_ids.split(',')]
    token_len  = len(token_ids) * 8
    token_offset = args.token_offset

    cp   = parse_dump(args.cp)
    post = parse_dump(args.post)

    blocks = clean_aes_blocks(token_offset, token_len)

    print(f"Token span : 0x{token_offset:03x} – 0x{token_offset + token_len - 1:03x}"
          f"  ({token_len} bytes, {len(token_ids)} tokens)")
    if not blocks:
        print("[!] No clean AES blocks. Token straddles block boundaries.")
        print("    -> Adjust prefix in send_tokens.py or use a different token position.")
        sys.exit(1)

    print(f"Clean AES blocks: {[f'0x{b:03x}' for b in blocks]}")
    print()

    all_match = True
    for blk in blocks:
        cp_b   = cp  [blk : blk + 16]
        post_b = post[blk : blk + 16]
        ok = (cp_b == post_b)
        if not ok:
            all_match = False
        status = "MATCH ✓" if ok else "MISMATCH ✗"
        print(f"  [+0x{blk:03x}–+0x{blk+15:03x}]  {status}")
        print(f"    cp  : {cp_b.hex()}")
        print(f"    post: {post_b.hex()}")

    print()
    if all_match:
        print("Result: MATCH ✓  — token confirmed at this block")
    else:
        print("Result: MISMATCH ✗  — token mismatch or alignment error")
        print("        Use the calibrate subcommand to check alignment.")


def main() -> None:
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest='cmd', required=True)

    # calibrate
    c = sub.add_parser('calibrate', help='Find O_cp in cp.out and compute required prefix')
    c.add_argument('cp_out', help='Pre-swap cp page dump file')
    c.add_argument('--token-ids', required=True,
                   help='Comma-separated int64 token IDs (e.g. "12472,2090,315,11486")')
    c.add_argument('--target-offset', required=True, type=lambda x: int(x, 0),
                   help='Page offset of indication GPA (e.g. 0x3f8)')

    # verify
    v = sub.add_parser('verify', help='Compare cp.out vs gpa.out at AES block boundaries')
    v.add_argument('--cp',   required=True, help='Pre-swap cp page dump')
    v.add_argument('--post', required=True, help='Post-swap cp page dump')
    v.add_argument('--token-offset', required=True, type=lambda x: int(x, 0),
                   help='Page offset of indication GPA (e.g. 0x3f8)')
    v.add_argument('--token-ids', required=True,
                   help='Comma-separated int64 token IDs (e.g. "12472,2090,315,11486")')

    args = p.parse_args()
    if args.cmd == 'calibrate':
        cmd_calibrate(args)
    else:
        cmd_verify(args)


if __name__ == '__main__':
    main()
