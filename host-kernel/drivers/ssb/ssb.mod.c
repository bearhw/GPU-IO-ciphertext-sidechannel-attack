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

SYMBOL_CRC(ssb_bus_resume, 0xe22791f8, "");
SYMBOL_CRC(ssb_bus_suspend, 0xa97d0839, "");
SYMBOL_CRC(ssb_bus_unregister, 0x2fcf9049, "");
SYMBOL_CRC(ssb_bus_sdiobus_register, 0xe92e95ad, "");
SYMBOL_CRC(__ssb_driver_register, 0x76ae55c5, "");
SYMBOL_CRC(ssb_driver_unregister, 0x304d5cc0, "");
SYMBOL_CRC(ssb_set_devtypedata, 0x6c7117cd, "");
SYMBOL_CRC(ssb_clockspeed, 0xf0aa3754, "");
SYMBOL_CRC(ssb_device_is_enabled, 0x3498f0d7, "");
SYMBOL_CRC(ssb_device_enable, 0x5083e1b8, "");
SYMBOL_CRC(ssb_device_disable, 0x818e4ee9, "");
SYMBOL_CRC(ssb_dma_translation, 0x29dcb88c, "");
SYMBOL_CRC(ssb_bus_may_powerdown, 0x8e04127a, "");
SYMBOL_CRC(ssb_bus_powerup, 0xb2cab5bc, "");
SYMBOL_CRC(ssb_commit_settings, 0xe525ca07, "");
SYMBOL_CRC(ssb_admatch_base, 0xcb17f1cb, "");
SYMBOL_CRC(ssb_admatch_size, 0xdfc7c6ef, "");
SYMBOL_CRC(ssb_pcihost_register, 0xae173f90, "");
SYMBOL_CRC(ssb_chipco_gpio_control, 0x6cb23a59, "");
SYMBOL_CRC(ssb_pmu_set_ldo_voltage, 0x7359cbd8, "");
SYMBOL_CRC(ssb_pmu_set_ldo_paref, 0x403005f8, "");
SYMBOL_CRC(ssb_pmu_spuravoid_pllupdate, 0xc7753d3c, "_gpl");
SYMBOL_CRC(ssb_pcicore_dev_irqvecs_enable, 0xca40f9ef, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0x71009614, "sdio_release_host" },
	{ 0xbcc44c9, "device_set_wakeup_enable" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x2744ebe2, "sdio_claim_host" },
	{ 0xae121354, "pci_iomap" },
	{ 0x9f249e67, "sdio_readw" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xacec5cc3, "pci_back_from_sleep" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x96848186, "scnprintf" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xd461f464, "pci_prepare_to_sleep" },
	{ 0xedc03953, "iounmap" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x37a0cba, "kfree" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x5715b79f, "sdio_writew" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x92997ed8, "_printk" },
	{ 0x848d372e, "iowrite8" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xfbab1bb1, "ioread8_rep" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0x2121e851, "device_create_file" },
	{ 0x14b4a9da, "sdio_readsb" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xaa00a553, "sdio_readl" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xde80cd09, "ioremap" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0x11089ac7, "_ctype" },
	{ 0x422066d2, "device_register" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0xb19b445, "ioread8" },
	{ 0xfb578fc5, "memset" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xe6118aae, "sdio_writel" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xbfc177bc, "iowrite32_rep" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0x45ac8202, "_dev_emerg" },
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x8cc79cab, "iowrite16_rep" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x5fc67252, "ioread16_rep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6cc09945, "ioread32_rep" },
	{ 0x56470118, "__warn_printk" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x5658803a, "sdio_writesb" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa4b94fea, "iowrite8_rep" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0xc487b792, "bus_register" },
	{ 0x56435244, "sdio_readb" },
	{ 0x799a6ff5, "sdio_writeb" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000014E4d00004301sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004306sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004307sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004311sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004312sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004315sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014A4d00004318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004319sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004320sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004321sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004322sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d0000A8D6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004324sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004325sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004328sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004329sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d0000432Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d0000432Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004350sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004351sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "AEA5BFDA69648F09E49B09E");
