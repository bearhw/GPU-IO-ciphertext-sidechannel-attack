// SPDX-License-Identifier: GPL-2.0
/*
 * src_track.c – SEV-Step Src-Page tracking engine.
 *
 * Detects which guest pages were *read by the CPU* before data arrived
 * in a DMA bounce buffer ("Src Pages" in load [Src] / store [BB]).
 *
 * Architecture
 * ============
 *  1. KVM_SRC_TRACK_ENABLE ioctl → apply KVM_PAGE_TRACK_ACCESS to a
 *     range of GFNs (or all memory when nr_pages == 0).
 *
 *  2. On each NPF for a tracked page → page_fault_handle_page_track()
 *     in mmu.c calls src_track_log_fault().  We write one src_fault_entry
 *     into the lockless ring buffer using atomic_fetch_add for the slot.
 *     __untrack_single_page() has already run (one-shot P-bit restore).
 *
 *  3. KVM_SRC_TRACK_DRAIN ioctl → userspace drains fault entries.
 *
 *  4. KVM_SRC_TRACK_DISABLE ioctl → clears the enabled flag; residual
 *     tracked pages may still fault but the hot path silently drops them.
 *
 * The two subsystems (dma_track and src_track) can run simultaneously.
 * Userspace correlates them by comparing fault timestamps against active
 * DMA window lifetimes.
 */

#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/ktime.h>
#include <linux/printk.h>
#include <linux/export.h>
#include <linux/kvm_host.h>

#include <asm/kvm_host.h>
#include <asm/kvm_page_track.h>

#include "../mmu/mmu_internal.h"
#include <linux/sev-step/sev-step.h>
#include <linux/sev-step/src_track.h>
#include <uapi/linux/kvm.h>

/* ── global state ──────────────────────────────────────────────── */

atomic_t src_tracking_enabled = ATOMIC_INIT(0);
EXPORT_SYMBOL(src_tracking_enabled);

struct src_fault_ring src_fring;
EXPORT_SYMBOL(src_fring);

/* ── one-time init (idempotent) ────────────────────────────────── */

static bool src_track_inited;

static void src_track_init_once(void)
{
	if (src_track_inited)
		return;

	mutex_init(&src_fring.drain_mutex);
	atomic_set(&src_fring.head, 0);
	src_fring.drain_tail = 0;

	src_track_inited = true;
	pr_info("src_track: initialised  ring=%u entries (%zu KB)\n",
		SRC_FAULT_RING_SIZE,
		(SRC_FAULT_RING_SIZE * sizeof(struct src_fault_entry)) >> 10);
}

/* ── NPF fault logger (hot path – called from mmu.c) ───────────── */

void src_track_log_fault(u64 gfn, u32 vcpu_id, bool is_write)
{
	u32 idx;
	struct src_fault_entry *e;

	/*
	 * Lockless ring-buffer write: each caller atomically claims a unique
	 * slot index, then fills it in place.
	 * Multi-CPU races write to different slots so no slot-level lock
	 * is needed.  The reader (drain) uses READ_ONCE on each field.
	 */
	idx = (u32)atomic_fetch_add(1, &src_fring.head);
	e   = &src_fring.entries[idx % SRC_FAULT_RING_SIZE];

	WRITE_ONCE(e->fault_gpa,    gfn << PAGE_SHIFT);
	WRITE_ONCE(e->timestamp_ns, ktime_get_ns());
	WRITE_ONCE(e->vcpu_id,      vcpu_id);
	WRITE_ONCE(e->is_write,     is_write ? 1 : 0);
}
EXPORT_SYMBOL(src_track_log_fault);

/* ── ioctl: KVM_SRC_TRACK_ENABLE ───────────────────────────────── */

