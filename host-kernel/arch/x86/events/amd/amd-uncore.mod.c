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
	{ 0xf474c21c, "bitmap_print_to_pagebuf" },
	{ 0x37a0cba, "kfree" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x97ed721b, "perf_event_update_userpage" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x618911fc, "numa_node" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7539145c, "perf_pmu_migrate_context" },
	{ 0x25750a11, "perf_pmu_register" },
	{ 0xbb5598ce, "get_llc_id" },
	{ 0xa86595d8, "__cpuhp_setup_state" },
	{ 0x983b9baa, "perf_pmu_unregister" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x6d606913, "pv_ops" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xda8bae0d, "__cpuhp_remove_state" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "274F03E0A1567F107682329");
