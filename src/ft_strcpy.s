    global ft_strcpy

    section .text
ft_strcpy:
    mov     rdx, 0
    mov     rax, rdi

loop:
    test    rsi, rsi
    je      .finish
    cmp     byte [rsi + rdx], 0
    je      .finish
    mov     bl, [rsi + rdx]
    mov     [rdi + rdx], bl
    inc     rdx
    jmp     loop

.finish:
    mov     byte [rax + rdx], 0
    ret
