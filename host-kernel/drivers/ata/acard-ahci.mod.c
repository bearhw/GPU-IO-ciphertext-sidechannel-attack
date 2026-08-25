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
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0x18825c8b, "ahci_reset_controller" },
	{ 0xc9f1ef1, "ahci_init_controller" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa4c085f8, "ata_tf_from_fis" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3943995e, "dmam_alloc_attrs" },
	{ 0x25c2ae69, "ahci_port_resume" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xfe9e8a82, "pcim_iomap_regions_request_all" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xb9ed2d3a, "ahci_save_initial_config" },
	{ 0x1c496d9e, "ahci_set_em_messages" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0xf1385f92, "ata_port_pbar_desc" },
	{ 0xc03ebe7f, "ata_dummy_port_ops" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x9ab89f8, "ahci_print_info" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xb6e9da2d, "ahci_host_activate" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0xea50dad3, "ahci_ignore_sss" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x48e28e6, "pcim_pin_device" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xdf0c757f, "ata_tf_to_fis" },
	{ 0x69acdf38, "memcpy" },
	{ 0x517de13f, "ahci_fill_cmd_slot" },
	{ 0x87b8798d, "sg_next" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0x9bf952f4, "ahci_ops" },
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
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libahci");

MODULE_ALIAS("pci:v00001191d0000000Dsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "B5B62A96E49D97E7EF4C66B");
