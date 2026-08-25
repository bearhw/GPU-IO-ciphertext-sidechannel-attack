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
	{ 0xa78af5f3, "ioread32" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x11089ac7, "_ctype" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2587f789, "_dev_info" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x1b1cdbe1, "atm_dev_deregister" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0xbd505649, "consume_skb" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0x37a0cba, "kfree" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xf9c0b663, "strlcat" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1000e51, "schedule" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x6d606913, "pv_ops" },
	{ 0x69acdf38, "memcpy" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xcd3165e6, "__dev_kfree_skb_irq" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbe888b32, "skb_put" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xae121354, "pci_iomap" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x99d368a7, "atm_dev_register" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x2121e851, "device_create_file" },
	{ 0x3e9936e5, "atm_dev_signal_change" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x44c6e633, "vcc_sklist_lock" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x2cc2d52d, "vcc_hash" },
	{ 0x3926200e, "atm_charge" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x754d539c, "strlen" },
	{ 0x86490580, "current_task" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x5a921311, "strncmp" },
	{ 0x738737f9, "skb_unlink" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x350f6ce5, "tasklet_unlock_wait" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");

MODULE_ALIAS("pci:v000010EEd00000300sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "CF441E45521C3CA05F2A54F");
