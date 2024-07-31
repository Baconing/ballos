//
// Created by bacon on 7/31/24.
//

#include <pic.h>
#include <io.h>
#include <terminal.h>

void pic_init(void) {
    terminal_write("[PIC] Initializing PIC...");
	outb(0x20, 0x11);
	outb(0xA0, 0x11);
	outb(0x21, 0x20);
	outb(0xA1, 0x28);
	outb(0x21, 4);
	outb(0xA1, 2);
	outb(0x21, 1);
	outb(0xA1, 1);
	outb(0x21, 0);
	outb(0xA1, 0);
    terminal_write("OK\n");
}

void pic_disable(void) {
    terminal_write("[PIC] Disabling PIC...");
    outb(0xA1, 0xFF);
    outb(0x21, 0xFF);
    terminal_write("OK\n");
}
