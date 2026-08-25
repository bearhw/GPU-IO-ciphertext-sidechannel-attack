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
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x12d9ac72, "tcf_block_put" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x37a0cba, "kfree" },
	{ 0x56605172, "gnet_stats_copy_queue" },
	{ 0x77732147, "gnet_stats_copy_app" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x50e2b9a2, "tcf_classify" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xe2026fc8, "qdisc_tree_reduce_backlog" },
	{ 0xb8fb460c, "skb_get_hash_perturb" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x40d7d7bb, "tcf_block_get" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xa965ca81, "reciprocal_value" },
	{ 0x9953813d, "rtnl_kfree_skbs" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D8B3BC032062DD2E03A509D");
