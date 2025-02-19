global ft_strcpy

ft_strcpy:
    mov rdx, 0
    mov rax, rdi

loop: 
    cmp byte [rsi + rdx], 0
    je .finish
    mov bl, [rsi + rdx]
    mov [rdi + rdx], bl
    inc rdx
    jmp loop

.finish:
    mov byte [rax + rdx], 0
    ret
