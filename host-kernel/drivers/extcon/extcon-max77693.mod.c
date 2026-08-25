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
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9d67f7e3, "devm_input_allocate_device" },
	{ 0xe3660c7e, "input_set_capability" },
	{ 0xaddf64b0, "input_register_device" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x55784228, "regmap_irq_get_virq" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x47884890, "system_power_efficient_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xc2261e62, "input_event" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "38434005D43F639F9345B5E");
