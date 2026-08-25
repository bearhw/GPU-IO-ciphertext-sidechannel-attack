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
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xe818b32b, "ata_bmdma_interrupt" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xbb2509b2, "ata_port_freeze" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x50e9512e, "ata_sff_tf_load" },
	{ 0x5c8d37b4, "ata_bmdma_start" },
	{ 0x451e3e94, "ata_sff_pause" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xcab339e3, "ata_sff_wait_ready" },
	{ 0xf5b49047, "ata_msleep" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xc6067da7, "ata_bmdma_irq_clear" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xbb38e0c0, "ata_sff_error_handler" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0xa0bee1ae, "ata_pci_bmdma_prepare_host" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0xc7f0a716, "ata_slave_link_init" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x73a48b4a, "ata_sff_std_ports" },
	{ 0xf1385f92, "ata_port_pbar_desc" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2587f789, "_dev_info" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x62e8eab4, "sata_std_hardreset" },
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
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001106d00005337sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00000591sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003149sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00003249sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00005372sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00007372sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00005287sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00009000sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "D02B8C752BDC9941B11FCCB");
