/* SPDX-License-Identifier: GPL-2.0 */
/*
 * nv_bb_track.h – Kernel-internal API for NVIDIA bounce-buffer detection
 *                 and H2D transfer source identification.
 *
 * Two subsystems:
 *   1. PSC tracking (Step 1): logs PSC events for BB detection.
 *   2. NPT fault tracking + correlation (Steps 2-3): write-protects BB
 *      pages, unmaps private memory, correlates read→write fault pairs
 *      to identify the private source page for each H2D transfer.
 *
 * Lives in kvm.ko (arch/x86/kvm/sev-step/nv_bb_track.c).
 * Consumed by:
 *   - arch/x86/kvm/svm/sev.c   (nv_bb_psc_event in PSC handler)
 *   - arch/x86/kvm/mmu/mmu.c   (nv_bb_handle_fault in NPF handler)
 *   - virt/kvm/kvm_main.c      (ioctl dispatch)
 */
#ifndef _SEV_STEP_NV_BB_TRACK_H
#define _SEV_STEP_NV_BB_TRACK_H

#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/mutex.h>

/* ══════════════════════════════════════════════════════════════════
 *  Step 1: PSC event tracking
 * ══════════════════════════════════════════════════════════════════ */

#define PSC_EVENT_RING_SIZE  4096

struct psc_event_entry {
	u64  gpa;
	u64  timestamp_ns;
	u32  vcpu_id;
	u8   op;       /* SNP_PAGE_STATE_PRIVATE=1, SNP_PAGE_STATE_SHARED=2 */
	u8   level;    /* PG_LEVEL_4K=1, PG_LEVEL_2M=2, PG_LEVEL_1G=3       */
	u8   _pad[2];
};

struct psc_event_ring {
	struct psc_event_entry  entries[PSC_EVENT_RING_SIZE];
	atomic_t                head;
	u32                     drain_tail;
	struct mutex            drain_mutex;
};

extern atomic_t              psc_tracking_enabled;
extern struct psc_event_ring psc_ring;

void nv_bb_psc_event(u32 vcpu_id, u64 gpa, u8 op, u8 level);
int  psc_track_enable(void);
int  psc_track_disable(void);
int  psc_track_drain(void __user *argp);

/* ══════════════════════════════════════════════════════════════════
 *  Steps 2-3: NPT fault tracking + kernel-side correlation
 * ══════════════════════════════════════════════════════════════════ */

/* ── Bounce buffer range storage ──────────────────────────────── */

#define NV_BB_MAX_RANGES  16

struct nv_bb_range {
	u64  start_gfn;
	u64  nr_pages;
};

struct nv_bb_pool {
	struct nv_bb_range  ranges[NV_BB_MAX_RANGES];
	u32                 nr_ranges;
	/* Source range: only ACCESS-track this GFN range (0=all) */
	u64                 src_start_gfn;
	u64                 src_nr_pages;
};

/* ── Per-vCPU read history ring (for correlation) ─────────────── */

#define NV_BB_MAX_VCPUS       16
#define NV_BB_READ_HIST_SIZE  32768 /* recent reads per vCPU */

struct nv_bb_read_entry {
	u64  gfn;
	u64  ts_ns;
};

/*
 * Max pages to re-unmap after each single-step VMEXIT.
 * One instruction typically touches 1-2 pages (src + dst for string ops).
 */
#define NV_BB_MAX_STEP_PAGES  4

struct nv_bb_vcpu_ctx {
	struct nv_bb_read_entry  hist[NV_BB_READ_HIST_SIZE];
	u32   head;              /* next write slot (wraps) */
	u32   count;             /* entries stored (max = HIST_SIZE) */

	/* Single-stepping: pages to re-unmap after timer VMEXIT */
	u64   step_rearm_gfns[NV_BB_MAX_STEP_PAGES];
	u32   nr_step_rearm;
};

/* ── Transfer pair result ring ────────────────────────────────── */

#define NV_BB_XFER_RING_SIZE  32768

struct nv_bb_xfer_entry {
	u64  src_gpa;
	u64  bb_gpa;
	u64  read_ts_ns;
	u64  write_ts_ns;
	u32  vcpu_id;
	u32  _pad;
};

struct nv_bb_xfer_ring {
	struct nv_bb_xfer_entry  entries[NV_BB_XFER_RING_SIZE];
	atomic_t                 head;
	u32                      drain_tail;
	struct mutex             drain_mutex;
};

/* ── Global tracking state ────────────────────────────────────── */

extern atomic_t                nv_bb_tracking_enabled;
extern struct nv_bb_pool       nv_bb_pool;
extern struct nv_bb_vcpu_ctx   nv_bb_vcpu[NV_BB_MAX_VCPUS];
extern struct nv_bb_xfer_ring  nv_bb_xring;
extern atomic64_t              nv_bb_nr_read_faults;
extern atomic64_t              nv_bb_nr_write_faults;
extern atomic64_t              nv_bb_nr_correlations;

/* ── Step 4: Single-stepping state ───────────────────────────── */

extern atomic_t                nv_bb_stepping_active;

/* ── Step 4b: Triggered single-stepping state ────────────────── */

extern atomic_t                nv_bb_trigger_armed;

/* ── API ──────────────────────────────────────────────────────── */

/**
 * nv_bb_handle_fault - NPF correlation engine (hot path).
 * Called from page_fault_handle_page_track() in mmu.c.
 */
void nv_bb_handle_fault(struct kvm_vcpu *vcpu, u64 gfn, bool is_write);

/**
 * nv_bb_step_post_vmexit - Re-unmap pages after single-step VMEXIT.
 * Called from svm.c after each stepping VMEXIT (timer or page fault).
 * Re-applies ACCESS tracking on pages faulted in the previous step,
 * so that the next access to those pages also generates a fault.
 */
void nv_bb_step_post_vmexit(struct kvm_vcpu *vcpu);

/**
 * nv_bb_trigger_post_vmexit - Check if trigger fired, activate stepping.
 * Called from svm.c when trigger_armed is set.  If the trigger page was
 * accessed, unmaps ALL memory and enables APIC single-stepping.
 */
void nv_bb_trigger_post_vmexit(struct kvm_vcpu *vcpu);

/* Ioctl handlers */
int  nv_bb_start(void __user *argp);
int  nv_bb_stop(void);
int  nv_bb_rearm(void);
int  nv_bb_drain_xfers(void __user *argp);
int  nv_bb_step_arm(void __user *argp);
int  nv_bb_step_disarm(void);
int  nv_bb_triggered_step_arm(void __user *argp);

#endif /* _SEV_STEP_NV_BB_TRACK_H */
