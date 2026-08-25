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
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x47884890, "system_power_efficient_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x1219496e, "iio_read_channel_raw" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0xa25e8c46, "devm_iio_channel_get" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0xdbdb0e8b, "request_any_context_irq" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "industrialio");


MODULE_INFO(srcversion, "BE8357ED423AB9D9E4CEA53");
