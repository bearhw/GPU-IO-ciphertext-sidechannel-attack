#include "linux/types.h"
#include <linux/printk.h>
#include <linux/uaccess.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>
#include <linux/sev-step/userspace_page_track_api.h>
#include <linux/raw_spinlock.h>
#include <asm/string.h>
#include <linux/sev-step/sev-step.h>

usp_poll_api_ctx_t* uspt_ctx = NULL;
EXPORT_SYMBOL(uspt_ctx);

int get_size_for_event(usp_event_type_t event_type, uint64_t *size) {
    switch (event_type)
    {
        case PAGE_FAULT_EVENT:
            *size = sizeof(usp_page_fault_event_t);
            return 0;
        case SEV_STEP_EVENT:
            *size = sizeof(sev_step_event_t);
            return 0;
        case DUMP_PAGE_EVENT:
            *size = sizeof(usp_dump_page_event_t);
            return 0;
#ifdef ENABLE_OLD_SWAP_PAGES_SUPPORT
        case PAGE_SWAP_EVENT:
            *size = sizeof(usp_page_swap_event_t);
            return 0;
#endif // ENABLE_OLD_SWAP_PAGES_SUPPORT
        default:
            return 1;
    }
}

/**
 * @brief 
 * 
 * @param ctx 
 * @param event_type 
 * @param event 
 * @return int 
 *  - 1 : general error
 *  - 0 : success
 *  - 2 : force reset
 */
int usp_send_and_block(usp_poll_api_ctx_t* ctx, usp_event_type_t event_type, void* event) {
    uint64_t event_bytes = 0;
    uint64_t abort_after = 0;
    uint64_t event_buffer_offset = 0;
    const uint64_t sec_to_nanosec = 1000000000ULL;


/*
Initial: have_event = 0, event_acked = 1

Sender: if event_acked true, we can send a new event by locking and setting
have_event = 1 and event_acked = 0

Receiver: if have_event is true, we can access the event buffer.
We must set event_acked = 1 to allow the sender to send the next event
we also reset have_event
*/
    if (!ctx_initialized()) {
        printk("usp_send_and_block: Ctx is not initialized\n");
        return 1;
    }
    //wait untill we are allowed to send the next event
    //printk("usp_send_and_block: trying to get lock...\n");
    while(1) {
        raw_spinlock_lock(&ctx->shared_mem_region->spinlock);
        if( ctx->shared_mem_region->event_acked ) {
            //DO NOT UNLOCK HERE
            break;
        }
        if( ctx->force_reset ) {
            printk("usp_send_and_block: abort wait for send due to force_reset=1\n");
            raw_spinlock_unlock(&ctx->shared_mem_region->spinlock);
            return 2; //TODO: introcude proper error constants

        }
        raw_spinlock_unlock(&ctx->shared_mem_region->spinlock);
    }

    //if we are here, we hold ctx->shared_mem_region.spinlock and last event was acked
    //printk("usp_send_and_block: got lock\n");
    
    //copy event
    if( get_size_for_event(event_type,&event_bytes)) {
        printk("Failed to determine size for event %d.",event_type);
        raw_spinlock_unlock(&ctx->shared_mem_region->spinlock);
        return 1;
    }
    //printk("resolved event size, copying...\n");
    memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset ,event,event_bytes);
    event_buffer_offset += event_bytes;
    if( event_type == SEV_STEP_EVENT) {
        sev_step_event_t* step_event = (sev_step_event_t*)event;
        if( step_event->cache_attack_timings != NULL ) {
            uint64_t bytes = sizeof(step_event->cache_attack_timings[0]) * step_event->cache_attack_data_len;
           
            if( sizeof(ctx->shared_mem_region->event_buffer) < 
                (event_buffer_offset + bytes ) ) {
                    printk("Cannot copy cache attack timing data as event buffer is full\n");
            } else {
                /*printk("copying optional cache attack timing data\n %llu entries",
                    step_event->cache_attack_data_len
                );*/
                memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                    step_event->cache_attack_timings,bytes
                );
                event_buffer_offset += bytes;
            }
           
        }
        if( step_event->cache_attack_perf_values != NULL ) {
            uint64_t bytes = sizeof(step_event->cache_attack_perf_values[0]) * step_event->cache_attack_data_len;
           
            if( sizeof(ctx->shared_mem_region->event_buffer) < 
                (event_buffer_offset + bytes ) ) {
                    printk("Cannot copy cache attack perf data as event buffer is full\n");
            } else {
                /*printk("copying optional cache attack perf data\n %llu entries",
                    step_event->cache_attack_data_len
                );*/
                memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                    step_event->cache_attack_perf_values,bytes
                );
                event_buffer_offset += bytes;
            }
           
        }
    } else if (event_type == PAGE_FAULT_EVENT) {
        usp_page_fault_event_t *pf_event = (usp_page_fault_event_t*)event;
#ifdef ENABLE_MONITOR_UNTRACKED_PAGES
        struct page_content_list *entry;
        u32 nr_updated_untracked_pages = 0;
        struct list_head *list_head_updated_untracked_pages_ptr
                    = (struct list_head *)pf_event->list_head_sent_untracked_pages_ptr;
#endif // ENABLE_MONITOR_UNTRACKED_PAGES
        if (pf_event->curr_pf_content_ptr) {
            memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                    pf_event->curr_pf_content_ptr, 4096);
            // Assign this value as it is only used as a non-NULL indicator in the userspace
            // to check if the page content is present
            pf_event->curr_pf_content_ptr = (uint8_t *)(-1);
            event_buffer_offset += 4096;
        }

        if (pf_event->prev_pf_content_ptr) {
            memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                    pf_event->prev_pf_content_ptr, 4096);
            // Assign this value as it is only used as a non-NULL indicator in the userspace
            // to check if the page content is present
            pf_event->prev_pf_content_ptr = (uint8_t *)(-1);
            event_buffer_offset += 4096;
        }

