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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xbcd4b433, "iput" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x37a0cba, "kfree" },
	{ 0x5d8a72fe, "init_pseudo" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xbdde263a, "alloc_anon_inode" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xe1b968a5, "__ClearPageMovable" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0xcd72be06, "__folio_lock" },
	{ 0x49608959, "migrate_disable" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4d7272e4, "migrate_enable" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x92997ed8, "_printk" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x52130aa3, "page_mapping" },
	{ 0xf19a6bbb, "__SetPageMovable" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x10795da2, "__put_page" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0xb0e602eb, "memmove" },
	{ 0x69acdf38, "memcpy" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x4d3b1fe9, "kern_mount" },
	{ 0x5c0f54b, "zpool_register_driver" },
	{ 0xbaa29ca6, "kern_unmount" },
	{ 0xd35b19c7, "zpool_unregister_driver" },
	{ 0x82b7c307, "kill_anon_super" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "62F5EF4E3E753EAC6922B0C");
