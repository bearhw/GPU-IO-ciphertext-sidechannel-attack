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
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6d606913, "pv_ops" },
	{ 0x69518368, "ata_bmdma_port_intr" },
	{ 0xbb2509b2, "ata_port_freeze" },
	{ 0x62f4d6d5, "ata_port_abort" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x316cf72c, "ata_sff_check_status" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xf1385f92, "ata_port_pbar_desc" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0x48e28e6, "pcim_pin_device" },
	{ 0x54bf0e65, "pci_intx" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xb68a7dff, "ata_pci_remove_one" },
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

MODULE_ALIAS("pci:v00001725d00007174sv*sd*bc01sc06i00*");
MODULE_ALIAS("pci:v00008086d00003200sv*sd*bc01sc06i00*");

MODULE_INFO(srcversion, "4ACAFD2B8468C002AF05869");
