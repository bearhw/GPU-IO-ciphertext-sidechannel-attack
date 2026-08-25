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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(gnss_serial_allocate, 0x5f481bcb, "_gpl");
SYMBOL_CRC(gnss_serial_free, 0x23bb0613, "_gpl");
SYMBOL_CRC(gnss_serial_register, 0xc2dba51a, "_gpl");
SYMBOL_CRC(gnss_serial_deregister, 0x14446c1b, "_gpl");
SYMBOL_CRC(gnss_serial_pm_ops, 0x9acf0a45, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9f714eee, "serdev_device_set_baudrate" },
	{ 0x30f65f59, "gnss_insert_raw" },
	{ 0x39fb1d99, "serdev_device_set_flow_control" },
	{ 0x37a0cba, "kfree" },
	{ 0x4e0865ed, "serdev_device_open" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x3f6de206, "serdev_device_write_wakeup" },
	{ 0x42751912, "serdev_device_write" },
	{ 0xe33e53c3, "serdev_device_wait_until_sent" },
	{ 0x157f3727, "gnss_allocate_device" },
	{ 0x16d88906, "gnss_deregister_device" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x5cf6e9c, "serdev_device_close" },
	{ 0x28f3d7ce, "gnss_register_device" },
	{ 0xb858e9c6, "gnss_put_device" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "gnss");


MODULE_INFO(srcversion, "772E499478228EE42CEFCCE");
