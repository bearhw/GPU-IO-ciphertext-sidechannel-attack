import os, json
import torch
from tqdm import tqdm
import shortuuid
from PIL import Image
from peft import PeftModel 

from utils import load_model, load_data, print_cpu_tensor_gpa
from arg_parse import parse_prediction_args

from utils import HuluInferCollator


def load_rgb(path):
    img = Image.open(path)
    if img.mode != "RGB":
        img = img.convert("RGB")
    return img


def build_user_prompt(processor, sample, model_id=""):
    """Build prompt - handle different model formats"""
    messages = sample["messages"][:1]
    
    # Hulu model needs messages reformatted
    if "hulu" in model_id.lower():
        reformatted = []
        for msg in messages:
            content = msg["content"]
            if isinstance(content, list):
                text_parts = [p.get("text", "") for p in content if isinstance(p, dict) and p.get("type") == "text"]
                text = " ".join(text_parts)
            else:
                text = str(content)
            reformatted.append({"role": msg["role"], "content": text})
        
        try:
            return processor.apply_chat_template(reformatted, tokenize=False, add_generation_prompt=True)
        except:
            return text
    
    try:
        return processor.apply_chat_template(messages, tokenize=False, add_generation_prompt=True)
    except:
        user_content = messages[0]["content"]
        if isinstance(user_content, list):
            text_parts = [p.get("text", "") for p in user_content if isinstance(p, dict) and p.get("type") == "text"]
            return " ".join(text_parts)
        return str(user_content)


def clean_output(text):
    """Ensure text ends with complete sentence"""
    if not text:
        return ""
    
    text = text.strip()
    
    if text and text[-1] in '.?!':
        return text
    
    last_period = text.rfind('.')
    if last_period > 0:
        return text[:last_period + 1]
    
    return text

import torch

@torch.inference_mode()
def generate_one_hulu(
    model,
    processor,
    sample,          
    collator,
    device="cuda",
    max_new_tokens=200,
    debug=False,
):
    assert isinstance(sample, dict), f"generate_one_hulu expects dict, got {type(sample)}"

    batch = collator([sample])

    # Print GPA of input_ids (CPU) before moving to device
    print_cpu_tensor_gpa("input/input_ids", batch["input_ids"])

    # move tensors
    for k, v in batch.items():
        if torch.is_tensor(v):
            batch[k] = v.to(device)

    if "pixel_values" in batch and batch["pixel_values"] is not None:
        batch["pixel_values"] = batch["pixel_values"].to(dtype=torch.bfloat16)
    if "pixel_values_videos" in batch and batch["pixel_values_videos"] is not None:
        batch["pixel_values_videos"] = batch["pixel_values_videos"].to(dtype=torch.bfloat16)

    gen_kwargs = dict(batch)
    gen_kwargs.pop("labels", None)  

    gen_ids = model.generate(
        **gen_kwargs,
        max_new_tokens=max_new_tokens,
        do_sample=False,
        num_beams=1,
        pad_token_id=processor.tokenizer.pad_token_id,
        eos_token_id=processor.tokenizer.eos_token_id,
    )

    in_len = batch["input_ids"].shape[1]
    out_len = gen_ids.shape[1]

    if debug:
        print("input_len:", in_len, "gen_len:", out_len)
        print("first 10 input_ids:", batch["input_ids"][0, :10].tolist())
        print("first 10 gen_ids:", gen_ids[0, :10].tolist())
        print("eos:", processor.tokenizer.eos_token_id, "pad:", processor.tokenizer.pad_token_id)

    trimmed = gen_ids[:, in_len:] if out_len > in_len else gen_ids

    # Print GPA of output tensor (CPU)
    gen_ids_cpu = gen_ids.cpu()
    print_cpu_tensor_gpa("output/gen_ids", gen_ids_cpu)

    if trimmed.numel() == 0 or (trimmed.shape[1] == 1 and trimmed[0, 0].item() == processor.tokenizer.eos_token_id):
        if debug:
            full_dec = processor.batch_decode(gen_ids, skip_special_tokens=False)[0]
            print("⚠️ trimmed empty/eos; full decode (w/ special tokens):")
            print(full_dec)

    text = processor.batch_decode(trimmed, skip_special_tokens=True, clean_up_tokenization_spaces=False)[0].strip()
    return text