#ifdef ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT
        if (pf_event->curr_pf_null_bitmap) {
            memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                    pf_event->curr_pf_null_bitmap, 256);
            // Assign this value as it is only used as a non-NULL indicator in the userspace
            // to check if the null bitmap is present
            pf_event->curr_pf_null_bitmap = (uint8_t *)(-1);
            event_buffer_offset += 256;
        }

        if (pf_event->prev_pf_null_bitmap) {
            memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                    pf_event->prev_pf_null_bitmap, 256);
            // Assign this value as it is only used as a non-NULL indicator in the userspace
            // to check if the null bitmap is present
            pf_event->prev_pf_null_bitmap = (uint8_t *)(-1);
            event_buffer_offset += 256;
        }
#endif // ENABLE_OLD_NULL_CIPHER_REPR_SUPPORT

#ifdef ENABLE_MONITOR_UNTRACKED_PAGES
        // Traverse the list_head
        if (list_head_updated_untracked_pages_ptr) {
            list_for_each_entry(entry, list_head_updated_untracked_pages_ptr, list) {
                // TODO: Currently only supports sending limited amount of pages
                // because the number of pinned pages is limited
                if (nr_updated_untracked_pages > 16) {
                    printk(KERN_ERR "usp_send_and_block: Number of updated untracked pages should not exceed 16\n");
                    // break;
                    goto pf_event_out;
                }
                memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                        (void *)(&entry->gpa), sizeof(entry->gpa));
                event_buffer_offset += sizeof(entry->gpa);
                memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                        (void *)(&entry->content), 4096);
                event_buffer_offset += 4096;
                nr_updated_untracked_pages++;
                // assert(nr_updated_untracked_pages <= 16);
            }
        }
pf_event_out:
        // pf_event->nr_updated_untracked_pages = nr_updated_untracked_pages;
        // printk(KERN_INFO "usp_send_and_block: Number of updated untracked pages: %u\n", nr_updated_untracked_pages);
        if (pf_event->nr_sent_untracked_pages <= 16) {
            // Check if nr_updated_untracked_pages is equal to the pf_event's nr_updated_untracked_pages
            if (nr_updated_untracked_pages != pf_event->nr_sent_untracked_pages) {
                printk(KERN_ERR "usp_send_and_block: Number of updated untracked pages mismatch:"
                                " %u != pf_event->%u\n",
                                nr_updated_untracked_pages,
                                pf_event->nr_sent_untracked_pages);
            }
        }
#endif // ENABLE_MONITOR_UNTRACKED_PAGES
    } else if (event_type == DUMP_PAGE_EVENT) {
        usp_dump_page_event_t *dump_event = (usp_dump_page_event_t*)event;
        if (dump_event->page_content != NULL) {
            memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                    dump_event->page_content, 4096);
            event_buffer_offset += 4096;
        } else {
            printk("usp_send_and_block: page content ptr is NULL\n");
        }
    }
#ifdef ENABLE_OLD_SWAP_PAGES_SUPPORT
    else if (event_type == PAGE_SWAP_EVENT) {
        usp_page_swap_event_t *swap_event = (usp_page_swap_event_t*)event;
        if (swap_event->four_pages_content != NULL) {
            memcpy((void*)ctx->shared_mem_region->event_buffer + event_buffer_offset,
                    swap_event->four_pages_content, 4 * 4096);
            event_buffer_offset += 4 * 4096;
        } else {
            printk("usp_send_and_block: four pages content ptr is NULL\n");
        }
    }
