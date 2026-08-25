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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x7a70b72e, "qdisc_watchdog_cancel" },
	{ 0x12d9ac72, "tcf_block_put" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x8520a781, "nla_put" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x26fb65da, "qdisc_watchdog_init" },
	{ 0x40d7d7bb, "tcf_block_get" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x56605172, "gnet_stats_copy_queue" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xc836e7ca, "flow_keys_dissector" },
	{ 0xa8c6da59, "__skb_flow_dissect" },
	{ 0x460f4a34, "flow_hash_from_keys" },
	{ 0x64281c1, "nf_ct_get_tuple_skb" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x50e2b9a2, "tcf_classify" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0xe401049, "qdisc_watchdog_schedule_range_ns" },
	{ 0xbd505649, "consume_skb" },
	{ 0xf05001d6, "netif_skb_features" },
	{ 0x8407c404, "__skb_gso_segment" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6307E213B4F864DF4C0064E");
