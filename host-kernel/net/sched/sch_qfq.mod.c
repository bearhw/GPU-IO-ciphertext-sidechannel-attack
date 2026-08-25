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
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x5c7a9342, "gnet_stats_copy_basic" },
	{ 0x31571e73, "gnet_stats_copy_rate_est" },
	{ 0x56605172, "gnet_stats_copy_queue" },
	{ 0x77732147, "gnet_stats_copy_app" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x40d7d7bb, "tcf_block_get" },
	{ 0x117093be, "qdisc_class_hash_init" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfc421e79, "gnet_stats_add_queue" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x56470118, "__warn_printk" },
	{ 0x16aeb9ab, "pfifo_qdisc_ops" },
	{ 0xbc9fd33f, "qdisc_create_dflt" },
	{ 0x76dc93bd, "noop_qdisc" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x37a0cba, "kfree" },
	{ 0x12d9ac72, "tcf_block_put" },
	{ 0xded39a6b, "gen_kill_estimator" },
	{ 0xff7b9063, "qdisc_put" },
	{ 0xf53d4c26, "qdisc_class_hash_destroy" },
	{ 0x91a7b1da, "qdisc_class_hash_remove" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xf630261, "gen_replace_estimator" },
	{ 0xc4212ab9, "qdisc_class_hash_insert" },
	{ 0x6d9ec1f0, "qdisc_class_hash_grow" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x866a62b2, "gnet_stats_basic_sync_init" },
	{ 0x5e9a01ce, "gen_new_estimator" },
	{ 0x82f569d1, "qdisc_hash_add" },
	{ 0x92997ed8, "_printk" },
	{ 0xec45f59e, "__qdisc_calculate_pkt_len" },
	{ 0x50e2b9a2, "tcf_classify" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8D5DE35389A5DAC9956946D");
