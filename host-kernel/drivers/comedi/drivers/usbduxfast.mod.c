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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x5f0fb884, "usb_kill_urb" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa4b6b817, "comedi_to_usb_dev" },
	{ 0x6e96a6ed, "usb_submit_urb" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6ed165e0, "comedi_nsamples_left" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x45ab5ce7, "comedi_event" },
	{ 0xa3c6cf82, "comedi_to_usb_interface" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa9f4fd3b, "usb_set_interface" },
	{ 0x5a735d55, "usb_alloc_urb" },
	{ 0x3fe0bdf8, "comedi_load_firmware" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0x37a0cba, "kfree" },
	{ 0x1ad22551, "usb_free_urb" },
	{ 0xec6c0a91, "usb_bulk_msg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3b8b9015, "comedi_usb_driver_register" },
	{ 0x777dfa46, "comedi_usb_driver_unregister" },
	{ 0x32d675bb, "comedi_usb_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_usb,comedi");

MODULE_ALIAS("usb:v13D8p0010d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D8p0011d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "7740D93479CB6FE0A597641");
