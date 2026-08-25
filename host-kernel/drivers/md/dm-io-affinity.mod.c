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
	{ 0x5e717fd1, "dm_unregister_path_selector" },
	{ 0x96848186, "scnprintf" },
	{ 0x37a0cba, "kfree" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x1d37304, "dm_register_path_selector" },
	{ 0x92997ed8, "_printk" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x618911fc, "numa_node" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xff80f59, "zalloc_cpumask_var" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xb86f74c5, "free_cpumask_var" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xb97220ff, "bitmap_parse" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x45d246da, "node_to_cpumask_map" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dm-multipath");


MODULE_INFO(srcversion, "D62E576A50D7543468A90DB");
