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
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x6fbc6a00, "radix_tree_insert" },
	{ 0xc63d2aad, "zero_fill_bio" },
	{ 0xfbc4f89e, "io_schedule_timeout" },
	{ 0x788957f4, "blkdev_nr_zones" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x70ad75fb, "radix_tree_lookup" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x96848186, "scnprintf" },
	{ 0xeee3ef31, "register_shrinker" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x1984d421, "out_of_line_wait_on_bit" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0xd688716b, "dm_kcopyd_client_create" },
	{ 0xbb3021a7, "blkdev_zone_mgmt" },
	{ 0xc849b0b6, "dm_accept_partial_bio" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xa916b694, "strnlen" },
	{ 0x231b2691, "unregister_shrinker" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x2c07ddf, "bioset_exit" },
	{ 0x800473f, "__cond_resched" },
	{ 0x58e3306d, "bit_wait_io" },
	{ 0xa09dd780, "bio_put" },
	{ 0x4e6e4b41, "radix_tree_delete" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x2b73bad9, "__bio_advance" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x4071b517, "out_of_line_wait_on_bit_timeout" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x69dd3b5b, "crc32_le" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x6dcf857f, "uuid_null" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0xc5e94d26, "blkdev_issue_zeroout" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x612bfd89, "errno_to_blk_status" },
	{ 0x86490580, "current_task" },
	{ 0x53c25af3, "bio_alloc_clone" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x668b19a1, "down_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x7dcf4135, "__xa_insert" },
	{ 0xaeca8967, "blk_limits_io_min" },
	{ 0x745a981, "xa_erase" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x80702017, "dm_kcopyd_copy" },
	{ 0xabe5fe4c, "dm_table_device_name" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0x44bae227, "bit_wait_timeout" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xe08efff5, "bioset_init" },
	{ 0xd9491c14, "xa_destroy" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x154c6338, "dm_kcopyd_client_destroy" },
	{ 0xee91879b, "rb_first_postorder" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x6b9f01cd, "blkdev_issue_flush" },
	{ 0x4e68e9be, "rb_next_postorder" },
	{ 0x1bb67920, "blk_limits_io_opt" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0x754d539c, "strlen" },
	{ 0xa0fbac79, "wake_up_bit" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x53b954a2, "up_read" },
	{ 0xbf529047, "submit_bio_wait" },
	{ 0x264fc44e, "blkdev_report_zones" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x9af19ea7, "fs_bio_set" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "71C1203312B8D7D8D72DF17");
