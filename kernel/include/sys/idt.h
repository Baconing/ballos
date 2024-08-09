#ifndef SYS_IDT_H
#define SYS_IDT_H

#include <stdint.h>

#define IDT_MAX_DESCRIPTORS 256

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags);
void idt_init(void);
void idt_reload(void);

#endif
