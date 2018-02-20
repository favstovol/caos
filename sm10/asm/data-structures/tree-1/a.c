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
        jz      found
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
