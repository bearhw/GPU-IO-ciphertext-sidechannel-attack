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
	{ 0x1be1c084, "lp8788_update_bits" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3c8f46a4, "lp8788_write_byte" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0xd7d18c4, "platform_get_resource_byname" },
	{ 0xa203e539, "irq_create_mapping_affinity" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x97ee7781, "lp8788_read_multi_bytes" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2D65E5D7D0E65B99DD8AD0C");
