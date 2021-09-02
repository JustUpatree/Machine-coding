section .text

; rdi = int to convert
; return value = numbers of bytes written
int_to_string: 
    push rbx
    push rdx
    push rcx

    mov rax, rdi
    mov rbx, 10
    mov rcx, 0

    .loop:
    mov rdx, 0 ; zero out top 64 bits of the dividend
    div rbx
    add rdx, 48 
    mov [buffer+rcx], dl
    inc rcx
    cmp rax, 0
    jne .loop

    mov rdi, buffer
    mov rsi, rcx
    call reverse

    mov rax, rcx
    pop rcx
    pop rdx
    pop rbx
    ret

; rdi = input buffer
; rsi = buffer size
; return value = nothing
reverse:
    push rcx
    push rdx
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
    pop rdx
    pop rcx
    ret


global _start
_start:
    mov rdi, 100500
    call int_to_string

    mov [buffer+rax], byte 10
    inc rax

    mov rdx, rax
    mov rax, 1
    mov rdi, 1
    mov rsi, buffer
    syscall

    mov rax, 60
    mov rdi, 0
    syscall

section .data
buffer: times 21 db 0 
