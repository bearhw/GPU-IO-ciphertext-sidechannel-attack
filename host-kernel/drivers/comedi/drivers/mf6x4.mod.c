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
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xbb52fc7f, "range_bipolar10" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x842c8e9d, "ioread16" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xedc03953, "iounmap" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi");

MODULE_ALIAS("pci:v0000186Cd00000634sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000186Cd00000624sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "A5175F8B2DE4691F7667CF9");
