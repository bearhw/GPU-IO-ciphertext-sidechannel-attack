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
	{ 0x8b0acf2d, "dln2_unregister_event_cb" },
	{ 0xb481db6, "generic_handle_domain_irq" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x4f8b36c3, "dln2_transfer" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa7bacb0b, "gpiochip_enable_irq" },
	{ 0x8ed93f5d, "gpiochip_disable_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xbe1ed923, "handle_simple_irq" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x45b368d0, "dln2_register_event_cb" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x5986a03b, "gpiochip_irq_reqres" },
	{ 0xcd995a5b, "gpiochip_irq_relres" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dln2");


MODULE_INFO(srcversion, "F221CCB4F605BD8C29CABFB");
