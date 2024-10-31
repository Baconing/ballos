#include <sys/gdt.h>
#include <stdint.h>
#include <terminal.h>

struct gdt_entry {
    uint16_t limit; // 16 Bit Limit
    uint16_t base_low; // Lower 16 Bit Base
    uint8_t base_middle; // Higher 8 Bit Base.

    // 8-Bit Access Byte Described as:
    // Present Bit (1 for any valid segment).
    // 2-Bit DPL - Ring level, 0-3.
    // Descriptor type bit - 0 for system segment, 1 for code/data segment.
    // Executable bit - 0 for data segment, 1 for code segment (e.g. executable).
    // DC Bit -
    //      Data Segments: 0 for grows up, 1 for grows down (offset is greater than limit.
    //      Code Segments: 0 - the segment can only be executed by the ring set in the DPL. 1 - the segment can be executed from an equal or lower ring.
    // RW Bit -
    //      Code Segments: 0 for no read access, 1 for read access. Writing is never allowed.
    //      Data Segments: 0 for no writing access, 1 for writing access. Read access is always allowed.
    uint8_t access;

    // Section Flags, lower 4 bits padded as limit.
    // Granularity Flag - 0 for 1 byte blocks for limit, 1 for 4 KiB blocks for limit.
    // Size Flag - 0 for 16-bit protected mode segment, 1 for 32-bit protected mode segment.
    // Log-mode Code Flag - 0 if this is not a 64-bit long mode code segment (should be for anything other than code segment), 1 for a 64-bit long mode code segment (size flag should be 0 if this is 1).
    // Reserved Flag, set to 0.
    // Last 4 bits are the remaning bits of the limit, should probably be 0b1111.
    uint8_t flags; // Higher 4 Bit Limit + 4 Bit Flags.
    uint8_t base_high; // Remaining Base (8 Bit).
} __attribute__((packed));

struct gdt_ptr {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed));

struct gdtr {
    struct gdt_entry entries[5];
} __attribute__((packed));

struct gdtr gdt = { 0 };
struct gdt_ptr gdtp;
extern void gdt_flush();

void gdt_init() {
    terminal_write("[SYS/GDT] Initializing GDT...");

    // Kernel Code Segment
    gdt.entries[1].base_low = 0;
    gdt.entries[1].base_middle = 0;
    gdt.entries[1].base_high = 0;
    gdt.entries[1].limit = 0xFFFFF;
    // Present = Yes | DPL = Ring 0 | Descriptor = Code/Data | Executable = Yes | Conforming = Ring 0 Only | Reading = Yes
    gdt.entries[1].access = 0b10011010;
    // Granularity = 4 KiB Limit Blocks | Size = 64-bit Long Mode | Long Mode Code = Yes | Reserved | Limit
    gdt.entries[1].flags = 0b10101111;

    // Kernel Data Segment
    gdt.entries[2].base_low = 0;
    gdt.entries[2].base_middle = 0;
    gdt.entries[2].base_high = 0;
    gdt.entries[2].limit = 0xFFFFF;
    // Present = Yes | DPL = Ring 0. | Descriptor = Code/Data | Executable = No | Conforming = Ring 0 Only. | Writing = Yes
    gdt.entries[2].access = 0b10010110;
    // Granularity = 4 KiB Limit Blocks | Size Flag = 32-bit Protected Mode | Long Mode Code = No | Reserved | Limit
    gdt.entries[2].flags = 0b11001111; // 4 bytes padding. 

    // GDT Flushing.
    gdtp.limit = sizeof(gdt) - 1;
    gdtp.base = (uint64_t)&gdt;

    terminal_write("OK\n");
    terminal_write("[SYS/GDT] Flushing GDT to CPU...");

    gdt_flush();

    terminal_write("OK\n");
}
