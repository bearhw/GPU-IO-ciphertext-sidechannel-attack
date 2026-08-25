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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x37a0cba, "kfree" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xfa57f273, "crypto_spawn_tfm2" },
	{ 0x8f7b8ada, "crypto_alloc_base" },
	{ 0xbacc0824, "crypto_alloc_shash" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0xcedb3edf, "crypto_cipher_encrypt_one" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0x8bce639d, "crypto_drop_spawn" },
	{ 0x2479193e, "crypto_authenc_extractkeys" },
	{ 0xc77b4f92, "crypto_shash_update" },
	{ 0x80b75976, "crypto_shash_finup" },
	{ 0x7dfbc7a3, "crypto_cipher_setkey" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0x2be1612f, "crypto_shash_tfm_digest" },
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0x4230a8d7, "sg_nents_for_len" },
	{ 0x69acdf38, "memcpy" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x5bbdfa26, "scatterwalk_ffwd" },
	{ 0x845dbf3b, "scatterwalk_map_and_copy" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xfdbd7a17, "crypto_get_attr_type" },
	{ 0x9a11a0fc, "crypto_attr_alg_name" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x39458f1d, "crypto_grab_skcipher" },
	{ 0xa01fdea1, "crypto_grab_aead" },
	{ 0x5a921311, "strncmp" },
	{ 0x9f984513, "strrchr" },
	{ 0x349cba85, "strchr" },
	{ 0xf4d389a1, "crypto_alg_mod_lookup" },
	{ 0x64498c3e, "crypto_mod_put" },
	{ 0x92997ed8, "_printk" },
	{ 0x95a5efe, "crypto_shash_alg_has_setkey" },
	{ 0xa916b694, "strnlen" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x1a7bb158, "aead_register_instance" },
	{ 0x351c3ac0, "skcipher_register_instance" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xfd9dcc31, "crypto_register_template" },
	{ 0x8e04220, "crypto_unregister_template" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "authenc");


MODULE_INFO(srcversion, "6C391FBA9370E4FB4E9E09E");
