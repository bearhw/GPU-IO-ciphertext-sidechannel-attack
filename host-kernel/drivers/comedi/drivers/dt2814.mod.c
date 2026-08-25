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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd8957246, "comedi_legacy_detach" },
	{ 0xb4246d37, "comedi_request_region" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xcd330f4, "range_unknown" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "013115F357DECDDF9563B27");
