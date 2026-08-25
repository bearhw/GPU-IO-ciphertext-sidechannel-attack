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
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3f7b09fb, "kset_unregister" },
	{ 0x37a0cba, "kfree" },
	{ 0xedc03953, "iounmap" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xfc39e32f, "ioport_unmap" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc9f34c1d, "acpi_acquire_global_lock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0xb19b445, "ioread8" },
	{ 0xfbab1bb1, "ioread8_rep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa805ecfc, "acpi_release_global_lock" },
	{ 0x26f8f0b8, "iowrite16be" },
	{ 0x56470118, "__warn_printk" },
	{ 0xfb578fc5, "memset" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x6b980b08, "kobject_del" },
	{ 0x7c181721, "kobject_put" },
	{ 0xdca09c91, "sysfs_remove_file_ns" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xeaf730c2, "kobject_create_and_add" },
	{ 0x7233a2e6, "kset_create_and_add" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0x594bf15b, "ioport_map" },
	{ 0xd7d18c4, "platform_get_resource_byname" },
	{ 0x63799c0f, "sysfs_create_file_ns" },
	{ 0xde80cd09, "ioremap" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xb26a1add, "elfcorehdr_addr" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa916b694, "strnlen" },
	{ 0xdd64e639, "strscpy" },
	{ 0xc392bf7, "kobject_init_and_add" },
	{ 0xd5d074ec, "sysfs_create_bin_file" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x85df9b6c, "strsep" },
	{ 0xcb81d5e8, "kset_find_obj" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x95352ea6, "kobject_set_name" },
	{ 0xe8eb5b88, "kset_register" },
	{ 0x1bf55fc, "paddr_vmcoreinfo_note" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xe419bc99, "iowrite32be" },
	{ 0x92997ed8, "_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x6afcc4fa, "firmware_kobj" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:QEMU0002:*");
MODULE_ALIAS("of:N*T*Cqemu,fw-cfg-mmio");
MODULE_ALIAS("of:N*T*Cqemu,fw-cfg-mmioC*");

MODULE_INFO(srcversion, "7DDBECACB6D3621D7D39DD4");
