; rdi = int to convert
; rsi = pointer to the buffer
; return value = numbers of bytes written
int_to_string: 
    push rbx

    mov rcx, 0
    mov rax, rdi
    mov rbx, 10

    cmp rax, 0
    jge .skip_negative
    not rax
    inc rax
    mov [rsi], byte '-'
    mov rcx, 1
    .skip_negative:

    .loop:
    mov rdx, 0 ; zero out top 64 bits of the dividend
    div rbx
    add rdx, '0' 
    mov [rsi+rcx], dl
    inc rcx
    cmp rax, 0
    jne .loop

    cmp rdi, 0
    jl .skip_minus
    mov rdi, rsi
    mov rsi, rcx
    jmp .end_if
    .skip_minus:
    lea rdi, [rsi+1]
    lea rsi, [rcx-1]
    .end_if:

    push rcx
    call reverse
    pop rax
    pop rbx
    ret

; rdi = input buffer
; rsi = buffer size
; return value = nothing
reverse:
    push rbx

    mov rbx, 0
    dec rsi

    .loop:
    cmp rsi, rbx 
    jle .end

    mov cl, [rdi+rbx]
    mov dl, [rdi+rsi]
    mov [rdi+rbx], dl
    mov [rdi+rsi], cl
    inc rbx
    dec rsi
    jmp .loop
    .end:

    pop rbx
    ret

; rdi = 64-bit signed integer value to print
; return value = nothing
print_int:
    sub rsp, 21
    mov rsi, rsp
    call int_to_string

    mov [rsp+rax], byte 10
    inc rax

    mov rdx, rax
    mov rax, 1
    mov rdi, 1
    mov rsi, rsp
    syscall

    add rsp, 21

    ret