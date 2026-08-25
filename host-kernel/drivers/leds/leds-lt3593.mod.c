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
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xce9da695, "device_get_child_node_count" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0xf3f5b3f5, "device_get_next_child_node" },
	{ 0xb053cfac, "fwnode_property_read_string" },
	{ 0x3dafe076, "devm_led_classdev_register_ext" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Clltc,lt3593");
MODULE_ALIAS("of:N*T*Clltc,lt3593C*");

MODULE_INFO(srcversion, "6873009F874136AAF18687F");
