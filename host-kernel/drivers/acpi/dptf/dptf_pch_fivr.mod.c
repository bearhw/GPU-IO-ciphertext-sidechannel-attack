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
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xd92deb6b, "acpi_evaluate_object" },
	{ 0x37a0cba, "kfree" },
	{ 0x5f93525c, "acpi_extract_package" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xb4043948, "acpi_execute_simple_method" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:INTC1045:*");
MODULE_ALIAS("acpi*:INTC1049:*");
MODULE_ALIAS("acpi*:INTC1064:*");
MODULE_ALIAS("acpi*:INTC10A3:*");

MODULE_INFO(srcversion, "646DCD1B5CEE779A7CE7A8B");
