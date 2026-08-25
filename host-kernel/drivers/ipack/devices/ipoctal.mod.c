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
	{ 0x848d372e, "iowrite8" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x409873e3, "tty_termios_baud_rate" },
	{ 0x5641485b, "tty_termios_encode_baud_rate" },
	{ 0x1de23e95, "module_put" },
	{ 0xad252699, "tty_port_close" },
	{ 0x2f3a6084, "tty_port_open" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x15bd91a4, "tty_standard_install" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x90641976, "tty_unregister_device" },
	{ 0x42a27157, "tty_port_free_xmit_buf" },
	{ 0x4352642a, "tty_port_destroy" },
	{ 0x34ac593f, "tty_unregister_driver" },
	{ 0x37a0cba, "kfree" },
	{ 0x2032b017, "tty_driver_kref_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xaa7322dc, "tty_port_hangup" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0xb1e8027, "__tty_alloc_driver" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x67b27ec1, "tty_std_termios" },
	{ 0xc783c290, "tty_register_driver" },
	{ 0x781a487c, "tty_port_init" },
	{ 0x1a3bb90b, "tty_port_alloc_xmit_buf" },
	{ 0x782020b, "tty_port_register_device_attr" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb19b445, "ioread8" },
	{ 0x4cf31c8, "__tty_insert_flip_char" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x9ed2b1f3, "tty_flip_buffer_push" },
	{ 0x94e254ac, "ipack_driver_register" },
	{ 0xed3a558f, "ipack_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ipack");

MODULE_ALIAS("ipack:f01v000000F0d00000022*");
MODULE_ALIAS("ipack:f01v000000F0d0000002A*");
MODULE_ALIAS("ipack:f01v000000F0d00000048*");

MODULE_INFO(srcversion, "D18D216A6665839B2344EFA");
