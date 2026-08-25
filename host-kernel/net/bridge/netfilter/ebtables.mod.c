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

SYMBOL_CRC(ebt_register_template, 0x2a1ed665, "");
SYMBOL_CRC(ebt_unregister_template, 0x6a5bacf3, "");
SYMBOL_CRC(ebt_unregister_table_pre_exit, 0x8617fa12, "");
SYMBOL_CRC(ebt_register_table, 0x252f6ea6, "");
SYMBOL_CRC(ebt_unregister_table, 0x8e835ca5, "");
SYMBOL_CRC(ebt_do_table, 0xc5ccdab5, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xc7fae024, "xt_compat_calc_jump" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb9db451f, "xt_find_match" },
	{ 0x1de23e95, "module_put" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xbb5600e2, "xt_check_match" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xb6115b4e, "xt_request_find_target" },
	{ 0xc7b94877, "xt_check_target" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0xbef6f2b0, "xt_compat_target_offset" },
	{ 0xa916b694, "strnlen" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7bce4603, "xt_data_to_user" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x999e8297, "vfree" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xdd64e639, "strscpy" },
	{ 0xfb578fc5, "memset" },
	{ 0x98202308, "xt_request_find_match" },
	{ 0x74df37ad, "xt_compat_match_offset" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x823edea5, "xt_compat_add_offset" },
	{ 0x618911fc, "numa_node" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x23fd3028, "vmalloc_node" },
	{ 0x50873741, "xt_compat_init_offsets" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x92997ed8, "_printk" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x56470118, "__warn_printk" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb44e18ea, "audit_enabled" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9968aacb, "__audit_log_nfcfg" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xa7c94f1d, "xt_compat_lock" },
	{ 0x4e27719, "xt_compat_flush_offsets" },
	{ 0xd1e246a2, "xt_compat_unlock" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x86490580, "current_task" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xae04012c, "__vmalloc" },
	{ 0x67a704bf, "xt_register_target" },
	{ 0x3fb130e, "nf_register_sockopt" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x4490c46c, "nf_unregister_sockopt" },
	{ 0xa5d0ece2, "xt_unregister_target" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "5875F44E26C32982A94FB3E");
