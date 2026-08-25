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

SYMBOL_CRC(dm_bufio_get, 0x24772bfe, "_gpl");
SYMBOL_CRC(dm_bufio_read, 0xb04f56ab, "_gpl");
SYMBOL_CRC(dm_bufio_new, 0xc0d7df85, "_gpl");
SYMBOL_CRC(dm_bufio_prefetch, 0xc90df7e5, "_gpl");
SYMBOL_CRC(dm_bufio_release, 0xe6024e59, "_gpl");
SYMBOL_CRC(dm_bufio_mark_partial_buffer_dirty, 0x111ab12a, "_gpl");
SYMBOL_CRC(dm_bufio_mark_buffer_dirty, 0x0ad0dc4f, "_gpl");
SYMBOL_CRC(dm_bufio_write_dirty_buffers_async, 0xc9a3422d, "_gpl");
SYMBOL_CRC(dm_bufio_write_dirty_buffers, 0xa82b2066, "_gpl");
SYMBOL_CRC(dm_bufio_issue_flush, 0xd4bddf5c, "_gpl");
SYMBOL_CRC(dm_bufio_issue_discard, 0x6aebce95, "_gpl");
SYMBOL_CRC(dm_bufio_release_move, 0xb2438d54, "_gpl");
SYMBOL_CRC(dm_bufio_forget, 0xcd2ba798, "_gpl");
SYMBOL_CRC(dm_bufio_forget_buffers, 0xf241a6eb, "_gpl");
SYMBOL_CRC(dm_bufio_set_minimum_buffers, 0x72f07bf4, "_gpl");
SYMBOL_CRC(dm_bufio_get_block_size, 0x7c381a76, "_gpl");
SYMBOL_CRC(dm_bufio_get_device_size, 0xd991e3b9, "_gpl");
SYMBOL_CRC(dm_bufio_get_dm_io_client, 0x867e87eb, "_gpl");
SYMBOL_CRC(dm_bufio_get_block_number, 0x2e0774dc, "_gpl");
SYMBOL_CRC(dm_bufio_get_block_data, 0xebcc64a4, "_gpl");
SYMBOL_CRC(dm_bufio_get_aux_data, 0x74dcd98c, "_gpl");
SYMBOL_CRC(dm_bufio_get_client, 0x6d3f57bd, "_gpl");
SYMBOL_CRC(dm_bufio_client_create, 0x3d86bedc, "_gpl");
SYMBOL_CRC(dm_bufio_client_destroy, 0xeca7949e, "_gpl");
SYMBOL_CRC(dm_bufio_set_sector_offset, 0xed3283a4, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa0fbac79, "wake_up_bit" },
	{ 0x84502a47, "blk_status_to_errno" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0xae04012c, "__vmalloc" },
	{ 0x86490580, "current_task" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x999e8297, "vfree" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x92997ed8, "_printk" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x93a6e0b2, "io_schedule" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd179edea, "bio_uninit" },
	{ 0x37a0cba, "kfree" },
	{ 0x2d8750e5, "dm_io" },
	{ 0x612bfd89, "errno_to_blk_status" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xecd23704, "bio_kmalloc" },
	{ 0xc005bb87, "bio_init" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0xa09dd780, "bio_put" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0x800473f, "__cond_resched" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x601f665f, "dm_io_client_create" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xeee3ef31, "register_shrinker" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x9e4faeef, "dm_io_client_destroy" },
	{ 0x58e3306d, "bit_wait_io" },
	{ 0xb3687850, "out_of_line_wait_on_bit_lock" },
	{ 0x1984d421, "out_of_line_wait_on_bit" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x231b2691, "unregister_shrinker" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x944375db, "_totalram_pages" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9180DE040125BD54DCF5859");
