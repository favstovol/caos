        .text
        .global mystrcmp
mystrcmp:
        pushl   %ebp
        movl    %esp, %ebp

        movl    8(%ebp), %ecx
        movl    12(%ebp), %edx
start:
        movb    (%ecx), %al
        cmpb    (%edx), %al
        jnz     exit
        cmpb    $0, (%edx)
        jz      exit
        incl    %ecx
        incl    %edx
        jmp     start
exit:
        xorl    %eax, %eax
        movb    (%ecx), %al
        xorl    %ecx, %ecx
        movb    (%edx), %cl
        subl    %ecx, %eax

        movl    %ebp, %esp
        popl    %ebp
        ret
