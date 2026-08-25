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
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa7bacb0b, "gpiochip_enable_irq" },
	{ 0x8ed93f5d, "gpiochip_disable_irq" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x764d9ae7, "__irq_resolve_mapping" },
	{ 0x549525ef, "handle_nested_irq" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x55784228, "regmap_irq_get_virq" },
	{ 0xbe1ed923, "handle_simple_irq" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x5986a03b, "gpiochip_irq_reqres" },
	{ 0xcd995a5b, "gpiochip_irq_relres" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2BDD016B0FC4BBF9570950F");
