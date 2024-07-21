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

#ifndef __LIBC_STDINT
#define __LIBC_STDINT

#define INT8_MIN (-128)
#define INT8_MAX (127)
#define UINT8_MAX (255)
typedef signed char int8_t;
typedef unsigned char uint8_t;

#define INT16_MIN (-32768)
#define INT16_MAX (32767)
#define UINT16_MAX (65535)
typedef signed short int16_t;
typedef unsigned short uint16_t;

#define INT32_MIN (-2147483648)
#define INT32_MAX (2147483647)
#define UINT32_MAX (4294967295)
typedef signed int int32_t;
typedef unsigned int uint32_t;

#define INT64_MIN (-9223372036854775808)
#define INT64_MAX (9223372036854775807)
#define UINT64_MAX (18446744073709551615)
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

#define INTPTR_MIN (-2147483648)
#define INTPTR_MAX (2147483647)
#define UINTPTR_MAX (4294967295)
typedef signed long intptr_t;
typedef unsigned long uintptr_t;

#define INTMAX_MIN (-9223372036854775808)
#define INTMAX_MAX (9223372036854775807)
#define UINTMAX_MAX (18446744073709551615)
typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;

#define INT_LEAST8_MIN (-128)
#define INT_LEAST8_MAX (127)
#define UINT_LEAST8_MAX (255)
typedef int8_t int_least8_t;
typedef uint8_t uint_least8_t;

#define INT_LEAST16_MIN (-32768)
#define INT_LEAST16_MAX (32767)
#define UINT_LEAST16_MAX (65535)
typedef int16_t int_least16_t;
typedef uint16_t uint_least16_t;

#define INT_LEAST32_MIN (-2147483648)
#define INT_LEAST32_MAX (2147483647)
#define UINT_LEAST32_MAX (4294967295)
typedef int32_t int_least32_t;
typedef uint32_t uint_least32_t;

#define INT_LEAST64_MIN (-9223372036854775808)
#define INT_LEAST64_MAX (9223372036854775807)
#define UINT_LEAST64_MAX (18446744073709551615)
typedef int64_t int_least64_t;
typedef uint64_t uint_least64_t;

#define INT_FAST8_MIN (-128)
#define INT_FAST8_MAX (127)
#define UINT_FAST8_MAX (255)
typedef int8_t int_fast8_t;
typedef uint8_t uint_fast8_t;

#define INT_FAST16_MIN (-32768)
#define INT_FAST16_MAX (32767)
#define UINT_FAST16_MAX (65535)
typedef int16_t int_fast16_t;
typedef uint16_t uint_fast16_t;

#define INT_FAST32_MIN (-2147483648)
#define INT_FAST32_MAX (2147483647)
#define UINT_FAST32_MAX (4294967295)
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast32_t;

#define INT_FAST64_MIN (-9223372036854775808)
#define INT_FAST64_MAX (9223372036854775807)
#define UINT_FAST64_MAX (18446744073709551615)
typedef int64_t int_fast64_t;
typedef uint64_t uint_fast64_t;

#endif