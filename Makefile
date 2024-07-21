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

all:libc qemu

qemu:iso
	qemu-system-i386 -s -cdrom target/boot.iso

iso:kernel
	cp target/kernel/kernel.bin target/iso/boot
	grub-mkrescue -o target/boot.iso target/iso

kernel:
	@$(MAKE) -C src/kernel all

libc:
	@$(MAKE) -C src/libc all

clean:
	@$(MAKE) -C src/kernel clean
	@$(MAKE) -C src/libc clean
	rm -rf target/kernel/*
	rm -rf target/libc/*
	rm -rf target/boot.iso
	rm -rf target/iso/boot/kernel.bin
	rm -rf target/kernel.bin