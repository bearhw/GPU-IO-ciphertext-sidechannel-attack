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
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0xd92deb6b, "acpi_evaluate_object" },
	{ 0x37a0cba, "kfree" },
	{ 0x509b64ea, "acpi_has_method" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x2587f789, "_dev_info" },
	{ 0xb3f548ad, "kmemdup_nul" },
	{ 0x349cba85, "strchr" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:ACPI000E:*");

MODULE_INFO(srcversion, "F10642FE3B38EDD0177FF1C");
