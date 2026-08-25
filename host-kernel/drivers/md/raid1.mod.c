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
	{ 0x37a0cba, "kfree" },
	{ 0xeed7856d, "md_bitmap_endwrite" },
	{ 0xf9e4c111, "md_write_end" },
	{ 0x18219d34, "bio_free_pages" },
	{ 0xa09dd780, "bio_put" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xbc1c6683, "bio_end_io_acct_remapped" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x22c71c1, "md_wakeup_thread" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x935bae2a, "md_bitmap_resize" },
	{ 0xac25495b, "md_set_array_sectors" },
	{ 0xeb78b21b, "kernfs_notify" },
	{ 0xb244293b, "md_integrity_add_rdev" },
	{ 0x90d27bc3, "disk_stack_limits" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x4dcfbebd, "sync_page_io" },
	{ 0xa532aa14, "rdev_set_badblocks" },
	{ 0x8eb7efa2, "md_error" },
	{ 0x59f2c5a8, "md_bitmap_unplug" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x800473f, "__cond_resched" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x86490580, "current_task" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0x1645c8ce, "__blk_trace_note_message" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x10795da2, "__put_page" },
	{ 0xd179edea, "bio_uninit" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x120b336a, "__rb_insert_augmented" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x56470118, "__warn_printk" },
	{ 0x551bd071, "__rb_erase_color" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0xca9360b5, "rb_next" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xc005bb87, "bio_init" },
	{ 0xecd23704, "bio_kmalloc" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x38e46431, "mempool_exit" },
	{ 0x2c07ddf, "bioset_exit" },
	{ 0x8262e8ed, "md_done_sync" },
	{ 0x2f47d5ce, "md_bitmap_end_sync" },
	{ 0x472a2ddb, "badblocks_check" },
	{ 0x5d6cbf9f, "bdevname" },
	{ 0x245d1c1c, "md_cluster_ops" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x53c25af3, "bio_alloc_clone" },
	{ 0xba97195a, "__tracepoint_block_bio_remap" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x273aff5c, "__SCT__tp_func_block_bio_remap" },
	{ 0xfb578fc5, "memset" },
	{ 0x54366892, "bio_split" },
	{ 0x9f218161, "bio_chain" },
	{ 0xa1179cbd, "bio_start_io_acct" },
	{ 0x5ef68429, "md_integrity_register" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x15c85de3, "mempool_init" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0xf8e5a250, "md_allow_write" },
	{ 0xe08efff5, "bioset_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x5232906e, "md_register_thread" },
	{ 0x6f52d648, "mddev_init_writes_pending" },
	{ 0x156d36c0, "blk_queue_max_write_zeroes_sectors" },
	{ 0xe3d51626, "md_unregister_thread" },
	{ 0xb0925ade, "md_bitmap_start_sync" },
	{ 0xcaebeb71, "md_bitmap_cond_end_sync" },
	{ 0xb5f8bf36, "bio_reset" },
	{ 0xdb4b00ec, "md_bitmap_close_sync" },
	{ 0x151f4898, "schedule_timeout_uninterruptible" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0xd3220720, "md_check_recovery" },
	{ 0xf53f74a2, "rdev_clear_badblocks" },
	{ 0x40f82a08, "bio_trim" },
	{ 0xbf529047, "submit_bio_wait" },
	{ 0x87c820c0, "bio_copy_data" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x1005980, "md_write_start" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0xd27b25dd, "blk_check_plugged" },
	{ 0x4f4a7886, "md_bitmap_startwrite" },
	{ 0x2c4354fc, "md_flush_request" },
	{ 0xd67881ed, "md_wait_for_blocked_rdev" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x21d6e3b6, "register_md_personality" },
	{ 0x4f2e94e7, "unregister_md_personality" },
	{ 0x1cd42933, "__SCK__tp_func_block_bio_remap" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F15C96CAD52A0D0470DE837");
