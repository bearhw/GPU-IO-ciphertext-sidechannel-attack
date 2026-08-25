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
	{ 0xfb578fc5, "memset" },
	{ 0xb3e302a3, "ni_route_to_register" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x92997ed8, "_printk" },
	{ 0x8ab47ba4, "ni_route_set_has_source" },
	{ 0x8f0f0901, "ni_find_route_set" },
	{ 0x85e75c94, "ni_assign_device_routes" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x863a306d, "ni_sort_device_routes" },
	{ 0x6c18c54e, "ni_count_valid_routes" },
	{ 0x64443d67, "ni_get_valid_routes" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x76bc308, "ni_find_route_source" },
	{ 0x1facf7f8, "ni_is_cmd_dest" },
	{ 0x921123e, "ni_lookup_route_register" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ni_routing");


MODULE_INFO(srcversion, "912E2A3DBC9C180295F364C");
