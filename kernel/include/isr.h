//
// Created by bacon on 7/31/24.
//

#ifndef ISR_H
#define ISR_H

#include <stdint.h>
#include <registers.h>

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();

void isr_init(void);
void __attribute__((cdecl)) isr_handle(registers_t *r);

#endif //ISR_H
