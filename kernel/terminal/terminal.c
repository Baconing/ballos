#include <terminal.h>
#include <video/fb.h>
#include <io/serial.h>
#include <klibc/string.h>

void terminal_write(const char *string) {
    write_string_serial(string);
    if (fb_available()) fb_write(string);
}

void terminal_write_char(char c) {
    write_serial(c);
    if (fb_available()) fb_write_char(c);
}

void terminal_write_dec(uint64_t value) {
    char buffer[21];
    ultoa(value, buffer, 10);
    terminal_write(buffer);
}

void terminal_write_hex(uint64_t value) {
    char buffer[17];
    ultoa(value, buffer, 16);
    terminal_write(buffer);
}
