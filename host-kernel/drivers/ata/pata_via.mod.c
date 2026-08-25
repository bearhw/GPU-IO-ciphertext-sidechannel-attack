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
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0x3fe8dc70, "ata_bmdma_port_start" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x27f04e19, "pci_test_config_bits" },
	{ 0xe7b5377e, "ata_sff_prereset" },
	{ 0x68a2f0ec, "ata_dev_pair" },
	{ 0x1d19b607, "ata_timing_compute" },
	{ 0xf6e874f5, "ata_timing_merge" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xafddd545, "ata_id_c_string" },
	{ 0x92997ed8, "_printk" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x1cd0ec24, "ata_acpi_cbl_80wire" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x3599c67a, "ata_pci_bmdma_init_one" },
	{ 0xeac76449, "ata_dummy_port_info" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x848d372e, "iowrite8" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0xd2185039, "ata_sff_data_xfer32" },
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

MODULE_ALIAS("pci:v00001106d00000415sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00000571sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00000581sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00001571sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003164sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00005324sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d0000C409sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00009001sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "04506FB3E939BD2C7481F0A");
