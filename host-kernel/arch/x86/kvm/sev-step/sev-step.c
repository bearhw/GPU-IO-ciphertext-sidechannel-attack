#include <linux/smp.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <asm/svm.h> //struct vmcb_save_area
#include <linux/psp-sev.h>
#include <linux/spinlock.h>
#include <linux/delay.h>

#include "../mmu.h"
#include "mmu/mmu_internal.h"

#include <linux/sev-step/userspace_page_track_api.h>
#include <linux/sev-step/sev-step.h>
#include <linux/sev-step/libcache.h>
#include "svm/svm.h"

#include <linux/types.h>
#include <asm/cacheflush.h>

#include <linux/highmem.h>

DEFINE_MUTEX(sev_step_config_mutex);
EXPORT_SYMBOL(sev_step_config_mutex);

#ifndef sev_step_dbg_log
#define sev_step_dbg_log(fmt, ...) \
	printk(KERN_DEBUG "%s:%d : %s " fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#endif

sev_step_config_t global_sev_step_config = {
	.tmict_value = 0,
	.single_stepping_status = SEV_STEP_STEPPING_STATUS_DISABLED,
    .counted_instructions = 0,
    .decrypt_vmsa = false,
    .main_vm = NULL,
    .waitingForTimer = false,
    .got_idt_on_cpu = -1,
	.perf_init = false,
	.entry_counter = 0,
    .tsc_latency = 0,
	.idt = {0},
    .old_apic_lvtt = 0,
    .old_apic_tdcr = 0,
    .old_apic_tmict = 0,
	.old_idt_gate = {0},

	.cache_attack_config = NULL,
	.main_vm_pid = 0,

	.is_dump_page = false,
	.nr_dump_pages = 0,
	.dump_page_gpas = NULL,
	.is_decrypt_when_dump = false,
	.is_relocate_when_dump = false,

	.prev_fault_gpa = (uint64_t)-1,
	.curr_fault_gpa = (uint64_t)-1,
	// .decrypt_page_content = false,
	.is_dump_pre_fault_when_track = false,
	.is_dump_post_fault_when_track = false,
	.is_decrypt_when_track = false,
	.is_relocate_when_track = false,
	.nr_track_events = 0,
#ifdef ENABLE_MONITOR_UNTRACKED_PAGES
	.is_observe_untracked_pages = false,
	.is_send_all_updated_pages = false,
	.nr_special_values_when_track = 0,
	.special_values_when_track = NULL,
#endif // ENABLE_MONITOR_UNTRACKED_PAGES

#ifdef ENABLE_OLD_SWAP_PAGES_SUPPORT
	.is_swap_pages = false,
	.nr_swap_times = 0,
	.nr_gfn1_new_assignments = 0,
	.nr_gfn2_new_assignments = 0,
	.is_swap_back = false,
	.swap_gfn1 = -1,
	.swap_gfn2 = -1,
#endif // ENABLE_OLD_SWAP_PAGES_SUPPORT

#ifdef ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT
	.null_cipher_repr_gpa = (uint64_t)-1,
	.null_cipher_repr_spa = (uint64_t)-1,
	.null_cipher_repr = NULL,
#endif // ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT

	.is_dump_private_pages = false,

	.target_page_pfn = (uint64_t)-1,
	.target_page_hva = 0,
	.target_page_null_ciphertexts = NULL,

	.gfn_to_translate = (uint64_t)-1,
	.translated_pfn_of_gfn = (uint64_t)-1,
};
EXPORT_SYMBOL(global_sev_step_config);

bool sev_step_is_single_stepping_active(sev_step_config_t* cfg) {
	return (cfg->single_stepping_status == SEV_STEP_STEPPING_STATUS_ENABLED) ||
		(cfg->single_stepping_status == SEV_STEP_STEPPING_STATUS_ENABLED_WANT_DISABLE);
}
EXPORT_SYMBOL(sev_step_is_single_stepping_active);

//used to store performance counter values; 6 counters, 2 readings per counter
uint64_t perf_reads[6][2];
perf_ctl_config_t perf_configs[6];
int perf_cpu;

uint64_t perf_ctl_to_u64(perf_ctl_config_t * config) {

	uint64_t result = 0;
	result |= (  config->EventSelect & 0xffULL); //[7:0] in result and  [7:0] in EventSelect
	result |= ( (config->UintMask & 0xffULL) << 8 ); //[15:8]
	result |= ( (config->OsUserMode & 0x3ULL) << 16); //[17:16]
	result |= ( (config->Edge & 0x1ULL ) << 18 ); // 18
	result |= ( (config->Int & 0x1ULL ) << 20 ); // 20
	result |= ( (config->En & 0x1ULL ) << 22 ); //22
	result |= ( (config->Inv & 0x1ULL ) << 23); //23
	result |= ( (config->CntMask & 0xffULL) << 24); //[31:24]
	result |= ( ( (config->EventSelect & 0xf00ULL) >> 8 ) << 32); //[35:32] in result and [11:8] in EventSelect
	result |= ( (config->HostGuestOnly & 0x3ULL) << 40); // [41:40]

	return result;

}

/* Need to be done this way, if moved to sev-step.h there are many building errors */
//uint64_t sev_step_get_rip(struct vcpu_svm* svm); prototyp is in svm.c

/**
 * @brief Tell sev to decrypt the data for debug purposes
 * 
 * @param kvm kvm struct to get the info from
 * @param src source address for the data
 * @param dst destination address for the data
 * @param size size of the data
 * @param error error code
 * @return int result from the execution of the command
 */
static int __my_sev_issue_dbg_cmd(struct kvm *kvm, unsigned long src,
			       unsigned long dst, int size,
			       int *error)
{
	struct kvm_sev_info *sev = &to_kvm_svm(kvm)->sev_info;
	struct sev_data_dbg *data;
	int ret;

	data = kzalloc(sizeof(*data), GFP_KERNEL_ACCOUNT);
	if (!data)
		return -ENOMEM;

	data->handle = sev->handle;
	data->dst_addr = dst;
	data->src_addr = src;
	data->len = size;

	/*ret = sev_issue_cmd(kvm,
			     SEV_CMD_DBG_DECRYPT,
			    data, error);*/
	ret = sev_do_cmd(SEV_CMD_DBG_DECRYPT, data, error);
	kfree(data);
	return ret;
}

/**
 * @brief Decrypt the vmcb_save_area
 * 
 * @param svm svm for getting the vmsa and vmcb
 * @param save_area the save area
 * @return int 0 on success
 */
int decrypt_vmsa(struct vcpu_svm* svm, struct vmcb_save_area* save_area) {

	uint64_t src_paddr, dst_paddr;
	void * dst_vaddr;
	void * src_vaddr;
	struct page * dst_page;
	int call_res,api_res;
	uint64_t payload_bytes;
	uint64_t decrypt_bytes;
	call_res = 1337;
	api_res = 1337;
	
	src_vaddr = svm->sev_es.vmsa;
	src_paddr = svm->vmcb->control.vmsa_pa;

	if( src_paddr % 16 != 0) {
		printk("decrypt_vmsa: src_paddr 0x%llx is not 16b aligned\n",(uint64_t)src_paddr);
		return -1;
	}

	payload_bytes = sizeof( struct vmcb_save_area);
	decrypt_bytes = payload_bytes;
	if( decrypt_bytes % 16 != 0 ) {
		printk("decrypt_vmsa: warning size of decrypt_bytes (0x%llx)is not 16 b aligned. Rounding up\n", decrypt_bytes);
		decrypt_bytes += (16 - (decrypt_bytes % 16));
		printk("new value is 0x%llx\n",decrypt_bytes);
	}
	if(decrypt_bytes > 4096 ) {
		printk("decrypt_vmsa: decrypt_bytes (0x%llx) large than page size, this is currently not supported\n",decrypt_bytes);
		return -1;
	}

	dst_page = alloc_page(GFP_KERNEL);
	dst_vaddr =  vmap(&dst_page, 1, 0, PAGE_KERNEL);
	dst_paddr = page_to_pfn(dst_page) << PAGE_SHIFT;
	memset(dst_vaddr,0,PAGE_SIZE);

	if( dst_paddr % 16 != 0 ) {
		printk("decrypt_vmsa: dst_paddr 0x%llx ist not 16 byte aligned\n", (uint64_t)dst_paddr);
		return -1;
	}

	//printk("src_paddr = 0x%llx dst_paddr = 0x%llx\n", __sme_clr(src_paddr), __sme_clr(dst_paddr));
	//printk("Sizeof vmcb_save_area is: 0x%lx\n", sizeof( struct vmcb_save_area) );


	call_res = __my_sev_issue_dbg_cmd(svm->vcpu.kvm, __sme_set(src_paddr), __sme_set(dst_paddr), decrypt_bytes, &api_res);


	printk("decrypt_vmsa: result of call was %d, result of api command was %d\n",call_res, api_res);

	//todo error handling
	if( api_res != 0 ) {
		__free_page(dst_page);
		return -1;
	}

	memcpy(save_area, dst_vaddr, payload_bytes );


	__free_page(dst_page);

	return 0;


}

/**
 * @brief Decrypt the rip of sev
 * 
 * @param svm svm for getting the info
 * @return uint64_t the decrypted rip
 */
uint64_t sev_step_get_rip(struct vcpu_svm* svm) {
	struct vmcb_save_area* save_area;
	struct kvm * kvm;
	struct kvm_sev_info *sev;
	uint64_t rip;

	printk("sev_step_get_rip: got called\n");
	kvm = svm->vcpu.kvm;
	sev = &to_kvm_svm(kvm)->sev_info;

	printk("sev-active: %d, sev->es_active :%d, sev->snp_active: %d\n",sev->active,
		sev->es_active,sev->snp_active);
	//for sev-es and sev-snp we need to use the debug api, to decrypt the vmsa
	if( sev->active && (sev->es_active || sev->snp_active)) {
		int res;
		save_area = vmalloc(sizeof(struct vmcb_save_area) );
		memset(save_area,0, sizeof(struct vmcb_save_area));

		res = decrypt_vmsa(svm, save_area);
		if( res != 0) {
			printk("sev_step_get_rip failed to decrypt\n");
			return 0;
		}

		rip =  save_area->rip;

		vfree(save_area);
	} else { //otherwise we can just access as plaintexts
		rip = svm->vmcb->save.rip;
	}
	return rip;

}
EXPORT_SYMBOL(sev_step_get_rip);

void write_ctl(perf_ctl_config_t * config, int cpu, uint64_t ctl_msr){
	wrmsrl( ctl_msr, perf_ctl_to_u64(config)); //always returns zero
}

void read_ctr(uint64_t ctr_msr, int cpu, uint64_t* result) {
    uint64_t tmp;
	rdmsrl( ctr_msr, tmp); //always returns zero
	*result = tmp & ( (0x1ULL << 48) - 1);
}

void setup_perfs(sev_step_config_t* config) {
    int i;
    
    //perf_cpu = smp_processor_id();
    
    for( i = 0; i < 6; i++) {
        perf_configs[i].HostGuestOnly = 0x1; //0x1 means: count only guest
        perf_configs[i].CntMask = 0x0;
        perf_configs[i].Inv = 0x0;
        perf_configs[i].En = 0x0;
        perf_configs[i].Int = 0x0;
        perf_configs[i].Edge = 0x0;
        perf_configs[i].OsUserMode = 0x3; //0x3 means: count userland and kernel events
    }
    
    //remember to set .En to enable the individual counter
    perf_configs[0].EventSelect = 0x0c0;
	perf_configs[0].UintMask = 0x0;
    perf_configs[0].En = 0x1;
	write_ctl(&perf_configs[0],perf_cpu, CTL_MSR_0);

	if( config->cache_attack_config != NULL ) {
		perf_configs[1] = config->cache_attack_config->cache_attack_perf;
		if( perf_configs[1].En == 0 ) {
			printk("%s:%d : %s Warning Cache Attack Perf not enabled!\n",
				__FILE__,
				__LINE__,
				__FUNCTION__
			);
		}
	}
	write_ctl(&perf_configs[1],perf_cpu,CTL_MSR_1);
    
}
EXPORT_SYMBOL(setup_perfs);

void calculate_steps(sev_step_config_t *config) {
   if(!config->perf_init) {
        read_ctr(CTR_MSR_0, perf_cpu, &perf_reads[0][0]);        
        config->perf_init = true;
    } else {
        read_ctr(CTR_MSR_0, perf_cpu, &perf_reads[0][1] );
		//TODO: fix case where readings are identical. underflow is very confusing!
        config->counted_instructions = perf_reads[0][1] - perf_reads[0][0] -1;
        config->perf_init = false;
    }
}
EXPORT_SYMBOL(calculate_steps);

bool __untrack_single_page(struct kvm_vcpu *vcpu, gfn_t gfn,
                           enum kvm_page_track_mode mode) {
  int idx;
  bool ret;
  struct kvm_memory_slot *slot;

  ret = false;
  idx = srcu_read_lock(&vcpu->kvm->srcu);
  slot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);

  if (slot != NULL && kvm_page_track_is_active(vcpu, gfn, mode)) {

    write_lock(&vcpu->kvm->mmu_lock);
    kvm_slot_page_track_remove_page(vcpu->kvm, slot, gfn, mode);
    write_unlock(&vcpu->kvm->mmu_lock);
    ret = true;

  } else {

    printk("Failed to untrack %016llx because ", gfn);
    if (slot == NULL) {
      printk(KERN_CONT "slot was  null");
    } else if (!kvm_page_track_is_active(vcpu, gfn, mode)) {
      printk(KERN_CONT "page track was not active");
    }
    printk(KERN_CONT "\n");
  }
  srcu_read_unlock(&vcpu->kvm->srcu, idx);
  return ret;
}
EXPORT_SYMBOL(__untrack_single_page);

