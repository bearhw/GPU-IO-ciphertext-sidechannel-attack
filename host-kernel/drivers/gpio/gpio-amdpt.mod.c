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
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x3ae3d618, "bgpio_init" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "gpio-generic");

MODULE_ALIAS("acpi*:AMDF030:*");
MODULE_ALIAS("acpi*:AMDIF030:*");
MODULE_ALIAS("acpi*:AMDIF031:*");

MODULE_INFO(srcversion, "F5F5DC73EDB134A73BEEC65");
