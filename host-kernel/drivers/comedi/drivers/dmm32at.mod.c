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
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb4246d37, "comedi_request_region" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0xd8957246, "comedi_legacy_detach" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi,comedi_8255");


MODULE_INFO(srcversion, "7DD8609167F1D8E538047A0");
