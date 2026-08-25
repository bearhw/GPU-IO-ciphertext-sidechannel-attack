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

SYMBOL_CRC(vmlfb_register_subsys, 0x90c018c6, "_gpl");
SYMBOL_CRC(vmlfb_unregister_subsys, 0x016e6c20, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x18734460, "cfb_copyarea" },
	{ 0x6612cb1, "vm_iomap_memory" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xd7afc0f, "set_pages_uc" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xedc03953, "iounmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xa4bd5528, "fb_set_var" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc2bb8c22, "set_pages_wb" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xae65c72, "fb_find_mode" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x98b71c6, "fb_dealloc_cmap" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xde80cd09, "ioremap" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xf9b2f2b8, "cfb_imageblit" },
	{ 0xfb578fc5, "memset" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x616f37dd, "cfb_fillrect" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0x77358855, "iomem_resource" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x85bd1608, "__request_region" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FF575D6DFC804FF0A691CE2");
