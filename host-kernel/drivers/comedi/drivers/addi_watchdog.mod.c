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

SYMBOL_CRC(addi_watchdog_reset, 0x79f4a6cf, "_gpl");
SYMBOL_CRC(addi_watchdog_init, 0x26d0bcd2, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xf1c0f6f4, "comedi_alloc_spriv" },
	{ 0x2587f789, "_dev_info" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "011FC16D41FD938A00158C8");
