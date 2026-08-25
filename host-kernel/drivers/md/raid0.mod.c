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
	{ 0xd75eb10d, "seq_printf" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x37a0cba, "kfree" },
	{ 0x92997ed8, "_printk" },
	{ 0x7c04c00f, "md_check_no_bitmap" },
	{ 0xdde44162, "acct_bioset_init" },
	{ 0xbb146a4b, "blk_queue_max_hw_sectors" },
	{ 0x156d36c0, "blk_queue_max_write_zeroes_sectors" },
	{ 0xb2aabc17, "blk_queue_max_discard_sectors" },
	{ 0xf8730f8f, "blk_queue_io_min" },
	{ 0x35e03f29, "blk_queue_io_opt" },
	{ 0x90d27bc3, "disk_stack_limits" },
	{ 0xac25495b, "md_set_array_sectors" },
	{ 0x5ef68429, "md_integrity_register" },
	{ 0x7ff8329b, "acct_bioset_exit" },
	{ 0x911fc621, "md_account_bio" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x54366892, "bio_split" },
	{ 0x9f218161, "bio_chain" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0xba97195a, "__tracepoint_block_bio_remap" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x273aff5c, "__SCT__tp_func_block_bio_remap" },
	{ 0x2c4354fc, "md_flush_request" },
	{ 0xb49090e0, "md_submit_discard_bio" },
	{ 0x21d6e3b6, "register_md_personality" },
	{ 0x4f2e94e7, "unregister_md_personality" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x1cd42933, "__SCK__tp_func_block_bio_remap" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "14AA683B41374D9D0CD4D82");
