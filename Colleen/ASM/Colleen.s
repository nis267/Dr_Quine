;I'am a comment
section .data
content db ";I'am a comment%1$csection .data%1$ccontent db %2$c%3$s%2$c, 0%1$csection .text%1$cglobal main%1$cextern printf%1$cprint:%1$cmov rcx, content%1$cmov rdx, 34%1$cmov rsi, 10%1$cmov rdi, content%1$cmov rax, 0%1$ccall printf%1$cret%1$cmain:%1$c;I'am a another comment%1$ccall print%1$c", 0
section .text
global main
extern printf
print:
mov rcx, content
mov rdx, 34
mov rsi, 10
mov rdi, content
mov rax, 0
call printf
ret
main:
;I'am a another comment
call print
