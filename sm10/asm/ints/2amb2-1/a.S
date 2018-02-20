        .data
str:    .asciz  "%llu\n"
        .text
        .global process
process:
        pushl   %ebx
        pushl   %ebp
        movl    %esp, %ebp
        movl    A + 4, %ebx
        movl    A, %eax
        shl     $1, %eax
        rcl     $1, %ebx
        movl    B + 4, %edx
        movl    B, %ecx
        shr     $1, %edx
        rcr     $1, %ecx
        
        subl    %ecx, %eax
        sbbl    %edx, %ebx
        
        pushl   %ebx
        pushl   %eax
        pushl   $str
        call    printf
        addl    $12, %esp

        movl    %ebp, %esp
        popl    %ebp
        popl    %ebx
        ret
