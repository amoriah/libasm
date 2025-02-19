global ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:
    mov     rbx, rdi           ; mov first arg to tmp rbx
    call    ft_strlen          ; get rdi return rax
    inc     rax                ; len + 1
    mov     rdi, rax           ; move len into ferst arg
    call    malloc WRT ..plt   ; search in dynamic library , get first arg return rax
    test    rax, rax           ; check if null
    jz      .error_handler
    mov     rdi, rax           ; move pointer of memory to first arg
    mov     rsi, rbx           ; move into second arg tmp rbx
    call    ft_strcpy          ; take rdi and rsi return rax
    ret 

.error_handler:
    mov     rax, 0
    ret