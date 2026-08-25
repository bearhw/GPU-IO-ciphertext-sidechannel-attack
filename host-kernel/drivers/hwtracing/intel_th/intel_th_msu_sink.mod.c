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
	{ 0x2306f7d0, "intel_th_msc_window_unlock" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0x37a0cba, "kfree" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0x1d62776c, "intel_th_msu_buffer_unregister" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x722f72ed, "intel_th_msu_buffer_register" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x87b8798d, "sg_next" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "intel_th_msu");


MODULE_INFO(srcversion, "B139D1A16A7ADA72A9BCEFB");
