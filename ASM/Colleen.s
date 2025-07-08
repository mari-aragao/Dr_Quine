;comment outside the program
global main
extern printf

section .data
    quine db ";comment outside the program%1$cglobal main%1$cextern printf%1$c%1$csection .data%1$c    quine db %2$c%3$s%2$c, 0%1$c%1$csection .text%1$canother_function:%1$c    ret%1$c%1$cmain:%1$c    ; comment inside the main%1$c    lea rdi, [rel quine]%1$c    mov rsi, 10%1$c    mov rdx, 34%1$c    lea rcx, [rel quine]%1$c    xor rax, rax%1$c    call printf wrt ..plt%1$c    call another_function%1$c    ret%1$c", 0

section .text
another_function:
    ret

main:
    ; comment inside the main
    lea rdi, [rel quine]
    mov rsi, 10
    mov rdx, 34
    lea rcx, [rel quine]
    xor rax, rax
    call printf wrt ..plt
    call another_function
    ret
