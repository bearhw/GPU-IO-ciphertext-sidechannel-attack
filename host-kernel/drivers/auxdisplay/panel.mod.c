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
	{ 0x800473f, "__cond_resched" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x8b73974d, "parport_release" },
	{ 0x41e3ce24, "parport_unregister_device" },
	{ 0xf883c540, "charlcd_unregister" },
	{ 0x37a0cba, "kfree" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x92997ed8, "_printk" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x6d606913, "pv_ops" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x9917359, "charlcd_poke" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xd4c28eac, "parport_register_dev_model" },
	{ 0xe697454e, "parport_claim" },
	{ 0x79e8e259, "hd44780_common_alloc" },
	{ 0x8b45326c, "charlcd_alloc" },
	{ 0x6fd9cc4a, "charlcd_register" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x349cba85, "strchr" },
	{ 0x9166fada, "strncpy" },
	{ 0x4708008a, "misc_register" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x24d273d1, "add_timer" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xefbd5788, "__parport_register_driver" },
	{ 0x938e02c5, "parport_unregister_driver" },
	{ 0x23af578f, "default_llseek" },
	{ 0x36dc00a2, "hd44780_common_print" },
	{ 0x7b26ecc, "hd44780_common_gotoxy" },
	{ 0x3c4c183f, "hd44780_common_home" },
	{ 0x23159a5b, "hd44780_common_clear_display" },
	{ 0x8d4f3fa4, "hd44780_common_init_display" },
	{ 0xc369090d, "hd44780_common_shift_cursor" },
	{ 0x30e85287, "hd44780_common_shift_display" },
	{ 0x64415593, "hd44780_common_display" },
	{ 0xa22afdaa, "hd44780_common_cursor" },
	{ 0x8585e5fd, "hd44780_common_blink" },
	{ 0xf360d788, "hd44780_common_fontsize" },
	{ 0x1aa688fd, "hd44780_common_lines" },
	{ 0x489c89e8, "hd44780_common_redefine_char" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "parport,charlcd,hd44780_common");


MODULE_INFO(srcversion, "EC23ED7677C7571BA47B88D");
