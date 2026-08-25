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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xda5d4ed, "qdisc_offload_dump_helper" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x12d9ac72, "tcf_block_put" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0x5c7a9342, "gnet_stats_copy_basic" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x56605172, "gnet_stats_copy_queue" },
	{ 0xf4846190, "qdisc_offload_graft_helper" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xec45f59e, "__qdisc_calculate_pkt_len" },
	{ 0x50e2b9a2, "tcf_classify" },
	{ 0xbea7f279, "qdisc_warn_nonwc" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x431ec3a9, "__nla_validate" },
	{ 0x16aeb9ab, "pfifo_qdisc_ops" },
	{ 0xbc9fd33f, "qdisc_create_dflt" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0x76dc93bd, "noop_qdisc" },
	{ 0x82f569d1, "qdisc_hash_add" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x866a62b2, "gnet_stats_basic_sync_init" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x40d7d7bb, "tcf_block_get" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BC5257261B407B41B935288");
