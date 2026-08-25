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
	{ 0xf02ae7d6, "sm4_avx_ctr_crypt" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5a5281bf, "sm4_avx_ecb_encrypt" },
	{ 0xbe883784, "simd_register_skciphers_compat" },
	{ 0xe63bd261, "sm4_avx_ecb_decrypt" },
	{ 0x24e254e8, "sm4_expandkey" },
	{ 0xcaa68533, "cpu_has_xfeatures" },
	{ 0x601119bd, "sm4_cbc_encrypt" },
	{ 0xb8fb702c, "simd_unregister_skciphers" },
	{ 0xae96a312, "sm4_avx_cbc_decrypt" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xa64c200, "sm4_cfb_encrypt" },
	{ 0x44dcd6fb, "sm4_avx_cfb_decrypt" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sm4-aesni-avx-x86_64,crypto_simd,sm4");


MODULE_INFO(srcversion, "572B7C70FB862E614C687EE");
