        .text
        .global _start
_start:
        subl    $1, %esp
        movl    $3, %eax
        xorl    %ebx, %ebx
        movl    %esp, %ecx
        movl    $1, %edx
        int     $0x80
        //0x30 - 0, 0x39 - 9
        cmpl    $0, %eax
        jle     exit
        cmpb    $0x30, (%esp)
        jb      write
        cmpb    $0x39, (%esp)
        ja      write
        movb    $0x30, (%esp)
write:
        movl    $4, %eax
        movl    $1, %ebx
        movl    %esp, %ecx
        movl    $1, %edx
        int     $0x80
        jmp     _start
exit:
        movl    $1, %eax
        xorl    %ebx, %ebx
        int     $0x80

