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
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0xc941264c, "crypto_alloc_ahash" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x26a93eb2, "verify_pkcs7_signature" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0x3abcdffb, "crypto_stats_get" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xc90df7e5, "dm_bufio_prefetch" },
	{ 0x96848186, "scnprintf" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb04f56ab, "dm_bufio_read" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x46a429db, "dm_bio_from_per_bio_data" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x50cf7585, "hex2bin" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xeca7949e, "dm_bufio_client_destroy" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x30933ff0, "key_put" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xc131710d, "crypto_req_done" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x5eb24829, "dm_shift_arg" },
	{ 0x3d86bedc, "dm_bufio_client_create" },
	{ 0xe6024e59, "dm_bufio_release" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0xf1e046cc, "panic" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x612bfd89, "errno_to_blk_status" },
	{ 0xfb578fc5, "memset" },
	{ 0xc7d094b5, "dm_read_arg_group" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x7e9b64ed, "crypto_ahash_final" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0xaeca8967, "blk_limits_io_min" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6a8ad92a, "dm_disk" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xedcdca80, "request_key_tag" },
	{ 0x56470118, "__warn_printk" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x3498d552, "crypto_stats_ahash_update" },
	{ 0xb1b06a8f, "dm_table_get_md" },
	{ 0xd991e3b9, "dm_bufio_get_device_size" },
	{ 0x6084ed79, "key_type_user" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x74dcd98c, "dm_bufio_get_aux_data" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x1e7bbcb3, "kernel_restart" },
	{ 0x53b954a2, "up_read" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dm-bufio");


MODULE_INFO(srcversion, "2AFDA9DAE9F58BE18646D43");
