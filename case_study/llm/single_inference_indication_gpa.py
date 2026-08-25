"""
Run inference GPA reporting on ReXGradient test samples.

Usage:
    python3 single_inference_indication_gpa.py --index 0
    python3 single_inference_indication_gpa.py --index 5 --gpa-only --calibrate
    # One process, allocate a fresh input_ids per sample (stdin protocol):
    python3 single_inference_indication_gpa.py --gpa-only --calibrate --stdin-loop
"""
import argparse
import ctypes
import gc
import json
import mmap
import os
import sys

import torch
from PIL import Image

from utils import load_model, resolve_path, print_cpu_tensor_gpa, _virt_to_gpa
from prediction import build_user_prompt, load_rgb

_libc = ctypes.CDLL("libc.so.6", use_errno=True)
_MADV_NOHUGEPAGE = 15
_PROT_READ = 1
_PROT_WRITE = 2
_MAP_PRIVATE = 0x02
_MAP_ANONYMOUS = 0x20
_MAP_POPULATE = 0x8000


def parse_args():
    p = argparse.ArgumentParser(description="Single-sample VLM inference with Indication GPA tracking")
    p.add_argument("--model_id", type=str, default="Qwen/Qwen2-VL-2B-Instruct")
    p.add_argument("--finetuned_model_path", type=str, default=None, help="LoRA adapter dir (only used with --use_lora)")
    p.add_argument("--use_lora", action="store_true")
    p.add_argument("--test_image_folder", type=str, default="../rexgradient/ReXGradient")
    p.add_argument("--test_dataset", type=str, default="../rexgradient/ReXGradient/metadata/rexgradient_test.json")
    p.add_argument("--index", type=int, default=0, help="Sample index in the test dataset")
    p.add_argument("--max_new_tokens", type=int, default=200)
    p.add_argument("--gpa-only", action="store_true",
                   help="Find GPA only and exit — does not load model to VRAM (fast)")
    p.add_argument("--calibrate", action="store_true",
                   help="Calibration mode: additionally print tok_start and HEADER_CONST_HINT = tok_start - N")
    p.add_argument("--stdin-loop", action="store_true",
                   help="Reuse processor in one process; allocate fresh input_ids "
                        "per stdin index. Protocol: INDEX -> HOLDING -> NEXT|QUIT")
    return p.parse_args()


def load_raw_entries(json_path):
    with open(json_path, "r") as f:
        content = f.read().strip()
    if content.startswith("["):
        return json.loads(content)
    return [json.loads(line) for line in content.split("\n") if line.strip()]


def find_indication_token_span(processor, full_text: str, input_ids_tensor, indication: str):
    """Analyze input_ids structure to return the [start, end) token index of the indication."""
    tokenizer = processor.tokenizer
    IMAGE_PAD_ID = tokenizer.convert_tokens_to_ids("<|image_pad|>")
    VISION_END_ID = tokenizer.convert_tokens_to_ids("<|vision_end|>")

    ids_list = input_ids_tensor[0].tolist()
    N = ids_list.count(IMAGE_PAD_ID)
    print(f"  [GPA] <|image_pad|> count: N={N}")

    try:
        vision_end_idx = ids_list.index(VISION_END_ID)
    except ValueError:
        img_indices = [i for i, t in enumerate(ids_list) if t == IMAGE_PAD_ID]
        vision_end_idx = img_indices[-1] if img_indices else -1

    marker = "<|vision_end|>"
    marker_pos = full_text.find(marker)
    if marker_pos != -1:
        post_image_text = full_text[marker_pos + len(marker):]
    else:
        pad_marker = "<|image_pad|>"
        marker_pos = full_text.find(pad_marker)
        if marker_pos == -1:
            return None
        post_image_text = full_text[marker_pos + len(pad_marker):]

    char_start = post_image_text.find(indication)
    if char_start == -1:
        return None
    char_end = char_start + len(indication)

    post_enc = tokenizer(post_image_text, return_offsets_mapping=True, add_special_tokens=False)
    post_ids = post_enc["input_ids"]
    post_offsets = post_enc["offset_mapping"]

    tok_start, tok_end = None, None
    for i, (s, e) in enumerate(post_offsets):
        if s == e:
            continue
        if tok_start is None and e > char_start:
            tok_start = i
        if s < char_end:
            tok_end = i + 1

    if tok_start is None or tok_end is None:
        return None

    indication_ids = post_ids[tok_start:tok_end]
    candidate = vision_end_idx + 1 + tok_start
    if ids_list[candidate:candidate + len(indication_ids)] == indication_ids:
        return candidate, candidate + len(indication_ids)

    search_from = max(0, vision_end_idx + 1)
    n = len(indication_ids)
    for i in range(search_from, len(ids_list) - n + 1):
        if ids_list[i:i + n] == indication_ids:
            return i, i + n

    return None


