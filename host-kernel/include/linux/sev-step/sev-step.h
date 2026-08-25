#ifndef SEV_STEP_H
#define SEV_STEP_H

#include <linux/types.h>
#include <linux/spinlock_types.h>
#include <asm/atomic.h>
#include <linux/kvm_types.h>
#include <asm/kvm_page_track.h>
#include <asm/svm.h>

#include "idt-gate-desc.h"
#include "libcache.h"
#include <uapi/linux/sev-step/sev-step.h>

#include <linux/hashtable.h>
#include <linux/spinlock.h>

#define CTL_MSR_0  0xc0010200ULL
#define CTL_MSR_1  0xc0010202ULL
#define CTL_MSR_2  0xc0010204ULL
#define CTL_MSR_3  0xc0010206ULL
#define CTL_MSR_4  0xc0010208ULL
#define CTL_MSR_5  0xc001020aULL

#define CTR_MSR_0  0xc0010201ULL
#define CTR_MSR_1  0xc0010203ULL
#define CTR_MSR_2  0xc0010205ULL
#define CTR_MSR_3  0xc0010207ULL
#define CTR_MSR_4  0xc0010209ULL
#define CTR_MSR_5  0xc001020bULL

/* Kernel only SEV-STEP TYPES */
/**
 * @brief struct for storing the api context
 */


/**
 * @brief struct for storing idt
 */
typedef struct {
    gate_desc_t *base;
    size_t     entries;
} idt_t;

/**
 * @brief Describes the current state of the signle stepping "engine"
 * 
 */
typedef enum  {
	///@brief Not running
	SEV_STEP_STEPPING_STATUS_DISABLED,
	///@brief User requested to enable, still pending until next vmenter
	SEV_STEP_STEPPING_STATUS_DISABLED_WANT_INIT,
	///@brief Running
	SEV_STEP_STEPPING_STATUS_ENABLED,
	/// @brief User requested to disable, still pending until next vmenter
	SEV_STEP_STEPPING_STATUS_ENABLED_WANT_DISABLE,
} sev_step_stepping_status_t;

typedef enum  {
	SEV_STEP_EV_TYPE_FROM_USER,
	SEV_STEP_EV_TYPE_L1D_KERN_ONLY,
	SEV_STEP_EV_TYPE_L1D_KERN_ONLY_ALIASING,
} sev_step_cache_attack_ev_type_t;

typedef enum {
	SEV_STEP_CACHE_ATTACK_IDLE,
	SEV_STEP_CACHE_ATTACK_WANT_PRIME,
	SEV_STEP_CACHE_ATTACK_WANT_PROBE,
	SEV_STEP_CACHE_ATTACK_HAVE_RESULT,
} sev_step_cache_attack_status_t;


typedef struct {
	/// @brief lookup tables that we can attack. @eviction_sets contains
	/// the corresponding eviction set to prime the whole table.
	lookup_table_t* lookup_tables;
	uint64_t lookup_tables_len;
	/// @brief Each entry is an eviction set for the corresponding lookup table. The first
	/// @way_count elements prime the first cacheline of the corresponding lookup table and so on
	addr_list_t* eviction_sets;
	/// @brief May be null from some @type values.
	/// For some eviction sets we need to pin pages. In this case, we store
	// for each eviction set an array of pointers to all the pinned pages. We use this later on to
	//unpin them
	struct page*** pinned_pages;
	/// @brief pinned_pages_inner_len[idx] is the length of pinned_pages[idx]
	uint64_t* pinned_pages_inner_len;
	/// @brief way count of the attacked cache
	uint64_t way_count;

	/// @brief we use this to decide how to free the eviction set resources
	sev_step_cache_attack_ev_type_t type;

	/// @brief only used with SEV_STEP_EV_TYPE_L1D_KERN_ONLY_ALIASING. Terribly hacky
	//TODO: refactor once we know if this attack works
	uint64_t* chase_result_for_aliasing_attack;
	uint64_t* probe_array;

	/// @brief used to control when to probe, prime and sent the results
	sev_step_cache_attack_status_t status;
	/// @brief if cache attack is active, this holds the idx of the lookup table that we
	/// want to attack
	int victim_lookup_table_idx;


	/// @brief config for perf counter evaluated in cache attack
	perf_ctl_config_t cache_attack_perf;

	/// @brief offset to apply to ev_addr before data store region begins. This
	/// can vary depending on whether we chase "forward"/"with slot 0" or "backward"/"with slot 1"
	uint64_t inplace_data_offset;


	/// @brief If true, use value in custom_apic_timer_value for next signle step. This allows us to force zero
	//steps
	bool use_custom_apic_timer_value;
	/// @brief if use_custom_apic_timer_value, we use this value for the apic timer when doing the cache attack
	uint32_t custom_apic_timer_value;
} sev_step_cache_attack_config_t;


