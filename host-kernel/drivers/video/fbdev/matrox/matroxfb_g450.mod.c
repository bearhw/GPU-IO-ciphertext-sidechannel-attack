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

SYMBOL_CRC(matroxfb_g450_connect, 0x3a367f61, "");
SYMBOL_CRC(matroxfb_g450_shutdown, 0x28343d9a, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x587ec73b, "matroxfb_g450_setclk" },
	{ 0xbd26ced4, "g450_mnp2f" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x2743599c, "matroxfb_DAC_out" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3b35bc92, "matroxfb_DAC_in" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "g450_pll,matroxfb_misc");


MODULE_INFO(srcversion, "015211AE3D28068A35539FA");
