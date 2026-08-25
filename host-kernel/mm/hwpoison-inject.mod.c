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
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0xc6cbbc89, "capable" },
	{ 0xb907513f, "unpoison_memory" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xa94a09bb, "mem_section" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xcc9268fc, "hwpoison_filter_enable" },
	{ 0x80f48c4f, "shake_page" },
	{ 0x6701489e, "PageHuge" },
	{ 0x378215ec, "is_free_buddy_page" },
	{ 0x9cc3fe44, "hwpoison_filter" },
	{ 0x92997ed8, "_printk" },
	{ 0x7918d817, "memory_failure" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xd713878c, "debugfs_create_u32" },
	{ 0x8d7e3373, "hwpoison_filter_dev_major" },
	{ 0x326cefe5, "hwpoison_filter_dev_minor" },
	{ 0x15ea2648, "hwpoison_filter_flags_mask" },
	{ 0xc1a16567, "debugfs_create_u64" },
	{ 0x6ba36c6a, "hwpoison_filter_flags_value" },
	{ 0x2176e42a, "hwpoison_filter_memcg" },
	{ 0x636a2492, "no_llseek" },
	{ 0x546b5d3f, "debugfs_attr_read" },
	{ 0x4f36eff0, "debugfs_attr_write" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A6EDB26D049F5ED40B206B3");
