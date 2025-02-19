global ft_read

ft_read:
    mov rax, 0
    syscall
    ret 
    mov rax, 60
    mov rdi, 0
    syscall