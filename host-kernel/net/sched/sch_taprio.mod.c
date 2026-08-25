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

SYMBOL_CRC(taprio_offload_get, 0xa7f08102, "_gpl");
SYMBOL_CRC(taprio_offload_free, 0x5fc3c6ed, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x37a0cba, "kfree" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x6d6fec1f, "ktime_mono_to_any" },
	{ 0xe59eb89b, "__ethtool_get_link_ksettings" },
	{ 0x34a6572b, "__dynamic_netdev_dbg" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0x5c7a9342, "gnet_stats_copy_basic" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x56605172, "gnet_stats_copy_queue" },
	{ 0x2784a458, "dev_deactivate" },
	{ 0x5f74f960, "dev_graft_qdisc" },
	{ 0xae86d5e8, "dev_activate" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x48ba113d, "netdev_set_num_tc" },
	{ 0x3fbfee8c, "netdev_set_tc_queue" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xef34bf3e, "hrtimer_active" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0xec45f59e, "__qdisc_calculate_pkt_len" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xf05001d6, "netif_skb_features" },
	{ 0x8407c404, "__skb_gso_segment" },
	{ 0xbd505649, "consume_skb" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xfce5d5bf, "netdev_reset_tc" },
	{ 0x9124ac4e, "__netif_schedule" },
	{ 0x16aeb9ab, "pfifo_qdisc_ops" },
	{ 0xbc9fd33f, "qdisc_create_dflt" },
	{ 0x82f569d1, "qdisc_hash_add" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9613E57A4F8AEFF06B17159");
