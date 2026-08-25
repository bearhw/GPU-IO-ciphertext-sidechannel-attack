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

SYMBOL_CRC(iscsi_find_param_from_key, 0xf34332f0, "");
SYMBOL_CRC(iscsit_get_datain_values, 0xb16fbaee, "");
SYMBOL_CRC(iscsit_increment_maxcmdsn, 0x387e3a0a, "");
SYMBOL_CRC(iscsit_cause_connection_reinstatement, 0x025c8470, "");
SYMBOL_CRC(iscsit_stop_dataout_timer, 0xaa97775c, "");
SYMBOL_CRC(iscsi_change_param_sprintf, 0x541d5635, "");
SYMBOL_CRC(iscsi_target_check_login_request, 0xa2758f29, "");
SYMBOL_CRC(iscsit_tmr_post_handler, 0xec7689ba, "");
SYMBOL_CRC(iscsit_allocate_cmd, 0x28e2482f, "");
SYMBOL_CRC(iscsit_sequence_cmd, 0xefa78c65, "");
SYMBOL_CRC(iscsit_find_cmd_from_itt, 0xbea6d845, "");
SYMBOL_CRC(iscsit_find_cmd_from_itt_or_dump, 0xa79cc6ef, "");
SYMBOL_CRC(iscsit_add_cmd_to_immediate_queue, 0x633f7914, "");
SYMBOL_CRC(iscsit_release_cmd, 0xd773566a, "");
SYMBOL_CRC(iscsit_free_cmd, 0x5d350f5c, "");
SYMBOL_CRC(iscsit_queue_rsp, 0xcc215396, "");
SYMBOL_CRC(iscsit_aborted_task, 0x2baa2683, "");
SYMBOL_CRC(iscsit_add_reject, 0xd081686c, "");
SYMBOL_CRC(iscsit_reject_cmd, 0xa42b1947, "");
SYMBOL_CRC(iscsit_setup_scsi_cmd, 0x30d55d53, "");
SYMBOL_CRC(iscsit_set_unsolicited_dataout, 0xafbd7d9b, "");
SYMBOL_CRC(iscsit_process_scsi_cmd, 0xb9f1b6cc, "");
SYMBOL_CRC(__iscsit_check_dataout_hdr, 0x53a2c6fc, "");
SYMBOL_CRC(iscsit_check_dataout_hdr, 0xd2941706, "");
SYMBOL_CRC(iscsit_check_dataout_payload, 0x2758dc19, "");
SYMBOL_CRC(iscsit_setup_nop_out, 0x5dcd3f54, "");
SYMBOL_CRC(iscsit_process_nop_out, 0x9b99786a, "");
SYMBOL_CRC(iscsit_handle_task_mgt_cmd, 0xa428eda2, "");
SYMBOL_CRC(iscsit_setup_text_cmd, 0x6cd314c0, "");
SYMBOL_CRC(iscsit_process_text_cmd, 0x4ad50087, "");
SYMBOL_CRC(iscsit_handle_logout_cmd, 0xdad1bbd8, "");
SYMBOL_CRC(iscsit_handle_snack, 0xf7ca011d, "");
SYMBOL_CRC(iscsit_build_datain_pdu, 0xa59cd11d, "");
SYMBOL_CRC(iscsit_build_logout_rsp, 0x5bfb3333, "");
SYMBOL_CRC(iscsit_build_nopin_rsp, 0x4b895a0e, "");
SYMBOL_CRC(iscsit_build_r2ts_for_cmd, 0xfa3db473, "");
SYMBOL_CRC(iscsit_build_rsp_pdu, 0x975962d6, "");
SYMBOL_CRC(iscsit_build_task_mgt_rsp, 0x2c99ec01, "");
SYMBOL_CRC(iscsit_build_text_rsp, 0x5414dc07, "");
SYMBOL_CRC(iscsit_build_reject, 0x685d8816, "");
SYMBOL_CRC(iscsit_thread_check_cpumask, 0xa9c29f67, "");
SYMBOL_CRC(iscsit_immediate_queue, 0xddb99393, "");
SYMBOL_CRC(iscsit_response_queue, 0x21936970, "");
SYMBOL_CRC(iscsit_logout_post_handler, 0x20673cc9, "");
SYMBOL_CRC(iscsit_register_transport, 0xefa19b8f, "");
SYMBOL_CRC(iscsit_unregister_transport, 0x1c3b957b, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xc941264c, "crypto_alloc_ahash" },
	{ 0xe914e41e, "strcpy" },
	{ 0x1b015d25, "bitmap_parselist" },
	{ 0x4e717dc0, "core_alua_check_nonop_delay" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x628bc7ff, "transport_generic_new_cmd" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x3abcdffb, "crypto_stats_get" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0x9db2f5e1, "target_execute_cmd" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xbd9acb3b, "kernel_bind" },
	{ 0xcf2a6966, "up" },
	{ 0xd72a9f53, "sock_create" },
	{ 0x6df1aaf1, "kernel_sigaction" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x5ed90adc, "int_to_scsilun" },
	{ 0x39b52d19, "__bitmap_and" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xf4206108, "kernel_accept" },
	{ 0x148653, "vsnprintf" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x364ab031, "core_tpg_set_initiator_node_queue_depth" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc93ffbbd, "transport_generic_handle_tmr" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x7aca4af8, "transport_lookup_tmr_lun" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x50cf7585, "hex2bin" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x6d11488, "__bitmap_equal" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x89d1ee5c, "transport_alloc_session_tags" },
	{ 0x79bb909, "transport_alloc_session" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x4af6ddf0, "kstrtou16" },
	{ 0x574c2e74, "bitmap_release_region" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xf8783b43, "sbitmap_prepare_to_wait" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x5085599b, "target_unregister_template" },
	{ 0xe3ffa071, "transport_send_check_condition_and_sense" },
	{ 0xa916b694, "strnlen" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x989bb726, "transport_free_session" },
	{ 0xc6cbbc89, "capable" },
	{ 0x1de23e95, "module_put" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0x61e876a5, "flush_signals" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x7c6024bd, "init_net" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xb3f548ad, "kmemdup_nul" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x8bc8cc11, "config_group_init_type_name" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x954f099c, "idr_preload" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x10a9c624, "set_cpus_allowed_ptr" },
	{ 0x5792f848, "strlcpy" },
	{ 0x7f026ac, "transport_deregister_session_configfs" },
	{ 0x5a921311, "strncmp" },
	{ 0xff80f59, "zalloc_cpumask_var" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x5a42c937, "sbitmap_queue_clear" },
	{ 0x7971b0bb, "iov_iter_kvec" },
	{ 0xffb7c514, "ida_free" },
	{ 0x2e3bcce2, "wait_for_completion_interruptible" },
	{ 0x8d6713c, "inet_pton_with_scope" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xa59392e1, "sock_sendmsg" },
	{ 0xc77b4f92, "crypto_shash_update" },
	{ 0x977165e6, "core_tpg_set_initiator_node_tag" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x86490580, "current_task" },
	{ 0x11089ac7, "_ctype" },
	{ 0xd67c7de1, "target_cmd_parse_cdb" },
	{ 0x71afa9ed, "sock_set_reuseaddr" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x83bc8b71, "crypto_ahash_finup" },
	{ 0xfb578fc5, "memset" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x347da517, "crypto_ahash_digest" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0x7e9b64ed, "crypto_ahash_final" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xb4cc8898, "__target_init_cmd" },
	{ 0xb86f74c5, "free_cpumask_var" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0xce1f2e9c, "transport_lookup_cmd_lun" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x87aac2f8, "core_tpg_check_initiator_node_acl" },
	{ 0x423defb2, "target_cmd_init_cdb" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xcd89d757, "kernel_listen" },
	{ 0x4163bd28, "core_tmr_alloc_req" },
	{ 0x999e8297, "vfree" },
	{ 0xd1b40a72, "ip_sock_set_freebind" },
	{ 0xea3c8e4e, "scsilun_to_int" },
	{ 0x9c311926, "sbitmap_finish_wait" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x80b75976, "crypto_shash_finup" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xa9a4ef21, "transport_wait_for_tasks" },
	{ 0xd45cc6ca, "bin2hex" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x63a7c28c, "bitmap_find_free_region" },
	{ 0x654b4a33, "transport_handle_cdb_direct" },
	{ 0x1155806f, "target_get_sess_cmd" },
	{ 0x87b8798d, "sg_next" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x66b5d182, "sock_recvmsg" },
	{ 0x590775d8, "core_tpg_deregister" },
	{ 0x6bd0e573, "down_interruptible" },
	{ 0xf5c45043, "__transport_register_session" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xb3eec32, "target_show_dynamic_sessions" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x6e5c0971, "sock_release" },
	{ 0xd2719129, "target_register_template" },
	{ 0x3498d552, "crypto_stats_ahash_update" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xb2340e65, "tcp_sock_set_nodelay" },
	{ 0xe71c4fef, "send_sig" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x5a207c8d, "transport_generic_free_cmd" },
	{ 0x3854774b, "kstrtoll" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3464c940, "core_tpg_register" },
	{ 0x754d539c, "strlen" },
	{ 0x4ed847b6, "target_put_sess_cmd" },
	{ 0x742578a5, "wait_for_random_bytes" },
	{ 0xd67475d7, "transport_deregister_session" },
	{ 0xe613a798, "inet_addr_is_any" },
	{ 0x349cba85, "strchr" },
	{ 0xbacc0824, "crypto_alloc_shash" },
	{ 0x3288b93b, "__sbitmap_queue_get" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x380a781d, "target_tpg_has_node_acl" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "target_core_mod");


MODULE_INFO(srcversion, "9699189AC9F803728DF59E3");
