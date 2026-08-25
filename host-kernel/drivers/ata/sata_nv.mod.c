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
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x7c53ac28, "ata_scsi_slave_config" },
	{ 0xafddd545, "ata_id_c_string" },
	{ 0xaef4aed4, "ata_scsi_change_queue_depth" },
	{ 0x92997ed8, "_printk" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x34ca18aa, "ata_bmdma_stop" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x848d372e, "iowrite8" },
	{ 0xb19b445, "ioread8" },
	{ 0x3f44709b, "ata_bmdma_error_handler" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xacd41c32, "blk_queue_segment_boundary" },
	{ 0xd2ce8dc4, "blk_queue_max_segments" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xc6067da7, "ata_bmdma_irq_clear" },
	{ 0x7915bab7, "ata_sff_tf_read" },
	{ 0xa8be71e5, "ata_bmdma_post_internal_cmd" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xcccfb2fa, "sata_deb_timing_hotplug" },
	{ 0xc094da0a, "sata_link_hardreset" },
	{ 0x4fdc945d, "sata_deb_timing_normal" },
	{ 0x91d7e9fc, "sata_link_resume" },
	{ 0x3fe8dc70, "ata_bmdma_port_start" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3943995e, "dmam_alloc_attrs" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xa0bee1ae, "ata_pci_bmdma_prepare_host" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xeef6b9d, "ata_pci_sff_activate_host" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x87b8798d, "sg_next" },
	{ 0xb79cfde, "ata_bmdma_qc_prep" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x7bfc26b9, "__tracepoint_ata_tf_load" },
	{ 0xde948f87, "__tracepoint_ata_exec_command" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xcf2b93c8, "__SCT__tp_func_ata_tf_load" },
	{ 0x46047827, "__SCT__tp_func_ata_exec_command" },
	{ 0x7d813863, "ata_bmdma_qc_issue" },
	{ 0x69518368, "ata_bmdma_port_intr" },
	{ 0x316cf72c, "ata_sff_check_status" },
	{ 0xbb2509b2, "ata_port_freeze" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xb31c4224, "ata_qc_get_active" },
	{ 0x3914ae2c, "ata_qc_complete_multiple" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x5899aa85, "ata_ehi_clear_desc" },
	{ 0x1eb9f673, "__ata_ehi_push_desc" },
	{ 0x973f082a, "ata_ehi_push_desc" },
	{ 0x62f4d6d5, "ata_port_abort" },
	{ 0xefea8670, "__tracepoint_ata_bmdma_status" },
	{ 0xd6ca37db, "sata_scr_read" },
	{ 0x69fbbe78, "sata_scr_write" },
	{ 0xc3e1021c, "__SCT__tp_func_ata_bmdma_status" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xe9c8768a, "ata_std_qc_defer" },
	{ 0x2761bdbf, "ata_bmdma_port_ops" },
	{ 0x55c3bbfb, "ata_scsi_queuecmd" },
	{ 0xa9cca2f6, "ata_scsi_ioctl" },
	{ 0x851271f, "ata_scsi_slave_destroy" },
	{ 0x15ca04ff, "ata_scsi_dma_need_drain" },
	{ 0x22f5fb25, "ata_std_bios_param" },
	{ 0x49761292, "ata_scsi_unlock_native_capacity" },
	{ 0x9f3c51a0, "ata_ncq_sdev_groups" },
	{ 0x86faae37, "ata_common_sdev_groups" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0x8c8aa660, "__SCK__tp_func_ata_bmdma_status" },
	{ 0xbdf4af97, "__SCK__tp_func_ata_exec_command" },
	{ 0x65e156bc, "__SCK__tp_func_ata_tf_load" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000010DEd0000008Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000000E3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000000EEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000054sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000055sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000036sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000003Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000266sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000267sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000037Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000037Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000003E7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000003F6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000003F7sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "8907FA75179D0CBFF03895A");
