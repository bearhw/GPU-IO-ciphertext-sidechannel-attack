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

SYMBOL_CRC(crypto_nhpoly1305_setkey, 0xeac159c9, "");
SYMBOL_CRC(crypto_nhpoly1305_init, 0x2f76f977, "");
SYMBOL_CRC(crypto_nhpoly1305_update_helper, 0x97fc1fb2, "");
SYMBOL_CRC(crypto_nhpoly1305_update, 0xdfde8e95, "");
SYMBOL_CRC(crypto_nhpoly1305_final_helper, 0x8a20fad5, "");
SYMBOL_CRC(crypto_nhpoly1305_final, 0x05319b65, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x21f3700, "poly1305_core_blocks" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x69acdf38, "memcpy" },
	{ 0xbcb90cb3, "poly1305_core_emit" },
	{ 0xd45b9cf4, "poly1305_core_setkey" },
	{ 0xaed5dc46, "crypto_register_shash" },
	{ 0x188426d5, "crypto_unregister_shash" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libpoly1305");


MODULE_INFO(srcversion, "54F35292825464DE31AB053");
