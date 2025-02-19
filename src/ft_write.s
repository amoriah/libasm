global ft_write

ft_write:
    mov rax, 1
    syscall
    mov rax, 60
    mov rdi, 0
    syscall

    ;error handler __errno_loc...