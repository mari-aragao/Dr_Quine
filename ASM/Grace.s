; comment outside the program
global main
extern dprintf

%define QUINE "; comment outside the program%1$cglobal main%1$cextern dprintf%1$c%1$c%3$cdefine QUINE %2$c%4$s%2$c%1$c%3$cdefine FILENAME %2$cGrace_kid.s%2$c%1$c%3$cdefine MAIN main:%1$c%1$c%3$cmacro GRACE 0%1$cMAIN%1$c    push rbp%1$c    mov rbp, rsp%1$c%1$copen:%1$c    mov rax, 2%1$c    lea rdi, [rel filename]%1$c    mov rsi, 0x241%1$c    mov rdx, 0644%1$c    syscall%1$c    mov rbx, rax%1$c    cmp rbx, 0%1$c    jb end%1$c%1$cwrite:%1$c    mov rdi, rbx%1$c    lea rsi, [rel quine]%1$c    mov rdx, 10%1$c    mov rcx, 34%1$c    mov r8, 37%1$c    lea r9, [rel quine]%1$c    call dprintf wrt ..plt%1$c%1$cclose:%1$c    mov rax, 3%1$c    mov rdi, rbx%1$c    syscall%1$c%1$cend:%1$c    leave%1$c    ret%1$c%1$c%3$cendmacro%1$c%1$csection .data%1$c    quine db QUINE, 0%1$c    filename db FILENAME, 0%1$c%1$csection .text%1$cGRACE"
%define FILENAME "Grace_kid.s"
%define MAIN main:

%macro GRACE 0
MAIN
    push rbp
    mov rbp, rsp

open:
    mov rax, 2
    lea rdi, [rel filename]
    mov rsi, 0x241
    mov rdx, 0644
    syscall
    mov rbx, rax
    cmp rbx, 0
    jb end

write:
    mov rdi, rbx
    lea rsi, [rel quine]
    mov rdx, 10
    mov rcx, 34
    mov r8, 37
    lea r9, [rel quine]
    call dprintf wrt ..plt

close:
    mov rax, 3
    mov rdi, rbx
    syscall

end:
    leave
    ret

%endmacro

section .data
    quine db QUINE, 0
    filename db FILENAME, 0

section .text
GRACE