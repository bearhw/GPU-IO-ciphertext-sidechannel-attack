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
	{ 0xb8cd3a7f, "nf_logger_put" },
	{ 0xccfb4622, "nf_log_packet" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd1f2eee2, "nf_logger_find_get" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x67a704bf, "xt_register_target" },
	{ 0xa5d0ece2, "xt_unregister_target" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "70F12B049DBDCBA29D16B6F");
