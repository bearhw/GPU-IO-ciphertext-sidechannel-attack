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
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0x6450e28b, "pps_unregister_source" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x2587f789, "_dev_info" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x24d273d1, "add_timer" },
	{ 0x4cb27100, "ktime_get_snapshot" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0xe272a15f, "gpiod_get_value" },
	{ 0x48bb1255, "pps_event" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0xbb726018, "device_property_present" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x4af699f6, "pps_register_source" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cpps-gpio");
MODULE_ALIAS("of:N*T*Cpps-gpioC*");

MODULE_INFO(srcversion, "1736904523CD35BAC14DF35");
