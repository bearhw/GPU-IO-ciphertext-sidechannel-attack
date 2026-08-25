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
	{ 0xd75eb10d, "seq_printf" },
	{ 0xa32fb801, "ether_setup" },
	{ 0x17c410a1, "l2tp_xmit_skb" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x1de23e95, "module_put" },
	{ 0x5f7c12ff, "dev_forward_skb" },
	{ 0xce1ac14a, "__skb_ext_del" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0xe05b6928, "dst_release" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x754d539c, "strlen" },
	{ 0xddeee1c6, "l2tp_session_create" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xf59c0a3a, "kernel_sock_ip_overhead" },
	{ 0xae4cc05, "release_sock" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0xb8359cc7, "l2tp_session_inc_refcount" },
	{ 0x6242c13e, "l2tp_session_register" },
	{ 0xa498108e, "register_netdevice" },
	{ 0xa916b694, "strnlen" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3195783f, "l2tp_session_dec_refcount" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x37a0cba, "kfree" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x4238cc26, "l2tp_session_delete" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x5d4aa0a9, "l2tp_nl_register_ops" },
	{ 0x92997ed8, "_printk" },
	{ 0x337f2432, "l2tp_nl_unregister_ops" },
	{ 0xe838916, "eth_mac_addr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "l2tp_core,l2tp_netlink");


MODULE_INFO(srcversion, "0A1F67DCE4201271045C901");
