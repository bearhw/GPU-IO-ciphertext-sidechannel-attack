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
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x9593ef31, "register_ftrace_export" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x81f372a2, "unregister_ftrace_export" },
	{ 0xc79cb4b2, "stm_source_unregister_device" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x5ee254d0, "stm_source_register_device" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x29863f97, "stm_source_write" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "stm_core");


MODULE_INFO(srcversion, "E9F53008F03D8D2E9FD519B");
