#include <input/keyboard.h>
#include <sys/irq.h>
#include <io/ports.h>
#include <terminal.h>

static void keyboard_handler(registers_t *registers) {
    char scancode = inb(0x60);

    terminal_write_char(scancode);
}

void keyboard_init(void) {
    irq_install(1, keyboard_handler);
}
