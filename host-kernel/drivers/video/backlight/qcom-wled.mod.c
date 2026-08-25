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
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x2a8a60bf, "dev_get_regmap" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cqcom,pm8941-wled");
MODULE_ALIAS("of:N*T*Cqcom,pm8941-wledC*");
MODULE_ALIAS("of:N*T*Cqcom,pmi8994-wled");
MODULE_ALIAS("of:N*T*Cqcom,pmi8994-wledC*");
MODULE_ALIAS("of:N*T*Cqcom,pmi8998-wled");
MODULE_ALIAS("of:N*T*Cqcom,pmi8998-wledC*");
MODULE_ALIAS("of:N*T*Cqcom,pm660l-wled");
MODULE_ALIAS("of:N*T*Cqcom,pm660l-wledC*");
MODULE_ALIAS("of:N*T*Cqcom,pm6150l-wled");
MODULE_ALIAS("of:N*T*Cqcom,pm6150l-wledC*");
MODULE_ALIAS("of:N*T*Cqcom,pm8150l-wled");
MODULE_ALIAS("of:N*T*Cqcom,pm8150l-wledC*");

MODULE_INFO(srcversion, "03F5BA95080F4CF4F49A790");
