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
	{ 0x639c8661, "pcf50633_free_irq" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0xe5305819, "pcf50633_irq_unmask" },
	{ 0xc39ab7dc, "pcf50633_irq_mask" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x76a0a886, "pcf50633_irq_mask_get" },
	{ 0x44ad44ac, "pcf50633_write_block" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x8a76884d, "pcf50633_read_block" },
	{ 0x5838f6c9, "rtc_valid_tm" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0xb7bafdcd, "pcf50633_register_irq" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcf50633");


MODULE_INFO(srcversion, "029CD9F0F223E493087E00B");
