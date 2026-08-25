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
	{ 0x7712771a, "unbind_from_irqhandler" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xb0285ae, "kill_fasync" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xcca5839d, "xen_vcpu_id" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x4c2c0ea7, "evtchn_make_refcounted" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xea5cbce, "xen_irq_lateeoi" },
	{ 0xa4cdf212, "fasync_helper" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0xe007edf, "xen_evtchn_nr_channels" },
	{ 0xa2af54b3, "irq_from_evtchn" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0x4708008a, "misc_register" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x56470118, "__warn_printk" },
	{ 0x636a2492, "no_llseek" },
	{ 0x7ec6993, "stream_open" },
	{ 0xf7866b4f, "bind_evtchn_to_irqhandler_lateeoi" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x45d14bdf, "hypercall_page" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "19A7C05207E672952A94D7E");
