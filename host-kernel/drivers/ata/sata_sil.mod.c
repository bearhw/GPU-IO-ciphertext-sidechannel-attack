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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2587f789, "_dev_info" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0x848d372e, "iowrite8" },
	{ 0xbf397c9e, "ata_sff_dma_pause" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xc6067da7, "ata_bmdma_irq_clear" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb19b445, "ioread8" },
	{ 0xafddd545, "ata_id_c_string" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x92997ed8, "_printk" },
	{ 0xeaeb5869, "ata_do_set_mode" },
	{ 0xe39abc12, "ata_dev_next" },
	{ 0x87b8798d, "sg_next" },
	{ 0x50877b9, "dmi_first_match" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x73a48b4a, "ata_sff_std_ports" },
	{ 0xf1385f92, "ata_port_pbar_desc" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x48e28e6, "pcim_pin_device" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xbb2509b2, "ata_port_freeze" },
	{ 0x3e7e918c, "ata_sff_hsm_move" },
	{ 0x973f082a, "ata_ehi_push_desc" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x9e199007, "ata_bmdma32_port_ops" },
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
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001095d00003112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001095d00000240sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001095d00003512sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001095d00003114sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000436Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004379sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000437Asv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "088CB79E9409BC95A0C3A5F");
