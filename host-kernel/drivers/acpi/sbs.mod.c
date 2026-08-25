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
	{ 0x4f6c2360, "acpi_smbus_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x1c8984c7, "acpi_smbus_unregister_callback" },
	{ 0xde586c1e, "power_supply_unregister" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x37a0cba, "kfree" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x9ab91f64, "power_supply_get_drvdata" },
	{ 0x96eb492d, "acpi_smbus_write" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xf50180e4, "power_supply_register" },
	{ 0x2121e851, "device_create_file" },
	{ 0x92997ed8, "_printk" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x556cca46, "x86_apple_machine" },
	{ 0x87bd07bd, "acpi_smbus_register_callback" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0x327bd7da, "acpi_bus_register_driver" },
	{ 0xf0cd6f57, "acpi_bus_unregister_driver" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sbshc");

MODULE_ALIAS("acpi*:ACPI0002:*");

MODULE_INFO(srcversion, "747F00CF3FAA3F3E3DED8DB");
