        .data
form:   .asciz  "%d %d %d\n"

        .text
        .global print_fib
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
        ret