void free_sev_step_cache_attack_config_t(sev_step_cache_attack_config_t* config);
void free_eviction_sets(addr_list_t* eviction_sets,uint64_t len);

// struct gpa_to_ciphertext_cache {
// 	uint64_t gpa;
// 	uint8_t *ct_cache;
// 	uint8_t *null_bitmap;
// 	struct hlist_node hash_node;
// };

#ifdef ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT
struct spa_to_null_cipher_repr {
	u64 spa; // System Physical Address
	uint8_t *null_cipher_repr;
	struct hlist_node hash_node;
};

// Node for a null-page list for quickly checking given a gpa if it is a null page
struct null_page_list {
	uint64_t gpa;
	struct hlist_node hash_node;
};
#endif // ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT

#ifdef ENABLE_MONITOR_UNTRACKED_PAGES
struct page_content_list {
	u64 gpa;
	u8 *content;
	struct list_head list;
};
#endif // ENABLE_MONITOR_UNTRACKED_PAGES

/**
 * @brief global struct holding all parameters needed for single
 * stepping with SEV-STEP
 */
typedef struct {
	// value for the apic timer
    uint32_t tmict_value;
	/// @brief Status of single stepping engine. See comments for enum type
	sev_step_stepping_status_t single_stepping_status;
	// stores the number of steps executed in the vm
	uint32_t counted_instructions;
	/// @brief if true, send vmsa information with each event.
	/// Only works if debug mode is active
	bool decrypt_vmsa;
	/// @brief if decrypt_vmsa is true, we fill this with the decrypted vmsa data after
	/// each vmexit. Other locations that want to send events can use this data
	sev_step_partial_vmcb_save_area_t decrypted_vmsa_data;
	// stores the running vm
	struct kvm* main_vm;
	// if true, interrupt from the previous timer programming has not yet been processed
	bool waitingForTimer;
	// if true, the performance counter is initialized
	bool perf_init;
	//TODO: testing to periodically send apic interrupts
	uint64_t entry_counter;

	/// @brief If true, we flush the guest's tlb before each single step
	bool do_tlb_flush_before_each_step;
	/// @brief May be null. If set, we reset the ACCESS bits of these pages before vmentry
	/// which improves single stepping accuracy
	uint64_t* gpas_target_pages;
	uint64_t gpas_target_pages_len;

	/// @brief core on which idt was retrieved or -1 if idt has never been fetched
	int got_idt_on_cpu;
	/// @brief if got_idt_on_cpu != -1, this holds the idt for that core
	idt_t idt;

	/// @brief May be null. If not, contains all config required for cache attack
	sev_step_cache_attack_config_t* cache_attack_config;


	/* All values for storing old apic config */
	uint32_t old_apic_lvtt;
	uint32_t old_apic_tdcr;
	uint32_t old_apic_tmict;
	gate_desc_t old_idt_gate;

    /************* NEMESIS ***************/
    // NOTE: we assume at most only a single step.
    // The host-program will terminate on multi-step detection anyways
	//We use this to temporarily store the value in svm.c before sending it to
	//userspace with the step event
    uint64_t tsc_latency;
    /************************************/

	bool state_save_values_valid;
	uint64_t vmsa_hpa;
	uint64_t vmcb_hpa;
	uint64_t vmcb_control_kern_vaddr;
	int main_vm_pid;

	bool is_dump_page;
	unsigned nr_dump_pages;
	uint64_t *dump_page_gpas;
	bool is_decrypt_when_dump;
	bool is_relocate_when_dump;

	uint64_t prev_fault_gpa;
	uint64_t curr_fault_gpa;
	bool is_decrypt_when_track;
	bool is_relocate_when_track;
	// bool is_dump_when_track;
	bool is_dump_pre_fault_when_track;
	bool is_dump_post_fault_when_track;
	uint64_t nr_track_events;
#ifdef ENABLE_MONITOR_UNTRACKED_PAGES
	bool is_observe_untracked_pages;
	bool is_send_all_updated_pages;
	uint32_t nr_special_values_when_track;
	uint64_t *special_values_when_track;
	struct list_head untracked_pages_list;
#endif // ENABLE_MONITOR_UNTRACKED_PAGES

#ifdef ENABLE_OLD_SWAP_PAGES_SUPPORT
	bool is_swap_pages;
	int nr_swap_times;
	int nr_gfn1_new_assignments;
	int nr_gfn2_new_assignments;
	bool is_swap_back;
	uint64_t swap_gfn1;
	uint64_t swap_gfn2;
	int swap_done; /* 0=pending, 1=success, -1=error (set by svm_vcpu_run) */
	uint8_t page_dump_buf[PAGE_SIZE]; /* post-swap copy of gfn1 page (is_swap_back mode) */
	bool page_dump_valid; /* true when page_dump_buf contains fresh data */
	/*
	 * Persistent gfn→pfn overrides for pages moved by snp_guest_page_move.
	 * The host page table still has 2MB PMD entries that cannot easily be
	 * updated at 4KB granularity, so instead of modifying the host PT we
	 * intercept kvm_faultin_pfn for the two swapped GFNs and return the
	 * correct post-swap PFN directly, bypassing hva_to_pfn.
	 */
	struct {
		uint64_t gfn;
		uint64_t pfn;
	} swap_pfn_override[2];
	bool swap_pfn_override_valid; /* true once entries are populated */
#endif // ENABLE_OLD_SWAP_PAGES_SUPPORT

#ifdef ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT
	uint64_t null_cipher_repr_spa;
	uint64_t null_cipher_repr_gpa;
	uint8_t *null_cipher_repr;
	// DECLARE_HASHTABLE(ciphertext_pages_cache, 13);
	// spinlock_t ciphertext_pages_cache_lock;
	DECLARE_HASHTABLE(pages_null_cipher_repr, 13);
	// gpas whose page cache represents null pages
	DECLARE_HASHTABLE(null_page_list, 13); 
	// struct list_head null_pages_list;
#endif // ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT

	bool is_dump_private_pages;

	u64 target_page_pfn;
	u64 target_page_hva;
	u8 *target_page_null_ciphertexts;

	u64 gfn_to_translate;
	u64 translated_pfn_of_gfn;
} sev_step_config_t;

