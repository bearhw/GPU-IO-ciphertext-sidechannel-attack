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
	{ 0x1a7cf4e7, "ip_vs_scheduler_err" },
	{ 0x5d5ae2d0, "register_ip_vs_scheduler" },
	{ 0x47b77462, "unregister_ip_vs_scheduler" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_vs");


MODULE_INFO(srcversion, "86EFF1FDE5F6118B4EB4B72");
