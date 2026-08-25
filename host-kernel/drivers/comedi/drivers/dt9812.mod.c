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
	{ 0xe142ae3c, "comedi_usb_auto_config" },
	{ 0xa3c6cf82, "comedi_to_usb_interface" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xc7b658f, "comedi_readback_insn_read" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa4b6b817, "comedi_to_usb_dev" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xec6c0a91, "usb_bulk_msg" },
	{ 0x37a0cba, "kfree" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xfacc6157, "usb_reset_configuration" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xbdbe75c6, "range_unipolar2_5" },
	{ 0xbb52fc7f, "range_bipolar10" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0x3b8b9015, "comedi_usb_driver_register" },
	{ 0x777dfa46, "comedi_usb_driver_unregister" },
	{ 0x32d675bb, "comedi_usb_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_usb,comedi");

MODULE_ALIAS("usb:v0867p9812d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "5E05E7AE73F05303223EACD");
