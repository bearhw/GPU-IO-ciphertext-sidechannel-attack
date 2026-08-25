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
	{ 0x4be60c75, "inet6_destroy_sock" },
	{ 0x811ec240, "inet6_csk_addr2sockaddr" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0xa20a00f5, "dccp_v4_connect" },
	{ 0x47ad4ec3, "ip_queue_xmit" },
	{ 0x9f78a072, "__fl6_sock_lookup" },
	{ 0x3969fc9a, "dccp_shutdown" },
	{ 0x6103fa99, "dccp_connect" },
	{ 0xbd505649, "consume_skb" },
	{ 0xc0a5b6ab, "dccp_rcv_state_process" },
	{ 0xf4bb6920, "dccp_reqsk_send_ack" },
	{ 0x290e4d31, "inet6_bind" },
	{ 0xe6140741, "inet_csk_accept" },
	{ 0xde40ad98, "inet6_unregister_protosw" },
	{ 0xbe4eb6ed, "secure_dccpv6_sequence_number" },
	{ 0xbb06e299, "sock_common_getsockopt" },
	{ 0xb16e78da, "__inet_inherit_port" },
	{ 0x108eb16, "inet_dccp_listen" },
	{ 0xd4592578, "security_inet_conn_request" },
	{ 0x37a0cba, "kfree" },
	{ 0x5f2ba55e, "security_req_classify_flow" },
	{ 0x5189c8ea, "__xfrm_policy_check" },
	{ 0xa7fc3426, "inet6_sk_rebuild_header" },
	{ 0x3a970709, "sock_common_setsockopt" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xc7643beb, "ipv6_setsockopt" },
	{ 0x12c15c3b, "inet_csk_reqsk_queue_hash_add" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x8f886c1c, "dccp_syn_ack_timeout" },
	{ 0x4cdd391d, "dccp_feat_list_purge" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x258d2eed, "inet_ehash_nolisten" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbef14778, "inet6_del_protocol" },
	{ 0x92997ed8, "_printk" },
	{ 0x853cc847, "dccp_invalid_packet" },
	{ 0xef9db4ae, "inet_stream_connect" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x5298bf58, "dccp_v4_send_check" },
	{ 0x70a1798d, "inet_reqsk_alloc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x8e4f64b7, "inet_twsk_purge" },
	{ 0x78981924, "dccp_done" },
	{ 0x2610fc06, "__sk_dst_check" },
	{ 0x5a66d955, "dccp_disconnect" },
	{ 0x68764184, "proto_register" },
	{ 0x948dbf5a, "__sk_receive_skb" },
	{ 0xc2528dd0, "inet6_compat_ioctl" },
	{ 0x28fa21d8, "dccp_poll" },
	{ 0xcb10dc39, "inet_ctl_sock_create" },
	{ 0x14a1f33, "dccp_death_row" },
	{ 0x1b3e4558, "inet_csk_get_port" },
	{ 0xb37f24cd, "sk_filter_trim_cap" },
	{ 0xf7c067a1, "inet_csk_reqsk_queue_drop_and_put" },
	{ 0xb5389568, "inet6_hash" },
	{ 0x2bb1a44b, "inet_accept" },
	{ 0xa86eca92, "inet6_hash_connect" },
	{ 0x368fb95, "dccp_sync_mss" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0xd75b7072, "dccp_orphan_count" },
	{ 0x5bb87a44, "inet_shutdown" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x16248a0d, "dccp_close" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x83a57545, "dccp_reqsk_init" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x5d3508f1, "fl6_update_dst" },
	{ 0x6fee5ca9, "inet6_csk_route_req" },
	{ 0x772c54cb, "inet6_ioctl" },
	{ 0x4c83cd6a, "security_sk_classify_flow" },
	{ 0x89f9370b, "dccp_getsockopt" },
	{ 0xb17f840d, "dccp_parse_options" },
	{ 0x657c57ee, "dccp_v4_request_recv_sock" },
	{ 0xc55c35e3, "__inet6_lookup_established" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xd84a0a47, "ip6_dst_lookup_flow" },
	{ 0xcfacc347, "skb_checksum" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0xb344f8ce, "dccp_child_process" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0xb47cca30, "csum_ipv6_magic" },
	{ 0xbf54b858, "sock_common_recvmsg" },
	{ 0xd08bbb91, "dccp_setsockopt" },
	{ 0x413fd817, "dccp_ioctl" },
	{ 0x1f12fa6, "inet6_csk_xmit" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2235b121, "sock_rfree" },
	{ 0xcfc9a4be, "inet6_getname" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x94873a45, "inet_sk_rebuild_header" },
	{ 0xd9d3ecac, "ip6_xmit" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x631af98f, "dccp_recvmsg" },
	{ 0x842efa51, "inet6_register_protosw" },
	{ 0xae316c11, "icmpv6_err_convert" },
	{ 0xf779e575, "inet6_release" },
	{ 0xebf69db7, "inet_sendmsg" },
	{ 0x181e53ce, "dccp_check_req" },
	{ 0x1dc7d6e0, "ipv6_dup_options" },
	{ 0x1e1391f2, "dccp_create_openreq_child" },
	{ 0x4b7a9c1d, "inet_csk_prepare_forced_close" },
	{ 0x2b1e0a75, "dccp_v4_conn_request" },
	{ 0x2f4ab576, "security_skb_classify_flow" },
	{ 0x7c7e0467, "dccp_req_err" },
	{ 0xcfa79cbd, "sock_pfree" },
	{ 0x2ccc02d6, "dccp_rcv_established" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xe05b6928, "dst_release" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x5d82976e, "dccp_make_response" },
	{ 0x9e865606, "dccp_destroy_sock" },
	{ 0xb61539d2, "dccp_ctl_make_reset" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xbc7fbc25, "sk_setup_caps" },
	{ 0xfc98033b, "ipv6_opt_accepted" },
	{ 0x399c3608, "dccp_sendmsg" },
	{ 0x16836ff1, "inet6_lookup_listener" },
	{ 0x9f492618, "inet6_add_protocol" },
	{ 0xcd5835b, "ipv6_flowlabel_exclusive" },
	{ 0xe4fac9e, "dccp_hashinfo" },
	{ 0x283c2885, "inet_twsk_put" },
	{ 0xbec98f63, "inet_unhash" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x478c3147, "ipv6_getsockopt" },
	{ 0x765268f3, "dccp_set_state" },
	{ 0xcae889a2, "inet6_csk_update_pmtu" },
	{ 0xa6dd6b98, "dccp_v4_do_rcv" },
	{ 0x2173216f, "__kfree_skb" },
	{ 0x48802110, "dccp_init_sock" },
	{ 0x59814a84, "dccp_statistics" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dccp_ipv4,dccp");


MODULE_INFO(srcversion, "F370CC33F2AF02CAF98BD03");
