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

SYMBOL_CRC(nf_reject_skb_v4_tcp_reset, 0x89d971ce, "_gpl");
SYMBOL_CRC(nf_reject_skb_v4_unreach, 0xf48c948d, "_gpl");
SYMBOL_CRC(nf_reject_ip_tcphdr_get, 0xbca05ae7, "_gpl");
SYMBOL_CRC(nf_reject_iphdr_put, 0x0d1a49dc, "_gpl");
SYMBOL_CRC(nf_reject_ip_tcphdr_put, 0x736ca113, "_gpl");
SYMBOL_CRC(nf_send_reset, 0x2bbde5c2, "_gpl");
SYMBOL_CRC(nf_send_unreach, 0x4115b9d4, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xbe888b32, "skb_put" },
	{ 0x24549fb1, "nf_ip_route" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xad14ca49, "nf_ip_checksum" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6a1530dc, "ip_route_me_harder" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0x8992fa70, "nf_ct_attach" },
	{ 0x2124474, "ip_send_check" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0x8a60e5c8, "ip_local_out" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0x284bf3d3, "pskb_trim_rcsum_slow" },
	{ 0x9def366f, "__icmp_send" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8A86BB64AF4CD514AC8C61B");
