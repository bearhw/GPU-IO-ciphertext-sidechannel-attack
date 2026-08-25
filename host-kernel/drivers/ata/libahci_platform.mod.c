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

SYMBOL_CRC(ahci_platform_ops, 0x8f556191, "_gpl");
SYMBOL_CRC(ahci_platform_enable_phys, 0x8cfaa6b0, "_gpl");
SYMBOL_CRC(ahci_platform_disable_phys, 0xbd40da94, "_gpl");
SYMBOL_CRC(ahci_platform_enable_clks, 0x4bfb5a82, "_gpl");
SYMBOL_CRC(ahci_platform_disable_clks, 0x7a4126a6, "_gpl");
SYMBOL_CRC(ahci_platform_enable_regulators, 0x3058e727, "_gpl");
SYMBOL_CRC(ahci_platform_disable_regulators, 0xc7218c90, "_gpl");
SYMBOL_CRC(ahci_platform_enable_resources, 0x21bc7471, "_gpl");
SYMBOL_CRC(ahci_platform_disable_resources, 0x3a809ee5, "_gpl");
SYMBOL_CRC(ahci_platform_get_resources, 0x8f723b28, "_gpl");
SYMBOL_CRC(ahci_platform_init_host, 0x55a6d850, "_gpl");
SYMBOL_CRC(ahci_platform_shutdown, 0xf3b22c13, "_gpl");
SYMBOL_CRC(ahci_platform_suspend_host, 0xbb5467be, "_gpl");
SYMBOL_CRC(ahci_platform_resume_host, 0x5665d220, "_gpl");
SYMBOL_CRC(ahci_platform_suspend, 0x2f038755, "_gpl");
SYMBOL_CRC(ahci_platform_resume, 0x6bd96b14, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x78ebe617, "phy_set_mode_ext" },
	{ 0x8fd79e71, "phy_power_on" },
	{ 0x7528b12f, "phy_init" },
	{ 0xc8a6e45b, "phy_power_off" },
	{ 0xe11e23a2, "phy_exit" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x9e2bd11c, "ata_host_resume" },
	{ 0x18825c8b, "ahci_reset_controller" },
	{ 0xc9f1ef1, "ahci_init_controller" },
	{ 0x2e1ca751, "clk_put" },
	{ 0x683601d7, "regulator_put" },
	{ 0x37a0cba, "kfree" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0xb9ed2d3a, "ahci_save_initial_config" },
	{ 0x1c496d9e, "ahci_set_em_messages" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x6d435d09, "ata_port_desc" },
	{ 0xc03ebe7f, "ata_dummy_port_ops" },
	{ 0xea50dad3, "ahci_ignore_sss" },
	{ 0x9ab89f8, "ahci_print_info" },
	{ 0xb6e9da2d, "ahci_host_activate" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xf2ce5b92, "ahci_reset_em" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xfac224d5, "devres_open_group" },
	{ 0x28de1031, "__devres_alloc_node" },
	{ 0xea900f57, "devres_add" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0x82c40558, "clk_get" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xd9372bb1, "devres_release_group" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xf683d35, "devm_of_phy_get" },
	{ 0x2cf4203d, "regulator_get" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x3ea831c3, "devres_remove_group" },
	{ 0x4746dab7, "devm_reset_control_array_get" },
	{ 0x6c4b6684, "reset_control_assert" },
	{ 0x19996497, "ata_host_suspend" },
	{ 0xb2210d64, "reset_control_deassert" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x9bf952f4, "ahci_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libahci");


MODULE_INFO(srcversion, "E4E182F586C52B3250A9222");
