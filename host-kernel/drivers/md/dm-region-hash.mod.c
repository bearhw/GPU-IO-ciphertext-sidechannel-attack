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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(dm_rh_region_to_sector, 0x38972f23, "_gpl");
SYMBOL_CRC(dm_rh_bio_to_region, 0x7259b774, "_gpl");
SYMBOL_CRC(dm_rh_region_context, 0xd8aa4284, "_gpl");
SYMBOL_CRC(dm_rh_get_region_key, 0x7d5e1815, "_gpl");
SYMBOL_CRC(dm_rh_get_region_size, 0xf92b8a3d, "_gpl");
SYMBOL_CRC(dm_region_hash_create, 0xe5a35bb0, "_gpl");
SYMBOL_CRC(dm_region_hash_destroy, 0x38efaf5a, "_gpl");
SYMBOL_CRC(dm_rh_dirty_log, 0x104be7f5, "_gpl");
SYMBOL_CRC(dm_rh_get_state, 0x57e16c3e, "_gpl");
SYMBOL_CRC(dm_rh_mark_nosync, 0xef54fbbd, "_gpl");
SYMBOL_CRC(dm_rh_update_states, 0x3a18389a, "_gpl");
SYMBOL_CRC(dm_rh_inc_pending, 0x45af8ade, "_gpl");
SYMBOL_CRC(dm_rh_dec, 0x5f4a6e61, "_gpl");
SYMBOL_CRC(dm_rh_recovery_prepare, 0xbe38a431, "_gpl");
SYMBOL_CRC(dm_rh_recovery_start, 0x01d2f9ac, "_gpl");
SYMBOL_CRC(dm_rh_recovery_end, 0xa83588eb, "_gpl");
SYMBOL_CRC(dm_rh_recovery_in_flight, 0xfd93482e, "_gpl");
SYMBOL_CRC(dm_rh_flush, 0xa53387c7, "_gpl");
SYMBOL_CRC(dm_rh_delay, 0x5ff783bf, "_gpl");
SYMBOL_CRC(dm_rh_stop_recovery, 0x7774620f, "_gpl");
SYMBOL_CRC(dm_rh_start_recovery, 0x7d053fc5, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xcf2a6966, "up" },
	{ 0x6626afca, "down" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x2fd31db6, "dm_dirty_log_destroy" },
	{ 0x38e46431, "mempool_exit" },
	{ 0x999e8297, "vfree" },
	{ 0x37a0cba, "kfree" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x6a037cf1, "mempool_kfree" },
	{ 0xd35a6d31, "mempool_kmalloc" },
	{ 0x15c85de3, "mempool_init" },
	{ 0x92997ed8, "_printk" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x3aca0190, "_raw_write_lock_irq" },
	{ 0x6d606913, "pv_ops" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xe9ffc063, "down_trylock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dm-log");


MODULE_INFO(srcversion, "372EA7B955B30888C2CCE52");
