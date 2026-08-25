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

SYMBOL_CRC(ipt_alloc_initial_table, 0xa3f92fb8, "_gpl");
SYMBOL_CRC(ipt_register_table, 0xe29834a6, "");
SYMBOL_CRC(ipt_unregister_table_pre_exit, 0x1a69506b, "");
SYMBOL_CRC(ipt_unregister_table_exit, 0x7c68ce19, "");
SYMBOL_CRC(ipt_do_table, 0x9456f63b, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa10ec8d9, "xt_find_table" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0x50873741, "xt_compat_init_offsets" },
	{ 0x74df37ad, "xt_compat_match_offset" },
	{ 0xbef6f2b0, "xt_compat_target_offset" },
	{ 0x823edea5, "xt_compat_add_offset" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc7fae024, "xt_compat_calc_jump" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2adad0c1, "xt_proto_fini" },
	{ 0x739dde36, "xt_proto_init" },
	{ 0x9c995c69, "xt_percpu_counter_alloc" },
	{ 0x98202308, "xt_request_find_match" },
	{ 0xbb5600e2, "xt_check_match" },
	{ 0x1de23e95, "module_put" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xbfacb837, "xt_percpu_counter_free" },
	{ 0xb6115b4e, "xt_request_find_target" },
	{ 0xc7b94877, "xt_check_target" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x9166fada, "strncpy" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x807d2b2c, "xt_recseq" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x800473f, "__cond_resched" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xa7c94f1d, "xt_compat_lock" },
	{ 0xd064f936, "xt_find_table_lock" },
	{ 0x4e27719, "xt_compat_flush_offsets" },
	{ 0x13d3e9a8, "xt_table_unlock" },
	{ 0xd1e246a2, "xt_compat_unlock" },
	{ 0x96d28eb7, "xt_compat_match_to_user" },
	{ 0x999e8297, "vfree" },
	{ 0x413b423e, "xt_compat_target_to_user" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0x86490580, "current_task" },
	{ 0xc5f6dd9c, "xt_request_find_table_lock" },
	{ 0xa916b694, "strnlen" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0xddf68fc6, "xt_find_revision" },
	{ 0xf53b9f2c, "xt_match_to_user" },
	{ 0x483b0fa6, "xt_target_to_user" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xd3fcc511, "xt_tee_enabled" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x70c52dc5, "nf_skb_duplicated" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xed8f7c03, "nf_log_trace" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb0c23a4d, "xt_unregister_table" },
	{ 0xe204e042, "xt_free_table_info" },
	{ 0xcb3e91cc, "xt_counters_alloc" },
	{ 0xa56c403e, "xt_replace_table" },
	{ 0xd7f5fcd, "xt_alloc_entry_offsets" },
	{ 0xd87ae60d, "xt_check_entry_offsets" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x3bf9d084, "xt_check_table_hooks" },
	{ 0xfef779fa, "xt_find_jump_offset" },
	{ 0x977fd4bf, "xt_alloc_table_info" },
	{ 0x69acdf38, "memcpy" },
	{ 0x97e73427, "xt_register_table" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0xa25fc115, "xt_compat_check_entry_offsets" },
	{ 0xfb578fc5, "memset" },
	{ 0x2925b011, "xt_compat_match_from_user" },
	{ 0x1dd2ecdf, "xt_compat_target_from_user" },
	{ 0xd9bb821b, "xt_copy_counters" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0x7ec922ce, "xt_register_matches" },
	{ 0x3fb130e, "nf_register_sockopt" },
	{ 0x4bb1f65e, "xt_unregister_matches" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x4490c46c, "nf_unregister_sockopt" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "A01497A93C75F551917781D");
