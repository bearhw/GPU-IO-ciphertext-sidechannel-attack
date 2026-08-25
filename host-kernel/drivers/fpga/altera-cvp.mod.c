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
	{ 0x124bad4d, "kstrtobool" },
	{ 0x1a8d8c2, "fpga_mgr_unregister" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xf34989c, "pci_release_region" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x369301b6, "pci_find_next_ext_capability" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x7cb8cb5f, "pci_request_region" },
	{ 0xae121354, "pci_iomap" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xd772282b, "fpga_mgr_register" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xf19f134f, "driver_create_file" },
	{ 0x92997ed8, "_printk" },
	{ 0x7bdff18e, "driver_remove_file" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fpga-mgr");

MODULE_ALIAS("pci:v00001172d*sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "CD261B6DAAFED703310F11A");
