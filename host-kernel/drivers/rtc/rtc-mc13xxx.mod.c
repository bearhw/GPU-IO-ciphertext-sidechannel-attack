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
	{ 0x6b1e46c2, "mc13xxx_lock" },
	{ 0x1b6854a1, "mc13xxx_irq_free" },
	{ 0x133d129a, "mc13xxx_unlock" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x2812387b, "mc13xxx_irq_mask" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0x5a50f2db, "mc13xxx_reg_read" },
	{ 0x393b10e4, "mc13xxx_reg_write" },
	{ 0x2cc09a56, "mc13xxx_irq_unmask" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8aa7d82d, "mc13xxx_irq_status" },
	{ 0x356461c8, "rtc_time64_to_tm" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x50390897, "mc13xxx_irq_request" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6f477cbc, "__platform_driver_probe" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mc13xxx-core");

MODULE_ALIAS("platform:mc13783-rtc");
MODULE_ALIAS("platform:mc13892-rtc");
MODULE_ALIAS("platform:mc34708-rtc");

MODULE_INFO(srcversion, "4B3CE8D56BBCEAFEE5E7B80");
