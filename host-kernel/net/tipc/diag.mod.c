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
	{ 0xbec9e99d, "tipc_nl_sk_walk" },
	{ 0x37a5d32, "sock_diag_save_cookie" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4e9b78bc, "tipc_dump_start" },
	{ 0xbff8a9d9, "tipc_dump_done" },
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x7172f90b, "tipc_sk_fill_sock_diag" },
	{ 0xb2a212e7, "sock_diag_register" },
	{ 0x45de6f4f, "sock_diag_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "tipc");


MODULE_INFO(srcversion, "EC86637D3E2FCE21FA28F78");
