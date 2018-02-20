        .data
        .global A
A:      .int 0
        .global B
B:      .int 0
        .global C
C:      .int 0
        .global X
X:      .int 0

        .text
        .global process
process:
        movl    X, %eax
        mull    X, %eax
        mull    A, %eax
        movl    B, %ecx
        mull    X, %ecx
        addl    C, %eax
        addl    %ecx, %eax
        ret