// struct gpa_to_ciphertext_cache *
// find_page_ciphertext_cache_at_gpa(sev_step_config_t *config, uint64_t gpa);
// int insert_page_ciphertext_cache_at_gpa(sev_step_config_t *config, uint64_t gpa,
// 					uint8_t *ciphertext,
// 					uint8_t *null_bitmap);
// int update_page_ciphertext_cache_at_gpa(sev_step_config_t *config, uint64_t gpa,
// 					uint8_t *ciphertext,
// 					uint8_t *null_bitmap);
// int remove_page_ciphertext_cache_at_gpa(sev_step_config_t *config,
// 					uint64_t gpa);
// int destroy_page_ciphertext_cache(sev_step_config_t *config);

#ifdef ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT
bool is_exist_page_null_cipher_repre(sev_step_config_t *config);
struct spa_to_null_cipher_repr *
get_a_page_null_cipher_repre(sev_step_config_t *config);
struct spa_to_null_cipher_repr *
find_page_null_cipher_repr_at_spa(sev_step_config_t *config, u64 spa);
int insert_page_null_cipher_repr(sev_step_config_t *config, u64 spa,
				 uint8_t *null_cipher_repr);
int remove_page_null_cipher_repr(sev_step_config_t *config, u64 spa);
int destroy_page_null_cipher_repr(sev_step_config_t *config);

