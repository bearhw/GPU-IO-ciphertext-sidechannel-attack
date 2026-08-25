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
	{ 0xff09bd65, "camellia_dec_blk" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8d9b761c, "camellia_decrypt_cbc_2way" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0x69f4ff25, "__camellia_enc_blk_2way" },
	{ 0xa44449bb, "skcipher_walk_virt" },
	{ 0xbe883784, "simd_register_skciphers_compat" },
	{ 0x8b44ee75, "camellia_ecb_dec_16way" },
	{ 0xcaa68533, "cpu_has_xfeatures" },
	{ 0x339c33c5, "camellia_cbc_dec_16way" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0xb8fb702c, "simd_unregister_skciphers" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xb901549, "camellia_dec_blk_2way" },
	{ 0x2c8b5dbf, "camellia_ecb_enc_16way" },
	{ 0x8d725052, "__camellia_setkey" },
	{ 0xfe729ed6, "__camellia_enc_blk" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "camellia-x86_64,crypto_simd,camellia-aesni-avx-x86_64");


MODULE_INFO(srcversion, "59FF6D4C1F8EACE5AFF7D1A");
