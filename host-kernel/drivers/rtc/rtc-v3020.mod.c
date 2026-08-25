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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xedc03953, "iounmap" },
	{ 0xde80cd09, "ioremap" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xb0d1656c, "gpio_free_array" },
	{ 0x9ba2bb2b, "gpio_request_array" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2587f789, "_dev_info" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0xe582fa0e, "gpio_to_desc" },
	{ 0x834b6d4, "gpiod_direction_output_raw" },
	{ 0x6a7d4e41, "gpiod_set_raw_value" },
	{ 0x551f15ad, "gpiod_direction_input" },
	{ 0x39799ac, "gpiod_get_raw_value" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "04DFC56E0B56FCF3D78D13F");
