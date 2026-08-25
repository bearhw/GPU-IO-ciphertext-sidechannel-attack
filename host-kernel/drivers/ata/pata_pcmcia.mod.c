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
	{ 0xa586d479, "ata_host_detach" },
	{ 0x1a6879ec, "pcmcia_disable_device" },
	{ 0x745548c3, "pcmcia_loop_config" },
	{ 0x781fa6ce, "pcmcia_enable_device" },
	{ 0x90a7a78d, "devm_ioport_map" },
	{ 0x848d372e, "iowrite8" },
	{ 0xa9bece9, "ata_host_alloc" },
	{ 0x73a48b4a, "ata_sff_std_ports" },
	{ 0x6d435d09, "ata_port_desc" },
	{ 0x3a4f6a32, "ata_sff_interrupt" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfbab1bb1, "ioread8_rep" },
	{ 0xa4b94fea, "iowrite8_rep" },
	{ 0x133564c3, "pcmcia_request_io" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xeaeb5869, "ata_do_set_mode" },
	{ 0x92997ed8, "_printk" },
	{ 0xa871400e, "ata_dev_disable" },
	{ 0xb19b445, "ioread8" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x50a9f59c, "pcmcia_register_driver" },
	{ 0xb59602ab, "pcmcia_unregister_driver" },
	{ 0x36753cab, "ata_cable_40wire" },
	{ 0x734f0af5, "ata_sff_port_ops" },
	{ 0xd2185039, "ata_sff_data_xfer32" },
	{ 0x55c3bbfb, "ata_scsi_queuecmd" },
	{ 0xa9cca2f6, "ata_scsi_ioctl" },
	{ 0x7c53ac28, "ata_scsi_slave_config" },
	{ 0x851271f, "ata_scsi_slave_destroy" },
	{ 0x15ca04ff, "ata_scsi_dma_need_drain" },
	{ 0x22f5fb25, "ata_std_bios_param" },
	{ 0x49761292, "ata_scsi_unlock_native_capacity" },
	{ 0x86faae37, "ata_common_sdev_groups" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcmcia");

MODULE_ALIAS("pcmcia:m*c*f04fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0000c0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0007c0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m000Ac0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m001Cc0001f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0032c0704f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0032c2904f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0045c0401f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m004Fc0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0097c1620f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0098c0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m00A4c002Df*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m00CEc0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m00F1c0101f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0319c0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m2080c0001f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m4E01c0100f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m4E01c0200f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa8C36137CpbD0693AB8pc2768A9F0pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa1B9179CApbEDE88951pc0D902F74pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa281F1C5Dpb1907960CpcF7FDE8B9pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa78F308DCpb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa78F308DCpb0C694728pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa46D7DB81pb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa7D93B852pb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paFF8C8A45pbFE8020C4pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa17692A66pbEF1DCBDEpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa6F58C983pb63C13AAFpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa0A5C52FDpb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa0A5C52FDpb0C694728pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa5714CBF7pb48E0AB8Epc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paF4F43949pb9EB86AAEpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paF4F43949pbA6D76178pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa3D5B9EF5pbCA6AB420pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paB569A6E5pbA6D76178pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paB569A6E5pbF2508753pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa2E6D1829pb55D5BFFBpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa2E6D1829pb531E7D10pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa2E6D1829pbACBE682Epc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa547E66DCpb8671043Bpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa547E66DCpb5C5AB149pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa547E66DCpbB3662674pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paE37BE2B5pb8671043Bpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa7ED2AD87pb7E9E78EEpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa7ED2AD87pb7A13045Cpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa*pbEBE0BD79pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa281F1C5Dpb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa281F1C5Dpb0C694728pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa4A3F0BA0pb322560E1pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa87C1B330pbE1F30883pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa43D74CB4pb6A22777Dpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa30896C92pb703CC5F6pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paB4585A1Apb3489E003pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paD0909443pb*pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pbF68B6F32pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pb2A54D4B1pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pb969AA4F2pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pbF54A91C8pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pb7558F133pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pbB2F89B47pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa244E5994pb3E232852pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paCC7CF69Cpb212BB918pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paE4A13209pb*pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paBF2DF18Dpb8CB57A0Epc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn01pfn*pa7A954BD9pb74BE00C6pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa*pb5A362506pc*pd*");

MODULE_INFO(srcversion, "49B1E4F2CDE806F61D6495F");