def _page_span(ptr: int, nbytes: int) -> tuple[int, int]:
    base = ptr & ~0xFFF
    end = (ptr + nbytes + 0xFFF) & ~0xFFF
    return base, max(4096, end - base)


def _madvise_nohugepage_span(ptr: int, nbytes: int) -> None:
    try:
        base, length = _page_span(ptr, nbytes)
        _libc.madvise(ctypes.c_void_p(base), ctypes.c_size_t(length),
                      ctypes.c_int(_MADV_NOHUGEPAGE))
    except Exception:
        pass


def _mlock_span(ptr: int, nbytes: int) -> bool:
    base, length = _page_span(ptr, nbytes)
    rc = _libc.mlock(ctypes.c_void_p(base), ctypes.c_size_t(length))
    if rc != 0:
        err = ctypes.get_errno()
        print(f"  [pin] mlock failed errno={err} len=0x{length:x}", flush=True)
        return False
    return True


def _munlock_span(ptr: int, nbytes: int) -> None:
    try:
        base, length = _page_span(ptr, nbytes)
        _libc.munlock(ctypes.c_void_p(base), ctypes.c_size_t(length))
    except Exception:
        pass


class PinnedInputIds:
    """input_ids copied into anonymous mmap + mlock'd pages (not torch cache).

    Host SNP swap-back mutates guest RAM under the reported GPA. Holding a
    torch caching-allocator buffer across samples reused the same PFNs too
    quickly after RELEASED and raced RMP settle → systemic NO_MATCH.
    """

    def __init__(self, src: torch.Tensor):
        if src.device.type != "cpu":
            raise ValueError("PinnedInputIds expects CPU tensor")
        src = src.detach().contiguous()
        if src.dtype != torch.long and src.dtype != torch.int64:
            src = src.to(torch.long)
        self.shape = tuple(src.shape)
        self.numel = int(src.numel())
        self.nbytes = self.numel * 8
        # Page-align the mapping so token0 can sit at a stable offset.
        self.map_size = (self.nbytes + 0xFFF) & ~0xFFF
        self._mm = mmap.mmap(-1, self.map_size)
        # Touch / populate then copy.
        self._mm[:self.nbytes] = src.numpy().astype("<i8", copy=False).tobytes()
        if self.map_size > self.nbytes:
            self._mm[self.nbytes:self.map_size] = b"\x00" * (self.map_size - self.nbytes)

        self.ptr = ctypes.addressof(ctypes.c_char.from_buffer(self._mm))
        _madvise_nohugepage_span(self.ptr, self.map_size)
        if not _mlock_span(self.ptr, self.map_size):
            # Still usable; host may see migration risk.
            pass

        # Torch view over the pinned bytes — keeps API compatible.
        self.tensor = torch.frombuffer(
            self._mm, dtype=torch.int64, count=self.numel
        ).reshape(self.shape)

    def gpa(self) -> int | None:
        return _virt_to_gpa(self.ptr)

    def close(self) -> None:
        try:
            _munlock_span(self.ptr, self.map_size)
        except Exception:
            pass
        try:
            self.tensor = None
        except Exception:
            pass
        try:
            self._mm.close()
        except Exception:
            pass
        self._mm = None
        self.ptr = 0


def prepare_processor_and_model(args):
    if args.gpa_only:
        from transformers import AutoProcessor
        processor = AutoProcessor.from_pretrained(args.model_id)
        model = None
        device = None
    else:
        model, processor = load_model(args.model_id)
        model.eval()
        if args.use_lora:
            from peft import PeftModel
            model = PeftModel.from_pretrained(model, args.finetuned_model_path)
        device = "cuda" if torch.cuda.is_available() else "cpu"
        model = model.to(device)

    processor.tokenizer.padding_side = "left"
    processor.tokenizer.truncation_side = "right"
    processor.tokenizer.pad_token = processor.tokenizer.eos_token
    return processor, model, device


