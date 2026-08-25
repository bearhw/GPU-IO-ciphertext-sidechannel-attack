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
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0x37a0cba, "kfree" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x16cb454, "fb_deferred_io_cleanup" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x5b36e1d1, "pwm_put" },
	{ 0xd28544d1, "pwm_apply_state" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3e343b7b, "sys_imageblit" },
	{ 0x1a1c7d7f, "sys_copyarea" },
	{ 0x63000ec2, "sys_fillrect" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x6d97917a, "devm_regulator_get_optional" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0xf235f72e, "device_property_read_u8_array" },
	{ 0xbb726018, "device_property_present" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x32294d1f, "fb_deferred_io_init" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x771d88be, "pwm_get" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x9e5f9556, "backlight_device_register" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2587f789, "_dev_info" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0xd1be46b0, "fb_sys_read" },
	{ 0xc5f26a2b, "fb_deferred_io_mmap" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sysimgblt,syscopyarea,sysfillrect,fb_sys_fops");

MODULE_ALIAS("i2c:ssd1305fb");
MODULE_ALIAS("i2c:ssd1306fb");
MODULE_ALIAS("i2c:ssd1307fb");
MODULE_ALIAS("i2c:ssd1309fb");
MODULE_ALIAS("of:N*T*Csolomon,ssd1305fb-i2c");
MODULE_ALIAS("of:N*T*Csolomon,ssd1305fb-i2cC*");
MODULE_ALIAS("of:N*T*Csolomon,ssd1306fb-i2c");
MODULE_ALIAS("of:N*T*Csolomon,ssd1306fb-i2cC*");
MODULE_ALIAS("of:N*T*Csolomon,ssd1307fb-i2c");
MODULE_ALIAS("of:N*T*Csolomon,ssd1307fb-i2cC*");
MODULE_ALIAS("of:N*T*Csolomon,ssd1309fb-i2c");
MODULE_ALIAS("of:N*T*Csolomon,ssd1309fb-i2cC*");

MODULE_INFO(srcversion, "B68AAC00F1CF5C015FD66F2");
