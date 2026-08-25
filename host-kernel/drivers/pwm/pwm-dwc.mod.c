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
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0x74e9decc, "pwmchip_remove" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xa76b4903, "pwmchip_add" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d00004BB7sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "22A013436BC1FCC2B6B2BA7");
