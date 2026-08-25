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
	{ 0xa9be1d81, "mite_buf_change" },
	{ 0xfb578fc5, "memset" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xab835de0, "mite_release_channel" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xb27cc7b6, "mite_request_channel_in_range" },
	{ 0xf14b6194, "comedi_buf_write_alloc" },
	{ 0xd56f697, "mite_prep_dma" },
	{ 0x3ca69576, "mite_dma_arm" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x86490580, "current_task" },
	{ 0x1000e51, "schedule" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0x8937566d, "mite_attach" },
	{ 0xaedc3735, "mite_alloc_ring" },
	{ 0x3fe0bdf8, "comedi_load_firmware" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x2587f789, "_dev_info" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x7d171675, "mite_free_ring" },
	{ 0x78e0b696, "mite_detach" },
	{ 0xedc03953, "iounmap" },
	{ 0x4422a4e1, "comedi_pci_disable" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x2e40b323, "comedi_dio_insn_config" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x1fd339dc, "mite_sync_dma" },
	{ 0x6d606913, "pv_ops" },
	{ 0xc073fc32, "mite_ack_linkc" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,mite,comedi");

MODULE_ALIAS("pci:v00001093d00001150sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000012B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001320sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "84EEDA9919E135B5C1D4168");
