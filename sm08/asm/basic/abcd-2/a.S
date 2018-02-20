        .data
        .global A
A:      .int    0
        .global B
B:      .int    0
        .global C
C:      .int    0
        .global D
D:      .int    0
        .global R
R:      .int    0

        .text
        .global process
process:
        movl    A, %eax
        imull   B, %eax
        movl    C, %ecx
        imull   D, %ecx
        subl    %ecx, %eax
        movl    %eax, R
        ret
