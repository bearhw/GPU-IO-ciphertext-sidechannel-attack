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
	{ 0x6d606913, "pv_ops" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x2e40b323, "comedi_dio_insn_config" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xb4246d37, "comedi_request_region" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0xcd330f4, "range_unknown" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0x8113872c, "range_unipolar10" },
	{ 0xbb52fc7f, "range_bipolar10" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0xd8957246, "comedi_legacy_detach" },
	{ 0x2f0ad9d3, "range_bipolar5" },
	{ 0x4fe634f3, "range_bipolar2_5" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "17F6E81D417FD577046494F");
