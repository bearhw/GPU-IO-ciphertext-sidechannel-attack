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
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xf1385f92, "ata_port_pbar_desc" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xef8bcfd2, "ata_sff_qc_issue" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x821a95c0, "ata_qc_complete" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x316cf72c, "ata_sff_check_status" },
	{ 0xa56add88, "ata_sff_port_intr" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x5899aa85, "ata_ehi_clear_desc" },
	{ 0x973f082a, "ata_ehi_push_desc" },
	{ 0xbb2509b2, "ata_port_freeze" },
	{ 0x62f4d6d5, "ata_port_abort" },
	{ 0xbb38e0c0, "ata_sff_error_handler" },
	{ 0xe7b5377e, "ata_sff_prereset" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3943995e, "dmam_alloc_attrs" },
	{ 0x87b8798d, "sg_next" },
	{ 0xdf0c757f, "ata_tf_to_fis" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
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

MODULE_ALIAS("pci:v000015E9d00002068sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "3B95E94429175D3ACAE16AD");
