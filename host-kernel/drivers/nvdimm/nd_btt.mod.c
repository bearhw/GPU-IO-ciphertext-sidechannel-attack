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

SYMBOL_CRC(nvdimm_namespace_attach_btt, 0x9a376418, "");
SYMBOL_CRC(nvdimm_namespace_detach_btt, 0x37ff01c4, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x184c1121, "bio_integrity_prep" },
	{ 0x56232755, "__blk_alloc_disk" },
	{ 0x3980cab6, "page_endio" },
	{ 0x81088473, "blk_queue_logical_block_size" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x88330529, "device_add_disk" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3293aa63, "devm_namespace_enable" },
	{ 0xc0970890, "debugfs_create_u16" },
	{ 0xda86dacb, "to_nd_region" },
	{ 0x37a0cba, "kfree" },
	{ 0x499f0ecf, "nd_sb_checksum" },
	{ 0xc992db44, "nd_btt_arena_is_valid" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbc1c6683, "bio_end_io_acct_remapped" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x815f2897, "empty_zero_page" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb38a7c5a, "debugfs_create_x64" },
	{ 0xeae84dbe, "blk_queue_flag_set" },
	{ 0xf135e93f, "nd_dev_to_uuid" },
	{ 0x2587f789, "_dev_info" },
	{ 0xa1179cbd, "bio_start_io_acct" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xbbcc3fd9, "nd_region_release_lane" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe3f3d437, "set_capacity" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x8f381413, "del_gendisk" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x612bfd89, "errno_to_blk_status" },
	{ 0xc78e0e8c, "to_nd_btt" },
	{ 0x86490580, "current_task" },
	{ 0x66446fc1, "nd_region_acquire_lane" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xd713878c, "debugfs_create_u32" },
	{ 0x1db71e76, "nvdimm_namespace_disk_name" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa5389eb1, "debugfs_create_x32" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe453f224, "nvdimm_namespace_capacity" },
	{ 0x40c00e11, "nd_integrity_init" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c190915, "nvdimm_check_and_set_ro" },
	{ 0xb5c4e0ab, "blk_cleanup_disk" },
	{ 0x472a2ddb, "badblocks_check" },
	{ 0xef6bed5a, "nd_btt_version" },
	{ 0xbb146a4b, "blk_queue_max_hw_sectors" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FC8753B660E798DA00747E8");
