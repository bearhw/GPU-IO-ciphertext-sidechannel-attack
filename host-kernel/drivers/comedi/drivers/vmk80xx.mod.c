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
	{ 0xa4b6b817, "comedi_to_usb_dev" },
	{ 0xec6c0a91, "usb_bulk_msg" },
	{ 0x1fbada2a, "usb_interrupt_msg" },
	{ 0x6626afca, "down" },
	{ 0xcf2a6966, "up" },
	{ 0xb678366f, "int_sqrt" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0xa3c6cf82, "comedi_to_usb_interface" },
	{ 0x37a0cba, "kfree" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3b8b9015, "comedi_usb_driver_register" },
	{ 0x777dfa46, "comedi_usb_driver_unregister" },
	{ 0x32d675bb, "comedi_usb_auto_unconfig" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_usb,comedi");

MODULE_ALIAS("usb:v10CFp5500d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp5501d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp5502d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp5503d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8061d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8062d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8063d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8064d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8065d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8066d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8067d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8068d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "5CD3C4D1C74C81FC3A2A2D2");
