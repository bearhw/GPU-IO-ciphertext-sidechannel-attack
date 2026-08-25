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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa44449bb, "skcipher_walk_virt" },
	{ 0xcec122d7, "chacha_crypt_generic" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xaaa4b9bc, "hchacha_block_generic" },
	{ 0xe6a9a548, "crypto_register_skciphers" },
	{ 0x27eee3d8, "crypto_unregister_skciphers" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libchacha");


MODULE_INFO(srcversion, "CA9645E79BB90334E04CEE3");
