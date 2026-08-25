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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xf2a22dc6, "w1_remove_master_device" },
	{ 0x1065192a, "usb_put_dev" },
	{ 0x37a0cba, "kfree" },
	{ 0xec6c0a91, "usb_bulk_msg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0x1fbada2a, "usb_interrupt_msg" },
	{ 0x2587f789, "_dev_info" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xf8e504bd, "usb_clear_halt" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb210748a, "usb_get_dev" },
	{ 0xfacc6157, "usb_reset_configuration" },
	{ 0xa9f4fd3b, "usb_set_interface" },
	{ 0xcf9384e, "w1_add_master_device" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xfb578fc5, "memset" },
	{ 0x69acdf38, "memcpy" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0x821e463, "usb_deregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "wire");

MODULE_ALIAS("usb:v04FAp2490d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "071AD93C611D13602C2F252");
