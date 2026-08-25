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
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0xf8f29f5f, "linedisp_unregister" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "line-display");

MODULE_ALIAS("of:N*T*Cimg,boston-lcd");
MODULE_ALIAS("of:N*T*Cimg,boston-lcdC*");
MODULE_ALIAS("of:N*T*Cmti,malta-lcd");
MODULE_ALIAS("of:N*T*Cmti,malta-lcdC*");
MODULE_ALIAS("of:N*T*Cmti,sead3-lcd");
MODULE_ALIAS("of:N*T*Cmti,sead3-lcdC*");

MODULE_INFO(srcversion, "7E70735B396661D2442BB54");
