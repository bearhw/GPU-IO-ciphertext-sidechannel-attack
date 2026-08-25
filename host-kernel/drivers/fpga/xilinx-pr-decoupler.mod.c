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
	{ 0xba5e0275, "fpga_bridge_unregister" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0xf3643ec5, "fpga_bridge_register" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fpga-bridge");


MODULE_INFO(srcversion, "03E2C7839977A27FEC3AB20");
