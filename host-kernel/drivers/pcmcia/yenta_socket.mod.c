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
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x65162719, "pci_get_slot" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x70d1ef80, "pci_bus_resource_n" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3da171f9, "pci_mem_start" },
	{ 0xf3e0e1df, "allocate_resource" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa8304678, "pcibios_bus_to_resource" },
	{ 0x7b89c8b9, "pci_claim_resource" },
	{ 0x2587f789, "_dev_info" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xfd0bbb57, "pci_match_id" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x45c00a5, "pcmcia_unregister_socket" },
	{ 0xedc03953, "iounmap" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x37a0cba, "kfree" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc5e74216, "release_resource" },
	{ 0x93cdae47, "pcmcia_parse_events" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x24d273d1, "add_timer" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0xb121390a, "probe_irq_on" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x360b1afe, "probe_irq_mask" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd653a169, "pccard_nonstatic_ops" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xde80cd09, "ioremap" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xf82d3dd4, "pcibios_resource_to_bus" },
	{ 0x56e7371e, "pci_setup_cardbus" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x9d08e002, "pcmcia_register_socket" },
	{ 0x2121e851, "device_create_file" },
	{ 0xcf97f3bd, "dead_socket" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x5daa032f, "param_ops_string" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcmcia_core,pcmcia_rsrc");

MODULE_ALIAS("pci:v0000104Cd0000AC13sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC1Asv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC12sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC15sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC1Esv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC17sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC19sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC1Csv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC1Dsv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC1Fsv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC51sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC1Bsv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC52sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC56sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC55sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC54sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC41sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd00008011sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC42sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC44sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC46sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC16sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC50sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd00008031sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd00008036sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd00008039sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC8Esv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC8Dsv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC49sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC47sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v0000104Cd0000AC48sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001524d00001411sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001524d00001412sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001524d00001421sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001524d00001422sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001524d00001211sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001524d00001225sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001524d00001410sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001524d00001420sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001180d00000465sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001180d00000466sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001180d00000475sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001180d00000476sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001180d00000478sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001179d0000060Asv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001179d0000060Fsv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001179d00000617sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v00001217d*sv*sd*bc06sc07i00*");
MODULE_ALIAS("pci:v*d*sv*sd*bc06sc07i00*");

MODULE_INFO(srcversion, "93A31D6DD6D8A5275DAEDBF");
