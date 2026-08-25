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
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x1b015d25, "bitmap_parselist" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x10795da2, "__put_page" },
	{ 0xcabcd476, "anon_inode_getfile" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x683cd46f, "pci_msix_vec_count" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xae121354, "pci_iomap" },
	{ 0x246e2c44, "param_get_string" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x27b9f3d6, "pci_request_regions_exclusive" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0xbd8bbd97, "fd_install" },
	{ 0x37a0cba, "kfree" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcff98af0, "param_set_copystring" },
	{ 0x3f4547a7, "put_unused_fd" },
	{ 0x6701489e, "PageHuge" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x92997ed8, "_printk" },
	{ 0x848d372e, "iowrite8" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x618911fc, "numa_node" },
	{ 0xc6cbbc89, "capable" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7eb808d0, "add_cpu" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xd28f6a7f, "fput" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xff80f59, "zalloc_cpumask_var" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xb19b445, "ioread8" },
	{ 0xfb578fc5, "memset" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0x4708008a, "misc_register" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xb86f74c5, "free_cpumask_var" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa843805a, "get_unused_fd_flags" },
	{ 0x12362d9f, "cpu_info" },
	{ 0xad4e6259, "remove_cpu" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0xe03af536, "get_user_pages_unlocked" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x3b83610f, "cpu_sibling_map" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001D0Fd0000E4C1sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "CE427F237319ECFBD2B659B");
