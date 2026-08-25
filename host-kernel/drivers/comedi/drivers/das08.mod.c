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

SYMBOL_CRC(das08_common_attach, 0x849c07bc, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x2f0ad9d3, "range_bipolar5" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0xc0424174, "comedi_8254_init" },
	{ 0xd88c6b45, "comedi_8254_subdevice_init" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4ac45c9a, "comedi_timeout" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2587f789, "_dev_info" },
	{ 0xcd330f4, "range_unknown" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi,comedi_8255,comedi_8254");


MODULE_INFO(srcversion, "13879DDD823E5EAD5A469F4");
