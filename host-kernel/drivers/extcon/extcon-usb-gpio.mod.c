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
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0x47884890, "system_power_efficient_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x9e289f24, "pinctrl_pm_select_default_state" },
	{ 0x3a769fb4, "pinctrl_pm_select_sleep_state" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0x686ba5ca, "gpiod_set_debounce" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x941062c9, "device_set_wakeup_capable" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("platform:extcon-usb-gpio");
MODULE_ALIAS("of:N*T*Clinux,extcon-usb-gpio");
MODULE_ALIAS("of:N*T*Clinux,extcon-usb-gpioC*");

MODULE_INFO(srcversion, "0714297A62A397583B8853D");
