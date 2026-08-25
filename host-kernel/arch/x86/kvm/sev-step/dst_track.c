// SPDX-License-Identifier: GPL-2.0
/*
 * dst_track.c – SEV-Step Dst-Page tracking engine.
 *
 * Detects which guest pages the CPU *writes* after reading from a GPU
 * DMA bounce buffer (GPU→CPU, Device-to-Host direction).
 *
 * Architecture
 * ============
 *  1. KVM_DST_TRACK_ENABLE ioctl → apply KVM_PAGE_TRACK_WRITE to a
 *     GFN range (or all memory when nr_pages == 0).
 *
 *  2. On each NPF write-fault for a tracked page →
 *     page_fault_handle_page_track() in mmu.c calls
 *     dst_track_log_fault().  The current dma_current_window_id is
 *     stamped into the ring entry, enabling direct userspace
 *     correlation with dma_track D2H windows.
 *
 *  3. KVM_DST_TRACK_DRAIN ioctl → userspace drains fault entries.
 *
 *  4. KVM_DST_TRACK_DISABLE → clears enabled flag.
 *
 * Correlation with D2H DMA windows
 * =================================
 * Each dst_fault_entry carries dma_window_id = dma_current_window_id
 * at fault time.  A write fault is a Dst-page candidate for D2H window
 * N when:
 *   - fault.dma_window_id == N
 *   - dma_window[N].prot & IOMMU_WRITE   (D2H direction)
 *   - fault.timestamp_ns > dma_window[N].unmap_ts_ns
 *     (CPU wrote AFTER the GPU finished DMA)
 */

#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/mutex.h>
#include <linux/uaccess.h>
#include <linux/ktime.h>
#include <linux/printk.h>
#include <linux/export.h>
#include <linux/kvm_host.h>

#include <asm/kvm_host.h>
#include <asm/kvm_page_track.h>

#include "../mmu/mmu_internal.h"
#include <linux/sev-step/sev-step.h>
#include <linux/sev-step/dma_track.h>
#include <linux/sev-step/dst_track.h>
#include <uapi/linux/kvm.h>

/* ── global state ──────────────────────────────────────────────── */

atomic_t dst_tracking_enabled = ATOMIC_INIT(0);
EXPORT_SYMBOL(dst_tracking_enabled);

struct dst_fault_ring dst_fring;
EXPORT_SYMBOL(dst_fring);

/* ── one-time init (idempotent) ────────────────────────────────── */

static bool dst_track_inited;

static void dst_track_init_once(void)
{
	if (dst_track_inited)
		return;

	mutex_init(&dst_fring.drain_mutex);
	atomic_set(&dst_fring.head, 0);
	dst_fring.drain_tail = 0;

	dst_track_inited = true;
	pr_info("dst_track: initialised  ring=%u entries (%zu KB)\n",
		DST_FAULT_RING_SIZE,
		(DST_FAULT_RING_SIZE * sizeof(struct dst_fault_entry)) >> 10);
}

/* ── NPF write-fault logger (hot path – called from mmu.c) ─────── */

void dst_track_log_fault(u64 gfn, u32 vcpu_id)
{
	u32 idx;
	struct dst_fault_entry *e;

	idx = (u32)atomic_fetch_add(1, &dst_fring.head);
	e   = &dst_fring.entries[idx % DST_FAULT_RING_SIZE];

	WRITE_ONCE(e->fault_gpa,     gfn << PAGE_SHIFT);
	WRITE_ONCE(e->timestamp_ns,  ktime_get_ns());
	WRITE_ONCE(e->dma_window_id, (u64)atomic64_read(&dma_current_window_id));
	WRITE_ONCE(e->vcpu_id,       vcpu_id);
}
EXPORT_SYMBOL(dst_track_log_fault);

/* ── ioctl: KVM_DST_TRACK_ENABLE ───────────────────────────────── */