bool __track_single_page(struct kvm_vcpu *vcpu, gfn_t gfn,
			 enum kvm_page_track_mode mode, bool is_allow_retrack)
{
  int idx;
  bool ret;
  struct kvm_memory_slot *slot;
  bool is_tracked;

  ret = false;
  idx = srcu_read_lock(&vcpu->kvm->srcu);
  slot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);

  is_tracked = kvm_page_track_is_active(vcpu, gfn, mode);
  if (is_tracked && is_allow_retrack) {
	return true;
  }

  if (slot != NULL && !is_tracked) {
    write_lock(&vcpu->kvm->mmu_lock);
    kvm_slot_page_track_add_page(vcpu->kvm, slot, gfn, mode);
    write_unlock(&vcpu->kvm->mmu_lock);
    ret = true;
  } else {
    printk("Failed to track %016llx because ", gfn);
    if (slot == NULL) {
      printk(KERN_CONT "slot was  null");
    }
    if (kvm_page_track_is_active(vcpu, gfn, mode)) {
      printk(KERN_CONT "page is already tracked");
    }
    printk(KERN_CONT "\n");
  }
  srcu_read_unlock(&vcpu->kvm->srcu, idx);
  return ret;
}
EXPORT_SYMBOL(__track_single_page);

//track all pages; taken from severed repo
long kvm_start_tracking(struct kvm_vcpu *vcpu,enum kvm_page_track_mode mode ) {
	long count = 0;
	u64 iterator, iterat_max;
	struct kvm_memslots* slots;
	struct kvm_memory_slot *slot;
	int srcu_lock_retval,bkt,i;

	for( i = 0; i < KVM_ADDRESS_SPACE_NUM; i++) {
		slots = __kvm_memslots(vcpu->kvm,i);
		kvm_for_each_memslot(slot, bkt, slots) {
			iterat_max = slot->base_gfn + slot->npages;
			srcu_lock_retval = srcu_read_lock(&vcpu->kvm->srcu);
			write_lock(&vcpu->kvm->mmu_lock);
			for (iterator=0; iterator < iterat_max; iterator++)
			{
				slot = kvm_vcpu_gfn_to_memslot(vcpu, iterator);
				if ( slot != NULL ) {
					if( !kvm_page_track_is_active(vcpu, iterator, mode)) {
						kvm_slot_page_track_add_page_no_flush(vcpu->kvm, slot, iterator, mode);
						count++;
					}
				}
				// FIXME: Commented out to avoid rescheduling
				// if( need_resched() || rwlock_needbreak(&vcpu->kvm->mmu_lock))  {
				// 	cond_resched_rwlock_write(&vcpu->kvm->mmu_lock);
				// }
			}
			write_unlock(&vcpu->kvm->mmu_lock);
			srcu_read_unlock(&vcpu->kvm->srcu, srcu_lock_retval);
		}
	}
	if( count > 0 ) {
		kvm_flush_remote_tlbs(vcpu->kvm);
	}
    return count;
}
EXPORT_SYMBOL(kvm_start_tracking);

long kvm_track_pages(struct kvm_vcpu *vcpu, u64 nr_pages, u64 *track_gpas,
		     enum kvm_page_track_mode mode)
{
	long count = 0;
	u64 i;
	for (i = 0; i < nr_pages; i++) {
		u64 gfn = track_gpas[i] >> PAGE_SHIFT;
		if (__track_single_page(vcpu, gfn, mode, false)) {
			count++;
		}
	}
	return count;
}
EXPORT_SYMBOL(kvm_track_pages);

long kvm_track_all_pages_except(struct kvm_vcpu *vcpu,
				u64 nr_except_pages, u64 *except_gpas,
				enum kvm_page_track_mode mode)
{
	long count = 0;
	u64 iterator, iterat_max;
	struct kvm_memslots *slots;
	struct kvm_memory_slot *slot;
	int srcu_lock_retval, bkt, i;

