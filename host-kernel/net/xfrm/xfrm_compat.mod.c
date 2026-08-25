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
	{ 0xd2c99738, "__kmalloc_track_caller" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xfb578fc5, "memset" },
	{ 0x4a0c7516, "xfrm_msg_min" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x8520a781, "nla_put" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xe2521b1c, "xfrma_policy" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd0efd987, "xfrm_register_translator" },
	{ 0xdc2a642a, "xfrm_unregister_translator" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "xfrm_user");


MODULE_INFO(srcversion, "6F891F884B63654135776FA");
