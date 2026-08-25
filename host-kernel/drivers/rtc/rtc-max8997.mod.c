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
	{ 0x594bbd2, "max8997_write_reg" },
	{ 0xf9a482f9, "msleep" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0x5eec8c4b, "max8997_update_reg" },
	{ 0x7b62f2d3, "max8997_read_reg" },
	{ 0x92997ed8, "_printk" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x6fcc79d7, "max8997_bulk_read" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x46f1b605, "max8997_bulk_write" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0xa203e539, "irq_create_mapping_affinity" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("platform:max8997-rtc");

MODULE_INFO(srcversion, "76174828739DCAF1DFED3C2");
