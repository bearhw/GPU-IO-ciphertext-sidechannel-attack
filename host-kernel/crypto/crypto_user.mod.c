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
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x35d3dc46, "crypto_alg_sem" },
	{ 0xf4d389a1, "crypto_alg_mod_lookup" },
	{ 0x8ccb66c5, "__netlink_kernel_create" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x1b556d75, "netlink_capable" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x8520a781, "nla_put" },
	{ 0xee18e3f7, "netlink_rcv_skb" },
	{ 0x67a3423c, "crypto_unregister_instance" },
	{ 0x1cbbb7c, "netlink_kernel_release" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x1cc0531b, "crypto_mod_get" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xdd64e639, "strscpy" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x457594fa, "crypto_alg_list" },
	{ 0xbf2eba7d, "crypto_remove_spawns" },
	{ 0x5bd0748f, "crypto_del_default_rng" },
	{ 0x64498c3e, "crypto_mod_put" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x3de9cae1, "crypto_remove_final" },
	{ 0x53b954a2, "up_read" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D1DFE68342A659ABBF18E8B");
