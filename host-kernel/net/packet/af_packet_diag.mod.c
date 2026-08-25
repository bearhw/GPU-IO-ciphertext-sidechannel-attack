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
	{ 0xefc35200, "netlink_net_capable" },
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0xebd2c7da, "sock_i_uid" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x37a5d32, "sock_diag_save_cookie" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xbf1b6ce, "nla_reserve_nohdr" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x8520a781, "nla_put" },
	{ 0xb2a212e7, "sock_diag_register" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xdf448d1c, "fanout_mutex" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0x89adae75, "sock_diag_put_filterinfo" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x45de6f4f, "sock_diag_unregister" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0xa3e78a68, "sock_diag_put_meminfo" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1A681A146239EACD5C1F46F");
