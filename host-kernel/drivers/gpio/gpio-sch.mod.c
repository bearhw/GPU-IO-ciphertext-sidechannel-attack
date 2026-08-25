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
	{ 0xa4faf62a, "acpi_disable_gpe" },
	{ 0x9d099a39, "acpi_remove_gpe_handler" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xb481db6, "generic_handle_domain_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa7bacb0b, "gpiochip_enable_irq" },
	{ 0x8ed93f5d, "gpiochip_disable_irq" },
	{ 0x45b2608e, "handle_edge_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x1795cf27, "handle_bad_irq" },
	{ 0xb97f7045, "acpi_install_gpe_handler" },
	{ 0x1344d7e6, "acpi_enable_gpe" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0xcd8ce890, "acpi_format_exception" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x5986a03b, "gpiochip_irq_reqres" },
	{ 0xcd995a5b, "gpiochip_irq_relres" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "13576852B8C3210BBF728EC");
