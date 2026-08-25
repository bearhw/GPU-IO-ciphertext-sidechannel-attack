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

SYMBOL_CRC(sdw_cdns_debugfs_init, 0x7e4ca7c5, "_gpl");
SYMBOL_CRC(cdns_xfer_msg, 0x2d7cd23e, "");
SYMBOL_CRC(cdns_xfer_msg_defer, 0x74c96c65, "");
SYMBOL_CRC(cdns_reset_page_addr, 0x00e9e213, "");
SYMBOL_CRC(sdw_cdns_irq, 0x34712074, "");
SYMBOL_CRC(sdw_cdns_check_self_clearing_bits, 0xab3ab196, "");
SYMBOL_CRC(sdw_cdns_exit_reset, 0x3e06c617, "");
SYMBOL_CRC(sdw_cdns_enable_interrupt, 0x32de33b7, "");
SYMBOL_CRC(sdw_cdns_pdi_init, 0x69605c9a, "");
SYMBOL_CRC(sdw_cdns_init, 0x5dc05520, "");
SYMBOL_CRC(cdns_bus_conf, 0x0bb93ceb, "");
SYMBOL_CRC(sdw_cdns_is_clock_stop, 0x8f805933, "");
SYMBOL_CRC(sdw_cdns_clock_stop, 0x5de540fd, "");
SYMBOL_CRC(sdw_cdns_clock_restart, 0xca69c34e, "");
SYMBOL_CRC(sdw_cdns_probe, 0xd876b4b6, "");
SYMBOL_CRC(cdns_set_sdw_stream, 0xd5901ce8, "");
SYMBOL_CRC(sdw_cdns_config_stream, 0x2164dbf6, "");
SYMBOL_CRC(sdw_cdns_alloc_pdi, 0xfa242cc0, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xa1202929, "sdw_bus_prep_clk_stop" },
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0x4f36eff0, "debugfs_attr_write" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x23095ae2, "sdw_bus_clk_stop" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x96848186, "scnprintf" },
	{ 0x37a0cba, "kfree" },
	{ 0x1deee061, "sdw_find_row_index" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x19b16242, "sdw_handle_slave_status" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0xeb6eb87, "add_taint" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x546b5d3f, "debugfs_attr_read" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf2b11959, "seq_read" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x60e31fbb, "sdw_find_col_index" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x636a2492, "no_llseek" },
	{ 0xbb2b861a, "single_release" },
	{ 0xa863499d, "sdw_bread_no_pm_unlocked" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xb82ba28c, "single_open" },
	{ 0xa1fea045, "sdw_bus_exit_clk_stop" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "soundwire-bus");


MODULE_INFO(srcversion, "125B9E1B3CD42F5A7D1C8CC");
