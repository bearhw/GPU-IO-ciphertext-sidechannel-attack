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
	{ 0x37a0cba, "kfree" },
	{ 0xdbcec317, "comedi_close" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9a590205, "comedi_dio_get_config" },
	{ 0x18237bac, "comedi_dio_config" },
	{ 0x1c532c0e, "comedi_dio_bitfield2" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xf0ab87db, "comedi_open" },
	{ 0x5e6f4263, "comedi_get_n_channels" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x32ae3e6, "comedi_find_subdevice_by_type" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0x2587f789, "_dev_info" },
	{ 0x73c52860, "comedi_driver_register" },
	{ 0x790c1b0c, "comedi_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "kcomedilib,comedi");


MODULE_INFO(srcversion, "83B904FCF07DE8B04251FF5");
