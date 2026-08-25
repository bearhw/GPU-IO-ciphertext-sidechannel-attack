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
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x8520a781, "nla_put" },
	{ 0xbbd5e70e, "tcf_exts_dump" },
	{ 0x74272ecc, "tcf_em_tree_dump" },
	{ 0xb92e3849, "tcf_exts_dump_stats" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x3f56328e, "tcf_exts_destroy" },
	{ 0x2a723f5a, "tcf_em_tree_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x47c6539c, "tcf_em_tree_validate" },
	{ 0xed491cdf, "tcf_exts_validate" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xcc61b44f, "tcf_block_netif_keep_dst" },
	{ 0xefaf2e4f, "tcf_queue_work" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x5a99a0d7, "flow_get_u32_dst" },
	{ 0x7f78fd7e, "from_kgid" },
	{ 0xb954f70a, "tcf_action_exec" },
	{ 0x6514c1e6, "flow_get_u32_src" },
	{ 0x932b011f, "__tcf_em_tree_match" },
	{ 0x402830fd, "from_kuid" },
	{ 0xc836e7ca, "flow_keys_dissector" },
	{ 0xa8c6da59, "__skb_flow_dissect" },
	{ 0xfd381298, "__skb_get_hash" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xfe99c7ff, "register_tcf_proto_ops" },
	{ 0x5c68b240, "unregister_tcf_proto_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F36093EED7715C9811A805F");
