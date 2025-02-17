global ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:
    mov rbx, rdi
    call ft_strlen
    inc rax
    mov rdi, rax
    call malloc WRT ..plt ; search some where
    mov rdi, rax
    mov rsi, rbx
    mov rax, 0
    mov rbx, 0
    call ft_strcpy
    ret

; error and null handler
