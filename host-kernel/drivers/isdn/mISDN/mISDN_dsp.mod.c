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

SYMBOL_CRC(dsp_audio_law_to_s32, 0x93df9e4b, "");
SYMBOL_CRC(dsp_audio_s16_to_law, 0xb07a21b8, "");
SYMBOL_CRC(mISDN_dsp_element_register, 0xb98308d8, "");
SYMBOL_CRC(mISDN_dsp_element_unregister, 0x01087af0, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x1a8bd555, "try_module_get" },
	{ 0xb905e0f7, "__class_create" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xbe888b32, "skb_put" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xbd505649, "consume_skb" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5f00e12, "mISDN_register_Bprotocol" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2121e851, "device_create_file" },
	{ 0x78041b8f, "byte_rev_table" },
	{ 0x24d273d1, "add_timer" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x422066d2, "device_register" },
	{ 0xd285995f, "mISDN_clock_get" },
	{ 0xfb578fc5, "memset" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x999e8297, "vfree" },
	{ 0x85df9b6c, "strsep" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x754d539c, "strlen" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x733f357e, "mISDN_unregister_Bprotocol" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mISDN_core");


MODULE_INFO(srcversion, "91E06C0E1BC45EEC2907BBA");