	for (i = 0; i < KVM_ADDRESS_SPACE_NUM; i++) {
		slots = __kvm_memslots(vcpu->kvm, i);
		kvm_for_each_memslot(slot, bkt, slots) {
			iterat_max = slot->base_gfn + slot->npages;
			srcu_lock_retval = srcu_read_lock(&vcpu->kvm->srcu);
			write_lock(&vcpu->kvm->mmu_lock);
			for (iterator = 0; iterator < iterat_max; iterator++) {
				slot = kvm_vcpu_gfn_to_memslot(vcpu, iterator);
				if (slot != NULL) {
					bool found = false;
					for (u64 j = 0; j < nr_except_pages; j++) {
						if (except_gpas[j] == iterator) {
							found = true;
							break;
						}
					}
					if (!found && !kvm_page_track_is_active(vcpu, iterator, mode)) {
						kvm_slot_page_track_add_page_no_flush(vcpu->kvm, slot, iterator, mode);
						count++;
					}
				}
				if (need_resched() || rwlock_needbreak(&vcpu->kvm->mmu_lock)) {
					cond_resched_rwlock_write(&vcpu->kvm->mmu_lock);
				}
			}
			write_unlock(&vcpu->kvm->mmu_lock);
			srcu_read_unlock(&vcpu->kvm->srcu, srcu_lock_retval);
		}
	}
	if (count > 0) {
		kvm_flush_remote_tlbs(vcpu->kvm);
	}
	return count;
}

//untrack all pages; taken from severed repo
long kvm_stop_tracking(struct kvm_vcpu *vcpu,enum kvm_page_track_mode mode ) {
		long count = 0;
		u64 iterator, iterat_max;
		struct kvm_memslots* slots;
		struct kvm_memory_slot *slot;
		int srcu_lock_retval,bkt,i;

		for( i = 0; i < KVM_ADDRESS_SPACE_NUM; i++) {
			slots = __kvm_memslots(vcpu->kvm,i);
			kvm_for_each_memslot(slot, bkt, slots) {
				iterat_max = slot->base_gfn + slot->npages;
				srcu_lock_retval = srcu_read_lock(&vcpu->kvm->srcu);
				write_lock(&vcpu->kvm->mmu_lock);
				for (iterator=0; iterator < iterat_max; iterator++)
				{
					slot = kvm_vcpu_gfn_to_memslot(vcpu, iterator);
					if( slot != NULL && kvm_page_track_is_active(vcpu, iterator,  mode)) {
						kvm_slot_page_track_remove_page(vcpu->kvm, 
										slot, 
										iterator, 
										mode);
						
						count++;
					}

					// FIXME: Commented out to avoid rescheduling
					// if( need_resched() || rwlock_needbreak(&vcpu->kvm->mmu_lock))  {
					// 	cond_resched_rwlock_write(&vcpu->kvm->mmu_lock);
					// }
				}
				write_unlock(&vcpu->kvm->mmu_lock);
				srcu_read_unlock(&vcpu->kvm->srcu, srcu_lock_retval);
			}
		}
    return count;
}
EXPORT_SYMBOL(kvm_stop_tracking);

bool __clear_nx_on_page(struct kvm_vcpu *vcpu, gfn_t gfn) {
	int idx;
	bool ret;
	struct kvm_memory_slot *slot;

	ret = false;
	idx = srcu_read_lock(&vcpu->kvm->srcu);
	slot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
	if( slot != NULL ) {
		write_lock(&vcpu->kvm->mmu_lock);
		kvm_mmu_slot_gfn_protect(vcpu->kvm,slot,gfn,PG_LEVEL_4K,KVM_PAGE_TRACK_RESET_EXEC);
		write_unlock(&vcpu->kvm->mmu_lock);
		ret = true;
	}
	srcu_read_unlock(&vcpu->kvm->srcu, idx);
	return ret;
}
EXPORT_SYMBOL(__clear_nx_on_page);

bool sev_step_reset_access_bit(struct kvm_vcpu *vcpu, gfn_t gfn) {
	int idx;
	bool ret;
	struct kvm_memory_slot *slot;

	ret = false;
	idx = srcu_read_lock(&vcpu->kvm->srcu);
	slot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
	if( slot != NULL ) {
		write_lock(&vcpu->kvm->mmu_lock);
		kvm_mmu_slot_gfn_protect(vcpu->kvm,slot,gfn,PG_LEVEL_4K,KVM_PAGE_TRACK_RESET_ACCESSED);
		write_unlock(&vcpu->kvm->mmu_lock);
		ret = true;
	}
	srcu_read_unlock(&vcpu->kvm->srcu, idx);
	return ret;
}
EXPORT_SYMBOL(sev_step_reset_access_bit);




void free_sev_step_cache_attack_config_t(sev_step_cache_attack_config_t* config) {
	kfree(config->lookup_tables);
	free_eviction_sets(config->eviction_sets,config->lookup_tables_len);
	kfree(config);
}
EXPORT_SYMBOL(free_sev_step_cache_attack_config_t);


int sev_step_get_vmcb_save_area(struct kvm_vcpu *vcpu, struct vmcb_save_area* vmcb_result,
	struct sev_es_save_area *vmsa_result) {
	struct vcpu_svm *svm = to_svm(vcpu);
	struct vmcb_save_area *save = &svm->vmcb->save;
	struct vmcb_save_area *save01 = &svm->vmcb01.ptr->save;



	if (vcpu->arch.guest_state_protected && sev_snp_guest(vcpu->kvm) ) {
		struct sev_es_save_area *vmsa;
		struct kvm_sev_info *sev = &to_kvm_svm(vcpu->kvm)->sev_info;
		struct page *save_page;
		int ret, error;

		save_page = alloc_page(GFP_KERNEL);
		if (!save_page)
			return 1;

		save = page_address(save_page);
		save01 = save;


		ret = snp_guest_dbg_decrypt_page(__pa(sev->snp_context) >> PAGE_SHIFT,
						 svm->vmcb->control.vmsa_pa >> PAGE_SHIFT,
						 __pa(save) >> PAGE_SHIFT,
						 &error);
		if (ret) {
			pr_err("%s: sev_snp_guest : failed to decrypt vmsa with ret=%d,  error=0x%x, (dec) error=%d\n", __func__, ret, error,error);
			return 1;
		}

		memcpy(vmcb_result,save,sizeof(struct vmcb_save_area));

		vmsa = (struct sev_es_save_area *)save;
		memcpy(vmsa_result,vmsa,sizeof(struct sev_es_save_area));

		__free_page(virt_to_page(save));
	} else if( vcpu->arch.guest_state_protected && sev_es_guest(vcpu->kvm)) {
		struct sev_es_save_area *vmsa;
		int error;


		error = decrypt_vmsa(svm, vmcb_result);
		if( error != 0) {
			pr_err("%s: sev_es_guest : failed to decrypt vmsa %d\n", __func__, error);
			return 1;
		}
		vmsa = (struct sev_es_save_area *)vmcb_result;
		memcpy(vmsa_result,vmsa,sizeof(struct sev_es_save_area));

	} else if (vcpu->arch.guest_state_protected) {
		printk("sev_step_get_vmcb_save_area: guest state protected but don't know how to decrypt\n");
		return 1;
	} else {
		memcpy(vmcb_result,save,sizeof(struct vmcb_save_area));
	}

	return 0;
}
EXPORT_SYMBOL(sev_step_get_vmcb_save_area);

// struct gpa_to_ciphertext_cache *
// find_page_ciphertext_cache_at_gpa(sev_step_config_t *config, uint64_t gpa)
// {
// 	struct gpa_to_ciphertext_cache *entry;
// 	hash_for_each_possible(config->ciphertext_pages_cache, entry, hash_node,
// 			       gpa) {
// 		if (entry->gpa == gpa)
// 		{
// 			return entry;
// 		}
// 	}
// 	return NULL;
// }
// EXPORT_SYMBOL(find_page_ciphertext_cache_at_gpa);

// int insert_page_ciphertext_cache_at_gpa(sev_step_config_t *config, uint64_t gpa,
// 					uint8_t *ciphertext,
// 					uint8_t *null_bitmap)
// {
// 	int ret = 0;
// 	struct gpa_to_ciphertext_cache *entry;
// 	entry = kmalloc(sizeof(struct gpa_to_ciphertext_cache), GFP_KERNEL);
// 	entry->gpa = gpa;
// 	entry->ct_cache = kmalloc(PAGE_SIZE, GFP_KERNEL);
// 	entry->null_bitmap = kmalloc(PAGE_SIZE / 16, GFP_KERNEL);
// 	if (entry->ct_cache == NULL || entry->null_bitmap == NULL)
// 	{
// 		ret = -ENOMEM;
// 		printk(KERN_ERR
// 		       "%s: Failed to allocate memory for ciphertext cache\n",
// 		       __func__);
// 		goto error_out;
// 	}
// 	memcpy(entry->ct_cache, ciphertext, PAGE_SIZE);
// 	memcpy(entry->null_bitmap, null_bitmap, PAGE_SIZE / 16);
// 	INIT_HLIST_NODE(&entry->hash_node);
// 	// spin_lock(&config->ciphertext_pages_cache_lock);
// 	hash_add(config->ciphertext_pages_cache, &entry->hash_node, gpa);
// 	// spin_unlock(&config->ciphertext_pages_cache_lock);
// 	printk(KERN_WARNING "%s: Inserted ciphertext cache at gpa 0x%llx\n",
// 	       __func__, gpa);

// 	return 0;

