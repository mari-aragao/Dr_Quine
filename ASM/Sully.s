global main
extern dprintf
extern sprintf
extern system

%define QUINE "global main%1$cextern dprintf%1$cextern sprintf%1$cextern system%1$c%1$c%%define QUINE %2$c%3$s%2$c%1$c%1$csection .data%1$c    i dq %4$d%1$c    filename db %2$cSully_%%d.s%2$c, 0%1$c    compile_cmd db %2$cnasm -f elf64 Sully_%%d.s -o Sully_%%d.o; gcc -Wall -Wextra -Werror Sully_%%d.o -o Sully_%%d%2$c, 0%1$c    exec_cmd db %2$c./Sully_%%d%2$c, 0%1$c    quine db QUINE, 0%1$c%1$csection .bss%1$c    filename_out resb 64%1$c    compile_cmd_out resb 128%1$c    exec_cmd_out resb 64%1$c%1$csection .text%1$cmain:%1$c    push rbp%1$c    mov rbp, rsp%1$c%1$c    mov rax, [rel i]%1$c    dec rax%1$c    mov [rel i], rax%1$c    cmp rax, 0%1$c    jl end%1$c%1$ccomplete_filename:%1$c    lea rdi, [rel filename_out]%1$c    lea rsi, [rel filename]%1$c    mov rdx, [rel i]%1$c    call sprintf wrt ..plt%1$c%1$copen:%1$c    mov rax, 2%1$c    lea rdi, [rel filename_out]%1$c    mov rsi, 0x241%1$c    mov rdx, 0644%1$c    syscall%1$c    mov rbx, rax%1$c    cmp rbx, 0%1$c    jl end%1$c%1$cwrite_in_file:%1$c    mov rdi, rbx%1$c    lea rsi, [rel quine]%1$c    mov rdx, 10%1$c    mov rcx, 34%1$c    lea r8, [rel quine]%1$c    mov r9, [rel i]%1$c    call dprintf wrt ..plt%1$c%1$cclose:%1$c    mov rax, 3%1$c    mov rdi, rbx%1$c    syscall%1$c%1$ccomplete_compile_cmd:%1$c    lea rdi, [rel compile_cmd_out]%1$c    lea rsi, [rel compile_cmd]%1$c    mov rdx, [rel i]%1$c    mov rcx, [rel i]%1$c    mov r8, [rel i]%1$c    mov r9, [rel i]%1$c    call sprintf wrt ..plt%1$c%1$crun_compile:%1$c    lea rdi, [rel compile_cmd_out]%1$c    call system wrt ..plt%1$c    test rax, rax%1$c    jnz end%1$c%1$ccomplete_exec_cmd:%1$c    lea rdi, [rel exec_cmd_out]%1$c    lea rsi, [rel exec_cmd]%1$c    mov rdx, [rel i]%1$c    call sprintf wrt ..plt%1$c%1$crun_exec:%1$c    lea rdi, [rel exec_cmd_out]%1$c    call system wrt ..plt%1$c    test rax, rax%1$c    jnz end%1$c%1$cend:%1$c    xor rax, rax%1$c    leave%1$c    ret%1$c"

section .data
    i dq 5
    filename db "Sully_%d.s", 0
    compile_cmd db "nasm -f elf64 Sully_%d.s -o Sully_%d.o; gcc -Wall -Wextra -Werror Sully_%d.o -o Sully_%d", 0
    exec_cmd db "./Sully_%d", 0
    quine db QUINE, 0

section .bss
    filename_out resb 64
    compile_cmd_out resb 128
    exec_cmd_out resb 64

section .text
main:
    push rbp
    mov rbp, rsp

    mov rax, [rel i]
    dec rax
    mov [rel i], rax
    cmp rax, 0
    jl end

complete_filename:
    lea rdi, [rel filename_out]
    lea rsi, [rel filename]
    mov rdx, [rel i]
    call sprintf wrt ..plt

open:
    mov rax, 2
    lea rdi, [rel filename_out]
    mov rsi, 0x241
    mov rdx, 0644
    syscall
    mov rbx, rax
    cmp rbx, 0
    jl end

write_in_file:
    mov rdi, rbx
    lea rsi, [rel quine]
    mov rdx, 10
    mov rcx, 34
    lea r8, [rel quine]
    mov r9, [rel i]
    call dprintf wrt ..plt

close:
    mov rax, 3
    mov rdi, rbx
    syscall

complete_compile_cmd:
    lea rdi, [rel compile_cmd_out]
    lea rsi, [rel compile_cmd]
    mov rdx, [rel i]
    mov rcx, [rel i]
    mov r8, [rel i]
    mov r9, [rel i]
    call sprintf wrt ..plt

run_compile:
    lea rdi, [rel compile_cmd_out]
    call system wrt ..plt
    test rax, rax
    jnz end

complete_exec_cmd:
    lea rdi, [rel exec_cmd_out]
    lea rsi, [rel exec_cmd]
    mov rdx, [rel i]
    call sprintf wrt ..plt

run_exec:
    lea rdi, [rel exec_cmd_out]
    call system wrt ..plt
    test rax, rax
    jnz end

end:
    xor rax, rax
    leave
    ret
