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
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0xc0d4ea32, "comedi_8254_pacer_enable" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xc0424174, "comedi_8254_init" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xbb52fc7f, "range_bipolar10" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa6b3c164, "pci_dev_get" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x798b7aa6, "comedi_set_hw_dev" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x44a53057, "comedi_8254_cascade_ns_to_timer" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x2d446dbb, "comedi_8254_update_divisors" },
	{ 0x708b5064, "comedi_8254_load" },
	{ 0x2587f789, "_dev_info" },
	{ 0x6ed165e0, "comedi_nsamples_left" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi,comedi_8254");

MODULE_ALIAS("pci:v000010E8d000080D9sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "2462CA5DE8AD11CA400DF86");
