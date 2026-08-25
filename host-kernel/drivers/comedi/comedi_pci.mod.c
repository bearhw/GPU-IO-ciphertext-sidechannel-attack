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

SYMBOL_CRC(comedi_to_pci_dev, 0x6b019029, "_gpl");
SYMBOL_CRC(comedi_pci_enable, 0xea7586f0, "_gpl");
SYMBOL_CRC(comedi_pci_disable, 0x4422a4e1, "_gpl");
SYMBOL_CRC(comedi_pci_detach, 0x0774d818, "_gpl");
SYMBOL_CRC(comedi_pci_auto_config, 0x63a5e9da, "_gpl");
SYMBOL_CRC(comedi_pci_auto_unconfig, 0x8a4bf4b3, "_gpl");
SYMBOL_CRC(comedi_pci_driver_register, 0xb5892997, "_gpl");
SYMBOL_CRC(comedi_pci_driver_unregister, 0xa7ea0490, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xa1ed73ab, "comedi_auto_config" },
	{ 0x5575ac06, "comedi_auto_unconfig" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "F0F3D262B8D1C6934D164D4");
