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

SYMBOL_CRC(intel_th_msu_buffer_register, 0x722f72ed, "_gpl");
SYMBOL_CRC(intel_th_msu_buffer_unregister, 0x1d62776c, "_gpl");
SYMBOL_CRC(intel_th_msc_window_unlock, 0x2306f7d0, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xab65ed80, "set_memory_uc" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x575d1ed3, "intel_th_trace_switch" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0x91607d95, "set_memory_wb" },
	{ 0x96848186, "scnprintf" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x37a0cba, "kfree" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x515f47fa, "intel_th_trace_enable" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x2587f789, "_dev_info" },
	{ 0xc6cbbc89, "capable" },
	{ 0x1de23e95, "module_put" },
	{ 0xcfc9deaf, "atomic_dec_and_mutex_lock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xc2f5bb2f, "split_page" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0xa07a37f0, "memchr" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3b48a9d9, "nonseekable_open" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x286a108e, "intel_th_driver_register" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x87b8798d, "sg_next" },
	{ 0x730bfc73, "intel_th_trace_disable" },
	{ 0x636a2492, "no_llseek" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x7795f368, "intel_th_driver_unregister" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x81188c30, "match_string" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "intel_th");


MODULE_INFO(srcversion, "25F7A9A20C938133292EE37");
