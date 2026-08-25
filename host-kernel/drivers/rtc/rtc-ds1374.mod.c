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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xf3e78736, "devm_free_irq" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x7a2fd204, "i2c_smbus_read_i2c_block_data" },
	{ 0x356461c8, "rtc_time64_to_tm" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfcec0987, "enable_irq" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x2df97cad, "i2c_smbus_write_i2c_block_data" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x941062c9, "device_set_wakeup_capable" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0x9e806b1c, "watchdog_init_timeout" },
	{ 0xd1f96cc2, "devm_watchdog_register_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x27bbf221, "disable_irq_nosync" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:ds1374");

MODULE_INFO(srcversion, "DF51EFB2D2DD8B4C0A02131");
