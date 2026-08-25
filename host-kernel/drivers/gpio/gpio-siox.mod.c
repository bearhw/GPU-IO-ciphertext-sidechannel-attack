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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd84b9a76, "handle_level_irq" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x764d9ae7, "__irq_resolve_mapping" },
	{ 0x549525ef, "handle_nested_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x39dc8707, "__siox_driver_register" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "siox-core");


MODULE_INFO(srcversion, "651B6E27E75B5B9BE70AA6C");
