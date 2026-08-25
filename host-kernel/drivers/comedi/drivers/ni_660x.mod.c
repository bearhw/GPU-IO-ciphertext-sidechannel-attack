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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xbbd5bd70, "ni_tio_handle_interrupt" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa9be1d81, "mite_buf_change" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x1fd339dc, "mite_sync_dma" },
	{ 0xcbd41e95, "comedi_buf_read_n_available" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x64443d67, "ni_get_valid_routes" },
	{ 0x46b3a51b, "mite_request_channel" },
	{ 0xc686ff80, "ni_tio_set_mite_channel" },
	{ 0xead5358, "ni_tio_acknowledge" },
	{ 0x45622ada, "ni_tio_cmd" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x24b9787e, "ni_gpct_device_destroy" },
	{ 0x7d171675, "mite_free_ring" },
	{ 0x78e0b696, "mite_detach" },
	{ 0xedc03953, "iounmap" },
	{ 0x4422a4e1, "comedi_pci_disable" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xb7169bec, "ni_tio_cancel" },
	{ 0xab835de0, "mite_release_channel" },
	{ 0x76bc308, "ni_find_route_source" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xac1cf23a, "ni_tio_get_routing" },
	{ 0xb3e302a3, "ni_route_to_register" },
	{ 0xd4e06b79, "ni_tio_set_routing" },
	{ 0x409afd9e, "ni_tio_unset_routing" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0x8937566d, "mite_attach" },
	{ 0xaedc3735, "mite_alloc_ring" },
	{ 0x85e75c94, "ni_assign_device_routes" },
	{ 0xdcd7c831, "ni_gpct_device_construct" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0xcd67167f, "ni_tio_insn_read" },
	{ 0x8c13f188, "ni_tio_insn_write" },
	{ 0x6a7fe1ee, "ni_tio_insn_config" },
	{ 0xca6df2d1, "ni_tio_cmdtest" },
	{ 0xbc68fce2, "ni_tio_init_counter" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,ni_tiocmd,comedi,mite,ni_routing,ni_tio");

MODULE_ALIAS("pci:v00001093d00001310sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001360sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002C60sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002DB0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002CC0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001E30sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001E40sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "3D45EA5264F9B6F7323A480");
