section .text
    global ft_strlen

ft_strlen:
    mov rax, 0   

loop:
    cmp byte [rdi + rax], 0 
    je .finish 
    inc rax
    jmp loop

.finish:
    ret

    ; Убедитесь, что при вызове этой функции из C или другого высокоуровневого языка вы правильно передаете указатель на строку с нулевым терминатором в регистре rdi.
    ; check null