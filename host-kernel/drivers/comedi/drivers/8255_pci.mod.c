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
	{ 0x63a5e9da, "comedi_pci_auto_config" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x2b179514, "subdev_8255_mm_init" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0xedc03953, "iounmap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi,comedi_8255");

MODULE_ALIAS("pci:v0000144Ad00007224sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Ad00007248sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000144Ad00007296sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d0000000Bsv00000000sd00000000bc*sc*i*");
MODULE_ALIAS("pci:v00001307d0000000Bsv00001307sd0000000Bbc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000017sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00000160sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001630sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000013C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00000400sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001250sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000017D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001800sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "E771FEC92A067036DAD87F5");
