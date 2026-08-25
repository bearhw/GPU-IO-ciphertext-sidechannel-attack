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

SYMBOL_CRC(pccard_static_ops, 0x461a36c4, "");
SYMBOL_CRC(pccard_nonstatic_ops, 0xd653a169, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x13110126, "request_resource" },
	{ 0x5c1f9988, "pci_find_parent_resource" },
	{ 0xedc03953, "iounmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x90c9f554, "class_interface_unregister" },
	{ 0xde80cd09, "ioremap" },
	{ 0xd9a9d63d, "class_interface_register" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0xd68c5a1f, "adjust_resource" },
	{ 0xf3e0e1df, "allocate_resource" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xbdde6953, "pci_bus_alloc_resource" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb9d10973, "pcmcia_socket_class" },
	{ 0xc5e74216, "release_resource" },
	{ 0x77358855, "iomem_resource" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcmcia_core");


MODULE_INFO(srcversion, "56E8DD42E9102CE9439CF81");
