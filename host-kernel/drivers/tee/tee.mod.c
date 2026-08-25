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

SYMBOL_CRC(teedev_open, 0x9fec0472, "_gpl");
SYMBOL_CRC(teedev_close_context, 0xc1c0ab31, "_gpl");
SYMBOL_CRC(tee_session_calc_client_uuid, 0x85fd9922, "_gpl");
SYMBOL_CRC(tee_device_alloc, 0x703d5a9d, "_gpl");
SYMBOL_CRC(tee_device_register, 0x3ca4771c, "_gpl");
SYMBOL_CRC(tee_device_unregister, 0xeb1aab81, "_gpl");
SYMBOL_CRC(tee_get_drvdata, 0xc8fc0586, "_gpl");
SYMBOL_CRC(tee_client_open_context, 0x37fe8e62, "_gpl");
SYMBOL_CRC(tee_client_close_context, 0x5573de19, "_gpl");
SYMBOL_CRC(tee_client_get_version, 0xc75287d0, "_gpl");
SYMBOL_CRC(tee_client_open_session, 0x07a61200, "_gpl");
SYMBOL_CRC(tee_client_close_session, 0x68dcbe16, "_gpl");
SYMBOL_CRC(tee_client_invoke_func, 0x74701231, "_gpl");
SYMBOL_CRC(tee_bus_type, 0xef216d86, "_gpl");
SYMBOL_CRC(tee_shm_alloc_kernel_buf, 0x2e3a8511, "_gpl");
SYMBOL_CRC(tee_shm_alloc_priv_buf, 0x4287cd2a, "_gpl");
SYMBOL_CRC(tee_shm_register_kernel_buf, 0x138e2be2, "_gpl");
SYMBOL_CRC(tee_shm_free, 0x419c2abb, "_gpl");
SYMBOL_CRC(tee_shm_get_va, 0x9402c675, "_gpl");
SYMBOL_CRC(tee_shm_get_pa, 0xba894de7, "_gpl");
SYMBOL_CRC(tee_shm_get_from_id, 0x9534291d, "_gpl");
SYMBOL_CRC(tee_shm_put, 0xa6817098, "_gpl");
SYMBOL_CRC(tee_shm_pool_alloc_res_mem, 0x386ff498, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd7f43eda, "pin_user_pages_fast" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x10795da2, "__put_page" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x20978fb9, "idr_find" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xced0f4d4, "gen_pool_create" },
	{ 0x67735685, "cdev_device_del" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x96848186, "scnprintf" },
	{ 0x7b82b9a1, "idr_replace" },
	{ 0xbd3718be, "device_initialize" },
	{ 0xc8814bbc, "unpin_user_pages" },
	{ 0xd6727dc4, "remap_pfn_range" },
	{ 0x37a0cba, "kfree" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6c224cda, "gen_pool_destroy" },
	{ 0x92997ed8, "_printk" },
	{ 0x75d94f40, "cdev_device_add" },
	{ 0x62567d06, "anon_inode_getfd" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x6dcf857f, "uuid_null" },
	{ 0xc77b4f92, "crypto_shash_update" },
	{ 0xfea06184, "get_kernel_pages" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0xfb578fc5, "memset" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xbefa51a3, "gen_pool_add_owner" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x9265315, "crypto_shash_final" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x60ba97c, "gen_pool_free_owner" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x2b593aa8, "gen_pool_alloc_algo_owner" },
	{ 0x5e855e56, "gen_pool_first_fit_align" },
	{ 0x7d0ba682, "gen_pool_virt_to_phys" },
	{ 0x39461d6a, "in_egroup_p" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xbacc0824, "crypto_alloc_shash" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x7ce88a05, "class_find_device" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D8F37604F70B4AA18A02164");
