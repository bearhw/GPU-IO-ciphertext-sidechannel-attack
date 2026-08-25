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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xde80cd09, "ioremap" },
	{ 0xedc03953, "iounmap" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x5b0ce8b8, "pci_bus_read_config_byte" },
	{ 0x49256a0f, "pci_bus_read_config_word" },
	{ 0xd28f6604, "pci_bus_write_config_dword" },
	{ 0xd0ff9662, "pci_bus_write_config_word" },
	{ 0xf5be2122, "pci_bus_read_config_dword" },
	{ 0x66945c8, "pci_bus_write_config_byte" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x3c7181, "edac_mc_handle_error" },
	{ 0x5ab09745, "edac_get_owner" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0xb51fbd64, "edac_op_state" },
	{ 0x2d4784f6, "pci_find_bus" },
	{ 0x7a537036, "edac_mc_alloc" },
	{ 0xbfbb39b8, "edac_mc_add_mc_with_groups" },
	{ 0x2c39ca93, "edac_mc_free" },
	{ 0xb8b2b1f7, "mce_register_decode_chain" },
	{ 0xf2d7d87, "mce_unregister_decode_chain" },
	{ 0xfe295174, "edac_mc_del_mc" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod005C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod005F:feature:*");

MODULE_INFO(srcversion, "92DED71D08B20EBE5C6450A");
