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
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x92997ed8, "_printk" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x11c7992a, "ipv6_find_tlv" },
	{ 0x5d5d050c, "km_report" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe7097cd2, "icmp6_send" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x24c60e49, "xfrm_register_type" },
	{ 0x918124c9, "rawv6_mh_filter_register" },
	{ 0x844bd2de, "xfrm_unregister_type" },
	{ 0x1f972c58, "rawv6_mh_filter_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "262EA760496938CB4CC87F2");
