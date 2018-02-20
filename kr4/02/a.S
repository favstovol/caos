        .text
        .global process
process:
        pushl   %ebp
        movl    %esp, %ebp
        pushl   %edi
        pushl   %ebx
        pushl   %esi
        movl    8(%ebp), %edi
        movl    (%edi), %eax
        movl    8(%edi), %ebx
        imul    %ebx
        movl    %edx, %ecx
        movl    %eax, %ebx
        
        movl    4(%edi), %eax
        movl    12(%edi), %esi
        imull   %esi
        
        addl    %ebx, %eax
        adcl    %ecx, %edx
        jno     exit
        xorl    %edx, %edx
        xorl    %eax, %eax
exit:
        popl    %esi
        popl    %ebx
        popl    %edi
        movl    %ebp, %esp
        popl    %ebp
        ret
