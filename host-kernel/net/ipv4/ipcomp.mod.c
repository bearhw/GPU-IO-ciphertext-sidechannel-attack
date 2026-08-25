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
	{ 0xa67c380, "ipcomp_init_state" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0x3338d282, "xfrm_state_alloc" },
	{ 0x37b4f03a, "xfrm_init_state" },
	{ 0xdc5965cb, "xfrm_state_insert" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0xfc32274f, "ipv4_redirect" },
	{ 0x58fcb880, "ipv4_update_pmtu" },
	{ 0x24c60e49, "xfrm_register_type" },
	{ 0x92997ed8, "_printk" },
	{ 0xd9e90548, "xfrm4_protocol_register" },
	{ 0x844bd2de, "xfrm_unregister_type" },
	{ 0x6ac54c65, "xfrm4_protocol_deregister" },
	{ 0x5c5fc4c, "xfrm4_rcv" },
	{ 0x6681fb42, "xfrm_input" },
	{ 0x7726f66a, "ipcomp_destroy" },
	{ 0x4e419ac5, "ipcomp_input" },
	{ 0x93d9e272, "ipcomp_output" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "xfrm_ipcomp");


MODULE_INFO(srcversion, "FC13258E5F97D2DFDCF1FF1");
