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
	{ 0xa9be1d81, "mite_buf_change" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x2e40b323, "comedi_dio_insn_config" },
	{ 0xe741a6bb, "comedi_buf_read_alloc" },
	{ 0xd56f697, "mite_prep_dma" },
	{ 0x3ca69576, "mite_dma_arm" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xba8043ee, "comedi_bytes_per_scan" },
	{ 0x6b76324b, "mite_init_ring_descriptors" },
	{ 0x64443d67, "ni_get_valid_routes" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x24b9787e, "ni_gpct_device_destroy" },
	{ 0x7d171675, "mite_free_ring" },
	{ 0x78e0b696, "mite_detach" },
	{ 0xedc03953, "iounmap" },
	{ 0x4422a4e1, "comedi_pci_disable" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x86490580, "current_task" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1fd339dc, "mite_sync_dma" },
	{ 0x3ffdcb71, "mite_bytes_in_transit" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0xc073fc32, "mite_ack_linkc" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0xbbd5bd70, "ni_tio_handle_interrupt" },
	{ 0x9d784270, "comedi_is_subdevice_running" },
	{ 0xb3e302a3, "ni_route_to_register" },
	{ 0x9b5dbf58, "comedi_bytes_per_scan_cmd" },
	{ 0x76bc308, "ni_find_route_source" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xac1cf23a, "ni_tio_get_routing" },
	{ 0xab835de0, "mite_release_channel" },
	{ 0x46b3a51b, "mite_request_channel" },
	{ 0xc686ff80, "ni_tio_set_mite_channel" },
	{ 0xead5358, "ni_tio_acknowledge" },
	{ 0x45622ada, "ni_tio_cmd" },
	{ 0xb7169bec, "ni_tio_cancel" },
	{ 0x409afd9e, "ni_tio_unset_routing" },
	{ 0xd4e06b79, "ni_tio_set_routing" },
	{ 0x921123e, "ni_lookup_route_register" },
	{ 0xf14b6194, "comedi_buf_write_alloc" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0xea7586f0, "comedi_pci_enable" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0x8937566d, "mite_attach" },
	{ 0xaedc3735, "mite_alloc_ring" },
	{ 0x85e75c94, "ni_assign_device_routes" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0xdcd7c831, "ni_gpct_device_construct" },
	{ 0xbc68fce2, "ni_tio_init_counter" },
	{ 0xcd67167f, "ni_tio_insn_read" },
	{ 0x8c13f188, "ni_tio_insn_write" },
	{ 0x6a7fe1ee, "ni_tio_insn_config" },
	{ 0xca6df2d1, "ni_tio_cmdtest" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0xcd330f4, "range_unknown" },
	{ 0xb5892997, "comedi_pci_driver_register" },
	{ 0xa7ea0490, "comedi_pci_driver_unregister" },
	{ 0x8a4bf4b3, "comedi_pci_auto_unconfig" },
	{ 0x2f0ad9d3, "range_bipolar5" },
	{ 0xbb52fc7f, "range_bipolar10" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pci,mite,comedi,ni_routing,ni_tio,ni_tiocmd,comedi_8255");

MODULE_ALIAS("pci:v00001093d00000162sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001170sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001180sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001190sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000011B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000011C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000011D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001270sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001330sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001340sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001350sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000014E0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000014F0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001580sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000015B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001880sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001870sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000018B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000018C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002410sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002420sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002430sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002890sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000028C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002A60sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002A70sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002A80sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002AB0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002B80sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002B90sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002C80sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002CA0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070AAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070ABsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070ACsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070ADsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070AEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070AFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070BAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070BBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070BCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070BDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070BEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070BFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070F2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070F3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000710Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000716Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000716Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000717Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000717Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000071BCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000072E8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000072E9sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "1DEC8A9C1D6C38494A1572A");
