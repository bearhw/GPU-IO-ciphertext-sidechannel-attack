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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x63a5e9da, "comedi_pci_auto_config" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xedc03953, "iounmap" },
	{ 0x4422a4e1, "comedi_pci_disable" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x2e40b323, "comedi_dio_insn_config" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x68b5d967, "comedi_8254_mm_init" },
	{ 0xd88c6b45, "comedi_8254_subdevice_init" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x2587f789, "_dev_info" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi,comedi_8254");

MODULE_ALIAS("pci:v00001435d00007520sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001435d00004520sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "3D8927BC78A7A80EBCCF06B");
