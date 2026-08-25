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
	{ 0x17f341a0, "i8042_lock_chip" },
	{ 0x1b8b95ad, "i8042_unlock_chip" },
	{ 0x4fdee897, "i8042_command" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0x6f477cbc, "__platform_driver_probe" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("dmi*:svn*VIA*:pn*K8N800*:pvr*VT8204B*:");
MODULE_ALIAS("dmi*:svn*CLEVOCo.*:pn*M5x0N*:");
MODULE_ALIAS("dmi*:pvr*VT6198*:rvn*CLEVOCo.*:rn*M5X0V*:");
MODULE_ALIAS("dmi*:pvr*0106*:rvn*Clevo*:rn*D400P*:rvr*Rev.A*:");
MODULE_ALIAS("dmi*:pvr*Rev.A1*:rvn*Clevo,Co.*:rn*D400V/D470V*:rvr*SS78B*:");

MODULE_INFO(srcversion, "F5C4EE98D680886A090A966");
