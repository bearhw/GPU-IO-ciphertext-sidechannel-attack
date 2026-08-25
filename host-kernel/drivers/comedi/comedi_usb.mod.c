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

SYMBOL_CRC(comedi_to_usb_interface, 0xa3c6cf82, "_gpl");
SYMBOL_CRC(comedi_to_usb_dev, 0xa4b6b817, "_gpl");
SYMBOL_CRC(comedi_usb_auto_config, 0xe142ae3c, "_gpl");
SYMBOL_CRC(comedi_usb_auto_unconfig, 0x32d675bb, "_gpl");
SYMBOL_CRC(comedi_usb_driver_register, 0x3b8b9015, "_gpl");
SYMBOL_CRC(comedi_usb_driver_unregister, 0x777dfa46, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa1ed73ab, "comedi_auto_config" },
	{ 0x5575ac06, "comedi_auto_unconfig" },
	{ 0x821e463, "usb_deregister" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "E273026B679CCF16F713FCF");
