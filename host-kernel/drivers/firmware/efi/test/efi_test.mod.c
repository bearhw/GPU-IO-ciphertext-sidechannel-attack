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
	{ 0x91f4d6a1, "security_locked_down" },
	{ 0xc6cbbc89, "capable" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x1f1821ae, "efi" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x37a0cba, "kfree" },
	{ 0x6d334118, "__get_user_8" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4708008a, "misc_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x636a2492, "no_llseek" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "312326C56039D01CAECB789");
