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
	{ 0xd93829dd, "speakup_info" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x92997ed8, "_printk" },
	{ 0xbbd15a51, "speakup_start_ttys" },
	{ 0xf7d31de9, "kstrtoul_from_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4708008a, "misc_register" },
	{ 0xb734cb9d, "speakup_event" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa0d7b21e, "synth_current" },
	{ 0x41a160e5, "synth_buffer_empty" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x86490580, "current_task" },
	{ 0x1000e51, "schedule" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x96848186, "scnprintf" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x76d40046, "synth_buffer_skip_nonlatin1" },
	{ 0x84dad068, "synth_buffer_getc" },
	{ 0xf9993d87, "synth_add" },
	{ 0x2ab6f6f9, "synth_remove" },
	{ 0x82f7ca44, "param_ops_short" },
	{ 0x810dd5c, "spk_var_show" },
	{ 0x47aba2b1, "spk_var_store" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "speakup");


MODULE_INFO(srcversion, "AEAF3ADD2A15509C769A919");
