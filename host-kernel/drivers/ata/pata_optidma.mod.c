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
	{ 0x27f04e19, "pci_test_config_bits" },
	{ 0xe7b5377e, "ata_sff_prereset" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x3599c67a, "ata_pci_bmdma_init_one" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x92997ed8, "_printk" },
	{ 0x68a2f0ec, "ata_dev_pair" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x848d372e, "iowrite8" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xeaeb5869, "ata_do_set_mode" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0x4d3a2730, "ata_pci_device_resume" },
	{ 0x36753cab, "ata_cable_40wire" },
	{ 0x2761bdbf, "ata_bmdma_port_ops" },
	{ 0x55c3bbfb, "ata_scsi_queuecmd" },
	{ 0xa9cca2f6, "ata_scsi_ioctl" },
	{ 0x7c53ac28, "ata_scsi_slave_config" },
	{ 0x851271f, "ata_scsi_slave_destroy" },
	{ 0x15ca04ff, "ata_scsi_dma_need_drain" },
	{ 0x22f5fb25, "ata_std_bios_param" },
	{ 0x49761292, "ata_scsi_unlock_native_capacity" },
	{ 0x86faae37, "ata_common_sdev_groups" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001045d0000D568sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "00B6C608D2302D15DC7C04A");
