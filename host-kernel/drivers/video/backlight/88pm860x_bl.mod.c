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
	{ 0x230ae399, "pm860x_reg_read" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xd7d18c4, "platform_get_resource_byname" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xbcb91eea, "pm860x_reg_write" },
	{ 0x4b21b21d, "pm860x_set_bits" },
	{ 0x6673975b, "pm8606_osc_disable" },
	{ 0xe25e9c90, "pm8606_osc_enable" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C933E7103AE45BA29EECA13");
