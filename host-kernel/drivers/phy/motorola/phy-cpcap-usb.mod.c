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
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0xbd44d6b9, "pinctrl_select_state" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x9492220, "musb_mailbox" },
	{ 0xba8de3bf, "usb_remove_phy" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "musb_hdrc");


MODULE_INFO(srcversion, "6B0F9ED4F7F23AE6A15D9DA");
