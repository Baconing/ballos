#ifndef SYS_IDT_H
#define SYS_IDT_H

#include <stdint.h>

#define IDT_MAX_DESCRIPTORS 256

typedef struct {
    uint16_t    offset_1;
    uint16_t    selector;
    uint8_t	    ist;
    uint8_t     attributes;
    uint16_t    offset_2;
    uint32_t    offset_3;
    uint32_t    reserved;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t	limit;
    uint64_t	base;
} __attribute__((packed)) idtr_t;

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags);
void idt_init(void);
void idt_reload(void);

#endif
