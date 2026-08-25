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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x7ceaf0d5, "generic_handle_irq" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x640a3548, "__devm_irq_alloc_descs" },
	{ 0xbe1ed923, "handle_simple_irq" },
	{ 0x18532aeb, "devm_irq_alloc_generic_chip" },
	{ 0xa7eef584, "devm_irq_setup_generic_chip" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000010DBd0000802Esv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "1DE5BF4DB18EAAF76B1E073");
