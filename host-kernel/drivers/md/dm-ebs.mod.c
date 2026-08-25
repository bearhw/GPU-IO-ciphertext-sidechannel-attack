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
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0xc90df7e5, "dm_bufio_prefetch" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb04f56ab, "dm_bufio_read" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xeca7949e, "dm_bufio_client_destroy" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x3d86bedc, "dm_bufio_client_create" },
	{ 0xe6024e59, "dm_bufio_release" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x612bfd89, "errno_to_blk_status" },
	{ 0x7c381a76, "dm_bufio_get_block_size" },
	{ 0x111ab12a, "dm_bufio_mark_partial_buffer_dirty" },
	{ 0xaeca8967, "blk_limits_io_min" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa82b2066, "dm_bufio_write_dirty_buffers" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xf241a6eb, "dm_bufio_forget_buffers" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0xc0d7df85, "dm_bufio_new" },
	{ 0x6aebce95, "dm_bufio_issue_discard" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dm-bufio");


MODULE_INFO(srcversion, "8BCEADD54517ABC74F1F81B");
