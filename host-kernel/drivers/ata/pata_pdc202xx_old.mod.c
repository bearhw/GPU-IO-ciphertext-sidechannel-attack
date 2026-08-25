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
	{ 0x3599c67a, "ata_pci_bmdma_init_one" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xb19b445, "ioread8" },
	{ 0x848d372e, "iowrite8" },
	{ 0x5c8d37b4, "ata_bmdma_start" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3fe8dc70, "ata_bmdma_port_start" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xde2ac54c, "ata_pio_need_iordy" },
	{ 0x34ca18aa, "ata_bmdma_stop" },
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

MODULE_ALIAS("pci:v0000105Ad00004D33sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00004D38sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00000D38sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00000D30sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00004D30sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "9818FB7BA9621A5BED73E8B");
