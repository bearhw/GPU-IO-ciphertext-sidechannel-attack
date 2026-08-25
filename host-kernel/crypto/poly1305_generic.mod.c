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
	{ 0x7f376d08, "poly1305_final_generic" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x21f3700, "poly1305_core_blocks" },
	{ 0xd45b9cf4, "poly1305_core_setkey" },
	{ 0x69acdf38, "memcpy" },
	{ 0xaed5dc46, "crypto_register_shash" },
	{ 0x188426d5, "crypto_unregister_shash" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libpoly1305");


MODULE_INFO(srcversion, "6A9AAA3C76ACA84181DFF1A");
