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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(nf_reject_skb_v6_tcp_reset, 0x762e74ca, "_gpl");
SYMBOL_CRC(nf_reject_skb_v6_unreach, 0xad2baf54, "_gpl");
SYMBOL_CRC(nf_reject_ip6_tcphdr_get, 0xf701d866, "_gpl");
SYMBOL_CRC(nf_reject_ip6hdr_put, 0x94212089, "_gpl");
SYMBOL_CRC(nf_reject_ip6_tcphdr_put, 0xee5ddffb, "_gpl");
SYMBOL_CRC(nf_send_reset6, 0x93e1bf7b, "_gpl");
SYMBOL_CRC(nf_send_unreach6, 0xdb22ea97, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xbe888b32, "skb_put" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xb47cca30, "csum_ipv6_magic" },
	{ 0xf49030d3, "__nf_ip6_route" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0xf6a9ff1d, "nf_ip6_checksum" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xe7097cd2, "icmp6_send" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x284bf3d3, "pskb_trim_rcsum_slow" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0x16c7b891, "l3mdev_master_ifindex_rcu" },
	{ 0x2f4ab576, "security_skb_classify_flow" },
	{ 0x86f015e6, "ip6_route_output_flags" },
	{ 0x822e0163, "xfrm_lookup" },
	{ 0x3356bb23, "ip6_dst_hoplimit" },
	{ 0x8992fa70, "nf_ct_attach" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xe05b6928, "dst_release" },
	{ 0xa8037a64, "ip6_local_out" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "ADAAB47DF1FFC2B710F664D");
