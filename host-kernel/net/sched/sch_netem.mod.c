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
	{ 0x7a70b72e, "qdisc_watchdog_cancel" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xece784c2, "rb_first" },
	{ 0xca9360b5, "rb_next" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x9953813d, "rtnl_kfree_skbs" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x69acdf38, "memcpy" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xa965ca81, "reciprocal_value" },
	{ 0x92997ed8, "_printk" },
	{ 0x26fb65da, "qdisc_watchdog_init" },
	{ 0xec45f59e, "__qdisc_calculate_pkt_len" },
	{ 0xd01cc0c4, "kfree_skb_list_reason" },
	{ 0xe401049, "qdisc_watchdog_schedule_range_ns" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0x231396b0, "skb_orphan_partial" },
	{ 0xdf2c2742, "rb_last" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xf05001d6, "netif_skb_features" },
	{ 0x8407c404, "__skb_gso_segment" },
	{ 0xbd505649, "consume_skb" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xf652d653, "skb_checksum_help" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CC1684BDB9BBAEC77C8F3E4");
