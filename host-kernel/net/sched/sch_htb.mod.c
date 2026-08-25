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
	{ 0x5f74f960, "dev_graft_qdisc" },
	{ 0x2784a458, "dev_deactivate" },
	{ 0xae86d5e8, "dev_activate" },
	{ 0x9124ac4e, "__netif_schedule" },
	{ 0xca9360b5, "rb_next" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0x5c7a9342, "gnet_stats_copy_basic" },
	{ 0x31571e73, "gnet_stats_copy_rate_est" },
	{ 0x56605172, "gnet_stats_copy_queue" },
	{ 0x77732147, "gnet_stats_copy_app" },
	{ 0x866a62b2, "gnet_stats_basic_sync_init" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0x26fb65da, "qdisc_watchdog_init" },
	{ 0x40d7d7bb, "tcf_block_get" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x117093be, "qdisc_class_hash_init" },
	{ 0x16aeb9ab, "pfifo_qdisc_ops" },
	{ 0xbc9fd33f, "qdisc_create_dflt" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0xf53d4c26, "qdisc_class_hash_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x82f569d1, "qdisc_hash_add" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0x7a70b72e, "qdisc_watchdog_cancel" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x9953813d, "rtnl_kfree_skbs" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xece784c2, "rb_first" },
	{ 0xe401049, "qdisc_watchdog_schedule_range_ns" },
	{ 0xbea7f279, "qdisc_warn_nonwc" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x92997ed8, "_printk" },
	{ 0x76dc93bd, "noop_qdisc" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x12d9ac72, "tcf_block_put" },
	{ 0x91a7b1da, "qdisc_class_hash_remove" },
	{ 0xded39a6b, "gen_kill_estimator" },
	{ 0x50e2b9a2, "tcf_classify" },
	{ 0xec45f59e, "__qdisc_calculate_pkt_len" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0xf630261, "gen_replace_estimator" },
	{ 0xb6e36ce2, "psched_ratecfg_precompute" },
	{ 0xa0d87339, "qdisc_get_rtab" },
	{ 0xa61ced89, "qdisc_put_rtab" },
	{ 0x6d9ec1f0, "qdisc_class_hash_grow" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x5e9a01ce, "gen_new_estimator" },
	{ 0xc4212ab9, "qdisc_class_hash_insert" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CFC4EB21892AA766F741163");
