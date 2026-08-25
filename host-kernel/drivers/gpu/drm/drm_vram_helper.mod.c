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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(drm_gem_vram_create, 0x78979797, "");
SYMBOL_CRC(drm_gem_vram_put, 0xe7264b63, "");
SYMBOL_CRC(drm_gem_vram_offset, 0xc60b2e27, "");
SYMBOL_CRC(drm_gem_vram_pin, 0x08d16d64, "");
SYMBOL_CRC(drm_gem_vram_unpin, 0x0402a0cb, "");
SYMBOL_CRC(drm_gem_vram_vmap, 0x5871e7c0, "");
SYMBOL_CRC(drm_gem_vram_vunmap, 0x3066fe28, "");
SYMBOL_CRC(drm_gem_vram_fill_create_dumb, 0x129aa104, "");
SYMBOL_CRC(drm_gem_vram_driver_dumb_create, 0x3bb7b4ea, "");
SYMBOL_CRC(drm_gem_vram_plane_helper_prepare_fb, 0x1d5bf59c, "");
SYMBOL_CRC(drm_gem_vram_plane_helper_cleanup_fb, 0x15e0becb, "");
SYMBOL_CRC(drm_gem_vram_simple_display_pipe_prepare_fb, 0x4e874dc3, "");
SYMBOL_CRC(drm_gem_vram_simple_display_pipe_cleanup_fb, 0xeaf93c19, "");
SYMBOL_CRC(drm_vram_mm_debugfs_init, 0x85ce2b6e, "");
SYMBOL_CRC(drmm_vram_helper_init, 0x3a32bb89, "");
SYMBOL_CRC(drm_vram_helper_mode_valid, 0x54805c00, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xb2c7417f, "ttm_range_man_init_nocheck" },
	{ 0xcef6fc7a, "ww_mutex_lock_interruptible" },
	{ 0xc5048d22, "ttm_resource_manager_debug" },
	{ 0x2e80b5ac, "ww_mutex_unlock" },
	{ 0x37a0cba, "kfree" },
	{ 0x2522a243, "ttm_range_man_fini_nocheck" },
	{ 0xef3c4945, "drm_gem_object_init" },
	{ 0xfeb953b1, "__drm_printfn_seq_file" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x20ee561, "ttm_bo_pin" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0xab86734c, "drm_gem_ttm_mmap" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7e754496, "__drmm_add_action_or_reset" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x1c83ef36, "ttm_bo_vunmap" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0xb15186c, "drm_debugfs_create_files" },
	{ 0xa15e1675, "drm_gem_object_release" },
	{ 0x593b6030, "ww_mutex_lock" },
	{ 0x7f4fc901, "ttm_tt_init" },
	{ 0x435f223e, "drm_gem_handle_create" },
	{ 0x270b039f, "ttm_bo_unpin" },
	{ 0x513072fe, "__drm_puts_seq_file" },
	{ 0x6d606913, "pv_ops" },
	{ 0x56470118, "__warn_printk" },
	{ 0x98f6a292, "ttm_device_init" },
	{ 0xcc94d006, "ttm_bo_init" },
	{ 0xcad20cf7, "ttm_bo_validate" },
	{ 0x30f7d8d0, "ttm_bo_move_to_lru_tail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xe2ae3814, "ttm_bo_vmap" },
	{ 0x504aff0f, "ttm_bo_put" },
	{ 0xcbcd095f, "ttm_bo_move_memcpy" },
	{ 0x3b91c516, "ttm_tt_fini" },
	{ 0x3ef2485d, "ttm_device_fini" },
	{ 0xe1c6437, "drm_gem_plane_helper_prepare_fb" },
	{ 0x214e9884, "ttm_bo_eviction_valuable" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xd2a5db47, "drm_gem_ttm_print_info" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ttm,drm,drm_ttm_helper,drm_kms_helper");


MODULE_INFO(srcversion, "641BAB1016C40A11E6C4138");
