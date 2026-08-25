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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xeb44339a, "free_pages_exact" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x24fec4ac, "xenbus_switch_state" },
	{ 0xe4979d03, "xenbus_frontend_closed" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x57719632, "gnttab_grant_foreign_access" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x4b931968, "xen_features" },
	{ 0x3362b03c, "xen_p2m_size" },
	{ 0x25f02c87, "xen_p2m_addr" },
	{ 0x3a7d80f9, "xen_max_p2m_pfn" },
	{ 0xfe727411, "get_phys_to_machine" },
	{ 0xe7650b7, "xenbus_alloc_evtchn" },
	{ 0xbc99281e, "xenbus_free_evtchn" },
	{ 0x34eab46d, "bind_evtchn_to_irqhandler" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x7712771a, "unbind_from_irqhandler" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xe1f7ab96, "gnttab_end_foreign_access" },
	{ 0x37a0cba, "kfree" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xecd8f23d, "xenbus_read" },
	{ 0xc6572a90, "xenbus_read_unsigned" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x92997ed8, "_printk" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xd27f215d, "gnttab_alloc_grant_references" },
	{ 0x31dca4d8, "gnttab_claim_grant_reference" },
	{ 0xf27d0a7b, "gnttab_grant_foreign_access_ref" },
	{ 0x52431348, "xenbus_transaction_start" },
	{ 0x4fe00144, "xenbus_dev_fatal" },
	{ 0x6aa2a877, "xenbus_printf" },
	{ 0x732852fe, "xenbus_transaction_end" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x86623fd7, "notify_remote_via_irq" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0x5fc72f0e, "alloc_pages_exact" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x15b5ef2e, "__xenbus_register_frontend" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CB88A824DFA2F58837846DA");
