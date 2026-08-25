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
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x37a0cba, "kfree" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x92997ed8, "_printk" },
	{ 0xd653a169, "pccard_nonstatic_ops" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x9d08e002, "pcmcia_register_socket" },
	{ 0x45c00a5, "pcmcia_unregister_socket" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x93cdae47, "pcmcia_parse_events" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xcf97f3bd, "dead_socket" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcmcia_rsrc,pcmcia_core");

MODULE_ALIAS("pci:v00001013d00001100sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "BF4725B472D0C9163D4762E");
