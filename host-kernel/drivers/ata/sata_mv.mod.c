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
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x19996497, "ata_host_suspend" },
	{ 0xa586d479, "ata_host_detach" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x2e1ca751, "clk_put" },
	{ 0xc8a6e45b, "phy_power_off" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x87b8798d, "sg_next" },
	{ 0xb19b445, "ioread8" },
	{ 0xbb2509b2, "ata_port_freeze" },
	{ 0xa2e251fd, "sata_pmp_error_handler" },
	{ 0x66a9d73, "ata_eh_analyze_ncq_error" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x201c9a21, "dmam_pool_create" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x2f7754a8, "dma_pool_free" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xbf397c9e, "ata_sff_dma_pause" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x60494799, "_dev_alert" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x82c40558, "clk_get" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x69f17cba, "devm_phy_optional_get" },
	{ 0x8fd79e71, "phy_power_on" },
	{ 0x815588a6, "clk_enable" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xf1385f92, "ata_port_pbar_desc" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x48e28e6, "pcim_pin_device" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x3e312e2e, "pci_try_set_mwi" },
	{ 0xb31c4224, "ata_qc_get_active" },
	{ 0x3914ae2c, "ata_qc_complete_multiple" },
	{ 0x62e8eab4, "sata_std_hardreset" },
	{ 0x3e1dede2, "ata_sff_softreset" },
	{ 0x678b96ec, "dma_pool_alloc" },
	{ 0xcccfb2fa, "sata_deb_timing_hotplug" },
	{ 0x4fdc945d, "sata_deb_timing_normal" },
	{ 0xc094da0a, "sata_link_hardreset" },
	{ 0xd6ca37db, "sata_scr_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x7d813863, "ata_bmdma_qc_issue" },
	{ 0xdf0c757f, "ata_tf_to_fis" },
	{ 0xf7a31902, "ata_sff_queue_pio_task" },
	{ 0x5899aa85, "ata_ehi_clear_desc" },
	{ 0x973f082a, "ata_ehi_push_desc" },
	{ 0x85d3140e, "ata_link_abort" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x986cc81b, "sata_scr_write_flush" },
	{ 0x6d606913, "pv_ops" },
	{ 0x69518368, "ata_bmdma_port_intr" },
	{ 0x155b0f72, "ata_link_offline" },
	{ 0x624ad0d2, "sata_async_notification" },
	{ 0x62f4d6d5, "ata_port_abort" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0x2761bdbf, "ata_bmdma_port_ops" },
	{ 0x734f0af5, "ata_sff_port_ops" },
	{ 0x55c3bbfb, "ata_scsi_queuecmd" },
	{ 0xa9cca2f6, "ata_scsi_ioctl" },
	{ 0x7c53ac28, "ata_scsi_slave_config" },
	{ 0x851271f, "ata_scsi_slave_destroy" },
	{ 0xaef4aed4, "ata_scsi_change_queue_depth" },
	{ 0x15ca04ff, "ata_scsi_dma_need_drain" },
	{ 0x22f5fb25, "ata_std_bios_param" },
	{ 0x49761292, "ata_scsi_unlock_native_capacity" },
	{ 0x9f3c51a0, "ata_ncq_sdev_groups" },
	{ 0x86faae37, "ata_common_sdev_groups" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000011ABd00005040sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00005041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00005080sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00005081sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00001720sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00001740sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00001742sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00006040sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00006041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00006042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00006080sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00006081sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00000241sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00000243sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00007042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00002300sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00002310sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "B7D16691DA08CB313B84DF5");
