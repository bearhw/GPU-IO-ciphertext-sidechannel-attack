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
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xb911bb58, "minmax_running_max" },
	{ 0x56470118, "__warn_printk" },
	{ 0xfd43b4ab, "register_btf_kfunc_id_set" },
	{ 0xd0fe2c67, "tcp_register_congestion_control" },
	{ 0x6914dc9d, "tcp_unregister_congestion_control" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "765B94864F64837746ECC52");
