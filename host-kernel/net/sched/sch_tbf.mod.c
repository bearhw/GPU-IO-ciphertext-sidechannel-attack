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
	{ 0x7a70b72e, "qdisc_watchdog_cancel" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x29e08458, "skb_gso_validate_mac_len" },
	{ 0xf05001d6, "netif_skb_features" },
	{ 0x8407c404, "__skb_gso_segment" },
	{ 0xec45f59e, "__qdisc_calculate_pkt_len" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0xbd505649, "consume_skb" },
	{ 0xda5d4ed, "qdisc_offload_dump_helper" },
	{ 0x8520a781, "nla_put" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x76dc93bd, "noop_qdisc" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xf4846190, "qdisc_offload_graft_helper" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0xb6e36ce2, "psched_ratecfg_precompute" },
	{ 0xd764e977, "fifo_set_limit" },
	{ 0xa0d87339, "qdisc_get_rtab" },
	{ 0xa61ced89, "qdisc_put_rtab" },
	{ 0x7729a256, "bfifo_qdisc_ops" },
	{ 0x517ed726, "fifo_create_dflt" },
	{ 0x82f569d1, "qdisc_hash_add" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0x26fb65da, "qdisc_watchdog_init" },
	{ 0xe401049, "qdisc_watchdog_schedule_range_ns" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "00BA545B22B6FE23847CF7E");
