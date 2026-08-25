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

SYMBOL_CRC(subdev_8255_init, 0xbe6fb8b1, "_gpl");
SYMBOL_CRC(subdev_8255_mm_init, 0x2b179514, "_gpl");
SYMBOL_CRC(subdev_8255_regbase, 0x370d65a6, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2e40b323, "comedi_dio_insn_config" },
	{ 0xf1c0f6f4, "comedi_alloc_spriv" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "F62C98B658990DE58F86FDF");
