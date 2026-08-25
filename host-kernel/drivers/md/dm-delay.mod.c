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
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x96848186, "scnprintf" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x92997ed8, "_printk" },
	{ 0x46a429db, "dm_bio_from_per_bio_data" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x828d0cfd, "dm_submit_bio_remap" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "943F9BF3807807218F7C4DF");
