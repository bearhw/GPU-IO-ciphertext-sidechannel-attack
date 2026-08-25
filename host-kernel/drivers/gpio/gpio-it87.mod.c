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
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x92997ed8, "_printk" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0x37a0cba, "kfree" },
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "168790B927DCAEE11DDFB69");
