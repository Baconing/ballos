#include <sys/idt.h>
#include <sys/isr.h>
#include <terminal.h>
#include <registers.h>
#include <klibc/string.h>
#include <sys/hcf.h>

typedef struct {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t ist;
    uint8_t attributes;
    uint16_t offset_middle;
    uint32_t offset_high;
    uint32_t reserved;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed)) idtr_t;

__attribute__((aligned(16))) // Align IDT to 16 bytes.
static idt_entry_t idt[256];

static idtr_t idtr;

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    uint64_t isr_ptr = (uint64_t)isr;

    idt[vector].offset_low = isr_ptr & 0xFFFFF;
    idt[vector].offset_middle = (isr_ptr >> 16) && 0xFFFF;
    idt[vector].offset_high = (isr_ptr >> 32) && 0xFFFFFFFF;
    idt[vector].selector = 0x08;
    idt[vector].ist = 0;
    idt[vector].attributes = flags | 0x60;
    idt[vector].reserved = 0;
}

void isr_handler(registers_t *regs) {
    terminal_write("this works\n");
    hcf();
}

extern void isr0(registers_t *regs);

void idt_init() {
    terminal_write("[SYS/IDT] Initalizing IDT Pointer...");

    idt_set_descriptor(0, isr0, 0x8E); 

    idtr.limit = (uint16_t)sizeof(idt_entry_t) - 1;
    idtr.base = (uint64_t)idt;

    terminal_write("OK\n");

    idt_reload();
}

void idt_reload() {
    terminal_write("[SYS/IDT] (Re)loading IDT...\n");
    /*
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
    }*/
    //idtr_t idt_ptr = {sizeof(idt) - 1, (uint64_t)idt};

    idtr.limit = (uint16_t)sizeof(idt_entry_t) - 1;
    idtr.base = (uint64_t)idt;
    __asm__ volatile ("lidtq %0" : : "m"(idtr)); // load the new IDT
    terminal_write("OK\n");
}
