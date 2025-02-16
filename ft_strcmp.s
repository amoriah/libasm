global ft_strcmp

ft_strcmp:
    mov rax, 0

loop:
    cmp byte [rdi + rax], 0
    je .and
    cmp byte [rsi + rax], 0
    je .and
    mov cl, [rdi + rax]
    mov bl, [rsi+ rax]
    cmp cl, bl
    je .and
    inc rax
    jmp loop

.and
    ret
-------------------------------------------

    mov rax, 5   ; Move the value 5 into the rax register
mov rbx, 4   ; Move the value 4 into the rbx register
sub rax, rbx   ; Subtract the value in rbx from rax, store the result in rax
; The result (5 - 4 = 1) is now stored in rax