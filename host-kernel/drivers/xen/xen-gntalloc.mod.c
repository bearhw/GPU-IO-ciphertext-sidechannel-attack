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
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x3362b03c, "xen_p2m_size" },
	{ 0x204f2c5c, "gnttab_free_grant_reference" },
	{ 0xcaf1d958, "evtchn_get" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x37a0cba, "kfree" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa687cbb6, "vm_insert_page" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4708008a, "misc_register" },
	{ 0x14ec4fdb, "evtchn_put" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x3a7d80f9, "xen_max_p2m_pfn" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x57719632, "gnttab_grant_foreign_access" },
	{ 0x4b931968, "xen_features" },
	{ 0xfe727411, "get_phys_to_machine" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xe1f7ab96, "gnttab_end_foreign_access" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x45d14bdf, "hypercall_page" },
	{ 0x25f02c87, "xen_p2m_addr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "60CF7513C6E2F4A359E858C");
