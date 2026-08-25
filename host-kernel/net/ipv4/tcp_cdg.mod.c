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
	{ 0x37a0cba, "kfree" },
	{ 0xfb578fc5, "memset" },
	{ 0xbe103d3e, "tcp_reno_cong_avoid" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x79154a68, "tcp_enter_cwr" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd0fe2c67, "tcp_register_congestion_control" },
	{ 0x6914dc9d, "tcp_unregister_congestion_control" },
	{ 0xdc1b51c6, "tcp_reno_undo_cwnd" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "28470D1C63BB9A58F8A81E1");
