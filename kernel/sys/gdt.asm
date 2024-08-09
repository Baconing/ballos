extern gdtp
global gdt_flush

gdt_flush:
    lgdt [rel gdtp]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret