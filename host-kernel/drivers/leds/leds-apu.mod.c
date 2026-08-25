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
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x848d372e, "iowrite8" },
	{ 0x6d606913, "pv_ops" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x78ddb76b, "dmi_match" },
	{ 0x92997ed8, "_printk" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0x6f477cbc, "__platform_driver_probe" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("dmi*:svn*PCEngines*:pn*APU*:");
MODULE_ALIAS("dmi*:svn*PCEngines*:pn*apu1*:");

MODULE_INFO(srcversion, "E67C0BEB22889198C07443B");
