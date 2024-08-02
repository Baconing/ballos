#include <sys/idt.h>
#include <sys/isr.h>
#include <terminal.h>
#include <klibc/string.h>

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    idt_entry_t* descriptor = &idt[vector];

    descriptor->isr_low        = (uint64_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x08;
    descriptor->ist            = 0;
    descriptor->attributes     = flags;
    descriptor->isr_mid        = ((uint64_t)isr >> 16) & 0xFFFF;
    descriptor->isr_high       = ((uint64_t)isr >> 32) & 0xFFFFFFFF;
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
    __asm__ volatile ("lidt %0" : : "m"(idtr)); // load the new IDT
    __asm__ volatile ("sti"); // set the interrupt flag
	terminal_write("OK\n");
}