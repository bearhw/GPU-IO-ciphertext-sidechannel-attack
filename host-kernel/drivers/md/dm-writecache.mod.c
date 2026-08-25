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
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2d8750e5, "dm_io" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xa6257a2f, "complete" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x92997ed8, "_printk" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x96848186, "scnprintf" },
	{ 0x86490580, "current_task" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x93a6e0b2, "io_schedule" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xbc4e24bb, "copy_mc_to_kernel" },
	{ 0x2b73bad9, "__bio_advance" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x328e3354, "__memcpy_flushcache" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0x2c07ddf, "bioset_exit" },
	{ 0x38e46431, "mempool_exit" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x999e8297, "vfree" },
	{ 0x154c6338, "dm_kcopyd_client_destroy" },
	{ 0x9e4faeef, "dm_io_client_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0x94961283, "vunmap" },
	{ 0xfb578fc5, "memset" },
	{ 0xa34af51, "dm_suspended" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xca9360b5, "rb_next" },
	{ 0xf82ec573, "rb_prev" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x392b1fea, "wait_for_completion_io" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xa09dd780, "bio_put" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x84502a47, "blk_status_to_errno" },
	{ 0xece784c2, "rb_first" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x601f665f, "dm_io_client_create" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x5eb24829, "dm_shift_arg" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0x6a037cf1, "mempool_kfree" },
	{ 0xd35a6d31, "mempool_kmalloc" },
	{ 0x15c85de3, "mempool_init" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0xe08efff5, "bioset_init" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xc7d094b5, "dm_read_arg_group" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x2a976d1c, "dax_synchronous" },
	{ 0xd84d35bd, "dax_read_lock" },
	{ 0x2d609547, "dax_direct_access" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x8a35b432, "sme_me_mask" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0xed2a2b32, "vmap" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x8eee3399, "dax_read_unlock" },
	{ 0xd688716b, "dm_kcopyd_client_create" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xa38602cd, "drain_workqueue" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0xc849b0b6, "dm_accept_partial_bio" },
	{ 0xceeef209, "dm_bio_get_target_bio_nr" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x80702017, "dm_kcopyd_copy" },
	{ 0x7807f0f8, "schedule_timeout_idle" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x90006be6, "dm_kcopyd_client_flush" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "56E9CEFA38990ED574D3034");
