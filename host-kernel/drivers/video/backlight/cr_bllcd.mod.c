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
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0x946aad21, "devm_lcd_device_register" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "lcd");


MODULE_INFO(srcversion, "986A57AE4A8F6B629368D0B");
