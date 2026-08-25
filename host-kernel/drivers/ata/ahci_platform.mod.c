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
	{ 0x8f723b28, "ahci_platform_get_resources" },
	{ 0x21bc7471, "ahci_platform_enable_resources" },
	{ 0x38e2bc4e, "acpi_device_get_match_data" },
	{ 0x55a6d850, "ahci_platform_init_host" },
	{ 0x3a809ee5, "ahci_platform_disable_resources" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xe4425ded, "ata_platform_remove_one" },
	{ 0xf3b22c13, "ahci_platform_shutdown" },
	{ 0x2f038755, "ahci_platform_suspend" },
	{ 0x6bd96b14, "ahci_platform_resume" },
	{ 0x55c3bbfb, "ata_scsi_queuecmd" },
	{ 0xa9cca2f6, "ata_scsi_ioctl" },
	{ 0x7c53ac28, "ata_scsi_slave_config" },
	{ 0x851271f, "ata_scsi_slave_destroy" },
	{ 0xaef4aed4, "ata_scsi_change_queue_depth" },
	{ 0x15ca04ff, "ata_scsi_dma_need_drain" },
	{ 0x22f5fb25, "ata_std_bios_param" },
	{ 0x49761292, "ata_scsi_unlock_native_capacity" },
	{ 0xfec4464e, "ahci_shost_groups" },
	{ 0xe403dd30, "ahci_sdev_groups" },
	{ 0x8f556191, "ahci_platform_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libahci_platform,libahci");

MODULE_ALIAS("acpi*:APMC0D33:*");
MODULE_ALIAS("acpi*:010601:*");
MODULE_ALIAS("of:N*T*Cgeneric-ahci");
MODULE_ALIAS("of:N*T*Cgeneric-ahciC*");
MODULE_ALIAS("of:N*T*Csnps,spear-ahci");
MODULE_ALIAS("of:N*T*Csnps,spear-ahciC*");
MODULE_ALIAS("of:N*T*Cibm,476gtr-ahci");
MODULE_ALIAS("of:N*T*Cibm,476gtr-ahciC*");
MODULE_ALIAS("of:N*T*Csnps,dwc-ahci");
MODULE_ALIAS("of:N*T*Csnps,dwc-ahciC*");
MODULE_ALIAS("of:N*T*Chisilicon,hisi-ahci");
MODULE_ALIAS("of:N*T*Chisilicon,hisi-ahciC*");
MODULE_ALIAS("of:N*T*Ccavium,octeon-7130-ahci");
MODULE_ALIAS("of:N*T*Ccavium,octeon-7130-ahciC*");

MODULE_INFO(srcversion, "8ED9BE3666003C041CE3F3D");
