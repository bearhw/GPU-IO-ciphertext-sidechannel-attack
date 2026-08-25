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
	{ 0xe59eb89b, "__ethtool_get_link_ksettings" },
	{ 0x34a6572b, "__dynamic_netdev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xe401049, "qdisc_watchdog_schedule_range_ns" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x9953813d, "rtnl_kfree_skbs" },
	{ 0x56470118, "__warn_printk" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x16aeb9ab, "pfifo_qdisc_ops" },
	{ 0xbc9fd33f, "qdisc_create_dflt" },
	{ 0x76dc93bd, "noop_qdisc" },
	{ 0x82f569d1, "qdisc_hash_add" },
	{ 0x26fb65da, "qdisc_watchdog_init" },
	{ 0x7a70b72e, "qdisc_watchdog_cancel" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "12AC2F73C2CE314D5F090F4");
