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

SYMBOL_CRC(acpi_video_get_levels, 0xa2bab8ab, "");
SYMBOL_CRC(acpi_video_get_edid, 0xa37802b7, "");
SYMBOL_CRC(acpi_video_register, 0x8826c13b, "");
SYMBOL_CRC(acpi_video_unregister, 0x7a45377b, "");
SYMBOL_CRC(acpi_video_handles_brightness_key_presses, 0x7cc484a5, "");
SYMBOL_CRC(acpi_video_get_backlight_type, 0x6de7f7ff, "");
SYMBOL_CRC(acpi_video_set_dmi_backlight_type, 0xe92ca535, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x81e6b37f, "dmi_get_system_info" },
	{ 0x3da716bf, "input_allocate_device" },
	{ 0x76a14435, "acpi_device_hid" },
	{ 0x509b64ea, "acpi_has_method" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0xec2b8a42, "acpi_walk_namespace" },
	{ 0xc3bf5097, "backlight_force_update" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x7d12d76d, "acpi_get_parent" },
	{ 0x7681946c, "unregister_pm_notifier" },
	{ 0x5aa70984, "acpi_reduced_hardware" },
	{ 0x84ddca63, "input_unregister_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x7d8d8c0a, "thermal_cooling_device_register" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xfe9ebbbb, "acpi_osi_is_win8" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xdc512134, "backlight_register_notifier" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xe42878c7, "input_free_device" },
	{ 0x92997ed8, "_printk" },
	{ 0xaddf64b0, "input_register_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x2587f789, "_dev_info" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0xcd8ce890, "acpi_format_exception" },
	{ 0x32e6f1a0, "acpi_video_backlight_string" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb7c0f443, "sort" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0x1a45cb6c, "acpi_disabled" },
	{ 0xb4043948, "acpi_execute_simple_method" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x9cc4f70a, "register_pm_notifier" },
	{ 0x1888dd3b, "acpi_get_pci_dev" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd8df08ac, "acpi_handle_printk" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x9e25ecce, "backlight_device_get_by_type" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x2f384db3, "acpi_is_video_device" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xc36a3bd4, "__acpi_handle_debug" },
	{ 0xc2261e62, "input_event" },
	{ 0xb1caf579, "acpi_match_device_ids" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x69e38717, "acpi_notifier_call_chain" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x4087b19f, "acpi_fetch_acpi_dev" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xf0cd6f57, "acpi_bus_unregister_driver" },
	{ 0xd92deb6b, "acpi_evaluate_object" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x9e5f9556, "backlight_device_register" },
	{ 0x413f8338, "thermal_cooling_device_unregister" },
	{ 0x170ddf79, "acpi_install_notify_handler" },
	{ 0x9939eba0, "backlight_unregister_notifier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x1c58427f, "acpi_remove_notify_handler" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x327bd7da, "acpi_bus_register_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:LNXVIDEO:*");

MODULE_INFO(srcversion, "B171D7D5F51C89B432B9467");
