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
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x914ca4d7, "ip_vs_proto_get" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xec623802, "ipv6_find_hdr" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x97fcf9f5, "xt_register_match" },
	{ 0x8ae43d15, "xt_unregister_match" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_vs,x_tables");


MODULE_INFO(srcversion, "063C9F4568E62FA4D62A726");
