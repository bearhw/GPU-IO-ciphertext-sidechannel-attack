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

SYMBOL_CRC(dccp_v4_connect, 0xa20a00f5, "_gpl");
SYMBOL_CRC(dccp_req_err, 0x7c7e0467, "");
SYMBOL_CRC(dccp_v4_send_check, 0x5298bf58, "_gpl");
SYMBOL_CRC(dccp_v4_request_recv_sock, 0x657c57ee, "_gpl");
SYMBOL_CRC(dccp_syn_ack_timeout, 0x8f886c1c, "");
SYMBOL_CRC(dccp_v4_conn_request, 0x2b1e0a75, "_gpl");
SYMBOL_CRC(dccp_v4_do_rcv, 0xa6dd6b98, "_gpl");
SYMBOL_CRC(dccp_invalid_packet, 0x853cc847, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe352a323, "__inet_lookup_established" },
	{ 0x38b9cf1a, "inet_csk_addr2sockaddr" },
	{ 0x2c882d29, "inet_unregister_protosw" },
	{ 0x47ad4ec3, "ip_queue_xmit" },
	{ 0x3969fc9a, "dccp_shutdown" },
	{ 0x6103fa99, "dccp_connect" },
	{ 0xc0a5b6ab, "dccp_rcv_state_process" },
	{ 0xf4bb6920, "dccp_reqsk_send_ack" },
	{ 0x15440701, "__inet_lookup_listener" },
	{ 0xe6140741, "inet_csk_accept" },
	{ 0x86be7924, "dccp_packet_name" },
	{ 0xbb06e299, "sock_common_getsockopt" },
	{ 0x6d69c9c4, "inet_bind" },
	{ 0xb16e78da, "__inet_inherit_port" },
	{ 0x108eb16, "inet_dccp_listen" },
	{ 0xd4592578, "security_inet_conn_request" },
	{ 0x37a0cba, "kfree" },
	{ 0xa36dea07, "inet_register_protosw" },
	{ 0x5189c8ea, "__xfrm_policy_check" },
	{ 0x3a970709, "sock_common_setsockopt" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0x12c15c3b, "inet_csk_reqsk_queue_hash_add" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x4cdd391d, "dccp_feat_list_purge" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x258d2eed, "inet_ehash_nolisten" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x46439afe, "inet_getname" },
	{ 0xef9db4ae, "inet_stream_connect" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x70a1798d, "inet_reqsk_alloc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x8e4f64b7, "inet_twsk_purge" },
	{ 0x78981924, "dccp_done" },
	{ 0x90333008, "inet_release" },
	{ 0x2610fc06, "__sk_dst_check" },
	{ 0x5a66d955, "dccp_disconnect" },
	{ 0x65c180fa, "ip_route_output_key_hash" },
	{ 0x68764184, "proto_register" },
	{ 0xb391353d, "inet_hash" },
	{ 0x948dbf5a, "__sk_receive_skb" },
	{ 0x28fa21d8, "dccp_poll" },
	{ 0xcb10dc39, "inet_ctl_sock_create" },
	{ 0x14a1f33, "dccp_death_row" },
	{ 0x1b3e4558, "inet_csk_get_port" },
	{ 0x47a2595f, "inet_ioctl" },
	{ 0xc65e4e97, "secure_dccp_sequence_number" },
	{ 0xf7c067a1, "inet_csk_reqsk_queue_drop_and_put" },
	{ 0x2bb1a44b, "inet_accept" },
	{ 0x368fb95, "dccp_sync_mss" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0xd75b7072, "dccp_orphan_count" },
	{ 0x1e208bf5, "inet_add_protocol" },
	{ 0x5bb87a44, "inet_shutdown" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x16248a0d, "dccp_close" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x83a57545, "dccp_reqsk_init" },
	{ 0xb22d9b3f, "inet_hash_connect" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xf38b6a1c, "inet_csk_route_child_sock" },
	{ 0x5bfbf859, "inet_csk_route_req" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x4c83cd6a, "security_sk_classify_flow" },
	{ 0xb1dadac1, "inet_csk_update_pmtu" },
	{ 0x89f9370b, "dccp_getsockopt" },
	{ 0xb17f840d, "dccp_parse_options" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xcfacc347, "skb_checksum" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xb344f8ce, "dccp_child_process" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0xbf54b858, "sock_common_recvmsg" },
	{ 0xd08bbb91, "dccp_setsockopt" },
	{ 0x413fd817, "dccp_ioctl" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x94873a45, "inet_sk_rebuild_header" },
	{ 0xe71edfc0, "inet_del_protocol" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x631af98f, "dccp_recvmsg" },
	{ 0xebf69db7, "inet_sendmsg" },
	{ 0x181e53ce, "dccp_check_req" },
	{ 0x1e1391f2, "dccp_create_openreq_child" },
	{ 0x4b7a9c1d, "inet_csk_prepare_forced_close" },
	{ 0x2f4ab576, "security_skb_classify_flow" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xcfa79cbd, "sock_pfree" },
	{ 0x2ccc02d6, "dccp_rcv_established" },
	{ 0xf48f4278, "dccp_send_sync" },
	{ 0xe05b6928, "dst_release" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x5d82976e, "dccp_make_response" },
	{ 0x9e865606, "dccp_destroy_sock" },
	{ 0xb61539d2, "dccp_ctl_make_reset" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xbc7fbc25, "sk_setup_caps" },
	{ 0x167ef4eb, "ip_build_and_send_pkt" },
	{ 0x399c3608, "dccp_sendmsg" },
	{ 0xc6e73ac, "ip_setsockopt" },
	{ 0xe4fac9e, "dccp_hashinfo" },
	{ 0x283c2885, "inet_twsk_put" },
	{ 0xbec98f63, "inet_unhash" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xd4bab9d5, "ip_getsockopt" },
	{ 0x765268f3, "dccp_set_state" },
	{ 0x48802110, "dccp_init_sock" },
	{ 0x49045426, "icmp_err_convert" },
	{ 0x59814a84, "dccp_statistics" },
	{ 0x62a85488, "inet_csk_reqsk_queue_drop" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dccp");


MODULE_INFO(srcversion, "370CB6D7F93A1F2E2693D1C");
