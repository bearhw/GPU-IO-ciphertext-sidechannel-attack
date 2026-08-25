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
	{ 0x16ab5603, "edac_pci_release_generic_ctl" },
	{ 0xfe295174, "edac_mc_del_mc" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x2c39ca93, "edac_mc_free" },
	{ 0x92997ed8, "_printk" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x62f0e65e, "edac_mc_find_csrow_by_page" },
	{ 0x3c7181, "edac_mc_handle_error" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x7a537036, "edac_mc_alloc" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xe241560, "pci_scan_single_device" },
	{ 0xa6b3c164, "pci_dev_get" },
	{ 0xbfbb39b8, "edac_mc_add_mc_with_groups" },
	{ 0x12362d9f, "cpu_info" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x13813875, "edac_pci_create_generic_ctl" },
	{ 0x1e6d26a8, "strstr" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb51fbd64, "edac_op_state" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d00003590sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000359Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00003592sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000035B0sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "D804AE1F69298C2E0E9D000");
