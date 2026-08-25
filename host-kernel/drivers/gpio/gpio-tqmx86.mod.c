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
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xb19b445, "ioread8" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x848d372e, "iowrite8" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x548ad742, "platform_get_irq_optional" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x90a7a78d, "devm_ioport_map" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0xbe1ed923, "handle_simple_irq" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb481db6, "generic_handle_domain_irq" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BD630EA096EE448140C7C31");
