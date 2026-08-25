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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x86490580, "current_task" },
	{ 0xc6a06d16, "spk_get_var" },
	{ 0xd93829dd, "speakup_info" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x76d40046, "synth_buffer_skip_nonlatin1" },
	{ 0x41a160e5, "synth_buffer_empty" },
	{ 0xaadb0612, "synth_buffer_peek" },
	{ 0x84dad068, "synth_buffer_getc" },
	{ 0x349cba85, "strchr" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xf9993d87, "synth_add" },
	{ 0x2ab6f6f9, "synth_remove" },
	{ 0x82f7ca44, "param_ops_short" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xeada697, "spk_ttyio_ops" },
	{ 0x19f17e10, "spk_ttyio_synth_probe" },
	{ 0x10492de0, "spk_ttyio_release" },
	{ 0x1ea2033a, "spk_ttyio_synth_immediate" },
	{ 0xb5a3d79e, "spk_synth_is_alive_restart" },
	{ 0x810dd5c, "spk_var_show" },
	{ 0x47aba2b1, "spk_var_store" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "speakup");


MODULE_INFO(srcversion, "7CFF9FBAF131A9EF073760D");
