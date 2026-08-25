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
	{ 0xf97831, "nvdimm_bus_unregister" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2de84993, "virtio_reset_device" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xb8774cae, "virtio_pmem_host_ack" },
	{ 0x800473f, "__cond_resched" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x58ac4016, "nvdimm_bus_register" },
	{ 0xd58f40e1, "async_pmem_flush" },
	{ 0xe26efb67, "nvdimm_pmem_region_create" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x7edf0c62, "register_virtio_driver" },
	{ 0x188e7d5c, "unregister_virtio_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nd_virtio");

MODULE_ALIAS("virtio:d0000001Bv*");

MODULE_INFO(srcversion, "E9B5954515A1847D9DA9F32");
