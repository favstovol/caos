        .text
        .global myhypot
myhypot:
        pushl   %ebp
        movl    %esp, %ebp
        movsd   8(%esp), %xmm0
        movsd   16(%esp), %xmm1
        mulsd   %xmm0, %xmm0
        mulsd   %xmm1, %xmm1
        addsd   %xmm0, %xmm1
        sqrtsd  %xmm1, %xmm1
        movl    24(%esp), %eax
        movsd   %xmm1, (%eax)
        movl    %ebp, %esp
        popl    %ebp
        ret
