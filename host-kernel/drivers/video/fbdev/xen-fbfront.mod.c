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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xe7650b7, "xenbus_alloc_evtchn" },
	{ 0x34eab46d, "bind_evtchn_to_irqhandler" },
	{ 0x6aa2a877, "xenbus_printf" },
	{ 0x732852fe, "xenbus_transaction_end" },
	{ 0x52431348, "xenbus_transaction_start" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x4b931968, "xen_features" },
	{ 0x3362b03c, "xen_p2m_size" },
	{ 0x25f02c87, "xen_p2m_addr" },
	{ 0x3a7d80f9, "xen_max_p2m_pfn" },
	{ 0xfe727411, "get_phys_to_machine" },
	{ 0x4fe00144, "xenbus_dev_fatal" },
	{ 0x7712771a, "unbind_from_irqhandler" },
	{ 0xbc99281e, "xenbus_free_evtchn" },
	{ 0x24fec4ac, "xenbus_switch_state" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x86623fd7, "notify_remote_via_irq" },
	{ 0x16cb454, "fb_deferred_io_cleanup" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x999e8297, "vfree" },
	{ 0x37a0cba, "kfree" },
	{ 0xc6572a90, "xenbus_read_unsigned" },
	{ 0xe4979d03, "xenbus_frontend_closed" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3e343b7b, "sys_imageblit" },
	{ 0x1a1c7d7f, "sys_copyarea" },
	{ 0x63000ec2, "sys_fillrect" },
	{ 0xd3f2af1e, "fb_sys_write" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x6502d9c2, "xenbus_scanf" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0x32294d1f, "fb_deferred_io_init" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x2459bbcc, "console_set_on_cmdline" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0xc91745f5, "console_drivers" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xc631580a, "console_unlock" },
	{ 0x4d00c819, "unregister_console" },
	{ 0x9373b350, "register_console" },
	{ 0x92997ed8, "_printk" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x54ea6dfe, "xen_start_flags" },
	{ 0x85cb2c45, "xen_has_pv_devices" },
	{ 0x15b5ef2e, "__xenbus_register_frontend" },
	{ 0x9ee2b870, "xenbus_unregister_driver" },
	{ 0xd1be46b0, "fb_sys_read" },
	{ 0xc5f26a2b, "fb_deferred_io_mmap" },
	{ 0x786109b9, "param_array_ops" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sysimgblt,syscopyarea,sysfillrect,fb_sys_fops");


MODULE_INFO(srcversion, "C4294CC2D0C7F5D4789713B");