def allocate_and_report(args, processor, raw_entries, index: int, pin: bool):
    """Build input_ids for `index`. If pin=True, return PinnedInputIds hold.

    Returns (hold, input_ids_tensor) where hold is PinnedInputIds|None.
    """
    raw = raw_entries[index]
    indication = raw.get("indication", "") or ""

    image_path = resolve_path(args.test_image_folder, raw["image"].replace("..", "."))
    image = load_rgb(image_path)

    print("\n" + "=" * 60)
    print(f"  INDICATION (sample id: {raw.get('id')})")
    print("=" * 60)
    print(f"  {indication}")
    print("=" * 60 + "\n")

    sample = {
        "messages": [{
            "role": "user",
            "content": [
                {"type": "image", "image": image_path},
                {"type": "text", "text": raw["conversations"][0]["value"].replace("<image>", "").strip()},
            ],
        }]
    }
    full_text = build_user_prompt(processor, sample, model_id=args.model_id)

    inputs = processor(
        text=full_text,
        images=[image],
        return_tensors="pt",
        padding=False,
        truncation=True,
        max_length=4096,
    )
    src_ids = inputs["input_ids"].detach().contiguous().cpu().long()

    # Drop processor / image tensors before pinning so we do not hold huge
    # pixel_values alongside the attack buffer.
    del inputs
    del image
    gc.collect()

    hold = None
    if pin:
        hold = PinnedInputIds(src_ids)
        input_ids = hold.tensor
        del src_ids
        gc.collect()
    else:
        input_ids = src_ids
        _madvise_nohugepage_span(input_ids.data_ptr(),
                                int(input_ids.numel() * input_ids.element_size()))

    # Fault-check: every page of the tensor must be present for pagemap GPA.
    _ = int(input_ids.view(-1)[0])
    _ = int(input_ids.view(-1)[-1])

    print_cpu_tensor_gpa("input/input_ids", input_ids)
    base_gpa = hold.gpa() if hold is not None else _virt_to_gpa(input_ids.data_ptr())
    if base_gpa is None:
        print("input_ids base GPA: FAILED (pagemap)", flush=True)
        if hold is not None:
            hold.close()
        raise RuntimeError("pagemap GPA translation failed — need sudo?")

    IMAGE_PAD_ID = processor.tokenizer.convert_tokens_to_ids("<|image_pad|>")
    N = input_ids[0].tolist().count(IMAGE_PAD_ID)

    base_page_gpa = base_gpa & ~0xFFF
    print(f"input_ids base GPA: 0x{base_gpa:016x}")
    print(f"input_ids base page GPA: 0x{base_page_gpa:016x}")
    print(f"N_image_pad: {N}")
    if hold is not None:
        print(f"PINNED map_size=0x{hold.map_size:x} ptr=0x{hold.ptr:x}", flush=True)

    if args.gpa_only or args.calibrate:
        span = find_indication_token_span(processor, full_text, input_ids, indication)
        if span is not None:
            tok_start, tok_end = span
            print(f"N_indication_tokens: {tok_end - tok_start}")
            print(f"tok_start: {tok_start}")
            print(f"HEADER_CONST_HINT: {tok_start - N}")
        else:
            print("N_indication_tokens: FAILED (indication not found in input_ids)",
                  file=sys.stderr)
            print("HEADER_CONST_HINT: FAILED (indication not found in input_ids)",
                  file=sys.stderr)

    sys.stdout.flush()
    return hold, input_ids


