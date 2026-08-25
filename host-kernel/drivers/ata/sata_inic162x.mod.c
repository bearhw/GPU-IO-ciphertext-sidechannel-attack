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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x87b8798d, "sg_next" },
	{ 0x8462cb62, "atapi_cmd_type" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3943995e, "dmam_alloc_attrs" },
	{ 0xcccfb2fa, "sata_deb_timing_hotplug" },
	{ 0x4fdc945d, "sata_deb_timing_normal" },
	{ 0xf9a482f9, "msleep" },
	{ 0xf5b49047, "ata_msleep" },
	{ 0x91d7e9fc, "sata_link_resume" },
	{ 0x1eecb0f0, "ata_link_online" },
	{ 0xb8e53f5e, "ata_wait_after_reset" },
	{ 0x3e952a00, "ata_port_classify" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x821a95c0, "ata_qc_complete" },
	{ 0x5899aa85, "ata_ehi_clear_desc" },
	{ 0x973f082a, "ata_ehi_push_desc" },
	{ 0x62f4d6d5, "ata_port_abort" },
	{ 0xbb2509b2, "ata_port_freeze" },
	{ 0x1eb9f673, "__ata_ehi_push_desc" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x60494799, "_dev_alert" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xf1385f92, "ata_port_pbar_desc" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0x6c60cbf4, "ata_std_error_handler" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0xa82c74e3, "sata_port_ops" },
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

MODULE_ALIAS("pci:v00001101d00001622sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "27ED004027413BA0C2DFE0B");
