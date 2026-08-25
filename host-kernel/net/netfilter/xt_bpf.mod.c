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
	{ 0x76048be1, "bpf_prog_destroy" },
	{ 0xf84bd6ee, "bpf_stats_enabled_key" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3a26ed11, "sched_clock" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x49608959, "migrate_disable" },
	{ 0x4d7272e4, "migrate_enable" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa916b694, "strnlen" },
	{ 0xe4520f37, "bpf_prog_get_type_path" },
	{ 0xb237e1d6, "bpf_prog_create" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xf0f73fe2, "bpf_prog_get_type_dev" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x92997ed8, "_printk" },
	{ 0x7ec922ce, "xt_register_matches" },
	{ 0x4bb1f65e, "xt_unregister_matches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "D3EE0220C3C869B56194D98");
