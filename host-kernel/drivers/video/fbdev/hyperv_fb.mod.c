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
	{ 0x69acdf38, "memcpy" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xfbaaf01e, "console_lock" },
	{ 0x6d228747, "fb_set_suspend" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xa3afc2c1, "vmbus_close" },
	{ 0xc631580a, "console_unlock" },
	{ 0x999e8297, "vfree" },
	{ 0xedc03953, "iounmap" },
	{ 0x31e2e77f, "vmbus_free_mmio" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x7ceeac9, "panic_notifier_list" },
	{ 0x7181db30, "atomic_notifier_chain_unregister" },
	{ 0x16cb454, "fb_deferred_io_cleanup" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xa01592eb, "framebuffer_release" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x2fd90375, "vmbus_sendpacket" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x77f9ae61, "vmbus_open" },
	{ 0x46a417ca, "vmbus_proto_version" },
	{ 0xd64660db, "vmbus_recvpacket" },
	{ 0xa6257a2f, "complete" },
	{ 0xa4fd2529, "framebuffer_alloc" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xab781570, "fb_get_options" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x1f1821ae, "efi" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x37b8b39e, "screen_info" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0xb9056bb6, "remove_conflicting_framebuffers" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x32294d1f, "fb_deferred_io_init" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xc9a35505, "vmbus_allocate_mmio" },
	{ 0x556422b3, "ioremap_cache" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x2b9997fb, "atomic_notifier_chain_register" },
	{ 0x8f4947c8, "__vmbus_driver_register" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xcaff6dc5, "vmbus_driver_unregister" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xc5f26a2b, "fb_deferred_io_mmap" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "hv_vmbus");

MODULE_ALIAS("vmbus:02780ada77e3ac4a8e770558eb1073f8");
MODULE_ALIAS("pci:v00001414d00005353sv00000000sd00000000bc*sc*i*");

MODULE_INFO(srcversion, "B13F7F5E716DF9A22EDB9F8");
