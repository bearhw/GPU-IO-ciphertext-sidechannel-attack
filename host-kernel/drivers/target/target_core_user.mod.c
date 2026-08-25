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
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x6a6e05bf, "kstrtou8" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa6257a2f, "complete" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x37a0cba, "kfree" },
	{ 0xaa50bea4, "uio_event_notify" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x86490580, "current_task" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x69acdf38, "memcpy" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xe189049a, "passthrough_parse_cdb" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x7429e20c, "kstrtos8" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x50fad434, "round_jiffies_up" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xf07e285d, "genlmsg_multicast_allns" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x8fa25c24, "xa_find" },
	{ 0xfdf39e99, "unlock_page" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xdf36914b, "xa_find_after" },
	{ 0x745a981, "xa_erase" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xcd72be06, "__folio_lock" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0xffc86f14, "__xas_next" },
	{ 0x5b3e282f, "xa_store" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x999e8297, "vfree" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xd9491c14, "xa_destroy" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x85df9b6c, "strsep" },
	{ 0x44e9a829, "match_token" },
	{ 0x4e3567f7, "match_int" },
	{ 0xfba7ddd2, "match_u64" },
	{ 0x3539f11b, "match_strlcpy" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0x754d539c, "strlen" },
	{ 0x8520a781, "nla_put" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x9061f154, "__uio_register_device" },
	{ 0xf14a7a00, "uio_unregister_device" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xfb578fc5, "memset" },
	{ 0x6cab4b6b, "target_complete_cmd" },
	{ 0x1dd8eda9, "target_complete_cmd_with_length" },
	{ 0x5fe9aab5, "transport_copy_sense_to_cmd" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x334da4e, "scsi_command_size_tbl" },
	{ 0x9114b616, "__xa_alloc" },
	{ 0x4af6ddf0, "kstrtou16" },
	{ 0x31d34278, "xas_load" },
	{ 0x677ff88c, "xas_store" },
	{ 0x9ae47436, "_find_last_bit" },
	{ 0x79cc14e8, "unmap_mapping_range" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x27352a9d, "__root_device_register" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0x3aed5964, "passthrough_attrib_attrs" },
	{ 0xe6b161a, "passthrough_pr_attrib_attrs" },
	{ 0xec722f37, "transport_backend_register" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0x1c6dbfe, "root_device_unregister" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0xded62f97, "target_backend_unregister" },
	{ 0xf7dcd754, "sbc_get_device_type" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "uio,target_core_mod");


MODULE_INFO(srcversion, "CF278A71CC7458452103C54");
