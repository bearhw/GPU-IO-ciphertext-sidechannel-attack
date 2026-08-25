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
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0xb4246d37, "comedi_request_region" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0x4236eaaf, "range_4_20mA" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x21102f87, "range_0_32mA" },
	{ 0x2f0ad9d3, "range_bipolar5" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0xd8957246, "comedi_legacy_detach" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "7A0F4C37DB7EEF08EA40779");
