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
	{ 0xb86aa4a3, "bdev_alignment_offset" },
	{ 0x14fa2140, "sbc_parse_cdb" },
	{ 0x7f70af7a, "target_to_linux_sector" },
	{ 0xe3a87077, "blkdev_issue_discard" },
	{ 0x92997ed8, "_printk" },
	{ 0x37a0cba, "kfree" },
	{ 0xa09dd780, "bio_put" },
	{ 0x6cab4b6b, "target_complete_cmd" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0x9af19ea7, "fs_bio_set" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x6bce7da8, "blkdev_put" },
	{ 0x2c07ddf, "bioset_exit" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x85df9b6c, "strsep" },
	{ 0x44e9a829, "match_token" },
	{ 0xacf4d843, "match_strdup" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x3539f11b, "match_strlcpy" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xe08efff5, "bioset_init" },
	{ 0x28aee912, "blkdev_get_by_path" },
	{ 0xa42e29af, "target_configure_unmap_from_queue" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x5264eb17, "bioset_integrity_create" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd0ebc22, "bio_integrity_alloc" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0x7f60d7d7, "bio_integrity_add_page" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x87b8798d, "sg_next" },
	{ 0xa668688f, "sbc_get_write_same_sectors" },
	{ 0x800473f, "__cond_resched" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0xc5e94d26, "blkdev_issue_zeroout" },
	{ 0xec722f37, "transport_backend_register" },
	{ 0xded62f97, "target_backend_unregister" },
	{ 0xf7dcd754, "sbc_get_device_type" },
	{ 0x58dfdea7, "sbc_attrib_attrs" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "target_core_mod");


MODULE_INFO(srcversion, "8CEF549FD0965A110A17B1C");
