        .text
        .global mystrspn
mystrspn:
        pushl   %ebp
        movl    %esp, %ebp
        pushl   %esi
        pushl   %ebx
        xorl    %eax, %eax
        movl    8(%ebp), %esi
start:
        movzb   (%esi), %ecx
        cmpl    $0, %ecx
        je      exit
        movl    12(%ebp), %ebx
loop_start:
        movzb   (%ebx), %edx
        cmpl    $0, %edx
        je      exit
        cmpl    %edx, %ecx
        je      equal
        incl    %ebx
        jmp     loop_start
equal:
        incl    %eax
        incl    %esi
        jmp     start
exit:
        popl    %ebx
        popl    %esi
        movl    %ebp, %esp
        popl    %ebp
        ret
