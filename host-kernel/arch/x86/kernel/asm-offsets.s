	.file	"asm-offsets.c"
# GNU C11 (Ubuntu 11.4.0-1ubuntu1~22.04.3) version 11.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -m64 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -mindirect-branch=thunk-extern -mindirect-branch-register -mindirect-branch-cs-prefix -mharden-sls=all -mrecord-mcount -mfentry -march=x86-64 -O2 -std=gnu11 -p -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE -fcf-protection=none -falign-jumps=1 -falign-loops=1 -fno-asynchronous-unwind-tables -fno-jump-tables -fno-delete-null-pointer-checks -fno-allow-store-data-races -fstack-protector-strong -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-stack-clash-protection -fno-strict-overflow -fstack-check=no -fconserve-stack -fsanitize=bounds -fsanitize=shift -fsanitize=bool -fsanitize=enum -fstack-protector-strong
	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
1:	call	__fentry__
	.section __mcount_loc, "a",@progbits
	.quad 1b
	.previous
	pushq	%rbp	#
	movq	%rsp, %rbp	#,
# arch/x86/kernel/asm-offsets_64.c:20: 	BLANK();
#APP
# 20 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:24: 	OFFSET(KVM_STEAL_TIME_preempted, kvm_steal_time, preempted);
# 24 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->KVM_STEAL_TIME_preempted $16 offsetof(struct kvm_steal_time, preempted)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:25: 	BLANK();
# 25 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:29: 	ENTRY(bx);
# 29 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_bx $40 offsetof(struct pt_regs, bx)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:30: 	ENTRY(cx);
# 30 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_cx $88 offsetof(struct pt_regs, cx)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:31: 	ENTRY(dx);
# 31 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_dx $96 offsetof(struct pt_regs, dx)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:32: 	ENTRY(sp);
# 32 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_sp $152 offsetof(struct pt_regs, sp)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:33: 	ENTRY(bp);
# 33 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_bp $32 offsetof(struct pt_regs, bp)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:34: 	ENTRY(si);
# 34 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_si $104 offsetof(struct pt_regs, si)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:35: 	ENTRY(di);
# 35 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_di $112 offsetof(struct pt_regs, di)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:36: 	ENTRY(r8);
# 36 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_r8 $72 offsetof(struct pt_regs, r8)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:37: 	ENTRY(r9);
# 37 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_r9 $64 offsetof(struct pt_regs, r9)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:38: 	ENTRY(r10);
# 38 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_r10 $56 offsetof(struct pt_regs, r10)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:39: 	ENTRY(r11);
# 39 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_r11 $48 offsetof(struct pt_regs, r11)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:40: 	ENTRY(r12);
# 40 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_r12 $24 offsetof(struct pt_regs, r12)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:41: 	ENTRY(r13);
# 41 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_r13 $16 offsetof(struct pt_regs, r13)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:42: 	ENTRY(r14);
# 42 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_r14 $8 offsetof(struct pt_regs, r14)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:43: 	ENTRY(r15);
# 43 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_r15 $0 offsetof(struct pt_regs, r15)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:44: 	ENTRY(flags);
# 44 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->pt_regs_flags $144 offsetof(struct pt_regs, flags)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:45: 	BLANK();
# 45 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:49: 	ENTRY(cr0);
# 49 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->saved_context_cr0 $200 offsetof(struct saved_context, cr0)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:50: 	ENTRY(cr2);
# 50 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->saved_context_cr2 $208 offsetof(struct saved_context, cr2)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:51: 	ENTRY(cr3);
# 51 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->saved_context_cr3 $216 offsetof(struct saved_context, cr3)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:52: 	ENTRY(cr4);
# 52 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->saved_context_cr4 $224 offsetof(struct saved_context, cr4)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:53: 	ENTRY(gdt_desc);
# 53 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->saved_context_gdt_desc $266 offsetof(struct saved_context, gdt_desc)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:54: 	BLANK();
# 54 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:57: 	BLANK();
# 57 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:60: 	DEFINE(stack_canary_offset, offsetof(struct fixed_percpu_data, stack_canary));
# 60 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->stack_canary_offset $40 offsetof(struct fixed_percpu_data, stack_canary)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:61: 	BLANK();
# 61 "arch/x86/kernel/asm-offsets_64.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets_64.c:64: }
#NO_APP
	xorl	%eax, %eax	#
	popq	%rbp	#
	ret	
	int3	
	.size	main, .-main
	.text
	.p2align 4
	.type	common, @function
common:
1:	call	__fentry__
	.section __mcount_loc, "a",@progbits
	.quad 1b
	.previous
	pushq	%rbp	#
	movq	%rsp, %rbp	#,
