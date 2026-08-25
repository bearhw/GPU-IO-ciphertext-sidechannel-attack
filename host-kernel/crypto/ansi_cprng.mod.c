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
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x7dfbc7a3, "crypto_cipher_setkey" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x92997ed8, "_printk" },
	{ 0x8f7b8ada, "crypto_alloc_base" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0xcedb3edf, "crypto_cipher_encrypt_one" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfb578fc5, "memset" },
	{ 0x2de1375f, "crypto_register_rngs" },
	{ 0x82f45f89, "crypto_unregister_rngs" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2D60F7AE5307BCCEC2FADA9");
