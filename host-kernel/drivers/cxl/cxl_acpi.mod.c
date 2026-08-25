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
	{ 0x8e5bdc93, "to_cxl_decoder" },
	{ 0x76a14435, "acpi_device_hid" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0xda529bdd, "cxl_find_dport_by_dev" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x123d56f3, "cxl_decoder_autoremove" },
	{ 0x23a07715, "devm_cxl_add_dport" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x36173c1d, "phys_to_target_node" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5ace3c4c, "is_root_decoder" },
	{ 0x1ced2f38, "devm_cxl_add_nvdimm_bridge" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0x5c3bc265, "bus_for_each_dev" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x1fe605b2, "acpi_pci_find_root" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa05b3bab, "cxl_root_decoder_alloc" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x3aa44ed5, "devm_cxl_add_port" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0xa072c71c, "devm_cxl_register_pci_bus" },
	{ 0x31fc64d2, "cxl_bus_rescan" },
	{ 0x3b1e766e, "cxl_decoder_add" },
	{ 0xc331c3c7, "acpi_table_parse_cedt" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cxl_core");

MODULE_ALIAS("acpi*:ACPI0017:*");

MODULE_INFO(srcversion, "3603DB6EEE2DD9EB33D419D");
