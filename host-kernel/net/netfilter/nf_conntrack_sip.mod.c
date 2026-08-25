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

SYMBOL_CRC(nf_nat_sip_hooks, 0x6e7f4a14, "_gpl");
SYMBOL_CRC(ct_sip_parse_request, 0x69f35f3f, "_gpl");
SYMBOL_CRC(ct_sip_get_header, 0xeedf6f72, "_gpl");
SYMBOL_CRC(ct_sip_parse_header_uri, 0x90157492, "_gpl");
SYMBOL_CRC(ct_sip_parse_address_param, 0x9efcae76, "_gpl");
SYMBOL_CRC(ct_sip_parse_numerical_param, 0x5da0ca82, "_gpl");
SYMBOL_CRC(ct_sip_get_sdp_header, 0x2c48e3ce, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x11089ac7, "_ctype" },
	{ 0x96b29254, "strncasecmp" },
	{ 0x609bcd98, "in6_pton" },
	{ 0xac5fcec0, "in4_pton" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x754d539c, "strlen" },
	{ 0x5a921311, "strncmp" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9adb7399, "nf_conntrack_expect_lock" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x4ccad4d6, "nf_ct_remove_expect" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x81e39ae6, "nf_ct_helper_log" },
	{ 0x73ef9dcd, "__nf_ct_refresh_acct" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x4eb7d7bb, "nf_ct_expect_alloc" },
	{ 0xf1fc41fe, "nf_ct_expect_init" },
	{ 0x4cba5ac3, "nf_ct_expect_put" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0xd8895533, "__nf_ct_expect_find" },
	{ 0xf49030d3, "__nf_ip6_route" },
	{ 0xe05b6928, "dst_release" },
	{ 0x24549fb1, "nf_ip_route" },
	{ 0x13a0a56, "nf_ct_unexpect_related" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x1e0a0c24, "mod_timer_pending" },
	{ 0x98914c14, "nf_conntrack_helpers_unregister" },
	{ 0x250f5474, "nf_ct_helper_init" },
	{ 0x35c98d0a, "nf_conntrack_helpers_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x786109b9, "param_array_ops" },
	{ 0x5897cdd4, "param_ops_ushort" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack");


MODULE_INFO(srcversion, "D7ECA66978D5A0BDE981351");
