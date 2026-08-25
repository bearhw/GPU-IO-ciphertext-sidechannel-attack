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

SYMBOL_CRC(vbg_get_gdev, 0x35813e55, "");
SYMBOL_CRC(vbg_put_gdev, 0xe51651bf, "");
SYMBOL_CRC(vbg_info, 0x569b312f, "");
SYMBOL_CRC(vbg_warn, 0x70cdcbfd, "");
SYMBOL_CRC(vbg_err, 0x260590c0, "");
SYMBOL_CRC(vbg_err_ratelimited, 0x68f1cf1a, "");
SYMBOL_CRC(vbg_hgcm_connect, 0x18063a09, "");
SYMBOL_CRC(vbg_hgcm_disconnect, 0x72515d2e, "");
SYMBOL_CRC(vbg_hgcm_call, 0x44e30854, "");
SYMBOL_CRC(vbg_status_code_to_errno, 0x9c072aa8, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8a35b432, "sme_me_mask" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xaa0c318b, "vscnprintf" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x9d67f7e3, "devm_input_allocate_device" },
	{ 0x94961283, "vunmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xaddf64b0, "input_register_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x800473f, "__cond_resched" },
	{ 0x2121e851, "device_create_file" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe3660c7e, "input_set_capability" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xed2a2b32, "vmap" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0x402830fd, "from_kuid" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0xfb578fc5, "memset" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x4708008a, "misc_register" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xc2261e62, "input_event" },
	{ 0xd5a679cf, "input_set_abs_params" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x39461d6a, "in_egroup_p" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x77358855, "iomem_resource" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000080EEd0000CAFEsv00000000sd00000000bc*sc*i*");

MODULE_INFO(srcversion, "59B45E9C40EF8E9469ADBCA");
