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
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x6d606913, "pv_ops" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xd7d18c4, "platform_get_resource_byname" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "15ADFD8F58F73BDBDEC49EF");
