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
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xaeca8967, "blk_limits_io_min" },
	{ 0x1bb67920, "blk_limits_io_opt" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0x61b09da7, "md_reap_sync_thread" },
	{ 0x22c71c1, "md_wakeup_thread" },
	{ 0x4dcfbebd, "sync_page_io" },
	{ 0x92997ed8, "_printk" },
	{ 0x8eb7efa2, "md_error" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xfb578fc5, "memset" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x342ca964, "mddev_suspend" },
	{ 0x4fd1913c, "mddev_unlock" },
	{ 0xcf8a50ba, "md_stop_writes" },
	{ 0x8ec5f72, "md_handle_request" },
	{ 0x8b00646a, "md_rdev_clear" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x5092f3bc, "md_stop" },
	{ 0x50b2239f, "mddev_resume" },
	{ 0xb1b06a8f, "dm_table_get_md" },
	{ 0x6a8ad92a, "dm_disk" },
	{ 0x2287440d, "set_capacity_and_notify" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2bf609c5, "dm_table_event" },
	{ 0x935bae2a, "md_bitmap_resize" },
	{ 0xc24ac022, "md_update_sb" },
	{ 0x48f7eef0, "md_bitmap_load" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x96848186, "scnprintf" },
	{ 0x5eb24829, "dm_shift_arg" },
	{ 0xc7d094b5, "dm_read_arg_group" },
	{ 0x7deff673, "dm_consume_args" },
	{ 0x11e0ec41, "dm_read_arg" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x5372c10c, "mddev_init" },
	{ 0x5343cb19, "md_rdev_init" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x466793e6, "dm_set_target_max_io_len" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x754ef488, "md_run" },
	{ 0x81b14586, "md_start" },
	{ 0x701d492f, "r5c_journal_mode_set" },
	{ 0x993a804d, "raid5_set_cache_size" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "raid456");


MODULE_INFO(srcversion, "FE6F2BDA064D4F997FAF45A");
