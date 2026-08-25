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
	{ 0x56232755, "__blk_alloc_disk" },
	{ 0x3980cab6, "page_endio" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x81088473, "blk_queue_logical_block_size" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xc1c2033b, "nvdimm_has_cache" },
	{ 0x35a7d2e, "devm_memremap" },
	{ 0x88330529, "device_add_disk" },
	{ 0x3293aa63, "devm_namespace_enable" },
	{ 0x9d8bb00e, "set_dax_nocache" },
	{ 0xda86dacb, "to_nd_region" },
	{ 0x3496c7a, "blk_queue_write_cache" },
	{ 0x138e0957, "dax_write_cache_enabled" },
	{ 0xbc4e24bb, "copy_mc_to_kernel" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x68438a13, "alloc_dax" },
	{ 0xeb78b21b, "kernfs_notify" },
	{ 0xbc1c6683, "bio_end_io_acct_remapped" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0xaff7e41, "_copy_from_iter_flushcache" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x815f2897, "empty_zero_page" },
	{ 0xfad9c827, "kill_dax" },
	{ 0x1e4f408c, "nvdimm_setup_pfn" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9a376418, "nvdimm_namespace_attach_btt" },
	{ 0x7ee04d80, "blk_queue_physical_block_size" },
	{ 0xcc1c5aaf, "nvdimm_badblocks_populate" },
	{ 0xeae84dbe, "blk_queue_flag_set" },
	{ 0x37ff01c4, "nvdimm_namespace_detach_btt" },
	{ 0xb4a202a5, "dax_add_host" },
	{ 0xa1179cbd, "bio_start_io_acct" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x18ae7042, "nvdimm_has_flush" },
	{ 0xc8126340, "clear_mce_nospec" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x37697ad3, "pmem_should_map_pages" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x9e9c4f24, "set_dax_nomc" },
	{ 0xe3f3d437, "set_capacity" },
	{ 0x328e3354, "__memcpy_flushcache" },
	{ 0x5f6f1e9e, "dax_get_private" },
	{ 0x590b666e, "kernfs_find_and_get_ns" },
	{ 0xc6c73ec5, "dax_remove_host" },
	{ 0xca515634, "nvdimm_clear_poison" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x46adca73, "__nd_driver_register" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x8f381413, "del_gendisk" },
	{ 0x612bfd89, "errno_to_blk_status" },
	{ 0x7a54ddcf, "pmem_sector_size" },
	{ 0xc78e0e8c, "to_nd_btt" },
	{ 0x86490580, "current_task" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x1db71e76, "nvdimm_namespace_disk_name" },
	{ 0x285a20be, "is_nd_btt" },
	{ 0x8afeae2a, "nvdimm_flush" },
	{ 0x12664928, "nd_pfn_probe" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x5afcb34f, "nd_dax_probe" },
	{ 0x330f6116, "set_dax_synchronous" },
	{ 0x3585851d, "is_nvdimm_sync" },
	{ 0x5c52bf15, "kernfs_put" },
	{ 0xf0850137, "devm_memremap_pages" },
	{ 0x56470118, "__warn_printk" },
	{ 0x3a454907, "devm_namespace_disable" },
	{ 0x4c190915, "nvdimm_check_and_set_ro" },
	{ 0x8135613, "dax_write_cache" },
	{ 0x7242d92, "put_dax" },
	{ 0xb5c4e0ab, "blk_cleanup_disk" },
	{ 0x472a2ddb, "badblocks_check" },
	{ 0x269e0f02, "is_nd_pfn" },
	{ 0x88de63b0, "nvdimm_namespace_common_probe" },
	{ 0x2c635527, "arch_invalidate_pmem" },
	{ 0xbb146a4b, "blk_queue_max_hw_sectors" },
	{ 0x84d9d0a7, "badblocks_clear" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x50d1389d, "devm_init_badblocks" },
	{ 0x77358855, "iomem_resource" },
	{ 0x84502a47, "blk_status_to_errno" },
	{ 0x242ebdf2, "to_nd_pfn" },
	{ 0xb62930d9, "nd_btt_probe" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nd_btt");


MODULE_INFO(srcversion, "00F7ECA640DF71A49484CFB");
