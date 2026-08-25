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
	{ 0xdc7df67f, "apei_exec_ctx_init" },
	{ 0xb82ba28c, "single_open" },
	{ 0x77358855, "iomem_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0x556422b3, "ioremap_cache" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xedc03953, "iounmap" },
	{ 0x58f9366, "apei_exec_collect_resources" },
	{ 0x17614bf3, "apei_resources_sub" },
	{ 0xef1f6e23, "apei_resources_request" },
	{ 0x8e6fa8b5, "apei_exec_pre_map_gars" },
	{ 0xe13cb4d, "apei_resources_release" },
	{ 0x74457e56, "apei_resources_fini" },
	{ 0xbec66c3a, "__apei_exec_run" },
	{ 0xfe0e7cd3, "apei_exec_post_unmap_gars" },
	{ 0xb52e502, "apei_resources_add" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xf6a28554, "region_intersects" },
	{ 0x85efc7e0, "zero_pfn" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xdb1aaf9b, "arch_is_platform_page" },
	{ 0x1a45cb6c, "acpi_disabled" },
	{ 0x16cdc340, "acpi_get_table" },
	{ 0xcd8ce890, "acpi_format_exception" },
	{ 0xf010a88d, "apei_get_debugfs_dir" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x47b8942d, "debugfs_create_file_unsafe" },
	{ 0x603d0d51, "acpi_os_map_iomem" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x6b3ae022, "acpi_os_unmap_iomem" },
	{ 0xa5389eb1, "debugfs_create_x32" },
	{ 0xb38a7c5a, "debugfs_create_x64" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x7df03617, "debugfs_create_blob" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x92b99a33, "acpi_put_table" },
	{ 0x636a2492, "no_llseek" },
	{ 0x546b5d3f, "debugfs_attr_read" },
	{ 0x4f36eff0, "debugfs_attr_write" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xf2b11959, "seq_read" },
	{ 0xbb2b861a, "single_release" },
	{ 0x500c768c, "apei_exec_read_register" },
	{ 0x1cb7c983, "apei_exec_read_register_value" },
	{ 0x90c8498c, "apei_exec_write_register" },
	{ 0x574609c5, "apei_exec_write_register_value" },
	{ 0x12e730e, "apei_exec_noop" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0448C48FE96A0E0003B704F");
