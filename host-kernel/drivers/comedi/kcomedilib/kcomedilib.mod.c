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

SYMBOL_CRC(comedi_open, 0xf0ab87db, "_gpl");
SYMBOL_CRC(comedi_close, 0xdbcec317, "_gpl");
SYMBOL_CRC(comedi_dio_get_config, 0x9a590205, "_gpl");
SYMBOL_CRC(comedi_dio_config, 0x18237bac, "_gpl");
SYMBOL_CRC(comedi_dio_bitfield2, 0x1c532c0e, "_gpl");
SYMBOL_CRC(comedi_find_subdevice_by_type, 0x032ae3e6, "_gpl");
SYMBOL_CRC(comedi_get_n_channels, 0x5e6f4263, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9c2722f, "comedi_dev_put" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7457a54a, "comedi_dev_get_from_minor" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x5a921311, "strncmp" },
	{ 0xeee6efea, "comedi_check_chanlist" },
	{ 0x668b19a1, "down_read" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x53b954a2, "up_read" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "BF59149F7360DB1D6412BEE");
