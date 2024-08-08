#include <sys/isr.h>
#include <sys/idt.h>
#include <sys/hcf.h>
#include <terminal.h>

#define NUM_ISR 256

extern void isr0(registers_t *regs);
extern void isr1(registers_t *regs);
extern void isr2(registers_t *regs);
extern void isr3(registers_t *regs);
extern void isr4(registers_t *regs);
extern void isr5(registers_t *regs);
extern void isr6(registers_t *regs);
extern void isr7(registers_t *regs);
extern void isr8(registers_t *regs);
extern void isr9(registers_t *regs);
extern void isr10(registers_t *regs);
extern void isr11(registers_t *regs);
extern void isr12(registers_t *regs);
extern void isr13(registers_t *regs);
extern void isr14(registers_t *regs);
extern void isr15(registers_t *regs);
extern void isr16(registers_t *regs);
extern void isr17(registers_t *regs);
extern void isr18(registers_t *regs);
extern void isr19(registers_t *regs);
extern void isr20(registers_t *regs);
extern void isr21(registers_t *regs);
extern void isr22(registers_t *regs);
extern void isr23(registers_t *regs);
extern void isr24(registers_t *regs);
extern void isr25(registers_t *regs);
extern void isr26(registers_t *regs);
extern void isr27(registers_t *regs);
extern void isr28(registers_t *regs);
extern void isr29(registers_t *regs);
extern void isr30(registers_t *regs);
extern void isr31(registers_t *regs);
extern void isr32(registers_t *regs);
extern void isr33(registers_t *regs);
extern void isr34(registers_t *regs);
extern void isr35(registers_t *regs);
extern void isr36(registers_t *regs);
extern void isr37(registers_t *regs);
extern void isr38(registers_t *regs);
extern void isr39(registers_t *regs);
extern void isr40(registers_t *regs);
extern void isr41(registers_t *regs);
extern void isr42(registers_t *regs);
extern void isr43(registers_t *regs);
extern void isr44(registers_t *regs);
extern void isr45(registers_t *regs);
extern void isr46(registers_t *regs);
extern void isr47(registers_t *regs);
extern void isr48(registers_t *regs);
extern void isr49(registers_t *regs);
extern void isr50(registers_t *regs);
extern void isr51(registers_t *regs);
extern void isr52(registers_t *regs);
extern void isr53(registers_t *regs);
extern void isr54(registers_t *regs);
extern void isr55(registers_t *regs);
extern void isr56(registers_t *regs);
extern void isr57(registers_t *regs);
extern void isr58(registers_t *regs);
extern void isr59(registers_t *regs);
extern void isr60(registers_t *regs);
extern void isr61(registers_t *regs);
extern void isr62(registers_t *regs);
extern void isr63(registers_t *regs);
extern void isr64(registers_t *regs);
extern void isr65(registers_t *regs);
extern void isr66(registers_t *regs);
extern void isr67(registers_t *regs);
extern void isr68(registers_t *regs);
extern void isr69(registers_t *regs);
extern void isr70(registers_t *regs);
extern void isr71(registers_t *regs);
extern void isr72(registers_t *regs);
extern void isr73(registers_t *regs);
extern void isr74(registers_t *regs);
extern void isr75(registers_t *regs);
extern void isr76(registers_t *regs);
extern void isr77(registers_t *regs);
extern void isr78(registers_t *regs);
extern void isr79(registers_t *regs);
extern void isr80(registers_t *regs);
extern void isr81(registers_t *regs);
extern void isr82(registers_t *regs);
extern void isr83(registers_t *regs);
extern void isr84(registers_t *regs);
extern void isr85(registers_t *regs);
extern void isr86(registers_t *regs);
extern void isr87(registers_t *regs);
extern void isr88(registers_t *regs);
extern void isr89(registers_t *regs);
extern void isr90(registers_t *regs);
extern void isr91(registers_t *regs);
extern void isr92(registers_t *regs);
extern void isr93(registers_t *regs);
extern void isr94(registers_t *regs);
extern void isr95(registers_t *regs);
extern void isr96(registers_t *regs);
extern void isr97(registers_t *regs);
extern void isr98(registers_t *regs);
extern void isr99(registers_t *regs);
extern void isr100(registers_t *regs);
extern void isr101(registers_t *regs);
extern void isr102(registers_t *regs);
extern void isr103(registers_t *regs);
extern void isr104(registers_t *regs);
extern void isr105(registers_t *regs);
extern void isr106(registers_t *regs);
extern void isr107(registers_t *regs);
extern void isr108(registers_t *regs);
extern void isr109(registers_t *regs);
extern void isr110(registers_t *regs);
extern void isr111(registers_t *regs);
extern void isr112(registers_t *regs);
extern void isr113(registers_t *regs);
extern void isr114(registers_t *regs);
extern void isr115(registers_t *regs);
extern void isr116(registers_t *regs);
extern void isr117(registers_t *regs);
extern void isr118(registers_t *regs);
extern void isr119(registers_t *regs);
extern void isr120(registers_t *regs);
extern void isr121(registers_t *regs);
extern void isr122(registers_t *regs);
extern void isr123(registers_t *regs);
extern void isr124(registers_t *regs);
extern void isr125(registers_t *regs);
extern void isr126(registers_t *regs);
extern void isr127(registers_t *regs);
extern void isr128(registers_t *regs);
extern void isr129(registers_t *regs);
extern void isr130(registers_t *regs);
extern void isr131(registers_t *regs);
extern void isr132(registers_t *regs);
extern void isr133(registers_t *regs);
extern void isr134(registers_t *regs);
extern void isr135(registers_t *regs);
extern void isr136(registers_t *regs);
extern void isr137(registers_t *regs);
extern void isr138(registers_t *regs);
extern void isr139(registers_t *regs);
extern void isr140(registers_t *regs);
extern void isr141(registers_t *regs);
extern void isr142(registers_t *regs);
extern void isr143(registers_t *regs);
extern void isr144(registers_t *regs);
extern void isr145(registers_t *regs);
extern void isr146(registers_t *regs);
extern void isr147(registers_t *regs);
extern void isr148(registers_t *regs);
extern void isr149(registers_t *regs);
extern void isr150(registers_t *regs);
extern void isr151(registers_t *regs);
extern void isr152(registers_t *regs);
extern void isr153(registers_t *regs);
extern void isr154(registers_t *regs);
extern void isr155(registers_t *regs);
extern void isr156(registers_t *regs);
extern void isr157(registers_t *regs);
extern void isr158(registers_t *regs);
extern void isr159(registers_t *regs);
extern void isr160(registers_t *regs);
extern void isr161(registers_t *regs);
extern void isr162(registers_t *regs);
extern void isr163(registers_t *regs);
extern void isr164(registers_t *regs);
extern void isr165(registers_t *regs);
extern void isr166(registers_t *regs);
extern void isr167(registers_t *regs);
extern void isr168(registers_t *regs);
extern void isr169(registers_t *regs);
extern void isr170(registers_t *regs);
extern void isr171(registers_t *regs);
extern void isr172(registers_t *regs);
extern void isr173(registers_t *regs);
extern void isr174(registers_t *regs);
extern void isr175(registers_t *regs);
extern void isr176(registers_t *regs);
extern void isr177(registers_t *regs);
extern void isr178(registers_t *regs);
extern void isr179(registers_t *regs);
extern void isr180(registers_t *regs);
extern void isr181(registers_t *regs);
extern void isr182(registers_t *regs);
extern void isr183(registers_t *regs);
extern void isr184(registers_t *regs);
extern void isr185(registers_t *regs);
extern void isr186(registers_t *regs);
extern void isr187(registers_t *regs);
extern void isr188(registers_t *regs);
extern void isr189(registers_t *regs);
extern void isr190(registers_t *regs);
extern void isr191(registers_t *regs);
extern void isr192(registers_t *regs);
extern void isr193(registers_t *regs);
extern void isr194(registers_t *regs);
extern void isr195(registers_t *regs);
extern void isr196(registers_t *regs);
extern void isr197(registers_t *regs);
extern void isr198(registers_t *regs);
extern void isr199(registers_t *regs);
extern void isr200(registers_t *regs);
extern void isr201(registers_t *regs);
extern void isr202(registers_t *regs);
extern void isr203(registers_t *regs);
extern void isr204(registers_t *regs);
extern void isr205(registers_t *regs);
extern void isr206(registers_t *regs);
extern void isr207(registers_t *regs);
extern void isr208(registers_t *regs);
extern void isr209(registers_t *regs);
extern void isr210(registers_t *regs);
extern void isr211(registers_t *regs);
extern void isr212(registers_t *regs);
extern void isr213(registers_t *regs);
extern void isr214(registers_t *regs);
extern void isr215(registers_t *regs);
extern void isr216(registers_t *regs);
extern void isr217(registers_t *regs);
extern void isr218(registers_t *regs);
extern void isr219(registers_t *regs);
extern void isr220(registers_t *regs);
extern void isr221(registers_t *regs);
extern void isr222(registers_t *regs);
extern void isr223(registers_t *regs);
extern void isr224(registers_t *regs);
extern void isr225(registers_t *regs);
extern void isr226(registers_t *regs);
extern void isr227(registers_t *regs);
extern void isr228(registers_t *regs);
extern void isr229(registers_t *regs);
extern void isr230(registers_t *regs);
extern void isr231(registers_t *regs);
extern void isr232(registers_t *regs);
extern void isr233(registers_t *regs);
extern void isr234(registers_t *regs);
extern void isr235(registers_t *regs);
extern void isr236(registers_t *regs);
extern void isr237(registers_t *regs);
extern void isr238(registers_t *regs);
extern void isr239(registers_t *regs);
extern void isr240(registers_t *regs);
extern void isr241(registers_t *regs);
extern void isr242(registers_t *regs);
extern void isr243(registers_t *regs);
extern void isr244(registers_t *regs);
extern void isr245(registers_t *regs);
extern void isr246(registers_t *regs);
extern void isr247(registers_t *regs);
extern void isr248(registers_t *regs);
extern void isr249(registers_t *regs);
extern void isr250(registers_t *regs);
extern void isr251(registers_t *regs);
extern void isr252(registers_t *regs);
extern void isr253(registers_t *regs);
extern void isr254(registers_t *regs);
extern void isr255(registers_t *regs);

