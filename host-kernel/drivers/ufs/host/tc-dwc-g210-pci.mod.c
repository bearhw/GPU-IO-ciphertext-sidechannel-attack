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
	{ 0x8d5c95f0, "ufshcd_shutdown" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0x3b8dd3c3, "ufshcd_remove" },
	{ 0x34b56137, "tc_dwc_g210_config_40_bit" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x72794b15, "ufshcd_alloc_host" },
	{ 0x71928c32, "ufshcd_init" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0x71429048, "tc_dwc_g210_config_20_bit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x3c9c5f65, "ufshcd_suspend_prepare" },
	{ 0xeb3130e2, "ufshcd_resume_complete" },
	{ 0x6793c7d5, "ufshcd_system_suspend" },
	{ 0x273346d7, "ufshcd_system_resume" },
	{ 0xfc214ed2, "ufshcd_runtime_suspend" },
	{ 0xf178f117, "ufshcd_runtime_resume" },
	{ 0xe7733de3, "ufshcd_dwc_link_startup_notify" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ufshcd-core,tc-dwc-g210,ufshcd-dwc");

MODULE_ALIAS("pci:v000016C3d0000B101sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000016C3d0000B102sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "A94D904F5203540CC3CC38B");
