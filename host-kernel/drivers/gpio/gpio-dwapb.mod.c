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
	{ 0x6c4b6684, "reset_control_assert" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x479f7d4b, "clk_bulk_disable" },
	{ 0x63c08029, "clk_bulk_unprepare" },
	{ 0xce9da695, "device_get_child_node_count" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xf3f5b3f5, "device_get_next_child_node" },
	{ 0x144b5c4, "is_software_node" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0x548ad742, "platform_get_irq_optional" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x83369b01, "fwnode_irq_get" },
	{ 0x63526f4c, "__devm_reset_control_get" },
	{ 0xb2210d64, "reset_control_deassert" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0xe63e70c4, "devm_clk_bulk_get_optional" },
	{ 0xead5c8e5, "clk_bulk_prepare" },
	{ 0xc7a7e770, "clk_bulk_enable" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0x3ae3d618, "bgpio_init" },
	{ 0x1795cf27, "handle_bad_irq" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0x2587f789, "_dev_info" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8ed93f5d, "gpiochip_disable_irq" },
	{ 0xa7bacb0b, "gpiochip_enable_irq" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x764d9ae7, "__irq_resolve_mapping" },
	{ 0xbb7cf14f, "irq_get_irq_data" },
	{ 0x7ceaf0d5, "generic_handle_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd84b9a76, "handle_level_irq" },
	{ 0x45b2608e, "handle_edge_irq" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x5986a03b, "gpiochip_irq_reqres" },
	{ 0xcd995a5b, "gpiochip_irq_relres" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "gpio-generic");

MODULE_ALIAS("acpi*:HISI0181:*");
MODULE_ALIAS("acpi*:APMC0D07:*");
MODULE_ALIAS("acpi*:APMC0D81:*");
MODULE_ALIAS("of:N*T*Csnps,dw-apb-gpio");
MODULE_ALIAS("of:N*T*Csnps,dw-apb-gpioC*");
MODULE_ALIAS("of:N*T*Capm,xgene-gpio-v2");
MODULE_ALIAS("of:N*T*Capm,xgene-gpio-v2C*");

MODULE_INFO(srcversion, "A920B1424EF54158AC2A754");
