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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xb19b445, "ioread8" },
	{ 0x848d372e, "iowrite8" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xfd0bbb57, "pci_match_id" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x594bf15b, "ioport_map" },
	{ 0x2587f789, "_dev_info" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0xfc39e32f, "ioport_unmap" },
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001022d0000746Bsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "7EF3B9C41EB69A0335C23F0");
