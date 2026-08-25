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
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x37a0cba, "kfree" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc79cb4b2, "stm_source_unregister_device" },
	{ 0x5ee254d0, "stm_source_register_device" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x29863f97, "stm_source_write" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0x828e22f4, "hrtimer_forward" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "stm_core");


MODULE_INFO(srcversion, "04C3D5F97038023536D5010");
