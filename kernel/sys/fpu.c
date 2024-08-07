#include <sys/fpu.h>
#include <terminal.h>
#include <stddef.h>

void fpu_init() {
    terminal_write("[SYS/FPU] Initializing FPU...");

    size_t cr0;

    asm __volatile__("clts");
    asm __volatile__("mov %%cr0, %0" : "=r"(cr0));
    cr0 &= ~(1 << 2);
    cr0 |= (1 << 1);
    asm __volatile__("mov %0, %%cr0" : : "r"(cr0));
    asm __volatile__("fninit");

    terminal_write("OK\n");
}
