#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>

void terminal_write(const char *string);
void terminal_write_char(char c);
void terminal_write_dec(uint64_t value);
void terminal_write_hex(uint64_t value);

#endif
