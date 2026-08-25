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
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xa0bee1ae, "ata_pci_bmdma_prepare_host" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x54bf0e65, "pci_intx" },
	{ 0xe818b32b, "ata_bmdma_interrupt" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0xc7f0a716, "ata_slave_link_init" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2587f789, "_dev_info" },
	{ 0x7ee0213d, "sis_info133_for_sata" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x2761bdbf, "ata_bmdma_port_ops" },
	{ 0x55c3bbfb, "ata_scsi_queuecmd" },
	{ 0xa9cca2f6, "ata_scsi_ioctl" },
	{ 0x7c53ac28, "ata_scsi_slave_config" },
	{ 0x851271f, "ata_scsi_slave_destroy" },
	{ 0x15ca04ff, "ata_scsi_dma_need_drain" },
	{ 0x22f5fb25, "ata_std_bios_param" },
	{ 0x49761292, "ata_scsi_unlock_native_capacity" },
	{ 0x86faae37, "ata_common_sdev_groups" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0x4d3a2730, "ata_pci_device_resume" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001039d00000180sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000181sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000182sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000183sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00001182sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00001183sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "757BDF33F92B6E2528F2B45");
