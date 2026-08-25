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
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x1c4c2d08, "parport_remove_port" },
	{ 0xedc03953, "iounmap" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x37a0cba, "kfree" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0xfcec0987, "enable_irq" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0xde80cd09, "ioremap" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0xc15defcd, "parport_register_port" },
	{ 0x5e3a3912, "parport_irq_handler" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x2587f789, "_dev_info" },
	{ 0xe6f675ad, "parport_announce_port" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xfa0f1ab6, "parport_ieee1284_epp_write_data" },
	{ 0xa05f234c, "parport_ieee1284_epp_read_data" },
	{ 0x116ebe07, "parport_ieee1284_epp_write_addr" },
	{ 0xf00a0aa6, "parport_ieee1284_epp_read_addr" },
	{ 0xddfcbbe3, "parport_ieee1284_ecp_write_data" },
	{ 0x14f82304, "parport_ieee1284_ecp_read_data" },
	{ 0x369d1f52, "parport_ieee1284_ecp_write_addr" },
	{ 0x98a97864, "parport_ieee1284_write_compat" },
	{ 0x9b74c762, "parport_ieee1284_read_nibble" },
	{ 0x2113cc70, "parport_ieee1284_read_byte" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "parport");


MODULE_INFO(srcversion, "2FCBBBFDDF4069F58DE7EA0");
