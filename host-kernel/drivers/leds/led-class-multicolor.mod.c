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

SYMBOL_CRC(led_mc_calc_color_components, 0x99b2183f, "_gpl");
SYMBOL_CRC(led_classdev_multicolor_register_ext, 0x059a9e48, "_gpl");
SYMBOL_CRC(led_classdev_multicolor_unregister, 0x78d97403, "_gpl");
SYMBOL_CRC(devm_led_classdev_multicolor_register_ext, 0x12560dea, "_gpl");
SYMBOL_CRC(devm_led_classdev_multicolor_unregister, 0xcde01402, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x6b198c77, "led_colors" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x43744e2f, "led_set_brightness" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x867b5609, "devres_release" },
	{ 0x28de1031, "__devres_alloc_node" },
	{ 0xea900f57, "devres_add" },
	{ 0xe93e49c3, "devres_free" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FE94CE4CBC25B0523982273");
