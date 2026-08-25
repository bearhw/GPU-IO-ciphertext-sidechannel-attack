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
	{ 0x918169e8, "nf_nat_setup_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_nat,nf_conntrack,x_tables");


MODULE_INFO(srcversion, "6DEBC2C5EF24C14D94E28B5");
