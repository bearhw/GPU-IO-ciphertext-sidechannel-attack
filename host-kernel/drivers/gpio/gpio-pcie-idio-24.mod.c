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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xb19b445, "ioread8" },
	{ 0x848d372e, "iowrite8" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb14fc46a, "find_next_clump8" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x45b2608e, "handle_edge_irq" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xb481db6, "generic_handle_domain_irq" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v0000494Fd00000FD0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000494Fd00000BD0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000494Fd000007D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000494Fd00000FC0sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "D6FACCCAA49C0FDB14953EC");
