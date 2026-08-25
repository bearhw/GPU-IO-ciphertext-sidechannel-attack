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
	{ 0x918169e8, "nf_nat_setup_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe052320e, "nf_nat_follow_master" },
	{ 0x549632a0, "nf_nat_mangle_udp_packet" },
	{ 0x500685b4, "__nf_nat_mangle_tcp_packet" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x13a0a56, "nf_ct_unexpect_related" },
	{ 0xa8386217, "get_h225_addr" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x89d40c79, "set_h245_addr_hook" },
	{ 0x48607772, "set_h225_addr_hook" },
	{ 0xe787a529, "set_sig_addr_hook" },
	{ 0xcef26393, "set_ras_addr_hook" },
	{ 0xf0c05255, "nat_rtp_rtcp_hook" },
	{ 0x598aa008, "nat_t120_hook" },
	{ 0xbc03419f, "nat_h245_hook" },
	{ 0x9a8e879c, "nat_callforwarding_hook" },
	{ 0xb58b7df6, "nat_q931_hook" },
	{ 0x19e81a0a, "nf_ct_helper_expectfn_register" },
	{ 0xe3c0ac72, "nf_ct_helper_expectfn_unregister" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_nat,nf_conntrack,nf_conntrack_h323");


MODULE_INFO(srcversion, "E030ABC61C09FE58CF1EA01");