@torch.inference_mode()
def generate_batch(model, processor, batch, model_id="", device="cuda", max_new_tokens=200):
    """Standard generation for most VLMs"""
    texts = [build_user_prompt(processor, s, model_id) for s in batch]
    images = [load_rgb(s["images"][0]) for s in batch]

    inputs = processor(
        text=texts,
        images=images,
        return_tensors="pt",
        padding=True,
        truncation=True,
        max_length=4096
    )

    # Print GPA of input_ids (CPU) before moving to device
    print_cpu_tensor_gpa("input/input_ids", inputs["input_ids"])

    inputs = inputs.to(device)

    # Cast pixel_values to match model dtype
    if 'pixel_values' in inputs and inputs['pixel_values'] is not None:
        inputs['pixel_values'] = inputs['pixel_values'].to(dtype=torch.bfloat16)
    if 'pixel_values_videos' in inputs and inputs['pixel_values_videos'] is not None:
        inputs['pixel_values_videos'] = inputs['pixel_values_videos'].to(dtype=torch.bfloat16)

    gen_ids = model.generate(
        **inputs,
        max_new_tokens=max_new_tokens,
        do_sample=False,
        num_beams=1,
        # repetition_penalty=1.2,
        eos_token_id=processor.tokenizer.eos_token_id,
        pad_token_id=processor.tokenizer.pad_token_id,
    )
    input_len = inputs["input_ids"].shape[1]
    trimmed = gen_ids[:, input_len:]

    # Print GPA of output tensor (CPU)
    gen_ids_cpu = gen_ids.cpu()
    print_cpu_tensor_gpa("output/gen_ids", gen_ids_cpu)

    outputs = processor.batch_decode(
        trimmed,
        skip_special_tokens=True,
        clean_up_tokenization_spaces=False,
    )

    return [clean_output(t) for t in outputs]


def main():
    args = parse_prediction_args()
    MODEL_ID = args.model_id
    FINETUNED_MODEL_PATH = args.finetuned_model_path
    TEST_IMAGE_FOLDER = args.test_image_folder
    TEST_DATASET = args.test_dataset
    PREDICTION_FILE = args.prediction_file
    USE_LORA = args.use_lora

    test_dataset = load_data(TEST_IMAGE_FOLDER, TEST_DATASET)
    print(f"Test dataset loaded: {len(test_dataset)} samples")

    if args.limit is not None:
        test_dataset = test_dataset[:args.limit]
        print(f"--limit set: running on first {len(test_dataset)} samples")

    model, processor = load_model(MODEL_ID)
    
    # Fix padding side for decoder-only models
    processor.tokenizer.padding_side = "left"

    device = "cuda" if torch.cuda.is_available() else "cpu"
    model.eval()

    if USE_LORA:
        print(f"Loading LoRA adapter from {FINETUNED_MODEL_PATH}")
        model = PeftModel.from_pretrained(model, FINETUNED_MODEL_PATH)

    model = model.to(device)

    os.makedirs(os.path.dirname(PREDICTION_FILE), exist_ok=True)

    # Use batch_size=1 for Hulu due to its special processing
    is_hulu = "hulu" in MODEL_ID.lower()
    BATCH_SIZE = 1 if is_hulu else 24

    MAX_NEW_TOKENS = 200

    with open(PREDICTION_FILE, "w") as f:
        f.write("[\n")
        
        first_entry = True
        if is_hulu:
            collator = HuluInferCollator(processor) 
        for i in tqdm(range(0, len(test_dataset), BATCH_SIZE), desc="Evaluating"):
            batch = test_dataset[i:i + BATCH_SIZE]
            if is_hulu:
                sample = batch[0]                       # batch is a list of length 1
                out = generate_one_hulu(model, processor, sample, collator,
                            device=device, max_new_tokens=MAX_NEW_TOKENS)
                outs = [out] 
            else:
                outs = generate_batch(model, processor, batch, model_id=MODEL_ID, device=device, max_new_tokens=MAX_NEW_TOKENS)

            for sample, out in zip(batch, outs):
                entry = {
                    "question_id": sample["id"],
                    "prompt": sample.get("prompt"),
                    "text": out,
                    "answer_id": shortuuid.uuid(),
                    "model_id": FINETUNED_MODEL_PATH if USE_LORA else MODEL_ID,
                    "ground_truth": sample.get("ground_truth"),
                }
                
                if not first_entry:
                    f.write(",\n")
                first_entry = False
                
                json.dump(entry, f, indent=2)
                f.flush()
        
        f.write("\n]")

    print(f"Done: {PREDICTION_FILE}")


if __name__ == "__main__":
    main()