#include <registers.h>

#ifndef ISR_H
#define ISR_H

void isr_handle(registers_t *registers);

__attribute__((noreturn))
void isr_exception(registers_t *registers);

#endif //ISR_H
