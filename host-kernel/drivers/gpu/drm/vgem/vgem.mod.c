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
	{ 0x7f05725d, "drm_open" },
	{ 0x5151da72, "drm_poll" },
	{ 0xd9372bb1, "devres_release_group" },
	{ 0xd0f9fa29, "dma_resv_reserve_fences" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x480d14ca, "drm_gem_shmem_dumb_create" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x7b82b9a1, "idr_replace" },
	{ 0x2e80b5ac, "ww_mutex_unlock" },
	{ 0x2f2f1e5a, "dma_resv_add_fence" },
	{ 0x37a0cba, "kfree" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2330f595, "drm_gem_object_lookup" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0x14605535, "dma_fence_context_alloc" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x731c4a9c, "dma_fence_signal" },
	{ 0x6c241300, "drm_read" },
	{ 0xdd8166a1, "dma_fence_free" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x593b6030, "ww_mutex_lock" },
	{ 0xfac224d5, "devres_open_group" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x16dee44d, "dma_fence_init" },
	{ 0xbe56866a, "drm_dev_unregister" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x6ee0b8fb, "__devm_drm_dev_alloc" },
	{ 0x1a3b73ee, "drm_gem_shmem_prime_import_sg_table" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x1d40b6f3, "idr_for_each" },
	{ 0xb12311e0, "platform_device_register_full" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xb91fc7c5, "dma_resv_test_signaled" },
	{ 0xe123f3d9, "dma_fence_release" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x33da23c4, "drm_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_shmem_helper");


MODULE_INFO(srcversion, "142C3C97109C3FB930E19D2");
