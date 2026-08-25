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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(dm_array_info_init, 0x925f421d, "_gpl");
SYMBOL_CRC(dm_array_empty, 0xfce51d79, "_gpl");
SYMBOL_CRC(dm_array_resize, 0xc0d7c2d1, "_gpl");
SYMBOL_CRC(dm_array_new, 0x1ba7cc87, "_gpl");
SYMBOL_CRC(dm_array_del, 0xe8438eb5, "_gpl");
SYMBOL_CRC(dm_array_get_value, 0x382a0134, "_gpl");
SYMBOL_CRC(dm_array_set_value, 0xa2a74861, "_gpl");
SYMBOL_CRC(dm_array_walk, 0xd237b9fb, "_gpl");
SYMBOL_CRC(dm_array_cursor_begin, 0xb720ee73, "_gpl");
SYMBOL_CRC(dm_array_cursor_end, 0x243ce1ad, "_gpl");
SYMBOL_CRC(dm_array_cursor_next, 0x24507fbf, "_gpl");
SYMBOL_CRC(dm_array_cursor_skip, 0x9ced228c, "_gpl");
SYMBOL_CRC(dm_array_cursor_get_value, 0x6c2c7ef4, "_gpl");
SYMBOL_CRC(dm_disk_bitset_init, 0x88998224, "_gpl");
SYMBOL_CRC(dm_bitset_empty, 0x73420d49, "_gpl");
SYMBOL_CRC(dm_bitset_new, 0xb3d7482b, "_gpl");
SYMBOL_CRC(dm_bitset_resize, 0x2d38ecd9, "_gpl");
SYMBOL_CRC(dm_bitset_del, 0xc0fadb13, "_gpl");
SYMBOL_CRC(dm_bitset_flush, 0x5736c9c5, "_gpl");
SYMBOL_CRC(dm_bitset_set_bit, 0x11fbbe02, "_gpl");
SYMBOL_CRC(dm_bitset_clear_bit, 0x7e29c59d, "_gpl");
SYMBOL_CRC(dm_bitset_test_bit, 0x6b2357b6, "_gpl");
SYMBOL_CRC(dm_bitset_cursor_begin, 0x9955fef4, "_gpl");
SYMBOL_CRC(dm_bitset_cursor_end, 0x6c218062, "_gpl");
SYMBOL_CRC(dm_bitset_cursor_next, 0x88a5c035, "_gpl");
SYMBOL_CRC(dm_bitset_cursor_skip, 0xa29d4c0c, "_gpl");
SYMBOL_CRC(dm_bitset_cursor_get_value, 0x9341b376, "_gpl");
SYMBOL_CRC(dm_block_location, 0x5475ba9e, "_gpl");
SYMBOL_CRC(dm_block_data, 0x1e3f728d, "_gpl");
SYMBOL_CRC(dm_block_manager_create, 0xb654f935, "_gpl");
SYMBOL_CRC(dm_block_manager_destroy, 0x72289260, "_gpl");
SYMBOL_CRC(dm_bm_block_size, 0x688d422d, "_gpl");
SYMBOL_CRC(dm_bm_read_lock, 0x7b6b3af5, "_gpl");
SYMBOL_CRC(dm_bm_write_lock, 0x5375ca71, "_gpl");
SYMBOL_CRC(dm_bm_write_lock_zero, 0x30c37cc0, "_gpl");
SYMBOL_CRC(dm_bm_unlock, 0x48e323be, "_gpl");
SYMBOL_CRC(dm_bm_flush, 0x3ad0f55b, "_gpl");
SYMBOL_CRC(dm_bm_is_read_only, 0x95a52abd, "_gpl");
SYMBOL_CRC(dm_bm_set_read_only, 0x9e798e22, "_gpl");
SYMBOL_CRC(dm_bm_set_read_write, 0x2f40da68, "_gpl");
SYMBOL_CRC(dm_bm_checksum, 0x4f477261, "_gpl");
SYMBOL_CRC(dm_sm_disk_create, 0x79bdc649, "_gpl");
SYMBOL_CRC(dm_sm_disk_open, 0x9718cffa, "_gpl");
SYMBOL_CRC(dm_tm_create_non_blocking_clone, 0x7b047bd9, "_gpl");
SYMBOL_CRC(dm_tm_destroy, 0x7ade1071, "_gpl");
SYMBOL_CRC(dm_tm_pre_commit, 0x0054f69d, "_gpl");
SYMBOL_CRC(dm_tm_commit, 0xd163cade, "_gpl");
SYMBOL_CRC(dm_tm_shadow_block, 0x932a6ffc, "_gpl");
SYMBOL_CRC(dm_tm_read_lock, 0x9290e07a, "_gpl");
SYMBOL_CRC(dm_tm_unlock, 0x88295b96, "_gpl");
SYMBOL_CRC(dm_tm_inc, 0x87c934be, "_gpl");
SYMBOL_CRC(dm_tm_inc_range, 0x3ae50a4a, "_gpl");
SYMBOL_CRC(dm_tm_dec, 0xe781f874, "_gpl");
SYMBOL_CRC(dm_tm_dec_range, 0x1ae16d40, "_gpl");
SYMBOL_CRC(dm_tm_with_runs, 0x8db6f8f0, "_gpl");
SYMBOL_CRC(dm_tm_issue_prefetches, 0x3646e38f, "_gpl");
SYMBOL_CRC(dm_tm_create_with_sm, 0xdf3a4e7d, "_gpl");
SYMBOL_CRC(dm_tm_open_with_sm, 0x2bc1a8d9, "_gpl");
SYMBOL_CRC(dm_btree_empty, 0xf82dba90, "_gpl");
SYMBOL_CRC(dm_btree_del, 0x586705e1, "_gpl");
SYMBOL_CRC(dm_btree_lookup, 0x75606d09, "_gpl");
SYMBOL_CRC(dm_btree_lookup_next, 0xb6879c01, "_gpl");
SYMBOL_CRC(dm_btree_insert, 0x3d6961ed, "_gpl");
SYMBOL_CRC(dm_btree_insert_notify, 0xa9cf611b, "_gpl");
SYMBOL_CRC(dm_btree_find_highest_key, 0x1816383d, "_gpl");
SYMBOL_CRC(dm_btree_find_lowest_key, 0x2c5a02df, "_gpl");
SYMBOL_CRC(dm_btree_walk, 0x8f5eefee, "_gpl");
SYMBOL_CRC(dm_btree_cursor_begin, 0x15085586, "_gpl");
SYMBOL_CRC(dm_btree_cursor_end, 0x7bc7621f, "_gpl");
SYMBOL_CRC(dm_btree_cursor_next, 0xc36559ad, "_gpl");
SYMBOL_CRC(dm_btree_cursor_skip, 0x7062014c, "_gpl");
SYMBOL_CRC(dm_btree_cursor_get_value, 0xd39c0246, "_gpl");
SYMBOL_CRC(dm_btree_remove, 0x30a26537, "_gpl");
SYMBOL_CRC(dm_btree_remove_leaves, 0x46768dbf, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xb0e602eb, "memmove" },
	{ 0x6d3f57bd, "dm_bufio_get_client" },
	{ 0xc90df7e5, "dm_bufio_prefetch" },
	{ 0x24772bfe, "dm_bufio_get" },
	{ 0xad0dc4f, "dm_bufio_mark_buffer_dirty" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb04f56ab, "dm_bufio_read" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2e0774dc, "dm_bufio_get_block_number" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xeca7949e, "dm_bufio_client_destroy" },
	{ 0xebcc64a4, "dm_bufio_get_block_data" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x3d86bedc, "dm_bufio_client_create" },
	{ 0xe6024e59, "dm_bufio_release" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x7c381a76, "dm_bufio_get_block_size" },
	{ 0xfb578fc5, "memset" },
	{ 0x6d606913, "pv_ops" },
	{ 0xb15b4109, "crc32c" },
	{ 0xa82b2066, "dm_bufio_write_dirty_buffers" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xc0d7df85, "dm_bufio_new" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xd991e3b9, "dm_bufio_get_device_size" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x74dcd98c, "dm_bufio_get_aux_data" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dm-bufio,libcrc32c");


MODULE_INFO(srcversion, "DF4419032177883A510A86A");
