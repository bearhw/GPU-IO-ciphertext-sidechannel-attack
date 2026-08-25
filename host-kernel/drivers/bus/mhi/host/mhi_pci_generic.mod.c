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
	{ 0xbbe839b2, "pci_save_state" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xb4c5e24f, "pci_wake_from_d3" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x32980d8d, "mhi_sync_power_up" },
	{ 0x44f8b60d, "mhi_power_down" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x56eb3d25, "mhi_pm_resume" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x66a3a2a3, "pci_assign_resource" },
	{ 0xdaf61130, "pci_disable_pcie_error_reporting" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x1b4704af, "mhi_register_controller" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5f99088d, "mhi_soc_reset" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0xc8d566bf, "mhi_pm_suspend" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x750122e9, "pci_load_saved_state" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xae0ebf2f, "pci_store_saved_state" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0x9819ee8, "pci_enable_pcie_error_reporting" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xce6f93af, "pci_reset_function" },
	{ 0x131db64a, "system_long_wq" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xdf9cd31f, "mhi_unregister_controller" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0xffaac81d, "pci_pme_capable" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x7b3005b6, "mhi_unprepare_after_power_down" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x15937681, "mhi_prepare_for_power_up" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xf9a482f9, "msleep" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mhi");

MODULE_ALIAS("pci:v000017CBd00000304sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000017CBd00000306sv000018D7sd00000200bc*sc*i*");
MODULE_ALIAS("pci:v000017CBd00000306sv00001C5Dsd00002000bc*sc*i*");
MODULE_ALIAS("pci:v000017CBd00000306sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000017CBd00000308sv00001C5Dsd00002010bc*sc*i*");
MODULE_ALIAS("pci:v000017CBd00000308sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001EACd00001001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001EACd00001002sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Bd0000E0ABsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Bd0000E0B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Bd0000E0B1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Bd0000E0BFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Bd0000E0D8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Bd0000E0D9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001269d000000B3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001269d000000BAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001269d000000BBsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "15402956FD9F838E1EC33FC");
