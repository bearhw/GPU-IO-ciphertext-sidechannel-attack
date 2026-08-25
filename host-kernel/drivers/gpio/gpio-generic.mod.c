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

SYMBOL_CRC(bgpio_init, 0x3ae3d618, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xa71d2e2c, "ioread16be" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0xd7d18c4, "platform_get_resource_byname" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe419bc99, "iowrite32be" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x9bb4e317, "ioread32be" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x26f8f0b8, "iowrite16be" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("platform:basic-mmio-gpio");
MODULE_ALIAS("platform:basic-mmio-gpio-be");

MODULE_INFO(srcversion, "9AC63DB3CF2B46F139C4B8B");
