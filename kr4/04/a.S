        .text
        .global addbe
addbe:
        pushl   %ebp
        movl    %esp, %ebp
        pushl   %ebx
        pushl   %edi
        pushl   %esi

        movl    8(%ebp), %ecx
        movl    12(%ebp), %edi
        movl    16(%ebp), %esi
        movl    20(%ebp), %edx

        xorl    %eax, %eax
start:
        decl    %ecx
        movzbl  (%edi, %ecx), %ebx
        addl    %ebx, %eax
        movzbl  (%esi, %ecx), %ebx
        addl    %ebx, %eax
        movb    %al, (%edx, %ecx)
        shrl    $8, %eax
        cmpl    $0, %ecx
        jne     start

        popl    %esi
        popl    %edi
        popl    %ebx
        movl    %ebp, %esp
        popl    %ebp
        ret
