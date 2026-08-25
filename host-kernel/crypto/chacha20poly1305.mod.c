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
	{ 0x69acdf38, "memcpy" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xfa57f273, "crypto_spawn_tfm2" },
	{ 0x8bce639d, "crypto_drop_spawn" },
	{ 0x37a0cba, "kfree" },
	{ 0x4934bdd0, "crypto_check_attr_type" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x9a11a0fc, "crypto_attr_alg_name" },
	{ 0x39458f1d, "crypto_grab_skcipher" },
	{ 0x9a470e16, "crypto_grab_ahash" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x1a7bb158, "aead_register_instance" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x845dbf3b, "scatterwalk_map_and_copy" },
	{ 0x5a44f8cb, "__crypto_memneq" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x5bbdfa26, "scatterwalk_ffwd" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x83bc8b71, "crypto_ahash_finup" },
	{ 0x3abcdffb, "crypto_stats_get" },
	{ 0x3498d552, "crypto_stats_ahash_update" },
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0xab0c0853, "crypto_register_templates" },
	{ 0xfee5286a, "crypto_unregister_templates" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F5B18879E5B292D231CD76C");
