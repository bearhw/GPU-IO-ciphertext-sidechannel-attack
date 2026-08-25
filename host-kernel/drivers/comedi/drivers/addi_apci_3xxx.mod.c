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
	{ 0x4ac45c9a, "comedi_timeout" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2e40b323, "comedi_dio_insn_config" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x774d818, "comedi_pci_detach" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,comedi");

MODULE_ALIAS("pci:v000015B8d00003010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d0000300Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d0000300Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003013sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003015sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003016sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003017sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003019sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d0000301Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d0000301Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d0000301Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d0000301Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d0000301Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d0000301Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003023sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d0000300Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003002sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003004sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B8d00003024sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "23FCCEDFF667B591FE67672");
