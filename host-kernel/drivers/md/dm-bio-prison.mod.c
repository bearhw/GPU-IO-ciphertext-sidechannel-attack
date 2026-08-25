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

SYMBOL_CRC(dm_bio_prison_create, 0x753e20b2, "_gpl");
SYMBOL_CRC(dm_bio_prison_destroy, 0xb70b342a, "_gpl");
SYMBOL_CRC(dm_bio_prison_alloc_cell, 0x40e5d1e0, "_gpl");
SYMBOL_CRC(dm_bio_prison_free_cell, 0x0df0fb40, "_gpl");
SYMBOL_CRC(dm_bio_detain, 0xf9873ff6, "_gpl");
SYMBOL_CRC(dm_get_cell, 0x1f49be93, "_gpl");
SYMBOL_CRC(dm_cell_release, 0x2b442b4d, "_gpl");
SYMBOL_CRC(dm_cell_release_no_holder, 0xacb4525b, "_gpl");
SYMBOL_CRC(dm_cell_error, 0x4cda7b08, "_gpl");
SYMBOL_CRC(dm_cell_visit_release, 0x67b4beed, "_gpl");
SYMBOL_CRC(dm_cell_promote_or_release, 0x9c0961ee, "_gpl");
SYMBOL_CRC(dm_deferred_set_create, 0x17dd39d6, "_gpl");
SYMBOL_CRC(dm_deferred_set_destroy, 0x2eb01e04, "_gpl");
SYMBOL_CRC(dm_deferred_entry_inc, 0xca2e3a88, "_gpl");
SYMBOL_CRC(dm_deferred_entry_dec, 0x6791a44e, "_gpl");
SYMBOL_CRC(dm_deferred_set_add_work, 0xb6d5c65d, "_gpl");
SYMBOL_CRC(dm_bio_prison_create_v2, 0xd99e003d, "_gpl");
SYMBOL_CRC(dm_bio_prison_destroy_v2, 0xace9b57b, "_gpl");
SYMBOL_CRC(dm_bio_prison_alloc_cell_v2, 0x19ee7502, "_gpl");
SYMBOL_CRC(dm_bio_prison_free_cell_v2, 0x6cf28ef1, "_gpl");
SYMBOL_CRC(dm_cell_get_v2, 0xf651305f, "_gpl");
SYMBOL_CRC(dm_cell_put_v2, 0x61a6fe0f, "_gpl");
SYMBOL_CRC(dm_cell_lock_v2, 0x6d7c8349, "_gpl");
SYMBOL_CRC(dm_cell_quiesce_v2, 0x4a914868, "_gpl");
SYMBOL_CRC(dm_cell_lock_promote_v2, 0xf71b1e21, "_gpl");
SYMBOL_CRC(dm_cell_unlock_v2, 0x45700556, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x15c85de3, "mempool_init" },
	{ 0x37a0cba, "kfree" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xc972449f, "mempool_alloc_slab" },
	{ 0x6d606913, "pv_ops" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x38e46431, "mempool_exit" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8C2D044E210E19C3D6C3870");
