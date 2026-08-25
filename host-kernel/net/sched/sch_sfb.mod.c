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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x77732147, "gnet_stats_copy_app" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x12d9ac72, "tcf_block_put" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x76dc93bd, "noop_qdisc" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x50e2b9a2, "tcf_classify" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x70002fe8, "siphash_1u32" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xec45f59e, "__qdisc_calculate_pkt_len" },
	{ 0xb8fb460c, "skb_get_hash_perturb" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x16aeb9ab, "pfifo_qdisc_ops" },
	{ 0x517ed726, "fifo_create_dflt" },
	{ 0x82f569d1, "qdisc_hash_add" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x40d7d7bb, "tcf_block_get" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DC0065A7D62E4C462CF5495");
