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

SYMBOL_CRC(ks0108_writedata, 0x48a70518, "_gpl");
SYMBOL_CRC(ks0108_writecontrol, 0xbf4774db, "_gpl");
SYMBOL_CRC(ks0108_displaystate, 0x14102f23, "_gpl");
SYMBOL_CRC(ks0108_startline, 0x4f506333, "_gpl");
SYMBOL_CRC(ks0108_address, 0xfee8ef7b, "_gpl");
SYMBOL_CRC(ks0108_page, 0xedde6df2, "_gpl");
SYMBOL_CRC(ks0108_isinited, 0x6edae968, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xd4c28eac, "parport_register_dev_model" },
	{ 0xe697454e, "parport_claim" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x41e3ce24, "parport_unregister_device" },
	{ 0x8b73974d, "parport_release" },
	{ 0xefbd5788, "__parport_register_driver" },
	{ 0x938e02c5, "parport_unregister_driver" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "parport");


MODULE_INFO(srcversion, "B6CAD5251AC21235C25BE9E");
