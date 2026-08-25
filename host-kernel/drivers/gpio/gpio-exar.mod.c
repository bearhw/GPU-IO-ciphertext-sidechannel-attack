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
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x3f46d4da, "regmap_test_bits" },
	{ 0xffb7c514, "ida_free" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x90be2e92, "__devm_regmap_init_mmio_clk" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8D465DE0BBE5BACC06B56A2");
