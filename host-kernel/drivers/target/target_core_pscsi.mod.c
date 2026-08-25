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
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x6cab4b6b, "target_complete_cmd" },
	{ 0x1d2915ac, "blk_mq_free_request" },
	{ 0x5fe9aab5, "transport_copy_sense_to_cmd" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x1dd8eda9, "target_complete_cmd_with_length" },
	{ 0x8c7184ab, "target_lun_is_rdonly" },
	{ 0x717b0c2b, "transport_kmap_data_sg" },
	{ 0xb76c87df, "transport_kunmap_data_sg" },
	{ 0x92997ed8, "_printk" },
	{ 0xd179edea, "bio_uninit" },
	{ 0x37a0cba, "kfree" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x85df9b6c, "strsep" },
	{ 0x44e9a829, "match_token" },
	{ 0x4e3567f7, "match_int" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x6ec3e817, "scsi_host_put" },
	{ 0x12e047bb, "scsi_device_put" },
	{ 0x6bce7da8, "blkdev_put" },
	{ 0x6cfbb5af, "scsi_host_lookup" },
	{ 0xe189049a, "passthrough_parse_cdb" },
	{ 0x39f970ff, "scsi_alloc_request" },
	{ 0xcf30c2cf, "bio_add_pc_page" },
	{ 0x4abb121f, "blk_rq_append_bio" },
	{ 0xecd23704, "bio_kmalloc" },
	{ 0xc005bb87, "bio_init" },
	{ 0x334da4e, "scsi_command_size_tbl" },
	{ 0x87b8798d, "sg_next" },
	{ 0xa26854e7, "blk_execute_rq_nowait" },
	{ 0xa09dd780, "bio_put" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xb91a5868, "__scsi_execute" },
	{ 0x871ffd6, "transport_set_vpd_ident" },
	{ 0xf3c2dfe0, "transport_set_vpd_proto_id" },
	{ 0x142072c0, "transport_set_vpd_assoc" },
	{ 0x3a20a9d7, "transport_set_vpd_ident_type" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xbc137caa, "scsi_device_get" },
	{ 0x28aee912, "blkdev_get_by_path" },
	{ 0x72ea7b2d, "scsi_device_type" },
	{ 0xec722f37, "transport_backend_register" },
	{ 0xded62f97, "target_backend_unregister" },
	{ 0x3aed5964, "passthrough_attrib_attrs" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "target_core_mod");


MODULE_INFO(srcversion, "BDADD4E89477E2475FD25B3");
