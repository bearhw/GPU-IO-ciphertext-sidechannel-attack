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
	{ 0xafddd545, "ata_id_c_string" },
	{ 0x1e6d26a8, "strstr" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0xe39abc12, "ata_dev_next" },
	{ 0x7d813863, "ata_bmdma_qc_issue" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xda409a7d, "ata_pci_device_do_resume" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x3599c67a, "ata_pci_bmdma_init_one" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x2587f789, "_dev_info" },
	{ 0xab95d250, "ata_do_dev_read_id" },
	{ 0x3fe8dc70, "ata_bmdma_port_start" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x848d372e, "iowrite8" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb19b445, "ioread8" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x37a0cba, "kfree" },
	{ 0x5fc67252, "ioread16_rep" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x34ca18aa, "ata_bmdma_stop" },
	{ 0x8c8e95a, "ata_sff_dev_select" },
	{ 0x5c8d37b4, "ata_bmdma_start" },
	{ 0x68a2f0ec, "ata_dev_pair" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
	{ 0xbd1f8765, "ata_pci_device_suspend" },
	{ 0x2761bdbf, "ata_bmdma_port_ops" },
	{ 0xc7266fbd, "ata_cable_unknown" },
	{ 0xf74a4ae0, "ata_cable_80wire" },
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

MODULE_ALIAS("pci:v00001283d00008211sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001283d00008212sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000017F3d00001010sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "B77B5C3F2A522B3E62835F5");
