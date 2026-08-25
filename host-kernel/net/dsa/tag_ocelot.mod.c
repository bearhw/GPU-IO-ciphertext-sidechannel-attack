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
	{ 0x4eb6f185, "skb_push" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x59a2f0ee, "packing" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xd5a17699, "__skb_vlan_pop" },
	{ 0x6d63a14c, "skb_pull_rcsum" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x99311936, "br_vlan_enabled" },
	{ 0x16da6c69, "br_vlan_get_proto" },
	{ 0x48d93b44, "br_vlan_get_pvid_rcu" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xe489931, "dsa_tag_drivers_register" },
	{ 0xf69aec4a, "dsa_tag_drivers_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "bridge,dsa_core");


MODULE_INFO(srcversion, "41DB812BB8281FB336480E0");
