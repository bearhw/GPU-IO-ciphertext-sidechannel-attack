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

SYMBOL_CRC(ni_assign_device_routes, 0x85e75c94, "_gpl");
SYMBOL_CRC(ni_count_valid_routes, 0x6c18c54e, "_gpl");
SYMBOL_CRC(ni_get_valid_routes, 0x64443d67, "_gpl");
SYMBOL_CRC(ni_is_cmd_dest, 0x1facf7f8, "_gpl");
SYMBOL_CRC(ni_sort_device_routes, 0x863a306d, "_gpl");
SYMBOL_CRC(ni_find_route_set, 0x8f0f0901, "_gpl");
SYMBOL_CRC(ni_route_set_has_source, 0x8ab47ba4, "_gpl");
SYMBOL_CRC(ni_lookup_route_register, 0x0921123e, "_gpl");
SYMBOL_CRC(ni_route_to_register, 0xb3e302a3, "_gpl");
SYMBOL_CRC(ni_find_route_source, 0x076bc308, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x1057a279, "bsearch" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb7c0f443, "sort" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7B8049CD37957340D124E4E");
