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
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x74f001ac, "ata_pci_bmdma_clear_simplex" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x3599c67a, "ata_pci_bmdma_init_one" },
	{ 0xc629948, "ata_pci_sff_init_one" },
	{ 0x92997ed8, "_printk" },
	{ 0xafddd545, "ata_id_c_string" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x8462cb62, "atapi_cmd_type" },
	{ 0x19023ab9, "ata_sff_postreset" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x68a2f0ec, "ata_dev_pair" },
	{ 0x1d19b607, "ata_timing_compute" },
	{ 0xf6e874f5, "ata_timing_merge" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0x36753cab, "ata_cable_40wire" },
	{ 0x9e199007, "ata_bmdma32_port_ops" },
	{ 0xd2185039, "ata_sff_data_xfer32" },
	{ 0x734f0af5, "ata_sff_port_ops" },
	{ 0x55c3bbfb, "ata_scsi_queuecmd" },
	{ 0xa9cca2f6, "ata_scsi_ioctl" },
	{ 0x7c53ac28, "ata_scsi_slave_config" },
	{ 0x851271f, "ata_scsi_slave_destroy" },
	{ 0x15ca04ff, "ata_scsi_dma_need_drain" },
	{ 0x22f5fb25, "ata_std_bios_param" },
	{ 0x49761292, "ata_scsi_unlock_native_capacity" },
	{ 0x86faae37, "ata_common_sdev_groups" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000010B9d00005228sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010B9d00005229sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "2CF4AD28C336E4730B93594");
