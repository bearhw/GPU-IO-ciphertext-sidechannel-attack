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
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0xc3637570, "pci_enable_wake" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0x6cc09945, "ioread32_rep" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbfc177bc, "iowrite32_rep" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xae121354, "pci_iomap" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x6d606913, "pv_ops" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001179d00000805sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "2DDCD10061645A294684AD6");
