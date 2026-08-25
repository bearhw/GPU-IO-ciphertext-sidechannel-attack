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

SYMBOL_CRC(l2tp_ioctl, 0x24aedab1, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0x7561021b, "__sock_recv_timestamp" },
	{ 0xcaaa389b, "ip_cmsg_recv_offset" },
	{ 0xfd6361e7, "__sock_recv_wifi_status" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xcf6d36d0, "sock_wmalloc" },
	{ 0xbe888b32, "skb_put" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x4c83cd6a, "security_sk_classify_flow" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0x47ad4ec3, "ip_queue_xmit" },
	{ 0xae4cc05, "release_sock" },
	{ 0xbc7fbc25, "sk_setup_caps" },
	{ 0x2610fc06, "__sk_dst_check" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xce886e70, "l2tp_sk_to_tunnel" },
	{ 0x2c1a0516, "l2tp_tunnel_delete" },
	{ 0xa468e703, "__udp_disconnect" },
	{ 0x8fef807, "__ip4_datagram_connect" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0xa67d1e7, "inet_addr_type" },
	{ 0xe05b6928, "dst_release" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x4a463eba, "sk_common_release" },
	{ 0xd010dd2e, "l2tp_session_get" },
	{ 0xe3591ce7, "l2tp_recv_common" },
	{ 0x3195783f, "l2tp_session_dec_refcount" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x948dbf5a, "__sk_receive_skb" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x5189c8ea, "__xfrm_policy_check" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x92997ed8, "_printk" },
	{ 0x68764184, "proto_register" },
	{ 0x1e208bf5, "inet_add_protocol" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0xa36dea07, "inet_register_protosw" },
	{ 0x2c882d29, "inet_unregister_protosw" },
	{ 0xe71edfc0, "inet_del_protocol" },
	{ 0x90333008, "inet_release" },
	{ 0x6d69c9c4, "inet_bind" },
	{ 0x97a609a3, "inet_dgram_connect" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0x47a2595f, "inet_ioctl" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x5bb87a44, "inet_shutdown" },
	{ 0x3a970709, "sock_common_setsockopt" },
	{ 0xbb06e299, "sock_common_getsockopt" },
	{ 0xebf69db7, "inet_sendmsg" },
	{ 0xbf54b858, "sock_common_recvmsg" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0xc6e73ac, "ip_setsockopt" },
	{ 0xd4bab9d5, "ip_getsockopt" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "l2tp_core");


MODULE_INFO(srcversion, "9EE88C40A8DEA872C80B37A");
