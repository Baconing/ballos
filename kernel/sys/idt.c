#include <sys/idt.h>
#include <sys/isr.h>
#include <terminal.h>
#include <klibc/string.h>

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

__attribute__((aligned(0x10)))
static idt_entry_t idt[256];

static idtr_t idtr;

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    uint64_t isr_ptr = (uint64_t)isr;

    idt_entry_t* descriptor = &idt[vector];

    descriptor->offset_1       = (uint16_t)isr_ptr;
    descriptor->selector       = 8;
    descriptor->ist            = 0;
    descriptor->attributes     = flags | 0x60;
    descriptor->offset_2       = (uint16_t)(isr_ptr >> 16);
    descriptor->offset_3       = (uint32_t)(isr_ptr >> 32);
    descriptor->reserved       = 0;
}

void idt_init() {
    terminal_write("[SYS/IDT] Initalizing IDT Pointer...");
    idtr.base = (uintptr_t)&idt[0];
    idtr.limit = (uint16_t)sizeof(idt_entry_t) * IDT_MAX_DESCRIPTORS - 1;
    terminal_write("OK\n");

    idt_reload();
}

void idt_reload() {
    terminal_write("[SYS/IDT] (Re)loading IDT...\n");
    for (int i = 0; i < IDT_MAX_DESCRIPTORS; i++) {
        terminal_write("\t[SYS/IDT] IDT Descriptor ");
        terminal_write_dec(i);
        terminal_write(": ");
        terminal_write("Selector: ");
        terminal_write_hex(idt[i].selector);
        terminal_write(" IST: ");
        terminal_write_hex(idt[i].ist);
        terminal_write(" Attributes: ");
        terminal_write_hex(idt[i].attributes);
        terminal_write("\n");
    }
    //idtr_t idt_ptr = {sizeof(idt) - 1, (uint64_t)idt};
    __asm__ volatile ("lidtq %0" : : "m"(idtr)); // load the new IDT
    terminal_write("OK\n");
}
