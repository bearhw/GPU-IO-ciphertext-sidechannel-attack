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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2587f789, "_dev_info" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xedc03953, "iounmap" },
	{ 0xc23582b6, "amplc_dio200_set_enhance" },
	{ 0x2b1d33ea, "amplc_dio200_common_attach" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,amplc_dio200_common");

MODULE_ALIAS("pci:v000014DCd0000000Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DCd0000000Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DCd00000011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DCd00000012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DCd00000014sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "A5B4123BA1BB327A584DD3C");
