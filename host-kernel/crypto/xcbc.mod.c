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
	{ 0x7dfbc7a3, "crypto_cipher_setkey" },
	{ 0xcedb3edf, "crypto_cipher_encrypt_one" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfb578fc5, "memset" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xa152fa09, "crypto_spawn_tfm" },
	{ 0x4934bdd0, "crypto_check_attr_type" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x9a11a0fc, "crypto_attr_alg_name" },
	{ 0x50efe432, "crypto_grab_spawn" },
	{ 0x41a4c733, "shash_free_singlespawn_instance" },
	{ 0xcaaae678, "crypto_inst_setname" },
	{ 0xad8020d6, "shash_register_instance" },
	{ 0x69acdf38, "memcpy" },
	{ 0xa3f12f69, "__crypto_xor" },
	{ 0xfd9dcc31, "crypto_register_template" },
	{ 0x8e04220, "crypto_unregister_template" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "47CAEC5189F831A8FD50774");