// error_out:
// 	if (entry->ct_cache)
// 		kfree(entry->ct_cache);
// 	if (entry->null_bitmap)
// 		kfree(entry->null_bitmap);
// 	if (entry)
// 		kfree(entry);
// 	return ret;
// }
// EXPORT_SYMBOL(insert_page_ciphertext_cache_at_gpa);

// int update_page_ciphertext_cache_at_gpa(sev_step_config_t *config, uint64_t gpa,
// 					uint8_t *ciphertext,
// 					uint8_t *null_bitmap)
// {
// 	struct gpa_to_ciphertext_cache *entry;
// 	// spin_lock(&config->ciphertext_pages_cache_lock);
// 	hash_for_each_possible(config->ciphertext_pages_cache, entry, hash_node,
// 			       gpa) {
// 		if (entry->gpa == gpa)
// 		{
// 			memcpy(entry->ct_cache, ciphertext, PAGE_SIZE);
// 			memcpy(entry->null_bitmap, null_bitmap, PAGE_SIZE / 16);
// 			printk(KERN_WARNING
// 			       "%s: Updated ciphertext cache at gpa 0x%llx\n",
// 			       __func__, gpa);
// 			return 0;
// 		}
// 	}
// 	// spin_unlock(&config->ciphertext_pages_cache_lock);
// 	return -1;
// }
// EXPORT_SYMBOL(update_page_ciphertext_cache_at_gpa);

// int remove_page_ciphertext_cache_at_gpa(sev_step_config_t *config,
// 						uint64_t gpa)
// {
// 	struct gpa_to_ciphertext_cache *entry;
// 	// spin_lock(&config->ciphertext_pages_cache_lock);
// 	hash_for_each_possible(config->ciphertext_pages_cache, entry, hash_node,
// 			       gpa) {
// 		if (entry->gpa == gpa)
// 		{
// 			hash_del(&entry->hash_node);
// 			kfree(entry->ct_cache);
// 			kfree(entry->null_bitmap);
// 			kfree(entry);
// 			printk(KERN_WARNING
// 			       "%s: Removed ciphertext cache at gpa 0x%llx\n",
// 			       __func__, gpa);
// 			return 0;
// 		}
// 	}
// 	// spin_unlock(&config->ciphertext_pages_cache_lock);
// 	return -1;
// }
// EXPORT_SYMBOL(remove_page_ciphertext_cache_at_gpa);

// int destroy_page_ciphertext_cache(sev_step_config_t *config)
// {
// 	struct hlist_node *tmp;
// 	struct gpa_to_ciphertext_cache *entry;
// 	int bkt;

// 	// For debug purpose, iterate over the hash table and print the
// 	// ciphertext cache
// 	// spin_lock(&config->ciphertext_pages_cache_lock);
// 	hash_for_each_possible(config->ciphertext_pages_cache, entry, hash_node,
// 			       0) {
// 		printk(KERN_WARNING
// 		       "%s: Ciphertext cache: gpa 0x%llx, ct_cache %p, null_bitmap %p\n",
// 		       __func__, entry->gpa, entry->ct_cache,
// 		       entry->null_bitmap);
// 	}
// 	printk(KERN_WARNING "%s: Destroying page ciphertext cache\n", __func__);
// 	hash_for_each_safe(config->ciphertext_pages_cache, bkt, tmp, entry,
// 			   hash_node) {
// 		uint64_t gpa = entry->gpa;
// 		hash_del(&entry->hash_node);
// 		kfree(entry->ct_cache);
// 		kfree(entry->null_bitmap);
// 		kfree(entry);
// 		printk(KERN_WARNING
// 		       "%s: Removed ciphertext cache at gpa 0x%llx\n",
// 		       __func__, gpa);
// 	}
// 	// spin_unlock(&config->ciphertext_pages_cache_lock);
// 	hash_init(config->ciphertext_pages_cache); // It might be unnecessary
// 	return 0;
// }
// EXPORT_SYMBOL(destroy_page_ciphertext_cache);

#ifdef ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT
bool is_exist_page_null_cipher_repr(sev_step_config_t *config)
{
	// Find if hash_table pages_null_cipher_repr is empty
	return !hash_empty(config->pages_null_cipher_repr);
}
EXPORT_SYMBOL(is_exist_page_null_cipher_repr);

struct spa_to_null_cipher_repr *
get_a_page_null_cipher_repre(sev_step_config_t *config)
{
	// Just return the first element in the hash_table pages_null_cipher_repr
	struct spa_to_null_cipher_repr *entry;
	hash_for_each_possible(config->pages_null_cipher_repr, entry, hash_node,
			       0) {
		return entry;
	}
	return NULL;
}
EXPORT_SYMBOL(get_a_page_null_cipher_repre);

struct spa_to_null_cipher_repr *
find_page_null_cipher_repr_at_spa(sev_step_config_t *config, uint64_t spa)
{
	struct spa_to_null_cipher_repr *entry;
	hash_for_each_possible(config->pages_null_cipher_repr, entry, hash_node,
			       spa) {
		if (entry->spa == spa)
		{
			return entry;
		}
	}
	return NULL;
}
EXPORT_SYMBOL(find_page_null_cipher_repr_at_spa);

int insert_page_null_cipher_repr(sev_step_config_t *config, u64 spa,
				 uint8_t *null_cipher_repr)
{
	int ret = 0;
	struct spa_to_null_cipher_repr *entry;
	entry = kmalloc(sizeof(struct spa_to_null_cipher_repr), GFP_KERNEL);
	if (entry == NULL)
	{
		ret = -ENOMEM;
		printk(KERN_ERR
		       "%s: Failed to allocate memory for null cipher repr\n",
		       __func__);
		goto error_out;
	}
	entry->spa = spa;
	entry->null_cipher_repr = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (entry->null_cipher_repr == NULL)
	{
		ret = -ENOMEM;
		printk(KERN_ERR
		       "%s: Failed to allocate memory for null cipher repr\n",
		       __func__);
		goto error_out;
	}
	memcpy(entry->null_cipher_repr, null_cipher_repr, PAGE_SIZE);
	INIT_HLIST_NODE(&entry->hash_node);
	hash_add(config->pages_null_cipher_repr, &entry->hash_node, spa);
	printk(KERN_WARNING "%s: Inserted null cipher repr at spa 0x%llx\n",
	       __func__, spa);

	return 0;

error_out:
	if (entry->null_cipher_repr)
		kfree(entry->null_cipher_repr);
	if (entry)
		kfree(entry);
	return ret;
}
EXPORT_SYMBOL(insert_page_null_cipher_repr);

int remove_page_null_cipher_repr(sev_step_config_t *config, uint64_t spa)
{
	struct spa_to_null_cipher_repr *entry;
	hash_for_each_possible(config->pages_null_cipher_repr, entry, hash_node,
			       spa) {
		if (entry->spa == spa)
		{
			hash_del(&entry->hash_node);
			kfree(entry->null_cipher_repr);
			kfree(entry);
			return 0;
		}
	}
	return -1;
}
EXPORT_SYMBOL(remove_page_null_cipher_repr);

int destroy_page_null_cipher_repr(sev_step_config_t *config)
{
	struct hlist_node *tmp;
	struct spa_to_null_cipher_repr *entry;
	int bkt;
	printk(KERN_WARNING "%s: Destroying page null cipher repr\n", __func__);
	hash_for_each_safe(config->pages_null_cipher_repr, bkt, tmp, entry,
			   hash_node) {
		hash_del(&entry->hash_node);
		kfree(entry->null_cipher_repr);
		kfree(entry);
	}
	hash_init(config->pages_null_cipher_repr); // It might be unnecessary
	printk(KERN_WARNING "%s: Destroyed page null cipher repr\n", __func__);
	return 0;
}
EXPORT_SYMBOL(destroy_page_null_cipher_repr);

bool is_page_in_null_page_list(sev_step_config_t *config, uint64_t gpa)
{
	struct null_page_list *entry;
	hash_for_each_possible(config->null_page_list, entry, hash_node, gpa) {
		if (entry->gpa == gpa)
		{
			return true;
		}
	}
	return false;
}
EXPORT_SYMBOL(is_page_in_null_page_list);

int insert_page_to_null_page_list(sev_step_config_t *config, uint64_t gpa)
{
	int ret = 0;
	struct null_page_list *entry;
	entry = kmalloc(sizeof(struct null_page_list), GFP_KERNEL);
	if (entry == NULL)
	{
		ret = -ENOMEM;
		printk(KERN_ERR
		       "%s: Failed to allocate memory for null page list\n",
		       __func__);
		goto error_out;
	}
	entry->gpa = gpa;
	INIT_HLIST_NODE(&entry->hash_node);
	hash_add(config->null_page_list, &entry->hash_node, gpa);
	printk(KERN_WARNING "%s: Inserted null page at gpa 0x%llx\n", __func__,
	       gpa);

	return 0;
error_out:
	if (entry)
		kfree(entry);
	return ret;
}
EXPORT_SYMBOL(insert_page_to_null_page_list);

