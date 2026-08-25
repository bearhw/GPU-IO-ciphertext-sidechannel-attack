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
	{ 0x2e1a1b74, "regmap_write" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xf3f5b3f5, "device_get_next_child_node" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0xd8cad17f, "fwnode_property_present" },
	{ 0xb053cfac, "fwnode_property_read_string" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0x2085b347, "devm_pwm_get" },
	{ 0xd28544d1, "pwm_apply_state" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cti,lm3630a");
MODULE_ALIAS("of:N*T*Cti,lm3630aC*");
MODULE_ALIAS("i2c:lm3630a_bl");

MODULE_INFO(srcversion, "FAC20806CA2764FDB0C0B04");
