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
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3b8dd3c3, "ufshcd_remove" },
	{ 0xeff148a3, "ufshcd_pltfrm_init" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x9bbd63f6, "ufshcd_pltfrm_shutdown" },
	{ 0x6793c7d5, "ufshcd_system_suspend" },
	{ 0x273346d7, "ufshcd_system_resume" },
	{ 0xfc214ed2, "ufshcd_runtime_suspend" },
	{ 0xf178f117, "ufshcd_runtime_resume" },
	{ 0xe7733de3, "ufshcd_dwc_link_startup_notify" },
	{ 0x34b56137, "tc_dwc_g210_config_40_bit" },
	{ 0x71429048, "tc_dwc_g210_config_20_bit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ufshcd-core,ufshcd-pltfrm,ufshcd-dwc,tc-dwc-g210");

MODULE_ALIAS("of:N*T*Csnps,g210-tc-6.00-20bit");
MODULE_ALIAS("of:N*T*Csnps,g210-tc-6.00-20bitC*");
MODULE_ALIAS("of:N*T*Csnps,g210-tc-6.00-40bit");
MODULE_ALIAS("of:N*T*Csnps,g210-tc-6.00-40bitC*");

MODULE_INFO(srcversion, "EFFAAAEF0CFE2EB3E24F3E0");
