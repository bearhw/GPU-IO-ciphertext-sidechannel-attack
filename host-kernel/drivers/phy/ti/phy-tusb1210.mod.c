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
	{ 0x6b81c38b, "power_supply_unreg_notifier" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xde586c1e, "power_supply_unregister" },
	{ 0xcf56f12a, "power_supply_put" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0x1141225e, "power_supply_get_by_name" },
	{ 0x9c149d, "power_supply_get_property" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8d1ce0, "power_supply_changed" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x131db64a, "system_long_wq" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9ab91f64, "power_supply_get_drvdata" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x585ba22b, "phy_remove_lookup" },
	{ 0x975c76a4, "phy_destroy" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xf9a482f9, "msleep" },
	{ 0xe2044c84, "ulpi_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x3aa46486, "ulpi_read" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0xf235f72e, "device_property_read_u8_array" },
	{ 0xbb726018, "device_property_present" },
	{ 0xf50180e4, "power_supply_register" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x136209db, "power_supply_reg_notifier" },
	{ 0x5a3bfdcf, "phy_create" },
	{ 0x2fd7e313, "phy_create_lookup" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0xcaf9a63, "__ulpi_register_driver" },
	{ 0xc644233d, "ulpi_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ulpi");

MODULE_ALIAS("ulpi:v0451p1507");
MODULE_ALIAS("ulpi:v0451p1508");

MODULE_INFO(srcversion, "EE86FABC28D888CC8C62131");
