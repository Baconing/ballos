#include <string.h>

size_t strlen(const char *s) {
    const char *a = s;
#ifdef __GNUC__
    typedef size_t __attribute__((__may_alias__)) word;
    const word *w;
    for (; (uintptr_t)s % ALIGN; s++)
        if (!*s)
            return s - a;
    for (w = (const void *)s; !HASZERO(*w); w++)
        ;
    s = (const void *)w;
#endif
    for (; *s; s++)
        ;
    return s - a;
}

char *ltoa(int64_t value, char *str, int base) {
    char *rc;
    char *ptr;
    char *low;
    // Check for supported base.
    if (base < 2 || base > 36) {
        *str = '\0';
        return str;
    }
    rc = ptr = str;
    // Set '-' for negative decimals.
    if (value < 0 && base == 10) {
        *ptr++ = '-';
    }
    // Remember where the numbers start.
    low = ptr;
    // The actual conversion.
    do {
        // Modulo is negative for negative value. This trick makes abs()
        // unnecessary.
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnop"
                 "qrstuvwxyz"[35 + value % base];
        value /= base;
    } while (value);
    // Terminating the string.
    *ptr-- = '\0';
    // Invert the numbers.
    while (low < ptr) {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }
    return rc;
}

char *ultoa(uint64_t value, char *str, int base) {
    char *rc;
    char *ptr;
    char *low;
    // Check for supported base.
    if (base < 2 || base > 36) {
        *str = '\0';
        return str;
    }
    rc = ptr = str;
    // Remember where the numbers start.
    low = ptr;
    // The actual conversion.
    do {
        *ptr++ = "0123456789abcdefghijklmnop"
                 "qrstuvwxyz"[value % base];
        value /= base;
    } while (value);
    // Terminating the string.
    *ptr-- = '\0';
    // Invert the numbers.
    while (low < ptr) {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }
    return rc;
}

int64_t atol(const char *string) {
    long num = 0;
    int i = 0, sign = 1;

    // skip white space characters
    while (string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
        i++;
    }

    // note sign of the number
    if (string[i] == '+' || string[i] == '-') {
        if (string[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // run till the end of the string is reached, or the
    // current character is non-numeric
    while (string[i] && (string[i] >= '0' && string[i] <= '9')) {
        num = num * 10 + (string[i] - '0');
        i++;
    }

    return sign * num;
}