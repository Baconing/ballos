global isr_wrapper

%macro pushall 0

push rax
push rbx
push rcx
push rdx
push rbp
push rdi
push rsi
push r8
push r9
push r10
push r11
push r12
push r13
push r14
push r15

%endmacro

%macro popall 0

pop r15
pop r14
pop r13
pop r12
pop r11
pop r10
pop r9
pop r8
pop rsi
pop rdi
pop rbp
pop rdx
pop rcx
pop rbx
pop rax

%endmacro

extern isr_handler

isr_common:
    pushall
    cld
    call isr_handler
    popall
    iretq

%macro isr 1

global isr%1
isr%1:
	push 0
	push %1
	jmp isr_common

%endmacro

%macro error_isr 1

global isr%1
isr%1:
	push %1
	jmp isr_common

%endmacro

%define has_errcode(i) (i == 8 || (i >= 10 && i <= 14) || i == 17 || i == 21 || i == 29 || i == 30)

%assign i 0
%rep 256
%if has_errcode(i)
	error_isr i
%else
	isr i
%endif
%assign i i + 1
%endrep