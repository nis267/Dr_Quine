global main
extern strcmp
extern __progname
extern free
extern dprintf
extern asprintf
extern system
section .data
fmt_file_name db "Sully_%d.s", 0
nasm db "nasm -f elf64 -o Sully_%1$d.o Sully_%1$d.s", 0
clang db "clang -Wall -Wextra -Werror -o Sully_%1$d Sully_%1$d.o", 0
sully db "Sully", 0
sully_x db "./Sully_%d", 0
content db "global main%2$cextern strcmp%2$cextern __progname%2$cextern free%2$cextern dprintf%2$cextern asprintf%2$cextern system%2$csection .data%2$cfmt_file_name db %3$cSully_%4$cd.s%3$c, 0%2$cnasm db %3$cnasm -f elf64 -o Sully_%4$c1$d.o Sully_%4$c1$d.s%3$c, 0%2$cclang db %3$cclang -Wall -Wextra -Werror -o Sully_%4$c1$d Sully_%4$c1$d.o%3$c, 0%2$csully db %3$cSully%3$c, 0%2$csully_x db %3$c./Sully_%4$cd%3$c, 0%2$ccontent db %3$c%5$s%3$c%2$csection .text%2$cprint_content_to_file:%2$cpush    rbp%2$cmov     rbp, rsp%2$csub     rsp, 16%2$cmov     dword [rbp-4H], edi%2$cmov     dword [rbp-8H], esi%2$cpush content%2$cmov r9,  37%2$cmov r8,  34%2$cmov rcx, 10%2$cmov edx, dword [rbp-8H]%2$cmov rsi, content%2$cmov edi, dword [rbp-4H]%2$cmov rax, 0%2$ccall dprintf%2$cmov rax, 0%2$cleave%2$cret%2$cexit:%2$cmov rdi, 1%2$cmov rax, 60%2$csyscall%2$ccreate_and_fil_up_file:%2$cpush    rbp%2$cmov     rbp, rsp%2$csub     rsp, 16%2$cmov     dword [rbp-4H], edi%2$cmov     eax, dword [rbp-4H]%2$clea rax, [rbp-10H]%2$cmov edx, edi%2$cmov rsi, fmt_file_name%2$cmov rdi, rax%2$cmov eax, 0%2$ccall asprintf%2$cmov rdx, 0666o%2$cmov rsi, 0102o%2$cmov rdi, qword [rbp-10H]%2$cmov eax, 2%2$csyscall%2$cpush rax%2$cmov rdi, qword [rbp-10H]%2$ccall free%2$cpop rax%2$ccmp rax, 0%2$cjnae exit%2$cmov rdi, rax%2$cpush rdi%2$cmov esi, dword [rbp-4H]%2$ccall print_content_to_file%2$cpop rdi%2$cmov rax, 3%2$csyscall%2$cmov rax, 0%2$cleave%2$cret%2$cexecution:%2$cpush    rbp%2$cmov     rbp, rsp%2$csub     rsp, 16%2$cmov     dword [rbp-4H], edi%2$ccall    create_and_fil_up_file%2$cmov     edi, dword [rbp-4H]%2$cmov     qword rsi, nasm%2$ccall    execute_comand%2$cmov     edi, dword [rbp-4H]%2$cmov     qword rsi, clang%2$ccall    execute_comand%2$cmov     edi, dword [rbp-4H]%2$cmov     qword rsi, sully_x%2$ccall    execute_comand%2$cleave%2$cret%2$cbuild_command:%2$cpush    rbp%2$cmov     rbp, rsp%2$csub     rsp, 16%2$cmov     dword [rbp-4H], edi%2$cmov     eax, dword [rbp-4H]%2$clea     rax, [rbp-10H]%2$cmov     edx, edi%2$cmov     rdi, rax%2$cmov     eax, 0%2$ccall asprintf%2$cmov     rax, qword [rbp-10H]%2$cleave%2$cret%2$cexecute_comand:%2$ccall    build_command%2$cmov     rdi, rax%2$cpush    rdi%2$ccall system%2$cpop    rdi%2$cpush rax%2$ccall free%2$cpop rax%2$ccmp rax, 0%2$cjnz exit%2$cret%2$cfirst_call:%2$ccall    execution%2$cjmp     quit%2$cmain:%2$cpush    rbp%2$cmov     rbp, rsp%2$csub     rsp, 16%2$cmov     dword [rbp-4H], %1$d%2$ccmp     dword [rbp-4H], 0%2$cjle     quit%2$cmov     rsi, qword [__progname]%2$cmov     rdi, sully%2$ccall    strcmp%2$cmov     edi, dword [rbp-4H]%2$ccmp    eax, 0%2$cjz     first_call%2$csub     dword [rbp-4H], 1%2$cmov     eax, dword [rbp-4H]%2$cmov     edi, eax%2$ccall    execution%2$cjmp     quit%2$cquit:%2$cmov     eax, 0%2$cleave%2$cret%2$c"
section .text
print_content_to_file:
push    rbp
mov     rbp, rsp
sub     rsp, 16
mov     dword [rbp-4H], edi
mov     dword [rbp-8H], esi
push content
mov r9,  37
mov r8,  34
mov rcx, 10
mov edx, dword [rbp-8H]
mov rsi, content
mov edi, dword [rbp-4H]
mov rax, 0
call dprintf
mov rax, 0
leave
ret
exit:
mov rdi, 1
mov rax, 60
syscall
create_and_fil_up_file:
push    rbp
mov     rbp, rsp
sub     rsp, 16
mov     dword [rbp-4H], edi
mov     eax, dword [rbp-4H]
lea rax, [rbp-10H]
mov edx, edi
mov rsi, fmt_file_name
mov rdi, rax
mov eax, 0
call asprintf
mov rdx, 0666o
mov rsi, 0102o
mov rdi, qword [rbp-10H]
mov eax, 2
syscall
push rax
mov rdi, qword [rbp-10H]
call free
pop rax
cmp rax, 0
jnae exit
mov rdi, rax
push rdi
mov esi, dword [rbp-4H]
call print_content_to_file
pop rdi
mov rax, 3
syscall
mov rax, 0
leave
ret
execution:
push    rbp
mov     rbp, rsp
sub     rsp, 16
mov     dword [rbp-4H], edi
call    create_and_fil_up_file
mov     edi, dword [rbp-4H]
mov     qword rsi, nasm
call    execute_comand
mov     edi, dword [rbp-4H]
mov     qword rsi, clang
call    execute_comand
mov     edi, dword [rbp-4H]
mov     qword rsi, sully_x
call    execute_comand
leave
ret
build_command:
push    rbp
mov     rbp, rsp
sub     rsp, 16
mov     dword [rbp-4H], edi
mov     eax, dword [rbp-4H]
lea     rax, [rbp-10H]
mov     edx, edi
mov     rdi, rax
mov     eax, 0
call asprintf
mov     rax, qword [rbp-10H]
leave
ret
execute_comand:
call    build_command
mov     rdi, rax
push    rdi
call system
pop    rdi
push rax
call free
pop rax
cmp rax, 0
jnz exit
ret
first_call:
call    execution
jmp     quit
main:
push    rbp
mov     rbp, rsp
sub     rsp, 16
mov     dword [rbp-4H], 5
cmp     dword [rbp-4H], 0
jle     quit
mov     rsi, qword [__progname]
mov     rdi, sully
call    strcmp
mov     edi, dword [rbp-4H]
cmp    eax, 0
jz     first_call
sub     dword [rbp-4H], 1
mov     eax, dword [rbp-4H]
mov     edi, eax
call    execution
jmp     quit
quit:
mov     eax, 0
leave
ret