int remove_page_from_null_page_list(sev_step_config_t *config, uint64_t gpa)
{
	struct null_page_list *entry;
	hash_for_each_possible(config->null_page_list, entry, hash_node, gpa) {
		if (entry->gpa == gpa)
		{
			hash_del(&entry->hash_node);
			kfree(entry);
			printk(KERN_WARNING "%s: Removed null page at gpa 0x%llx\n",
			       __func__, gpa);
			return 0;
		}
	}
	return -1;
}
EXPORT_SYMBOL(remove_page_from_null_page_list);

int destroy_null_page_list(sev_step_config_t *config)
{
	struct hlist_node *tmp;
	struct null_page_list *entry;
	int bkt;
	printk(KERN_WARNING "%s: Destroying null page list\n", __func__);
	hash_for_each_safe(config->null_page_list, bkt, tmp, entry, hash_node) {
		hash_del(&entry->hash_node);
		kfree(entry);
	}
	hash_init(config->null_page_list); // It might be unnecessary
	printk(KERN_WARNING "%s: Destroyed null page list\n", __func__);
	return 0;
}
EXPORT_SYMBOL(destroy_null_page_list);
#endif // ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT

bool is_pfn_sev_private(struct kvm *kvm, u64 pfn)
{
	struct kvm_sev_info *sev;
	int asid;

	sev = &to_kvm_svm(kvm)->sev_info;

	// dump_rmpentry(pfn);

	asid = get_rmpentry_asid(pfn);

	// printk("%s: asid = %d, sev->asid = %d\n", __func__, asid, sev->asid);

	return asid == sev->asid;
}
EXPORT_SYMBOL(is_pfn_sev_private);

// int get_ciphertext_at_gpa(struct kvm *kvm, u64 gpa, u64 target_gpa,
// 			  u8 *out_page_content)
// {
// 	// Swap the page first and copy the content to new_page_content
// 	// and then swap back
// 	int ret = 0, error = 0;
// 	struct page *tmp_page = NULL;
// 	void *tmp_page_addr = NULL;
// 	u64 gfn1, gfn2;
// 	u64 hva1, hva2;
// 	u64 pfn1, pfn2;
// 	struct kvm_sev_info *sev = &to_kvm_svm(kvm)->sev_info;

// 	struct kvm_vcpu *vcpu = kvm_get_vcpu(kvm, 0);

// 	gfn1 = target_gpa >> PAGE_SHIFT;
// 	gfn2 = gpa >> PAGE_SHIFT;
// 	pfn1 = gfn_to_pfn(kvm, gfn1); // gfn1, target_gpa
// 	pfn2 = gfn_to_pfn(kvm, gfn2); // gfn2, gpa
// 	hva1 = gfn_to_hva(kvm, gfn1);
// 	hva2 = gfn_to_hva(kvm, gfn2);

// 	if (!pfn_valid(pfn1) || !pfn_valid(pfn2)) {
// 		printk(KERN_ERR "=%s invalid pfn1 or pfn2\n", __func__);
// 		return -EINVAL;
// 	}

// 	tmp_page = alloc_page(GFP_KERNEL);
// 	if (!tmp_page) {
// 		printk(KERN_ERR "=%s failed to allocate tmp_page\n", __func__);
// 		return -ENOMEM;
// 	}

// 	tmp_page_addr = page_address(tmp_page);
// 	if (!tmp_page_addr) {
// 		printk(KERN_ERR "=%s failed to get page address\n", __func__);
// 		ret = -ENOMEM;
// 		goto out;
// 	}

// 	// Swap the page
// 	ret = snp_guest_page_move(__pa(sev->snp_context) >> PAGE_SHIFT, pfn1,
// 				  __pa(tmp_page_addr) >> PAGE_SHIFT, &error,
// 				  /*src_gpa*/ target_gpa, to_svm(vcpu)->asid);
// 	if (ret) {
// 		printk(KERN_ERR
// 		       "%s: snp_guest_page_move failed with error %d"
// 		       " when moving page from gpa 0x%llx to tmp_page\n",
// 		       __func__, error, gpa);
// 		goto out;
// 	}

// 	ret = snp_guest_page_move(__pa(sev->snp_context) >> PAGE_SHIFT, pfn2,
// 				  pfn1, &error, /*src_gpa*/ gpa,
// 				  to_svm(vcpu)->asid);
// 	if (ret) {
// 		printk(KERN_ERR
// 		       "%s: snp_guest_page_move failed with error %d"
// 		       " when moving page from gpa 0x%llx to gpa 0x%llx\n",
// 		       __func__, error, target_gpa, gpa);
// 		goto out;
// 	}

// 	// Copy the content to out_page_content
// 	clflush_cache_range_user((void *)hva1, PAGE_SIZE);
// 	ret = copy_from_user(out_page_content, (void *)hva1, PAGE_SIZE);
// 	// clflush_cache_range_user((void *)hva1, PAGE_SIZE);
// 	if (ret) {
// 		printk(KERN_ERR "=%s failed to copy_from_user\n", __func__);
// 		ret = -EFAULT;
// 		goto out;
// 	}

// 	// Swap it back
// 	ret = snp_guest_page_move(__pa(sev->snp_context) >> PAGE_SHIFT, pfn1,
// 				  pfn2, &error, /*src_gpa*/ gpa,
// 				  to_svm(vcpu)->asid);
// 	if (ret) {
// 		printk(KERN_ERR
// 		       "%s: snp_guest_page_move failed with error %d"
// 		       " when moving page from gpa 0x%llx to tmp_page\n",
// 		       __func__, error, gpa);
// 		goto out;
// 	}

// 	ret = snp_guest_page_move(__pa(sev->snp_context) >> PAGE_SHIFT,
// 				  __pa(tmp_page_addr) >> PAGE_SHIFT, pfn1,
// 				  &error, /*src_gpa*/ target_gpa,
// 				  to_svm(vcpu)->asid);

// 	if (ret) {
// 		printk(KERN_ERR
// 		       "%s: snp_guest_page_move failed with error %d"
// 		       " when moving page from gpa 0x%llx to gpa 0x%llx\n",
// 		       __func__, error, target_gpa, gpa);
// 		goto out;
// 	}

// out:
// 	if (tmp_page)
// 		snp_free_guest_invalid_page(tmp_page);

// 	return ret;
// }
// EXPORT_SYMBOL(get_ciphertext_at_gpa);

// int get_gfn_ciphertext_at_gfn_with_timing(struct kvm *kvm, u64 gfn, u64 target_gfn,
// 				      u8 *out_page_content,
// 				      s64 *ptr_move_time_in_ns,
// 				      s64 *ptr_copy_time_in_ns,
// 				      s64 *ptr_other_time_in_ns,
// 				      u32 *ptr_nr_move_times)
// {
// 	// Swap the page first and copy the content to new_page_content
// 	// and then swap back
// 	int ret = 0, error = 0;
// 	struct page *tmp_page = NULL;
// 	void *tmp_page_addr = NULL;
// 	// u64 gfn1, gfn2;
// 	u64 hva1, hva2;
// 	u64 pfn1, pfn2;
// 	struct kvm_sev_info *sev = &to_kvm_svm(kvm)->sev_info;

// 	s64 move_time_in_ns = 0;
// 	s64 copy_time_in_ns = 0;
// 	s64 other_time_in_ns = 0;
// 	u32 nr_move_times = 0;

// 	ktime_t start, end;

// 	struct kvm_vcpu *vcpu = kvm_get_vcpu(kvm, 0);

// 	start = ktime_get();
// 	gfn1 = target_gpa >> PAGE_SHIFT;
// 	gfn2 = gpa >> PAGE_SHIFT;
// 	pfn1 = gfn_to_pfn(kvm, gfn1); // gfn1, target_gpa
// 	pfn2 = gfn_to_pfn(kvm, gfn2); // gfn2, gpa
// 	hva1 = gfn_to_hva(kvm, gfn1);
// 	hva2 = gfn_to_hva(kvm, gfn2);

// 	if (!pfn_valid(pfn1) || !pfn_valid(pfn2)) {
// 		printk(KERN_ERR "=%s invalid pfn1 or pfn2\n", __func__);
// 		return -EINVAL;
// 	}

// 	tmp_page = alloc_page(GFP_KERNEL);
// 	if (!tmp_page) {
// 		printk(KERN_ERR "=%s failed to allocate tmp_page\n", __func__);
// 		return -ENOMEM;
// 	}

// 	tmp_page_addr = page_address(tmp_page);
// 	if (!tmp_page_addr) {
// 		printk(KERN_ERR "=%s failed to get page address\n", __func__);
// 		ret = -ENOMEM;
// 		goto out;
// 	}

// 	end = ktime_get();

// 	other_time_in_ns += ktime_to_ns(ktime_sub(end, start));

// 	start = ktime_get();

// 	// Swap the page
// 	ret = snp_guest_page_move(__pa(sev->snp_context) >> PAGE_SHIFT, pfn1,
// 				  __pa(tmp_page_addr) >> PAGE_SHIFT, &error,
// 				  /*src_gpa*/ target_gpa, to_svm(vcpu)->asid);
// 	if (ret) {
// 		printk(KERN_ERR
// 		       "%s: snp_guest_page_move failed with error %d"
// 		       " when moving page from gpa 0x%llx to tmp_page\n",
// 		       __func__, error, gpa);
// 		goto out;
// 	}

