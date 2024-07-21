# This file is a part of ballos (https://github.com/Baconing/ballos).
#
# Copyright (c) 2023 Brenden "Bacon" Freier <iam@baconing.tech>
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
# OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

TARGET = ../../target/libc
TARGET_ARCH = i686

C = /usr/bin/i686-elf-gcc
CPP = /usr/bin/i686-elf-g++
ARCHIVER = /usr/bin/i686-elf-ar
ASSEMBLER = /usr/bin/i686-elf-as
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -c -Iinclude
CPPFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
ASFLAGS =

STRING_OBJS = \
	string/strlen.o \
	string/memmove.o \

OBJS =\
	$(STRING_OBJS) \

.PHONY: all clean

all:libc.a

clean:
	rm -rf **/*.o
	rm -rf $(TARGET)/libc.a
	rm -rf $(OBJS)

libc.a:$(OBJS)
	mkdir -p $(TARGET)
	$(ARCHIVER) rcs $(TARGET)/libc.a $(OBJS)

.c.o:
	$(C) $(CFLAGS) -o $@ $<
.cpp.o:
	$(CPP) $(CPPFLAGS) -o $@ $<
.S.o:
	$(ASSEMBLER) $(ASFLAGS) -o $@ $<