static void (*stubs[NUM_ISR])(registers_t *regs) = {
    isr0, isr1, isr2, isr3, isr4, isr5, isr6, isr7, isr8, isr9, isr10, isr11, isr12, isr13, isr14, isr15, isr16,
    isr17, isr18, isr19, isr20, isr21, isr22, isr23, isr24, isr25, isr26, isr27, isr28, isr29, isr30, isr31, isr32,
    isr33, isr34, isr35, isr36, isr37, isr38, isr39, isr40, isr41, isr42, isr43, isr44, isr45, isr46, isr47, isr48,
    isr49, isr50, isr51, isr52, isr53, isr54, isr55, isr56, isr57, isr58, isr59, isr60, isr61, isr62, isr63, isr64,
    isr65, isr66, isr67, isr68, isr69, isr70, isr71, isr72, isr73, isr74, isr75, isr76, isr77, isr78, isr79, isr80,
    isr81, isr82, isr83, isr84, isr85, isr86, isr87, isr88, isr89, isr90, isr91, isr92, isr93, isr94, isr95, isr96,
    isr97, isr98, isr99, isr100, isr101, isr102, isr103, isr104, isr105, isr106, isr107, isr108, isr109, isr110,
    isr111, isr112, isr113, isr114, isr115, isr116, isr117, isr118, isr119, isr120, isr121, isr122, isr123, isr124,
    isr125, isr126, isr127, isr128, isr129, isr130, isr131, isr132, isr133, isr134, isr135, isr136, isr137, isr138,
    isr139, isr140, isr141, isr142, isr143, isr144, isr145, isr146, isr147, isr148, isr149, isr150, isr151, isr152,
    isr153, isr154, isr155, isr156, isr157, isr158, isr159, isr160, isr161, isr162, isr163, isr164, isr165, isr166,
    isr167, isr168, isr169, isr170, isr171, isr172, isr173, isr174, isr175, isr176, isr177, isr178, isr179, isr180,
    isr181, isr182, isr183, isr184, isr185, isr186, isr187, isr188, isr189, isr190, isr191, isr192, isr193, isr194,
    isr195, isr196, isr197, isr198, isr199, isr200, isr201, isr202, isr203, isr204, isr205, isr206, isr207, isr208,
    isr209, isr210, isr211, isr212, isr213, isr214, isr215, isr216, isr217, isr218, isr219, isr220, isr221, isr222,
    isr223, isr224, isr225, isr226, isr227, isr228, isr229, isr230, isr231, isr232, isr233, isr234, isr235, isr236,
    isr237, isr238, isr239, isr240, isr241, isr242, isr243, isr244, isr245, isr246, isr247, isr248, isr249, isr250,
    isr251, isr252, isr253, isr254, isr255
};

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

