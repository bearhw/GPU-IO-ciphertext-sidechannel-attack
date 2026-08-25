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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0x92997ed8, "_printk" },
	{ 0x6e96a6ed, "usb_submit_urb" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x5a735d55, "usb_alloc_urb" },
	{ 0x60ab036c, "bchannel_get_rxbuf" },
	{ 0xbe888b32, "skb_put" },
	{ 0x69acdf38, "memcpy" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xbb3fc6f8, "recv_Dchannel" },
	{ 0x72c9f6b2, "recv_Bchannel" },
	{ 0x9987c730, "recv_Echannel" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbd505649, "consume_skb" },
	{ 0xfcb51bb5, "get_next_dframe" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xbb2bf4ae, "get_next_bframe" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x37a0cba, "kfree" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x588886a6, "l1_event" },
	{ 0xf294dd92, "dchannel_senddata" },
	{ 0x86f76de7, "queue_ch_frame" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd5a938fc, "mISDN_initdchannel" },
	{ 0x9ce1309f, "mISDN_initbchannel" },
	{ 0x222d708e, "mISDN_freebchannel" },
	{ 0xb6e0a005, "mISDN_freedchannel" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0xa9f4fd3b, "usb_set_interface" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5339c64, "mISDN_register_device" },
	{ 0x5021bd81, "_raw_write_lock_irqsave" },
	{ 0xeb078aee, "_raw_write_unlock_irqrestore" },
	{ 0xd822b137, "mISDN_unregister_device" },
	{ 0x5f0fb884, "usb_kill_urb" },
	{ 0x1ad22551, "usb_free_urb" },
	{ 0xd057a352, "mISDN_clear_bchannel" },
	{ 0x1de23e95, "module_put" },
	{ 0x84052933, "mISDN_ctrl_bchannel" },
	{ 0x6d2e16a4, "bchannel_senddata" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x71b337ed, "create_l1" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0x821e463, "usb_deregister" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mISDN_core");

MODULE_ALIAS("usb:v0959p2BD0d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0675p1688d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B0p0007d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0742p2008d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0742p2009d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0742p200Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v08E3p0301d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07FAp0846d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07FAp0847d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B0p0006d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v071Dp1005d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0586p0102d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1AE7p0525d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "F561A606C6C7989BF50066D");
