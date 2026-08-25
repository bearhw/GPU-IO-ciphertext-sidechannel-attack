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

SYMBOL_CRC(parport_pc_probe_port, 0xd397c2a3, "");
SYMBOL_CRC(parport_pc_unregister_port, 0xe3cf61cb, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x5a921311, "strncmp" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb121390a, "probe_irq_on" },
	{ 0xab600421, "probe_irq_off" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x86490580, "current_task" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0x1c4c2d08, "parport_remove_port" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x72b243d4, "free_dma" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x37a0cba, "kfree" },
	{ 0x9f4f20bc, "parport_del_port" },
	{ 0xabdc439, "cc_platform_has" },
	{ 0xb66f1944, "parport_wait_event" },
	{ 0x1000e51, "schedule" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x69acdf38, "memcpy" },
	{ 0x175e33fb, "dma_spin_lock" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xdd7c688b, "parport_wait_peripheral" },
	{ 0xddfcbbe3, "parport_ieee1284_ecp_write_data" },
	{ 0x98a97864, "parport_ieee1284_write_compat" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc15defcd, "parport_register_port" },
	{ 0x85bd1608, "__request_region" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x5e3a3912, "parport_irq_handler" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xe6f675ad, "parport_announce_port" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x7054a3e4, "request_dma" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa834c8c2, "pnp_get_resource" },
	{ 0x2587f789, "_dev_info" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xfd0bbb57, "pci_match_id" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x1d526753, "pnp_register_driver" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x8a75fabb, "pnp_unregister_driver" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xdc7f53cc, "platform_bus_type" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x786109b9, "param_array_ops" },
	{ 0xfa0f1ab6, "parport_ieee1284_epp_write_data" },
	{ 0xa05f234c, "parport_ieee1284_epp_read_data" },
	{ 0x116ebe07, "parport_ieee1284_epp_write_addr" },
	{ 0xf00a0aa6, "parport_ieee1284_epp_read_addr" },
	{ 0x14f82304, "parport_ieee1284_ecp_read_data" },
	{ 0x369d1f52, "parport_ieee1284_ecp_write_addr" },
	{ 0x9b74c762, "parport_ieee1284_read_nibble" },
	{ 0x2113cc70, "parport_ieee1284_read_byte" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "parport");

MODULE_ALIAS("pnp:dPNP0400*");
MODULE_ALIAS("acpi*:PNP0400:*");
MODULE_ALIAS("pnp:dPNP0401*");
MODULE_ALIAS("acpi*:PNP0401:*");
MODULE_ALIAS("pci:v00001106d00000686sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d00008231sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001283d00008872sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00001020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00001021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001407d00008000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001407d00008002sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001407d00008003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001407d00008800sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009050sv0000D84Dsd00004014bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007268sv00001409sd00000101bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007268sv00001409sd00000102bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007268sv00001409sd00000103bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007268sv00001409sd00000104bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007268sv00001409sd00009018bc*sc*i*");
MODULE_ALIAS("pci:v00001592d00000782sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001592d00000783sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014D2d00008001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002120sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002121sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d00009523sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d00009513sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d00008403sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d0000C000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d0000C004sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d0000C100sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d0000C104sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d0000C110sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d0000C114sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d0000C118sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001415d0000C11Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000416Cd00000100sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014F2d00000121sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009705sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009715sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009755sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009805sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009815sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009901sv0000A000sd00002000bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009865sv0000A000sd00001000bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009865sv0000A000sd00002000bc*sc*i*");
MODULE_ALIAS("pci:v0000135Cd00000278sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001C00d00003050sv00001C00sd00003050bc*sc*i*");

MODULE_INFO(srcversion, "5A0554FDC39C690A2A334F0");
