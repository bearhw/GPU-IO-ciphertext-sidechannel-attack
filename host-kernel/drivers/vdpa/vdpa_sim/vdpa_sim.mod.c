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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(vdpasim_create, 0x4690a6f6, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x69acdf38, "memcpy" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x37a0cba, "kfree" },
	{ 0x311c6da4, "put_iova_domain" },
	{ 0xc7061ef3, "iova_cache_put" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xa24517eb, "vhost_iotlb_free" },
	{ 0xe40f4ed3, "__vdpa_alloc_device" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x3197c4e3, "put_device" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x8a7d8ee9, "vhost_iotlb_init" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xa8efaeb9, "vringh_set_iotlb" },
	{ 0x438d8df2, "iova_cache_get" },
	{ 0x4043757f, "init_iova_domain" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x6bec0e66, "vhost_iotlb_del_range" },
	{ 0x885512a2, "vhost_iotlb_add_range_ctx" },
	{ 0x2e9ec24d, "free_iova" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3ee1955e, "vringh_init_iotlb" },
	{ 0xd27eeb4b, "alloc_iova" },
	{ 0x38ff875f, "vhost_iotlb_add_range" },
	{ 0xdf1be5e1, "__free_iova" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x5f4e5249, "vhost_iotlb_reset" },
	{ 0x69e872f9, "vhost_iotlb_itree_first" },
	{ 0x83be64b9, "vhost_iotlb_itree_next" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vhost_iotlb,vdpa,vringh");


MODULE_INFO(srcversion, "7907F00C33F59103761287D");
