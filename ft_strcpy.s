global ft_strcpy

ft_strcpy:
    mov rdx, 0
    mov rax, rdi

loop: 
    cmp byte [rsi + rdx], 0
    je .end
    mov bl, [rsi + rdx]
    mov [rdi + rdx], bl
    inc rdx
    jmp loop

.end: 
    mov bl, 0
    ret
