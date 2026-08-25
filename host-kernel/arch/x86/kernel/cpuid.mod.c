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
	{ 0xdaa33c7e, "device_destroy" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x12362d9f, "cpu_info" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa6257a2f, "complete" },
	{ 0x1f1f589c, "device_create" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xa080c5e5, "smp_call_function_single_async" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeb0c5cb4, "__register_chrdev" },
	{ 0x92997ed8, "_printk" },
	{ 0xb905e0f7, "__class_create" },
	{ 0xa86595d8, "__cpuhp_setup_state" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xda8bae0d, "__cpuhp_remove_state" },
	{ 0x959f9b0c, "no_seek_end_llseek" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "64BCC114AFF7369B216F637");
