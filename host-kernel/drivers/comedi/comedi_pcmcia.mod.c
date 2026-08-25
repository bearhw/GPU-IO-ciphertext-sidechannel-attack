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

SYMBOL_CRC(comedi_to_pcmcia_dev, 0x7024e03d, "_gpl");
SYMBOL_CRC(comedi_pcmcia_enable, 0xe63a7161, "_gpl");
SYMBOL_CRC(comedi_pcmcia_disable, 0xc927a35f, "_gpl");
SYMBOL_CRC(comedi_pcmcia_auto_config, 0xa7e75aae, "_gpl");
SYMBOL_CRC(comedi_pcmcia_auto_unconfig, 0xa56b6a6a, "_gpl");
SYMBOL_CRC(comedi_pcmcia_driver_register, 0x060d424e, "_gpl");
SYMBOL_CRC(comedi_pcmcia_driver_unregister, 0xac6f1934, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x745548c3, "pcmcia_loop_config" },
	{ 0x781fa6ce, "pcmcia_enable_device" },
	{ 0x133564c3, "pcmcia_request_io" },
	{ 0x1a6879ec, "pcmcia_disable_device" },
	{ 0xa1ed73ab, "comedi_auto_config" },
	{ 0x5575ac06, "comedi_auto_unconfig" },
	{ 0xb59602ab, "pcmcia_unregister_driver" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x50a9f59c, "pcmcia_register_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcmcia,comedi");


MODULE_INFO(srcversion, "077DDF8BD07AE1E1FC215C5");
