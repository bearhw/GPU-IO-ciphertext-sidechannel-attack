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
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x3fe0bdf8, "comedi_load_firmware" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xbb52fc7f, "range_bipolar10" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xedc03953, "iounmap" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi,comedi_8255");

MODULE_ALIAS("pci:v00001616d00000409sv00001616sd00000002bc*sc*i*");
MODULE_ALIAS("pci:v00001616d00000409sv00001616sd00000004bc*sc*i*");

MODULE_INFO(srcversion, "645A1D0D6C6CD4AC058F38A");
