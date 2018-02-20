        .data
e_plus:
        .quad   0,00000001
e_minus:
        .quad   -0,00000001

        .text
        .global tree_find
tree_find:
        pushl   %ebp
        movl    %esp, %ebp
        movl    8(%ebp), %eax   // pointer to root
        movsd   12(%ebp), %xmm0 // double key
        movl    20(%ebp), %ecx  // char **pstr
start:
        test    %eax, %eax
        jz      not_found
        movsd   (%eax), %xmm1
        comisd  %xmm0, %xmm1
        movsd   %xmm1, %xmm2
        comisd  e_plus, %xmm1
        ja      nxt
        comisd  e_minus, %xmm2
        jc      nxt
        jmp     found
nxt:
        movsd   (%eax), %xmm1
        comisd  %xmm0, %xmm1
        jna     right
        movl    8(%eax), %eax
        jmp     start
right:  
        movl    12(%eax), %eax
        jmp     start
found:
        test    %ecx, %ecx
        jz      next
        addl    $16, %eax
        movl    %eax, (%ecx)
next:
        movl    $1, %eax
not_found:
        movl    %ebp, %esp
        popl    %ebp
        ret
