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
	{ 0x6d606913, "pv_ops" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0xe39abc12, "ata_dev_next" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d19b607, "ata_timing_compute" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xef8bcfd2, "ata_sff_qc_issue" },
	{ 0x68a2f0ec, "ata_dev_pair" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x848d372e, "iowrite8" },
	{ 0xf6e874f5, "ata_timing_merge" },
	{ 0xb19b445, "ioread8" },
	{ 0xd2185039, "ata_sff_data_xfer32" },
	{ 0x6cc09945, "ioread32_rep" },
	{ 0xbfc177bc, "iowrite32_rep" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xfb4264e2, "ata_sff_data_xfer" },
	{ 0xde2ac54c, "ata_pio_need_iordy" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x85bd1608, "__request_region" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x90a7a78d, "devm_ioport_map" },
	{ 0xa9bece9, "ata_host_alloc" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x73a48b4a, "ata_sff_std_ports" },
	{ 0x6d435d09, "ata_port_desc" },
	{ 0x3a4f6a32, "ata_sff_interrupt" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0xa5efbf4c, "async_synchronize_full" },
	{ 0xa586d479, "ata_host_detach" },
	{ 0x36753cab, "ata_cable_40wire" },
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


MODULE_INFO(srcversion, "D260B0A4236464F98EA1F05");
