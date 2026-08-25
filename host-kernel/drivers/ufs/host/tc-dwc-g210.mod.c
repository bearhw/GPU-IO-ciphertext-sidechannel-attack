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

SYMBOL_CRC(tc_dwc_g210_config_40_bit, 0x34b56137, "");
SYMBOL_CRC(tc_dwc_g210_config_20_bit, 0x71429048, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd55cd640, "ufshcd_dwc_dme_set_attrs" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xffacfb5c, "ufshcd_dme_set_attr" },
	{ 0x627b41ff, "ufshcd_dme_get_attr" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ufshcd-dwc,ufshcd-core");


MODULE_INFO(srcversion, "D2AFFD6CFFAF26AAB9A9BCF");
