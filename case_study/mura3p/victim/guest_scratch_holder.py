#!/usr/bin/env python3
"""
guest_scratch_holder.py — keep a few guest pages pinned and idle for the host.

The attack reads every page under one physical address (FIXED_GPA). MURA used a
page an ICMP packet had passed through; once the packet is freed the kernel reuses
that page (slab, bio, ...), and a page-move round trip that does not restore it
exactly then corrupts live kernel objects — the GPFs and panics seen in the MURA
and 3DShapes runs. A page owned by an idle process is never touched by the guest,
so a bad round trip costs nothing. This only changes which scratch page the
hypervisor uses; the attack reads and compares ciphertext exactly as before.

Writes the GPAs to /tmp/scratch_gpas and sleeps forever.
  sudo nohup python3 guest_scratch_holder.py &
"""
import ctypes
import mmap
import struct
import time

N = 8
buf = mmap.mmap(-1, N * 4096, flags=mmap.MAP_PRIVATE | mmap.MAP_ANONYMOUS)
for i in range(N):
    buf[i * 4096] = 1
libc = ctypes.CDLL("libc.so.6", use_errno=True)
addr = ctypes.addressof(ctypes.c_char.from_buffer(buf))
libc.mlock(ctypes.c_void_p(addr), ctypes.c_size_t(N * 4096))

gpas = []
with open("/proc/self/pagemap", "rb") as f:
    for i in range(N):
        va = addr + i * 4096
        f.seek((va // 4096) * 8)
        e = struct.unpack("Q", f.read(8))[0]
        gpas.append((e & ((1 << 55) - 1)) << 12)
with open("/tmp/scratch_gpas", "w") as f:
    f.write("\n".join(hex(g) for g in gpas) + "\n")
while True:
    time.sleep(3600)
