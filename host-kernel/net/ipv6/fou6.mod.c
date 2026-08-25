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
	{ 0xdf27a4e5, "udp6_set_csum" },
	{ 0xbd71c13e, "__gue_build_header" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2e871af2, "__fou_build_header" },
	{ 0x104d4bc5, "inet6_protos" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x1fdb9df2, "ip6_tnl_encap_add_ops" },
	{ 0x92997ed8, "_printk" },
	{ 0xd4f953fc, "ip6_tnl_encap_del_ops" },
	{ 0xf13914b3, "gue_encap_hlen" },
	{ 0x1757d1a4, "fou_encap_hlen" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fou,ip6_tunnel");


MODULE_INFO(srcversion, "4B51D0FA5058C78E6E0CB78");
