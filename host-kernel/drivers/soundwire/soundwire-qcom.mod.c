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
	{ 0x741f5b96, "sdw_slave_add" },
	{ 0xa1202929, "sdw_bus_prep_clk_stop" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x38b17471, "sdw_compare_devid" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0xa6257a2f, "complete" },
	{ 0x23095ae2, "sdw_bus_clk_stop" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x1deee061, "sdw_find_row_index" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x9e122d79, "sdw_alloc_stream" },
	{ 0x19b16242, "sdw_handle_slave_status" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x55e99707, "slimbus_bus" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcade3366, "sdw_extract_slave_id" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc7ec954c, "sdw_stream_remove_master" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xbb7cf14f, "irq_get_irq_data" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2a8a60bf, "dev_get_regmap" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x6f8a5d30, "sdw_stream_add_master" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x60e31fbb, "sdw_find_col_index" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0x7aa6c261, "sdw_bus_master_delete" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x27bbf221, "disable_irq_nosync" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xda5bce09, "sdw_release_stream" },
	{ 0xb82ba28c, "single_open" },
	{ 0x815588a6, "clk_enable" },
	{ 0xa1fea045, "sdw_bus_exit_clk_stop" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "soundwire-bus,slimbus");

MODULE_ALIAS("of:N*T*Cqcom,soundwire-v1.3.0");
MODULE_ALIAS("of:N*T*Cqcom,soundwire-v1.3.0C*");
MODULE_ALIAS("of:N*T*Cqcom,soundwire-v1.5.1");
MODULE_ALIAS("of:N*T*Cqcom,soundwire-v1.5.1C*");
MODULE_ALIAS("of:N*T*Cqcom,soundwire-v1.6.0");
MODULE_ALIAS("of:N*T*Cqcom,soundwire-v1.6.0C*");

MODULE_INFO(srcversion, "283EA809BFB429BD23F3686");
