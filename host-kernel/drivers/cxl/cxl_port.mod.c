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
	{ 0xa40a8382, "get_device" },
	{ 0xeb55b07d, "is_cxl_memdev" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x148e4619, "devm_cxl_enumerate_decoders" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x5c538aa0, "devm_cxl_setup_hdm" },
	{ 0x9bc8f710, "devm_cxl_add_passthrough_decoder" },
	{ 0x9fcc31c8, "cxl_hdm_decode_init" },
	{ 0xff4ba120, "to_cxl_port" },
	{ 0x7f00d276, "__cxl_driver_register" },
	{ 0xbc31bd33, "cxl_driver_unregister" },
	{ 0x297d0a47, "schedule_cxl_memdev_detach" },
	{ 0xd5fd0a1f, "cxl_await_media_ready" },
	{ 0xf56929eb, "devm_cxl_port_enumerate_dports" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cxl_core");


MODULE_INFO(srcversion, "7075C365B99B0324591C74C");
