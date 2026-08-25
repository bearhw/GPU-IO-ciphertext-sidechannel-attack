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
	{ 0x6f64e05d, "counter_priv" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x47392d90, "devm_counter_alloc" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x4331a573, "devm_counter_add" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4f2ce15d, "counter_push_event" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x13b30243, "isa_register_driver" },
	{ 0xd4a33111, "isa_unregister_driver" },
	{ 0x786109b9, "param_array_ops" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "counter");


MODULE_INFO(srcversion, "7F4B91B2693AD3889F3E857");
