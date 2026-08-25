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
	{ 0x7712771a, "unbind_from_irqhandler" },
	{ 0x1430723c, "p9_req_put" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3362b03c, "xen_p2m_size" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x4fe00144, "xenbus_dev_fatal" },
	{ 0xc6572a90, "xenbus_read_unsigned" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0xecd8f23d, "xenbus_read" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x6aa2a877, "xenbus_printf" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x24fec4ac, "xenbus_switch_state" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe7650b7, "xenbus_alloc_evtchn" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x15b5ef2e, "__xenbus_register_frontend" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0x732852fe, "xenbus_transaction_end" },
	{ 0x9ee2b870, "xenbus_unregister_driver" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xbc99281e, "xenbus_free_evtchn" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x5fc72f0e, "alloc_pages_exact" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x34eab46d, "bind_evtchn_to_irqhandler" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x86623fd7, "notify_remote_via_irq" },
	{ 0xbd07c956, "p9_tag_lookup" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3a7d80f9, "xen_max_p2m_pfn" },
	{ 0x52431348, "xenbus_transaction_start" },
	{ 0x16cd7ad4, "v9fs_register_trans" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x57719632, "gnttab_grant_foreign_access" },
	{ 0xeb44339a, "free_pages_exact" },
	{ 0x4b931968, "xen_features" },
	{ 0xfe727411, "get_phys_to_machine" },
	{ 0xed1b5526, "v9fs_unregister_trans" },
	{ 0x28ac4d9b, "p9_client_cb" },
	{ 0xe4979d03, "xenbus_frontend_closed" },
	{ 0xe1f7ab96, "gnttab_end_foreign_access" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x25f02c87, "xen_p2m_addr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "9pnet");


MODULE_INFO(srcversion, "1D46D02FA9BAC769CE9CCC2");
