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

SYMBOL_CRC(comedi_8254_status, 0x62cc8923, "_gpl");
SYMBOL_CRC(comedi_8254_read, 0x2caf7357, "_gpl");
SYMBOL_CRC(comedi_8254_write, 0x4c672995, "_gpl");
SYMBOL_CRC(comedi_8254_set_mode, 0x9dbf2816, "_gpl");
SYMBOL_CRC(comedi_8254_load, 0x708b5064, "_gpl");
SYMBOL_CRC(comedi_8254_pacer_enable, 0xc0d4ea32, "_gpl");
SYMBOL_CRC(comedi_8254_update_divisors, 0x2d446dbb, "_gpl");
SYMBOL_CRC(comedi_8254_cascade_ns_to_timer, 0x44a53057, "_gpl");
SYMBOL_CRC(comedi_8254_ns_to_timer, 0xe5a06f74, "_gpl");
SYMBOL_CRC(comedi_8254_set_busy, 0xe6b1ef31, "_gpl");
SYMBOL_CRC(comedi_8254_subdevice_init, 0xd88c6b45, "_gpl");
SYMBOL_CRC(comedi_8254_init, 0xc0424174, "_gpl");
SYMBOL_CRC(comedi_8254_mm_init, 0x68b5d967, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xcd330f4, "range_unknown" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi");


MODULE_INFO(srcversion, "FC372963EA580596173A5B6");
