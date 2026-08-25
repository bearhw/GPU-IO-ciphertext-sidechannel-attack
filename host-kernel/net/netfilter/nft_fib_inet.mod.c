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
	{ 0xcdb8dd36, "nft_fib6_eval_type" },
	{ 0x1b12bf66, "nft_fib6_eval" },
	{ 0x73ed2ee9, "nft_fib4_eval_type" },
	{ 0x6b994b84, "nft_fib4_eval" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x496464b1, "nft_fib_init" },
	{ 0xc96487a0, "nft_fib_dump" },
	{ 0x85b243f9, "nft_fib_validate" },
	{ 0xebc15f3e, "nft_fib_reduce" },
	{ 0xb3c36947, "nft_fib_policy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nft_fib_ipv6,nft_fib_ipv4,nf_tables,nft_fib");


MODULE_INFO(srcversion, "D4253E7B13A864B5D71401F");
