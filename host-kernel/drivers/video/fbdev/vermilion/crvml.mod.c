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
	{ 0xa78af5f3, "ioread32" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xedc03953, "iounmap" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x90c018c6, "vmlfb_register_subsys" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x16e6c20, "vmlfb_unregister_subsys" },
	{ 0xde80cd09, "ioremap" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vmlfb");


MODULE_INFO(srcversion, "EF01578A642E2EF0FAD5B92");
