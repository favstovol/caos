        .text
count_bits:
        pushl   %ebp
        movl    %esp, %ebp
        movl    %eax, %edx
        xorl    %eax, %eax
loop_start:
        test    %edx, %edx
        jz      exit_count
        test    $1, %edx
        jz      next_step
        incl    %eax
next_step:
        shr     $1, %edx
        jmp     loop_start
exit_count:
        movl    %ebp, %esp
        popl    %ebp
        ret

compare:
        pushl   %ebp
        movl    %esp, %ebp
        popcnt  8(%ebp), %ecx
        popcnt  12(%ebp), %edx
        cmpl    %edx, %ecx
        js      less
        jne     more
        movl    12(%ebp), %eax
        subl    8(%ebp), %eax
        jmp     exit_cmp
less:
        movl    $-1, %eax
        jmp     exit_cmp
more:
        movl    $1, %eax
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
