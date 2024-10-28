#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>
#include <io/serial.h>
#include <video/fb.h>
#include <input/keyboard.h>
#include <sys/hcf.h>
#include <sys/irq.h>
#include <sys/isr.h>
#include <sys/idt.h>
#include <sys/fpu.h>
#include <sys/gdt.h>
#include <mm/paging.h>
#include <mm/mmap.h>
#include <mm/mem.h>
#include <terminal.h>

__attribute__((used, section(".requests")))
static volatile LIMINE_BASE_REVISION(2);

// Finally, define the start and end markers for the Limine requests.
// These can also be moved anywhere, to any .c file, as seen fit.

__attribute__((used, section(".requests_start_marker")))
static volatile LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".requests_end_marker")))
static volatile LIMINE_REQUESTS_END_MARKER;

void *memcpy(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    for (size_t i = 0; i < n; i++) {
        pdest[i] = psrc[i];
    }

    return dest;
}

void *memset(void *s, int c, size_t n) {
    uint8_t *p = (uint8_t *)s;

    for (size_t i = 0; i < n; i++) {
        p[i] = (uint8_t)c;
    }

    return s;
}

void *memmove(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;

    if (src > dest) {
        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
        }
    } else if (src < dest) {
        for (size_t i = n; i > 0; i--) {
            pdest[i-1] = psrc[i-1];
        }
    }

    return dest;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *p1 = (const uint8_t *)s1;
    const uint8_t *p2 = (const uint8_t *)s2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] < p2[i] ? -1 : 1;
        }
    }

    return 0;
}

void _start(void) {
    asm("cli");

    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        hcf();
    }

    serial_init();
    fb_init();

    fpu_init();
    gdt_init();
    idt_init();
    isr_init();
    irq_init();
    keyboard_init();
    //paging_init();
    mmap_init();
    mem_init();

    terminal_write("[TEST/KMALLOC] Testing kmalloc...");
    int *ptr;
    ptr = (int *)kmalloc(sizeof(int));

    if (ptr == NULL) {
        terminal_write("ERROR (kmalloc returned NULL)\n");
    } else {
        terminal_write("OK\n");
    }

    terminal_write("[TEST/KFREE] Testing kfree...");
    kfree(ptr);
    terminal_write("OK\n");

    /*
    terminal_write("[TEST/FPU] Testing FPU...");
    float a = 1.0, b = 2.0, c;
    c = a + b;
    if (c != 3.0) {
        terminal_write("ERROR\n");
    } else {
        terminal_write("OK\n");
    }
    */

    asm("sti");

    asm ("int $0x02");

    hcf();
}
