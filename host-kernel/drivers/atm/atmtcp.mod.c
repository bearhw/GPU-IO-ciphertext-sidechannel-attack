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
	{ 0x37a0cba, "kfree" },
	{ 0x1b1cdbe1, "atm_dev_deregister" },
	{ 0x1de23e95, "module_put" },
	{ 0x86490580, "current_task" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbe888b32, "skb_put" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x1000e51, "schedule" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xbd505649, "consume_skb" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x99d368a7, "atm_dev_register" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x44c6e633, "vcc_sklist_lock" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x2cc2d52d, "vcc_hash" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xf0dba0fe, "atm_alloc_charge" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x92997ed8, "_printk" },
	{ 0xc6cbbc89, "capable" },
	{ 0x25e04082, "atm_dev_lookup" },
	{ 0x31cbdc32, "vcc_insert_socket" },
	{ 0x55045e31, "atm_init_aal5" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x3197c4e3, "put_device" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x59f209e, "register_atm_ioctl" },
	{ 0x67023607, "deregister_atm_ioctl" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");


MODULE_INFO(srcversion, "CC9AAB4E2C87C45379816DB");