// 	ret = snp_guest_page_move(__pa(sev->snp_context) >> PAGE_SHIFT, pfn2,
// 				  pfn1, &error, /*src_gpa*/ gpa,
// 				  to_svm(vcpu)->asid);
// 	if (ret) {
// 		printk(KERN_ERR
// 		       "%s: snp_guest_page_move failed with error %d"
// 		       " when moving page from gpa 0x%llx to gpa 0x%llx\n",
// 		       __func__, error, target_gpa, gpa);
// 		goto out;
// 	}

// 	end = ktime_get();

// 	move_time_in_ns += ktime_to_ns(ktime_sub(end, start));
// 	nr_move_times += 2;

// 	start = ktime_get();

// 	// Copy the content to out_page_content
// 	clflush_cache_range_user((void *)hva1, PAGE_SIZE);
// 	ret = copy_from_user(out_page_content, (void *)hva1, PAGE_SIZE);
// 	// clflush_cache_range_user((void *)hva1, PAGE_SIZE);
// 	if (ret) {
// 		printk(KERN_ERR "=%s failed to copy_from_user\n", __func__);
// 		ret = -EFAULT;
// 		goto out;
// 	}

// 	end = ktime_get();

// 	copy_time_in_ns += ktime_to_ns(ktime_sub(end, start));

// 	start = ktime_get();
// 	// Swap it back
// 	ret = snp_guest_page_move(__pa(sev->snp_context) >> PAGE_SHIFT, pfn1,
// 				  pfn2, &error, /*src_gpa*/ gpa,
// 				  to_svm(vcpu)->asid);
// 	if (ret) {
// 		printk(KERN_ERR
// 		       "%s: snp_guest_page_move failed with error %d"
// 		       " when moving page from gpa 0x%llx to tmp_page\n",
// 		       __func__, error, gpa);
// 		goto out;
// 	}

// 	ret = snp_guest_page_move(__pa(sev->snp_context) >> PAGE_SHIFT,
// 				  __pa(tmp_page_addr) >> PAGE_SHIFT, pfn1,
// 				  &error, /*src_gpa*/ target_gpa,
// 				  to_svm(vcpu)->asid);

// 	if (ret) {
// 		printk(KERN_ERR
// 		       "%s: snp_guest_page_move failed with error %d"
// 		       " when moving page from gpa 0x%llx to gpa 0x%llx\n",
// 		       __func__, error, target_gpa, gpa);
// 		goto out;
// 	}

// 	end = ktime_get();
// 	move_time_in_ns += ktime_to_ns(ktime_sub(end, start));
// 	nr_move_times += 2;

// out:
// 	if (tmp_page)
// 		snp_free_guest_invalid_page(tmp_page);

// 	// Assign timing results
// 	if (ptr_move_time_in_ns)
// 		*ptr_move_time_in_ns = move_time_in_ns;
// 	if (ptr_copy_time_in_ns)
// 		*ptr_copy_time_in_ns = copy_time_in_ns;
// 	if (ptr_other_time_in_ns)
// 		*ptr_other_time_in_ns = other_time_in_ns;
// 	if (ptr_nr_move_times)
// 		*ptr_nr_move_times = nr_move_times;

// 	return ret;
// }
// EXPORT_SYMBOL(get_gpa_ciphertext_at_gpa_with_timing);

/* This function assumes that target_pfn has already been allocated
 * and we have already obtained its translation.
 * It also assumes that the page at gfn_pfn is already encrypted and
 * we have already obtained its translation.
 */
int get_gfn_ciphertext_at_pfn_safe(struct kvm *kvm, u64 gfn, u64 gfn_pfn,
				   void *target_hva, u64 target_pfn,
				   u8 *out_page_content,
				   bool is_kernel_target)
{
	int ret = 0;
	int error = 0;

	struct kvm_sev_info *sev = &to_kvm_svm(kvm)->sev_info;
	u64 snp_context_pfn;
	u64 gpa = gfn << PAGE_SHIFT;
	struct kvm_memory_slot *slot = gfn_to_memslot(kvm, gfn);
	int idx;
	int asid = sev->asid;

	if (asid == 0) {
		printk(KERN_ERR "=%s asid is 0\n", __func__);
		return -EINVAL;
	}

	if (sev == NULL) {
		printk(KERN_ERR "=%s sev is NULL\n", __func__);
		return -EINVAL;
	}

	if (sev->snp_context == NULL) {
		printk(KERN_ERR "=%s sev->snp_context is NULL\n", __func__);
		return -EINVAL;
	}

	if (!pfn_valid(gfn_pfn)) {
		printk(KERN_ERR "=%s invalid gfn=0x%llx gfn_pfn=0x%llx\n",
		       __func__, gfn, gfn_pfn);
		return -EINVAL;
	}

	if (!pfn_valid(target_pfn)) {
		printk(KERN_ERR "=%s invalid target_pfn\n", __func__);
		return -EINVAL;
	}

	snp_context_pfn = __pa(sev->snp_context) >> PAGE_SHIFT;

	if (!pfn_valid(snp_context_pfn)) {
		printk(KERN_ERR "=%s invalid snp_context_pfn\n", __func__);
		return -EINVAL;
	}

	if (!slot) {
		printk(KERN_ERR "=%s invalid slot for gfn -1x%llx\n", __func__, gfn);
		return -EINVAL;
	}

	if (!is_pfn_sev_private(kvm, gfn_pfn)) {
		printk(KERN_ERR "=%s gfn_pfn 0x%llx is not private\n", __func__,
		       gfn_pfn);
		return -EINVAL;
	}

	idx = srcu_read_lock(&kvm->srcu);
	write_lock(&kvm->mmu_lock);
	kvm_slot_page_track_add_page(kvm, slot, gfn, KVM_PAGE_TRACK_ACCESS);

	// Just move the page from gfn_pfn to target_pfn and then move it back
	ret = snp_guest_page_move(snp_context_pfn, gfn_pfn, target_pfn, &error,
				  gpa, asid);

	if (ret) {
		printk(KERN_ERR
		       "%s: snp_guest_page_move failed with error %d"
		       " when moving page from gfn_pfn 0x%llx to target_pfn 0x%llx\n",
		       __func__, error, gfn_pfn, target_pfn);
		goto out;
	}

	// printk(KERN_WARNING
	//        "%s: Moved page from gfn_pfn 0x%llx to target_pfn 0x%llx\n",
	//        __func__, gfn_pfn, target_pfn);

	// printk(KERN_WARNING "%s: out_page_content = 0x%llx\n", __func__,
	//        (u64)out_page_content);

	// Copy the content to out_page_content
	if (is_kernel_target)
	{
		clflush_cache_range((void *)target_hva, PAGE_SIZE);
		memcpy(out_page_content, (void *)target_hva, PAGE_SIZE);
	} else {
		clflush_cache_range_user((void *)target_hva, PAGE_SIZE);
		ret = copy_from_user(out_page_content, (void *)target_hva, PAGE_SIZE);
		if (ret) {
			printk(KERN_ERR "=%s failed to copy_from_user\n", __func__);
			memset(out_page_content, 0xfa, PAGE_SIZE);
		}
	}

	// Move it back
	ret = snp_guest_page_move(snp_context_pfn, target_pfn, gfn_pfn, &error,
				  gpa, asid);
	if (ret) {
		printk(KERN_ERR
		       "%s: snp_guest_page_move failed with error %d"
		       " when moving page from target_pfn 0x%llx to gfn_pfn 0x%llx\n",
		       __func__, error, target_pfn, gfn_pfn);
		goto out;
	}

out:
	write_unlock(&kvm->mmu_lock);
	srcu_read_unlock(&kvm->srcu, idx);

	// idx = srcu_read_lock(&kvm->srcu);
	// write_lock(&kvm->mmu_lock);
	// kvm_slot_page_track_remove_page(kvm, slot, gfn, KVM_PAGE_TRACK_ACCESS);
	// write_unlock(&kvm->mmu_lock);
	// srcu_read_unlock(&kvm->srcu, idx);

	return ret;
}
EXPORT_SYMBOL(get_gfn_ciphertext_at_pfn_safe);

/* This function assumes that target_pfn has already been allocated
 * and we have already obtained its translation.
 * It also assumes that the page at gfn_pfn is already encrypted and
 * we have already obtained its translation.
 */
