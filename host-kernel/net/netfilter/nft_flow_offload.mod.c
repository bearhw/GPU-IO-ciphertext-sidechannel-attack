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
	{ 0xae47eb8d, "nft_chain_validate_hooks" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0xfbc67e43, "nf_tables_deactivate_flowtable" },
	{ 0xa1525092, "nft_flowtable_lookup" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0xa964fc1a, "nf_flow_table_cleanup" },
	{ 0x754d539c, "strlen" },
	{ 0x8520a781, "nla_put" },
	{ 0xd071f385, "dev_fill_forward_path" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb549b1e4, "nf_route" },
	{ 0x9285c4f8, "flow_offload_alloc" },
	{ 0xd9ce211b, "flow_offload_route_init" },
	{ 0xe41d9ee2, "flow_offload_add" },
	{ 0xe05b6928, "dst_release" },
	{ 0x3d218f35, "flow_offload_free" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables,nf_conntrack,nf_flow_table");


MODULE_INFO(srcversion, "5B3AA3B61F8B9BF7EF5CC34");
