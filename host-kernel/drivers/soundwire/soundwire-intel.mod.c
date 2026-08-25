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

SYMBOL_CRC(sdw_intel_enable_irq, 0x5af438eb, "");
SYMBOL_CRC(sdw_intel_thread, 0xaa52eba1, "");
SYMBOL_CRC(sdw_intel_probe, 0x82f050df, "");
SYMBOL_CRC(sdw_intel_startup, 0xd2616ec8, "");
SYMBOL_CRC(sdw_intel_exit, 0x2a87f684, "");
SYMBOL_CRC(sdw_intel_process_wakeen_event, 0x38be6b1e, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x69605c9a, "sdw_cdns_pdi_init" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0xe9e213, "cdns_reset_page_addr" },
	{ 0x4f36eff0, "debugfs_attr_write" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x4a14661, "auxiliary_device_init" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x5dc05520, "sdw_cdns_init" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xca69c34e, "sdw_cdns_clock_restart" },
	{ 0x7e4ca7c5, "sdw_cdns_debugfs_init" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0xcd7ee133, "sdw_bus_master_add" },
	{ 0x32de33b7, "sdw_cdns_enable_interrupt" },
	{ 0x96848186, "scnprintf" },
	{ 0x37a0cba, "kfree" },
	{ 0x8f805933, "sdw_cdns_is_clock_stop" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2164dbf6, "sdw_cdns_config_stream" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x51dc5e30, "auxiliary_driver_unregister" },
	{ 0xbb93ceb, "cdns_bus_conf" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xd5901ce8, "cdns_set_sdw_stream" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0x2587f789, "_dev_info" },
	{ 0xeb6eb87, "add_taint" },
	{ 0x66072b1a, "sdw_clear_slave_status" },
	{ 0x546b5d3f, "debugfs_attr_read" },
	{ 0xc7ec954c, "sdw_stream_remove_master" },
	{ 0xc1ef135d, "snd_soc_unregister_component" },
	{ 0x3e06c617, "sdw_cdns_exit_reset" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0xff9e4c96, "__auxiliary_device_add" },
	{ 0xfa242cc0, "sdw_cdns_alloc_pdi" },
	{ 0x5de540fd, "sdw_cdns_clock_stop" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x74c96c65, "cdns_xfer_msg_defer" },
	{ 0x2d7cd23e, "cdns_xfer_msg" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x3312881b, "device_del" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0xf2b11959, "seq_read" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x69204e78, "snd_soc_register_component" },
	{ 0x6f8a5d30, "sdw_stream_add_master" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4087b19f, "acpi_fetch_acpi_dev" },
	{ 0x44b821fd, "device_get_named_child_node" },
	{ 0xd876b4b6, "sdw_cdns_probe" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x636a2492, "no_llseek" },
	{ 0x7aa6c261, "sdw_bus_master_delete" },
	{ 0xbb2b861a, "single_release" },
	{ 0xdcb1320b, "__auxiliary_driver_register" },
	{ 0xab3ab196, "sdw_cdns_check_self_clearing_bits" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x34712074, "sdw_cdns_irq" },
	{ 0xb82ba28c, "single_open" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x3de0561a, "sdw_master_read_prop" },
	{ 0x233095e5, "sdw_compute_params" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x50877b9, "dmi_first_match" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xe56a9336, "snd_pcm_format_width" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "soundwire-cadence,soundwire-bus,snd-soc-core,soundwire-generic-allocation,snd-pcm");

MODULE_ALIAS("auxiliary:soundwire_intel.link");

MODULE_INFO(srcversion, "154E6550DEA1499E339D063");
