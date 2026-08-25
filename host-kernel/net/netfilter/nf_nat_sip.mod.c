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
	{ 0x549632a0, "nf_nat_mangle_udp_packet" },
	{ 0x500685b4, "__nf_nat_mangle_tcp_packet" },
	{ 0x2c48e3ce, "ct_sip_get_sdp_header" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeedf6f72, "ct_sip_get_header" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0x13a0a56, "nf_ct_unexpect_related" },
	{ 0x81e39ae6, "nf_ct_helper_log" },
	{ 0x35215281, "nf_ct_seqadj_set" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x90157492, "ct_sip_parse_header_uri" },
	{ 0x918169e8, "nf_nat_setup_info" },
	{ 0x9adb7399, "nf_conntrack_expect_lock" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x96b29254, "strncasecmp" },
	{ 0x9efcae76, "ct_sip_parse_address_param" },
	{ 0x69f35f3f, "ct_sip_parse_request" },
	{ 0x5da0ca82, "ct_sip_parse_numerical_param" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0x41267473, "nf_nat_helper_unregister" },
	{ 0x6e7f4a14, "nf_nat_sip_hooks" },
	{ 0xe3c0ac72, "nf_ct_helper_expectfn_unregister" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x693d67e1, "nf_nat_helper_register" },
	{ 0x19e81a0a, "nf_ct_helper_expectfn_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_nat,nf_conntrack_sip,nf_conntrack");


MODULE_INFO(srcversion, "611C746A25BF5C9EAEC77E5");
