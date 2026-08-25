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
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x58465e91, "intel_th_free" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7bd671b3, "acpi_match_device" },
	{ 0xd416f32e, "intel_th_alloc" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "intel_th");

MODULE_ALIAS("acpi*:INTC1000:*");
MODULE_ALIAS("acpi*:INTC1001:*");

MODULE_INFO(srcversion, "FE51CA45152971D232C17F8");
