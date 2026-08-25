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
	{ 0xf341ee35, "tcp_hashinfo" },
	{ 0x474faaa5, "inet_diag_find_one_icsk" },
	{ 0xb6af2b3d, "sock_diag_destroy" },
	{ 0x2c795cac, "sock_gen_put" },
	{ 0x3e8ec4b2, "tcp_get_info" },
	{ 0x4eb853b1, "inet_diag_dump_one_icsk" },
	{ 0x4403ab7e, "inet_diag_dump_icsk" },
	{ 0x8520a781, "nla_put" },
	{ 0xa916b694, "strnlen" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xad115d2, "nla_reserve" },
	{ 0xfb578fc5, "memset" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x720d3ca3, "inet_diag_register" },
	{ 0x915a0c88, "inet_diag_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "inet_diag");


MODULE_INFO(srcversion, "99724035650F8E1CF79510D");
