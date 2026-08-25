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
	{ 0x1ad22551, "usb_free_urb" },
	{ 0x37a0cba, "kfree" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x6d606913, "pv_ops" },
	{ 0x5f0fb884, "usb_kill_urb" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x88896213, "usb_unlink_urb" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x6e96a6ed, "usb_submit_urb" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x653dd51c, "usb_control_msg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0x5a735d55, "usb_alloc_urb" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xc97b2d74, "usb_register_driver" },
	{ 0x821e463, "usb_deregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("usb:v0A12p5D10d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "DA36753D3BC37A8421C3DC1");
