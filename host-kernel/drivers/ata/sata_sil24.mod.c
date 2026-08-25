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
	{ 0x999436a, "ata_wait_register" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3943995e, "dmam_alloc_attrs" },
	{ 0xf1385f92, "ata_port_pbar_desc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xdf0c757f, "ata_tf_to_fis" },
	{ 0x69acdf38, "memcpy" },
	{ 0x87b8798d, "sg_next" },
	{ 0xe9c8768a, "ata_std_qc_defer" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x2fd44381, "pcie_set_readrq" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x2587f789, "_dev_info" },
	{ 0x54bf0e65, "pci_intx" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x92997ed8, "_printk" },
	{ 0x92d46bb0, "ata_eh_freeze_port" },
	{ 0xa2e251fd, "sata_pmp_error_handler" },
	{ 0x62e8eab4, "sata_std_hardreset" },
	{ 0x5fa4bab0, "sata_set_spd" },
	{ 0x1eecb0f0, "ata_link_online" },
	{ 0xc428068d, "sata_deb_timing_long" },
	{ 0x32efe0e4, "sata_link_debounce" },
	{ 0x155b0f72, "ata_link_offline" },
	{ 0xf5b49047, "ata_msleep" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0xa4c085f8, "ata_tf_from_fis" },
	{ 0x3e952a00, "ata_port_classify" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x3914ae2c, "ata_qc_complete_multiple" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf8f3a0fb, "ata_ratelimit" },
	{ 0xbb2509b2, "ata_port_freeze" },
	{ 0x5899aa85, "ata_ehi_clear_desc" },
	{ 0x973f082a, "ata_ehi_push_desc" },
	{ 0x85d3140e, "ata_link_abort" },
	{ 0x624ad0d2, "sata_async_notification" },
	{ 0x62f4d6d5, "ata_port_abort" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x53a9a01e, "sata_pmp_port_ops" },
	{ 0x55c3bbfb, "ata_scsi_queuecmd" },
	{ 0xa9cca2f6, "ata_scsi_ioctl" },
	{ 0x7c53ac28, "ata_scsi_slave_config" },
	{ 0x851271f, "ata_scsi_slave_destroy" },
	{ 0xaef4aed4, "ata_scsi_change_queue_depth" },
	{ 0x15ca04ff, "ata_scsi_dma_need_drain" },
	{ 0x22f5fb25, "ata_std_bios_param" },
	{ 0x49761292, "ata_scsi_unlock_native_capacity" },
	{ 0x9f3c51a0, "ata_ncq_sdev_groups" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001095d00003124sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003124sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001095d00003132sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001095d00000242sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001095d00000244sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001095d00003131sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001095d00003531sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "302C4F957F353B6BC88DC51");
