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
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x37a0cba, "kfree" },
	{ 0x92997ed8, "_printk" },
	{ 0x5a921311, "strncmp" },
	{ 0xc8f2543, "fw_run_transaction" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x5a207c8d, "transport_generic_free_cmd" },
	{ 0x11089ac7, "_ctype" },
	{ 0xbe564b91, "fw_send_response" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd4c14632, "system_unbound_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xbc6094c, "fw_core_remove_descriptor" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3a771e39, "fw_core_add_descriptor" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe86fb5c7, "fw_card_release" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xcf62688d, "target_remove_session" },
	{ 0x36eadb73, "fw_core_remove_address_handler" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa1939e45, "fw_core_add_address_handler" },
	{ 0x3464c940, "core_tpg_register" },
	{ 0x590775d8, "core_tpg_deregister" },
	{ 0x5a42c937, "sbitmap_queue_clear" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3d4912de, "target_setup_session" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x4ed847b6, "target_put_sess_cmd" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x3288b93b, "__sbitmap_queue_get" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x334da4e, "scsi_command_size_tbl" },
	{ 0x320237e3, "target_submit_cmd" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0x9db2f5e1, "target_execute_cmd" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2885fec5, "fw_get_request_speed" },
	{ 0xd2719129, "target_register_template" },
	{ 0x5085599b, "target_unregister_template" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "firewire-core,target_core_mod");


MODULE_INFO(srcversion, "699686DFC5B9B0B667EA5F3");
