#include <terminal.h>
#include <video/fb.h>
#include <io/serial.h>

void terminal_write(const char *string) {
    write_string_serial(string);
    if (fb_available()) fb_write(string);
}

void terminal_write_char(char c) {
    write_serial(c);
    if (fb_available()) fb_write_char(c);
}
