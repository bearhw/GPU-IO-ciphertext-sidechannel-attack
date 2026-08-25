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
	{ 0x1a6879ec, "pcmcia_disable_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xe3cf61cb, "parport_pc_unregister_port" },
	{ 0x37a0cba, "kfree" },
	{ 0x133564c3, "pcmcia_request_io" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x745548c3, "pcmcia_loop_config" },
	{ 0x781fa6ce, "pcmcia_enable_device" },
	{ 0xd397c2a3, "parport_pc_probe_port" },
	{ 0x92997ed8, "_printk" },
	{ 0x50a9f59c, "pcmcia_register_driver" },
	{ 0xb59602ab, "pcmcia_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcmcia,parport_pc");

MODULE_ALIAS("pcmcia:m*c*f03fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn01pfn*pa3BEB8CF2pbDB9E58BCpc*pd*");
MODULE_ALIAS("pcmcia:m0137c0003f*fn*pfn*pa*pb*pc*pd*");

MODULE_INFO(srcversion, "B87056C1767CB96DBA80C00");
