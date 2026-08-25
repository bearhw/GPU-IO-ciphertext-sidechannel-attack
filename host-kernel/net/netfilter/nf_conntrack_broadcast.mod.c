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

SYMBOL_CRC(nf_conntrack_broadcast_help, 0xbb079046, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x4eb7d7bb, "nf_ct_expect_alloc" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0x4cba5ac3, "nf_ct_expect_put" },
	{ 0x73ef9dcd, "__nf_ct_refresh_acct" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack");


MODULE_INFO(srcversion, "D59E4FF1D04222E37CA5EE8");
