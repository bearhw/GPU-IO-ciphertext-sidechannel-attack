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
	{ 0x4ece3615, "blocking_notifier_chain_unregister" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x48f33e60, "cros_ec_cmd_xfer_status" },
	{ 0x37a0cba, "kfree" },
	{ 0x901c70e2, "extcon_set_state" },
	{ 0x5b1ad755, "extcon_set_property" },
	{ 0x50c903ee, "extcon_sync" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe846fe9b, "cros_ec_get_host_event" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0xde49eaa4, "extcon_set_property_capability" },
	{ 0x907d14d, "blocking_notifier_chain_register" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D54DD85126E7CCE9583FB8F");
