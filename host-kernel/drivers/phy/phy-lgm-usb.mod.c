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
	{ 0xba8de3bf, "usb_remove_phy" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6c4b6684, "reset_control_assert" },
	{ 0xedd05ad5, "extcon_get_property" },
	{ 0x9a5c00da, "extcon_get_state" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb2210d64, "reset_control_deassert" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x63526f4c, "__devm_reset_control_get" },
	{ 0x96498a26, "usb_add_phy_dev" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cintel,lgm-usb-phy");
MODULE_ALIAS("of:N*T*Cintel,lgm-usb-phyC*");

MODULE_INFO(srcversion, "A54714CD9D172D68D71B15C");
