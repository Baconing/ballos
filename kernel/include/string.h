//
// Created by bacon on 7/31/24.
//

#ifndef STRING_H
#define STRING_H

#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>

#define ALIGN (sizeof(size_t))
#define ONES ((size_t)-1 / UCHAR_MAX)
#define HIGHS (ONES * (UCHAR_MAX / 2 + 1))
#define HASZERO(x) (((x)-ONES) & ~(x) & HIGHS)

size_t strlen(const char *s);
char *ltoa(int64_t value, char *str, int base);
char *ultoa(uint64_t value, char *str, int base);
int64_t atol(const char *string);

#endif //STRING_H
