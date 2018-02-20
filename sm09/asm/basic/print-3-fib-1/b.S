        .data
form:   .asciz "%d %d %d\n"
A:      .int 10
B:      .int 15

        .text
        .global main
print_fib:
        pushl   %ebp
        movl    %esp, %ebp
        
        movl    (A), %ecx
        addl    (B), %ecx
        movl    %ecx, %edx
        addl    (B), %edx
        movl    %ecx, %eax
        addl    %edx, %eax

        sub     $16, %esp
        movl    %eax, 12(%esp)
        movl    %edx, 8(%esp)
        movl    %ecx, 4(%esp)
        movl    $form, (%esp)

        call    printf

        movl    %ebp, %esp
        popl    %ebp
        
main:
        call    print_fib