def run_stdin_loop(args, processor, raw_entries) -> None:
    """Persistent process: fresh pinned input_ids per stdin index.

    Protocol:
      guest → LOOP_READY
      host  → "<index>\\n"
      guest → GPA fields … HOLDING
      host  → sweeps (tensor mlock'd)
      host  → "NEXT\\n" | "QUIT\\n"
      guest → munmap pin; RELEASED
    """
    print("LOOP_READY", flush=True)
    while True:
        line = sys.stdin.readline()
        if not line:
            break
        cmd = line.strip()
        if not cmd:
            continue
        if cmd.upper() == "QUIT":
            break
        try:
            index = int(cmd)
        except ValueError:
            print(f"LOOP_ERR unknown command: {cmd!r}", flush=True)
            continue

        if index < 0 or index >= len(raw_entries):
            print(f"LOOP_ERR index out of range: {index}", flush=True)
            continue

        print(f"LOOP_INDEX {index}", flush=True)
        try:
            hold, input_ids = allocate_and_report(
                args, processor, raw_entries, index, pin=True)
        except Exception as e:
            print(f"LOOP_ERR allocate failed: {e!r}", flush=True)
            continue

        # Keep refs alive; do not touch tensor during HOLDING.
        print("HOLDING", flush=True)
        release = sys.stdin.readline()

        # Drop pin only after host finished all swap-backs on these pages.
        del input_ids
        if hold is not None:
            hold.close()
            del hold
        gc.collect()
        print("RELEASED", flush=True)

        if not release or release.strip().upper() == "QUIT":
            break

    sys.stdout.flush()
    sys.stderr.flush()
    # Skip GC teardown writes into pages the host may still be settling.
    os._exit(0)


def main():
    args = parse_args()
    raw_entries = load_raw_entries(args.test_dataset)
    processor, model, device = prepare_processor_and_model(args)

    if args.stdin_loop:
        if not args.gpa_only:
            print("--stdin-loop requires --gpa-only", file=sys.stderr)
            sys.exit(2)
        run_stdin_loop(args, processor, raw_entries)
        return

    if args.gpa_only:
        hold, input_ids = allocate_and_report(
            args, processor, raw_entries, args.index, pin=True)
        sys.stdout.flush()
        input("\nPress Enter to exit and release memory...")
        if hold is not None:
            hold.close()
        sys.stdout.flush()
        sys.stderr.flush()
        os._exit(0)

    # Full generate path (unchanged semantics).
    raw = raw_entries[args.index]
    indication = raw.get("indication", "") or ""
    image_path = resolve_path(args.test_image_folder, raw["image"].replace("..", "."))
    image = load_rgb(image_path)
    print("\n" + "=" * 60)
    print(f"  INDICATION (sample id: {raw.get('id')})")
    print("=" * 60)
    print(f"  {indication}")
    print("=" * 60 + "\n")

    sample = {
        "messages": [{
            "role": "user",
            "content": [
                {"type": "image", "image": image_path},
                {"type": "text", "text": raw["conversations"][0]["value"].replace("<image>", "").strip()},
            ],
        }]
    }
    full_text = build_user_prompt(processor, sample, model_id=args.model_id)
    inputs = processor(
        text=full_text, images=[image], return_tensors="pt",
        padding=False, truncation=True, max_length=4096,
    )
    input_ids = inputs["input_ids"]
    print_cpu_tensor_gpa("input/input_ids", input_ids)
    base_gpa = _virt_to_gpa(input_ids.data_ptr())
    print(f"input_ids base GPA: 0x{base_gpa:016x}")
    IMAGE_PAD_ID = processor.tokenizer.convert_tokens_to_ids("<|image_pad|>")
    N = input_ids[0].tolist().count(IMAGE_PAD_ID)
    print(f"N_image_pad: {N}")
    if args.calibrate:
        span = find_indication_token_span(processor, full_text, input_ids, indication)
        if span is not None:
            tok_start, tok_end = span
            print(f"N_indication_tokens: {tok_end - tok_start}")
            print(f"tok_start: {tok_start}")
            print(f"HEADER_CONST_HINT: {tok_start - N}")

    sys.stdout.flush()
    input("\nPress Enter to run generate() and produce the output...")

    inputs = inputs.to(device)
    if "pixel_values" in inputs and inputs["pixel_values"] is not None:
        inputs["pixel_values"] = inputs["pixel_values"].to(dtype=torch.bfloat16)

    gen_ids = model.generate(
        **inputs,
        max_new_tokens=args.max_new_tokens,
        do_sample=False,
        num_beams=1,
        eos_token_id=processor.tokenizer.eos_token_id,
        pad_token_id=processor.tokenizer.pad_token_id,
    )
    in_len = inputs["input_ids"].shape[1]
    trimmed = gen_ids[:, in_len:]
    output_text = processor.batch_decode(trimmed, skip_special_tokens=True)[0].strip()
    print(f"\nGenerated report: {output_text}")


if __name__ == "__main__":
    main()
