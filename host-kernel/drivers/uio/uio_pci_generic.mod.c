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
	{ 0x312ef23d, "pci_check_and_mask_intx" },
	{ 0xaaa78c1b, "pci_clear_master" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa0d4f927, "__devm_uio_register_device" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "uio");


MODULE_INFO(srcversion, "57391C301CEDB961E1B049A");
