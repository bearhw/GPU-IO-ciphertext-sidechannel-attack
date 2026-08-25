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
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xb4043948, "acpi_execute_simple_method" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x170ddf79, "acpi_install_notify_handler" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x1c58427f, "acpi_remove_notify_handler" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xb0101402, "sysfs_notify" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:INT3407:*");
MODULE_ALIAS("acpi*:INT3532:*");
MODULE_ALIAS("acpi*:INTC1047:*");
MODULE_ALIAS("acpi*:INTC1050:*");
MODULE_ALIAS("acpi*:INTC1060:*");
MODULE_ALIAS("acpi*:INTC1061:*");
MODULE_ALIAS("acpi*:INTC1065:*");
MODULE_ALIAS("acpi*:INTC1066:*");
MODULE_ALIAS("acpi*:INTC10A4:*");
MODULE_ALIAS("acpi*:INTC10A5:*");

MODULE_INFO(srcversion, "E1D87A62CD05E32ABFA354A");
