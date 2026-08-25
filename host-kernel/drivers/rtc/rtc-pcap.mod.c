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
	{ 0x91c6e5b0, "pcap_to_irq" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0xd9ff2172, "ezx_pcap_write" },
	{ 0xf31632e0, "ezx_pcap_read" },
	{ 0x356461c8, "rtc_time64_to_tm" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x6f477cbc, "__platform_driver_probe" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A70829DA0CA0E299A8BC735");
