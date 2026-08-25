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

SYMBOL_CRC(cs_dsp_mem_region_name, 0x144d6986, "_gpl");
SYMBOL_CRC(cs_dsp_init_debugfs, 0xc7bdaaa9, "_gpl");
SYMBOL_CRC(cs_dsp_cleanup_debugfs, 0xea10f164, "_gpl");
SYMBOL_CRC(cs_dsp_coeff_write_acked_control, 0xe834276e, "_gpl");
SYMBOL_CRC(cs_dsp_coeff_write_ctrl, 0x4d3107c9, "_gpl");
SYMBOL_CRC(cs_dsp_coeff_read_ctrl, 0x7c412c82, "_gpl");
SYMBOL_CRC(cs_dsp_get_ctl, 0xfb72e417, "_gpl");
SYMBOL_CRC(cs_dsp_find_alg_region, 0x056a8e53, "_gpl");
SYMBOL_CRC(cs_dsp_adsp1_init, 0xb4453cae, "_gpl");
SYMBOL_CRC(cs_dsp_adsp1_power_up, 0x21888c14, "_gpl");
SYMBOL_CRC(cs_dsp_adsp1_power_down, 0x15bddd9c, "_gpl");
SYMBOL_CRC(cs_dsp_set_dspclk, 0xee9b0306, "_gpl");
SYMBOL_CRC(cs_dsp_power_up, 0xe1e2b430, "_gpl");
SYMBOL_CRC(cs_dsp_power_down, 0xd9fa0319, "_gpl");
SYMBOL_CRC(cs_dsp_run, 0x63bd4f9a, "_gpl");
SYMBOL_CRC(cs_dsp_stop, 0xbc852c68, "_gpl");
SYMBOL_CRC(cs_dsp_adsp2_init, 0x54a1735b, "_gpl");
SYMBOL_CRC(cs_dsp_halo_init, 0x88bd8729, "_gpl");
SYMBOL_CRC(cs_dsp_remove, 0x6d56bda1, "_gpl");
SYMBOL_CRC(cs_dsp_read_raw_data_block, 0x3deddff6, "_gpl");
SYMBOL_CRC(cs_dsp_read_data_word, 0x515134de, "_gpl");
SYMBOL_CRC(cs_dsp_write_data_word, 0x11328c51, "_gpl");
SYMBOL_CRC(cs_dsp_remove_padding, 0x4e5562f8, "_gpl");
SYMBOL_CRC(cs_dsp_adsp2_bus_error, 0x6be6cf26, "_gpl");
SYMBOL_CRC(cs_dsp_halo_bus_error, 0x6e451882, "_gpl");
SYMBOL_CRC(cs_dsp_halo_wdt_expire, 0x780456e2, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x4465655e, "debugfs_create_bool" },
	{ 0xa5389eb1, "debugfs_create_x32" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x37a0cba, "kfree" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x812dad29, "regmap_raw_write" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa973a327, "regmap_raw_read" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0x5a921311, "strncmp" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x2587f789, "_dev_info" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x10d3b4bb, "regmap_multi_reg_write" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x754d539c, "strlen" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x9d4b7c86, "regmap_async_complete" },
	{ 0x999e8297, "vfree" },
	{ 0x56899e29, "regmap_raw_write_async" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6a59169d, "simple_open" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "101A8571AB88188C9047D93");
