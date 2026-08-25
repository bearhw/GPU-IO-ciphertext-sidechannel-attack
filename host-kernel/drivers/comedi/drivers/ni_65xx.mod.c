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
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0xedc03953, "iounmap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi");

MODULE_ALIAS("pci:v00001093d00001710sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00007085sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00007086sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00007087sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00007088sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070A9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070C3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070C8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070C9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070CCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070CDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070D1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070D2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070D3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00007124sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00007125sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00007126sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00007127sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00007128sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000718Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000718Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000071C5sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "927936DCF7C18761B2C98E1");
