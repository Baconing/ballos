#ifndef KLIBC_STRING_H
#define KLIBC_STRING_H

//#include <string.h>
#include <stdint.h>
#include <stddef.h>

size_t strlen(const char *s);
char *ltoa(int64_t value, char *str, int base);
char *ultoa(uint64_t value, char *str, int base);
int64_t atol(const char *string);

#endif
