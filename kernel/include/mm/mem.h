#ifndef MEM_H
#define MEM_H

#include <stddef.h>

struct mem_block {
    size_t size;
    struct mem_block *next;
};

void mem_init(void);

void *kmalloc(size_t size);
void kfree(void *ptr);

#endif
