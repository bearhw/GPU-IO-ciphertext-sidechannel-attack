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
	{ 0x720d3ca3, "inet_diag_register" },
	{ 0x4eb853b1, "inet_diag_dump_one_icsk" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x915a0c88, "inet_diag_unregister" },
	{ 0xe4fac9e, "dccp_hashinfo" },
	{ 0x4403ab7e, "inet_diag_dump_icsk" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "inet_diag,dccp");


MODULE_INFO(srcversion, "002A4514B0327E160B0E5E2");
