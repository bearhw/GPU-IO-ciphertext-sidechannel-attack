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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0x131a5ed7, "regmap_del_irq_chip" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0xe9d549c4, "regmap_add_irq_chip" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x55784228, "regmap_irq_get_virq" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x47884890, "system_power_efficient_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x2587f789, "_dev_info" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:rt8973a");
MODULE_ALIAS("of:N*T*Crichtek,rt8973a-muic");
MODULE_ALIAS("of:N*T*Crichtek,rt8973a-muicC*");

MODULE_INFO(srcversion, "5E929B072E294D7FE425805");
