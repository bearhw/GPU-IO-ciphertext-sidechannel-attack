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
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x6c94fa3e, "i3c_master_unregister" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xb0e602eb, "memmove" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0xa6257a2f, "complete" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xbb126c9a, "i3c_master_get_free_addr" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x694af998, "i3c_generic_ibi_alloc_pool" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x9033a0c5, "i3c_master_enec_locked" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeddeb948, "i3c_master_add_i3c_dev_locked" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9f4099, "i3c_master_set_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x7ad4242b, "i3c_generic_ibi_get_free_slot" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x6cee69e8, "i3c_generic_ibi_recycle_slot" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0x76fe3e05, "i3c_generic_ibi_free_pool" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x56470118, "__warn_printk" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xfdc0f64c, "i3c_master_disec_locked" },
	{ 0x6b7080dd, "i3c_master_register" },
	{ 0x1c675c26, "_dev_crit" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x223b920c, "i3c_master_queue_ibi" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "i3c");

MODULE_ALIAS("of:N*T*Cmipi-i3c-hci");
MODULE_ALIAS("of:N*T*Cmipi-i3c-hciC*");

MODULE_INFO(srcversion, "A70929E71CB94F12C52A5E8");
