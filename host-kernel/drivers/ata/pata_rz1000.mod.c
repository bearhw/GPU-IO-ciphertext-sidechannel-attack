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
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0xf1e046cc, "panic" },
	{ 0xe39abc12, "ata_dev_next" },
	{ 0x92997ed8, "_printk" },
	{ 0xc629948, "ata_pci_sff_init_one" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0x36753cab, "ata_cable_40wire" },
	{ 0x734f0af5, "ata_sff_port_ops" },
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

MODULE_ALIAS("pci:v00001042d00001000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001042d00001001sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "8FD4507B3F13675EDD68FB5");