bool is_page_in_null_page_list(sev_step_config_t *config, uint64_t gpa);
int insert_page_to_null_page_list(sev_step_config_t *config, uint64_t gpa);
int remove_page_from_null_page_list(sev_step_config_t *config, uint64_t gpa);
int destroy_null_page_list(sev_step_config_t *config);
#endif // ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT

#ifdef ENABLE_MONITOR_UNTRACKED_PAGES
int insert_page_to_untracked_pages_list(sev_step_config_t *config, uint64_t gpa, u8 *content);
int remove_page_from_untracked_pages_list(sev_step_config_t *config, uint64_t gpa);
int destroy_untracked_pages_list(sev_step_config_t *config);
#endif // ENABLE_MONITOR_UNTRACKED_PAGES

int get_all_private_gfn(struct kvm *kvm, uint64_t **array, size_t *size, size_t max_nr_gfns, bool is_deduplication);

int create_target_page_info(sev_step_config_t *config, u64 target_page_hva,
			    u64 target_page_pfn, u8 *null_ciphertexts,
			    bool print_ciphertexts);
int destroy_target_page_info(sev_step_config_t *config);

extern sev_step_config_t global_sev_step_config;
extern struct mutex sev_step_config_mutex;

/* SEV-STEP FUNCTIONS */

/**
 * @brief Remove a single page from page track pool
 * 
 * @param vcpu vcpu of kvm
 * @param gfn guest page number
 * @param mode tracking mode
 * @return true on success
 */
bool __untrack_single_page(struct kvm_vcpu *vcpu, gfn_t gfn,
			   enum kvm_page_track_mode mode);

/**
 * @brief Add a single page to page track pool
 * 
 * @param vcpu vcpu of kvm
 * @param gfn guest page number
 * @param mode page tracking mode
 * @param is_allow_retrack if true, allow retrack
 * @return true on success
 */
bool __track_single_page(struct kvm_vcpu *vcpu, gfn_t gfn,
			 enum kvm_page_track_mode mode, bool is_allow_retrack);

/**
 * @brief Start the tracking of all pages
 * 
 * @param vcpu vcpu of kvm
 * @param mode page tracking mode
 * @return long the number of tracked pages
 */
long kvm_start_tracking(struct kvm_vcpu *vcpu, enum kvm_page_track_mode mode);

/**
 * @brief Track a list of pages
 * 
 * @param vcpu vcpu of kvm
 * @param nr_pages number of pages
 * @param track_gpas array of guest page numbers
 * @param mode page tracking mode
 * @return long the number of tracked pages
 */
long kvm_track_pages(struct kvm_vcpu *vcpu, u64 nr_pages, u64 *track_gpas,
		     enum kvm_page_track_mode mode);

/**
 * @brief Track all pages except the ones in the except_gpas array
 * 
 * @param vcpu vcpu of kvm
 * @param nr_except_pages number of pages to exclude
 * @param except_gpas array of guest page numbers to exclude
 * @param mode page tracking mode
 * @return long the number of tracked pages
 */
long kvm_track_all_pages_except(struct kvm_vcpu *vcpu, u64 nr_except_pages,
				u64 *except_gpas,
				enum kvm_page_track_mode mode);

/**
 * @brief Stop the tracking of all pages
 * 
 * @param vcpu vcpu of kvm
 * @param mode page tracking mode
 * @return long the number of untracked pages
 */
long kvm_stop_tracking(struct kvm_vcpu *vcpu, enum kvm_page_track_mode mode);

/**
 * @brief Convert the performance counter config to u64 int
 * 
 * @param config performance counter config
 * @return uint64_t config as u64 int
 */
uint64_t perf_ctl_to_u64(perf_ctl_config_t * config);

/**
 * @brief Set ctl config on cpu
 * 
 * @param config performance counter config
 * @param cpu the cpu id on which the performance counting runs
 * @param ctl_msr predefined ctl value
 */
void write_ctl(perf_ctl_config_t * config, int cpu, uint64_t ctl_msr);

/**
 * @brief Read the counter values
 * 
 * @param ctr_msr predefined ctr value
 * @param cpu the cpu id on which the performance counting runs
 * @param result for storing the performance values
 */
