/*
 This file is a part of ballos (https://github.com/Baconing/ballos).

 Copyright (c) 2023 Brenden "Bacon" Freier <iam@baconing.tech>

 Permission to use, copy, modify, and/or distribute this software for any
 purpose with or without fee is hereby granted, provided that the above
 copyright notice and this permission notice appear in all copies.

 THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 PERFORMANCE OF THIS SOFTWARE.
 */

#include <stddef.h>

#ifndef __LIBC_STRING
#define __LIBC_STRING

#ifdef __cplusplus
extern "C" {
#endif

/*
    The memcpy function copies n characters from the object pointed to by s2 into the
    object pointed to by s1. If copying takes place between objects that overlap, the behavior
    is undefined.

    The memcpy function returns the value of s1.
*/
void *memcpy(void * restrict s1, const void * restrict s2, size_t n);

/*
    The memmove function copies n characters from the object pointed to by s2 into the
    object pointed to by s1. Copying takes place as if the n characters from the object
    pointed to by s2 are first copied into a temporary array of n characters that does not
    overlap the objects pointed to by s1 and s2, and then the n characters from the
    temporary array are copied into the object pointed to by s1.

    The memmove function returns the value of s1.
*/
void *memmove(void *s1, const void *s2, size_t n);

/*
    The strcpy function copies the string pointed to by s2 (including the terminating null
    character) into the array pointed to by s1. If copying takes place between objects that
    overlap, the behavior is undefined.

    The strcpy function returns the value of s1.
*/
char *strcpy(char * restrict s1, const char * restrict s2);

/*
    The strncpy function copies not more than n characters (characters that follow a null
    character are not copied) from the array pointed to by s2 to the array pointed to by s1.
    If copying takes place between objects that overlap, the behavior is undefined.
    If the array pointed to by s2 is a string that is shorter than n characters, null characters
    are appended to the copy in the array pointed to by s1, until n characters in all have been
    written.

    The strncpy function returns the value of s1.
*/
char *strncpy(char * restrict s1, const char * restrict s2, size_t n);

/*
    The strcat function appends a copy of the string pointed to by s2 (including the
    terminating null character) to the end of the string pointed to by s1. The initial character
    of s2 overwrites the null character at the end of s1. If copying takes place between
    objects that overlap, the behavior is undefined.

    The strcat function returns the value of s1.
*/
char *strcat(char * restrict s1, const char * restrict s2);

/*
    The strncat function appends not more than n characters (a null character and
    characters that follow it are not appended) from the array pointed to by s2 to the end of
    the string pointed to by s1. The initial character of s2 overwrites the null character at the
    end of s1. A terminating null character is always appended to the result. If copying takes place
    between objects that overlap, the behavior is undefined.

    The strncat function returns the value of s1.
*/
char *strncat(char * restrict s1, const char * restrict s2, size_t n);

/*
    The memcmp function compares the first n characters of the object pointed to by s1 to
    the first n characters of the object pointed to by s2.

    The memcmp function returns an integer greater than, equal to, or less than zero,
    accordingly as the object pointed to by s1 is greater than, equal to, or less than the object
    pointed to by s2.
*/
int memcmp(const void *s1, const void *s2, size_t n);

/*
    The strcmp function compares the string pointed to by s1 to the string pointed to by s2.

    The strcmp function returns an integer greater than, equal to, or less than zero,
    accordingly as the string pointed to by s1 is greater than, equal to, or less than
    the string pointed to by s2.
*/
int strcmp(const char *s1, const char *s2);

/*
    The strcoll function compares the string pointed to by s1 to the string pointed to by
    s2, both interpreted as appropriate to the LC_COLLATE category of the current locale.

    The strcoll function returns an integer greater than, equal to, or less than zero,
    accordingly as the string pointed to by s1 is greater than, equal to, or less than the string
    pointed to by s2 when both are interpreted as appropriate to the current locale.
*/
int strcoll(const char *s1, const char *s2);

/*
    The strncmp function compares not more than n characters (characters that follow a
    null character are not compared) from the array pointed to by s1 to the array pointed to
    by s2.

    The strncmp function returns an integer greater than, equal to, or less than zero,
    accordingly as the possibly null-terminated array pointed to by s1 is greater than, equal
    to, or less than the possibly null-terminated array pointed to by s2.
*/
int strncmp(const char *s1, const char *s2, size_t n);

/*
    The strxfrm function transforms the string pointed to by s2 and places the resulting
    string into the array pointed to by s1. The transformation is such that if the strcmp
    function is applied to two transformed strings, it returns a value greater than, equal to, or
    less than zero, corresponding to the result of the strcoll function applied to the same
    two original strings. No more than n characters are placed into the resulting array
    pointed to by s1, including the terminating null character. If n is zero, s1 is permitted to
    be a null pointer. If copying takes place between objects that overlap, the behavior is
    undefined.

    The strxfrm function returns the length of the transformed string (not including the
    terminating null character). If the value returned is n or more, the contents of the array
    pointed to by s1 are indeterminate.
*/
size_t strxfrm(char * restrict s1, const char * restrict s2, size_t n);

/*
    The memchr function locates the first occurrence of c (converted to an unsigned
    char) in the initial n characters (each interpreted as unsigned char) of the object
    pointed to by s. The implementation shall behave as if it reads the characters sequentially
    and stops as soon as a matching character is found.

    The memchr function returns a pointer to the located character, or a null pointer if the
    character does not occur in the object.
*/
void *memchr(const void *s, int c, size_t n);

/*
    The strchr function locates the first occurrence of c (converted to a char) in the string
    pointed to by s. The terminating null character is considered to be part of the string.

    The strchr function returns a pointer to the located character, or a null pointer if the
    character does not occur in the string.
*/
char *strchr(const char *s, int c);

/*
    The strcspn function computes the length of the maximum initial segment of the string
    pointed to by s1 which consists entirely of characters not from the string pointed to by s2.

    The strcspn function returns the length of the segment.
*/
size_t strcspn(const char *s1, const char *s2);

/*
    The strpbrk function locates the first occurrence in the string pointed to by s1 of any
    character from the string pointed to by s2.

    The strpbrk function returns a pointer to the character, or a null pointer if no character
    from s2 occurs in s1.
*/
char *strpbrk(const char *s1, const char *s2);

/*
    The strrchr function locates the last occurrence of c (converted to a char) in the string
    pointed to by s. The terminating null character is considered to be part of the string.

    The strrchr function returns a pointer to the located character, or a null pointer if the
    character does not occur in the string.
*/
size_t strrchr(const char *s, int c);

/*
    The strspn function computes the length of the maximum initial segment of the string
    pointed to by s1 which consists entirely of characters from the string pointed to by s2.

    The strspn function returns the length of the segment.
*/
size_t strspn(const char *s1, const char *s2);

/*
    The strstr function locates the first occurrence in the string pointed to by s1 of the
    sequence of characters (excluding the terminating null character) in the string pointed to
    by s2.

    The strstr function returns a pointer to the located string, or a null pointer if the string
    is not found. If s2 points to a string with zero length, the function returns s1.
*/
char *strstr(const char *s1, const char *s2);

/*
    A sequence of calls to the strtok function breaks the string pointed to by s1 into a
    sequence of tokens, each of which is delimited by a character from the string pointed to
    by s2. The first call in the sequence has a non-null first argument; subsequent calls in the
    sequence have a null first argument. The separator string pointed to by s2 may be
    different from call to call.

    The first call in the sequence searches the string pointed to by s1 for the first character
    that is not contained in the current separator string pointed to by s2. If no such character
    is found, then there are no tokens in the string pointed to by s1 and the strtok function
    returns a null pointer. If such a character is found, it is the start of the first token.

    The strtok function then searches from there for a character that is contained in the
    current separator string. If no such character is found, the current token extends to the
    end of the string pointed to by s1, and subsequent searches for a token will return a null
    pointer. If such a character is found, it is overwritten by a null character, which
    terminates the current token. The strtok function saves a pointer to the following
    character, from which the next search for a token will start.

    Each subsequent call, with a null pointer as the value of the first argument, starts
    searching from the saved pointer and behaves as described above.

    The strtok function is not required to avoid data races with other calls to the strtok
    function. The implementation shall behave as if no library function calls the strtok
    function.

    The strtok function returns a pointer to the first character of a token, or a null pointer
    if there is no token.
*/
char *strtok(char * restrict s1, const char * restrict s2);

/*
    The memset function copies the value of c (converted to an unsigned char) into
    each of the first n characters of the object pointed to by s.

    The memset function returns the value of s.
*/
void *memset(void *s, int c, size_t n);

/*
    The strerror function maps the number in errnum to a message string. Typically,
    the values for errnum come from errno, but strerror shall map any value of type
    int to a message.

    The strerror function is not required to avoid data races with other calls to the
    strerror function. The implementation shall behave as if no library function calls
    the strerror function.

    The strerror function returns a pointer to the string, the contents of which are locale-
    specific. The array pointed to shall not be modified by the program, but may be
    overwritten by a subsequent call to the strerror function.
*/
char *strerror(int errnum);

/*
    The strlen function computes the length of the string pointed to by s.

    The strlen function returns the number of characters that precede the terminating null
    character.
*/
size_t strlen(const char *s);


#ifdef __cplusplus
}
#endif

#endif