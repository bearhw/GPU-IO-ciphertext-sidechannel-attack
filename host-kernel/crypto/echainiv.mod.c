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
	{ 0x845dbf3b, "scatterwalk_map_and_copy" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0xfb578fc5, "memset" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x58a997dd, "aead_geniv_alloc" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7b35ca39, "aead_init_geniv" },
	{ 0x8f840193, "aead_exit_geniv" },
	{ 0x1a7bb158, "aead_register_instance" },
	{ 0xfd9dcc31, "crypto_register_template" },
	{ 0x8e04220, "crypto_unregister_template" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1076131CD0C90A1E35F85A7");
