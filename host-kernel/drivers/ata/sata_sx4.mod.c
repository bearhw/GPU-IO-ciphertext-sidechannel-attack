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
	{ 0xb19b445, "ioread8" },
	{ 0x59f3f569, "ata_sff_exec_command" },
	{ 0x50e9512e, "ata_sff_tf_load" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3943995e, "dmam_alloc_attrs" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0xbb38e0c0, "ata_sff_error_handler" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xef8bcfd2, "ata_sff_qc_issue" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3e1dede2, "ata_sff_softreset" },
	{ 0x87b8798d, "sg_next" },
	{ 0xf9a482f9, "msleep" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0x2587f789, "_dev_info" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xf1385f92, "ata_port_pbar_desc" },
	{ 0xfe57ed37, "ata_print_version" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0x48e28e6, "pcim_pin_device" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x821a95c0, "ata_qc_complete" },
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
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v0000105Ad00006622sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "2C01CF72FFDCB0E43C5D5E3");
