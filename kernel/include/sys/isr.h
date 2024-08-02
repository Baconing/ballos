#ifndef SYS_ISR_H
#define SYS_ISR_H

#include <registers.h>

void isr_init(void);
void __attribute__((cdecl)) isr_handle(registers_t *r);

#endif
