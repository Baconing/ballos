override MAKEFLAGS += -rR
override KERNEL := ballos
override IMAGE := ballos.iso

define DEFAULT_VAR =
    ifeq ($(origin $1),default)
        override $(1) := $(2)
    endif
    ifeq ($(origin $1),undefined)
        override $(1) := $(2)
    endif
endef

override DEFAULT_KCC := cc
$(eval $(call DEFAULT_VAR,KCC,$(DEFAULT_KCC)))

override DEFAULT_KLD := ld
$(eval $(call DEFAULT_VAR,KLD,$(DEFAULT_KLD)))

override DEFAULT_KCFLAGS := -g -O2 -pipe
$(eval $(call DEFAULT_VAR,KCFLAGS,$(DEFAULT_KCFLAGS)))

override DEFAULT_KCPPFLAGS :=
$(eval $(call DEFAULT_VAR,KCPPFLAGS,$(DEFAULT_KCPPFLAGS)))

override DEFAULT_KNASMFLAGS := -F dwarf -g
$(eval $(call DEFAULT_VAR,KNASMFLAGS,$(DEFAULT_KNASMFLAGS)))

override DEFAULT_KLDFLAGS :=
$(eval $(call DEFAULT_VAR,KLDFLAGS,$(DEFAULT_KLDFLAGS)))

override KCFLAGS += \
    -Wall \
    -Wextra \
    -std=gnu11 \
    -ffreestanding \
    -fno-stack-protector \
    -fno-stack-check \
    -fno-lto \
    -fPIE \
    -m64 \
    -march=x86-64 \
    -mno-80387 \
    -mno-mmx \
    -mno-sse \
    -mno-sse2 \
    -mno-red-zone

override KCPPFLAGS := \
    -I kernel/include \
    $(KCPPFLAGS) \
    -MMD \
    -MP

override KLDFLAGS += \
    -m elf_x86_64 \
    -nostdlib \
    -pie \
    -z text \
    -z max-page-size=0x1000 \
    -T linker.ld

override KNASMFLAGS += \
    -Wall \
    -f elf64

override CFILES := $(shell cd kernel && find -L * -type f -name '*.c')
override ASFILES := $(shell cd kernel && find -L * -type f -name '*.S')
override NASMFILES := $(shell cd kernel && find -L * -type f -name '*.asm')
override FONTS := $(shell cd kernel && find -L resources -type f -name '*.psf')
override OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(ASFILES:.S=.S.o) $(NASMFILES:.asm=.asm.o) $(FONTS:.psf=.psf.o))
override HEADER_DEPS := $(addprefix obj/,$(CFILES:.c=.c.d) $(ASFILES:.S=.S.d))

.PHONY: all
all: qemu

qemu: obj/${IMAGE}
	qemu-system-x86_64 -cdrom obj/${IMAGE}

obj/${IMAGE}: obj/$(KERNEL)
	mkdir -p iso/boot/limine
	cp obj/$(KERNEL) iso/boot
	cp -v limine.cfg limine/limine-bios.sys limine/limine-bios-cd.bin \
	    limine/limine-uefi-cd.bin iso/boot/limine/
	mkdir -p iso/EFI/BOOT
	cp -v limine/BOOTX64.EFI iso/EFI/BOOT/
	cp -v limine/BOOTIA32.EFI iso/EFI/BOOT/
	xorriso -as mkisofs -b boot/limine/limine-bios-cd.bin \
	    -no-emul-boot -boot-load-size 4 -boot-info-table \
	    --efi-boot boot/limine/limine-uefi-cd.bin \
	    -efi-boot-part --efi-boot-image --protective-msdos-label \
	    iso -o obj/${IMAGE}
	limine bios-install obj/${IMAGE}

obj/$(KERNEL): GNUmakefile linker.ld $(OBJ)
	mkdir -p "$$(dirname $@)"
	$(KLD) $(OBJ) $(KLDFLAGS) -o $@
	printf '\003' | dd of=$@ bs=1 count=1 seek=16 conv=notrunc 2>/dev/null

-include $(HEADER_DEPS)

obj/%.psf.o: kernel/%.psf GNUmakefile
	mkdir -p "$$(dirname $@)"
	objcopy -O elf64-x86-64 -B i386 -I binary $< $@

obj/%.c.o: kernel/%.c GNUmakefile
	mkdir -p "$$(dirname $@)"
	$(KCC) $(KCFLAGS) $(KCPPFLAGS) -c $< -o $@

obj/%.S.o: kernel/%.S GNUmakefile
	mkdir -p "$$(dirname $@)"
	$(KCC) $(KCFLAGS) $(KCPPFLAGS) -c $< -o $@

obj/%.asm.o: kernel/%.asm GNUmakefile
	mkdir -p "$$(dirname $@)"
	nasm $(KNASMFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf bin obj
