section .text
%include "helper.asm"

; rdi = pointer to string
; rsi = size of string
; return value = converted 64-bit signed integer value
string_to_int:
    mov rax, 10
    ret

global _start
_start:

    mov rdi, buffer
    mov rsi, buffer_length
    call string_to_int
    
    mov rdi, rax
    call print_int

    mov rax, 60
    mov rdi, 0 
    syscall

section .data
buffer: db "169"
buffer_length: equ $ - buffer