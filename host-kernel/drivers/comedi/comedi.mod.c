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

SYMBOL_CRC(comedi_dev_put, 0xd9c2722f, "_gpl");
SYMBOL_CRC(comedi_dev_get_from_minor, 0x7457a54a, "_gpl");
SYMBOL_CRC(comedi_is_subdevice_running, 0x9d784270, "_gpl");
SYMBOL_CRC(comedi_set_spriv_auto_free, 0xbff4f43d, "_gpl");
SYMBOL_CRC(comedi_alloc_spriv, 0xf1c0f6f4, "_gpl");
SYMBOL_CRC(comedi_event, 0x45ab5ce7, "_gpl");
SYMBOL_CRC(range_bipolar10, 0xbb52fc7f, "_gpl");
SYMBOL_CRC(range_bipolar5, 0x2f0ad9d3, "_gpl");
SYMBOL_CRC(range_bipolar2_5, 0x4fe634f3, "_gpl");
SYMBOL_CRC(range_unipolar10, 0x8113872c, "_gpl");
SYMBOL_CRC(range_unipolar5, 0xdb2044b2, "_gpl");
SYMBOL_CRC(range_unipolar2_5, 0xbdbe75c6, "_gpl");
SYMBOL_CRC(range_0_20mA, 0xb679cebc, "_gpl");
SYMBOL_CRC(range_4_20mA, 0x4236eaaf, "_gpl");
SYMBOL_CRC(range_0_32mA, 0x21102f87, "_gpl");
SYMBOL_CRC(range_unknown, 0x0cd330f4, "_gpl");
SYMBOL_CRC(comedi_check_chanlist, 0xeee6efea, "_gpl");
SYMBOL_CRC(comedi_set_hw_dev, 0x798b7aa6, "_gpl");
SYMBOL_CRC(comedi_alloc_devpriv, 0x7e2f11fc, "_gpl");
SYMBOL_CRC(comedi_alloc_subdevices, 0x9b66e218, "_gpl");
SYMBOL_CRC(comedi_alloc_subdev_readback, 0x86e07916, "_gpl");
SYMBOL_CRC(comedi_readback_insn_read, 0x0c7b658f, "_gpl");
SYMBOL_CRC(comedi_timeout, 0x4ac45c9a, "_gpl");
SYMBOL_CRC(comedi_dio_insn_config, 0x2e40b323, "_gpl");
SYMBOL_CRC(comedi_dio_update_state, 0x06256868, "_gpl");
SYMBOL_CRC(comedi_bytes_per_scan_cmd, 0x9b5dbf58, "_gpl");
SYMBOL_CRC(comedi_bytes_per_scan, 0xba8043ee, "_gpl");
SYMBOL_CRC(comedi_nscans_left, 0xb8f1eb1f, "_gpl");
SYMBOL_CRC(comedi_nsamples_left, 0x6ed165e0, "_gpl");
SYMBOL_CRC(comedi_inc_scan_progress, 0x4ea2cf27, "_gpl");
SYMBOL_CRC(comedi_handle_events, 0x3fa52e21, "_gpl");
SYMBOL_CRC(comedi_load_firmware, 0x3fe0bdf8, "_gpl");
SYMBOL_CRC(__comedi_request_region, 0xc8b1fea8, "_gpl");
SYMBOL_CRC(comedi_request_region, 0xb4246d37, "_gpl");
SYMBOL_CRC(comedi_legacy_detach, 0xd8957246, "_gpl");
SYMBOL_CRC(comedi_auto_config, 0xa1ed73ab, "_gpl");
SYMBOL_CRC(comedi_auto_unconfig, 0x5575ac06, "_gpl");
SYMBOL_CRC(comedi_driver_register, 0x73c52860, "_gpl");
SYMBOL_CRC(comedi_driver_unregister, 0x790c1b0c, "_gpl");
SYMBOL_CRC(comedi_buf_write_alloc, 0xf14b6194, "_gpl");
SYMBOL_CRC(comedi_buf_write_free, 0x0b8c6fad, "_gpl");
SYMBOL_CRC(comedi_buf_read_n_available, 0xcbd41e95, "_gpl");
SYMBOL_CRC(comedi_buf_read_alloc, 0xe741a6bb, "_gpl");
SYMBOL_CRC(comedi_buf_read_free, 0x6d840572, "_gpl");
SYMBOL_CRC(comedi_buf_write_samples, 0x00079cb1, "_gpl");
SYMBOL_CRC(comedi_buf_read_samples, 0x369058ca, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8a35b432, "sme_me_mask" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0xb905e0f7, "__class_create" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x5897cdd4, "param_ops_ushort" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0xb0285ae, "kill_fasync" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x69acdf38, "memcpy" },
	{ 0xd6727dc4, "remap_pfn_range" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x94961283, "vunmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc3ff38c2, "down_read_trylock" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa916b694, "strnlen" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x2587f789, "_dev_info" },
	{ 0xc6cbbc89, "capable" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x8057ff4, "cdev_add" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xce807a25, "up_write" },
	{ 0x1f1f589c, "device_create" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xa4cdf212, "fasync_helper" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xed2a2b32, "vmap" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xdd64e639, "strscpy" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x999e8297, "vfree" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x95352ea6, "kobject_set_name" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x391de184, "seq_puts" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xae5917ce, "dma_mmap_attrs" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xa6aa1711, "proc_create_single_data" },
	{ 0x3fd78f3b, "register_chrdev_region" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x53b954a2, "up_read" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x113f6db6, "cdev_del" },
	{ 0x85bd1608, "__request_region" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3C45692FC8FEDE3DC6C98A0");
