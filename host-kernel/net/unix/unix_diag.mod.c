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
	{ 0xebd2c7da, "sock_i_uid" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xad115d2, "nla_reserve" },
	{ 0x37a5d32, "sock_diag_save_cookie" },
	{ 0xa2b06af, "unix_outq_len" },
	{ 0x2ec631e3, "sock_diag_check_cookie" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xdca3d057, "unix_inq_len" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xae581fa8, "unix_table_locks" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4b37d7b7, "unix_peer_get" },
	{ 0x8520a781, "nla_put" },
	{ 0xb2a212e7, "sock_diag_register" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0x45de6f4f, "sock_diag_unregister" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0xa3e78a68, "sock_diag_put_meminfo" },
	{ 0x1d77b0f8, "unix_socket_table" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D4B27CEE48978A9B3885A43");
