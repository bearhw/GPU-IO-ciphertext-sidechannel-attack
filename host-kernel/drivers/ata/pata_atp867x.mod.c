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
	{ 0x6a86bc1, "iowrite16" },
	{ 0xb19b445, "ioread8" },
	{ 0x848d372e, "iowrite8" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0x92997ed8, "_printk" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2587f789, "_dev_info" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x48e28e6, "pcim_pin_device" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x73a48b4a, "ata_sff_std_ports" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x6d435d09, "ata_port_desc" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xe818b32b, "ata_bmdma_interrupt" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0x68a2f0ec, "ata_dev_pair" },
	{ 0x1d19b607, "ata_timing_compute" },
	{ 0xf6e874f5, "ata_timing_merge" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
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

MODULE_ALIAS("pci:v00001191d0000000Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001191d0000000Bsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "E049A5C0120E2738D83D295");
