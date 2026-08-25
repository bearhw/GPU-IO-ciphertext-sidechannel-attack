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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xd7fea2a8, "device_wakeup_enable" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0xedc03953, "iounmap" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x92997ed8, "_printk" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x2587f789, "_dev_info" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xde80cd09, "ioremap" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xa07d1b3c, "tasklet_setup" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001106d00009530sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "7B43F06057CECB33D1A517C");
