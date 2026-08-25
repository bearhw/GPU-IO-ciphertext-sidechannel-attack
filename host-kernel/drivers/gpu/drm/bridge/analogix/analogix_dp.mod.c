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

SYMBOL_CRC(analogix_dp_probe, 0x80c6ade8, "_gpl");
SYMBOL_CRC(analogix_dp_bind, 0xdbf4b53b, "_gpl");
SYMBOL_CRC(analogix_dp_unbind, 0xf588c3d3, "_gpl");
SYMBOL_CRC(analogix_dp_remove, 0x16a5fab5, "_gpl");
SYMBOL_CRC(analogix_dp_suspend, 0x21606ef8, "_gpl");
SYMBOL_CRC(analogix_dp_resume, 0xbf0799a7, "_gpl");
SYMBOL_CRC(analogix_dp_start_crc, 0x42683bf3, "_gpl");
SYMBOL_CRC(analogix_dp_stop_crc, 0xf5ff903e, "_gpl");
SYMBOL_CRC(anx_dp_aux_transfer, 0x3ee0dd60, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x228dfabf, "drm_dp_start_crc" },
	{ 0x731506a, "drm_panel_get_modes" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x811842bf, "drm_dp_aux_register" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xca8ff46f, "drm_dp_dpcd_read" },
	{ 0xf6902744, "drm_panel_enable" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0x59c4b9de, "drm_helper_hpd_irq_event" },
	{ 0xc63e6508, "drm_atomic_get_old_connector_for_encoder" },
	{ 0x37a0cba, "kfree" },
	{ 0xfcec0987, "enable_irq" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xe272a15f, "gpiod_get_value" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x78fc2624, "drm_atomic_helper_bridge_reset" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0xc1168254, "drm_atomic_get_new_connector_for_encoder" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0xe43186d1, "drm_dev_printk" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0x2c7b324e, "drm_dp_stop_crc" },
	{ 0xb8f117dc, "drm_panel_disable" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x8b0d7462, "drm_dp_aux_unregister" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x8fd79e71, "phy_power_on" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xc8a6e45b, "phy_power_off" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0xebd9bd17, "drm_atomic_helper_bridge_destroy_state" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x6845c2d1, "drm_panel_prepare" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0x9b285573, "drm_match_cea_mode" },
	{ 0x86332e44, "drm_bridge_attach" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0xc8920b4d, "devm_phy_get" },
	{ 0xb3f593c8, "drm_atomic_helper_bridge_duplicate_state" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x1668523a, "drm_get_edid" },
	{ 0x815588a6, "clk_enable" },
	{ 0xb0c01ee9, "drm_dp_dpcd_write" },
	{ 0x75c8b268, "drm_panel_unprepare" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_display_helper,drm,drm_kms_helper");


MODULE_INFO(srcversion, "5D7920E537E6C25518292D3");
