import os
import ctypes
import torch
import numpy as np
from torchvision import datasets, transforms

def get_gpa(vaddr):
    """Convert CPU virtual address to guest physical address (GPA)."""
    page_size = os.sysconf('SC_PAGE_SIZE')
    page_num = vaddr // page_size
    offset = vaddr % page_size
    try:
        with open('/proc/self/pagemap', 'rb') as f:
            f.seek(page_num * 8)
            entry = int.from_bytes(f.read(8), 'little')
        if not (entry >> 63 & 1):
            return None
        pfn = entry & ((1 << 55) - 1)
        return pfn * page_size + offset
    except IOError:
        return None
def main():
    # 1. CUDA initialization warmup (eliminate ~1,300 pushbuffer noise pages)
    print("[Guest] CUDA initialization warmup...")
    dummy = torch.zeros(1).to('cuda')
    torch.cuda.synchronize() if torch.cuda.is_available() else None

    # 2. Load data
    transform = transforms.Compose([transforms.ToTensor()])
    dataset = datasets.MNIST('../data', train=True, download=True, transform=transform)
    data, target = dataset[11] 

    # Keep as unpinned tensor: under SEV-SNP, pin_memory() converts pages to
    # shared (unencrypted) memory, letting GPU DMA directly without SWIOTLB
    # bounce. h2d_tracker needs the image page in encrypted guest RAM to
    # detect src/dst faults.
    image_tensor = data.squeeze().to(torch.float32)

    pixel_va = image_tensor.data_ptr()
    image_gpa = get_gpa(pixel_va)

    if image_gpa:
        print(f"Target Label: {target}")
        print(f"Image GPA: 0x{image_gpa:016x}")

        # Synchronization point
        input("\n[Guest] Ready. Run h2d_tracker on host, then press Enter...")

        # Trigger GPU copy: encrypted page → SWIOTLB bounce → GPU DMA
        print("Sending data to GPU...")
        image_tensor_gpu = image_tensor.to('cuda')
        torch.cuda.synchronize() if torch.cuda.is_available() else None
        print("Transfer complete!")

if __name__ == '__main__':
    main()

