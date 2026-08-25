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

SYMBOL_CRC(chacha20poly1305_encrypt, 0x147c3f2e, "");
SYMBOL_CRC(xchacha20poly1305_encrypt, 0xce15a526, "");
SYMBOL_CRC(chacha20poly1305_decrypt, 0xc20134e7, "");
SYMBOL_CRC(xchacha20poly1305_decrypt, 0x521c7102, "");
SYMBOL_CRC(chacha20poly1305_encrypt_sg_inplace, 0x37b34b92, "");
SYMBOL_CRC(chacha20poly1305_decrypt_sg_inplace, 0x5b19e187, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xfaeb41b2, "poly1305_final_arch" },
	{ 0x220b49ab, "chacha_crypt_arch" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x815f2897, "empty_zero_page" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0xe1df0e1b, "poly1305_init_arch" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x5a44f8cb, "__crypto_memneq" },
	{ 0x845dbf3b, "scatterwalk_map_and_copy" },
	{ 0xdd8ec6bd, "hchacha_block_arch" },
	{ 0xdc94f829, "chacha_init_arch" },
	{ 0xd9ec23eb, "poly1305_update_arch" },
	{ 0xa3f12f69, "__crypto_xor" },
	{ 0x461d16ca, "sg_nents" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "poly1305-x86_64,chacha-x86_64");


MODULE_INFO(srcversion, "880F127E6893E33D1D163FD");
