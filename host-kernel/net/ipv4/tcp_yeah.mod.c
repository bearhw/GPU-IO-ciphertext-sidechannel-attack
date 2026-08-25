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
	{ 0xdcf6d7d6, "tcp_vegas_init" },
	{ 0xf66564de, "tcp_cong_avoid_ai" },
	{ 0xaa85cd71, "tcp_slow_start" },
	{ 0xd0fe2c67, "tcp_register_congestion_control" },
	{ 0x6914dc9d, "tcp_unregister_congestion_control" },
	{ 0x1ff4d4d7, "tcp_vegas_state" },
	{ 0x10d72f57, "tcp_vegas_cwnd_event" },
	{ 0xdde4b914, "tcp_vegas_pkts_acked" },
	{ 0xdc1b51c6, "tcp_reno_undo_cwnd" },
	{ 0xaa9fbe4e, "tcp_vegas_get_info" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "tcp_vegas");


MODULE_INFO(srcversion, "985D2B48460A4718CB0839E");
