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
	{ 0x84d5b86a, "filp_close" },
	{ 0xfb578fc5, "memset" },
	{ 0xdd6a20bc, "kernel_write" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x999e8297, "vfree" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x751e692e, "filp_open" },
	{ 0x14fa2140, "sbc_parse_cdb" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x13d4a8af, "I_BDEV" },
	{ 0x7f70af7a, "target_to_linux_sector" },
	{ 0xe3a87077, "blkdev_issue_discard" },
	{ 0x6cab4b6b, "target_complete_cmd" },
	{ 0x37a0cba, "kfree" },
	{ 0x44a21f8e, "vfs_fsync_range" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x85df9b6c, "strsep" },
	{ 0x44e9a829, "match_token" },
	{ 0xacf4d843, "match_strdup" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x4e3567f7, "match_int" },
	{ 0x3539f11b, "match_strlcpy" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xa42e29af, "target_configure_unmap_from_queue" },
	{ 0xa668688f, "sbc_get_write_same_sectors" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd9aa2171, "iov_iter_bvec" },
	{ 0x4838be6d, "vfs_iter_write" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x87b8798d, "sg_next" },
	{ 0x441920fc, "vfs_iter_read" },
	{ 0xd27d7c99, "iov_iter_zero" },
	{ 0x9d3ab428, "sbc_dif_verify" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xec722f37, "transport_backend_register" },
	{ 0xded62f97, "target_backend_unregister" },
	{ 0xf7dcd754, "sbc_get_device_type" },
	{ 0x58dfdea7, "sbc_attrib_attrs" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "target_core_mod");


MODULE_INFO(srcversion, "26ECDDFA2525D2C95FAC65F");
