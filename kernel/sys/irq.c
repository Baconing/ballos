#include <sys/irq.h>
#include <io/ports.h>
#include <terminal.h>

static void PIC_WAIT() {
    do {
        asm volatile("jmp 1f\n\t"
                     "1:jmp 2f\n\t"
                     "2:");
    } while (0);
}

static void (*handlers[32])(registers_t *registers) = { 0 };

static void stub(registers_t *registers) {
    if (registers->int_no <= 47 && registers->int_no >= 32) {
        if (handlers[registers->int_no - 32]) {
            handlers[registers->int_no - 32](registers);
        }
    }

    if (registers->int_no >= 0x40) {
        outb(PIC2, PIC_EOI);
    }

    outb(PIC1, PIC_EOI);
}

static void irq_remap() {
    uint8_t mask1 = inb(PIC1_DATA);
    uint8_t mask2 = inb(PIC2_DATA);

    outb(PIC1, ICW1_INIT | ICW1_ICW4);
    outb(PIC2, ICW1_INIT | ICW1_ICW4);
    outb(PIC1_DATA, PIC1_OFFSET);
    outb(PIC2_DATA, PIC2_OFFSET);
    outb(PIC1_DATA, 4);
    outb(PIC2_DATA, 2);
    outb(PIC1_DATA, PIC_MODE_8086);
    outb(PIC2_DATA, PIC_MODE_8086);
    outb(PIC1_DATA, mask1);
    outb(PIC2_DATA, mask2);
}

static void irq_set_mask(size_t irq) {
    uint16_t port = irq < 8 ? PIC1_DATA : PIC2_DATA;
    uint8_t value = inb(port) | (1 << irq);

    outb(port, value);
}

static void irq_clear_mask(size_t irq) {
    uint16_t port = irq < 8 ? PIC1_DATA : PIC2_DATA;
    uint8_t value = inb(port) & ~(1 << irq);

    outb(port, value);
}

void irq_install(size_t irq, void (*handler)(registers_t *registers)) {
    asm volatile("cli");
    handlers[irq] = handler;
    irq_clear_mask(irq);
    asm volatile("sti");
}

void irq_init() {
    terminal_write("[SYS/IRQ] Initializing IRQs...");
    irq_remap();

    for (size_t i = 0; i < 16; i++) {
        irq_install(i + 32, stub);
    }

    terminal_write("OK\n");
}
