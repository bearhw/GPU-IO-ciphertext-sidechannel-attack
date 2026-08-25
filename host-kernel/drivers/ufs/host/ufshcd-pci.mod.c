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
	{ 0x627b41ff, "ufshcd_dme_get_attr" },
	{ 0xffacfb5c, "ufshcd_dme_set_attr" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x4a0766b1, "dev_pm_qos_hide_latency_tolerance" },
	{ 0x273346d7, "ufshcd_system_resume" },
	{ 0x8d5c95f0, "ufshcd_shutdown" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0x3b8dd3c3, "ufshcd_remove" },
	{ 0xaa30c322, "ufshcd_dealloc_host" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x72794b15, "ufshcd_alloc_host" },
	{ 0x71928c32, "ufshcd_init" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x75ce00e5, "ufshcd_uic_hibern8_exit" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0xae5a04bb, "acpi_evaluate_dsm" },
	{ 0x37a0cba, "kfree" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xd5c36791, "dev_pm_qos_expose_latency_tolerance" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xa5389eb1, "debugfs_create_x32" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x4cbd449d, "ufshcd_config_pwr_mode" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x3c9c5f65, "ufshcd_suspend_prepare" },
	{ 0xeb3130e2, "ufshcd_resume_complete" },
	{ 0x6793c7d5, "ufshcd_system_suspend" },
	{ 0xfc214ed2, "ufshcd_runtime_suspend" },
	{ 0xf178f117, "ufshcd_runtime_resume" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ufshcd-core");

MODULE_ALIAS("pci:v0000144Dd0000C00Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009DFAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004B41sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004B43sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000098FAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000051FFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000054FFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00007E47sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "DA03A72C213F7546D2A1019");
