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

SYMBOL_CRC(vringh_kiov_advance, 0x660779c8, "");
SYMBOL_CRC(vringh_init_user, 0xf1e32cc0, "");
SYMBOL_CRC(vringh_getdesc_user, 0x5bd469c0, "");
SYMBOL_CRC(vringh_iov_pull_user, 0x4311cd91, "");
SYMBOL_CRC(vringh_iov_push_user, 0x3b304ebb, "");
SYMBOL_CRC(vringh_abandon_user, 0xf9d0dd07, "");
SYMBOL_CRC(vringh_complete_user, 0x9b30452e, "");
SYMBOL_CRC(vringh_complete_multi_user, 0x90e93e3c, "");
SYMBOL_CRC(vringh_notify_enable_user, 0xf8605294, "");
SYMBOL_CRC(vringh_notify_disable_user, 0xa7ce8bd6, "");
SYMBOL_CRC(vringh_need_notify_user, 0x6a693a25, "");
SYMBOL_CRC(vringh_init_kern, 0x5f586ca2, "");
SYMBOL_CRC(vringh_getdesc_kern, 0x2890c460, "");
SYMBOL_CRC(vringh_iov_pull_kern, 0xde804bb9, "");
SYMBOL_CRC(vringh_iov_push_kern, 0x97fa07e9, "");
SYMBOL_CRC(vringh_abandon_kern, 0x1fe50c1a, "");
SYMBOL_CRC(vringh_complete_kern, 0x2d2babc9, "");
SYMBOL_CRC(vringh_notify_enable_kern, 0xeb2ec139, "");
SYMBOL_CRC(vringh_notify_disable_kern, 0x19c24590, "");
SYMBOL_CRC(vringh_need_notify_kern, 0xd465f463, "");
SYMBOL_CRC(vringh_init_iotlb, 0x3ee1955e, "");
SYMBOL_CRC(vringh_set_iotlb, 0xa8efaeb9, "");
SYMBOL_CRC(vringh_getdesc_iotlb, 0x61e3831b, "");
SYMBOL_CRC(vringh_iov_pull_iotlb, 0x0c46f5fb, "");
SYMBOL_CRC(vringh_iov_push_iotlb, 0x18f3ddc2, "");
SYMBOL_CRC(vringh_abandon_iotlb, 0x4504adc9, "");
SYMBOL_CRC(vringh_complete_iotlb, 0x3684d8af, "");
SYMBOL_CRC(vringh_notify_enable_iotlb, 0xc87491c8, "");
SYMBOL_CRC(vringh_notify_disable_iotlb, 0xe4c21196, "");
SYMBOL_CRC(vringh_need_notify_iotlb, 0xc0bb1581, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x715a5ed0, "vprintk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x69acdf38, "memcpy" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x69e872f9, "vhost_iotlb_itree_first" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x6d606913, "pv_ops" },
	{ 0xd9aa2171, "iov_iter_bvec" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x86490580, "current_task" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vhost_iotlb");


MODULE_INFO(srcversion, "A765BACFEC1BFEB7574475B");
