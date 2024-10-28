#include <sys/gdt.h>
#include <stdint.h>
#include <terminal.h>

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

struct gdt_ptr {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed));

struct gdtr {
    struct gdt_entry entries[5];
} __attribute__((packed));

struct gdtr gdt = { 0 };

extern void gdt_flush();

void gdt_init() {
    terminal_write("[SYS/GDT] Initializing GDT...");

    gdt.entries[1].access = 0b10011010;
    gdt.entries[1].granularity = 0b11001111;

    gdt.entries[2].access = 0b10010010;

    gdt.entries[3].access = 0b11111010;

    gdt.entries[4].access = 0b11110010;
    gdt.entries[4].granularity = 0b11001111;

    struct gdt_ptr gdtp = {sizeof(gdt) - 1, (uint64_t)&gdt};

    terminal_write("OK\n");
    terminal_write("[SYS/GDT] Flushing GDT to CPU...");

    __asm__ volatile("lgdtq %0" : : "m"(gdtp));

    terminal_write("OK\n");
}
