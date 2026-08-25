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
	{ 0x15ba50a6, "jiffies" },
	{ 0xe44841d8, "ip_set_put_byindex" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x5922420e, "ip_set_init_comment" },
	{ 0xaca83782, "ip_set_del" },
	{ 0xaad3f406, "ip_set_add" },
	{ 0xb9867643, "ip_set_test" },
	{ 0xd1c17ba8, "ip_set_match_extensions" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe24187de, "ip_set_extensions" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x8202224c, "ip_set_elem_len" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x37a0cba, "kfree" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x8520a781, "nla_put" },
	{ 0xb5997d69, "ip_set_name_byindex" },
	{ 0xa916b694, "strnlen" },
	{ 0x9641c5c6, "ip_set_put_extensions" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x51fa242b, "ip_set_put_flags" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x24d273d1, "add_timer" },
	{ 0x67dd76de, "ip_set_get_extensions" },
	{ 0x4da15d8c, "ip_set_get_byname" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x5328c5ae, "ip_set_type_register" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x2276f00e, "ip_set_type_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_set");


MODULE_INFO(srcversion, "7FE7858C69056D95974740D");
