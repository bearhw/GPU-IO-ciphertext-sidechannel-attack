#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8a35b432, "sme_me_mask" },
	{ 0xd7f43eda, "pin_user_pages_fast" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x10795da2, "__put_page" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xa38602cd, "drain_workqueue" },
	{ 0x941f2aaa, "eventfd_ctx_put" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x4940ba3b, "__mmap_lock_do_trace_acquire_returned" },
	{ 0x94961283, "vunmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x704ea0a4, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x3b9642a2, "__tracepoint_mmap_lock_released" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x2ebe3135, "cpu_is_hotpluggable" },
	{ 0x3c1c035, "acrn_remove_intr_handler" },
	{ 0xfd98a590, "find_vma" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7eb808d0, "add_cpu" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xd28f6a7f, "fput" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x9166fada, "strncpy" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xed2a2b32, "vmap" },
	{ 0xd0177a65, "acrn_setup_intr_handler" },
	{ 0xd67364f7, "eventfd_ctx_fdget" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x41ed3cec, "eventfd_ctx_remove_wait_queue" },
	{ 0x2d0fc210, "follow_pfn" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x4708008a, "misc_register" },
	{ 0x380e6678, "unpin_user_page" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x668b19a1, "down_read" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0x24f14039, "__mmap_lock_do_trace_start_locking" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x29ad8e33, "x86_hyper_type" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x999e8297, "vfree" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x12362d9f, "cpu_info" },
	{ 0xad4e6259, "remove_cpu" },
	{ 0x1f9907f7, "__tracepoint_mmap_lock_start_locking" },
	{ 0x1f06be15, "__mmap_lock_do_trace_released" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xc1d8cfaf, "__fdget" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x53b954a2, "up_read" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x1e6fbbe4, "eventfd_ctx_fileget" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "AAA135BE6572F49C05F42E9");
