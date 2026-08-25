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
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0xff81487d, "gpiod_remove_lookup_table" },
	{ 0x37a0cba, "kfree" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0x7954df, "gpiod_direction_output" },
	{ 0x551f15ad, "gpiod_direction_input" },
	{ 0x96a75a88, "gpiod_get_direction" },
	{ 0x7ae3095d, "gpiod_set_config" },
	{ 0x12c94b1a, "gpiod_count" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2a11d5c9, "devm_gpiod_get_index" },
	{ 0x7d9c7665, "gpiod_to_chip" },
	{ 0x533ac20c, "gpiod_cansleep" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xcbc03608, "desc_to_gpio" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0xe272a15f, "gpiod_get_value" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xb71589f0, "skip_spaces" },
	{ 0x20dbf27, "bitmap_alloc" },
	{ 0xa033d747, "next_arg" },
	{ 0x868acba5, "get_options" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x38aa1397, "gpiod_add_lookup_table" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0x1b015d25, "bitmap_parselist" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x5a921311, "strncmp" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xc1ffba9, "gpiod_set_array_value_cansleep" },
	{ 0xca63a378, "gpiod_set_array_value" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x922f45a6, "__bitmap_clear" },
	{ 0xd97442b1, "gpiod_get_array_value_cansleep" },
	{ 0x6143f927, "gpiod_get_array_value" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x1d40b6f3, "idr_for_each" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2880DF5FDFFF2B27E6EC54C");
