#ifndef SYS_HCF_H
#define SYS_HCF_H

__attribute__((noreturn))
static void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}

#endif
