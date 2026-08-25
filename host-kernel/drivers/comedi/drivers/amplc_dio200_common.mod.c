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

SYMBOL_CRC(amplc_dio200_set_enhance, 0xc23582b6, "_gpl");
SYMBOL_CRC(amplc_dio200_common_attach, 0x2b1d33ea, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2e40b323, "comedi_dio_insn_config" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xf1c0f6f4, "comedi_alloc_spriv" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x68b5d967, "comedi_8254_mm_init" },
	{ 0xd88c6b45, "comedi_8254_subdevice_init" },
	{ 0xbff4f43d, "comedi_set_spriv_auto_free" },
	{ 0xc0424174, "comedi_8254_init" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi,comedi_8254");


MODULE_INFO(srcversion, "1D9C67E76C0EA1C0A4B287A");
