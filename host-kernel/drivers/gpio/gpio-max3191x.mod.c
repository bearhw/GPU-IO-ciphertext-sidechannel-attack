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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x12c94b1a, "gpiod_count" },
	{ 0x2ec0dae1, "devm_gpiod_get_array_optional" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x8b51deca, "spi_sync" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0x9c5d5b94, "crc8" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0xbb726018, "device_property_present" },
	{ 0x20dbf27, "bitmap_alloc" },
	{ 0xfb578fc5, "memset" },
	{ 0xc1ffba9, "gpiod_set_array_value_cansleep" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0x923d581, "devm_gpiod_put_array" },
	{ 0xb14fc46a, "find_next_clump8" },
	{ 0xaa8106bc, "crc8_populate_msb" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "crc8");

MODULE_ALIAS("spi:max31910");
MODULE_ALIAS("spi:max31911");
MODULE_ALIAS("spi:max31912");
MODULE_ALIAS("spi:max31913");
MODULE_ALIAS("spi:max31953");
MODULE_ALIAS("spi:max31963");

MODULE_INFO(srcversion, "85139AB2E4FDC44D2EBAC0F");
