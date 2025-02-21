section .text
    global ft_write
    extern __errno_location

ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl .error
    ret

.error:
    neg rax
    call __errno_location
    mov [rax], rax
    mov rax, -1
    ret 

    ;error handler __errno_loc...

