section .text
%include "helper.asm"

; rdi = pointer to string
; rsi = size of string
; return value = converted 64-bit signed integer value
string_to_int:
    mov rcx, 0 ; counter 
    mov rax, 0
    mov r8, 10
    mov r9, 0

    cmp byte [rdi+rcx], 45
    jne .skip_minus
    add rcx, 1
    mov r9, 1

    .skip_minus:

    .return:
    cmp rcx, rsi
    je .finish
    mov bl, [rdi+rcx]
    sub rbx, 48
    mul r8
    add rax, rbx
    add rcx, 1
    jmp .return
    .finish:

    cmp r9, 1
    jne .mul_minus
    ; mov r8, -1
    ; mul r8
    not rax
    inc rax
    .mul_minus:

    ret

; rdi = message for panic
; rsi = size of message
panic:
    mov rax, 1
    mov rdx, rsi
    mov rsi, rdi
    mov rdi, 2
    syscall

    mov rax, 60
    mov rdi, 1 
    syscall

global _start
_start:

    mov rax, 0
    mov rdi, 0
    mov rsi, input_buffer
    mov rdx, input_buffer_length
    syscall

    cmp rax, 0
    jne valid_value
    mov rdi, error_message
    mov rsi, error_message_length
    call panic


    valid_value:
    dec rax

    mov rdi, input_buffer
    mov rsi, rax
    call string_to_int

    mov rdi, rax
    call print_int

    mov rax, 60
    mov rdi, 0 
    syscall

section .bss
input_buffer: resb 100
input_buffer_length: equ $ - input_buffer

section .data
error_message: db "Invalid input", 10
error_message_length: equ $ - error_message