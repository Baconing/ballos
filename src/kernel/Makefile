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

TARGET = ../../target/kernel
TARGET_ARCH = x86
TARGET_ARCH_DIR = arch/$(TARGET_ARCH)

C = /usr/bin/i686-elf-gcc
CPP = /usr/bin/i686-elf-g++
LINKER = /usr/bin/i686-elf-ld
ASSEMBLER = /usr/bin/i686-elf-as
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -c -g -Iinclude
CPPFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
LDFLAGS = -T arch/$(TARGET_ARCH)/boot/link.ld -ffreestanding -O2 -nostdlib -lgcc
ASFLAGS =

ARCH_OBJS =\
	$(TARGET_ARCH_DIR)/boot/boot.o \
	$(TARGET_ARCH_DIR)/cpu/system.o \
	$(TARGET_ARCH_DIR)/vga/vga.o \

OBJS =\
	$(ARCH_OBJS) \
	kernel.o \
	serial/serial.o \
 	string/string.o \
	terminal/terminal.o

.PHONY: all clean

all:kernel.bin

clean:
	rm -rf **/*.o
	rm -rf $(TARGET)/kernel.bin
	rm -rf $(OBJS)

kernel.bin:$(OBJS)
	mkdir -p $(TARGET)
	$(C) $(LDFLAGS) -o $(TARGET)/kernel.bin $(OBJS)

.c.o:
	$(C) $(CFLAGS) -o $@ $<
.cpp.o:
	$(CPP) $(CPPFLAGS) -o $@ $<
.S.o:
	$(ASSEMBLER) $(ASFLAGS) -o $@ $<