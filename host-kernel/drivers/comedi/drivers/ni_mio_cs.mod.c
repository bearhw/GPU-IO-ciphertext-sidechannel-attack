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
	{ 0xa7e75aae, "comedi_pcmcia_auto_config" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x9085e9a, "_dev_err" },
	{  0x79cb1, "comedi_buf_write_samples" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x369058ca, "comedi_buf_read_samples" },
	{ 0x3fa52e21, "comedi_handle_events" },
	{ 0xcbd41e95, "comedi_buf_read_n_available" },
	{ 0x9d784270, "comedi_is_subdevice_running" },
	{ 0x133564c3, "pcmcia_request_io" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6256868, "comedi_dio_update_state" },
	{ 0x2e40b323, "comedi_dio_insn_config" },
	{ 0x64443d67, "ni_get_valid_routes" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x24b9787e, "ni_gpct_device_destroy" },
	{ 0xc927a35f, "comedi_pcmcia_disable" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x86490580, "current_task" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xb3e302a3, "ni_route_to_register" },
	{ 0x76bc308, "ni_find_route_source" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xac1cf23a, "ni_tio_get_routing" },
	{ 0x409afd9e, "ni_tio_unset_routing" },
	{ 0xd4e06b79, "ni_tio_set_routing" },
	{ 0x921123e, "ni_lookup_route_register" },
	{ 0x7024e03d, "comedi_to_pcmcia_dev" },
	{ 0xe63a7161, "comedi_pcmcia_enable" },
	{ 0x33860e8, "pcmcia_request_irq" },
	{ 0x7e2f11fc, "comedi_alloc_devpriv" },
	{ 0x85e75c94, "ni_assign_device_routes" },
	{ 0x9b66e218, "comedi_alloc_subdevices" },
	{ 0x86e07916, "comedi_alloc_subdev_readback" },
	{ 0xdb2044b2, "range_unipolar5" },
	{ 0xdcd7c831, "ni_gpct_device_construct" },
	{ 0xbc68fce2, "ni_tio_init_counter" },
	{ 0xcd67167f, "ni_tio_insn_read" },
	{ 0x8c13f188, "ni_tio_insn_write" },
	{ 0x6a7fe1ee, "ni_tio_insn_config" },
	{ 0xbe6fb8b1, "subdev_8255_init" },
	{ 0xcd330f4, "range_unknown" },
	{ 0x60d424e, "comedi_pcmcia_driver_register" },
	{ 0xac6f1934, "comedi_pcmcia_driver_unregister" },
	{ 0xa56b6a6a, "comedi_pcmcia_auto_unconfig" },
	{ 0x2f0ad9d3, "range_bipolar5" },
	{ 0xbb52fc7f, "range_bipolar10" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi_pcmcia,comedi,pcmcia,ni_routing,ni_tio,comedi_8255");

MODULE_ALIAS("pcmcia:m010Bc010Df*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m010Bc010Cf*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m010Bc02C4f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m010Bc075Ef*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m010Bc0245f*fn*pfn*pa*pb*pc*pd*");

MODULE_INFO(srcversion, "6AC5A4FFFDA5CC6E9F7DA7D");
