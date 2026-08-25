import argparse
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
    p = argparse.ArgumentParser()
    p.add_argument("--index", type=int, default=114)
    args = p.parse_args()

    # 1. Load MNIST dataset (keep as 0.0~1.0 float32)
    transform = transforms.Compose([transforms.ToTensor()])
    dataset = datasets.MNIST('../data', train=True, download=True, transform=transform)

    data, target = dataset[args.index]
    
    # Convert pixel data to float32 numpy array (784 elements)
    pixel_data = data.squeeze().numpy().astype(np.float32)
    
    # 2. Allocate page-aligned memory (4096 bytes)
    # Force pixel data to start at the beginning of the page (offset 0)
    PAGE_SIZE = 4096
    libc = ctypes.CDLL("libc.so.6")
    
    # Allocate page-aligned memory via posix_memalign
    raw_ptr = ctypes.c_void_p()
    libc.posix_memalign(ctypes.byref(raw_ptr), PAGE_SIZE, PAGE_SIZE)
    
    # Copy pixel data to aligned address (784 * 4 bytes = 3136 bytes)
    # Remaining 960 bytes stay zero (satisfies v1 model's zero-padding requirement)
    ctypes.memmove(raw_ptr, pixel_data.ctypes.data, pixel_data.nbytes)
    
    pixel_va = raw_ptr.value
    gpa = get_gpa(pixel_va)

    if gpa:
        print(f"--- Alignment Fixed for v1 Model ---")
        print(f"Target Label: {target}")
        print(f"Image VA (Aligned):  0x{pixel_va:016x}")
        print(f"Image GPA (Aligned): 0x{gpa:016x}")
        
        print(f"\n[Step 1] Capture Zero Page (before loading image or from other zero page)")
        print(f"[Step 2] Capture Image Page in qemu-monitor:")
        print(f"xp /4096bx 0x{gpa:x}")
        
        # Verify first pixel's float32 byte value (little-endian)
        first_pixel_hex = pixel_data.flatten()[0].tobytes().hex()
        print(f"\nFirst pixel value (float32): {pixel_data.flatten()[0]}")
        print(f"First pixel bytes (Hex): 0x{first_pixel_hex}")
        print(f"Note: This should match the first 4 bytes of your QEMU dump.")
    else:
        print("Page not present in pagemap. Try accessing the memory first.")

    input("\nPress Enter to exit and release memory...")
    # Free allocated memory
    libc.free(raw_ptr)

if __name__ == '__main__':
    main()
