#include <sys/isr.h>
#include <sys/idt.h>
#include <terminal.h>
#include <klibc/string.h>

void isr_init(void) {
	terminal_write("[SYS/ISR] Installing ISRs...");
	terminal_write("OK\n");
	idt_reload();
}

static const char *isr_exception_messages[] = {"Divide by zero",
											   "Debug",
											   "NMI",
											   "Breakpoint",
											   "Overflow",
											   "Bound Range Exceeded",
											   "Invalid Opcode",
											   "Device Not Available",
											   "Double fault",
											   "Co-processor Segment Overrun",
											   "Invalid TSS",
											   "Segment not present",
											   "Stack-Segment Fault",
											   "GPF",
											   "Page Fault",
											   "Reserved",
											   "x87 Floating Point Exception",
											   "alignment check",
											   "Machine check",
											   "SIMD floating-point exception",
											   "Virtualization Exception",
											   "Deadlock",
											   "Reserved",
											   "Reserved",
											   "Reserved",
											   "Reserved",
											   "Reserved",
											   "Reserved",
											   "Reserved",
											   "Reserved",
											   "Reserved",
											   "Security Exception",
											   "Reserved",
											   "Triple Fault",
											   "FPU error"};

void __attribute__((cdecl)) isr_handle(registers_t *r) {
	if (r->isrNumber < 32) {
			terminal_write("CPU EXCEPTION\n");

			char RIP[17];
			char RBP[17];
		    char RSP[17];
			char RAX[17];
			char RBX[17];
			char RCX[17];
			char RDX[17];
			char RDI[17];
			char RSI[17];
			char R8[17];
			char R9[17];
			char R10[17];
			char R11[17];
			char R12[17];
			char R13[17];
			char R14[17];
			char R15[17];
			char ERR[9];
			char CS[5];
			char SS[5];

			ultoa(r->rip, RIP, 16);
			ultoa(r->rbp, RBP, 16);
			ultoa(r->rsp, RSP, 16);
			ultoa(r->rax, RAX, 16);
			ultoa(r->rbx, RBX, 16);
			ultoa(r->rcx, RCX, 16);
			ultoa(r->rdx, RDX, 16);
			ultoa(r->rdi, RDI, 16);
			ultoa(r->rsi, RSI, 16);
			ultoa(r->r8, R8, 16);
			ultoa(r->r9, R9, 16);
			ultoa(r->r10, R10, 16);
			ultoa(r->r11, R11, 16);
			ultoa(r->r12, R12, 16);
			ultoa(r->r13, R13, 16);
			ultoa(r->r14, R14, 16);
			ultoa(r->r15, R15, 16);
			ultoa(r->errorCode, ERR, 8);
			ultoa(r->cs, CS, 4);
			ultoa(r->ss, SS, 4);

			terminal_write("RIP: "); terminal_write(RIP); terminal_write(" RBP: "); terminal_write(RBP); terminal_write(" RSP: "); terminal_write(RSP); terminal_write("\n");
		    terminal_write("RAX: "); terminal_write(RAX); terminal_write(" RBX: "); terminal_write(RBX); terminal_write(" RCX: "); terminal_write(RCX); terminal_write(" RDX: "); terminal_write(RDX); terminal_write("\n");
			terminal_write("RDI: "); terminal_write(RDI); terminal_write(" RSI: "); terminal_write(RSI); terminal_write(" R8: "); terminal_write(R8); terminal_write(" R9: "); terminal_write(R9); terminal_write("\n");
            terminal_write("R10: "); terminal_write(R10); terminal_write(" R11: "); terminal_write(R11); terminal_write(" R12: "); terminal_write(R12); terminal_write(" R13: "); terminal_write(R13); terminal_write("\n");
			terminal_write("R14: "); terminal_write(R14); terminal_write(" R15: "); terminal_write(R15); terminal_write(" ERR: "); terminal_write(ERR); terminal_write(" CS: "); terminal_write(CS); terminal_write(" SS: "); terminal_write(SS); terminal_write("\n");
			terminal_write("Exception: "); terminal_write(isr_exception_messages[r->isrNumber]); terminal_write("\n");
	}
}
