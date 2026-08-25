import os, sys, struct, glob
from PIL import Image
from torchvision import transforms

DATA_ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "mura_downloads")
SAMPLE_N  = 5

def va_to_gpa(va):
    page_size = 4096
    page_num  = va // page_size
    offset    = va % page_size
    with open('/proc/self/pagemap', 'rb') as f:
        f.seek(page_num * 8)
        entry = struct.unpack('Q', f.read(8))[0]
    present = (entry >> 63) & 1
    if not present:
        raise RuntimeError(f"page not present: VA=0x{va:x}")
    pfn = entry & ((1 << 55) - 1)
    return (pfn << 12) | offset

to_tensor = transforms.Compose([
    transforms.Resize((224, 224)),
    transforms.ToTensor(),
])

paths = sorted(glob.glob(f"{DATA_ROOT}/train/XR_WRIST/**/*.png", recursive=True))[:SAMPLE_N]

print(f"pid={os.getpid()}  images={len(paths)}\n")
for i, p in enumerate(paths):
    img = Image.open(p).convert("L")
    t   = to_tensor(img).contiguous()

    va      = t.data_ptr()
    n_bytes = t.numel() * t.element_size()
    n_pages = (n_bytes + 4095) // 4096

    print(f"[{i}] {'/'.join(p.split('/')[-3:])}")
    print(f"    shape={tuple(t.shape)}  dtype={t.dtype}  bytes={n_bytes:,}  pages={n_pages}")
    print(f"    VA          = 0x{va:016x}")

    for pg in range(n_pages):
        addr = va + pg * 4096
        gpa  = va_to_gpa(addr)
        print(f"    page[{pg:>3d}]    VA=0x{addr:016x}  GPA=0x{gpa:016x}")
    print()
