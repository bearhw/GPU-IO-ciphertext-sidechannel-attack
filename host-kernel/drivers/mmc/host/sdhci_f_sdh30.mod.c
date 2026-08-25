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
	{ 0x688a7f13, "sdhci_remove_host" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x9b1b5206, "sdhci_free_host" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2587f789, "_dev_info" },
	{ 0xba06f8f2, "sdhci_reset" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x145a1091, "sdhci_alloc_host" },
	{ 0xbb726018, "device_property_present" },
	{ 0x7a91a460, "mmc_of_parse" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0xf9a482f9, "msleep" },
	{ 0x7775af29, "sdhci_add_host" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x44482d79, "sdhci_pltfm_pmops" },
	{ 0xa75e4ca7, "sdhci_set_clock" },
	{ 0x38989072, "sdhci_set_bus_width" },
	{ 0xc2e55ce, "sdhci_set_uhs_signaling" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sdhci,sdhci-pltfm");

MODULE_ALIAS("acpi*:SCX0002:*");

MODULE_INFO(srcversion, "6029F4CFB02F309EBC52B43");
