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
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x774a0a6d, "platform_device_add_data" },
	{ 0x47155238, "platform_device_add" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B54E88088EC8A80C53A34DA");
