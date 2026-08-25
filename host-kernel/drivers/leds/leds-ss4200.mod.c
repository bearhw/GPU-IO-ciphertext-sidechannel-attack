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
	{ 0x92997ed8, "_printk" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x85bd1608, "__request_region" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2587f789, "_dev_info" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d000027B8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000027B9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000027B0sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "68801E71CC84FBF63804663");
