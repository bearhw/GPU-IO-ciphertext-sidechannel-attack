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
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x92997ed8, "_printk" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x37a0cba, "kfree" },
	{ 0x72b243d4, "free_dma" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x85bd1608, "__request_region" },
	{ 0xa07d1b3c, "tasklet_setup" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x7054a3e4, "request_dma" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa834c8c2, "pnp_get_resource" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x3e3bad0a, "__tasklet_hi_schedule" },
	{ 0x6d606913, "pv_ops" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x175e33fb, "dma_spin_lock" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x905695ab, "sg_copy_from_buffer" },
	{ 0x86490580, "current_task" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x2b8ab42, "sg_copy_to_buffer" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x1d526753, "pnp_register_driver" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x47155238, "platform_device_add" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x8a75fabb, "pnp_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pnp:dWEC0517*");
MODULE_ALIAS("acpi*:WEC0517:*");
MODULE_ALIAS("pnp:dWEC0518*");
MODULE_ALIAS("acpi*:WEC0518:*");

MODULE_INFO(srcversion, "7B99808FFEA74C9B4DEE81D");
