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

SYMBOL_CRC(xt_register_target, 0x67a704bf, "");
SYMBOL_CRC(xt_unregister_target, 0xa5d0ece2, "");
SYMBOL_CRC(xt_register_targets, 0x7b7451f4, "");
SYMBOL_CRC(xt_unregister_targets, 0x8b4eba64, "");
SYMBOL_CRC(xt_register_match, 0x97fcf9f5, "");
SYMBOL_CRC(xt_unregister_match, 0x8ae43d15, "");
SYMBOL_CRC(xt_register_matches, 0x7ec922ce, "");
SYMBOL_CRC(xt_unregister_matches, 0x4bb1f65e, "");
SYMBOL_CRC(xt_find_match, 0xb9db451f, "");
SYMBOL_CRC(xt_request_find_match, 0x98202308, "_gpl");
SYMBOL_CRC(xt_request_find_target, 0xb6115b4e, "_gpl");
SYMBOL_CRC(xt_data_to_user, 0x7bce4603, "_gpl");
SYMBOL_CRC(xt_match_to_user, 0xf53b9f2c, "_gpl");
SYMBOL_CRC(xt_target_to_user, 0x483b0fa6, "_gpl");
SYMBOL_CRC(xt_find_revision, 0xddf68fc6, "_gpl");
SYMBOL_CRC(xt_check_proc_name, 0x48012e28, "");
SYMBOL_CRC(xt_check_match, 0xbb5600e2, "_gpl");
SYMBOL_CRC(xt_check_table_hooks, 0x3bf9d084, "");
SYMBOL_CRC(xt_compat_add_offset, 0x823edea5, "_gpl");
SYMBOL_CRC(xt_compat_flush_offsets, 0x04e27719, "_gpl");
SYMBOL_CRC(xt_compat_calc_jump, 0xc7fae024, "_gpl");
SYMBOL_CRC(xt_compat_init_offsets, 0x50873741, "");
SYMBOL_CRC(xt_compat_match_offset, 0x74df37ad, "_gpl");
SYMBOL_CRC(xt_compat_match_from_user, 0x2925b011, "_gpl");
SYMBOL_CRC(xt_compat_match_to_user, 0x96d28eb7, "_gpl");
SYMBOL_CRC(xt_compat_check_entry_offsets, 0xa25fc115, "");
SYMBOL_CRC(xt_check_entry_offsets, 0xd87ae60d, "");
SYMBOL_CRC(xt_alloc_entry_offsets, 0x0d7f5fcd, "");
SYMBOL_CRC(xt_find_jump_offset, 0xfef779fa, "");
SYMBOL_CRC(xt_check_target, 0xc7b94877, "_gpl");
SYMBOL_CRC(xt_copy_counters, 0xd9bb821b, "_gpl");
SYMBOL_CRC(xt_compat_target_offset, 0xbef6f2b0, "_gpl");
SYMBOL_CRC(xt_compat_target_from_user, 0x1dd2ecdf, "_gpl");
SYMBOL_CRC(xt_compat_target_to_user, 0x413b423e, "_gpl");
SYMBOL_CRC(xt_alloc_table_info, 0x977fd4bf, "");
SYMBOL_CRC(xt_free_table_info, 0xe204e042, "");
SYMBOL_CRC(xt_find_table, 0xa10ec8d9, "");
SYMBOL_CRC(xt_find_table_lock, 0xd064f936, "_gpl");
SYMBOL_CRC(xt_request_find_table_lock, 0xc5f6dd9c, "_gpl");
SYMBOL_CRC(xt_table_unlock, 0x13d3e9a8, "_gpl");
SYMBOL_CRC(xt_compat_lock, 0xa7c94f1d, "_gpl");
SYMBOL_CRC(xt_compat_unlock, 0xd1e246a2, "_gpl");
SYMBOL_CRC(xt_recseq, 0x807d2b2c, "_gpl");
SYMBOL_CRC(xt_tee_enabled, 0xd3fcc511, "_gpl");
SYMBOL_CRC(xt_counters_alloc, 0xcb3e91cc, "");
SYMBOL_CRC(xt_replace_table, 0xa56c403e, "_gpl");
SYMBOL_CRC(xt_register_table, 0x97e73427, "_gpl");
SYMBOL_CRC(xt_unregister_table, 0xb0c23a4d, "_gpl");
SYMBOL_CRC(xt_hook_ops_alloc, 0x6dfcff39, "_gpl");
SYMBOL_CRC(xt_register_template, 0x0c16f7ad, "_gpl");
SYMBOL_CRC(xt_unregister_template, 0x2146cc7c, "_gpl");
SYMBOL_CRC(xt_proto_init, 0x739dde36, "_gpl");
SYMBOL_CRC(xt_proto_fini, 0x2adad0c1, "_gpl");
SYMBOL_CRC(xt_percpu_counter_alloc, 0x9c995c69, "_gpl");
SYMBOL_CRC(xt_percpu_counter_free, 0xbfacb837, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa916b694, "strnlen" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0x754d539c, "strlen" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0x349cba85, "strchr" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x999e8297, "vfree" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1de23e95, "module_put" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x69acdf38, "memcpy" },
	{ 0x9166fada, "strncpy" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xb44e18ea, "audit_enabled" },
	{ 0x37a0cba, "kfree" },
	{ 0x9968aacb, "__audit_log_nfcfg" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0x9ad2c4fe, "proc_set_user" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xe7d4daac, "seq_list_next" },
	{ 0xff1e9dd8, "seq_list_start" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x618911fc, "numa_node" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x800473f, "__cond_resched" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xd8cef6e1, "clear_user" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xdd64e639, "strscpy" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x86490580, "current_task" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "602DB6A32E8433D17901C04");
