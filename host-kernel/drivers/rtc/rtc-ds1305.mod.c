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
	{ 0xf3e78736, "devm_free_irq" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xa07321bc, "spi_write_then_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x8b51deca, "spi_sync" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xfbad13e8, "devm_rtc_nvmem_register" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x941062c9, "device_set_wakeup_capable" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "AD8AADCC44541A61434318B");
