    global  ft_strcmp

    section .text
ft_strcmp:
    mov rax, 0

loop:
    mov cl, [rdi]
    mov bl, [rsi]
    cmp cl, 0
    je  .finish
    cmp bl, 0
    je  .finish
    cmp cl, bl
    jne .finish
    inc rdi
    inc rsi
    jmp loop

.ret_negative:
    mov rax, -1
    ret

.ret_positive:
    mov rax, 1
    ret

.finish:
    sub  cl, bl
    jg   .ret_positive
    jl   .ret_negative
    ret

    ; add errno
    ;It returns NULL if insufficient memory was available, with errno set to indicate the error.