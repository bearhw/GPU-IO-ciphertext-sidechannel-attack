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
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x44e8a412, "l2tp_tunnel_get_session" },
	{ 0x3195783f, "l2tp_session_dec_refcount" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x1ebe39c0, "l2tp_udp_encap_recv" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0x7c90c120, "l2tp_tunnel_dec_refcount" },
	{ 0x58ac7f2e, "l2tp_tunnel_get_nth" },
	{ 0x2fac87ee, "ppp_input" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x92997ed8, "_printk" },
	{ 0x7b0a3df8, "l2tp_session_get_nth" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xae4cc05, "release_sock" },
	{ 0x5f4375c2, "l2tp_tunnel_get" },
	{ 0x4f7c2e55, "l2tp_tunnel_create" },
	{ 0xc59ed1d6, "l2tp_tunnel_inc_refcount" },
	{ 0xeb9dec00, "l2tp_tunnel_register" },
	{ 0x2c1a0516, "l2tp_tunnel_delete" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xddeee1c6, "l2tp_session_create" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xb8359cc7, "l2tp_session_inc_refcount" },
	{ 0x6242c13e, "l2tp_session_register" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0xe05b6928, "dst_release" },
	{ 0x402b4d30, "ppp_register_net_channel" },
	{ 0x4238cc26, "l2tp_session_delete" },
	{ 0x37a0cba, "kfree" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa4f1a441, "ppp_dev_name" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x391de184, "seq_puts" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x7a8ac0a5, "pppox_unbind_sock" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xebf0ff1e, "l2tp_session_set_header_len" },
	{ 0xcf6d36d0, "sock_wmalloc" },
	{ 0xbe888b32, "skb_put" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x17c410a1, "l2tp_xmit_skb" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0x68764184, "proto_register" },
	{ 0xc6f4d9c, "register_pppox_proto" },
	{ 0x5d4aa0a9, "l2tp_nl_register_ops" },
	{ 0xe0ff7a18, "unregister_pppox_proto" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x337f2432, "l2tp_nl_unregister_ops" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0x2f0a93ad, "pppox_ioctl" },
	{ 0xc8b30bca, "pppox_compat_ioctl" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "l2tp_core,pppox,l2tp_netlink");


MODULE_INFO(srcversion, "25193AF67D944124EFC79B4");
