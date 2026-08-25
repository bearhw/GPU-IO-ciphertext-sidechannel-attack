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
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa07321bc, "spi_write_then_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "850484904F771491B0E83DC");