int src_track_enable(u64 start_gfn, u64 nr_pages)
{
	struct kvm      *kvm;
	struct kvm_vcpu *vcpu;
	u64   gfn;
	long  tracked = 0;
	struct kvm_memory_slot *memslot;
	int   srcu_idx;

	src_track_init_once();

	kvm = global_sev_step_config.main_vm;
	if (!kvm) {
		pr_err("src_track: ENABLE: main_vm == NULL "
		       "(SEV-Step not yet connected?)\n");
		return -ENXIO;
	}

	vcpu = kvm_get_vcpu(kvm, 0);
	if (!vcpu) {
		pr_err("src_track: ENABLE: no vCPU[0]\n");
		return -ENXIO;
	}

	if (nr_pages == 0) {
		/*
		 * Track all guest memory.  Reuse kvm_start_tracking() from
		 * sev-step.c – it iterates all memslots, batch-adds with the
		 * no-flush variant, then issues a single TLB flush.
		 */
		tracked = kvm_start_tracking(vcpu, KVM_PAGE_TRACK_ACCESS);
		pr_info("src_track: ENABLED, tracking all memory "
			"(%ld pages)\n", tracked);
	} else {
		/* Track a specific GFN range. */
		srcu_idx = srcu_read_lock(&kvm->srcu);
		write_lock(&kvm->mmu_lock);

		for (gfn = start_gfn; gfn < start_gfn + nr_pages; gfn++) {
			memslot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
			if (!memslot)
				continue;
			if (kvm_page_track_is_active(vcpu, gfn,
						     KVM_PAGE_TRACK_ACCESS))
				continue;
			kvm_slot_page_track_add_page_no_flush(
				kvm, memslot, gfn, KVM_PAGE_TRACK_ACCESS);
			tracked++;
		}

		write_unlock(&kvm->mmu_lock);
		srcu_read_unlock(&kvm->srcu, srcu_idx);

		if (tracked > 0)
			kvm_flush_remote_tlbs(kvm);

		pr_info("src_track: ENABLED, tracking GFNs [0x%llx, 0x%llx) "
			"(%ld/%llu pages tracked)\n",
			start_gfn, start_gfn + nr_pages,
			tracked, nr_pages);
	}

	atomic_set(&src_tracking_enabled, 1);
	return 0;
}
EXPORT_SYMBOL(src_track_enable);

/* ── ioctl: KVM_SRC_TRACK_DISABLE ──────────────────────────────── */

int src_track_disable(void)
{
	/*
	 * Clear the enabled flag.  Residual tracked pages may still fire
	 * NPFs, but the hot path checks src_tracking_enabled first and
	 * silently ignores them.  This avoids an expensive full-scan on
	 * disable.
	 *
	 * If hard cleanup is needed, call:
	 *   kvm_stop_tracking(vcpu, KVM_PAGE_TRACK_ACCESS)
	 * before the atomic_set – at the cost of higher disable latency.
	 */
	atomic_set(&src_tracking_enabled, 0);
	pr_info("src_track: DISABLED\n");
	return 0;
}
EXPORT_SYMBOL(src_track_disable);

/* ── ioctl: KVM_SRC_TRACK_DRAIN ────────────────────────────────── */

int src_track_drain(void __user *argp)
{
	struct kvm_src_drain_param       param;
	struct kvm_src_fault_entry __user *ufaults;
	struct kvm_src_fault_entry        kfault;
	u32 nr = 0;
	u32 head_snap, tail;

	if (copy_from_user(&param, argp, sizeof(param))) {
		pr_err("src_track: DRAIN copy_from_user(param) failed\n");
		return -EFAULT;
	}

	ufaults = (struct kvm_src_fault_entry __user *)
		  (uintptr_t)param.faults_ptr;

	if (param.max_faults > SRC_FAULT_RING_SIZE)
		param.max_faults = SRC_FAULT_RING_SIZE;

	mutex_lock(&src_fring.drain_mutex);

	head_snap = (u32)atomic_read(&src_fring.head);
	tail      = src_fring.drain_tail;

	/* Handle ring wrap: only expose the last RING_SIZE entries. */
	if ((head_snap - tail) > SRC_FAULT_RING_SIZE)
		tail = head_snap - SRC_FAULT_RING_SIZE;

	while (tail != head_snap && nr < param.max_faults) {
		u32 slot = tail % SRC_FAULT_RING_SIZE;
		struct src_fault_entry *fe = &src_fring.entries[slot];

		kfault.fault_gpa    = READ_ONCE(fe->fault_gpa);
		kfault.timestamp_ns = READ_ONCE(fe->timestamp_ns);
		kfault.vcpu_id      = READ_ONCE(fe->vcpu_id);
		kfault.is_write     = READ_ONCE(fe->is_write);
		memset(kfault._pad, 0, sizeof(kfault._pad));

		if (ufaults &&
		    copy_to_user(&ufaults[nr], &kfault, sizeof(kfault))) {
			mutex_unlock(&src_fring.drain_mutex);
			pr_err("src_track: DRAIN copy_to_user(fault[%u]) "
			       "failed\n", nr);
			return -EFAULT;
		}
		nr++;
		tail++;
	}
	src_fring.drain_tail = tail;
	mutex_unlock(&src_fring.drain_mutex);

	pr_info("src_track: DRAIN done  faults=%u\n", nr);

	param.nr_faults = nr;
	if (copy_to_user(argp, &param, sizeof(param))) {
		pr_err("src_track: DRAIN copy_to_user(param out) failed\n");
		return -EFAULT;
	}
	return 0;
}
EXPORT_SYMBOL(src_track_drain);
