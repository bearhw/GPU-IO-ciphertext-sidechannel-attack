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
	{ 0x2c63315b, "gpiod_get" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xc4c62b2, "gpiod_put" },
	{ 0x399e2175, "drm_bridge_add" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xa01fbb6b, "cec_notifier_set_phys_addr" },
	{ 0xf03e9b49, "component_del" },
	{ 0xd0b01891, "drm_hdmi_avi_infoframe_from_display_mode" },
	{ 0x37a0cba, "kfree" },
	{ 0xfcec0987, "enable_irq" },
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3082b526, "drm_encoder_cleanup" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xf9a97e7c, "drm_bridge_remove" },
	{ 0x574e008e, "drm_connector_attach_encoder" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x2587f789, "_dev_info" },
	{ 0x800473f, "__cond_resched" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x97ff9a18, "i2c_unregister_device" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x118dd7a0, "drm_add_edid_modes" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xbb7cf14f, "irq_get_irq_data" },
	{ 0x551f15ad, "gpiod_direction_input" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x73965ef6, "i2c_new_client_device" },
	{ 0x744a3688, "cec_notifier_conn_register" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x39494420, "drm_connector_update_edid_property" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xaadb001c, "drm_do_get_edid" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xa248afde, "drm_detect_monitor_audio" },
	{ 0x6d606913, "pv_ops" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0xc16f2887, "cec_notifier_set_phys_addr_from_edid" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0xea8ee118, "drm_simple_encoder_init" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6204a1c1, "drm_kms_helper_hotplug_event" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x595d8002, "hdmi_infoframe_pack" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x65702bd6, "drm_default_rgb_quant_range" },
	{ 0x4b7c8fa3, "drm_hdmi_avi_infoframe_quant_range" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0x86332e44, "drm_bridge_attach" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x5f9564a, "component_add" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb302156f, "drm_hdmi_vendor_infoframe_from_display_mode" },
	{ 0x7954df, "gpiod_direction_output" },
	{ 0xf9a482f9, "msleep" },
	{ 0xaee236c6, "cec_notifier_conn_unregister" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,cec,drm_kms_helper");

MODULE_ALIAS("i2c:tda998x");

MODULE_INFO(srcversion, "65E7398A337283D77D33073");
