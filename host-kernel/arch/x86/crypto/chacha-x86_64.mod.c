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

SYMBOL_CRC(hchacha_block_arch, 0xdd8ec6bd, "");
SYMBOL_CRC(chacha_init_arch, 0xdc94f829, "");
SYMBOL_CRC(chacha_crypt_arch, 0x220b49ab, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x73dd54eb, "irq_fpu_usable" },
	{ 0xcec122d7, "chacha_crypt_generic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0xaaa4b9bc, "hchacha_block_generic" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa44449bb, "skcipher_walk_virt" },
	{ 0xcaa68533, "cpu_has_xfeatures" },
	{ 0xe6a9a548, "crypto_register_skciphers" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x27eee3d8, "crypto_unregister_skciphers" },
	{ 0x6b2b69f7, "static_key_enable" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libchacha");


MODULE_INFO(srcversion, "9CC23658E0446443B5302C5");
