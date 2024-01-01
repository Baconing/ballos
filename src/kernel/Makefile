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

C = /usr/bin/i686-elf-gcc
CPP = /usr/bin/i686-elf-g++
LINKER = /usr/bin/i686-elf-ld
ASSEMBLER = /usr/bin/i686-elf-as
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -c -Iinclude
CPPFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
LDFLAGS = -T boot/link.ld -ffreestanding -O2 -nostdlib -lgcc
ASFLAGS =

TARGET = ../../target

OBJS =\
 $(TARGET)/obj/boot.o \
 $(TARGET)/obj/kernel.o \
 $(TARGET)/obj/system.o \
 $(TARGET)/obj/serial.o \
 $(TARGET)/obj/terminal.o \
 $(TARGET)/obj/vga.o \
 $(TARGET)/obj/string.o \

all:$(OBJS)
	mkdir -p $(TARGET)
	$(C) $(LDFLAGS) -o $(TARGET)/kernel.bin $(OBJS)

$(TARGET)/obj/boot.o:boot/boot.S
	mkdir -p $(TARGET)/obj/
	$(ASSEMBLER) $(ASFLAGS) -o $(TARGET)/obj/boot.o boot/boot.S

$(TARGET)/obj/kernel.o:kernel.c
	mkdir -p $(TARGET)/obj/
	$(C) $(CFLAGS) -o $(TARGET)/obj/kernel.o kernel.c

$(TARGET)/obj/system.o:cpu/system.c
	mkdir -p $(TARGET)/obj/
	$(C) $(CFLAGS) -o $(TARGET)/obj/system.o cpu/system.c

$(TARGET)/obj/serial.o:serial/serial.c
	mkdir -p $(TARGET)/obj/
	$(C) $(CFLAGS) -o $(TARGET)/obj/serial.o serial/serial.c

$(TARGET)/obj/terminal.o:terminal/terminal.c
	mkdir -p $(TARGET)/obj/
	$(C) $(CFLAGS) -o $(TARGET)/obj/terminal.o terminal/terminal.c

$(TARGET)/obj/vga.o:vga/vga.c
	mkdir -p $(TARGET)/obj/
	$(C) $(CFLAGS) -o $(TARGET)/obj/vga.o vga/vga.c

$(TARGET)/obj/string.o:string/string.c
	mkdir -p $(TARGET)/obj/
	$(C) $(CFLAGS) -o $(TARGET)/obj/string.o string/string.c