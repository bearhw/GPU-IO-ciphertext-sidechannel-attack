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
	{ 0x85f6adc3, "ptp_clock_unregister" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0x81db095, "ptp_clock_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x29ad8e33, "x86_hyper_type" },
	{ 0x327bd7da, "acpi_bus_register_driver" },
	{ 0xf0cd6f57, "acpi_bus_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:VMW0005:*");

MODULE_INFO(srcversion, "188B9501F71B9AD0C3834B4");
