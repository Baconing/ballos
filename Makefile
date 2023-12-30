all:qemu

qemu:iso
	qemu-system-i386 -cdrom target/boot.iso

iso:kernel
	cp target/kernel.bin target/iso/boot 
	grub-mkrescue -o target/boot.iso target/iso

kernel:
	@$(MAKE) -C src/kernel all
