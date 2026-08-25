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
	{ 0x8a35b432, "sme_me_mask" },
	{ 0x416c1e62, "drm_gem_fb_destroy" },
	{ 0x7712771a, "unbind_from_irqhandler" },
	{ 0x615e2f98, "drm_kms_helper_poll_fini" },
	{ 0x7f05725d, "drm_open" },
	{ 0x5151da72, "drm_poll" },
	{ 0x18b0b5a1, "drm_dev_enter" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0x472d1bb0, "drm_gem_get_pages" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2295bc93, "drm_kms_helper_poll_init" },
	{ 0xa6257a2f, "complete" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0x494e3393, "vm_get_page_prot" },
	{ 0xc55e0195, "drm_gem_prime_mmap" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4fe00144, "xenbus_dev_fatal" },
	{ 0x29442fd5, "drm_atomic_helper_shutdown" },
	{ 0xc6572a90, "xenbus_read_unsigned" },
	{ 0xa633a415, "xen_front_pgdir_shbuf_get_dir_start" },
	{ 0xbec3c8a2, "drm_prime_sg_to_page_array" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x94961283, "vunmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x6aa2a877, "xenbus_printf" },
	{ 0xc6352942, "xen_front_pgdir_shbuf_map" },
	{ 0x24fec4ac, "xenbus_switch_state" },
	{ 0xef3c4945, "drm_gem_object_init" },
	{ 0x6e7a1685, "drm_gem_prime_handle_to_fd" },
	{ 0x4893617e, "drmm_mode_config_init" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xfffa4690, "drm_firmware_drivers_only" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xabceb1cb, "drm_crtc_send_vblank_event" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe8ad0188, "drm_atomic_helper_commit" },
	{ 0xef7dbcda, "drm_atomic_helper_check" },
	{ 0x6357ffa3, "drm_atomic_helper_connector_destroy_state" },
	{ 0x63208031, "xen_front_pgdir_shbuf_free" },
	{ 0x18c2c9e5, "drm_gem_mmap" },
	{ 0x90982d56, "drm_mode_create" },
	{ 0x60457cb1, "drm_ioctl" },
	{ 0xd0458ccb, "xenbus_strstate" },
	{ 0xe7650b7, "xenbus_alloc_evtchn" },
	{ 0xd4b4b56f, "xen_free_unpopulated_pages" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x55631405, "drm_gem_prime_fd_to_handle" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0xdc905b62, "drm_gem_vm_close" },
	{ 0x75f96800, "drm_gem_vm_open" },
	{ 0x5d8a9030, "drm_dev_unplug" },
	{ 0x10408a6f, "drm_connector_init" },
	{ 0x15b5ef2e, "__xenbus_register_frontend" },
	{ 0x66cf2f64, "drm_display_mode_from_videomode" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x6c241300, "drm_read" },
	{ 0xa15e1675, "drm_gem_object_release" },
	{ 0x732852fe, "xenbus_transaction_end" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xae84b03f, "xen_front_pgdir_shbuf_alloc" },
	{ 0x9ee2b870, "xenbus_unregister_driver" },
	{ 0x9b995b3c, "xen_front_pgdir_shbuf_unmap" },
	{ 0xed2a2b32, "vmap" },
	{ 0x435f223e, "drm_gem_handle_create" },
	{ 0xbc99281e, "xenbus_free_evtchn" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0x51587db2, "drm_prime_pages_to_sg" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xbe56866a, "drm_dev_unregister" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xc7831494, "drm_dev_put" },
	{ 0x2b7d170c, "drm_gem_fb_create_with_funcs" },
	{ 0x34eab46d, "bind_evtchn_to_irqhandler" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0xd287444b, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xe88ebc52, "drm_simple_display_pipe_init" },
	{ 0x86623fd7, "notify_remote_via_irq" },
	{ 0x29cf8e8d, "drm_connector_cleanup" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0xec12af74, "__drm_dbg" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x6502d9c2, "xenbus_scanf" },
	{ 0x52431348, "xenbus_transaction_start" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x20db0e09, "vm_map_pages" },
	{ 0x9b651e51, "xenbus_teardown_ring" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xbfb8b1ce, "xen_alloc_unpopulated_pages" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x89cd6dc0, "drm_atomic_helper_connector_reset" },
	{ 0x2e695727, "drm_mode_config_reset" },
	{ 0x579205ff, "xenbus_setup_ring" },
	{ 0x80961b33, "drm_mode_config_cleanup" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf969b534, "xenbus_dev_error" },
	{ 0xe4979d03, "xenbus_frontend_closed" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x2f1d6eaa, "drm_dev_alloc" },
	{ 0xe02e38c0, "drm_gem_put_pages" },
	{ 0xb35e9eb7, "drm_compat_ioctl" },
	{ 0x79fd4f29, "drm_dev_register" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x85cb2c45, "xen_has_pv_devices" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x3122d93a, "drm_prime_gem_destroy" },
	{ 0x33da23c4, "drm_release" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm,xen-front-pgdir-shbuf");


MODULE_INFO(srcversion, "944D14B22AF51796CAA39FF");
