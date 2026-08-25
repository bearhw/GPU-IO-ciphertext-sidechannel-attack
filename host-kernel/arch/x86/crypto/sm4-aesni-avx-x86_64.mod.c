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

SYMBOL_CRC(sm4_avx_ecb_encrypt, 0x5a5281bf, "_gpl");
SYMBOL_CRC(sm4_avx_ecb_decrypt, 0xe63bd261, "_gpl");
SYMBOL_CRC(sm4_cbc_encrypt, 0x601119bd, "_gpl");
SYMBOL_CRC(sm4_avx_cbc_decrypt, 0xae96a312, "_gpl");
SYMBOL_CRC(sm4_cfb_encrypt, 0x0a64c200, "_gpl");
SYMBOL_CRC(sm4_avx_cfb_decrypt, 0x44dcd6fb, "_gpl");
SYMBOL_CRC(sm4_avx_ctr_crypt, 0xf02ae7d6, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x3ef051c8, "crypto_inc" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa44449bb, "skcipher_walk_virt" },
	{ 0xbe883784, "simd_register_skciphers_compat" },
	{ 0x24e254e8, "sm4_expandkey" },
	{ 0xcaa68533, "cpu_has_xfeatures" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0xfa81970e, "sm4_crypt_block" },
	{ 0xb8fb702c, "simd_unregister_skciphers" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xa3f12f69, "__crypto_xor" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "crypto_simd,sm4");


MODULE_INFO(srcversion, "84570D7A6F9619EB019F5FC");
