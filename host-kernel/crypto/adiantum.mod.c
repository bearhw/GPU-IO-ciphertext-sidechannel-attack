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
	{ 0xfa57f273, "crypto_spawn_tfm2" },
	{ 0xa152fa09, "crypto_spawn_tfm" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x461d16ca, "sg_nents" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0xc77b4f92, "crypto_shash_update" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0x9265315, "crypto_shash_final" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8bce639d, "crypto_drop_spawn" },
	{ 0x37a0cba, "kfree" },
	{ 0x845dbf3b, "scatterwalk_map_and_copy" },
	{ 0x1d6f5538, "crypto_cipher_decrypt_one" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x21f3700, "poly1305_core_blocks" },
	{ 0xbcb90cb3, "poly1305_core_emit" },
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0xcedb3edf, "crypto_cipher_encrypt_one" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xc131710d, "crypto_req_done" },
	{ 0x7dfbc7a3, "crypto_cipher_setkey" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0xd45b9cf4, "poly1305_core_setkey" },
	{ 0x755b14b4, "crypto_shash_setkey" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x4934bdd0, "crypto_check_attr_type" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x9a11a0fc, "crypto_attr_alg_name" },
	{ 0x39458f1d, "crypto_grab_skcipher" },
	{ 0x50efe432, "crypto_grab_spawn" },
	{ 0x14f01063, "crypto_grab_shash" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x92997ed8, "_printk" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x351c3ac0, "skcipher_register_instance" },
	{ 0xfd9dcc31, "crypto_register_template" },
	{ 0x8e04220, "crypto_unregister_template" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libpoly1305");


MODULE_INFO(srcversion, "E2DD3E9C82110E8C4F75C22");
