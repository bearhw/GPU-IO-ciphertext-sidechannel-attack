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

SYMBOL_CRC(apple_bl_register, 0x2c63e051, "_gpl");
SYMBOL_CRC(apple_bl_unregister, 0xdab0f892, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xf0cd6f57, "acpi_bus_unregister_driver" },
	{ 0x327bd7da, "acpi_bus_register_driver" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x85bd1608, "__request_region" },
	{ 0x9e5f9556, "backlight_device_register" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:APP0002:*");

MODULE_INFO(srcversion, "2F3CEB15C3D31BE5ED0E17F");
