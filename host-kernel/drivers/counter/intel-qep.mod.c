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
	{ 0x47392d90, "devm_counter_alloc" },
	{ 0x6f64e05d, "counter_priv" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0x4331a573, "devm_counter_add" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "counter");

MODULE_ALIAS("pci:v00008086d00004BC3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004B81sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004B82sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004B83sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "65758EAC2C49419A77E79F2");
