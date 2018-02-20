        .text
        .global satsum
satsum:
        pushl   %ebp
        movl    %esp, %ebp
        movl    8(%ebp), %eax
        addl    12(%ebp), %eax
        jnc     exit
        xorl    %eax, %eax
        notl    %eax
exit:
        movl    %ebp, %esp
        popl    %ebp
        ret
