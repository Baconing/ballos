#include <sys/idt.h>
#include <sys/isr.h>
#include <terminal.h>
#include <klibc/string.h>


__attribute__((aligned(0x10)))
static idt_entry_t idt[256];

static idtr_t idtr;

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    idt_entry_t* descriptor = &idt[vector];

    descriptor->offset_1       = (uint64_t)isr & 0xFFFF;
    descriptor->selector       = 8;
    descriptor->ist            = 0;
    descriptor->attributes     = flags | 0x60;
    descriptor->offset_2       = ((uint64_t)isr >> 16) & 0xFFFF;
    descriptor->offset_3       = ((uint64_t)isr >> 32) & 0xFFFFFFFF;
    descriptor->reserved       = 0;
}

void idt_init() {
    terminal_write("[SYS/IDT] Setting IDTR base...");
    idtr.base = (uintptr_t)&idt[0];
	terminal_write("OK\n");
    terminal_write("[SYS/IDT] Setting IDTR Limit...");
    idtr.limit = (uint16_t)sizeof(idt_entry_t) * IDT_MAX_DESCRIPTORS - 1;
	terminal_write("OK\n");

	idt_reload();
}

void idt_reload() {
	terminal_write("[SYS/IDT] (Re)loading IDT...");
    idtr_t idt_ptr = {sizeof(idt) - 1, (uint64_t)idt};
    __asm__ volatile ("lidtq %0" : : "m"(idt_ptr)); // load the new IDT
	terminal_write("OK\n");
}