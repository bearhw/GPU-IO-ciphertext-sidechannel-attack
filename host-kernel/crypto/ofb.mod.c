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
	{ 0xa1095163, "skcipher_alloc_instance_simple" },
	{ 0x351c3ac0, "skcipher_register_instance" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa44449bb, "skcipher_walk_virt" },
	{ 0xcedb3edf, "crypto_cipher_encrypt_one" },
	{ 0xa3f12f69, "__crypto_xor" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfd9dcc31, "crypto_register_template" },
	{ 0x8e04220, "crypto_unregister_template" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C38996459D70A475AAB8E36");
