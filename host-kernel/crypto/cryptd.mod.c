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

SYMBOL_CRC(cryptd_alloc_skcipher, 0x5befbd11, "_gpl");
SYMBOL_CRC(cryptd_skcipher_child, 0x9c216e3d, "_gpl");
SYMBOL_CRC(cryptd_skcipher_queued, 0xcab59a21, "_gpl");
SYMBOL_CRC(cryptd_free_skcipher, 0x62e75ac4, "_gpl");
SYMBOL_CRC(cryptd_alloc_ahash, 0x722c8dff, "_gpl");
SYMBOL_CRC(cryptd_ahash_child, 0x227aaf79, "_gpl");
SYMBOL_CRC(cryptd_shash_desc, 0x454e8eca, "_gpl");
SYMBOL_CRC(cryptd_ahash_queued, 0x06f3adf0, "_gpl");
SYMBOL_CRC(cryptd_free_ahash, 0xb40ed353, "_gpl");
SYMBOL_CRC(cryptd_alloc_aead, 0x611e75ae, "_gpl");
SYMBOL_CRC(cryptd_aead_child, 0x9e5d9bca, "_gpl");
SYMBOL_CRC(cryptd_aead_queued, 0x368dc019, "_gpl");
SYMBOL_CRC(cryptd_free_aead, 0x11e0e7fa, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x6a4924c, "crypto_alloc_skcipher" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc941264c, "crypto_alloc_ahash" },
	{ 0xa5577939, "crypto_alloc_aead" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0xfa57f273, "crypto_spawn_tfm2" },
	{ 0x8bce639d, "crypto_drop_spawn" },
	{ 0x37a0cba, "kfree" },
	{ 0x755b14b4, "crypto_shash_setkey" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x372076ef, "crypto_dequeue_request" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x7db4dbe9, "crypto_enqueue_request" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xfdbd7a17, "crypto_get_attr_type" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x9a11a0fc, "crypto_attr_alg_name" },
	{ 0x39458f1d, "crypto_grab_skcipher" },
	{ 0xa01fdea1, "crypto_grab_aead" },
	{ 0x1a7bb158, "aead_register_instance" },
	{ 0x14f01063, "crypto_grab_shash" },
	{ 0x95a5efe, "crypto_shash_alg_has_setkey" },
	{ 0x9d31c4b, "ahash_register_instance" },
	{ 0x351c3ac0, "skcipher_register_instance" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0xfb578fc5, "memset" },
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0x4ab863, "shash_ahash_digest" },
	{ 0x5b039e0d, "shash_ahash_finup" },
	{ 0x9265315, "crypto_shash_final" },
	{ 0x1556bcf5, "shash_ahash_update" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x499043d3, "crypto_init_queue" },
	{ 0x92997ed8, "_printk" },
	{ 0xfd9dcc31, "crypto_register_template" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x8e04220, "crypto_unregister_template" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "84A51E70A4BA769D4514B8D");
