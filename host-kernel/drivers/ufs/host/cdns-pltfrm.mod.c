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
	{ 0xffacfb5c, "ufshcd_dme_set_attr" },
	{ 0x627b41ff, "ufshcd_dme_get_attr" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x3b8dd3c3, "ufshcd_remove" },
	{ 0xeff148a3, "ufshcd_pltfrm_init" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x9bbd63f6, "ufshcd_pltfrm_shutdown" },
	{ 0x3c9c5f65, "ufshcd_suspend_prepare" },
	{ 0xeb3130e2, "ufshcd_resume_complete" },
	{ 0x6793c7d5, "ufshcd_system_suspend" },
	{ 0x273346d7, "ufshcd_system_resume" },
	{ 0xfc214ed2, "ufshcd_runtime_suspend" },
	{ 0xf178f117, "ufshcd_runtime_resume" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ufshcd-core,ufshcd-pltfrm");

MODULE_ALIAS("of:N*T*Ccdns,ufshc");
MODULE_ALIAS("of:N*T*Ccdns,ufshcC*");
MODULE_ALIAS("of:N*T*Ccdns,ufshc-m31-16nm");
MODULE_ALIAS("of:N*T*Ccdns,ufshc-m31-16nmC*");

MODULE_INFO(srcversion, "8385B44522379DDDE1297AF");
