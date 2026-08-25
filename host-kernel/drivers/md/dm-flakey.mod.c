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
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x58cadab8, "dm_report_zones" },
	{ 0x96848186, "scnprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x5eb24829, "dm_shift_arg" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x11e0ec41, "dm_read_arg" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0xc7d094b5, "dm_read_arg_group" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0x92997ed8, "_printk" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "39724945577BAAB00A05581");
