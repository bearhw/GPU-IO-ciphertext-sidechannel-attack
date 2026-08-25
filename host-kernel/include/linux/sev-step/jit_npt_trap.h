/* SPDX-License-Identifier: GPL-2.0 */
/*
 * jit_npt_trap.h – Two-Phase Just-In-Time NPT Trapping
 *
 * Goal
 * ====
 * Deduce the encrypted target_input GPA that a guest PyTorch .cuda() H2D
 * transfer reads from, by observing the CPU access pattern during
 *
 *   memcpy(swiotlb_bounce_buffer, target_input)
 *
 * without causing a page-fault storm or background overhead.
 *
 * State machine
 * =============
 *
 *  ┌──────────────────────────────────────────────────────────────────┐
 *  │  DISARMED  ──[arm ioctl]──►  IDLE                               │
 *  │                               │                                  │
 *  │  • bounce GFN zapped (P=0)    │ write fault on bounce GPA        │
 *  │  • sweep range recorded       ▼                                  │
 *  │                            SWEEP_DONE                            │
 *  │                               │                                  │
 *  │  • heap [sweep_start,end)     │ read fault anywhere in           │
 *  │    now zapped (P=0)           │ [sweep_start, sweep_end)         │
 *  │  • bounce re-mapped by        ▼                                  │
 *  │    normal handler          DISARMED  ◄── target GPA logged       │
 *  └──────────────────────────────────────────────────────────────────┘
 *
 * Phase 1  IDLE:        Only the bounce buffer page is unmapped; everything
 *                       else runs at native speed (zero overhead: one
 *                       atomic_read per KVM page fault).
 *
 * Phase 2  Write fault: Guest memcpy writes the bounce buffer → NPF.
 *                       Detected at the start of kvm_mmu_page_fault().
 *
 * Phase 3  Sweep:       While the vCPU is paused in the fault handler,
 *                       kvm_zap_gfn_range() unmaps the configured heap range.
 *                       State advances to SWEEP_DONE, then the normal KVM
 *                       fault handler maps the bounce buffer and resumes.
 *
 * Phase 4  Read fault:  The resumed guest immediately tries to read the
 *                       *next* cacheline from target_input.  Because we
 *                       zapped the heap, that read triggers an NPF.
 *                       The faulting GPA is the target_input address.
 *                       We printk it, reset to DISARMED, and let the normal
 *                       handler re-map the target page.
 *
 * Arming
 * ======
 * Write to /sys/kernel/jit_npt_trap/arm:
 *   echo "<bounce_gpa_hex> <sweep_start_gfn_hex> <sweep_end_gfn_hex>" > arm
 * e.g.:
 *   echo "0x7f3000 0x100000 0x200000" > /sys/kernel/jit_npt_trap/arm
 *
 * Disarm at any time:
 *   echo 1 > /sys/kernel/jit_npt_trap/disarm
 *
 * Current state:
 *   cat /sys/kernel/jit_npt_trap/state
 *
 * Caveats
 * =======
 *  • The sweep range should be as tight as possible (a few hundred pages
 *    at most) to limit post-capture demand-paging overhead.
 *  • After Phase 4, the swept pages that were NOT the target are re-mapped
 *    on demand by the normal KVM MMU — one NPF per page, but with state
 *    already DISARMED so no special handling occurs.
 *  • Designed for AMD SVM / TDP MMU (NPF path).  Intel VMX (EPT) uses the
 *    same kvm_mmu_page_fault() entry point and should work identically.
 *
 * Lives in:  arch/x86/kvm/sev-step/jit_npt_trap.c
 * Hook in:   arch/x86/kvm/mmu/mmu.c  (top of kvm_mmu_page_fault)
 */

#ifndef _SEV_STEP_JIT_NPT_TRAP_H
#define _SEV_STEP_JIT_NPT_TRAP_H

#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/spinlock.h>
#include <linux/kvm_host.h>

/* ── state machine ─────────────────────────────────────────────── */

enum jit_npt_state {
	JIT_NPT_DISARMED  = 0,   /* inactive – zero overhead              */
	JIT_NPT_IDLE      = 1,   /* armed: bounce GFN zapped, watching    */
	JIT_NPT_SWEEP_DONE = 2,  /* heap zapped; waiting for target read  */
};

struct jit_npt_ctx {
	/*
	 * state is read on EVERY KVM page fault (hot path).
	 * Keep it as an atomic so the reader never takes a lock.
	 */
	atomic_t          state;       /* enum jit_npt_state                */

	spinlock_t        lock;        /* serialises state transitions only */

	/* Provided at arm time */
	gfn_t             bounce_gfn;
	gfn_t             sweep_start_gfn;
	gfn_t             sweep_end_gfn;

	/* Filled in Phase 4 */
	gpa_t             target_gpa;
};

/* Singleton, defined in jit_npt_trap.c */
extern struct jit_npt_ctx jit_npt;

/* ── API called from mmu.c ─────────────────────────────────────── */

/*
 * jit_npt_handle_fault() – hot-path hook.
 *
 * Called at the very start of kvm_mmu_page_fault() before any lock is
 * acquired.  Returns 1 if the fault was fully handled (caller should
 * return 1 to resume the guest), 0 to let normal handling proceed.
 *
 * Fast path: if state == DISARMED the function is a single atomic_read
 * and an immediate return 0.
 */
int jit_npt_handle_fault(struct kvm_vcpu *vcpu, gpa_t gpa, u64 error_code);

/* ── lifecycle – called from module init/exit ──────────────────── */
int  jit_npt_init(void);
void jit_npt_exit(void);

#endif /* _SEV_STEP_JIT_NPT_TRAP_H */
