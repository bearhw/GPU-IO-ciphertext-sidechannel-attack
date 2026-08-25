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
	{ 0x7c2d02cc, "mbox_chan_txdone" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x1d835796, "mbox_chan_received_data" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x50b74a29, "devm_mbox_controller_register" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Caltr,mailbox-1.0");
MODULE_ALIAS("of:N*T*Caltr,mailbox-1.0C*");

MODULE_INFO(srcversion, "7518FC6EA8BEF0CC18AC212");
