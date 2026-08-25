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
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9f714eee, "serdev_device_set_baudrate" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0x30f65f59, "gnss_insert_raw" },
	{ 0x39fb1d99, "serdev_device_set_flow_control" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0x4e0865ed, "serdev_device_open" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x3f6de206, "serdev_device_write_wakeup" },
	{ 0x42751912, "serdev_device_write" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe33e53c3, "serdev_device_wait_until_sent" },
	{ 0xe120daca, "__serdev_device_driver_register" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x157f3727, "gnss_allocate_device" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x16d88906, "gnss_deregister_device" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x5cf6e9c, "serdev_device_close" },
	{ 0x28f3d7ce, "gnss_register_device" },
	{ 0xb858e9c6, "gnss_put_device" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xf9a482f9, "msleep" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "gnss");


MODULE_INFO(srcversion, "5379F7AED809B86B12CC01A");
