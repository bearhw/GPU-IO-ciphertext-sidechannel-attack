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
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xa973a327, "regmap_raw_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x812dad29, "regmap_raw_write" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2a8a60bf, "dev_get_regmap" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0xbb726018, "device_property_present" },
	{ 0xf235f72e, "device_property_read_u8_array" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Crichtek,rt4831-backlight");
MODULE_ALIAS("of:N*T*Crichtek,rt4831-backlightC*");

MODULE_INFO(srcversion, "38088A79D3CE54291567C0F");
