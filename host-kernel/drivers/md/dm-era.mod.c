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
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xa38602cd, "drain_workqueue" },
	{ 0x3d6961ed, "dm_btree_insert" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x925f421d, "dm_array_info_init" },
	{ 0x9290e07a, "dm_tm_read_lock" },
	{ 0x1e3f728d, "dm_block_data" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xb654f935, "dm_block_manager_create" },
	{ 0x96848186, "scnprintf" },
	{ 0x586705e1, "dm_btree_del" },
	{ 0x932a6ffc, "dm_tm_shadow_block" },
	{ 0x37a0cba, "kfree" },
	{ 0x5475ba9e, "dm_block_location" },
	{ 0x54f69d, "dm_tm_pre_commit" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x7b6b3af5, "dm_bm_read_lock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xdf3a4e7d, "dm_tm_create_with_sm" },
	{ 0xc0d7c2d1, "dm_array_resize" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0x30c37cc0, "dm_bm_write_lock_zero" },
	{ 0x88998224, "dm_disk_bitset_init" },
	{ 0x75606d09, "dm_btree_lookup" },
	{ 0x7ade1071, "dm_tm_destroy" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xa2a74861, "dm_array_set_value" },
	{ 0x6b2357b6, "dm_bitset_test_bit" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x5375ca71, "dm_bm_write_lock" },
	{ 0xfce51d79, "dm_array_empty" },
	{ 0x2c5a02df, "dm_btree_find_lowest_key" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0x73420d49, "dm_bitset_empty" },
	{ 0x72289260, "dm_block_manager_destroy" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xc0fadb13, "dm_bitset_del" },
	{ 0x4f477261, "dm_bm_checksum" },
	{ 0x466793e6, "dm_set_target_max_io_len" },
	{ 0xfb578fc5, "memset" },
	{ 0xe8438eb5, "dm_array_del" },
	{ 0x2d38ecd9, "dm_bitset_resize" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xf82dba90, "dm_btree_empty" },
	{ 0x5736c9c5, "dm_bitset_flush" },
	{ 0xd163cade, "dm_tm_commit" },
	{ 0xaeca8967, "blk_limits_io_min" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0x999e8297, "vfree" },
	{ 0x88295b96, "dm_tm_unlock" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x688d422d, "dm_bm_block_size" },
	{ 0x1bb67920, "blk_limits_io_opt" },
	{ 0x11fbbe02, "dm_bitset_set_bit" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x30a26537, "dm_btree_remove" },
	{ 0x48e323be, "dm_bm_unlock" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x87c934be, "dm_tm_inc" },
	{ 0x2bc1a8d9, "dm_tm_open_with_sm" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dm-persistent-data");


MODULE_INFO(srcversion, "4DB555F6AF32D569A51E761");
