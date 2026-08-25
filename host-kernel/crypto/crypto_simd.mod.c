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

SYMBOL_CRC(simd_skcipher_create_compat, 0x88638552, "_gpl");
SYMBOL_CRC(simd_skcipher_create, 0x66983e96, "_gpl");
SYMBOL_CRC(simd_skcipher_free, 0xefe73979, "_gpl");
SYMBOL_CRC(simd_register_skciphers_compat, 0xbe883784, "_gpl");
SYMBOL_CRC(simd_unregister_skciphers, 0xb8fb702c, "_gpl");
SYMBOL_CRC(simd_aead_create_compat, 0x504cb053, "_gpl");
SYMBOL_CRC(simd_aead_create, 0x851c747c, "_gpl");
SYMBOL_CRC(simd_aead_free, 0xbfd26f15, "_gpl");
SYMBOL_CRC(simd_register_aeads_compat, 0xa6dee470, "_gpl");
SYMBOL_CRC(simd_unregister_aeads, 0xad024ce2, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0x611e75ae, "cryptd_alloc_aead" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x9e5d9bca, "cryptd_aead_child" },
	{ 0x73dd54eb, "irq_fpu_usable" },
	{ 0xcb0890e3, "crypto_register_aead" },
	{ 0xea91e76, "crypto_unregister_aead" },
	{ 0x37a0cba, "kfree" },
	{ 0xeb9ee9e5, "crypto_register_aeads" },
	{ 0xa5577939, "crypto_alloc_aead" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x7e006dc4, "crypto_unregister_aeads" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x9c216e3d, "cryptd_skcipher_child" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0x5befbd11, "cryptd_alloc_skcipher" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0x8fb5f174, "crypto_register_skcipher" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0x368dc019, "cryptd_aead_queued" },
	{ 0x53cee77b, "crypto_unregister_skcipher" },
	{ 0xe6a9a548, "crypto_register_skciphers" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xcab59a21, "cryptd_skcipher_queued" },
	{ 0x11e0e7fa, "cryptd_free_aead" },
	{ 0x27eee3d8, "crypto_unregister_skciphers" },
	{ 0x62e75ac4, "cryptd_free_skcipher" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x6a4924c, "crypto_alloc_skcipher" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cryptd");


MODULE_INFO(srcversion, "97509D0C432E67D3007BE03");
