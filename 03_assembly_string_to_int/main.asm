section .text
%include "helper.asm"

; rdi = pointer to string
; rsi = size of string
; return value = rax : rdx
; rax = bool value, valid input or not  
; rdx = converted 64-bit signed integer value
string_to_int:

    mov rcx, 0 ; counter 
    mov rax, 0
    mov r8, 10
    mov r9, 0 ; is negative

    cmp rsi, 0
    je .empty_input

    cmp byte [rdi], 45
    jne .skip_minus
    add rcx, 1
    mov r9, 1

    .skip_minus:

    .loop:
    cmp rcx, rsi
    je .finish
    
    mov bl, [rdi+rcx]

    cmp rbx, 47
    jle .invalid_character
    cmp rbx, 58
    jge .invalid_character

    sub rbx, 48
    mul r8
    cmp r9, 0
    jne .sub_negative_value
    add rax, rbx
    jmp .endif
    .sub_negative_value:
    sub rax, rbx
    .endif:
    jo .overflow
    add rcx, 1
    jmp .loop
    .finish:


    mov rdx, rax
    mov rax, 1
    ret

    .empty_input:
    .invalid_character:
    .overflow:
    mov rax, 0
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

    sub rsp, 22

    mov rax, 0
    mov rdi, 0
    mov rsi, rsp
    mov rdx, 22
    syscall

    cmp rax, 0
    je .not_passed_validation

    cmp byte [rsp + rax - 1], 10
    je .valid_input_length
    .not_passed_validation:
    mov rdi, error_message
    mov rsi, error_message_length
    call panic

    .valid_input_length:
    dec rax

    mov rdi, rsp
    mov rsi, rax
    call string_to_int

    cmp rax, 0
    je .not_passed_validation
    mov rdi, rdx
    call print_int

    add rsp, 22

    mov rax, 60
    mov rdi, 0 
    syscall

section .data
error_message: db "Invalid input", 10
error_message_length: equ $ - error_message