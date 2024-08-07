#include <mm/mem.h>
#include <mm/mmap.h>
#include <limine.h>
#include <terminal.h>

static struct mem_block *free_list = NULL;

void mem_init() {
    terminal_write("[MM/MEM] Initializing memory manager...");
    /*
    struct mmap_entry *mmap_entries = mmap_get_entries();
    for (size_t i = 0; i < mmap_get_entry_count(); i++) {
        struct mmap_entry *entry = &mmap_entries[i];
        struct mem_block *block = (struct mem_block *)entry->base;
        block->size = entry->length - sizeof(struct mem_block);
        block->next = free_list;
        free_list = block;
        terminal_write("[MM/MEM] Added block: base=");
        terminal_write_hex((uint64_t)entry->base);
        terminal_write(", size=");
        terminal_write_dec(block->size);
        terminal_write("\n");
    }
     */
    terminal_write("TODO\n");
}

void *kmalloc(size_t size) {
    struct mem_block *prev = NULL;
    struct mem_block *curr = free_list;

    while (curr != NULL) {
        if (curr->size >= size) {
            if (curr->size > size + sizeof(struct mem_block)) {
                struct mem_block *new_block = (struct mem_block *)((char *)curr + sizeof(struct mem_block) + size);
                new_block->size = curr->size - size - sizeof(struct mem_block);
                new_block->next = curr->next;
                curr->size = size;
                curr->next = new_block;
            }

            if (prev == NULL) {
                free_list = curr->next;
            } else {
                prev->next = curr->next;
            }

            return (void *)((char *)curr + sizeof(struct mem_block));
        }

        prev = curr;
        curr = curr->next;
    }

    return NULL; // No suitable block found
}

void kfree(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    struct mem_block *block = (struct mem_block *)((char *)ptr - sizeof(struct mem_block));
    block->next = free_list;
    free_list = block;
}