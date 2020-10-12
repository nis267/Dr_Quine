%macro PRINT_TO_FILE_AND_CLOSE_IT 2
mov r9, %2
mov r8, 37
mov rcx, 34
mov rdx, 10
mov rsi, %2
mov rdi, %1
mov rax, 0
call dprintf
mov rdi, %1
mov rax, 3
syscall
ret
%endmacro
%macro OPEN 1
mov rdx, 0666o
mov rsi, 1102o
mov rdi, %1
mov rax, 2
syscall
mov rbx, rax
cmp rbx, 0
jl exit_error
PRINT_TO_FILE_AND_CLOSE_IT rbx, content
exit_error:
mov rdi, rbx
mov rax, 60
syscall
ret
%endmacro
%macro START 0
section .data
file db "Grace_kid.s", 0
content db "%3$cmacro PRINT_TO_FILE_AND_CLOSE_IT 2%1$cmov r9, %3$c2%1$cmov r8, 37%1$cmov rcx, 34%1$cmov rdx, 10%1$cmov rsi, %3$c2%1$cmov rdi, %3$c1%1$cmov rax, 0%1$ccall dprintf%1$cmov rdi, %3$c1%1$cmov rax, 3%1$csyscall%1$cret%1$c%3$cendmacro%1$c%3$cmacro OPEN 1%1$cmov rdx, 0666o%1$cmov rsi, 1102o%1$cmov rdi, %3$c1%1$cmov rax, 2%1$csyscall%1$cmov rbx, rax%1$ccmp rbx, 0%1$cjl exit_error%1$cPRINT_TO_FILE_AND_CLOSE_IT rbx, content%1$cexit_error:%1$cmov rdi, rbx%1$cmov rax, 60%1$csyscall%1$cret%1$c%3$cendmacro%1$c%3$cmacro START 0%1$csection .data%1$cfile db %2$cGrace_kid.s%2$c, 0%1$ccontent db %2$c%4$s%2$c, 0%1$csection .text%1$cglobal main%1$cextern dprintf%1$cmain:%1$cOPEN file%1$c%3$cendmacro%1$c;I'm a comment%1$cSTART%1$c", 0
section .text
global main
extern dprintf
main:
OPEN file
%endmacro
;I'm a comment
START
