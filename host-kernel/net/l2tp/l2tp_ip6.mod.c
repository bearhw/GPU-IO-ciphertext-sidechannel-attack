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
	{ 0xce886e70, "l2tp_sk_to_tunnel" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x753c0877, "ip6_flush_pending_frames" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2c1a0516, "l2tp_tunnel_delete" },
	{ 0x4be60c75, "inet6_destroy_sock" },
	{ 0xa468e703, "__udp_disconnect" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0xf9fc75eb, "__ip6_datagram_connect" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4a463eba, "sk_common_release" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0xbc769b5f, "ipv6_chk_addr" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0x188d3f36, "ipv6_recv_error" },
	{ 0x7561021b, "__sock_recv_timestamp" },
	{ 0xa4b2340f, "ip6_datagram_recv_ctl" },
	{ 0xfd6361e7, "__sock_recv_wifi_status" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x992e96dd, "ip6_datagram_send_ctl" },
	{ 0x5cd37c77, "fl6_merge_options" },
	{ 0x6f6b52e9, "__ipv6_fixup_options" },
	{ 0x5d3508f1, "fl6_update_dst" },
	{ 0x4c83cd6a, "security_sk_classify_flow" },
	{ 0xd84a0a47, "ip6_dst_lookup_flow" },
	{ 0x4643b747, "ip_generic_getfrag" },
	{ 0x89ad546a, "ip6_append_data" },
	{ 0xe05b6928, "dst_release" },
	{ 0xcd5835b, "ipv6_flowlabel_exclusive" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xf23eb205, "ip6_push_pending_frames" },
	{ 0x9f78a072, "__fl6_sock_lookup" },
	{ 0x3356bb23, "ip6_dst_hoplimit" },
	{ 0xd010dd2e, "l2tp_session_get" },
	{ 0xe3591ce7, "l2tp_recv_common" },
	{ 0x3195783f, "l2tp_session_dec_refcount" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x5189c8ea, "__xfrm_policy_check" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x948dbf5a, "__sk_receive_skb" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x92997ed8, "_printk" },
	{ 0x68764184, "proto_register" },
	{ 0x9f492618, "inet6_add_protocol" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x842efa51, "inet6_register_protosw" },
	{ 0xde40ad98, "inet6_unregister_protosw" },
	{ 0xbef14778, "inet6_del_protocol" },
	{ 0xf779e575, "inet6_release" },
	{ 0x290e4d31, "inet6_bind" },
	{ 0x97a609a3, "inet_dgram_connect" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0x772c54cb, "inet6_ioctl" },
	{ 0xc2528dd0, "inet6_compat_ioctl" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x5bb87a44, "inet_shutdown" },
	{ 0x3a970709, "sock_common_setsockopt" },
	{ 0xbb06e299, "sock_common_getsockopt" },
	{ 0xebf69db7, "inet_sendmsg" },
	{ 0xbf54b858, "sock_common_recvmsg" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x24aedab1, "l2tp_ioctl" },
	{ 0xc7643beb, "ipv6_setsockopt" },
	{ 0x478c3147, "ipv6_getsockopt" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "l2tp_core,l2tp_ip");


MODULE_INFO(srcversion, "C486B4C60322B959DB6A93C");
