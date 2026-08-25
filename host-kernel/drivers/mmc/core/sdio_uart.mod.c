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
	{ 0xaa6878ed, "tty_port_put" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x56435244, "sdio_readb" },
	{ 0xaa7322dc, "tty_port_hangup" },
	{ 0xad252699, "tty_port_close" },
	{ 0x2f3a6084, "tty_port_open" },
	{ 0x799a6ff5, "sdio_writeb" },
	{ 0xf72a65ea, "tty_get_char_size" },
	{ 0x409873e3, "tty_termios_baud_rate" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2744ebe2, "sdio_claim_host" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa0935d, "tty_port_tty_hangup" },
	{ 0xcc235fcb, "sdio_release_irq" },
	{ 0x347d72ae, "sdio_disable_func" },
	{ 0x71009614, "sdio_release_host" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x90641976, "tty_unregister_device" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x781a487c, "tty_port_init" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xb49ce922, "tty_port_register_device" },
	{ 0x92997ed8, "_printk" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xa906274e, "seq_putc" },
	{ 0xc6cbbc89, "capable" },
	{ 0x15bd91a4, "tty_standard_install" },
	{ 0x86490580, "current_task" },
	{ 0xcd420564, "tty_port_tty_get" },
	{ 0x1e91687d, "tty_kref_put" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x13d0adf7, "__kfifo_out" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xa8d968d, "tty_wakeup" },
	{ 0x4cf31c8, "__tty_insert_flip_char" },
	{ 0x9ed2b1f3, "tty_flip_buffer_push" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x999802b0, "sdio_enable_func" },
	{ 0xf005e2c4, "sdio_claim_irq" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0xb1e8027, "__tty_alloc_driver" },
	{ 0x67b27ec1, "tty_std_termios" },
	{ 0xc783c290, "tty_register_driver" },
	{ 0xac9e7a61, "sdio_register_driver" },
	{ 0x34ac593f, "tty_unregister_driver" },
	{ 0x2032b017, "tty_driver_kref_put" },
	{ 0xbb2949db, "sdio_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("sdio:c01v*d*");
MODULE_ALIAS("sdio:c04v*d*");

MODULE_INFO(srcversion, "0EB1C93E5C25F3CE502CFB8");
