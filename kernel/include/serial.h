#include <io.h>

#ifndef SERIAL_H
#define SERIAL_H

#define PORT 0x3f8

int serial_init(void);

int serial_received(void);
char read_serial(void);

int is_transmit_empty(void);
void write_serial(char character);
void write_string_serial(const char *string);

#endif //SERIAL_H
