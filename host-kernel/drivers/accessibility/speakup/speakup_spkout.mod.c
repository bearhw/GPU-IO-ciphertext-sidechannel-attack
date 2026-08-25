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
	{ 0xf9993d87, "synth_add" },
	{ 0x2ab6f6f9, "synth_remove" },
	{ 0x82f7ca44, "param_ops_short" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xeada697, "spk_ttyio_ops" },
	{ 0x19f17e10, "spk_ttyio_synth_probe" },
	{ 0x10492de0, "spk_ttyio_release" },
	{ 0x1ea2033a, "spk_ttyio_synth_immediate" },
	{ 0x1991dd20, "spk_do_catch_up" },
	{ 0xb5a3d79e, "spk_synth_is_alive_restart" },
	{ 0x1daf7a4, "spk_synth_get_index" },
	{ 0x810dd5c, "spk_var_show" },
	{ 0x47aba2b1, "spk_var_store" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "speakup");


MODULE_INFO(srcversion, "8D91970740116975062414E");
