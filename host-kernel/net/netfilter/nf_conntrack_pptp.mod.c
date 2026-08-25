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

SYMBOL_CRC(nf_nat_pptp_hook, 0x3cd2de69, "_gpl");
SYMBOL_CRC(pptp_msg_name, 0xf2a36612, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xfe731af8, "nf_ct_invert_tuple" },
	{ 0xbf87fcb0, "nf_ct_expect_find_get" },
	{ 0x13a0a56, "nf_ct_unexpect_related" },
	{ 0x4cba5ac3, "nf_ct_expect_put" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xaa28cd50, "nf_conntrack_find_get" },
	{ 0xc1bdbf4f, "nf_ct_delete" },
	{ 0x3b08a8f0, "nf_ct_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x4eb7d7bb, "nf_ct_expect_alloc" },
	{ 0xf1fc41fe, "nf_ct_expect_init" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0x9df39187, "nf_ct_gre_keymap_add" },
	{ 0x9ba74647, "nf_ct_gre_keymap_destroy" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x82b6160f, "nf_ct_ext_add" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x3f9abf02, "nf_conntrack_helper_register" },
	{ 0x924f2ced, "nf_conntrack_helper_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack");


MODULE_INFO(srcversion, "7A48FC8CFABBC36C211D038");
