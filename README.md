# GPU I/O Ciphertext Side-Channel Attack

```
.
├── host-kernel/           # SEV-Step modified Linux kernel (5.19.0-rc6)
├── sev-step-module/       # Kernel module, experiment scripts, logs & plots
│   ├── mnist/             #   MNIST experiment runs
│   ├── mura/              #   MURA experiment runs
│   └── llm/               #   LLM experiment runs
├── qemu-script/           # QEMU VM launcher
├── case_study/
│   ├── host_scripts/      # Shared host-side page-dump pipeline
│   ├── mnist/
│   │   ├── model/         #   Trained models (.pth) & training scripts
│   │   ├── flow/          #   Page dump data
│   │   └── dict/          #   Dictionary build
│   ├── mura/
│   │   ├── DenseNet-MURA-PyTorch/
│   │   ├── dict/          #   Dictionary & XOR analysis
│   │   └── *.pth          #   Trained XOR-slice classifiers
│   └── llm/
│       ├── run_all-v4_*/  #   Blind test results (3 runs)
│       └── dict/          #   Token dictionary & pages
```
