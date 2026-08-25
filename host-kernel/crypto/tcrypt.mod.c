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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0x3abcdffb, "crypto_stats_get" },
	{ 0x3498d552, "crypto_stats_ahash_update" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0x92997ed8, "_printk" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x6a4924c, "crypto_alloc_skcipher" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xc131710d, "crypto_req_done" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x800473f, "__cond_resched" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xfb578fc5, "memset" },
	{ 0xc941264c, "crypto_alloc_ahash" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0x1f42e417, "crypto_ahash_setkey" },
	{ 0x347da517, "crypto_ahash_digest" },
	{ 0x7e9b64ed, "crypto_ahash_final" },
	{ 0xa5577939, "crypto_alloc_aead" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0x3bdb5d28, "alg_test" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x951a2773, "crypto_has_alg" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8FE7673EEA65B77C1EDC660");
