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

SYMBOL_CRC(nvmf_get_address, 0x9fdbb040, "_gpl");
SYMBOL_CRC(nvmf_reg_read32, 0x31ec5018, "_gpl");
SYMBOL_CRC(nvmf_reg_read64, 0x343d800b, "_gpl");
SYMBOL_CRC(nvmf_reg_write32, 0xd8d91733, "_gpl");
SYMBOL_CRC(nvmf_connect_admin_queue, 0x4b61711b, "_gpl");
SYMBOL_CRC(nvmf_connect_io_queue, 0xa789c0b1, "_gpl");
SYMBOL_CRC(nvmf_should_reconnect, 0x545760bd, "_gpl");
SYMBOL_CRC(nvmf_register_transport, 0x52bee7f2, "_gpl");
SYMBOL_CRC(nvmf_unregister_transport, 0xecf89816, "_gpl");
SYMBOL_CRC(nvmf_ip_options_match, 0x130312a4, "_gpl");
SYMBOL_CRC(nvmf_free_options, 0x51c659eb, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x1a8bd555, "try_module_get" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0xb905e0f7, "__class_create" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x96848186, "scnprintf" },
	{ 0x37a0cba, "kfree" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x69e683de, "uuid_gen" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xce807a25, "up_write" },
	{ 0x4e3567f7, "match_int" },
	{ 0x1f1f589c, "device_create" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x9166fada, "strncpy" },
	{ 0xfc5c306e, "__nvme_submit_sync_cmd" },
	{ 0x4708008a, "misc_register" },
	{ 0xb67fec0e, "uuid_parse" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0xf2b11959, "seq_read" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x1d07e365, "memdup_user_nul" },
	{ 0x44e9a829, "match_token" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xacf4d843, "match_strdup" },
	{ 0x391de184, "seq_puts" },
	{ 0xbb2b861a, "single_release" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xb82ba28c, "single_open" },
	{ 0x53b954a2, "up_read" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nvme-core");


MODULE_INFO(srcversion, "BAD297EDB4531C96E9E85F3");
