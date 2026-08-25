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
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0xed74f322, "spi_sync_locked" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x37a0cba, "kfree" },
	{ 0x5e6450d6, "mmc_spi_put_pdata" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x8b51deca, "spi_sync" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xba55d23e, "crc7_be" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x1689b9c2, "spi_setup" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x800473f, "__cond_resched" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xa9de18b9, "mmc_spi_get_pdata" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0x46083359, "mmc_gpiod_request_cd" },
	{ 0x5e3fb177, "mmc_gpiod_request_ro" },
	{ 0x6eb1c234, "mmc_gpiod_request_cd_irq" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87764532, "spi_bus_lock" },
	{ 0xf1969a8e, "__usecs_to_jiffies" },
	{ 0x87b8798d, "sg_next" },
	{ 0x9a34a2b, "crc_itu_t" },
	{ 0xf123ce5, "spi_bus_unlock" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf9a482f9, "msleep" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x13a52dda, "mmc_gpio_get_ro" },
	{ 0xa3bfb7e5, "mmc_gpio_get_cd" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "of_mmc_spi,crc7,crc-itu-t");

MODULE_ALIAS("of:N*T*Cmmc-spi-slot");
MODULE_ALIAS("of:N*T*Cmmc-spi-slotC*");
MODULE_ALIAS("spi:mmc-spi-slot");

MODULE_INFO(srcversion, "072F0FE59E9C16384AE12AF");
