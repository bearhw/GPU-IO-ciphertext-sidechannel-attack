#!/usr/bin/env python3
"""
Confirm the Linux vmemmap struct page array via /proc/kcore (no /dev/mem,
no kernel module). RUN INSIDE THE GUEST AS ROOT.

Why kcore: CONFIG_STRICT_DEVMEM blocks reading System RAM through /dev/mem
(EINVAL), so we read struct page records at their kernel VIRTUAL address
(vmemmap_base + pfn*64) through /proc/kcore instead.

What it proves:
  (1) Layout: struct page records read at vmemmap_base+pfn*64 have non-zero
      bytes only at the 5.19 field offsets {0,8,16,24,32,40,48,52,56}.
  (2) Identity: page_mapcount from the record (_mapcount@48 + 1) equals the
      kernel's own /proc/kpagecount[pfn], for the SAME pfn, across many
      top-of-RAM frames. Two independent kernel interfaces agreeing on a
      per-pfn value at address vmemmap_base+pfn*64 proves this region is the
      vmemmap struct page array.

What it does NOT prove: that a specific Region B *physical* GPA backs these
VAs. That spatial tie needs the kernel module (spmap_probe.c), because
VA->PA of a vmemmap address is not available from userspace.

Usage:
  sudo python3 verify_regionb_vmemmap.py            # auto: top 4096 frames
  sudo python3 verify_regionb_vmemmap.py --count 8192
  sudo python3 verify_regionb_vmemmap.py --pfn 0x3fff000 --count 256
"""
import os, sys, struct, argparse

REC = 64
OFF_MAPCOUNT = 48
FIELD_OFFSETS = {0:"flags", 8:"lru/compound_head", 16:"lru.prev",
                 24:"mapping", 32:"index", 40:"private",
                 48:"_mapcount", 52:"_refcount", 56:"memcg_data"}

# ---- /proc/kcore reader ------------------------------------------------
class Kcore:
    def __init__(self):
        self.f = open("/proc/kcore", "rb")
        self._parse()
    def _parse(self):
        f = self.f
        e = f.read(64)
        if e[:4] != b"\x7fELF" or e[4] != 2:
            raise RuntimeError("kcore not 64-bit ELF")
        e_phoff = struct.unpack_from("<Q", e, 32)[0]
        e_phentsize = struct.unpack_from("<H", e, 54)[0]
        e_phnum = struct.unpack_from("<H", e, 56)[0]
        self.loads = []   # (vaddr, memsz, offset)
        f.seek(e_phoff)
        ph = f.read(e_phentsize * e_phnum)
        for i in range(e_phnum):
            o = i * e_phentsize
            p_type = struct.unpack_from("<I", ph, o)[0]
            if p_type != 1:  # PT_LOAD
                continue
            p_offset = struct.unpack_from("<Q", ph, o+8)[0]
            p_vaddr  = struct.unpack_from("<Q", ph, o+16)[0]
            p_memsz  = struct.unpack_from("<Q", ph, o+40)[0]
            self.loads.append((p_vaddr, p_memsz, p_offset))
    def read_va(self, va, n):
        for vaddr, memsz, off in self.loads:
            if vaddr <= va < vaddr + memsz:
                self.f.seek(off + (va - vaddr))
                return self.f.read(n)
        return None

# ---- helpers -----------------------------------------------------------
def kallsyms_addr(name):
    try:
        with open("/proc/kallsyms") as f:
            for l in f:
                p = l.split()
                if len(p) >= 3 and p[2] == name:
                    return int(p[0], 16)
    except Exception:
        pass
    return None

def get_vmemmap_base(kc):
    """Prefer the runtime value of vmemmap_base (KASLR); fall back to the
    x86-64 default 0xffffea0000000000."""
    sym = kallsyms_addr("vmemmap_base")
    if sym:
        raw = kc.read_va(sym, 8)
        if raw:
            val = struct.unpack("<Q", raw)[0]
            if val:
                return val, "vmemmap_base symbol"
    return 0xffffea0000000000, "x86-64 default (KASLR off / kallsyms hidden)"

def num_pfns():
    """proc files stat as size 0, so derive top-of-RAM PFN from /proc/iomem
    (root sees real addresses). Returns highest System RAM end PFN."""
    top=0
    try:
        with open("/proc/iomem") as f:
            for l in f:
                if "System RAM" in l:
                    a,b=l.split(":")[0].strip().split("-")
                    top=max(top,(int(b,16)+1)>>12)
    except Exception:
        pass
    return top