int dst_track_enable(u64 start_gfn, u64 nr_pages)
{
	struct kvm      *kvm;
	struct kvm_vcpu *vcpu;
	u64   gfn;
	long  tracked = 0;
	struct kvm_memory_slot *memslot;
	int   srcu_idx;

	dst_track_init_once();

	kvm = global_sev_step_config.main_vm;
	if (!kvm) {
		pr_err("dst_track: ENABLE: main_vm == NULL\n");
		return -ENXIO;
	}

	vcpu = kvm_get_vcpu(kvm, 0);
	if (!vcpu) {
		pr_err("dst_track: ENABLE: no vCPU[0]\n");
		return -ENXIO;
	}

	if (nr_pages == 0) {
		/*
		 * Track writes to all guest memory.
		 * KVM_PAGE_TRACK_WRITE fires only on write accesses,
		 * keeping fault rate lower than ACCESS tracking.
		 */
		tracked = kvm_start_tracking(vcpu, KVM_PAGE_TRACK_WRITE);
		pr_info("dst_track: ENABLED, tracking all memory "
			"(%ld pages, WRITE-only)\n", tracked);
	} else {
		srcu_idx = srcu_read_lock(&kvm->srcu);
		write_lock(&kvm->mmu_lock);

		for (gfn = start_gfn; gfn < start_gfn + nr_pages; gfn++) {
			memslot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
			if (!memslot)
				continue;
			if (kvm_page_track_is_active(vcpu, gfn,
						     KVM_PAGE_TRACK_WRITE))
				continue;
			kvm_slot_page_track_add_page_no_flush(
				kvm, memslot, gfn, KVM_PAGE_TRACK_WRITE);
			tracked++;
		}

		write_unlock(&kvm->mmu_lock);
		srcu_read_unlock(&kvm->srcu, srcu_idx);

		if (tracked > 0)
			kvm_flush_remote_tlbs(kvm);

		pr_info("dst_track: ENABLED, tracking GFNs [0x%llx, 0x%llx) "
			"(%ld/%llu pages tracked, WRITE-only)\n",
			start_gfn, start_gfn + nr_pages,
			tracked, nr_pages);
	}

	atomic_set(&dst_tracking_enabled, 1);
	return 0;
}
EXPORT_SYMBOL(dst_track_enable);

/* ── ioctl: KVM_DST_TRACK_DISABLE ──────────────────────────────── */

int dst_track_disable(void)
{
	atomic_set(&dst_tracking_enabled, 0);
	pr_info("dst_track: DISABLED\n");
	return 0;
}
EXPORT_SYMBOL(dst_track_disable);

/* ── ioctl: KVM_DST_TRACK_DRAIN ────────────────────────────────── */

int dst_track_drain(void __user *argp)
{
	struct kvm_dst_drain_param       param;
	struct kvm_dst_fault_entry __user *ufaults;
	struct kvm_dst_fault_entry        kfault;
	u32 nr = 0;
	u32 head_snap, tail;

	if (copy_from_user(&param, argp, sizeof(param))) {
		pr_err("dst_track: DRAIN copy_from_user(param) failed\n");
		return -EFAULT;
	}

	ufaults = (struct kvm_dst_fault_entry __user *)
		  (uintptr_t)param.faults_ptr;

	if (param.max_faults > DST_FAULT_RING_SIZE)
		param.max_faults = DST_FAULT_RING_SIZE;

	mutex_lock(&dst_fring.drain_mutex);

	head_snap = (u32)atomic_read(&dst_fring.head);
	tail      = dst_fring.drain_tail;

	if ((head_snap - tail) > DST_FAULT_RING_SIZE)
		tail = head_snap - DST_FAULT_RING_SIZE;

	while (tail != head_snap && nr < param.max_faults) {
		u32 slot = tail % DST_FAULT_RING_SIZE;
		struct dst_fault_entry *fe = &dst_fring.entries[slot];

		kfault.fault_gpa    = READ_ONCE(fe->fault_gpa);
		kfault.timestamp_ns = READ_ONCE(fe->timestamp_ns);
		kfault.dma_window_id = READ_ONCE(fe->dma_window_id);
		kfault.vcpu_id      = READ_ONCE(fe->vcpu_id);
		memset(kfault._pad, 0, sizeof(kfault._pad));

		if (ufaults &&
		    copy_to_user(&ufaults[nr], &kfault, sizeof(kfault))) {
			mutex_unlock(&dst_fring.drain_mutex);
			pr_err("dst_track: DRAIN copy_to_user(fault[%u]) "
			       "failed\n", nr);
			return -EFAULT;
		}
		nr++;
		tail++;
	}
	dst_fring.drain_tail = tail;
	mutex_unlock(&dst_fring.drain_mutex);

	pr_info("dst_track: DRAIN done  faults=%u\n", nr);

	param.nr_faults = nr;
	if (copy_to_user(argp, &param, sizeof(param))) {
		pr_err("dst_track: DRAIN copy_to_user(param out) failed\n");
		return -EFAULT;
	}
	return 0;
}
EXPORT_SYMBOL(dst_track_drain);
