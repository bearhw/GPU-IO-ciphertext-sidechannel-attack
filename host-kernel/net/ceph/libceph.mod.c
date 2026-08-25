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

SYMBOL_CRC(libceph_compatible, 0x466b85b8, "");
SYMBOL_CRC(ceph_msg_type_name, 0xb54676fa, "");
SYMBOL_CRC(ceph_check_fsid, 0x8337490a, "");
SYMBOL_CRC(ceph_compare_options, 0x35623dd4, "");
SYMBOL_CRC(ceph_parse_fsid, 0x4affd6c2, "");
SYMBOL_CRC(ceph_alloc_options, 0x987d3968, "");
SYMBOL_CRC(ceph_destroy_options, 0xd4d736db, "");
SYMBOL_CRC(ceph_parse_mon_ips, 0x5fdcc6a5, "");
SYMBOL_CRC(ceph_parse_param, 0x1fd71316, "");
SYMBOL_CRC(ceph_print_client_options, 0xcbbb5ba2, "");
SYMBOL_CRC(ceph_client_addr, 0xd50396fa, "");
SYMBOL_CRC(ceph_client_gid, 0xccc338a4, "");
SYMBOL_CRC(ceph_create_client, 0x897572dc, "");
SYMBOL_CRC(ceph_destroy_client, 0x416cd313, "");
SYMBOL_CRC(ceph_reset_client_addr, 0x1ee5968b, "");
SYMBOL_CRC(__ceph_open_session, 0x67b530a1, "");
SYMBOL_CRC(ceph_open_session, 0x15007b86, "");
SYMBOL_CRC(ceph_wait_for_latest_osdmap, 0xfc868706, "");
SYMBOL_CRC(ceph_pr_addr, 0x6a7a38a0, "");
SYMBOL_CRC(ceph_msgr_flush, 0xafb8a407, "");
SYMBOL_CRC(ceph_con_close, 0xe6ec3f38, "");
SYMBOL_CRC(ceph_con_open, 0xdbd890ac, "");
SYMBOL_CRC(ceph_con_init, 0x896dc9c9, "");
SYMBOL_CRC(ceph_con_send, 0x94482531, "");
SYMBOL_CRC(ceph_con_keepalive, 0x186c1918, "");
SYMBOL_CRC(ceph_msg_data_add_pages, 0x841c6ed2, "");
SYMBOL_CRC(ceph_msg_data_add_pagelist, 0x94eaabf3, "");
SYMBOL_CRC(ceph_msg_data_add_bio, 0x20f64eb6, "");
SYMBOL_CRC(ceph_msg_data_add_bvecs, 0xb570680e, "");
SYMBOL_CRC(ceph_msg_new2, 0xeb052d7e, "");
SYMBOL_CRC(ceph_msg_new, 0x841ca47a, "");
SYMBOL_CRC(ceph_msg_get, 0x8e9155b9, "");
SYMBOL_CRC(ceph_msg_put, 0x2bed0961, "");
SYMBOL_CRC(ceph_msg_dump, 0xd52b951a, "");
SYMBOL_CRC(ceph_buffer_new, 0x9fbba67f, "");
SYMBOL_CRC(ceph_buffer_release, 0xb72c162e, "");
SYMBOL_CRC(ceph_pagelist_alloc, 0xe76e7226, "");
SYMBOL_CRC(ceph_pagelist_release, 0x2a983d26, "");
SYMBOL_CRC(ceph_pagelist_append, 0xefce991c, "");
SYMBOL_CRC(ceph_pagelist_reserve, 0xefce3c3b, "");
SYMBOL_CRC(ceph_pagelist_free_reserve, 0x165b1948, "");
SYMBOL_CRC(ceph_pagelist_set_cursor, 0xf03fe862, "");
SYMBOL_CRC(ceph_pagelist_truncate, 0xc366bfa1, "");
SYMBOL_CRC(ceph_monc_want_map, 0x296a69a5, "");
SYMBOL_CRC(ceph_monc_got_map, 0x9b293eb2, "");
SYMBOL_CRC(ceph_monc_renew_subs, 0x6db8b9cc, "");
SYMBOL_CRC(ceph_monc_wait_osdmap, 0x3823b577, "");
SYMBOL_CRC(ceph_monc_open_session, 0x6770ea59, "");
SYMBOL_CRC(ceph_monc_do_statfs, 0x578fd726, "");
SYMBOL_CRC(ceph_monc_get_version, 0x4cc1fbcf, "");
SYMBOL_CRC(ceph_monc_get_version_async, 0x8219a177, "");
SYMBOL_CRC(ceph_monc_blocklist_add, 0xad4c40b9, "");
SYMBOL_CRC(ceph_monc_init, 0xd690db6c, "");
SYMBOL_CRC(ceph_monc_stop, 0x77e8d8d1, "");
SYMBOL_CRC(ceph_monc_validate_auth, 0xc2aa3ebc, "");
SYMBOL_CRC(ceph_decode_entity_addr, 0xd4eb7735, "");
SYMBOL_CRC(ceph_decode_entity_addrvec, 0x50603ce3, "");
SYMBOL_CRC(ceph_cls_lock, 0x2c451792, "");
SYMBOL_CRC(ceph_cls_unlock, 0x00170999, "");
SYMBOL_CRC(ceph_cls_break_lock, 0x1ebf9b72, "");
SYMBOL_CRC(ceph_cls_set_cookie, 0xb96851e1, "");
SYMBOL_CRC(ceph_free_lockers, 0xa698f998, "");
SYMBOL_CRC(ceph_cls_lock_info, 0x6d95ad27, "");
SYMBOL_CRC(ceph_cls_assert_locked, 0xe5d7e37a, "");
SYMBOL_CRC(osd_req_op_extent_osd_data, 0x811d4448, "");
SYMBOL_CRC(osd_req_op_raw_data_in_pages, 0x9c7bfa05, "");
SYMBOL_CRC(osd_req_op_extent_osd_data_pages, 0xb2b2baea, "");
SYMBOL_CRC(osd_req_op_extent_osd_data_pagelist, 0xcbf65afe, "");
SYMBOL_CRC(osd_req_op_extent_osd_data_bio, 0x2f6a7c69, "");
SYMBOL_CRC(osd_req_op_extent_osd_data_bvecs, 0x079e69ea, "");
SYMBOL_CRC(osd_req_op_extent_osd_data_bvec_pos, 0xe60ecefa, "");
SYMBOL_CRC(osd_req_op_cls_request_data_pagelist, 0x21261147, "");
SYMBOL_CRC(osd_req_op_cls_request_data_pages, 0xe69d7cb0, "");
SYMBOL_CRC(osd_req_op_cls_request_data_bvecs, 0x584fe885, "");
SYMBOL_CRC(osd_req_op_cls_response_data_pages, 0x72e2a6bc, "");
SYMBOL_CRC(ceph_osdc_get_request, 0x95f92b2a, "");
SYMBOL_CRC(ceph_osdc_put_request, 0xbc77c55d, "");
SYMBOL_CRC(ceph_osdc_alloc_request, 0x0e3c14db, "");
SYMBOL_CRC(ceph_osdc_alloc_messages, 0x0c014c37, "");
SYMBOL_CRC(osd_req_op_init, 0x7e47bee9, "");
SYMBOL_CRC(osd_req_op_extent_init, 0xbb3e108c, "");
SYMBOL_CRC(osd_req_op_extent_update, 0x29dcd8cc, "");
SYMBOL_CRC(osd_req_op_extent_dup_last, 0xf61f60ef, "");
SYMBOL_CRC(osd_req_op_cls_init, 0xb062b565, "");
SYMBOL_CRC(osd_req_op_xattr_init, 0x1e20b1fa, "");
SYMBOL_CRC(osd_req_op_alloc_hint_init, 0xd758200b, "");
SYMBOL_CRC(ceph_osdc_new_request, 0x8625d078, "");
SYMBOL_CRC(ceph_osdc_abort_requests, 0x3529684d, "");
SYMBOL_CRC(ceph_osdc_clear_abort_err, 0x45e7024c, "");
SYMBOL_CRC(ceph_osdc_update_epoch_barrier, 0xc9b06b57, "");
SYMBOL_CRC(ceph_osdc_start_request, 0x9584a57c, "");
SYMBOL_CRC(ceph_osdc_cancel_request, 0xd959a2a9, "");
SYMBOL_CRC(ceph_osdc_wait_request, 0x23b256cc, "");
SYMBOL_CRC(ceph_osdc_sync, 0x470980d8, "");
SYMBOL_CRC(ceph_osdc_watch, 0x83ae6b20, "");
SYMBOL_CRC(ceph_osdc_unwatch, 0x9e00e099, "");
SYMBOL_CRC(ceph_osdc_notify_ack, 0xc7d2adf6, "");
SYMBOL_CRC(ceph_osdc_notify, 0x71d2b1f7, "");
SYMBOL_CRC(ceph_osdc_list_watchers, 0xc4b66306, "");
SYMBOL_CRC(ceph_osdc_flush_notifies, 0xcf061351, "");
SYMBOL_CRC(ceph_osdc_maybe_request_map, 0x33201781, "");
SYMBOL_CRC(ceph_osdc_call, 0x7349c29d, "");
SYMBOL_CRC(osd_req_op_copy_from_init, 0xf02d7c59, "");
SYMBOL_CRC(ceph_pg_pool_name_by_id, 0x1378aba3, "");
SYMBOL_CRC(ceph_pg_poolid_by_name, 0x04cad6f0, "");
SYMBOL_CRC(ceph_pg_pool_flags, 0x92b7b4ce, "");
SYMBOL_CRC(ceph_oloc_copy, 0xbd2f79ae, "");
SYMBOL_CRC(ceph_oloc_destroy, 0x417a9131, "");
SYMBOL_CRC(ceph_oid_copy, 0x2087719e, "");
SYMBOL_CRC(ceph_oid_printf, 0xdf6ef4a1, "");
SYMBOL_CRC(ceph_oid_aprintf, 0x5aeeee62, "");
SYMBOL_CRC(ceph_oid_destroy, 0x2101cbc9, "");
SYMBOL_CRC(ceph_object_locator_to_pg, 0xe34a59f2, "");
SYMBOL_CRC(ceph_pg_to_acting_primary, 0x17c17611, "");
SYMBOL_CRC(ceph_calc_file_object_mapping, 0x9fefa3cb, "");
SYMBOL_CRC(ceph_file_to_extents, 0x38f2d94e, "");
SYMBOL_CRC(ceph_iterate_extents, 0xeef6cfa3, "");
SYMBOL_CRC(ceph_extent_to_file, 0xca80437b, "");
SYMBOL_CRC(ceph_get_num_objects, 0x3c8d7111, "");
SYMBOL_CRC(ceph_auth_is_authenticated, 0xb4af4827, "");
SYMBOL_CRC(__ceph_auth_get_authorizer, 0xf8cb8c1f, "");
SYMBOL_CRC(ceph_auth_destroy_authorizer, 0xad703657, "");
SYMBOL_CRC(ceph_auth_add_authorizer_challenge, 0x6bc89848, "");
SYMBOL_CRC(ceph_auth_verify_authorizer_reply, 0x6864d423, "");
SYMBOL_CRC(ceph_auth_invalidate_authorizer, 0x8fb85c19, "");
SYMBOL_CRC(ceph_auth_get_authorizer, 0x887ab0e9, "");
SYMBOL_CRC(ceph_auth_handle_svc_reply_more, 0x7b7769a0, "");
SYMBOL_CRC(ceph_auth_handle_svc_reply_done, 0x1bb860d5, "");
SYMBOL_CRC(ceph_auth_handle_bad_authorizer, 0x1359b3c6, "");
SYMBOL_CRC(ceph_entity_type_name, 0xdfc091f9, "");
SYMBOL_CRC(ceph_str_hash, 0x57baf885, "");
SYMBOL_CRC(ceph_str_hash_name, 0x63758856, "");
SYMBOL_CRC(ceph_put_page_vector, 0xd4be4170, "");
SYMBOL_CRC(ceph_release_page_vector, 0x0f9e56f7, "");
SYMBOL_CRC(ceph_alloc_page_vector, 0x43a4e437, "");
SYMBOL_CRC(ceph_copy_user_to_page_vector, 0x33b1bd5b, "");
SYMBOL_CRC(ceph_copy_to_page_vector, 0x90dce594, "");
SYMBOL_CRC(ceph_copy_from_page_vector, 0x854248ef, "");
SYMBOL_CRC(ceph_zero_page_vector_range, 0x29981535, "");
SYMBOL_CRC(ceph_create_snap_context, 0x9ca95932, "");
SYMBOL_CRC(ceph_get_snap_context, 0xbe3879aa, "");
SYMBOL_CRC(ceph_put_snap_context, 0x86fca7e4, "");
SYMBOL_CRC(ceph_find_or_create_string, 0x9bc6b539, "");
SYMBOL_CRC(ceph_release_string, 0xee120c03, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xddf6ad7a, "completion_done" },
	{ 0x10795da2, "__put_page" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xf6c7e5a4, "tcp_sock_set_cork" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x78b887ed, "vsprintf" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x16161009, "fs_param_is_string" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0xb0e602eb, "memmove" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0xca9360b5, "rb_next" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xcc4e4b3c, "iov_iter_advance" },
	{ 0x609bcd98, "in6_pton" },
	{ 0x849180c0, "unregister_key_type" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x1eb9516e, "round_jiffies_relative" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xf0b65f4c, "fs_param_is_enum" },
	{ 0xd5244492, "logfc" },
	{ 0xa5577939, "crypto_alloc_aead" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0x148653, "vsnprintf" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x23c1e0f, "register_key_type" },
	{ 0xc3ff38c2, "down_read_trylock" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x284faa6b, "__x86_indirect_thunk_r11" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x358e7605, "fs_param_is_u32" },
	{ 0x815f2897, "empty_zero_page" },
	{ 0x92997ed8, "_printk" },
	{ 0x1953c958, "mempool_create" },
	{ 0xac5fcec0, "in4_pton" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xa1ebc4ea, "filemap_alloc_folio" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x7778b4ff, "dns_query" },
	{ 0xfcb20a4, "seq_escape_mem" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0x30933ff0, "key_put" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x78041b8f, "byte_rev_table" },
	{ 0x57bc19d2, "down_write" },
	{ 0xc131710d, "crypto_req_done" },
	{ 0xce807a25, "up_write" },
	{ 0x755b14b4, "crypto_shash_setkey" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0xa07a37f0, "memchr" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x5a921311, "strncmp" },
	{ 0xa906274e, "seq_putc" },
	{ 0x365acda7, "set_normalized_timespec64" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x7971b0bb, "iov_iter_kvec" },
	{ 0x2e3bcce2, "wait_for_completion_interruptible" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xa59392e1, "sock_sendmsg" },
	{ 0xc77b4f92, "crypto_shash_update" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x86490580, "current_task" },
	{ 0x11089ac7, "_ctype" },
	{ 0xd319981b, "tcp_stream_memory_free" },
	{ 0x558e68f5, "sg_alloc_table_from_pages_segment" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xfb578fc5, "memset" },
	{ 0xd9aa2171, "iov_iter_bvec" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xc972449f, "mempool_alloc_slab" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0xece784c2, "rb_first" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0x79e8fe8c, "crypto_alloc_sync_skcipher" },
	{ 0x5a44f8cb, "__crypto_memneq" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf2b11959, "seq_read" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xb15b4109, "crc32c" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x9265315, "crypto_shash_final" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xcf78d1e6, "sock_create_kern" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x726bc3c7, "wait_for_completion_killable_timeout" },
	{ 0xedcdca80, "request_key_tag" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x87b8798d, "sg_next" },
	{ 0x21cb898, "generic_key_instantiate" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x9034a696, "mempool_destroy" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x66b5d182, "sock_recvmsg" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x943ea161, "set_page_dirty_lock" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x287a4665, "iov_iter_discard" },
	{ 0x18888d00, "downgrade_write" },
	{ 0x391de184, "seq_puts" },
	{ 0xbb2b861a, "single_release" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xb2340e65, "tcp_sock_set_nodelay" },
	{ 0x9e4d8096, "__fs_parse" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x742578a5, "wait_for_random_bytes" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xb82ba28c, "single_open" },
	{ 0x349cba85, "strchr" },
	{ 0xbacc0824, "crypto_alloc_shash" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0x53b954a2, "up_read" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x188ea314, "jiffies_to_timespec64" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libcrc32c");


MODULE_INFO(srcversion, "35832B9F37F340CFB69A122");
