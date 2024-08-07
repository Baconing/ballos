#ifndef MMAP_H
#define MMAP_H

#include <stdint.h>
#include <stddef.h>

struct mmap_entry {
    uint64_t base;
    uint64_t length;
};

uint64_t mmap_total_mem();
void mmap_init(void);
struct mmap_entry *mmap_get_entries(void);
size_t mmap_get_entry_count(void);

#endif
