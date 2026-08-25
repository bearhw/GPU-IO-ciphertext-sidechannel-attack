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
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x7465b024, "platform_device_add_resources" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0x47155238, "platform_device_add" },
	{ 0x2ad0effe, "mcb_release_bus" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x77358855, "iomem_resource" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x728a5a01, "mcb_alloc_bus" },
	{ 0x2434a5a3, "chameleon_parse_cells" },
	{ 0xe8e5654a, "mcb_bus_add_devices" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mcb");

MODULE_ALIAS("dmi*:svn*MEN*:pvr*14SC24*:");
MODULE_ALIAS("dmi*:svn*MEN*:pvr*14SC31*:");

MODULE_INFO(srcversion, "ED1C1406C267C1CD8D81488");
