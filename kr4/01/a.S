        .text
        .global forward.args
forward.args:
        pushl   %ebp
        movl    %esp, %ebp
        movl    8(%ebp), %eax
        pushl   %eax
        movl    20(%ebp), %eax
        pushl   %eax
        movl    16(%ebp), %eax
        pushl   %eax
        movl    12(%ebp), %eax
        pushl   %eax
        call    process
        addl    $16, %esp
        movl    $-1, %ecx
        imull   %ecx
        movl    %ebp, %esp
        popl    %ebp
        ret
