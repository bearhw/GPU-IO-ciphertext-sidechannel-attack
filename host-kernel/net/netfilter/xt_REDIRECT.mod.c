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
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xcaf3db26, "nf_nat_redirect_ipv4" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0x5ed6a51f, "nf_nat_redirect_ipv6" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack,nf_nat,x_tables");


MODULE_INFO(srcversion, "B6B069F4F0E1CE07496143C");
