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
	{ 0x87e2553b, "ieee802154_max_payload" },
	{ 0xdf6b082f, "proc_dointvec_jiffies" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xbd505649, "consume_skb" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0x5a6a6e71, "inet_frag_queue_insert" },
	{ 0xcaaae203, "inet_frags_init" },
	{ 0x17c7d3ad, "lowpan_register_netdevice" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x29b8fdf5, "ieee802154_hdr_peek_addrs" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x3e3c9028, "lowpan_unregister_netdevice" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x2eb28b3a, "inet_frag_destroy" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x5a705dc0, "inet_frag_reasm_finish" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xa0cf1873, "skb_copy_expand" },
	{ 0xb8e22311, "fqdir_init" },
	{ 0x8906f4a8, "lowpan_header_decompress" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x35279c79, "nd_tbl" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xeeb417ff, "ieee802154_hdr_peek" },
	{ 0xd47850e2, "inet_frags_fini" },
	{ 0xec2e1c8f, "proc_doulongvec_minmax" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0xf9cc5a0a, "inet_frag_reasm_prepare" },
	{ 0xe327c28, "inet_frag_find" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x214f0d3f, "fqdir_exit" },
	{ 0x6d606913, "pv_ops" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd894637d, "lowpan_header_compress" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xe05b6928, "dst_release" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xfebda60e, "inet_frag_kill" },
	{ 0xacbdf341, "neigh_lookup" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ieee802154,6lowpan");


MODULE_INFO(srcversion, "9F4EEBD9E3290671C5E1E01");
