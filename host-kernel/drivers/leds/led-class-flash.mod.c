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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(led_classdev_flash_register_ext, 0x16c36dbb, "_gpl");
SYMBOL_CRC(led_classdev_flash_unregister, 0x46bfcb53, "_gpl");
SYMBOL_CRC(devm_led_classdev_flash_register_ext, 0x1063441c, "_gpl");
SYMBOL_CRC(devm_led_classdev_flash_unregister, 0x4cf7ef5f, "_gpl");
SYMBOL_CRC(led_set_flash_timeout, 0x3dce8d1f, "_gpl");
SYMBOL_CRC(led_get_flash_fault, 0x882431fb, "_gpl");
SYMBOL_CRC(led_set_flash_brightness, 0x1f2dd0dc, "_gpl");
SYMBOL_CRC(led_update_flash_brightness, 0x9641e00c, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x867b5609, "devres_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x28de1031, "__devres_alloc_node" },
	{ 0xea900f57, "devres_add" },
	{ 0xe93e49c3, "devres_free" },
	{ 0x754d539c, "strlen" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5ABC2DB2DA6D017567CE862");
