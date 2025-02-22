    global ft_strdup

    extern ft_strlen
    extern ft_strcpy
    extern malloc
    extern __errno_location

    section .text
ft_strdup:
    mov     rbx, rdi           
    call    ft_strlen         
    inc     rax                
    mov     rdi, rax           
    call    malloc WRT ..plt   
    cmp     rax, 0
    jl      .error
    mov     rdi, rax
    mov     rsi, rbx
    call    ft_strcpy 
    ret 

.error:
    neg rax
    mov rdi, rax
    call __errno_location wrt ..plt
    mov [rax], edi
    mov rax, -1
    ret 