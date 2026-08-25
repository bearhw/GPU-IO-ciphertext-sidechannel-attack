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
	{ 0xbe1bbf53, "ip_set_nfnl_put" },
	{ 0x7d0b6ea8, "ip_set_nfnl_get_byindex" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xaad3f406, "ip_set_add" },
	{ 0xaca83782, "ip_set_del" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb9867643, "ip_set_test" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7ec922ce, "xt_register_matches" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0x4bb1f65e, "xt_unregister_matches" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_set,x_tables");


MODULE_INFO(srcversion, "2664E89D13CED67CA5A2AEC");
