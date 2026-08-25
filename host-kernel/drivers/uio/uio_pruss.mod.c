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
	{ 0xf14a7a00, "uio_unregister_device" },
	{ 0xedc03953, "iounmap" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0x60ba97c, "gen_pool_free_owner" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x815588a6, "clk_enable" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x486075c8, "gen_pool_dma_alloc" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xde80cd09, "ioremap" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0x9061f154, "__uio_register_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "uio");


MODULE_INFO(srcversion, "50B100557C3EA5AF5497009");