#endif // ENABLE_OLD_SWAP_PAGES_SUPPORT
       
    ctx->shared_mem_region->event_type = event_type;
    //printk("usp_send_and_block: done copying. Setting status flags...\n");


    //set status flags
    ctx->shared_mem_region->event_acked = 0;
    ctx->shared_mem_region->have_event = 1;

    raw_spinlock_unlock(&ctx->shared_mem_region->spinlock);
    //printk("usp_send_and_block: unlocked and done\n");

    //wait until we are allowed to send the next event
    //wait for ack, but with tiemout. Otherwise small bugs in userland easily lead
    //to a kernel hang
    abort_after = ktime_get_ns() + 10ULL * sec_to_nanosec;
    //printk("usp_send_and_block: waiting with return untill user acked...\n");
    while(1) {
        raw_spinlock_lock(&ctx->shared_mem_region->spinlock);
        if( ctx->shared_mem_region->event_acked ) {
            raw_spinlock_unlock(&ctx->shared_mem_region->spinlock);
            break;
        }
        if( ctx->force_reset ) {
            printk("usp_send_and_block: abort wait for send due to force_reset=1\n");
            raw_spinlock_unlock(&ctx->shared_mem_region->spinlock);
            return 2; //TODO: introcude proper error constants
        }


        if( ktime_get_ns() > abort_after ) {
            printk("Waiting for ack of event timed out, continuing\n");
            raw_spinlock_unlock(&ctx->shared_mem_region->spinlock);
            return 3;
        }

        raw_spinlock_unlock(&ctx->shared_mem_region->spinlock);

       


    }
    //printk("usp_send_and_block: user acked the event ");

    return 0;
}
EXPORT_SYMBOL(usp_send_and_block);

int usp_poll_init_user_vaddr(int pid,uint64_t user_vaddr_shared_mem,usp_poll_api_ctx_t* ctx) {
    struct page **shared_mem_pages;
	shared_mem_region_t* shared_mem_kern_mapping;
    int res;
    int shared_mem_pages_len;
    int idx;


    //create persistent, kernel accessible mapping for user space memory
    if ( (user_vaddr_shared_mem & 0xfff) != 0 ) {
            printk("usp_poll_init_user_vaddr: the provided vaddr 0x%llx is not page aligend!\n",user_vaddr_shared_mem);
            return 1;
    }
    if( (SEV_STEP_SHARED_MEM_BYTES % 4096) != 0 ) {
         printk("usp_poll_init_user_vaddr: SEV_STEP_SHARED_MEM_BYTES is not a multiple of page size!\n");
        return 1;
    }
    shared_mem_pages_len = SEV_STEP_SHARED_MEM_BYTES / 4096;
    shared_mem_pages = kmalloc(sizeof(struct page*) * shared_mem_pages_len, GFP_KERNEL);


   res = pin_user_pages(
        user_vaddr_shared_mem, //start vaddr
        shared_mem_pages_len, //number of pages to pin from start vaddr
        FOLL_LONGTERM | FOLL_WRITE,
        shared_mem_pages,
        NULL
    );
    printk("%s: Pinned %d pages\n", __func__, res);
    if( res <= 0 ) {
        printk("usp_poll_init_user_vaddr: get_user_pages failed with %d\n",res);
        return 1;
    }
    if (res != shared_mem_pages_len) {
        printk("usp_poll_init_user_vaddr: get_user_pages returned %d pages, but we need %d\n",res,shared_mem_pages_len);
        return 1;
    }
    //sanity check refcount value
    for( idx = 0; idx < shared_mem_pages_len; idx++ ) {
        if(page_ref_count(shared_mem_pages[idx]) < 0 ) {
            printk("%s:%d [%s] pinned pfn 0x%lx. refcount: %d\n",__FILE__,__LINE__,__FUNCTION__,page_to_pfn(shared_mem_pages[idx]),page_ref_count(shared_mem_pages[idx]));
        }
    }
   


    shared_mem_kern_mapping = (shared_mem_region_t*)vmap(shared_mem_pages,shared_mem_pages_len,0,PAGE_KERNEL);
    if( shared_mem_kern_mapping == NULL ) {
        printk("usp_poll_init_user_vaddr: failed to get virtual mapping for page struct\n");
        return 1;
    }
    //printk("usp_poll_init_user_vaddr: vaddr of kernel mapping is 0x%llx\n",(uint64_t)shared_mem_kern_mapping);

    //call regular create ctx path

    usp_poll_init_kern_vaddr(pid,shared_mem_kern_mapping,ctx);

    //fix ctx values specific to this ctx creation path

    ctx->_pages_for_shared_mem = shared_mem_pages;
    ctx->_pages_for_shared_mem_len = shared_mem_pages_len;
    return 0;
}


int usp_poll_init_kern_vaddr(int pid, shared_mem_region_t* shared_mem_region ,usp_poll_api_ctx_t* ctx ) {

    ctx->pid = pid;
    ctx->next_id = 1;
    ctx->force_reset = 0;
    ctx->shared_mem_region = shared_mem_region;
    ctx->_pages_for_shared_mem = NULL;
    ctx->_pages_for_shared_mem_len = 0;
    return 0;
}

int usp_poll_close_api(usp_poll_api_ctx_t* ctx) {
    raw_spinlock_lock(&ctx->shared_mem_region->spinlock);
    ctx->force_reset = 1;
    raw_spinlock_unlock(&ctx->shared_mem_region->spinlock);
    return 0;
}

int ctx_initialized() {
    return uspt_ctx != NULL;
}