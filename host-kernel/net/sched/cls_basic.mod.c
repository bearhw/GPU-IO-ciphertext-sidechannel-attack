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
	{ 0xb954f70a, "tcf_action_exec" },
	{ 0x932b011f, "__tcf_em_tree_match" },
	{ 0x8520a781, "nla_put" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xbbd5e70e, "tcf_exts_dump" },
	{ 0x74272ecc, "tcf_em_tree_dump" },
	{ 0xb92e3849, "tcf_exts_dump_stats" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3f56328e, "tcf_exts_destroy" },
	{ 0x2a723f5a, "tcf_em_tree_destroy" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x37a0cba, "kfree" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xefaf2e4f, "tcf_queue_work" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0xed491cdf, "tcf_exts_validate" },
	{ 0x47c6539c, "tcf_em_tree_validate" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x7b82b9a1, "idr_replace" },
	{ 0xd9916c3a, "idr_alloc_u32" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xfe99c7ff, "register_tcf_proto_ops" },
	{ 0x5c68b240, "unregister_tcf_proto_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0D3C72710290869F6FE6C99");