static struct {
    size_t index;
    void (*handler)(registers_t *regs);
} isrs[NUM_ISR];

static void (*handlers[NUM_ISR])(registers_t *regs) = { 0 };

void isr_install(size_t interrupt, void (*handler)(registers_t *regs)) {
    handlers[interrupt] = handler;
}

void isr_handler(registers_t *regs) {
    if (handlers[regs->int_no]) {
        handlers[regs->int_no](regs);
    } else {
        terminal_write("Unhandled interrupt: ");
        terminal_write_dec(regs->int_no);
        terminal_write(" (");
        terminal_write(isr_exception_messages[regs->int_no]);
        terminal_write(")\n");
    }
}

__attribute__((noreturn))
static void exception_handler(registers_t *regs) {
    terminal_write("Exception: ");
    terminal_write_dec(regs->int_no);
    terminal_write(" (");
    terminal_write(isr_exception_messages[regs->int_no]);
    terminal_write(")\n");
    terminal_write("Error code: ");
    terminal_write_dec(regs->error_code);
    terminal_write("\n");
    terminal_write("RIP: ");
    terminal_write_hex(regs->rip);
    terminal_write("\n");
    terminal_write("CS: ");
    terminal_write_hex(regs->cs);
    terminal_write("\n");
    terminal_write("RFLAGS: ");
    terminal_write_hex(regs->rflags);
    terminal_write("\n");
    terminal_write("RSP: ");
    terminal_write_hex(regs->rsp);
    terminal_write("\n");
    terminal_write("SS: ");
    terminal_write_hex(regs->ss);
    terminal_write("\n");

    __asm__ volatile("cli");
    hcf();
}

void isr_init(void) {
	terminal_write("[SYS/ISR] Installing ISRs...");

    for (size_t i = 0; i < NUM_ISR; i++) {
        isrs[i].index = i;
        isrs[i].handler = stubs[i];
        idt_set_descriptor(isrs[i].index, isrs[i].handler, 0x8E);
    }

    for (size_t i = 0; i < 32; i++) {
		isr_install(i, exception_handler);
    }

    terminal_write("OK\n");
}