# arch/x86/kernel/asm-offsets.c:35: 	BLANK();
#APP
# 35 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:36: 	OFFSET(TASK_threadsp, task_struct, thread.sp);
# 36 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TASK_threadsp $5336 offsetof(struct task_struct, thread.sp)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:38: 	OFFSET(TASK_stack_canary, task_struct, stack_canary);
# 38 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TASK_stack_canary $2440 offsetof(struct task_struct, stack_canary)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:41: 	BLANK();
# 41 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:42: 	OFFSET(pbe_address, pbe, address);
# 42 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->pbe_address $0 offsetof(struct pbe, address)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:43: 	OFFSET(pbe_orig_address, pbe, orig_address);
# 43 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->pbe_orig_address $8 offsetof(struct pbe, orig_address)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:44: 	OFFSET(pbe_next, pbe, next);
# 44 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->pbe_next $16 offsetof(struct pbe, next)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:47: 	BLANK();
# 47 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:48: 	OFFSET(IA32_SIGCONTEXT_ax, sigcontext_32, ax);
# 48 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_SIGCONTEXT_ax $44 offsetof(struct sigcontext_32, ax)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:49: 	OFFSET(IA32_SIGCONTEXT_bx, sigcontext_32, bx);
# 49 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_SIGCONTEXT_bx $32 offsetof(struct sigcontext_32, bx)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:50: 	OFFSET(IA32_SIGCONTEXT_cx, sigcontext_32, cx);
# 50 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_SIGCONTEXT_cx $40 offsetof(struct sigcontext_32, cx)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:51: 	OFFSET(IA32_SIGCONTEXT_dx, sigcontext_32, dx);
# 51 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_SIGCONTEXT_dx $36 offsetof(struct sigcontext_32, dx)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:52: 	OFFSET(IA32_SIGCONTEXT_si, sigcontext_32, si);
# 52 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_SIGCONTEXT_si $20 offsetof(struct sigcontext_32, si)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:53: 	OFFSET(IA32_SIGCONTEXT_di, sigcontext_32, di);
# 53 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_SIGCONTEXT_di $16 offsetof(struct sigcontext_32, di)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:54: 	OFFSET(IA32_SIGCONTEXT_bp, sigcontext_32, bp);
# 54 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_SIGCONTEXT_bp $24 offsetof(struct sigcontext_32, bp)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:55: 	OFFSET(IA32_SIGCONTEXT_sp, sigcontext_32, sp);
# 55 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_SIGCONTEXT_sp $28 offsetof(struct sigcontext_32, sp)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:56: 	OFFSET(IA32_SIGCONTEXT_ip, sigcontext_32, ip);
# 56 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_SIGCONTEXT_ip $56 offsetof(struct sigcontext_32, ip)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:58: 	BLANK();
# 58 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:59: 	OFFSET(IA32_RT_SIGFRAME_sigcontext, rt_sigframe_ia32, uc.uc_mcontext);
# 59 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->IA32_RT_SIGFRAME_sigcontext $164 offsetof(struct rt_sigframe_ia32, uc.uc_mcontext)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:63: 	BLANK();
# 63 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:64: 	OFFSET(XEN_vcpu_info_mask, vcpu_info, evtchn_upcall_mask);
# 64 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->XEN_vcpu_info_mask $1 offsetof(struct vcpu_info, evtchn_upcall_mask)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:65: 	OFFSET(XEN_vcpu_info_pending, vcpu_info, evtchn_upcall_pending);
# 65 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->XEN_vcpu_info_pending $0 offsetof(struct vcpu_info, evtchn_upcall_pending)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:66: 	OFFSET(XEN_vcpu_info_arch_cr2, vcpu_info, arch.cr2);
# 66 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->XEN_vcpu_info_arch_cr2 $16 offsetof(struct vcpu_info, arch.cr2)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:69: 	BLANK();
# 69 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:70: 	OFFSET(TDX_MODULE_rcx, tdx_module_output, rcx);
# 70 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_MODULE_rcx $0 offsetof(struct tdx_module_output, rcx)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:71: 	OFFSET(TDX_MODULE_rdx, tdx_module_output, rdx);
# 71 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_MODULE_rdx $8 offsetof(struct tdx_module_output, rdx)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:72: 	OFFSET(TDX_MODULE_r8,  tdx_module_output, r8);
# 72 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_MODULE_r8 $16 offsetof(struct tdx_module_output, r8)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:73: 	OFFSET(TDX_MODULE_r9,  tdx_module_output, r9);
# 73 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_MODULE_r9 $24 offsetof(struct tdx_module_output, r9)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:74: 	OFFSET(TDX_MODULE_r10, tdx_module_output, r10);
# 74 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_MODULE_r10 $32 offsetof(struct tdx_module_output, r10)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:75: 	OFFSET(TDX_MODULE_r11, tdx_module_output, r11);
# 75 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_MODULE_r11 $40 offsetof(struct tdx_module_output, r11)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:77: 	BLANK();
# 77 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:78: 	OFFSET(TDX_HYPERCALL_r10, tdx_hypercall_args, r10);
# 78 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_HYPERCALL_r10 $0 offsetof(struct tdx_hypercall_args, r10)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:79: 	OFFSET(TDX_HYPERCALL_r11, tdx_hypercall_args, r11);
# 79 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_HYPERCALL_r11 $8 offsetof(struct tdx_hypercall_args, r11)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:80: 	OFFSET(TDX_HYPERCALL_r12, tdx_hypercall_args, r12);
# 80 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_HYPERCALL_r12 $16 offsetof(struct tdx_hypercall_args, r12)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:81: 	OFFSET(TDX_HYPERCALL_r13, tdx_hypercall_args, r13);
# 81 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_HYPERCALL_r13 $24 offsetof(struct tdx_hypercall_args, r13)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:82: 	OFFSET(TDX_HYPERCALL_r14, tdx_hypercall_args, r14);
# 82 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_HYPERCALL_r14 $32 offsetof(struct tdx_hypercall_args, r14)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:83: 	OFFSET(TDX_HYPERCALL_r15, tdx_hypercall_args, r15);
# 83 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TDX_HYPERCALL_r15 $40 offsetof(struct tdx_hypercall_args, r15)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:85: 	BLANK();
# 85 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:86: 	OFFSET(BP_scratch, boot_params, scratch);
# 86 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->BP_scratch $484 offsetof(struct boot_params, scratch)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:87: 	OFFSET(BP_secure_boot, boot_params, secure_boot);
# 87 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->BP_secure_boot $492 offsetof(struct boot_params, secure_boot)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:88: 	OFFSET(BP_loadflags, boot_params, hdr.loadflags);
# 88 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->BP_loadflags $529 offsetof(struct boot_params, hdr.loadflags)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:89: 	OFFSET(BP_hardware_subarch, boot_params, hdr.hardware_subarch);
# 89 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->BP_hardware_subarch $572 offsetof(struct boot_params, hdr.hardware_subarch)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:90: 	OFFSET(BP_version, boot_params, hdr.version);
# 90 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->BP_version $518 offsetof(struct boot_params, hdr.version)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:91: 	OFFSET(BP_kernel_alignment, boot_params, hdr.kernel_alignment);
# 91 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->BP_kernel_alignment $560 offsetof(struct boot_params, hdr.kernel_alignment)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:92: 	OFFSET(BP_init_size, boot_params, hdr.init_size);
# 92 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->BP_init_size $608 offsetof(struct boot_params, hdr.init_size)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:93: 	OFFSET(BP_pref_address, boot_params, hdr.pref_address);
# 93 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->BP_pref_address $600 offsetof(struct boot_params, hdr.pref_address)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:95: 	BLANK();
# 95 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->"
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:96: 	DEFINE(PTREGS_SIZE, sizeof(struct pt_regs));
# 96 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->PTREGS_SIZE $168 sizeof(struct pt_regs)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:99: 	OFFSET(TLB_STATE_user_pcid_flush_mask, tlb_state, user_pcid_flush_mask);
# 99 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TLB_STATE_user_pcid_flush_mask $22 offsetof(struct tlb_state, user_pcid_flush_mask)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:102: 	OFFSET(CPU_ENTRY_AREA_entry_stack, cpu_entry_area, entry_stack_page);
# 102 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->CPU_ENTRY_AREA_entry_stack $4096 offsetof(struct cpu_entry_area, entry_stack_page)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:103: 	DEFINE(SIZEOF_entry_stack, sizeof(struct entry_stack));
# 103 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->SIZEOF_entry_stack $4096 sizeof(struct entry_stack)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:104: 	DEFINE(MASK_entry_stack, (~(sizeof(struct entry_stack) - 1)));
# 104 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->MASK_entry_stack $-4096 (~(sizeof(struct entry_stack) - 1))"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:107: 	OFFSET(TSS_sp0, tss_struct, x86_tss.sp0);
# 107 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TSS_sp0 $4 offsetof(struct tss_struct, x86_tss.sp0)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:108: 	OFFSET(TSS_sp1, tss_struct, x86_tss.sp1);
# 108 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TSS_sp1 $12 offsetof(struct tss_struct, x86_tss.sp1)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:109: 	OFFSET(TSS_sp2, tss_struct, x86_tss.sp2);
# 109 "arch/x86/kernel/asm-offsets.c" 1
	
.ascii "->TSS_sp2 $20 offsetof(struct tss_struct, x86_tss.sp2)"	#
# 0 "" 2
# arch/x86/kernel/asm-offsets.c:110: }
#NO_APP
	popq	%rbp	#
	ret	
	int3	
	.size	common, .-common
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
