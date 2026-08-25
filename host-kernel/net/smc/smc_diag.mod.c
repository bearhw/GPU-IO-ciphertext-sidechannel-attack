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
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x37a5d32, "sock_diag_save_cookie" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xebd2c7da, "sock_i_uid" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x275603a1, "smc_proto" },
	{ 0x5402bfef, "smc_proto6" },
	{ 0xb2a212e7, "sock_diag_register" },
	{ 0x45de6f4f, "sock_diag_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "smc");


MODULE_INFO(srcversion, "7AA4CE71923617A51A2B954");