int get_gfn_ciphertext_at_pfn(struct kvm *kvm, u64 gfn, u64 gfn_pfn,
			      void *target_hva, u64 target_pfn,
			      u8 *out_page_content, bool is_kernel_target)
{
	int ret = 0;
	int error = 0;
	u64 snp_context_pfn;
	struct kvm_sev_info *sev = &to_kvm_svm(kvm)->sev_info;
	u64 gpa = gfn << PAGE_SHIFT;
	int asid = sev->asid;

	if (asid == 0) {
		printk(KERN_ERR "=%s asid is 0\n", __func__);
		return -EINVAL;
	}

	snp_context_pfn = __pa(sev->snp_context) >> PAGE_SHIFT;
	if (!pfn_valid(snp_context_pfn)) {
		printk(KERN_ERR "=%s invalid snp_context_pfn\n", __func__);
		return -EINVAL;
	}

	if (!pfn_valid(gfn_pfn)) {
		printk(KERN_ERR "=%s invalid gfn_pfn\n", __func__);
		return -EINVAL;
	}

	// Just move the page from gfn_pfn to target_pfn and then move it back
	ret = snp_guest_page_move(snp_context_pfn, gfn_pfn, target_pfn, &error,
				  gpa, asid);

	if (ret) {
		printk(KERN_ERR
		       "%s: snp_guest_page_move failed with error %d"
		       " when moving page from gfn_pfn 0x%llx to target_pfn 0x%llx\n",
		       __func__, error, gfn_pfn, target_pfn);
		goto out;
	}

	// printk(KERN_WARNING
	//        "%s: Moved page from gfn_pfn 0x%llx to target_pfn 0x%llx\n",
	//        __func__, gfn_pfn, target_pfn);

	// printk(KERN_WARNING "%s: out_page_content = 0x%llx\n", __func__,
	//        (u64)out_page_content);


	// Copy the content to out_page_content
	if (is_kernel_target)
	{
		clflush_cache_range((void *)target_hva, PAGE_SIZE);
		memcpy(out_page_content, (void *)target_hva, PAGE_SIZE);
	} else {
		clflush_cache_range_user((void *)target_hva, PAGE_SIZE);
		ret = copy_from_user(out_page_content, (void *)target_hva,
				     PAGE_SIZE); // FIXME: Is it copy_to_user?
		if (ret) {
			printk(KERN_ERR "=%s failed to copy_from_user\n", __func__);
			memset(out_page_content, 0xfa, PAGE_SIZE);
		}
	}

	// Move it back
	ret = snp_guest_page_move(snp_context_pfn, target_pfn, gfn_pfn, &error,
				  gpa, asid);
	if (ret) {
		printk(KERN_ERR
		       "%s: snp_guest_page_move failed with error %d"
		       " when moving page from target_pfn 0x%llx to gfn_pfn 0x%llx\n",
		       __func__, error, target_pfn, gfn_pfn);
		goto out;
	}

out:
	return ret;
}
EXPORT_SYMBOL(get_gfn_ciphertext_at_pfn);

int get_gfn_plaintext_by_decrypt_in_debug_mode(struct kvm *kvm, u64 gfn_pfn,
					       u8 *out_page_content)
{
	int ret = 0;
	int error;
	struct kvm_sev_info *sev;
	struct page *save_page = NULL;
	u8 *save_page_addr = NULL;

	sev = &to_kvm_svm(kvm)->sev_info;

	if (sev == NULL) {
		printk(KERN_ERR "=%s sev is NULL\n", __func__);
		return -EINVAL;
	}

	if (sev->snp_context == NULL) {
		printk(KERN_ERR "=%s sev->snp_context is NULL\n", __func__);
		return -EINVAL;
	}

	if (!pfn_valid(gfn_pfn)) {
		printk(KERN_ERR "=%s invalid gfn_pfn\n", __func__);
		return -EINVAL;
	}

	if (!is_pfn_sev_private(kvm, gfn_pfn)) {
		printk(KERN_ERR "=%s gfn_pfn 0x%llx is not private\n", __func__,
		       gfn_pfn);
		return -EINVAL;
	}

	save_page = alloc_page(GFP_KERNEL);
	if (!save_page) {
		printk(KERN_ERR "=%s failed to allocate save_page\n", __func__);
		return -ENOMEM;
	}
	save_page_addr = page_address(save_page);

	ret = snp_guest_dbg_decrypt_page(__pa(sev->snp_context) >> PAGE_SHIFT,
					 gfn_pfn, __pa(save_page_addr) >> PAGE_SHIFT,
					 &error);
	if (ret) {
		printk("KVM_GET_GFN_PLAINTEXTS_IN_DEBUG_MODE: snp_guest_dbg_decrypt_page failed\n");
		memset(out_page_content, 0xfa, PAGE_SIZE);
		__free_page(save_page);
		return -EFAULT;
	}

	memcpy(out_page_content, save_page_addr, PAGE_SIZE);

	__free_page(virt_to_page(save_page_addr));

	return ret;
}
EXPORT_SYMBOL(get_gfn_plaintext_by_decrypt_in_debug_mode);

int get_kvm_sev_snp_context_addr(struct kvm *kvm, u64 *snp_context_va, u64 *snp_context_pa)
{
	struct kvm_sev_info *sev;
	if (!kvm || snp_context_va == NULL || snp_context_pa == NULL) {
		printk(KERN_ERR "%s: Invalid arguments\n", __func__);
		return -EINVAL;
	}
	sev = &to_kvm_svm(kvm)->sev_info;
	*snp_context_va = (u64)sev->snp_context;
	*snp_context_pa = __pa(sev->snp_context);
	return 0;
}
EXPORT_SYMBOL(get_kvm_sev_snp_context_addr);

int get_kvm_sev_asid(struct kvm *kvm, int *asid)
{
	struct kvm_sev_info *sev;
	if (!kvm || asid == NULL) {
		printk(KERN_ERR "%s: Invalid arguments\n", __func__);
		return -EINVAL;
	}
	sev = &to_kvm_svm(kvm)->sev_info;
	*asid = sev->asid;
	return 0;
}
EXPORT_SYMBOL(get_kvm_sev_asid);

#ifdef ENABLE_MONITOR_UNTRACKED_PAGES
int insert_page_to_untracked_pages_list(sev_step_config_t *config, uint64_t gpa,
					u8 *content)
{
	// Get struct list_head untracked_pages_list first
	struct page_content_list *entry;
	entry = kmalloc(sizeof(struct page_content_list), GFP_KERNEL);

	if (entry == NULL)
	{
		printk(KERN_ERR
		       "%s: Failed to allocate memory for page content list\n",
		       __func__);
		return -ENOMEM;
	}

	entry->gpa = gpa;
	entry->content = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (entry->content == NULL)
	{
		printk(KERN_ERR
		       "%s: Failed to allocate memory for page content\n",
		       __func__);
		kfree(entry);
		return -ENOMEM;
	}

	memcpy(entry->content, content, PAGE_SIZE);

	// Add this entry node to the list
	INIT_LIST_HEAD(&entry->list);
	list_add(&entry->list, &config->untracked_pages_list);

	return 0;
}
EXPORT_SYMBOL(insert_page_to_untracked_pages_list);

int remove_page_from_untracked_pages_list(sev_step_config_t *config, uint64_t gpa)
{

	struct page_content_list *entry;
	list_for_each_entry(entry, &config->untracked_pages_list, list)
	{
		if (entry->gpa == gpa)
		{
			printk(KERN_WARNING
			       "%s: Removed untracked page at gpa 0x%llx\n",
			       __func__, gpa);
			list_del(&entry->list);
			kfree(entry->content);
			kfree(entry);
			return 0;
		}
	}
	return -1;

}
EXPORT_SYMBOL(remove_page_from_untracked_pages_list);

int destroy_untracked_pages_list(sev_step_config_t *config)
{
	struct page_content_list *entry, *tmp;
	list_for_each_entry_safe(entry, tmp, &config->untracked_pages_list, list)
	{
		list_del(&entry->list);
		kfree(entry->content);
		kfree(entry);
	}
	return 0;
}
EXPORT_SYMBOL(destroy_untracked_pages_list);
#endif // ENABLE_MONITOR_UNTRACKED_PAGES

int create_target_page_info(sev_step_config_t *config, u64 target_page_hva,
		       u64 target_page_pfn, u8 *target_page_null_ciphertexts, bool print_ciphertexts)
{
	size_t i;
	if (config->target_page_null_ciphertexts != NULL) {
		kfree(config->target_page_null_ciphertexts);
		config->target_page_null_ciphertexts = NULL;
		config->target_page_hva = 0;
		config->target_page_pfn = (u64)-1;
	}
	// Allocate memory for null ciphertexts
	config->target_page_null_ciphertexts = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if (config->target_page_null_ciphertexts == NULL) {
		printk(KERN_ERR
		       "%s: Failed to allocate memory for target_page_null_ciphertexts\n",
		       __func__);
		return -ENOMEM;
	}
	config->target_page_hva = target_page_hva;
	config->target_page_pfn = target_page_pfn;
	// Copy the null ciphertexts to the allocated memory
	memcpy(config->target_page_null_ciphertexts,
	       target_page_null_ciphertexts, PAGE_SIZE);
	printk(KERN_WARNING "%s: Created target page at hva 0x%llx\n", __func__,
	       target_page_hva);
	printk(KERN_WARNING "%s: target_page_pfn = 0x%llx\n", __func__,
	       target_page_pfn);
	// Print the current target_page_null_ciphertexts
	printk(KERN_WARNING "%s: target_page_null_ciphertexts = 0x%llx\n",
	       __func__, (u64)config->target_page_null_ciphertexts);

	if (print_ciphertexts) {
		for (i = 0; i < PAGE_SIZE; i += 16) {
			printk(KERN_WARNING "[%lx] %016llx %016llx\n", i,
			       *(u64 *)(config->target_page_null_ciphertexts +
					i),
			       *(u64 *)(config->target_page_null_ciphertexts +
					i + 8));
		}
	}
	return 0;
}
EXPORT_SYMBOL(create_target_page_info);

