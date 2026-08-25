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

SYMBOL_CRC(bcma_find_core_unit, 0xcbd028bb, "_gpl");
SYMBOL_CRC(bcma_core_irq, 0x1c462d88, "");
SYMBOL_CRC(__bcma_driver_register, 0x05ecba2d, "_gpl");
SYMBOL_CRC(bcma_driver_unregister, 0x7ed0a34c, "_gpl");
SYMBOL_CRC(bcma_core_is_enabled, 0xd8d913c2, "_gpl");
SYMBOL_CRC(bcma_core_disable, 0x71a23e63, "_gpl");
SYMBOL_CRC(bcma_core_enable, 0x11391920, "_gpl");
SYMBOL_CRC(bcma_core_set_clockmode, 0x0d41905d, "_gpl");
SYMBOL_CRC(bcma_core_pll_ctl, 0xfb9b9ef5, "_gpl");
SYMBOL_CRC(bcma_core_dma_translation, 0x28470cc7, "");
SYMBOL_CRC(bcma_chipco_get_alp_clock, 0xb57bb37e, "_gpl");
SYMBOL_CRC(bcma_chipco_gpio_out, 0x9d93ad32, "_gpl");
SYMBOL_CRC(bcma_chipco_gpio_outen, 0xd74c56b1, "_gpl");
SYMBOL_CRC(bcma_chipco_gpio_control, 0xaa7f885c, "_gpl");
SYMBOL_CRC(bcma_chipco_pll_read, 0x11dfbc2e, "_gpl");
SYMBOL_CRC(bcma_chipco_pll_write, 0x84178f1b, "_gpl");
SYMBOL_CRC(bcma_chipco_pll_maskset, 0x25753f9e, "_gpl");
SYMBOL_CRC(bcma_chipco_chipctl_maskset, 0x02776c04, "_gpl");
SYMBOL_CRC(bcma_chipco_regctl_maskset, 0xc00e75ba, "_gpl");
SYMBOL_CRC(bcma_pmu_get_bus_clock, 0x870ddf88, "_gpl");
SYMBOL_CRC(bcma_pmu_spuravoid_pllupdate, 0xfcc32d5c, "_gpl");
SYMBOL_CRC(bcma_chipco_b_mii_write, 0x9076c918, "_gpl");
SYMBOL_CRC(bcma_core_pci_power_save, 0x67e697f9, "_gpl");
SYMBOL_CRC(bcma_host_pci_up, 0x0a66f6da, "_gpl");
SYMBOL_CRC(bcma_host_pci_down, 0x24164ed9, "_gpl");
SYMBOL_CRC(bcma_host_pci_irq_ctl, 0xe9845a78, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xae121354, "pci_iomap" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x842c8e9d, "ioread16" },
	{ 0xe4933139, "dev_fwnode" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0xbd3718be, "device_initialize" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x37a0cba, "kfree" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x848d372e, "iowrite8" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0x4a78799d, "platform_device_register" },
	{ 0xfbab1bb1, "ioread8_rep" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x48098f3, "device_add" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xde80cd09, "ioremap" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xb19b445, "ioread8" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xbfc177bc, "iowrite32_rep" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x8cc79cab, "iowrite16_rep" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0x5fc67252, "ioread16_rep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6cc09945, "ioread32_rep" },
	{ 0x56470118, "__warn_printk" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x2fd44381, "pcie_set_readrq" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa4b94fea, "iowrite8_rep" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000014E4d00000576sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004313sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d0000A8D8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004331sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004353sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004357sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004358sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004359sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004360sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004365sv00001028sd00000016bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004365sv00001028sd00000018bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004365sv0000105Bsd0000E092bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004365sv0000103Csd0000804Abc*sc*i*");
MODULE_ALIAS("pci:v000014E4d000043A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d000043A9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d000043AAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d000043B1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004727sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d0000A8DBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d0000A8DCsv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "AA676485441C402DD09B7B2");
