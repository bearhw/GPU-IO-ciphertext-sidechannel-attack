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
	{ 0xbfbc5434, "pciserial_resume_ports" },
	{ 0x31c7970f, "pciserial_suspend_ports" },
	{ 0xe84f6e5c, "pciserial_remove_ports" },
	{ 0xe3cf61cb, "parport_pc_unregister_port" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0xd397c2a3, "parport_pc_probe_port" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaa7e50e6, "pciserial_init_ports" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "parport_pc");

MODULE_ALIAS("pci:v000014D2d00008011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014D2d00008021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009735sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009745sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009835sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009845sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009855sv00001000sd00000020bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009855sv00001000sd00000022bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009855sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009900sv0000A000sd00003011bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009900sv0000A000sd00003012bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009900sv0000A000sd00003020bc*sc*i*");
MODULE_ALIAS("pci:v00009710d00009912sv0000A000sd00002000bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002110sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002140sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002141sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002142sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002160sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002161sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014DBd00002162sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00001010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00001011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00001012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00001034sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00001035sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00001036sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002040sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002060sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002061sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000131Fd00002062sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00004078bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00004079bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00004085bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00004088bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00004089bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00004095bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00004096bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00005078bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00005079bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00005085bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00006079bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00007079bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00008079bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd00009079bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd0000A079bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd0000B079bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd0000C079bc*sc*i*");
MODULE_ALIAS("pci:v00001409d00007168sv00001409sd0000D079bc*sc*i*");
MODULE_ALIAS("pci:v00004348d00005053sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00004348d00007053sv00004348sd00003253bc*sc*i*");
MODULE_ALIAS("pci:v00001C00d00003050sv00001C00sd00003050bc*sc*i*");
MODULE_ALIAS("pci:v00001C00d00003250sv00001C00sd00003250bc*sc*i*");
MODULE_ALIAS("pci:v0000135Ad00004100sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001FD4d00001999sv00001FD4sd00000100bc*sc*i*");
MODULE_ALIAS("pci:v00001FD4d00001999sv00001FD4sd00000101bc*sc*i*");
MODULE_ALIAS("pci:v00001FD4d00001999sv00001FD4sd00000102bc*sc*i*");
MODULE_ALIAS("pci:v00001FD4d00001999sv00001FD4sd00000104bc*sc*i*");

MODULE_INFO(srcversion, "8AAEA61FC3AA337B13E89D4");