// Assume the lock is already held and config is not NULL
int destroy_target_page_info(sev_step_config_t *config)
{
	if (config->target_page_hva == 0 ||
	    config->target_page_pfn == (u64)-1 ||
	    config->target_page_null_ciphertexts == NULL) {
		printk(KERN_ERR
		       "%s: target_page_hva is NULL or target_page_pfn is invalid\n",
		       __func__);
		return -EINVAL;
	}
	kfree(config->target_page_null_ciphertexts);
	config->target_page_hva = 0;
	config->target_page_pfn = (u64)-1;
	config->target_page_null_ciphertexts = NULL;
	printk(KERN_WARNING "%s: Destroyed target page\n", __func__);

	return 0;
}
EXPORT_SYMBOL(destroy_target_page_info);

struct u64_entry {
	u64 key;
	struct hlist_node node;
};

// Declare a hash table for storing the deduplicated elements
DEFINE_HASHTABLE(deduplication_hash_table, 16);


int get_all_private_gfn(struct kvm *kvm, uint64_t **array, size_t *size, size_t max_nr_gfns, bool is_deduplication)
{
	struct kvm_memslots *slots;
	struct kvm_memory_slot *slot;
	int srcu_lock_retval, bkt, i;
	uint64_t *result = NULL;
	size_t result_capacity = max_nr_gfns;
	size_t result_size = 0;
	bool is_full = false;
	size_t nr_duplicated_gfns = 0;

	if (is_deduplication) {
		// Initialize the hash table for deduplication
		hash_init(deduplication_hash_table);
	}

	printk(KERN_WARNING "%s: max_nr_gfns = %zu, kvm = %p, array = %p, size = %p\n",
	       __func__, max_nr_gfns, kvm, array, size);

	if (kvm == NULL || array == NULL || size == NULL) {
		printk(KERN_ERR "%s: Invalid arguments\n", __func__);
		return -EINVAL;
	}

	result = kvmalloc(result_capacity * sizeof(uint64_t), GFP_KERNEL);

	printk(KERN_WARNING "%s: result = %p\n", __func__, result);

	if (result == NULL) {
		printk(KERN_ERR "%s: Failed to allocate memory for result\n",
		       __func__);
		return -ENOMEM;
	}

	for (i = 0; i < KVM_ADDRESS_SPACE_NUM; i++) {
		u64 gfn, gfn_max;
		slots = __kvm_memslots(kvm, i);
		kvm_for_each_memslot(slot, bkt, slots) {
			gfn_max = slot->base_gfn + slot->npages;
			srcu_lock_retval = srcu_read_lock(&kvm->srcu);
			write_lock(&kvm->mmu_lock);
			for (gfn = 0; gfn < gfn_max; gfn++) {
					// slot = kvm_vcpu_gfn_to_memslot(vcpu, iterator);
					slot = gfn_to_memslot(kvm, gfn);
					if (slot != NULL) {
						u64 pfn = gfn_to_pfn(kvm, gfn);
						if (pfn_valid(pfn) && is_pfn_sev_private(kvm, pfn)) {
							// Check there is not in the result array yet
							if (is_deduplication) {
								// Check if the gfn is already in the hash table
								struct u64_entry *entry;
								bool is_found_in_hash = false;
								hash_for_each_possible(deduplication_hash_table, entry, node, gfn) {
									if (entry->key == gfn) {
										// Found, so skip it
										nr_duplicated_gfns++;
										is_found_in_hash = true;
										goto hash_check_out;
									}
								}
							hash_check_out:
								if (is_found_in_hash) {
									continue;
								}
								// Not found, so add it to the hash table
								entry = kmalloc(sizeof(struct u64_entry), GFP_KERNEL);
								if (entry == NULL) {
									printk(KERN_ERR "%s: Failed to allocate memory for entry\n",
									       __func__);
									return -ENOMEM;
								}
								entry->key = gfn;
								INIT_HLIST_NODE(&entry->node);
								hash_add(deduplication_hash_table, &entry->node, gfn);
							}

							// Not found, so add it to the result array
							result[result_size++] = gfn;
							if (result_size >= result_capacity) {
							printk(KERN_WARNING
							       "%s: result array is full: %zu\n",
							       __func__,
							       result_size);
							is_full = true;
							break;
							}
						}
					}
					if (need_resched() ||
					    rwlock_needbreak(
						    &kvm->mmu_lock)) {
						cond_resched_rwlock_write(
							&kvm->mmu_lock);
					}
			}
			write_unlock(&kvm->mmu_lock);
			srcu_read_unlock(&kvm->srcu, srcu_lock_retval);
			if (is_full) {
					break;
			}
		}
		if (is_full) {
			break;
		}
	}

	*array = result;
	*size = result_size;

	if (is_deduplication) {
		// Destroy the hash table
		hash_init(deduplication_hash_table);
	}

	printk(KERN_WARNING "%s: nr_duplicated_gfns = %zu\n", __func__, nr_duplicated_gfns);
	printk(KERN_WARNING "%s: result_size = %zu\n", __func__, result_size);
	return 0;
}
EXPORT_SYMBOL(get_all_private_gfn);

int get_gfn_host_addrs(struct kvm *kvm, u64 gfn, u64 *hva, u64 *hpa)
{
	u64 pfn;

	if (kvm == NULL || hva == NULL || hpa == NULL) {
		printk(KERN_ERR "%s: Invalid arguments\n", __func__);
		return -EINVAL;
	}

	pfn = gfn_to_pfn(kvm, gfn);
	if (!pfn_valid(pfn)) {
		printk(KERN_ERR "%s: Invalid pfn\n", __func__);
		return -EINVAL;
	}

	*hva = gfn_to_hva(kvm, gfn);
	*hpa = pfn << PAGE_SHIFT;

	return 0;
}
EXPORT_SYMBOL(get_gfn_host_addrs);


// Remove duplicated elements in the array
int deduplicate_array(u64 *array, size_t old_arr_size, size_t *new_arr_size)
{
	// Use deduplication_hash_table to store the deduplicated elements
	struct u64_entry *entry;

	size_t i;
	size_t new_size = 0;

	// Initialize the hash table
	hash_init(deduplication_hash_table);

	// Iterate over the array and insert the elements to the hash table
	for (i = 0; i < old_arr_size; i++) {
		// Try to find the element in the hash table
		hash_for_each_possible(deduplication_hash_table, entry, node, array[i]) {
			if (entry->key == array[i]) {
				// Found, so skip it
				continue;
			}
		}

		// Not found, so add it to the hash table
		entry = kmalloc(sizeof(struct u64_entry), GFP_KERNEL);
		if (entry == NULL) {
			printk(KERN_ERR "%s: Failed to allocate memory for entry\n",
			       __func__);
			return -ENOMEM;
		}
		entry->key = array[i];
		INIT_HLIST_NODE(&entry->node);
		hash_add(deduplication_hash_table, &entry->node, array[i]);

		new_size++;
	}

	// Iterate over the hash table and copy the elements to the array
	hash_for_each(deduplication_hash_table, i, entry, node) {
		array[new_size++] = entry->key;
	}

	// Assign the new size to the output parameter
	*new_arr_size = new_size;

	// Destroy the hash table
	hash_init(deduplication_hash_table);

	return 0;
}

/* FIXME: This function might has implementation issue */
void block_vm_write(struct kvm *kvm) {
    struct kvm_vcpu *vcpu;
    long unsigned int i;

    kvm_for_each_vcpu(i, vcpu, kvm) {
		kvm_start_tracking(vcpu, KVM_PAGE_TRACK_WRITE);
    }
}
EXPORT_SYMBOL(block_vm_write);

/* FIXME: This function might has implementation issue */
void unblock_vm_write(struct kvm *kvm) {
    struct kvm_vcpu *vcpu;
    long unsigned int i;

    kvm_for_each_vcpu(i, vcpu, kvm) {
		kvm_stop_tracking(vcpu, KVM_PAGE_TRACK_WRITE);
    }
}
EXPORT_SYMBOL(unblock_vm_write);

/* FIXME: This function might has implementation issue */
void block_vm_write_on_gfn(struct kvm *kvm, u64 gfn) {
	struct kvm_vcpu *vcpu;
	long unsigned int i;

	kvm_for_each_vcpu(i, vcpu, kvm) {
		__track_single_page(vcpu, gfn, KVM_PAGE_TRACK_WRITE, true);
	}
}
EXPORT_SYMBOL(block_vm_write_on_gfn);

/* FIXME: This function might has implementation issue */
void unblock_vm_write_on_gfn(struct kvm *kvm, u64 gfn) {
	struct kvm_vcpu *vcpu;
	long unsigned int i;

	kvm_for_each_vcpu(i, vcpu, kvm) {
		__untrack_single_page(vcpu, gfn, KVM_PAGE_TRACK_WRITE);
	}
}
EXPORT_SYMBOL(unblock_vm_write_on_gfn);
