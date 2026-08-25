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
	{ 0x3fd74579, "nf_conncount_destroy" },
	{ 0x79b2a904, "nf_conncount_init" },
	{ 0x3bdf05c1, "nf_conncount_count" },
	{ 0xc958e6b3, "nf_ct_get_tuplepr" },
	{ 0x5a6cdb52, "nf_ct_zone_dflt" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x97fcf9f5, "xt_register_match" },
	{ 0x8ae43d15, "xt_unregister_match" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conncount,nf_conntrack,x_tables");


MODULE_INFO(srcversion, "6E6CAD986BFB098D5034A9C");
