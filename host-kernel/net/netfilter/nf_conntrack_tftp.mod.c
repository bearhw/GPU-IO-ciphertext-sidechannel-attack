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

SYMBOL_CRC(nf_nat_tftp_hook, 0x92257798, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4eb7d7bb, "nf_ct_expect_alloc" },
	{ 0xf1fc41fe, "nf_ct_expect_init" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4cba5ac3, "nf_ct_expect_put" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0x81e39ae6, "nf_ct_helper_log" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x98914c14, "nf_conntrack_helpers_unregister" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x250f5474, "nf_ct_helper_init" },
	{ 0x35c98d0a, "nf_conntrack_helpers_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x786109b9, "param_array_ops" },
	{ 0x5897cdd4, "param_ops_ushort" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack");


MODULE_INFO(srcversion, "EDD53DB867130B11AFB413B");
