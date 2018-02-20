        .text
        .global process
process:
        movl    X, %eax
        mull    X
        mull    A
        movl    %eax, %ecx
        movl    B, %eax
        mull    X
        addl    %ecx, %eax
        addl    C, %eax
        ret
