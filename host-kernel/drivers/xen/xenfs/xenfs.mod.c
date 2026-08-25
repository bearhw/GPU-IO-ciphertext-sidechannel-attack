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
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x9fe131f1, "xen_store_interface" },
	{ 0x94f5f6cf, "simple_fill_super" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0xd6727dc4, "remap_pfn_range" },
	{ 0x37a0cba, "kfree" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa916b694, "strnlen" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x5187ac4b, "xen_store_evtchn" },
	{ 0x54ea6dfe, "xen_start_flags" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x23af578f, "default_llseek" },
	{ 0x1f7a9338, "kill_litter_super" },
	{ 0xfb578fc5, "memset" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xf2b11959, "seq_read" },
	{ 0xf30577ef, "xen_privcmd_fops" },
	{ 0x3e5409e4, "xen_xenbus_fops" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x9f186838, "seq_release_private" },
	{ 0xb15169bb, "get_tree_single" },
	{ 0x754d539c, "strlen" },
	{ 0xc6051f1c, "seq_open_private" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x45d14bdf, "hypercall_page" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "xen-privcmd");


MODULE_INFO(srcversion, "3739516DC0A7C250B380687");
