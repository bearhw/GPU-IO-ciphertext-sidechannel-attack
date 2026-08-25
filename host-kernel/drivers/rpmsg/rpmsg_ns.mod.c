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

SYMBOL_CRC(rpmsg_ns_register_device, 0x5d711499, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa46f34a4, "rpmsg_register_device_override" },
	{ 0x598e2047, "rpmsg_create_ept" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x9166fada, "strncpy" },
	{ 0x2587f789, "_dev_info" },
	{ 0xdcc3d2e3, "rpmsg_release_channel" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3561db2, "rpmsg_create_channel" },
	{ 0xc045240, "__register_rpmsg_driver" },
	{ 0x92997ed8, "_printk" },
	{ 0xcde91d2c, "unregister_rpmsg_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "rpmsg_core");


MODULE_INFO(srcversion, "64FD8BE01067D0930285B53");
