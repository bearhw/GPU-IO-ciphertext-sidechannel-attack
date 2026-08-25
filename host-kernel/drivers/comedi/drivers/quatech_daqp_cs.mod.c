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
	{ 0xa7e75aae, "comedi_pcmcia_auto_config" },
	{ 0x7024e03d, "comedi_to_pcmcia_dev" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0xe63a7161, "comedi_pcmcia_enable" },
	{ 0x33860e8, "pcmcia_request_irq" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x2f0ad9d3, "range_bipolar5" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x60d424e, "comedi_pcmcia_driver_register" },
	{ 0xac6f1934, "comedi_pcmcia_driver_unregister" },
	{ 0xa56b6a6a, "comedi_pcmcia_auto_unconfig" },
	{ 0xc927a35f, "comedi_pcmcia_disable" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pcmcia,comedi,pcmcia");

MODULE_ALIAS("pcmcia:m0137c0027f*fn*pfn*pa*pb*pc*pd*");

MODULE_INFO(srcversion, "1AF571939098EE20400B616");
