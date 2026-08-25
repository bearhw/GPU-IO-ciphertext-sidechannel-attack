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

SYMBOL_CRC(ufshcd_pltfrm_shutdown, 0x9bbd63f6, "_gpl");
SYMBOL_CRC(ufshcd_get_pwr_dev_param, 0xff85cd6b, "_gpl");
SYMBOL_CRC(ufshcd_init_pwr_dev_param, 0x54c946de, "_gpl");
SYMBOL_CRC(ufshcd_pltfrm_init, 0xeff148a3, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8d5c95f0, "ufshcd_shutdown" },
	{ 0x92997ed8, "_printk" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x72794b15, "ufshcd_alloc_host" },
	{ 0xaa30c322, "ufshcd_dealloc_host" },
	{ 0x71928c32, "ufshcd_init" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ufshcd-core");


MODULE_INFO(srcversion, "069A43EE42456E0F846B0D2");
