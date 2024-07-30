//
// Created by bacon on 7/28/24.
//

#ifndef HCF_H
#define HCF_H

__attribute__((noreturn))
static void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}

#endif //HCF_H
