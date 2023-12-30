C = /usr/bin/i686-elf-gcc
CPP = /usr/bin/i686-elf-g++
LINKER = /usr/bin/i686-elf-ld
ASSEMBLER = /usr/bin/i686-elf-as
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -c
CPPFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
ASFLAGS = 
LDFLAGS = -T boot/link.ld -ffreestanding -O2 -nostdlib -lgcc

TARGET = ../../target

OBJS = $(TARGET)/obj/boot.o $(TARGET)/obj/kernel.o

all:$(OBJS)
	mkdir -p $(TARGET)
	$(C) $(LDFLAGS) -o $(TARGET)/kernel.bin $(OBJS)

$(TARGET)/obj/boot.o:boot/boot.S
	mkdir -p $(TARGET)/obj/
	$(ASSEMBLER) $(ASFLAGS) -o $(TARGET)/obj/boot.o boot/boot.S

$(TARGET)/obj/kernel.o:kernel.c
	mkdir -p $(TARGET)/obj/
	$(C) $(CFLAGS) -o $(TARGET)/obj/kernel.o kernel.c
