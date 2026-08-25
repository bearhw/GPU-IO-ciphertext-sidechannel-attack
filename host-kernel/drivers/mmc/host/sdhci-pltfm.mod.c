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

SYMBOL_CRC(sdhci_pltfm_clk_get_max_clock, 0x7e1899ad, "_gpl");
SYMBOL_CRC(sdhci_get_property, 0x61cb6be1, "_gpl");
SYMBOL_CRC(sdhci_pltfm_init, 0x2ab86846, "_gpl");
SYMBOL_CRC(sdhci_pltfm_free, 0xed3ef16f, "_gpl");
SYMBOL_CRC(sdhci_pltfm_register, 0x97e2f19c, "_gpl");
SYMBOL_CRC(sdhci_pltfm_unregister, 0x73654a04, "_gpl");
SYMBOL_CRC(sdhci_pltfm_suspend, 0x9d19c213, "_gpl");
SYMBOL_CRC(sdhci_pltfm_resume, 0x3adb54b2, "_gpl");
SYMBOL_CRC(sdhci_pltfm_pmops, 0x44482d79, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0xbb726018, "device_property_present" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x145a1091, "sdhci_alloc_host" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x9b1b5206, "sdhci_free_host" },
	{ 0x7775af29, "sdhci_add_host" },
	{ 0x688a7f13, "sdhci_remove_host" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0xc08571f3, "sdhci_suspend_host" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0xaebd384b, "sdhci_resume_host" },
	{ 0x92997ed8, "_printk" },
	{ 0xa75e4ca7, "sdhci_set_clock" },
	{ 0x38989072, "sdhci_set_bus_width" },
	{ 0xba06f8f2, "sdhci_reset" },
	{ 0xc2e55ce, "sdhci_set_uhs_signaling" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sdhci");


MODULE_INFO(srcversion, "E93A123B4BA07DC2F6C5FEC");
