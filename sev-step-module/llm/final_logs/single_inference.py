"""
Run one or all inferences on ReXGradient test samples and print/save results.

Usage:
    python3 single_inference.py --index 0
    python3 single_inference.py --index 5 --output_file results.txt
    python3 single_inference.py --run_all --batch_size 8 --output_file results.txt
    python3 single_inference.py --use_lora --finetuned_model_path /path/to/adapter --run_all --output_file results.txt
"""
import argparse
import json
import os
import struct
import subprocess
import time

import torch

_PAGE = 0x1000


def dump_tensor_gpa_full(name, tensor):
    """Print EVERY guest-physical page a CPU tensor occupies, as contiguous runs.

    The previous print_cpu_tensor_gpa reported only the first page; a pageable
    tensor (no pin) is physically scattered, so the real DMA-source ground truth
    is the full page set. In the guest, /proc/self/pagemap PFN == guest physical
    frame == GPA. Needs root (sudo) or PFNs read back zero.
    Emits, per contiguous physical run:  [GPA_RUN] <name>: 0x<base> len=<pages>
    and keeps a  [GPA] <name>: GPA=0x<first>  line for backward-compatible parsers.
    """
    t = tensor.detach()
    # Report the tensor's backing STORAGE (no copy): covers every page the data
    # occupies regardless of contiguity/offset, and is exactly what H2D reads.
    try:
        st = t.untyped_storage()
        va0, nbytes = st.data_ptr(), st.nbytes()
    except AttributeError:
        st = t.storage()
        va0, nbytes = st.data_ptr(), st.size() * t.element_size()
    va_start = va0 & ~(_PAGE - 1)
    va_end = (va0 + nbytes + _PAGE - 1) & ~(_PAGE - 1)
    npg = (va_end - va_start) // _PAGE

    frames = []  # guest-physical page-aligned addrs, in VA order (None if unmapped)
    try:
        with open("/proc/self/pagemap", "rb") as pm:
            for i in range(npg):
                va = va_start + i * _PAGE
                pm.seek((va // _PAGE) * 8)
                ent = struct.unpack("<Q", pm.read(8))[0]
                if ent & (1 << 63):                      # present
                    pfn = ent & ((1 << 55) - 1)
                    frames.append(pfn * _PAGE)
                else:
                    frames.append(None)
    except Exception as e:
        print(f"[GPA_ERR] {name}: pagemap read failed: {e}", flush=True)
        return

    first = next((f for f in frames if f is not None), None)
    if first is not None:
        print(f"[GPA] {name}: GPA=0x{first:x}", flush=True)

    # coalesce ascending-contiguous physical runs
    runs = []
    base = length = None
    for f in frames:
        if f is None:
            if base is not None:
                runs.append((base, length)); base = length = None
            continue
        if base is None:
            base, length = f, 1
        elif f == base + length * _PAGE:
            length += 1
        else:
            runs.append((base, length)); base, length = f, 1
    if base is not None:
        runs.append((base, length))

    mapped = sum(1 for f in frames if f is not None)
    print(f"[GPA_FULL] {name}: bytes={nbytes} pages={npg} mapped={mapped} "
          f"runs={len(runs)}", flush=True)
    for base, length in runs:
        print(f"[GPA_RUN] {name}: 0x{base:x} len={length}", flush=True)

_HOST_ADDR = "user@10.0.2.2"
_SIGNAL_READY_WAIT_S = 2

def _signal_host(remote_path):
    """Create a signal file on the host via ssh touch. Inference continues on failure."""
    try:
        subprocess.run(
            ["sudo", "-u", "ubuntu", "ssh",
             "-o", "StrictHostKeyChecking=no",
             "-o", "ConnectTimeout=3",
             "-o", "BatchMode=yes",
             _HOST_ADDR, f"touch {remote_path}"],
            timeout=5, check=False, capture_output=True,
        )
    except Exception:
        pass
from peft import PeftModel
from tqdm import tqdm

from utils import load_model, resolve_path, print_cpu_tensor_gpa
from prediction import build_user_prompt, load_rgb, clean_output

_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
_REXGRAD_ROOT = os.path.normpath(os.path.join(_SCRIPT_DIR, "../rexgradient"))


def _tty_print(msg):
    """Print directly to terminal, bypassing grep/pipe."""
    try:
        with open("/dev/tty", "w") as tty:
            tty.write(msg + "\n")
            tty.flush()
    except OSError:
        print(msg, flush=True)


def parse_args():
    p = argparse.ArgumentParser(description="Single-sample VLM inference")
    p.add_argument("--model_id", type=str, default="Qwen/Qwen2-VL-2B-Instruct")
    p.add_argument("--finetuned_model_path", type=str, default=None)
    p.add_argument("--use_lora", action="store_true")
    p.add_argument("--test_image_folder", type=str, default=_REXGRAD_ROOT)
    p.add_argument("--test_dataset", type=str,
                   default=os.path.join(_REXGRAD_ROOT, "ReXGradient/metadata/rexgradient_test.json"))
    p.add_argument("--index", type=int, default=0,
                   help="Sample index to run (ignored when --run_all is set)")
    p.add_argument("--run_all", action="store_true",
                   help="Run inference on all samples in the dataset")
    p.add_argument("--batch_size", type=int, default=1,
                   help="Number of samples per batch (GPA printed once per batch)")
    p.add_argument("--max_batches", type=int, default=None,
                   help="Only run the first N batches (speeds up GPA-capture runs; default: all)")
    p.add_argument("--max_new_tokens", type=int, default=200)
    p.add_argument("--output_file", type=str, default=None,
                   help="Path to txt file where outputs are saved")
    p.add_argument("--gpa_only", action="store_true",
                   help="Skip GPU compute — print input/output GPA only (output uses expected-shape dummy tensor)")
    p.add_argument("--track-input", action="store_true",
                   help="Send host write-protect activation signal to track input tensor write faults")
    p.add_argument("--input-only", action="store_true",
                   help="Print input GPA only, skip GPU compute (no generate)")
    p.add_argument("--host-addr", type=str, default=None,
                   help="Host SSH address (e.g. user@10.0.2.2). Sends scp signals before/after D2H.")
    return p.parse_args()


def load_raw_entries(json_path):
    with open(json_path) as f:
        content = f.read().strip()
    if content.startswith("["):
        return json.loads(content)
    return [json.loads(line) for line in content.splitlines() if line.strip()]


@torch.inference_mode()
def generate_batch_with_gpa(model, processor, texts, images, device, max_new_tokens, batch_idx, gpa_only=False, track_input=False, input_only=False):
    """Process a batch, printing input and output GPA once per batch.

    gpa_only=True: Skip GPU compute. Move input to GPU, then create a same-shape
    dummy tensor on GPU and copy to CPU to measure output GPA. Same memory transfer path.
    """
    padding = len(texts) > 1

    if track_input:
        _signal_host("/tmp/input_start")
        time.sleep(_SIGNAL_READY_WAIT_S)

    inputs = processor(
        text=texts,
        images=images,
        return_tensors="pt",
        padding=padding,
        truncation=True,
        max_length=4096,
    )

    if track_input:
        input_done_ns = time.clock_gettime_ns(time.CLOCK_REALTIME)
        print(f"[TS] batch{batch_idx}/input: write_done_realtime_ns={input_done_ns}", flush=True)

    dump_tensor_gpa_full(f"batch{batch_idx}/input/input_ids", inputs["input_ids"])
    if "pixel_values" in inputs and inputs["pixel_values"] is not None:
        dump_tensor_gpa_full(f"batch{batch_idx}/input/pixel_values", inputs["pixel_values"])

    if track_input:
        _signal_host("/tmp/input_done")

    if input_only:
        return [""] * len(texts)

    inputs = inputs.to(device)
    if "pixel_values" in inputs and inputs["pixel_values"] is not None:
        inputs["pixel_values"] = inputs["pixel_values"].to(dtype=torch.bfloat16)

    _tty_print(f"[batch{batch_idx}] input moved to GPU")

    if gpa_only:
        # Measure GPA by moving expected-shape dummy tensor GPU->CPU without generate
        batch_size, in_len = inputs["input_ids"].shape
        pad_id = processor.tokenizer.pad_token_id or 0
        _tty_print(f"[batch{batch_idx}] GPU compute started (dummy)")
        dummy_gpu = torch.full(
            (batch_size, in_len + max_new_tokens), pad_id,
            dtype=inputs["input_ids"].dtype, device=device
        )
        gen_ids_cpu = dummy_gpu.cpu()
        d2h_done_ns = time.clock_gettime_ns(time.CLOCK_REALTIME)
        print(f"[TS] batch{batch_idx}/output/gen_ids: d2h_done_realtime_ns={d2h_done_ns}", flush=True)
        print_cpu_tensor_gpa(f"batch{batch_idx}/output/gen_ids", gen_ids_cpu)
        return [""] * batch_size

    _tty_print(f"[batch{batch_idx}] GPU compute started")
    gen_ids = model.generate(
        **inputs,
        max_new_tokens=max_new_tokens,
        do_sample=False,
        num_beams=1,
        eos_token_id=processor.tokenizer.eos_token_id,
        pad_token_id=processor.tokenizer.pad_token_id,
    )

    _signal_host("/tmp/d2h_start")
    time.sleep(_SIGNAL_READY_WAIT_S)
    gen_ids_cpu = gen_ids.cpu()
    d2h_done_ns = time.clock_gettime_ns(time.CLOCK_REALTIME)
    _signal_host("/tmp/d2h_done")
    print(f"[TS] batch{batch_idx}/output/gen_ids: d2h_done_realtime_ns={d2h_done_ns}", flush=True)
    print_cpu_tensor_gpa(f"batch{batch_idx}/output/gen_ids", gen_ids_cpu)

    in_len = inputs["input_ids"].shape[1]
    trimmed = gen_ids_cpu[:, in_len:]
    return [t.strip() for t in processor.batch_decode(trimmed, skip_special_tokens=True)]


def write_result(idx, raw, output, out_f):
    indication = raw.get("indication", "") or ""
    ground_truth = raw["conversations"][1]["value"] if len(raw.get("conversations", [])) > 1 else ""
    header = (
        f"\n{'=' * 60}\n"
        f"  Index     : {idx}\n"
        f"  Sample id : {raw.get('id')}\n"
        f"  Indication: {indication}\n"
        f"{'=' * 60}\n"
    )
    body = (
        f"[GENERATED OUTPUT]\n{output}\n\n"
        f"[GROUND TRUTH]\n{ground_truth}\n"
        f"{'=' * 60}\n"
    )
    print(header + body)
    if out_f is not None:
        out_f.write(header + body)
        out_f.flush()


def main():
    global _HOST_ADDR
    args = parse_args()
    if args.host_addr:
        _HOST_ADDR = args.host_addr

    raw_entries = load_raw_entries(args.test_dataset)
    indices = list(range(len(raw_entries))) if args.run_all else [args.index]

    if args.input_only:
        from transformers import AutoProcessor
        processor = AutoProcessor.from_pretrained(args.model_id)
        model = None
        device = "cpu"
    else:
        model, processor = load_model(args.model_id)
        model.eval()
        if args.use_lora:
            print(f"Loading LoRA adapter from {args.finetuned_model_path}")
            model = PeftModel.from_pretrained(model, args.finetuned_model_path)
        device = "cuda" if torch.cuda.is_available() else "cpu"
        model = model.to(device)

    out_f = None
    if args.output_file:
        os.makedirs(os.path.dirname(os.path.abspath(args.output_file)), exist_ok=True)
        out_f = open(args.output_file, "w", encoding="utf-8")
        print(f"Saving outputs to: {args.output_file}")

    bs = args.batch_size
    batches = [indices[i:i + bs] for i in range(0, len(indices), bs)]
    if args.max_batches is not None:
        batches = batches[:args.max_batches]

    try:
        for batch_idx, batch_indices in enumerate(tqdm(batches, desc="Inference", disable=len(batches) == 1)):
            batch_raws = [raw_entries[i] for i in batch_indices]

            texts, images = [], []
            for raw in batch_raws:
                image_path = resolve_path(args.test_image_folder, raw["image"].replace("..", "."))
                images.append(load_rgb(image_path))
                sample = {
                    "messages": [{
                        "role": "user",
                        "content": [
                            {"type": "image", "image": image_path},
                            {"type": "text", "text": raw["conversations"][0]["value"].replace("<image>", "").strip()},
                        ],
                    }]
                }
                texts.append(build_user_prompt(processor, sample, model_id=args.model_id))

            outputs = generate_batch_with_gpa(
                model, processor, texts, images, device, args.max_new_tokens, batch_idx,
                gpa_only=args.gpa_only,
                track_input=args.track_input,
                input_only=args.input_only,
            )

            for idx, raw, output in zip(batch_indices, batch_raws, outputs):
                write_result(idx, raw, clean_output(output), out_f)
    finally:
        if out_f is not None:
            out_f.close()

    if args.output_file:
        print(f"\nDone. {len(indices)} sample(s) saved to {args.output_file}")


if __name__ == "__main__":
    main()
