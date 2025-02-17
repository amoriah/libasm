global ft_strcmp

ft_strcmp:

loop:
    mov cl, [rdi]
    mov bl, [rsi]
    cmp cl, 0
    je .finish
    cmp bl, 0
    je .finish
    cmp cl, bl
    jne .finish
    inc rdi
    inc rsi
    jmp loop

.finish:
    sub cl, bl
    movsx rax, cl
    ret
