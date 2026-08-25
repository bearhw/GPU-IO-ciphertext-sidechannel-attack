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

SYMBOL_CRC(ufshcd_dwc_dme_set_attrs, 0xd55cd640, "");
SYMBOL_CRC(ufshcd_dwc_link_startup_notify, 0xe7733de3, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xffacfb5c, "ufshcd_dme_set_attr" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x627b41ff, "ufshcd_dme_get_attr" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ufshcd-core");


MODULE_INFO(srcversion, "2AED09FD7C92750C37166A8");