void read_ctr(uint64_t ctr_msr, int cpu, uint64_t* result);

/**
 * @brief Setup the performance counter config
 */
void setup_perfs(sev_step_config_t* config);

/**
 * @brief Determine the amount of steps executed in the vm
 * 
 * @param config global sev step config
 */
void calculate_steps(sev_step_config_t *config);

/**
 * @brief Clear the no-execute bit
 * 
 * @param vcpu vcpu of kvm
 * @param gfn guest page number
 * @return true on success
 */
bool __clear_nx_on_page(struct kvm_vcpu *vcpu, gfn_t gfn);

/**
 * @brief Reset the access bit (dont' confuse with present bit, for access tracking)
 * for the given gfn. Mainly used to get more stable single
 * stepping as the page table walker has to reset this bit, enlarging the window where a timer interrupt
 * leads to a single step
 * 
 * @param vcpu 
 * @param gfn guest frame number
 * @return true on success
 * @return false on error
 */

bool sev_step_reset_access_bit(struct kvm_vcpu *vcpu, gfn_t gfn);
/**
 * @brief Helper function that return true for all sev_step_stepping_status_t states in which
 * signle stepping is enabled
 * 
 * @param cfg global sev_step_config
 * @return true if single stepping is enabled
 * @return false if single stepping is disabled
 */
bool sev_step_is_single_stepping_active(sev_step_config_t* cfg);

/**
 * @brief Copies the vmcb of the given vcpu into the result struct. Automatically decrypts
 * the data if sev is enabled
 * 
 * code adapted from `void dump_vmcb(struct kvm_vcpu *vcpu)` (also in svm.c)

 * 
 * @param struct vcpu whose vm control block field should be decrypted
 * @param vmcb_result caller allocated. Will be filled with decrypted data
 * @param sev_es_save_area caller allocated. Only filled for sev snp vm
 * @return int 0 on success
 */
int sev_step_get_vmcb_save_area(struct kvm_vcpu *vcpu, struct vmcb_save_area* vmcb_result,
	struct sev_es_save_area *vmsa_result);

bool is_pfn_sev_private(struct kvm *kvm, u64 pfn);

// int get_gpa_ciphertext_at_gpa(struct kvm *kvm, u64 gpa, u64 target_gpa,
// 			      u8 *out_page_content);

// int get_ciphertext_at_gpa_with_timing(struct kvm *kvm, u64 gpa, u64 target_gpa,
// 				      u8 *out_page_content,
// 				      s64 *ptr_move_time_in_ns,
// 				      s64 *ptr_copy_time_in_ns,
// 				      s64 *ptr_other_time_in_ns,
// 				      u32 *ptr_nr_move_times);

// int get_gfn_ciphertext_at_pfn(u64 snp_context_pa, u64 gfn, void *target_hva,
int get_gfn_ciphertext_at_pfn(struct kvm *kvm, u64 gfn, u64 gfn_pfn,
			      void *target_hva, u64 target_pfn,
			      u8 *out_page_content, bool is_kernel_target);

int get_gfn_ciphertext_at_pfn_safe(struct kvm *kvm, u64 gfn, u64 gfn_pfn,
				   void *target_hva, u64 target_pfn,
				   u8 *out_page_content, bool is_kernel_target);

int get_gfn_plaintext_by_decrypt_in_debug_mode(struct kvm *kvm, u64 gfn_pfn,
					       u8 *out_page_content);

int get_kvm_sev_snp_context_addr(struct kvm *kvm, u64 *snp_context_va,
				 u64 *snp_context_pa);

int get_kvm_sev_asid(struct kvm *kvm, int *asid);
int get_gfn_host_addrs(struct kvm *kvm, u64 gfn, u64 *hva, u64 *hpa);

int deduplicate_array(u64 *array, size_t old_size, size_t *new_size);

void block_vm_write(struct kvm *kvm);
void unblock_vm_write(struct kvm *kvm);

void block_vm_write_on_gfn(struct kvm *kvm, u64 gfn);
void unblock_vm_write_on_gfn(struct kvm *kvm, u64 gfn);


#endif // SEV_STEP_H
