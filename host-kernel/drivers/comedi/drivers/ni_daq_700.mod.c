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
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0x2e40b323, "comedi_dio_insn_config" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x7024e03d, "comedi_to_pcmcia_dev" },
	{ 0xe63a7161, "comedi_pcmcia_enable" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x60d424e, "comedi_pcmcia_driver_register" },
	{ 0xac6f1934, "comedi_pcmcia_driver_unregister" },
	{ 0xa56b6a6a, "comedi_pcmcia_auto_unconfig" },
	{ 0xc927a35f, "comedi_pcmcia_disable" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pcmcia,comedi");

MODULE_ALIAS("pcmcia:m010Bc4743f*fn*pfn*pa*pb*pc*pd*");

MODULE_INFO(srcversion, "3A13313663690884F2C3529");
