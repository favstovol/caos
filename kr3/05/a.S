        .text
        .global compare
compare:
        pushl   %ebp
        movl    %esp, %ebp
        movl    8(%ebp), %eax
        popcnt  (%eax), %eax
        movl    12(%ebp), %edx
        popcnt  (%edx), %edx 
        cmpl    %edx, %eax
        jne     exit_cmp
        movl    12(%ebp), %eax
        movl    (%eax), %eax
        movl    8(%ebp), %edx
        movl    (%edx), %edx
        cmpl    %edx, %eax
        ja      plus
minus:
        movl    $1, %eax
        jmp     exit_cmp
plus:
        movl    $-1, %eax
exit_cmp:
        movl    %ebp, %esp
        popl    %ebp
        ret

        .global process
process:
        pushl   %ebp
        movl    %esp, %ebp
        pushl   $compare
        pushl   $4
        movl    12(%ebp), %eax
        pushl   %eax
        movl    8(%ebp), %eax
        pushl   %eax
        call    qsort
        addl    $16, %esp
        movl    %ebp, %esp
        popl    %ebp
        ret
