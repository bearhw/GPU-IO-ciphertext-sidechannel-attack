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
	{ 0xe272a15f, "gpiod_get_value" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x8b0d7462, "drm_dp_aux_unregister" },
	{ 0x811842bf, "drm_dp_aux_register" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0xb2568e5, "drm_connector_register" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x3ee0dd60, "anx_dp_aux_transfer" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xca8ff46f, "drm_dp_dpcd_read" },
	{ 0x1668523a, "drm_get_edid" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0xf9a97e7c, "drm_bridge_remove" },
	{ 0x97ff9a18, "i2c_unregister_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0xa2e8b1e0, "i2c_new_dummy_device" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x92997ed8, "_printk" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x399e2175, "drm_bridge_add" },
	{ 0xd0b01891, "drm_hdmi_avi_infoframe_from_display_mode" },
	{ 0x809712ff, "hdmi_avi_infoframe_pack" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0x59c4b9de, "drm_helper_hpd_irq_event" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xb0c01ee9, "drm_dp_dpcd_write" },
	{ 0x10d3b4bb, "regmap_multi_reg_write" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_display_helper,drm,analogix_dp,drm_kms_helper");

MODULE_ALIAS("i2c:anx7814");

MODULE_INFO(srcversion, "C64CE945936CC8B3DCC2F5F");