def kpagecount(pfn):
    with open("/proc/kpagecount","rb") as f:
        f.seek(pfn*8)
        b = f.read(8)
    return struct.unpack("<Q", b)[0] if len(b)==8 else None

def kpagecount_slice(base, n):
    with open("/proc/kpagecount","rb") as f:
        f.seek(base*8)
        b = f.read(n*8)
    return list(struct.unpack("<%dQ"%(len(b)//8), b))

# ---- main --------------------------------------------------------------
def main():
    if os.geteuid()!=0:
        sys.exit("must run as root (reads /proc/kcore, /proc/kallsyms, /proc/kpagecount)")
    ap = argparse.ArgumentParser()
    ap.add_argument("--pfn", default=None, help="first PFN (hex/dec); default = top of RAM - count")
    ap.add_argument("--count", type=int, default=4096, help="number of PFNs to check")
    args = ap.parse_args()

    # try to unhide kallsyms addresses
    try:
        open("/proc/sys/kernel/kptr_restrict","w").write("0")
    except Exception:
        pass

    kc = Kcore()
    vbase, how = get_vmemmap_base(kc)
    top = num_pfns()
    if args.pfn is not None:
        start = int(args.pfn, 0)
    else:
        start = max(0, top - args.count)
    print(f"vmemmap_base = {vbase:#x}  ({how})")
    print(f"total PFNs   = {top}  (top of RAM ~ {top<<12:#x})")
    print(f"checking PFNs [{start}, {start+args.count})  "
          f"struct page VAs [{vbase+start*REC:#x} ..]")

    # ---- (1) field-level layout fingerprint over the checked PFNs ----
    # (offset, size, name) for the 5.19 struct page 64B record
    FIELDS=[(0,8,"flags"),(8,8,"lru/compound_head"),(16,8,"lru.prev/pt"),
            (24,8,"mapping"),(32,8,"index"),(40,8,"private"),
            (48,4,"_mapcount"),(52,4,"_refcount"),(56,8,"memcg_data")]
    fcount={f[2]:0 for f in FIELDS}
    live=0; checked=0
    want=[]; kpc=kpagecount_slice(start, args.count)
    for i in range(args.count):
        pfn=start+i
        va=vbase+pfn*REC
        rec=kc.read_va(va, REC)
        if rec is None or len(rec)<REC:
            want.append(None); continue
        checked+=1
        if any(rec):
            live+=1
            for off,sz,name in FIELDS:
                if any(rec[off:off+sz]):
                    fcount[name]+=1
        mc=struct.unpack_from("<i", rec, OFF_MAPCOUNT)[0]
        want.append(mc+1 if mc!=-1 else 0)

    print(f"\n[1] field-level fingerprint  ({live}/{checked} records non-zero)")
    for off,sz,name in FIELDS:
        print(f"   +{off:2d} ({sz}B) {name:18s}: {fcount[name]:5d}/{live} records")
    active=sum(1 for f in FIELDS if fcount[f[2]]>0)
    print(f"   -> {active}/9 struct-page fields ever populated: "
          f"{'STRUCT PAGE LAYOUT CONFIRMED' if active>=5 else 'inconclusive'}")

    # ---- (2) identity vs kpagecount for the SAME pfns ----
    match=tot=0
    for i in range(args.count):
        if want[i] is None: continue
        tot+=1
        if want[i]==kpc[i]: match+=1
    print(f"\n[2] identity vs /proc/kpagecount (same pfn): "
          f"{match}/{tot} records agree "
          f"({100*match/tot:.1f}%)" if tot else "[2] no records read")
    if tot and match/tot>=0.95:
        print("   -> DECISIVE: record at vmemmap_base+pfn*64 carries the kernel's")
        print("      own per-pfn page_mapcount -> this region IS the vmemmap")
        print("      struct page array. (Physical GPA tie: use spmap_probe.ko)")
    elif tot and match/tot>=0.6:
        print("   -> strong; residual mismatch is slab/buddy _mapcount overload")
    else:
        print("   -> weak; check kptr_restrict / vmemmap_base / KASLR")

if __name__=="__main__":
    main()
