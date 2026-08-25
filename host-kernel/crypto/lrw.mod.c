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
	{ 0x5e373fb4, "gf128mul_64k_bbe" },
	{ 0xa44449bb, "skcipher_walk_virt" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0xd60736ec, "gf128mul_free_64k" },
	{ 0x3755f990, "gf128mul_init_64k_bbe" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xfa57f273, "crypto_spawn_tfm2" },
	{ 0x8bce639d, "crypto_drop_spawn" },
	{ 0x37a0cba, "kfree" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0x4934bdd0, "crypto_check_attr_type" },
	{ 0x9a11a0fc, "crypto_attr_alg_name" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x39458f1d, "crypto_grab_skcipher" },
	{ 0xcaaae678, "crypto_inst_setname" },
	{ 0x5a921311, "strncmp" },
	{ 0xa916b694, "strnlen" },
	{ 0x69acdf38, "memcpy" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x351c3ac0, "skcipher_register_instance" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0xfd9dcc31, "crypto_register_template" },
	{ 0x8e04220, "crypto_unregister_template" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BFEC64829560707A02D33B7");
