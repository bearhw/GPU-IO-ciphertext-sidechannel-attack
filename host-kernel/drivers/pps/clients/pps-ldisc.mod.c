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
	{ 0xf597132c, "pps_lookup_dev" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2587f789, "_dev_info" },
	{ 0x6450e28b, "pps_unregister_source" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x4af699f6, "pps_register_source" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4cb27100, "ktime_get_snapshot" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0x48bb1255, "pps_event" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x968606ca, "n_tty_inherit_ops" },
	{ 0x9f63718c, "tty_register_ldisc" },
	{ 0x264c5f6c, "tty_unregister_ldisc" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A003259A9943374857B5865");
