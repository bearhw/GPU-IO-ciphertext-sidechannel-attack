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
	{ 0xa62df577, "alcor_read8" },
	{ 0xd5c3c23a, "alcor_write32" },
	{ 0x87b8798d, "sg_next" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x174c14b6, "alcor_write8" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0x6cc09945, "ioread32_rep" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbfc177bc, "iowrite32_rep" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x9f6b4f9, "alcor_read32" },
	{ 0xab37617d, "alcor_read32be" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x25e7c03b, "alcor_write16" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x5f0d6cd6, "alcor_write32be" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "alcor_pci");

MODULE_ALIAS("platform:alcor_sdmmc");

MODULE_INFO(srcversion, "AEE2B7A1BFA1C77962F20F9");
