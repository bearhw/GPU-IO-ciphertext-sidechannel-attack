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
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x92997ed8, "_printk" },
	{ 0x58cadab8, "dm_report_zones" },
	{ 0x754d539c, "strlen" },
	{ 0x349cba85, "strchr" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfb578fc5, "memset" },
	{ 0x69acdf38, "memcpy" },
	{ 0x2003eebe, "crypto_skcipher_setkey" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x96848186, "scnprintf" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x37a0cba, "kfree" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x5240ee7, "percpu_counter_batch" },
	{ 0xe138fb8c, "percpu_counter_add_batch" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa5577939, "crypto_alloc_aead" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6a4924c, "crypto_alloc_skcipher" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xc77b4f92, "crypto_shash_update" },
	{ 0xd0ebc22, "bio_integrity_alloc" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7f60d7d7, "bio_integrity_add_page" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x266a4b08, "tasklet_unlock" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x53c25af3, "bio_alloc_clone" },
	{ 0xa09dd780, "bio_put" },
	{ 0x828d0cfd, "dm_submit_bio_remap" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x9265315, "crypto_shash_final" },
	{ 0xa3f12f69, "__crypto_xor" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xbacc0824, "crypto_alloc_shash" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xa6257a2f, "complete" },
	{ 0xd4afbc82, "dm_audit_log_bio" },
	{ 0x86490580, "current_task" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x815f2897, "empty_zero_page" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xc131710d, "crypto_req_done" },
	{ 0xe9f7e02c, "crypto_skcipher_encrypt" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x1000e51, "schedule" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x6d606913, "pv_ops" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0xece784c2, "rb_first" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0x50cf7585, "hex2bin" },
	{ 0x11089ac7, "_ctype" },
	{ 0x5a921311, "strncmp" },
	{ 0x3cc4b494, "key_type_trusted" },
	{ 0x911131c3, "key_type_logon" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0xedcdca80, "request_key_tag" },
	{ 0x668b19a1, "down_read" },
	{ 0x53b954a2, "up_read" },
	{ 0x30933ff0, "key_put" },
	{ 0x6084ed79, "key_type_user" },
	{ 0xeeae3e8, "key_type_encrypted" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x2c07ddf, "bioset_exit" },
	{ 0x38e46431, "mempool_exit" },
	{ 0x53126ecc, "__percpu_counter_sum" },
	{ 0xac537ac2, "percpu_counter_destroy" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x944375db, "_totalram_pages" },
	{ 0xab2cad47, "dm_audit_log_ti" },
	{ 0x9f984513, "strrchr" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x9166fada, "strncpy" },
	{ 0xc941264c, "crypto_alloc_ahash" },
	{ 0xabe5fe4c, "dm_table_device_name" },
	{ 0x20cbb30a, "__percpu_counter_init" },
	{ 0xc7d094b5, "dm_read_arg_group" },
	{ 0x5eb24829, "dm_shift_arg" },
	{ 0x6a037cf1, "mempool_kfree" },
	{ 0xd35a6d31, "mempool_kmalloc" },
	{ 0x15c85de3, "mempool_init" },
	{ 0x85df9b6c, "strsep" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xe08efff5, "bioset_init" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0xb1b06a8f, "dm_table_get_md" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0xd07f9dfc, "dm_device_name" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x21ef374c, "try_wait_for_completion" },
	{ 0x800473f, "__cond_resched" },
	{ 0x5af2d38a, "crypto_skcipher_decrypt" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0x56470118, "__warn_printk" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0xc849b0b6, "dm_accept_partial_bio" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "046CB93F6FC2D0CCEF610CA");
