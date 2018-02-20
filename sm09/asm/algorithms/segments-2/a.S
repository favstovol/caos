        .text
input:
        .asciz  "%d %d %d %d"
output:
        .asciz  "%d\n"
        .global process
process:
        pushl   %ebx
        pushl   %edi
        pushl   %ebp
        movl    %esp, %ebp
        subl    $16, %esp
        movl    %esp, %edi
        addl    $12, %edi
        pushl   %edi
        subl    $4, %edi
        pushl   %edi
        subl    $4, %edi
        pushl   %edi
        subl    $4, %edi
        pushl   %edi
        movl    $0, %ebx
        pushl   $input
start:
        call    scanf
        cmpl    $4, %eax
        jnz     exit
        movl    (%edi), %eax
        cmpl    8(%edi), %eax
        jge     l1
        movl    8(%edi), %eax
l1:
        movl    4(%edi), %ecx
        cmpl    12(%edi), %ecx
        jle     l2
        movl    12(%edi), %ecx
l2:
        subl    %eax, %ecx
        js      start
        addl    %ecx, %ebx
        jmp     start
exit:
        pushl   %ebx
        pushl   $output
        call    printf
        addl    $8, %esp
        movl    %ebp, %esp
        popl    %ebp
        popl    %edi
        popl    %ebx
        ret
