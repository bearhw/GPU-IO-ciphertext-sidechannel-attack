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
	{ 0x14acfdfb, "tc_setup_cb_replace" },
	{ 0x949ca6ba, "tc_setup_cb_add" },
	{ 0xd79a11d7, "tc_setup_cb_destroy" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd79e38dc, "tc_setup_cb_reoffload" },
	{ 0xf84bd6ee, "bpf_stats_enabled_key" },
	{ 0xb954f70a, "tcf_action_exec" },
	{ 0x3a26ed11, "sched_clock" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x55c24701, "tc_setup_cb_call" },
	{ 0x8520a781, "nla_put" },
	{ 0xad115d2, "nla_reserve" },
	{ 0x69acdf38, "memcpy" },
	{ 0xbbd5e70e, "tcf_exts_dump" },
	{ 0xb92e3849, "tcf_exts_dump_stats" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x754d539c, "strlen" },
	{ 0x3f56328e, "tcf_exts_destroy" },
	{ 0x76048be1, "bpf_prog_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0xf9091774, "bpf_prog_put" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xefaf2e4f, "tcf_queue_work" },
	{ 0x92997ed8, "_printk" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xd9916c3a, "idr_alloc_u32" },
	{ 0xed491cdf, "tcf_exts_validate" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xb237e1d6, "bpf_prog_create" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xf0f73fe2, "bpf_prog_get_type_dev" },
	{ 0xcc61b44f, "tcf_block_netif_keep_dst" },
	{ 0x7b82b9a1, "idr_replace" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x56470118, "__warn_printk" },
	{ 0xfe99c7ff, "register_tcf_proto_ops" },
	{ 0x5c68b240, "unregister_tcf_proto_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1E1558E3A0FD761B91449E1");
