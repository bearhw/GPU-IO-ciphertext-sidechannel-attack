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
	{ 0x3293aa63, "devm_namespace_enable" },
	{ 0xda86dacb, "to_nd_region" },
	{ 0x4a72a372, "to_nd_dax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x1e4f408c, "nvdimm_setup_pfn" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9fb43a72, "dax_region_put" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x46adca73, "__nd_driver_register" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x56cc6ffc, "alloc_dax_region" },
	{ 0x3a454907, "devm_namespace_disable" },
	{ 0xd89b2a18, "devm_create_dev_dax" },
	{ 0x88de63b0, "nvdimm_namespace_common_probe" },
	{ 0x77358855, "iomem_resource" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B8955FF89C54BC0005CE389");
