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

SYMBOL_CRC(get_h225_addr, 0xa8386217, "_gpl");
SYMBOL_CRC(set_h245_addr_hook, 0x89d40c79, "_gpl");
SYMBOL_CRC(set_h225_addr_hook, 0x48607772, "_gpl");
SYMBOL_CRC(set_sig_addr_hook, 0xe787a529, "_gpl");
SYMBOL_CRC(set_ras_addr_hook, 0xcef26393, "_gpl");
SYMBOL_CRC(nat_rtp_rtcp_hook, 0xf0c05255, "_gpl");
SYMBOL_CRC(nat_t120_hook, 0x598aa008, "_gpl");
SYMBOL_CRC(nat_h245_hook, 0xbc03419f, "_gpl");
SYMBOL_CRC(nat_callforwarding_hook, 0x9a8e879c, "_gpl");
SYMBOL_CRC(nat_q931_hook, 0xb58b7df6, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x1e0a0c24, "mod_timer_pending" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x37a0cba, "kfree" },
	{ 0xf49030d3, "__nf_ip6_route" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x81e39ae6, "nf_ct_helper_log" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x9adb7399, "nf_conntrack_expect_lock" },
	{ 0xd8895533, "__nf_ct_expect_find" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x98914c14, "nf_conntrack_helpers_unregister" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0x4eb7d7bb, "nf_ct_expect_alloc" },
	{ 0x4cba5ac3, "nf_ct_expect_put" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x35c98d0a, "nf_conntrack_helpers_register" },
	{ 0x24549fb1, "nf_ip_route" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xf1fc41fe, "nf_ct_expect_init" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe05b6928, "dst_release" },
	{ 0x924f2ced, "nf_conntrack_helper_unregister" },
	{ 0x73ef9dcd, "__nf_ct_refresh_acct" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3f9abf02, "nf_conntrack_helper_register" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x13a0a56, "nf_ct_unexpect_related" },
	{ 0x7457d34f, "nf_ct_remove_expectations" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack");


MODULE_INFO(srcversion, "773E3DC368DC2C49F38EF65");
