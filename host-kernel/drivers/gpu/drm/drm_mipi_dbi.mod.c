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

SYMBOL_CRC(mipi_dbi_command_read, 0x10e15c16, "");
SYMBOL_CRC(mipi_dbi_command_buf, 0x0e022324, "");
SYMBOL_CRC(mipi_dbi_command_stackbuf, 0x0057563a, "");
SYMBOL_CRC(mipi_dbi_buf_copy, 0xaf302fd7, "");
SYMBOL_CRC(mipi_dbi_pipe_update, 0x0cab9781, "");
SYMBOL_CRC(mipi_dbi_enable_flush, 0xeddb6753, "");
SYMBOL_CRC(mipi_dbi_pipe_disable, 0x9da1f710, "");
SYMBOL_CRC(mipi_dbi_dev_init_with_formats, 0xdef12e57, "");
SYMBOL_CRC(mipi_dbi_dev_init, 0x3d2ecd70, "");
SYMBOL_CRC(mipi_dbi_hw_reset, 0x1211e36c, "");
SYMBOL_CRC(mipi_dbi_display_is_on, 0x752cbae8, "");
SYMBOL_CRC(mipi_dbi_poweron_reset, 0x1ba219c0, "");
SYMBOL_CRC(mipi_dbi_poweron_conditional_reset, 0x60b61c64, "");
SYMBOL_CRC(mipi_dbi_spi_cmd_max_speed, 0x2889ce7c, "");
SYMBOL_CRC(mipi_dbi_spi_init, 0xbe787cc2, "");
SYMBOL_CRC(mipi_dbi_spi_transfer, 0xa754bc53, "");
SYMBOL_CRC(mipi_dbi_debugfs_init, 0xe2acda3d, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x37a0cba, "kfree" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9ce050be, "drm_mode_copy" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0xb70870ce, "drm_plane_enable_fb_damage_clips" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0xb5e74aec, "drm_mode_duplicate" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0x4a35d30d, "drm_mode_set_name" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xb82ba28c, "single_open" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0x1d07e365, "memdup_user_nul" },
	{ 0x11089ac7, "_ctype" },
	{ 0x85df9b6c, "strsep" },
	{ 0x6a6e05bf, "kstrtou8" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe3ca4fc5, "drm_gem_fb_get_obj" },
	{ 0x5043ea76, "drm_gem_fb_begin_cpu_access" },
	{ 0x7723a66c, "drm_gem_fb_vmap" },
	{ 0x314638f6, "drm_gem_fb_vunmap" },
	{ 0x959eaca3, "drm_gem_fb_end_cpu_access" },
	{ 0xae1977d3, "drm_fb_swab" },
	{ 0xf7048cb7, "drm_fb_xrgb8888_to_rgb565" },
	{ 0x28c06c53, "drm_fb_memcpy" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x391de184, "seq_puts" },
	{ 0x8b51deca, "spi_sync" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0x4f18a150, "__drm_debug" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0xfb578fc5, "memset" },
	{ 0xc8e9adac, "drm_atomic_helper_damage_merged" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0xe43186d1, "drm_dev_printk" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xf2b11959, "seq_read" },
	{ 0xbb2b861a, "single_release" },
	{ 0x22a8c36f, "drm_gem_fb_create_with_dirty" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_kms_helper");


MODULE_INFO(srcversion, "0EEDCBDBBED2F348F162320");
