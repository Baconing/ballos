#include <klibc/string.h>
#include <limits.h>

#define ALIGN (sizeof(size_t))
#define ONES ((size_t)-1 / UCHAR_MAX)
#define HIGHS (ONES * (UCHAR_MAX / 2 + 1))
#define HASZERO(x) (((x)-ONES) & ~(x) & HIGHS)

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

char* ultoa(unsigned long val, char* s, int radix) {
    static const char dig[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char* p, *q;

    q = s;
    do {
        *q++ = dig[val % radix];
        val /= radix;
    } while (val);
    *q = '\0';

    // Reverse the string (but leave the \0)
    p = s;
    q--;

    while (p < q) {
        char c = *p;
        *p++ = *q;
        *q-- = c;
    }

    return s;
}

char* utoa(int val, char* s, int radix) {
    return ultoa(val, s, radix);
}

char* ltoa(long val, char* s, int radix) {
    if (val < 0) {
        *s = '-';
        utoa(-val, s + 1, radix);
    } else {
        utoa(val, s, radix);
    }
    return s;
}

char* itoa(int val, char* s, int radix) {
    return ltoa(val, s, radix);
}