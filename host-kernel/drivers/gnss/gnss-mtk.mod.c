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
	{ 0xb26ae49c, "regulator_enable" },
	{ 0xc2dba51a, "gnss_serial_register" },
	{ 0x9acf0a45, "gnss_serial_pm_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6d97917a, "devm_regulator_get_optional" },
	{ 0x14446c1b, "gnss_serial_deregister" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x5f481bcb, "gnss_serial_allocate" },
	{ 0xe120daca, "__serdev_device_driver_register" },
	{ 0x23bb0613, "gnss_serial_free" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "gnss-serial");


MODULE_INFO(srcversion, "3C1659134765A8102606891");
