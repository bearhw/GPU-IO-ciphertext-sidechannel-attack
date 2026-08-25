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
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0xfbad13e8, "devm_rtc_nvmem_register" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6f477cbc, "__platform_driver_probe" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E5546D170E1E66E78BC4E42");
