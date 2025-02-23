    global ft_strlen

    section .text
ft_strlen:
    mov rax, 0   

loop:
    test rdi, rdi
    jz .finish
    cmp byte [rdi + rax], 0 
    je .finish 
    inc rax
    jmp loop

.finish:
    ret