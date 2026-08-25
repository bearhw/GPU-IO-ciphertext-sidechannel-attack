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
	{ 0x73e6c750, "ili9320_resume" },
	{ 0xdfe315d7, "ili9320_suspend" },
	{ 0xcec74e7, "ili9320_shutdown" },
	{ 0x63c5ac0a, "ili9320_remove" },
	{ 0xda9eee23, "ili9320_probe_spi" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe0d30147, "ili9320_write" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x108b76f2, "ili9320_write_regs" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ili9320");


MODULE_INFO(srcversion, "1DD5FA4B564D3BD93848001");
