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
	{ 0x2fac87ee, "ppp_input" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0x6a7f1587, "ppp_unregister_channel" },
	{ 0x37a0cba, "kfree" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1de23e95, "module_put" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xbed9ef52, "ppp_input_error" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x428c712, "ppp_output_wakeup" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x3a10a05e, "ppp_channel_index" },
	{ 0xc004116a, "ppp_unit_number" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0xc6cbbc89, "capable" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa07d1b3c, "tasklet_setup" },
	{ 0x6602d9e2, "ppp_register_channel" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xf728c38e, "vcc_process_recv_queue" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x20c3e4b2, "skb_realloc_headroom" },
	{ 0xbd505649, "consume_skb" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x59f209e, "register_atm_ioctl" },
	{ 0x67023607, "deregister_atm_ioctl" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");


MODULE_INFO(srcversion, "624DB693C091F1C66D94F7A");
