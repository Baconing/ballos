#ifndef SYS_ISR_H
#define SYS_ISR_H

#include <stddef.h>
#include <registers.h>

void isr_install(size_t interrupt, void (*handler)(registers_t *registers));
void isr_init(void);

#endif
