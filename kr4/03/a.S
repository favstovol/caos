        .data
        .text
        .global myexp
myexp:
        pushl   %ebp
        movl    %esp, %ebp
        movl    $1, %eax
        cvtsi2sd        %eax, %xmm0
        movsd   %xmm0, %xmm1
        xorl    %eax, %eax
        movl    $40, %ecx
start:
        movsd   8(%ebp), %xmm2
        incl    %eax
        cvtsi2sd        %eax, %xmm3
        mulsd   %xmm2, %xmm1
        divsd   %xmm3, %xmm1
        addsd   %xmm1, %xmm0
        decl    %ecx
        cmpl    $0, %ecx
        jne     start
        movl    16(%ebp), %eax
        movsd   %xmm0, (%eax)
        movl    %ebp, %esp
        popl    %ebp
        ret
