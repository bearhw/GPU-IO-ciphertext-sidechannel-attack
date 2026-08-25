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

SYMBOL_CRC(__pata_platform_probe, 0x837d70d8, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe39abc12, "ata_dev_next" },
	{ 0x92997ed8, "_printk" },
	{ 0xa9bece9, "ata_host_alloc" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x734f0af5, "ata_sff_port_ops" },
	{ 0xc7266fbd, "ata_cable_unknown" },
	{ 0xd2185039, "ata_sff_data_xfer32" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x6d435d09, "ata_port_desc" },
	{ 0x3a4f6a32, "ata_sff_interrupt" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0xfb4264e2, "ata_sff_data_xfer" },
	{ 0x90a7a78d, "devm_ioport_map" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x944c1deb, "platform_get_mem_or_io" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xe4425ded, "ata_platform_remove_one" },
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


MODULE_INFO(srcversion, "B577FF9EAE20E49B43C046F");
