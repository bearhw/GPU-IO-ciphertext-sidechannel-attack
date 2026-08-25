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

SYMBOL_CRC(dm_cache_policy_register, 0x725a0512, "_gpl");
SYMBOL_CRC(dm_cache_policy_unregister, 0xb392a80f, "_gpl");
SYMBOL_CRC(dm_cache_policy_create, 0xe1bdae47, "_gpl");
SYMBOL_CRC(dm_cache_policy_destroy, 0xadbefda4, "_gpl");
SYMBOL_CRC(dm_cache_policy_get_name, 0x7890d535, "_gpl");
SYMBOL_CRC(dm_cache_policy_get_version, 0x890723f7, "_gpl");
SYMBOL_CRC(dm_cache_policy_get_hint_size, 0xcf8c2590, "_gpl");
SYMBOL_CRC(btracker_create, 0xbf1a2968, "_gpl");
SYMBOL_CRC(btracker_destroy, 0x5adc2807, "_gpl");
SYMBOL_CRC(btracker_nr_writebacks_queued, 0x5de611a9, "_gpl");
SYMBOL_CRC(btracker_nr_demotions_queued, 0xccfe6409, "_gpl");
SYMBOL_CRC(btracker_queue, 0x87bee547, "_gpl");
SYMBOL_CRC(btracker_issue, 0xa2365f44, "_gpl");
SYMBOL_CRC(btracker_complete, 0xa7eadcb5, "_gpl");
SYMBOL_CRC(btracker_promotion_already_present, 0x0efbca4c, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x24507fbf, "dm_array_cursor_next" },
	{ 0xa38602cd, "drain_workqueue" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x925f421d, "dm_array_info_init" },
	{ 0x1e3f728d, "dm_block_data" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x828d0cfd, "dm_submit_bio_remap" },
	{ 0x95a52abd, "dm_bm_is_read_only" },
	{ 0xb654f935, "dm_block_manager_create" },
	{ 0x6c218062, "dm_bitset_cursor_end" },
	{ 0x96848186, "scnprintf" },
	{ 0x15c85de3, "mempool_init" },
	{ 0x37a0cba, "kfree" },
	{ 0x5475ba9e, "dm_block_location" },
	{ 0xace9b57b, "dm_bio_prison_destroy_v2" },
	{ 0x54f69d, "dm_tm_pre_commit" },
	{ 0xd99e003d, "dm_bio_prison_create_v2" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc3ff38c2, "down_read_trylock" },
	{ 0x3ad0f55b, "dm_bm_flush" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd688716b, "dm_kcopyd_client_create" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x7b6b3af5, "dm_bm_read_lock" },
	{ 0xb3d7482b, "dm_bitset_new" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xdf3a4e7d, "dm_tm_create_with_sm" },
	{ 0xc0d7c2d1, "dm_array_resize" },
	{ 0x6c2c7ef4, "dm_array_cursor_get_value" },
	{ 0x19ee7502, "dm_bio_prison_alloc_cell_v2" },
	{ 0xb720ee73, "dm_array_cursor_begin" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x30c37cc0, "dm_bm_write_lock_zero" },
	{ 0x7e29c59d, "dm_bitset_clear_bit" },
	{ 0x88998224, "dm_disk_bitset_init" },
	{ 0x2c07ddf, "bioset_exit" },
	{ 0x1ba7cc87, "dm_array_new" },
	{ 0x7ade1071, "dm_tm_destroy" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xa2a74861, "dm_array_set_value" },
	{ 0x9e798e22, "dm_bm_set_read_only" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0xa34af51, "dm_suspended" },
	{ 0x6cf28ef1, "dm_bio_prison_free_cell_v2" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x88a5c035, "dm_bitset_cursor_next" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x5375ca71, "dm_bm_write_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xfce51d79, "dm_array_empty" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x5a921311, "strncmp" },
	{ 0x5eb24829, "dm_shift_arg" },
	{ 0x9166fada, "strncpy" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0x9f218161, "bio_chain" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0x61a6fe0f, "dm_cell_put_v2" },
	{ 0x73420d49, "dm_bitset_empty" },
	{ 0x72289260, "dm_block_manager_destroy" },
	{ 0xd237b9fb, "dm_array_walk" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xc0fadb13, "dm_bitset_del" },
	{ 0x612bfd89, "errno_to_blk_status" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x4f477261, "dm_bm_checksum" },
	{ 0x466793e6, "dm_set_target_max_io_len" },
	{ 0x2f40da68, "dm_bm_set_read_write" },
	{ 0xfb578fc5, "memset" },
	{ 0x53c25af3, "bio_alloc_clone" },
	{ 0x2bf609c5, "dm_table_event" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xe8438eb5, "dm_array_del" },
	{ 0x2d38ecd9, "dm_bitset_resize" },
	{ 0x9341b376, "dm_bitset_cursor_get_value" },
	{ 0xc7d094b5, "dm_read_arg_group" },
	{ 0xc972449f, "mempool_alloc_slab" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6d7c8349, "dm_cell_lock_v2" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0x5736c9c5, "dm_bitset_flush" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xd163cade, "dm_tm_commit" },
	{ 0xaeca8967, "blk_limits_io_min" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa29d4c0c, "dm_bitset_cursor_skip" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x9955fef4, "dm_bitset_cursor_begin" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x80702017, "dm_kcopyd_copy" },
	{ 0xabe5fe4c, "dm_table_device_name" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0x999e8297, "vfree" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xe08efff5, "bioset_init" },
	{ 0xf651305f, "dm_cell_get_v2" },
	{ 0x154c6338, "dm_kcopyd_client_destroy" },
	{ 0x4a914868, "dm_cell_quiesce_v2" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x688d422d, "dm_bm_block_size" },
	{ 0x1bb67920, "blk_limits_io_opt" },
	{ 0x11fbbe02, "dm_bitset_set_bit" },
	{ 0x45700556, "dm_cell_unlock_v2" },
	{ 0x243ce1ad, "dm_array_cursor_end" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf71b1e21, "dm_cell_lock_promote_v2" },
	{ 0x754d539c, "strlen" },
	{ 0x53b954a2, "up_read" },
	{ 0x48e323be, "dm_bm_unlock" },
	{ 0xceeef209, "dm_bio_get_target_bio_nr" },
	{ 0x7deff673, "dm_consume_args" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x382a0134, "dm_array_get_value" },
	{ 0x38e46431, "mempool_exit" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x2bc1a8d9, "dm_tm_open_with_sm" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dm-persistent-data,dm-bio-prison");


MODULE_INFO(srcversion, "BBA7F3E09E188BADF2E8A56");
